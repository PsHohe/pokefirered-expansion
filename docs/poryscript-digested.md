https://github.com/huderlem/poryscript

# Poryscript Reference for AI Script Generation

## 1. File Structure

A `.pory` file contains top-level statements:

- `script`
- `text`
- `movement`
- `mart`
- `mapscripts`
- `raw`
- `const`
- `poryswitch`

Example:
```pory
mapscripts MyMap_MapScripts {
    ...
}

script MyScript {
    ...
}

text MyText {
    "Hello.\n"
}

movement MyMovement {
    walk_left
    walk_right * 3
}

mart MyMart {
    ITEM_POTION
    ITEM_POKEBALL
}

raw `
Label:
    .string "Raw included text.$"
`


⸻

2. Scope Rules

Scope controls emitted label form:
	•	global => Label::
	•	local => Label:

Supported on:
	•	script
	•	text
	•	movement
	•	mapscripts

Syntax:

script(global) MyGlobalScript { ... }
script(local) MyLocalScript { ... }

Default scopes:

Statement	Default Scope
script	Global
text	Global
movement	Local
mart	Local
mapscripts	Global


⸻

3. script Statement

script contains commands plus control flow.

Example:

script MyScript {
    lock
    faceplayer
    if (flag(FLAG_DONE)) {
        msgbox("Already done.")
    } elif (var(VAR_COUNT) >= 3) {
        msgbox("Enough items.")
    } else {
        msgbox("Not yet.")
    }
    release
    end
}

Command syntax
	•	Bare command if no args: lock
	•	Function-style parens if args exist: msgbox("Hi"), setvar(VAR_X, 1)

⸻

4. Control Flow

if / elif / else
	•	elif is the only valid “else if” spelling.
	•	Nesting is allowed.

if (flag(FLAG_A)) {
    ...
} elif (var(VAR_B) > 0) {
    ...
} else {
    ...
}

while

while (var(VAR_RESULT) != 1) {
    msgbox("Try again?", MSGBOX_YESNO)
}

Infinite loop:

while {
    ...
    if (var(VAR_RESULT) == 0) {
        break
    }
}

do ... while

Runs body once before checking condition.

do {
    msgbox("Accept?", MSGBOX_YESNO)
} while (var(VAR_RESULT) == 0)

break and continue
	•	break exits nearest loop
	•	continue restarts nearest loop

Early exit

Use end or return.

if (flag(FLAG_ALREADY_DONE)) {
    end
}


⸻

5. Conditions and Boolean Expressions

Supported logical operators:
	•	&&
	•	||
	•	!
	•	parentheses grouping

Example:

if (flag(FLAG_CHAMPION) && !(flag(FLAG_TOWER) || flag(FLAG_DOME))) {
    msgbox("Try the facilities.")
}

Valid left-hand condition forms

The left operand must be one of:
	•	flag(...)
	•	var(...)
	•	defeated(...)
	•	an AutoVar command expression (see section 13)

Allowed comparison operators

Left side	Valid operators
flag(...)	==
var(...)	==, !=, >, >=, <, <=
defeated(...)	==
AutoVar	same as var(...)

Truthiness shortcuts

Equivalent forms:

if (flag(FLAG_X))
if (flag(FLAG_X) == true)

if (!flag(FLAG_X))
if (flag(FLAG_X) == false)

if (var(VAR_X))
if (var(VAR_X) != 0)

if (!var(VAR_X))
if (var(VAR_X) == 0)

if (defeated(TRAINER_BROCK))
if (defeated(TRAINER_BROCK) == true)

Allowed right-hand values

Left side	Valid right side
flag(...)	TRUE, true, FALSE, false
var(...)	numeric / constant / var-like expression
defeated(...)	TRUE, true, FALSE, false

value(...) for raw compare values

Gen 3 compare commands may reinterpret certain numeric ranges as vars. To force raw literal comparison, wrap the right side in value(...).

if (var(VAR_DAMAGE_DEALT) >= value(0x4000)) {
    ...
}

Use this when comparing against values in ranges like:
	•	0x4000..0x40FF
	•	0x8000..0x8015

⸻

6. switch

Rules:
	•	switch expression must be var(...) or an AutoVar-compatible value
	•	no fallthrough
	•	break inside a case is optional
	•	multiple case labels may stack
	•	optional default

switch (var(VAR_NUM_THINGS)) {
    case 0:
        msgbox("You have 0 things.")
    case 1:
    case 2:
        msgbox("You have 1 or 2 things.")
    default:
        msgbox("You have at least 3 things.")
}


⸻

7. Labels and goto

Labels may exist inside scripts.

Syntax:

MyLabel:
    ...

Example:

script MyScript {
    lockall
    if (flag(FLAG_TEST)) {
        goto(MyScript_End)
    }

MyScript_End:
    releaseall
    end
}

Notes:
	•	labels are usually unnecessary because structured control flow exists
	•	default label scope is local
	•	label scope can be explicitly made global with syntax like MyLabel(global):

⸻

8. Strings

Poryscript uses double-quoted strings everywhere.

Poryscript auto-appends the text terminator $ for normal text strings.

8.1 Auto strings

A multi-line string literal automatically inserts line-break controls and strips indentation on continuation lines.

msgbox("Hello, first line,
        second line,
        third line.

        New paragraph.")

Behavior:
	•	line transitions become \n, \l, or \p
	•	blank source line becomes paragraph break
	•	good for natural authoring

8.2 Manual strings

Adjacent quoted strings concatenate.

msgbox("Line 1.\n"
       "Line 2.\l"
       "Line 3.\p"
       "Paragraph 2.")

Use manual strings when you want precise control over break codes.

Guidance
	•	Prefer manual strings when exact textbox formatting matters.
	•	Prefer auto strings for fast drafting or readable source layout.
	•	Do not manually add $ to normal Poryscript text.

⸻

9. text Statement

Defines reusable/global text labels.

text MyText {
    "Hello there.
     Reusable text."
}

Usage:

script MyScript {
    msgbox(MyText)
}

Use text when:
	•	multiple scripts reuse the same text
	•	text must be referenced from C code
	•	inline text would clutter the script

⸻

10. format() Text Auto-Wrapping

format() automatically wraps a manual string to the configured text-box width.

Basic form:

msgbox(format("This is long text that should be automatically wrapped."))

Important:
	•	format() works with manual strings, not auto strings
	•	explicit breaks like \p, \n, \l still work
	•	special \N means: insert either \n or \l automatically

Example:

text MyText {
    format("You are my favorite trainer!\N...\N...\NBut I'm better!")
}

Parameters

Positional forms:

format("text")
format("text", "1_latin_rse")
format("text", "1_latin_rse", 100)

Named overrides:
	•	fontId
	•	maxLineLength
	•	numLines
	•	cursorOverlapWidth

Example:

text MyText {
    format("Example text.", numLines=3, maxLineLength=100)
}

Known bundled font IDs

Common defaults mentioned in docs:
	•	1_latin_rse for pokeemerald-style config
	•	1_latin_frlg for pokefirered-style config

Practical guidance
	•	Use format() for quick safe fitting
	•	Use manual strings for polished dialogue
	•	Avoid mixing auto-string layout intent with format()

⸻

11. Text Replacements

Configured via font_config.json textReplacements.

Useful shorthands are expanded automatically in all text.

Included defaults:

Pattern	Replacement
\e	é
\.	…
\au	{UP_ARROW}
\ad	{DOWN_ARROW}
\ar	{RIGHT_ARROW}
\al	{LEFT_ARROW}
\m	♂
\f	♀
\qo	“
\qc	”
\h<delay>	{PAUSE_<delay>}

Example:

text MyText {
    "Pok\emon said \qoHello!\qc\. \h30Boy\m or Girl\f?"
}

Compiles conceptually as:

text MyText {
    "Pokémon said “Hello!”… {PAUSE_30}Boy♂ or Girl♀?"
}

Notes:
	•	replacements apply globally to text
	•	regex replacements are allowed in config
	•	JSON backslashes must be escaped

⸻

12. Custom Text Encoding / String Directives

You can prefix a string literal with an assembler directive.

ascii"My ASCII string."
custom"My Custom string."

Conceptual output:

.ascii "My ASCII string.\0"
.custom "My Custom string."

Rules:
	•	.ascii gets auto \0
	•	other directives do not get an auto suffix
	•	useful for debug/custom encodings, not standard dialogue

⸻

13. AutoVar Commands

Some commands store results in a known variable (often VAR_RESULT). Poryscript lets those commands appear directly inside expressions.

Without AutoVar:

checkitem(ITEM_ROOT_FOSSIL)
if (var(VAR_RESULT) == TRUE) {
    ...
}

With AutoVar:

if (checkitem(ITEM_ROOT_FOSSIL) == TRUE) {
    ...
}

AutoVar expressions can be used anywhere var(...) can be used:
	•	if
	•	while
	•	switch
	•	compound boolean expressions

Types of AutoVar
	1.	Implicit AutoVar
The command’s destination var is defined in config.
	•	examples: checkitem, random, getpartysize
	2.	Explicit AutoVar
The command itself includes the destination var argument.
	•	examples: specialvar, checkcoins

Config is defined in command_config.json, passed via -cc.

Example config concept:

{
    "autovar_commands": {
        "specialvar": {
            "var_name_arg_position": 0
        },
        "checkitem": {
            "var_name": "VAR_RESULT"
        }
    }
}

Example usage:

if (checkitem(ITEM_POKEBLOCK_CASE)) {
    if (specialvar(VAR_RESULT, GetFirstFreePokeblockSlot) != -1 &&
        specialvar(VAR_RESULT, PlayerHasBerries)) {
        msgbox("Great! You can use the Berry Blender!")
    }
} else {
    msgbox("You don't have a Pokeblock case!")
}


⸻

14. movement Statement and moves()

Defines movement data, usually for applymovement.

movement MyMovement {
    walk_left
    walk_up * 5
    face_down
}

Usage:

applymovement(2, MyMovement)
waitmovement(0)

Rules:
	•	movement default scope is local
	•	* repeats the previous movement command
	•	generated movement data ends with step_end

Inline movement with moves()

Often preferable to separate movement.

applymovement(2, moves(
    walk_left
    walk_up * 5
    face_down
))

Also valid:

applymovement(2, moves(walk_left walk_up * 5 face_down))
applymovement(2, moves(walk_left, walk_up * 5, face_down))

Guidance:
	•	use moves() for short one-off sequences
	•	use movement for reusable or lengthy paths

⸻

15. mart Statement

Defines item lists for pokemart.

mart MyMartItems {
    ITEM_LAVA_COOKIE
    ITEM_MOOMOO_MILK
    ITEM_RARE_CANDY
}

Usage:

pokemart(MyMartItems)

Rules:
	•	default scope is local
	•	ITEM_NONE is auto-appended
	•	if ITEM_NONE appears manually, everything after it is ignored

⸻

16. mapscripts Statement

Defines map script tables.

Example:

mapscripts MyNewCity_MapScripts {
    MAP_SCRIPT_ON_RESUME: MyNewCity_OnResume

    MAP_SCRIPT_ON_TRANSITION {
        random(2)
        switch (var(VAR_RESULT)) {
            case 0: setweather(WEATHER_ASH)
            case 1: setweather(WEATHER_RAIN_HEAVY)
        }
    }

    MAP_SCRIPT_ON_FRAME_TABLE [
        VAR_TEMP_0, 0: MyNewCity_OnFrame_0
        VAR_TEMP_0, 1 {
            lock
            msgbox("This script is inlined.")
            setvar(VAR_TEMP_0, 2)
            release
        }
    ]
}

Notes:
	•	supports direct label references or inline script bodies
	•	frame-table style map scripts use []
	•	empty mapscripts block is valid:

mapscripts MyMap_MapScripts {}


⸻

17. raw Statement

Injects raw output directly.

raw `
MyLabel:
    .string "Direct raw content.$"
`

Use when:
	•	Poryscript lacks a feature/data form you need
	•	you want exact assembler/script output
	•	defining custom data blobs

Restrictions:
	•	contents are passed through directly
	•	comments are not supported inside raw

⸻

18. Comments

Valid comment styles:

# comment
// comment

Notes:
	•	both ignore the rest of the line
	•	comments cannot appear inside raw
	•	prefer // if preprocessing with the C preprocessor to avoid # conflicts

⸻

19. const

Defines compile-time constants for use within valid Poryscript expression positions.

const PROF_BIRCH_ID = 3
const ASSISTANT_ID = PROF_BIRCH_ID + 1
const FLAG_GREETED_BIRCH = FLAG_TEMP_2

Usage:

applymovement(PROF_BIRCH_ID, moves(walk_left * 4, face_down))
showobject(ASSISTANT_ID)
setflag(FLAG_GREETED_BIRCH)

Rules:
	•	must be defined before use
	•	can compose earlier constants
	•	this is not a general macro system

Valid usage positions include:
	•	command parameters
	•	condition operands / values
	•	switch vars and case values
	•	mapscript frame table entries

Example:

const CONSTANT = 1

if (flag(CONSTANT)) {}
if (var(CONSTANT) == CONSTANT) {}
if (defeated(CONSTANT)) {}

switch (var(CONSTANT)) {
    case CONSTANT:
        break
}


⸻

20. poryswitch Compile-Time Switches

Used to include different source depending on compiler switches supplied via CLI.

CLI:

./poryscript -i script.pory -o script.inc -s GAME_VERSION=RUBY -s LANGUAGE=GERMAN

Syntax:

poryswitch(GAME_VERSION) {
    RUBY {
        ...
    }
    SAPPHIRE {
        ...
    }
    _: ...
}

Rules:
	•	unmatched branches are omitted from compiled output
	•	_ is fallback/default
	•	can be used inside script, text, movement, mart
	•	single statement can use :
	•	multi-statement case uses {}

Examples:

script MyScript {
    poryswitch(GAME_VERSION) {
        RUBY {
            msgbox("Ruby version.")
            giveitem(ITEM_RUBY_ORB)
        }
        SAPPHIRE {
            msgbox("Sapphire version.")
            giveitem(ITEM_SAPPHIRE_ORB)
        }
        _: msgbox("Default version.")
    }
}

text MyText {
    poryswitch(LANGUAGE) {
        GERMAN: "Hallo."
        ENGLISH: "Hello."
    }
}


⸻

21. AI Authoring Patterns

Preferred style

When generating Poryscript:
	1.	prefer structured control flow over labels/goto
	2.	use inline strings for short one-off text
	3.	use text for reused text or long dialogue
	4.	use moves() for short movement sequences
	5.	use movement for reusable movement
	6.	use format() only when automatic wrapping is desired
	7.	use const for object IDs, temp flags, repeated numeric values
	8.	use poryswitch for version/language splits
	9.	use value(...) for suspicious raw compare literals in var compares
	10.	always end scripts cleanly with end or return

Good default NPC script pattern

script NPC_Sample {
    lock
    faceplayer
    if (flag(FLAG_DONE)) {
        msgbox("We've already talked.")
    } else {
        msgbox("Hello there.")
        setflag(FLAG_DONE)
    }
    release
    end
}

Yes/No loop pattern

script NPC_YesNo {
    lock
    faceplayer
    do {
        msgbox("Will you help me?", MSGBOX_YESNO)
    } while (var(VAR_RESULT) == 0)
    msgbox("Thank you!")
    release
    end
}

Switch-on-result pattern

script NPC_RandomLine {
    lock
    faceplayer
    random(3)
    switch (var(VAR_RESULT)) {
        case 0:
            msgbox("Line 1.")
        case 1:
            msgbox("Line 2.")
        case 2:
            msgbox("Line 3.")
    }
    release
    end
}

Inline movement pattern

script NPC_MoveDemo {
    lockall
    applymovement(OBJ_EVENT_ID_PLAYER, moves(walk_up * 2, face_left))
    waitmovement(0)
    releaseall
    end
}


⸻

22. Common Pitfalls
	1.	Do not write else if; write elif.
	2.	Commands with args require parentheses.
	3.	switch must use var(...)-style value, not arbitrary expressions.
	4.	No switch fallthrough.
	5.	format() is for manual strings, not auto strings.
	6.	raw does not allow comments.
	7.	const is limited substitution, not full macros.
	8.	movement and mart are local by default.
	9.	Normal text gets auto $; don’t add it manually in standard Poryscript strings.
	10.	Use value(...) when comparing var against literals that may be interpreted as vars by the engine.

⸻

23. Minimal Syntax Cheat Sheet

const NPC_ID = 2

script(global) MyScript {
    lock
    faceplayer

    if (flag(FLAG_A)) {
        msgbox("Flag set.")
    } elif (var(VAR_B) > 3) {
        msgbox(format("Var B is greater than 3."))
    } else {
        msgbox(MySharedText)
    }

    do {
        msgbox("Continue?", MSGBOX_YESNO)
    } while (var(VAR_RESULT) == 0)

    applymovement(NPC_ID, moves(walk_left * 2, face_down))
    waitmovement(0)

    release
    end
}

text MySharedText {
    "Reusable text."
}

movement MyMovement {
    walk_up * 3
    face_left
}

mart MyMart {
    ITEM_POTION
    ITEM_POKEBALL
}

mapscripts MyMap_MapScripts {
    MAP_SCRIPT_ON_RESUME: MyResumeScript
}

raw `
CustomLabel:
    .byte 1, 2, 3
`


⸻

24. Practical Output Heuristics for AI

When asked to generate Poryscript, default to:
	•	readable indentation
	•	explicit lock / faceplayer / release / end in NPC talk scripts
	•	msgbox("...") for short text
	•	text SomeLabel { ... } for long or reused text
	•	setflag, clearflag, setvar, addvar for state mutation
	•	if (flag(...)) and if (var(...) == ...) rather than raw goto-based branching
	•	switch (var(VAR_RESULT)) after commands like random(...)
	•	moves(...) for one-use movement sequences
	•	const for object IDs and reusable constants

Avoid:
	•	unnecessary labels
	•	unnecessary raw blocks
	•	mixing auto-formatting methods unless deliberate
	•	overusing format() when manual line control is clearly preferable
