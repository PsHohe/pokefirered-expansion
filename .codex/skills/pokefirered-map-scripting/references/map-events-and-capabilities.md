# Map Events And Capabilities

## `map.json` Event Types

`mapjson` supports:

- `object_events`:
  - `type: "object"` (default when omitted)
  - `type: "clone"` (clone another object's behavior via `target_local_id` + `target_map`)
- `warp_events`
- `coord_events`:
  - `type: "trigger"`
  - `type: "weather"` (manual JSON use; editor support may be disabled)
- `bg_events`:
  - `type: "sign"`
  - `type: "hidden_item"`
  - `type: "secret_base"` (engine support exists; FRLG usage is limited)

## Object Event Notes

- Generated local ID is position-based (`i + 1` in array).
- Optional `local_id` in JSON generates constants in `include/constants/map_event_ids.h`.
- Keep scripts using named `LOCALID_*` constants for resilience.
- `script: "0x0"` creates non-interactable placeholders for cutscene-controlled objects.
- `movement_range_x` is 4-bit in packed template; values above `15` overflow and are rejected by macro guard.

## Bg Event Notes

- Sign events use facing constraints (`BG_EVENT_PLAYER_FACING_*`).
- Hidden item data packs item/flag/quantity/underfoot into one field.
- Underfoot hidden items are not triggered by normal sign interaction path.

## Coord Event Notes

- For trigger events, map JSON fields map to:
  - `var` -> `CoordEvent.trigger`
  - `var_value` -> `CoordEvent.index`
  - `script` -> `CoordEvent.script`
- A trigger `var` of `0` means unconditional immediate script execution on step-in.

## Shared Script/Event Maps

- `shared_scripts_map` in `map.json` makes generated `header.inc` point to `<shared>_MapScripts`.
- `shared_events_map` can similarly redirect map events pointer.
- Use these to avoid duplicating identical map script/event banks across map variants.

## Script Language Capability Surface

The script command table (`data/script_cmd_table.inc`) and macros (`asm/macros/event.inc`) provide broad map capabilities:

- Flow/control: `goto`, `call`, `goto_if_*`, `call_if_*`, switches
- State: `setvar`, `addvar`, `setflag`, `checkflag`, comparisons
- NPC/object control: `addobject`, `removeobject`, `setobjectxy`, `applymovement`, `turnobject`, `faceplayer`
- Map changes: `setmetatile`, `setwarp`, `warp*`, door commands, weather commands
- Encounters/battles: `trainerbattle_*`, `setwildbattle`, `dowildbattle`
- UI/text/audio: `msgbox`, `message`, multichoice, sfx/bgm/fades
- C-side hooks: `special`, `specialvar`, `callnative`

Use `special` or `callnative` for advanced behavior that is not directly expressible through script opcodes.

## Integration Points Outside Map Folder

For new map script/text banks, add explicit includes to `data/event_scripts.s`:

- scripts section: `data/maps/<MapName>/scripts.inc`
- text section: `data/maps/<MapName>/text.inc`

`mapjson` does not auto-register map script/text include lines there.
