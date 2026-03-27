# Poryscript Authoring

## Scope

Use this reference when writing or reviewing `scripts.pory` files in this repository.

## Core Syntax Rules

- Use top-level statements: `mapscripts`, `script`, `text`, `movement`, `mart`, `raw`, `const`, `poryswitch`.
- Use `elif` (never `else if`).
- Call commands with parentheses when arguments exist.
- Use structured control flow (`if`, `switch`, `while`, `do ... while`) instead of label/goto by default.
- End event scripts explicitly with `end` or `return`.

## Mandatory Legacy Conversion Rule

- Always write new map script changes in `scripts.pory`.
- If a map has only `scripts.inc`, create `scripts.pory` first.
- Use the bundled converter:
  - `scripts/convert_map_script_to_pory.sh <map-dir|scripts.inc-path>`
- The converter copies `scripts.inc` into a `raw` block in `scripts.pory` so behavior remains unchanged while enabling incremental Poryscript refactors.

## Conditions And Comparisons

- Use left-side forms: `flag(...)`, `var(...)`, `defeated(...)`, or AutoVar command expressions.
- Use `value(...)` around numeric literals that could be interpreted as variable IDs in var comparisons (for example values in ranges like `0x4000..0x40FF` or `0x8000..0x8015`).
- Use boolean operators `&&`, `||`, and `!` for compound checks.

## String And Text Guidance

- Use double-quoted strings.
- Let Poryscript append `$` for normal text; do not add it manually.
- Use auto strings for fast drafting readability.
- Use manual strings when explicit `\n`, `\l`, `\p` control is required.
- Use `format("...")` only on manual strings when auto-wrap is desired.
- Use `text` blocks for reused lines or long dialogue; use inline strings for short one-off messages.

## Mapscripts Guidance

- Define map script tables in `mapscripts <MapName>_MapScripts { ... }`.
- Use direct label hooks for simple lifecycle scripts.
- Use frame-table / warp-table map scripts for conditional dispatch.
- Keep an empty block when no map scripts are needed:

```pory
mapscripts SomeMap_MapScripts {
}
```

## Movement, Mart, And Raw

- Use `moves(...)` for short single-use movement sequences.
- Use `movement` blocks for reusable movement paths.
- Use `mart` blocks for Pokemart item lists.
- Use `raw` for migration baselines or when Poryscript lacks needed output form.
- Do not place comments inside `raw` blocks.

## AutoVar And Switch Patterns

- Prefer direct AutoVar expressions when supported:

```pory
if (checkitem(ITEM_POTION)) {
    msgbox("You have one.")
}
```

- Switch on `var(VAR_RESULT)` after commands that write to result vars.
- Do not rely on switch fallthrough.

## Compile And Integration Rules

- Keep `data/event_scripts.s` includes pointing to `scripts.inc`.
- Treat `scripts.inc` as generated after `scripts.pory` exists.
- Validate with `make -j8` after script edits.

## Common Pitfalls

1. Writing `else if` instead of `elif`.
2. Editing `scripts.inc` after creating `scripts.pory`.
3. Mixing auto string layout with `format()` expectations.
4. Forgetting script termination (`end`/`return`).
5. Introducing labels/goto where structured flow is simpler.
