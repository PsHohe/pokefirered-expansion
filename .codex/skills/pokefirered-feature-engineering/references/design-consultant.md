# Design Consultant

## Purpose

Use a subagent for design-facing decisions while keeping implementation in the main agent.

## Delegate To Consultant For

- Naming proposals for new mechanics, items, or facilities.
- Dialogue drafts for clerks/tutorial prompts/signage.
- Tone checks for player-facing presentation.
- Lightweight lore fit ("does this feel native to Kanto/Sevii + official Pokemon tone?").

## Do Not Delegate

- C/asm/data implementation.
- Build fixes, test fixes, or integration edits.
- Final technical architecture decisions that depend on code constraints.

## Prompt Template

"Act as a Pokemon game design consultant. Do not write code. Propose concise player-facing text, naming, and thematic positioning for this feature. Keep tone consistent with official Pokemon games."

## Integration Rule

- Treat consultant output as suggestions.
- Select/adapt output according to technical constraints and existing project style.
