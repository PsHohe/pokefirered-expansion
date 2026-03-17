# AGENTS.md

## Project At A Glance
- `pokefirered-expansion` is a decompilation-based Game Boy Advance ROM project.
- Default build target is FireRed (`pokefirered.gba`).
- Main workflow is `make`-driven; build tools and many generated assets are handled automatically.

## Technologies Used
- C (GNU17) for gameplay/engine code (`src/`).
- ARM/Thumb assembly for low-level and data assembly (`asm/`, `data/*.s`).
- GNU Make build orchestration (`Makefile` + `*_rules.mk`).
- Python 3 scripts for generated headers/data (`tools/`, `migration_scripts/`).
- Asset/data pipelines for graphics, audio, maps, and JSON (`graphics/`, `sound/`, `data/`).

## Basic Commands
- `make` : Build default ROM (`pokefirered.gba`).
- `make check` : Build and run headless test suite.
- `make check TESTS="<pattern>"` : Run filtered tests (pattern passed to test runner).
- `make debug` : Debug-oriented build.
- `make release` : Release build (LTO controlled by `config.mk`).
- `make compare` : Build and checksum-compare against reference ROM.
- `make leafgreen` : Build LeafGreen instead of FireRed.
- `make tidy` : Remove built ROM/ELF/map artifacts.
- `make clean` : Full cleanup (artifacts, generated assets, tools, test tools).
Note: adding `-j8` is the correct way to make `make` run faster in this device.

## Main Organization
- `src/` : Primary game logic and systems.
- `src/data/` : C-side structured game data.
- `include/` : Headers, configs, constants, shared declarations.
- `constants/` : Constant definition headers used across systems.
- `data/` : Assembled data, map data, script-related assets.
- `graphics/`, `sound/` : Source assets and audio data.
- `asm/` : Assembly sources.
- `test/` : Automated test suites and test runner.
- `tools/` : Native helper tools used by the build.
- `build/` : Intermediate build outputs (do not hand-edit).

## Agent Working Notes
- Prefer editing source/data inputs, not generated outputs or build artifacts (`build/`, `*.gba`, `*.elf`, `*.map`).
- If changing build behavior, inspect `Makefile`, `make_tools.mk`, and the relevant `*_rules.mk` file together.
- When touching gameplay behavior, run `make check` before finalizing.
