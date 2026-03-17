# Dialogue And Design Consultant

## Consultant Workflow

Use a subagent as a game-design consultant when:

- writing new NPC dialogue
- revising existing dialogue tone
- designing player-facing feature messaging
- tuning cutscene readability and pacing

Keep this consultant non-code:

- ask for design rationale, player impact, and final dialogue candidates
- avoid asking for C/asm implementation details

## Consultant Prompt Template

Use a prompt equivalent to:

"Act as a Pokemon game designer consultant. Do not write code. Improve dialogue and player-facing presentation for the provided map/event context. Enforce max 32 visible characters per line. Keep tone consistent with official Pokemon games."

## Pokemon Dialogue Rules

- Keep language concise, friendly, and adventure-focused.
- Keep characterization clear in one or two lines per beat.
- Prefer short sentences and concrete verbs.
- Avoid modern slang that feels out-of-setting.
- Keep iconic Pokemon stylistic conventions where appropriate (for example: "POKeMON" formatting already used by project text labels).

## Line-Length Constraint

Hard rule:

- Max `32` visible characters per line.

Apply before converting to `.string` format:

- Count visible characters only.
- Keep each final line at or below 32.
- If a line exceeds 32, rewrite; do not rely on overflow.

When placeholders exist (`{PLAYER}`, `{STR_VAR_1}`, etc.):

- Reserve extra space for expansion.
- Prefer a safer target (`<= 26`) on lines containing placeholders.

## Output Format For Review

Ask consultant to return:

1. Final dialogue lines (already constrained to <= 32 chars each).
2. A short rationale (tone/pacing/player guidance).
3. Optional alternatives for key lines.

Then convert approved lines into map `text.inc` strings using `\n`, `\p`, and script flow as needed.
