# Map Script Lifecycle

## Core Dispatch Model

Map headers store a `mapScripts` pointer. The engine scans entries as pairs of:

- `1 byte`: script type tag (`MAP_SCRIPT_*`)
- `4 bytes`: pointer to script or `map_script_2` table

The main map script list ends at `.byte 0`.

## Script Types

- `MAP_SCRIPT_ON_LOAD`:
  - Executed via `RunOnLoadMapScript()`.
  - Triggered during map init (`InitMap` / `InitMapFromSavedGame`).
  - Runs immediately (`RunScriptImmediately`).
- `MAP_SCRIPT_ON_TRANSITION`:
  - Executed during map load transition and warp loading before map init.
  - Runs immediately.
- `MAP_SCRIPT_ON_RESUME`:
  - Executed when overworld resumes map control.
  - Runs immediately.
- `MAP_SCRIPT_ON_RETURN_TO_FIELD`:
  - Executed when returning to field and respawning objects.
  - Runs immediately.
- `MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE`:
  - Points to a `map_script_2` table.
  - Called after object spawn in local/link init.
  - Runs first matching entry immediately.
- `MAP_SCRIPT_ON_FRAME_TABLE`:
  - Points to a `map_script_2` table.
  - Polled every frame from field input loop.
  - Starts matched script in standard script context (`ScriptContext_SetupScript`), so waits/locks behave as normal event scripts.
- `MAP_SCRIPT_ON_DIVE_WARP`:
  - Constant exists; generally unused in this project.

## `map_script_2` Matching Semantics

Table entry layout:

- `.2byte var`
- `.2byte compare`
- `.4byte script`

Table terminator:

- `.2byte 0`

Runtime check is `VarGet(var) == VarGet(compare)`.

Practical consequence:

- `compare` may be literal value (`0`, `1`, enum constants) or another variable ID.
- This is why patterns like `map_script_2 VAR_TEMP_1, 0, ...` are valid.

## Coord Event Runtime Behavior

For each coord event at current tile/elevation:

- `script == NULL`: treat as weather coord event and run weather change function using `trigger` field.
- `trigger == 0`: run script immediately with `RunScriptImmediately`.
- Otherwise: run script only if `VarGet(trigger) == index`.

## Interaction Priority (A Button)

When player interacts, engine checks in this order:

1. object event script
2. bg event script
3. metatile interaction script (PC/bookshelf/sign-like tile behaviors)
4. water interaction script (surf/waterfall/current)

Use this order when debugging why one script does not fire.
