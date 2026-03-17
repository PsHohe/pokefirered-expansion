# Workflow And File Ownership

## Source Of Truth

- Combat/move behavior data:
  - `src/data/moves_info.h`
  - `src/data/battle_move_effects.h`
  - `include/constants/battle_move_effects.h`
  - `data/battle_scripts_1.s`
- Combat engine logic:
  - `src/battle_script_commands.c`
  - `src/battle_move_resolution.c`
  - `src/battle_util*.c`
  - `src/battle_ai_*.c`
- Item definitions and behavior:
  - `include/constants/items.h` (item IDs)
  - `src/data/items.h` (item table: price/pocket/effects/callbacks)
  - `src/item.c` (bag plumbing and item metadata access)
  - `src/item_use.c` + `include/item_use.h` (field and battle use flows)
- Shops/marts:
  - `src/shop.c` + `include/shop.h`
  - map script inventories in `data/maps/*/scripts.inc` via `pokemart <ListLabel>`
- Script engine extension points:
  - `src/scrcmd.c` (command implementations)
  - `data/script_cmd_table.inc` (command index table)
  - `data/specials.inc` + `src/field_specials.c` (special functions)
- Configuration gates:
  - `include/config/battle.h`
  - `include/config/item.h`

## Generated Files (Do Not Hand-Edit)

- `data/maps/*/{header.inc,events.inc,connections.inc}` (from `map.json` by mapjson).
- `include/constants/map_event_ids.h` (generated from all map json files).
- `src/data/trainers.h` (generated from `src/data/trainers.party`).
- `include/constants/script_commands.h` (generated from script command table tooling).

## Decision Rule

- If a feature can be expressed by table/config updates, prefer data edits.
- If the feature needs runtime state/control flow not expressible in tables, edit C.
- If map scripts only need to call C logic, prefer `special` over adding a brand-new opcode.

## Fast Checklist

1. Identify subsystem and source files.
2. Check for generated targets before editing.
3. Implement minimal change.
4. Build and run targeted tests.
