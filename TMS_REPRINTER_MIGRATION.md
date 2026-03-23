# TMs Reprinter (formerly TMs Revendor) - Implementation and Porting Guide

## Goal
Re-implement the **TM Reprinter** feature in another decomp repo (target: `pokeemerald`) with behavior parity to this repository.

This document is written for an AI implementer and includes:
- exact implementation footprint in this repo,
- relevant code snippets,
- integration points (specials, scripts, text),
- a practical port order with verification criteria.

## Naming History (Important)
The feature started as **"TMs Revendor"** and was later evolved into **"TM Reprinter"** UI behavior.

Current code still mixes names:
- `tm_revendor.h`, `OpenTMRevendorShop`, `Text_TmsRevendor` (legacy names kept)
- UI strings and logic use "TM PRINTER" / "Reprint" semantics

For migration, you can keep legacy symbol names for low-risk parity, or fully rename after behavior is stable.

## Source Commits (Feature Evolution)
- `5e07a56668e8a8a9e9760961aea2ce71a933cb25` - `tms revendor`
- `8ac89a05e50c0a4615523a7f280d626dd60dba49` - `tms revendor texts`
- `67bc3d484a2114c51feac55db0b7d4724944627c` - `tm reprinter`

Behavior changed significantly in `tm reprinter`: it moved from a standard Pokemart flow to a custom TM Case-powered reprinter mode with sorting and richer UX.

## Final Behavior
- NPC opens a special TM menu (TM Case UI in `TMCASE_REPRINTER` mode).
- Menu content is dynamically built from:
  - fixed TM item IDs,
  - additional TM item IDs unlocked by flags.
- Duplicate items are removed.
- Items are initially sorted by TM item ID (number order).
- In reprinter menu, pressing `R` cycles sort mode:
  - Number (`NO.`)
  - Name (`A-Z`)
  - Type (`TYPE`)
- Selecting a TM asks for purchase confirmation using that TM's normal item price.
- Purchase checks:
  - bag space (`CheckBagHasSpace`),
  - player money (`GetMoney` vs `GetItemPrice`).
- Successful purchase:
  - removes money,
  - adds one TM to bag,
  - updates money box,
  - plays shop SE,
  - prints success text.

## File-Level Implementation Map

### 1) TM source list data
**File:** `src/data/tm_revendor.h`

```c
#ifndef GUARD_DATA_TM_REVENDOR_H
#define GUARD_DATA_TM_REVENDOR_H

struct TmRevendorFlagItem
{
    u16 flag;
    u16 itemId;
};

static const u16 sTmRevendorFixedItems[] = {
    ITEM_TM01,
    ITEM_TM02,
};

static const struct TmRevendorFlagItem sTmRevendorFlagItems[] = {
    { FLAG_GOT_TM35_FROM_PALLET_FAT_MAN, ITEM_TM35 },
};

#endif // GUARD_DATA_TM_REVENDOR_H
```

Notes:
- This is the feature's data source.
- Add/remove unlock rules here; runtime logic consumes this table.

### 2) Field special entrypoint (build + open reprinter)
**File:** `src/field_specials.c`

Key include wiring:
```c
#include "tm_case.h"
#include "data/tm_revendor.h"
```

Key implementation:
```c
static EWRAM_DATA u16 sTmRevendorItemsForSale[NELEMS(sTmRevendorFixedItems) + NELEMS(sTmRevendorFlagItems) + 1] = {0};

static bool8 IsTmRevendorItemInList(const u16 *items, u16 count, u16 itemId)
{
    u16 i;

    for (i = 0; i < count; i++)
    {
        if (items[i] == itemId)
            return TRUE;
    }

    return FALSE;
}

static void BuildTmRevendorItemsForSale(void)
{
    u16 i;
    u16 j;
    u16 itemCount = 0;

    for (i = 0; i < NELEMS(sTmRevendorFixedItems); i++)
    {
        u16 itemId = sTmRevendorFixedItems[i];

        if (!IsTmRevendorItemInList(sTmRevendorItemsForSale, itemCount, itemId))
            sTmRevendorItemsForSale[itemCount++] = itemId;
    }

    for (i = 0; i < NELEMS(sTmRevendorFlagItems); i++)
    {
        u16 itemId = sTmRevendorFlagItems[i].itemId;

        if (FlagGet(sTmRevendorFlagItems[i].flag)
         && !IsTmRevendorItemInList(sTmRevendorItemsForSale, itemCount, itemId))
        {
            sTmRevendorItemsForSale[itemCount++] = itemId;
        }
    }

    for (i = 1; i < itemCount; i++)
    {
        u16 itemId = sTmRevendorItemsForSale[i];
        j = i;
        while (j > 0 && sTmRevendorItemsForSale[j - 1] > itemId)
        {
            sTmRevendorItemsForSale[j] = sTmRevendorItemsForSale[j - 1];
            j--;
        }
        sTmRevendorItemsForSale[j] = itemId;
    }

    sTmRevendorItemsForSale[itemCount] = ITEM_NONE;
}

void OpenTMRevendorShop(void)
{
    BuildTmRevendorItemsForSale();
    InitTMReprinter(sTmRevendorItemsForSale, CB2_ReturnToFieldContinueScriptPlayMapMusic);
}
```

Notes:
- Runtime list is sentinel-terminated with `ITEM_NONE`.
- Sorting at this stage is by item ID; reprinter menu can later re-sort for presentation.

### 3) Special registration
**File:** `data/specials.inc`

```asm
def_special OpenTMRevendorShop
```

Notes:
- Required so scripts can call `special OpenTMRevendorShop`.

### 4) TM Case API extension
**File:** `include/tm_case.h`

```c
enum {
    TMCASE_FIELD,
    TMCASE_GIVE_PARTY,
    TMCASE_SELL,
    TMCASE_GIVE_PC,
    TMCASE_POKEDUDE,
    TMCASE_REOPENING,
    TMCASE_REPRINTER,
};

void InitTMReprinter(const u16 *itemsForSale, void (* exitCallback)(void));
```

### 5) Core TM Case reprinter mode
**File:** `src/tm_case.c`

#### 5.1 New mode data and sort enum
```c
enum {
    TMCASE_SORT_NUMBER,
    TMCASE_SORT_NAME,
    TMCASE_SORT_TYPE,
    TMCASE_SORT_COUNT,
};
```

Dynamic resource additions:
```c
u8 sortMode;
u8 reprinterItemCount;
u16 *reprinterItems;
const u16 *reprinterSourceItems;
```

#### 5.2 Reprinter init API
```c
void InitTMReprinter(const u16 *itemsForSale, void (* exitCallback)(void))
{
    InitTMCase(TMCASE_REPRINTER, exitCallback, FALSE);
    sTMCaseDynamicResources->reprinterSourceItems = itemsForSale;
}
```

#### 5.3 Setup path switch
In `DoSetUpTMCaseUI`, step 9:
```c
if (sTMCaseStaticResources.menuType == TMCASE_REPRINTER)
    TMReprinterSetup_LoadItems();
else
    SortItemsInBag(&gBagPockets[POCKET_TM_HM], SORT_BY_INDEX);
```

In title setup:
```c
if (sTMCaseStaticResources.menuType == TMCASE_REPRINTER)
    PrintPlayersMoney();
```

#### 5.4 Unified item lookup helper
```c
static u16 GetListItemIdByIndex(u16 itemIndex)
{
    if (sTMCaseStaticResources.menuType == TMCASE_REPRINTER)
        return sTMCaseDynamicResources->reprinterItems[itemIndex];
    else
        return GetBagItemId(POCKET_TM_HM, itemIndex);
}
```

This helper is used by list building, cursor movement, printing, and selection.

#### 5.5 Reprinter-specific list rendering behavior
- Right-side value column shows price (`gText_PokedollarVar1`) instead of bag quantity/HM badge.
- Description panel shows move description (`gMovesInfo[ItemIdToBattleMoveId(item)].description`) instead of item description.
- Cancel row text becomes reprinter-specific shutdown text.

#### 5.6 Input behavior and sort cycling
In list input handler:
```c
if (sTMCaseStaticResources.menuType == TMCASE_REPRINTER
 && JOY_NEW(R_BUTTON)
 && sTMCaseDynamicResources->numTMs > 1)
{
    PlaySE(SE_SELECT);
    TMReprinterCycleSortMode(taskId);
}
```

Sort cycle logic preserves currently selected TM across order changes:
```c
DestroyListMenuTask(tListTaskId, NULL, NULL);
sTMCaseDynamicResources->sortMode = (sTMCaseDynamicResources->sortMode + 1) % TMCASE_SORT_COUNT;
TMReprinterSortItems();
TMReprinterSetCursorToItem(selectedItem);
InitTMCaseListMenuItems();
tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, sTMCaseStaticResources.scrollOffset, sTMCaseStaticResources.selectedRow);
PrintTitle();
```

#### 5.7 Purchase task flow
```c
static void Task_SelectedTMHM_Reprinter(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar2, GetItemPrice(gSpecialVar_ItemId), STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, sText_TMReprinterConfirm);
    PrintMessageWithFollowupTask(taskId, GetDialogBoxFontId(), gStringVar4, Task_Reprinter_PlaceYesNo);
}

static void Task_Reprinter_TryPurchase(u8 taskId)
{
    u32 price = GetItemPrice(gSpecialVar_ItemId);

    if (!CheckBagHasSpace(gSpecialVar_ItemId, 1))
    {
        PrintMessageWithFollowupTask(taskId, GetDialogBoxFontId(), sText_TMReprinterNoBagSpace, Task_Reprinter_AfterMessage);
        return;
    }

    if (GetMoney(&gSaveBlock1Ptr->money) < price)
    {
        PrintMessageWithFollowupTask(taskId, GetDialogBoxFontId(), sText_TMReprinterNoMoney, Task_Reprinter_AfterMessage);
        return;
    }

    RemoveMoney(&gSaveBlock1Ptr->money, price);
    AddBagItem(gSpecialVar_ItemId, 1);
    PlaySE(SE_SHOP);
    PrintMoneyAmountInMoneyBox(WIN_MONEY, GetMoney(&gSaveBlock1Ptr->money), 0);

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, sText_TMReprinterComplete);
    PrintMessageWithFollowupTask(taskId, GetDialogBoxFontId(), gStringVar4, Task_Reprinter_AfterMessage);
}
```

#### 5.8 Reprinter item load/sort implementation
```c
static void TMReprinterSetup_LoadItems(void)
{
    u16 i;
    u16 itemCount = 0;

    if (sTMCaseDynamicResources->reprinterItems == NULL)
        sTMCaseDynamicResources->reprinterItems = Alloc(NUM_ALL_MACHINES * sizeof(u16));

    if (sTMCaseDynamicResources->reprinterItems == NULL)
    {
        sTMCaseDynamicResources->reprinterItemCount = 0;
        return;
    }

    if (sTMCaseDynamicResources->reprinterSourceItems == NULL)
    {
        sTMCaseDynamicResources->reprinterItemCount = 0;
        return;
    }

    for (i = 0; sTMCaseDynamicResources->reprinterSourceItems[i] != ITEM_NONE && itemCount < NUM_ALL_MACHINES; i++)
    {
        u16 itemId = sTMCaseDynamicResources->reprinterSourceItems[i];
        u16 j;
        bool8 duplicate = FALSE;

        if (!IsItemTMHM(itemId))
            continue;

        for (j = 0; j < itemCount; j++)
        {
            if (sTMCaseDynamicResources->reprinterItems[j] == itemId)
            {
                duplicate = TRUE;
                break;
            }
        }

        if (!duplicate)
            sTMCaseDynamicResources->reprinterItems[itemCount++] = itemId;
    }

    sTMCaseDynamicResources->reprinterItemCount = itemCount;
    sTMCaseDynamicResources->sortMode = TMCASE_SORT_NUMBER;
    TMReprinterSortItems();
}
```

Comparator:
```c
static s32 TMReprinterCompareItems(u16 lhs, u16 rhs)
{
    switch (sTMCaseDynamicResources->sortMode)
    {
    case TMCASE_SORT_NAME:
    {
        s32 cmp = StringCompare(gMovesInfo[ItemIdToBattleMoveId(lhs)].name, gMovesInfo[ItemIdToBattleMoveId(rhs)].name);
        if (cmp != 0)
            return cmp;
        return lhs - rhs;
    }
    case TMCASE_SORT_TYPE:
    {
        s32 lhsType = gMovesInfo[ItemIdToBattleMoveId(lhs)].type;
        s32 rhsType = gMovesInfo[ItemIdToBattleMoveId(rhs)].type;

        if (lhsType != rhsType)
            return lhsType - rhsType;

        s32 cmp = StringCompare(gMovesInfo[ItemIdToBattleMoveId(lhs)].name, gMovesInfo[ItemIdToBattleMoveId(rhs)].name);
        if (cmp != 0)
            return cmp;
        return lhs - rhs;
    }
    case TMCASE_SORT_NUMBER:
    default:
        return lhs - rhs;
    }
}
```

#### 5.9 Cleanup
`DestroyTMCaseBuffers` must free `reprinterItems` to avoid leaks.

### 6) Script and text wiring
**Files:**
- `data/event_scripts.s`
- `data/text/tms_revendor.inc`
- `data/maps/TestingGrounds/scripts.inc`
- `data/maps/TestingGrounds/map.json` (example NPC wiring)

Text include registration:
```asm
@ TMs Revendor
    .include "data/text/tms_revendor.inc"
```

Dialog text:
```asm
Text_TmsRevendor::
    .string "Welcome to the TM Reprinter!\p"
    .string "Pick a TM and we'll burn a fresh copy.\p"
    .string "Press R to sort by No., Name, or Type.$"
```

Example script entrypoint:
```asm
TestingGrounds_EventScript_TmRevendor::
    lock
    faceplayer
    message Text_TmsRevendor
    waitmessage
    special OpenTMRevendorShop
    waitstate
    msgbox Text_PleaseComeAgain
    release
    end
```

## Port Order for `pokeemerald`

Assumptions:
- `pokeemerald` target has TM Case code with similar architecture (callbacks/tasks/list menu/money box).
- Script special mechanism is equivalent (`data/specials.inc` + `special` command).

Recommended implementation order:
1. Add TM source data table (`tm_revendor.h` equivalent).
2. Add field special function to build sale list + call reprinter initializer.
3. Register special in specials table.
4. Extend TM Case public API (`TMCASE_REPRINTER` + `InitTMReprinter`).
5. Add reprinter mode internals in TM Case:
   - reprinter item buffer/state,
   - setup branch,
   - list source abstraction (`GetListItemIdByIndex` pattern),
   - reprinter-specific display behavior,
   - R-button sort cycle,
   - purchase task flow,
   - cleanup/free logic.
6. Add NPC script/text wiring in your target map.
7. Build and run interaction tests.

## Symbol/Structure Differences to Expect in `pokeemerald`
Check and adapt these likely deltas:
- bag pocket constants and TM pocket field names,
- TM/HM count constants (`NUM_ALL_MACHINES`, TM index helpers),
- move/item data symbols (`gMovesInfo`, item->move conversion helper),
- TM Case window enums/templates and existing sell-mode windows,
- yes/no menu helper signature,
- money print helpers (`PrintMoneyAmountInMoneyBox*` variants),
- callback used after menu closes (FireRed uses `CB2_ReturnToFieldContinueScriptPlayMapMusic`).

## Minimal Verification Checklist
1. NPC opens reprinter menu and returns cleanly to field.
2. Menu list contents include fixed TMs.
3. Flag-gated TM appears only after flag is set.
4. Duplicate TM entries never appear.
5. `R` cycles Number -> Name -> Type sort and preserves selected TM.
6. Price shown per TM matches item price table.
7. Purchase denied when bag full.
8. Purchase denied when money is insufficient.
9. Successful purchase:
   - bag TM count increases by 1,
   - money decreases by item price,
   - success message shown,
   - money box updates.
10. Exit/cancel paths do not crash or leave stale windows/sprites.

## Practical Migration Notes
- Start with behavior parity before renaming symbols.
- Keep `revendor` labels during first pass to reduce integration risk.
- After passing the verification checklist, optionally run a rename pass (`revendor` -> `reprinter`) for clarity.
- No feature tests were added in this repo for this mechanic; manual scenario testing is required unless you add new harness coverage in target repo.

## Quick Reference (Current Files)
- `include/tm_case.h`
- `src/tm_case.c`
- `src/field_specials.c`
- `src/data/tm_revendor.h`
- `data/specials.inc`
- `data/text/tms_revendor.inc`
- `data/event_scripts.s`
- `data/maps/TestingGrounds/scripts.inc`
- `data/maps/TestingGrounds/map.json`
