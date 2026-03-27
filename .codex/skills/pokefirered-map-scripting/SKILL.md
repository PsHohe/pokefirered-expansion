---
name: pokefirered-map-scripting
description: Build and modify overworld map scripts and map event wiring for pokefirered-expansion with Poryscript-first workflow. Use when working in data/maps/*/{map.json,scripts.pory,scripts.inc,text.inc}, adding or changing cutscenes or NPC interactions, wiring coord/bg/object/warp triggers, selecting MAP_SCRIPT_* lifecycle hooks, migrating legacy script sources to Poryscript, or integrating map script includes in data/event_scripts.s.
---

# PokeFireRed Map Scripting (Poryscript-First)

## Overview

Implement map gameplay logic by editing source-of-truth files, preferring Poryscript where available, and respecting generated-file boundaries.

## Workflow

1. Decide scope before editing:
- Existing map behavior change:
  - If `data/maps/<MapName>/scripts.pory` exists, edit `scripts.pory`.
  - If only `scripts.inc` exists, create `scripts.pory` first with `scripts/convert_map_script_to_pory.sh <map-dir|scripts.inc-path>`, then edit `scripts.pory`.
- Event placement or trigger wiring change: Edit `map.json` (source of truth for object/warp/coord/bg events).
- New map: Add map folder and JSON, create `scripts.pory`, and ensure `data/event_scripts.s` includes `data/maps/<MapName>/scripts.inc`.

2. Edit only source-of-truth files:
- Edit: `data/maps/<MapName>/map.json`
- Edit (required for script logic changes): `data/maps/<MapName>/scripts.pory`
- Edit (legacy text only): `data/maps/<MapName>/text.inc`
- Do not edit: `data/maps/<MapName>/events.inc`
- Do not edit: `data/maps/<MapName>/header.inc`
- Do not edit: `data/maps/<MapName>/connections.inc`
- Do not edit: `include/constants/map_event_ids.h`

3. Apply Poryscript compilation model:
- This repo compiles `data/%.pory` into `data/%.inc` via `make`.
- Keep `.inc` include paths in `data/event_scripts.s`; do not include `.pory` directly there.
- Treat `scripts.inc` as generated output whenever sibling `scripts.pory` exists.

4. Choose the correct trigger mechanism:
- Use object events for A-button NPC/object interactions.
- Use bg events for signs and hidden items.
- Use coord events for tile-entry triggers and weather tiles.
- Use map scripts (`MAP_SCRIPT_*`) for lifecycle logic.
- Use `ON_FRAME_TABLE` and `ON_WARP_INTO_MAP_TABLE` for conditional table-driven triggers.

5. Validate after edits:
- Run `make -j8` to ensure script compilation and assembly pass.

## Poryscript Authoring Rules

- Use `elif`, never `else if`.
- Use structured flow (`if`, `switch`, `while`, `do ... while`) instead of label/goto unless required.
- End top-level NPC scripts with explicit cleanup and `end` or `return`.
- Use `msgbox("...")` for short one-off text; use `text` blocks for reused dialogue.
- Use `format("...")` only for manual strings when auto-wrap is desired.
- Use `moves(...)` for short inline movement and `movement` blocks for reusable paths.
- Use `value(...)` when comparing `var(...)` against literals that might be reinterpreted as var ids.

## Multiselect Pattern (Poryscript)

Use this pattern when a script needs dynamic options and post-selection branching:

```pory
lock
faceplayer

dynmultichoice(20, 8, FALSE, 4, 0, NULL, "Test 1", "Test 2", "Test 3", "Test 4")
switch (var(VAR_RESULT)) {
    case 0:
        msgbox("Pressed Test 1.", MSGBOX_NPC)
    case 1:
    case 2:
        msgbox("Pressed Test 2 or 3.", MSGBOX_NPC)
    default:
        msgbox("Pressed Test 4.", MSGBOX_NPC)
}

dynmultipush("First option", 0)
dynmultipush("Second option", 1)
if (flag(FLAG_SYS_GAME_CLEAR)) {
    dynmultipush("Secret option", 2)
}
dynmultistack(20, 8, TRUE, 4, FALSE, 0, NULL)
switch (var(VAR_RESULT)) {
    case 0:
        msgbox("Pressed First option.", MSGBOX_NPC)
    case 1:
        msgbox("Pressed Second option.", MSGBOX_NPC)
    case 2:
        msgbox("Pressed Secret option.", MSGBOX_NPC)
    default:
        msgbox("Pressed nothing.", MSGBOX_NPC)
}

release
end
```

Assume `VAR_RESULT` is overwritten by each selection command. Branch immediately after each selector when deterministic behavior is required.

## Migration Guidance (Legacy `.inc` to `.pory`)

1. Preserve existing script labels referenced by `map.json` events.
2. Convert one map at a time with `scripts/convert_map_script_to_pory.sh <map-dir|scripts.inc-path>`.
3. Keep the generated `raw`-wrapped baseline behavior-equivalent before refactoring into native Poryscript statements.
4. Leave `text.inc` untouched unless intentionally moving dialogue into Poryscript `text` blocks.
5. Compile with `make -j8` and fix syntax or label regressions before additional edits.

## Design Consultant Subagent

Use a subagent as a consultant for dialogue, pacing, and player-facing presentation only. Keep code edits in the main agent.

Use a prompt equivalent to:
- "Act as a Pokemon game designer consultant. Do not write code. Propose player-facing dialogue and feature presentation improvements for this map/script change. Enforce max 32 visible characters per line in dialogue output. Keep tone appropriate for an official Pokemon game."

Treat consultant output as design input and implement final script changes yourself.

## Trigger Selection

- `MAP_SCRIPT_ON_TRANSITION`: Run on map load transition for setup that should happen every entry.
- `MAP_SCRIPT_ON_LOAD`: Run after map layout initialization; use for persistent map setup (metatiles/object state setup).
- `MAP_SCRIPT_ON_RESUME`: Run when returning to live overworld control on that map.
- `MAP_SCRIPT_ON_RETURN_TO_FIELD`: Run after returning to field and respawning objects.
- `MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE`: Run one matching entry in a `map_script_2` table after warp/object init.
- `MAP_SCRIPT_ON_FRAME_TABLE`: Poll each frame, run first matching `map_script_2` entry, and start a normal script context.

For map script timing details, read [map-script-lifecycle.md](references/map-script-lifecycle.md).

## Resources (Load As Needed)

- Read [workflow-and-file-ownership.md](references/workflow-and-file-ownership.md) for practical edit flow.
- Read [map-script-lifecycle.md](references/map-script-lifecycle.md) when choosing map script hooks.
- Read [map-events-and-capabilities.md](references/map-events-and-capabilities.md) for JSON event schema and interaction behavior.
- Read [poryscript-authoring.md](references/poryscript-authoring.md) for syntax, control flow, string, and migration-safe compile guidance.
- Read [poryscript-multiselect.md](references/poryscript-multiselect.md) for dynamic multiselect patterns and `VAR_RESULT` branching rules.
- Read [dialogue-and-design-consultant.md](references/dialogue-and-design-consultant.md) for dialogue constraints and consultant workflow.
- Use [`scripts/convert_map_script_to_pory.sh`](scripts/convert_map_script_to_pory.sh) to create `scripts.pory` from legacy `scripts.inc` before editing script logic.
