# Items And Shops

## Items: Data Model And Flow

- Item ID catalog: `include/constants/items.h`.
- Core item table (`gItemsInfo`): `src/data/items.h`.
  - Key fields: `price`, `pocket`, `type`, `fieldUseFunc`, `battleUsage`, `secondaryId`, hold-effect fields.
- Runtime bag/item operations: `src/item.c`.
- Field and battle item use callbacks: `src/item_use.c` + `include/item_use.h`.
- Item behavior tuning gates: `include/config/item.h` and some battle-side item behavior in `include/config/battle.h`.

## Add/Modify Item Checklist

1. Add/update ID in `include/constants/items.h` if needed.
2. Define or update entry in `src/data/items.h`.
3. If new field-use behavior is needed, add callback in `src/item_use.c` and declaration in `include/item_use.h`.
4. If behavior depends on item-effect bits, verify `include/constants/item_effects.h`.
5. Add test coverage (`test/bag.c`, `test/battle/item_effect/*`, or new targeted tests).

## Shops And Marts

- Script command entry point: `ScrCmd_pokemart` in `src/scrcmd.c`.
- Shop UI/logic engine: `src/shop.c`.
- Script-side inventory lists are typically local labels in `data/maps/*/scripts.inc`, terminated by `ITEM_NONE`.
- Common script flow pattern:
  - `message Text_MayIHelpYou`
  - `pokemart <ItemsLabel>`
  - `msgbox Text_PleaseComeAgain`

## Dynamic Shop Inventories

- Use script conditions (`goto_if_*`, scene vars, flags) to route to different item lists.
- Example pattern exists in `data/maps/TwoIsland/scripts.inc` with progression-based inventory expansion.

## Money And Purchase Hooks

- Script money ops are available through opcodes such as `addmoney`, `removemoney`, `checkmoney` (`data/script_cmd_table.inc` / `src/scrcmd.c`).
- Core money helpers are in `src/money.c`.

## Guardrails

- Keep shop stock definitions in script/data unless shop engine UI logic truly needs C changes.
- Preserve list termination (`ITEM_NONE`) to avoid menu read overruns.
- When changing purchasable items, validate both buy flow and bag insertion behavior.
