---
name: pokefirered-overworld-object-sprite
description: Add or update a non-Pokemon object-event overworld sprite in pokefirered-expansion. Use when a request involves adding an NPC/character sprite from a PNG, wiring a new OBJ_EVENT_GFX_* constant, registering object-event graphics/palette structs, updating sprite conversion rules in spritesheet_rules.mk, or fixing visual issues such as pink blocks, fragmented frames, or incorrect overworld colors.
---

# Pokefirered Overworld Object Sprite

## Overview

Implement a complete, build-safe workflow for adding NPC/object-event overworld sprites.
Prevent common rendering failures by enforcing correct tile-packing conversion rules and palette wiring.

## Workflow

1. Confirm the sprite type and layout.
- Treat this skill as object-event NPC sprite work (not follower Pokemon sprite work).
- For standard human NPCs, use 16x32 frames with a 144x32 sheet (9 frame slots) and `overworld_ascending_frames(..., 2, 4)`.

2. Place the source PNG.
- Save the source at `graphics/object_events/pics/people/<name>.png`.
- Keep indexed color (`mode P`), 16 colors max, and transparent background as palette index 0.

3. Add conversion rule in `spritesheet_rules.mk` (critical).
- Add a specific rule for the new `.4bpp` target, near similar people sprites.
- For standard 16x32 NPC sheets, use:
```make
$(OBJEVENTGFXDIR)/people/<name>.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4
```
- Do not rely on the generic `%.4bpp: %.png` fallback for object-event people sprites.

4. Register graphics IDs and palette tags.
- Add a new `OBJ_EVENT_GFX_*` define in `include/constants/event_objects.h`.
- Append at the end of the object gfx block and bump `NUM_OBJ_EVENT_GFX` to avoid renumbering existing IDs.
- Add a new `OBJ_EVENT_PAL_TAG_*` define with a unique tag value.

5. Register graphics and palette data.
- Add `INCBIN_U32` for the new `.4bpp` in `src/data/object_events/object_event_graphics.h`.
- Add `INCBIN_U16` for the `.gbapal` in the same file.
- Add a `sPicTable_<Name>` entry in `src/data/object_events/object_event_pic_tables.h`.
- Add `gObjectEventGraphicsInfo_<Name>` in `src/data/object_events/object_event_graphics_info.h`.
- Add `extern` + pointer mapping entry in `src/data/object_events/object_event_graphics_info_pointers.h`.
- Add the new palette to `sObjectEventSpritePalettes` in `src/event_object_movement.c`.

6. Build and validate.
- Run `make -j8`.
- If build fails with undefined palette/graphics symbols, verify declarations are in the active build path and not accidentally placed under mismatched conditionals (`#if IS_FRLG`/`#if !IS_FRLG`, etc).

7. Use on map objects.
- In `data/maps/<MapName>/map.json`, set:
```json
"graphics_id": "OBJ_EVENT_GFX_<NAME>"
```
- Rebuild and verify in-game.

## Decision Rules

- Reuse existing palette tags only when deliberately sharing palette colors with another sprite.
- Create a new palette tag when the PNG uses its own palette and color fidelity matters.
- Keep edits in source-of-truth files only; do not hand-edit generated map includes.

## Debug Checklist

1. Pink block with fragmented sprite while moving:
- Ensure `spritesheet_rules.mk` has the specific `<name>.4bpp` rule with correct `-mwidth/-mheight`.

2. Solid box around sprite:
- Ensure transparent background is palette index 0 in the source PNG.

3. Colors look wrong:
- Ensure a palette tag exists and is loaded in `sObjectEventSpritePalettes`.
- Ensure `.paletteTag` in graphics info matches that tag.

4. Compile error for new symbol:
- Ensure declaration/definition/mapping were all added across graphics, graphics info, and pointer tables.

## References

- File registration checklist: [references/registration-files.md](references/registration-files.md)
- Troubleshooting patterns: [references/troubleshooting.md](references/troubleshooting.md)
