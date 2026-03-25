# Registration Files

Use this checklist when adding a new object-event NPC sprite in `pokefirered-expansion`.

1. Conversion rule:
- `spritesheet_rules.mk`

2. Graphics IDs and palette tags:
- `include/constants/event_objects.h`

3. Graphics and palette binary includes:
- `src/data/object_events/object_event_graphics.h`

4. Frame table:
- `src/data/object_events/object_event_pic_tables.h`

5. Graphics info struct:
- `src/data/object_events/object_event_graphics_info.h`

6. Graphics info extern + pointer mapping:
- `src/data/object_events/object_event_graphics_info_pointers.h`

7. Runtime palette loader table:
- `src/event_object_movement.c`

8. Map object usage:
- `data/maps/<MapName>/map.json` with `graphics_id: "OBJ_EVENT_GFX_<NAME>"`

## Typical 16x32 NPC Settings

- `overworld_ascending_frames(..., 2, 4)`
- `.size = 256`
- `.width = 16`
- `.height = 32`
- `.oam = &gObjectEventBaseOam_16x32`
- `.subspriteTables = sOamTables_16x32`
- `.anims = sAnimTable_Standard`
- `.tracks = TRACKS_FOOT`
