# Troubleshooting

## Pink block with sprite fragments when moving

Cause:
- `.4bpp` was built with generic conversion (no metatile packing), so frame tiles are in the wrong order.

Fix:
1. Add a dedicated conversion rule in `spritesheet_rules.mk`.
2. Use the correct `-mwidth` and `-mheight` for the sprite layout.
3. Rebuild the `.4bpp` and then rebuild ROM.

For standard 16x32 NPC sheets:
```make
$(OBJEVENTGFXDIR)/people/<name>.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4
```

## Sprite has opaque background box

Cause:
- Transparent pixels are not palette index 0.

Fix:
1. Reindex the PNG palette.
2. Move transparent color to index 0.
3. Rebuild.

## Sprite colors are wrong

Cause:
- Palette tag mismatch or palette not registered in `sObjectEventSpritePalettes`.

Fix:
1. Confirm `OBJ_EVENT_PAL_TAG_*` exists.
2. Confirm `.paletteTag` in graphics info uses that tag.
3. Confirm `src/event_object_movement.c` includes `{gObjectEventPal_<Name>, OBJ_EVENT_PAL_TAG_<NAME>}`.

## Undefined symbol compile errors

Cause:
- Incomplete registration or declaration placed in wrong conditional block.

Fix:
1. Verify declarations and definitions exist in all required files.
2. Verify new entries are outside incompatible `#if IS_FRLG` blocks unless intentionally FRLG-only.
