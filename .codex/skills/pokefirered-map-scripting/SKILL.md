---
name: pokefirered-map-scripting
description: Build and modify overworld map scripts and map event wiring for pokefirered-expansion. Use when working in data/maps/*/{map.json,scripts.inc,text.inc}, adding or changing cutscenes or NPC interactions, designing player-facing dialogue/features, wiring coord/bg/object/warp triggers, selecting MAP_SCRIPT_* lifecycle hooks, or integrating new map scripts/text into data/event_scripts.s.
---

# PokeFireRed Map Scripting

## Overview

Implement map gameplay logic correctly in this codebase by editing the right source files, choosing the right trigger type, and respecting generated-file boundaries. Follow this workflow for both small script tweaks and full new-map scripting.

## Workflow

1. Decide scope before editing:
- Existing map behavior change: Edit that map's `scripts.inc`, `text.inc`, and optionally `map.json`.
- Event placement or trigger wiring change: Edit `map.json` (source of truth for object/warp/coord/bg events).
- New map: Add map folder and JSON, then add script/text includes in `data/event_scripts.s`.

2. Edit only source-of-truth files:
- Edit: `data/maps/<MapName>/map.json`
- Edit: `data/maps/<MapName>/scripts.inc`
- Edit: `data/maps/<MapName>/text.inc`
- Do not edit: `data/maps/<MapName>/events.inc`
- Do not edit: `data/maps/<MapName>/header.inc`
- Do not edit: `data/maps/<MapName>/connections.inc`
- Do not edit: `include/constants/map_event_ids.h`

3. Choose the correct trigger mechanism:
- Use object events for A-button NPC/object interactions.
- Use bg events for signs and hidden items.
- Use coord events for tile-entry triggers and weather tiles.
- Use map scripts (`MAP_SCRIPT_*`) for lifecycle logic.
- Use `ON_FRAME_TABLE` and `ON_WARP_INTO_MAP_TABLE` for conditional table-driven triggers.

4. Validate after edits:
- Run `make -j8` to ensure assembly/data changes compile.
- If gameplay behavior changed, run `make check`.

## Design Consultant Subagent

Use a subagent as a consultant for game design tasks when subagents are available in the current environment and the task is dialogue/player-facing design rather than code mechanics.

Spawn a consultant subagent for:
- NPC dialogue drafting or rewrite
- cutscene pacing/flow
- player-facing UX copy (prompts, signs, tutorial text)
- thematic consistency checks for a Pokemon-style tone

Do not delegate code editing to this consultant. Keep code edits in the main agent.

Use a prompt equivalent to:
- "Act as a Pokemon game designer consultant. Do not write code. Propose player-facing dialogue and feature presentation improvements for this map/script change. Enforce max 32 visible characters per line in dialogue output. Keep tone appropriate for an official Pokemon game."

Treat consultant output as design input. Integrate, adapt, and then implement script/text changes in this repository.

## Trigger Selection

- `MAP_SCRIPT_ON_TRANSITION`: Run on map load transition for setup that should happen every entry.
- `MAP_SCRIPT_ON_LOAD`: Run after map layout initialization; use for persistent map setup (metatiles/object state setup).
- `MAP_SCRIPT_ON_RESUME`: Run when returning to live overworld control on that map.
- `MAP_SCRIPT_ON_RETURN_TO_FIELD`: Run after returning to field and respawning objects.
- `MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE`: Run one matching entry in a `map_script_2` table after warp/object init.
- `MAP_SCRIPT_ON_FRAME_TABLE`: Poll each frame, run first matching `map_script_2` entry, and start a normal script context.

For script-type timing and engine call order details, read [map-script-lifecycle.md](references/map-script-lifecycle.md).

## Resources (optional)

Read references by need:
- Read [workflow-and-file-ownership.md](references/workflow-and-file-ownership.md) first for practical edit flow.
- Read [map-script-lifecycle.md](references/map-script-lifecycle.md) when choosing map script hooks or debugging timing issues.
- Read [map-events-and-capabilities.md](references/map-events-and-capabilities.md) for JSON event schema, interaction priority, and script command capabilities.
- Read [dialogue-and-design-consultant.md](references/dialogue-and-design-consultant.md) for Pokemon dialogue constraints and consultant workflow.
