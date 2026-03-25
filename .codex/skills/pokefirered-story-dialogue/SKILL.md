---
name: pokefirered-story-dialogue
description: Design and implement story beats, character dialogue choices, and narrative decision outcomes for pokefirered-expansion (a Pokemon game). Use when requests involve NPC dialogue, quest/cutscene branches, character motivation, lore consistency, or translating narrative decisions into map script/text changes in data/maps/* and data/event_scripts.s.
---

# PokeFireRed Story & Dialogue

## Overview

Implement narrative decisions with clear player-facing outcomes, Pokemon-appropriate tone, and repository-correct script/text wiring.

## Workflow

1. Load narrative context first:
- Read [`knowledge-base/index.md`](../../../knowledge-base/index.md).
- Open only the linked files relevant to the requested scene or arc.

2. Define the decision clearly before writing:
- State the player choice (or hidden branch condition).
- State immediate consequence (dialogue/scene result).
- State medium-term consequence (flags, availability, follow-up encounter).

3. Keep Pokemon narrative constraints:
- Preserve hopeful/adventure-forward tone unless explicitly darker.
- Keep character voices consistent with their role and age.
- Avoid modern slang that conflicts with the setting.
- Keep stakes legible to players in short dialogue beats.

4. Implement in source-of-truth files:
- Edit `data/maps/<MapName>/text.inc` for dialogue.
- Edit `data/maps/<MapName>/scripts.inc` for branch logic and event flow.
- Edit `data/maps/<MapName>/map.json` when object/coord/bg wiring must change.
- Edit `data/event_scripts.s` when shared script/text includes are needed.
- Do not edit generated map includes directly.

5. Validate:
- Run `make -j8`.
- Check that each branch has an explicit player-readable outcome (dialogue, NPC state, item, battle, or access change).

## Output Pattern

When proposing or implementing a narrative decision, produce:
- Branch definition: trigger and alternatives.
- Dialogue draft: concise lines per outcome.
- Implementation map: exact files/symbols to edit.
- Consequence summary: short-term and follow-up effects.
