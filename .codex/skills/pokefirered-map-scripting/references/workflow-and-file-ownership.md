# Workflow And File Ownership

## Source Of Truth

- Edit `data/maps/<MapName>/map.json` for:
  - `object_events`
  - `warp_events`
  - `coord_events`
  - `bg_events`
  - map header fields (music, weather, map type, allow flags, etc.)
- Edit script sources with this priority:
  - If `data/maps/<MapName>/scripts.pory` exists, edit `scripts.pory`.
  - If no `scripts.pory` exists, consider migrating to `scripts.pory`, otherwise edit `scripts.inc` (legacy path).
- Edit `data/maps/<MapName>/text.inc` only for legacy maps that still store dialogue outside Poryscript.

## Generated Files (Do Not Hand-Edit)

- `data/maps/<MapName>/events.inc`
- `data/maps/<MapName>/header.inc`
- `data/maps/<MapName>/connections.inc`
- `include/constants/map_event_ids.h`
- `data/maps/<MapName>/scripts.inc` when sibling `scripts.pory` exists

`events.inc`, `header.inc`, and `connections.inc` are generated from `map.json` via map tools. `scripts.inc` is generated from `scripts.pory` by the Make rule `data/%.inc: data/%.pory`.

## Existing-Map Change Checklist

1. Choose script input:
   - Edit `scripts.pory` when present.
   - Otherwise edit `scripts.inc`.
2. If event placements/triggers changed, edit `map.json` (not `events.inc`).
3. Keep script labels referenced by `map.json` unchanged unless you also update those event pointers.
4. Build with `make -j8`.

## New Map Checklist

1. Add map directory with `map.json`.
2. Add `scripts.pory` (preferred) or `scripts.inc` (legacy fallback).
3. Add script include in `data/event_scripts.s`:
   - `\t.include "data/maps/<MapName>/scripts.inc"`
4. Add text include in `data/event_scripts.s` only when using map-local `text.inc` labels:
   - `\t.include "data/maps/<MapName>/text.inc"`
5. Ensure the map is wired in map groups/config as required by project workflow.
6. Build with `make -j8`.

## Data Ownership Notes

- `map.json` object order defines runtime local IDs (`1..N`) in generated `events.inc`.
- Prefer named `local_id` constants from `include/constants/map_event_ids.h` instead of hardcoded object numbers.
- `shared_scripts_map` in `map.json` points map header script pointer to another map's `<MapName>_MapScripts`.
- `shared_events_map` is supported for shared event pointers.

## Quick Example Split

- Add sign text and script:
  - Add sign event in `map.json`.
  - Add script body in `scripts.pory`/`scripts.inc`.
  - Keep or add `text.inc` only if that script references external text labels.

- Add one-time cutscene on tile:
  - Add coord trigger in `map.json`.
  - Gate with a var/flag in script.
  - Set the var/flag at cutscene end.
