# Combat Systems

## Capability Surface In This Engine

- The project already supports a large modern battle feature set (terrain, weather variants, gimmicks, advanced AI hooks, many move effects).
- Move behavior is primarily table-driven:
  - Move metadata in `src/data/moves_info.h`.
  - Effect-to-script mapping in `src/data/battle_move_effects.h`.
  - Effect enum catalog in `include/constants/battle_move_effects.h`.
  - Scripted flow in `data/battle_scripts_1.s`.

## Typical Change Patterns

### 1) Tune an existing move

- Edit move fields in `src/data/moves_info.h` (`power`, `accuracy`, `target`, flags, `effect`).
- If needed, adjust config interactions in `include/config/battle.h`.
- Add/update tests in `test/battle/move_effect/` or `test/battle/move_effect_secondary/`.

### 2) Add or change effect behavior

- Reuse an existing `EFFECT_*` when possible.
- If a new effect is required:
  - add enum entry in `include/constants/battle_move_effects.h`
  - add mapping in `src/data/battle_move_effects.h`
  - add or update battle script labels in `data/battle_scripts_1.s`
  - extend C command logic in `src/battle_script_commands.c` only where script opcodes need new behavior
- Wire affected moves in `src/data/moves_info.h`.

### 3) Add script-command-level battle behavior

- Use existing battle script opcodes first (`include/constants/battle_script_commands.h`).
- If absolutely necessary, implement new opcode handling in `src/battle_script_commands.c` and keep enum consistency.
- Avoid reserved/unused opcode slots unless there is no safer extension path.

## Trainer Battle Content

- Trainer script invocation lives in map/global scripts (for example `trainerbattle_*` macros in `data/scripts/trainers.inc`).
- Trainer data source is `src/data/trainers.party`; generated output is `src/data/trainers.h`.
- Edit `.party` source, not generated header.

## Practical Guardrails

- Prefer adding behavior behind existing config tags when generation-specific behavior already exists.
- Keep move effect behavior and battle scripts synchronized; mismatches cause subtle runtime desync.
- Add tests for both expected success path and failure/immunity path.
