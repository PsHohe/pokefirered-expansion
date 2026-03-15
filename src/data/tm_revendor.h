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
