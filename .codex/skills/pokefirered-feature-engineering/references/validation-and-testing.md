# Validation And Testing

## Minimum Validation

1. Build with `make -j8`.
2. Run targeted tests for touched subsystems.

## Targeted Test Patterns

- Battle mechanics:
  - `make check TESTS="test/battle/move_effect/<feature>.c"`
  - or name-filtered: `make check TESTS="<Mechanic Prefix>"`
- Item/bag behavior:
  - `make check TESTS="test/bag.c"`
  - `make check TESTS="test/battle/item_effect/"`
- Script-level behavior:
  - use script/unit tests where available, then run broader `make check`.

## When To Run Full Suite

- Run full `make check` when:
  - touching central battle execution (`battle_script_commands.c`, move-resolution core, shared effect systems),
  - changing item usage dispatch paths,
  - or editing shared script command plumbing.

## Regression Checklist

- Confirm build passes with no new warnings/errors.
- Confirm data tables and enums stay in sync after additions.
- Confirm no generated files were hand-edited.
- Confirm script command / special paths still return control correctly (`ScriptContext_Stop` vs `ScriptContext_Enable` patterns).
