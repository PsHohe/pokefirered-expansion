# Poryscript Multiselect Patterns

## Scope

Use this reference for dynamic option menus using `dynmultichoice`, `dynmultipush`, and `dynmultistack`.

## Rule Summary

- Treat `VAR_RESULT` as overwritten by each selector call.
- Branch immediately after each selector when deterministic behavior matters.
- Use `switch (var(VAR_RESULT))` for clean branching.
- Use `case` stacking for shared outcomes.

## Static Dynamic-Choice Example

```pory
dynmultichoice(20, 8, FALSE, 4, 0, NULL, "Test 1", "Test 2", "Test 3", "Test 4")
switch (var(VAR_RESULT)) {
    case 0:
        msgbox("Pressed Test 1.", MSGBOX_NPC)
    case 1:
    case 2:
        msgbox("Pressed Test 2 or 3.", MSGBOX_NPC)
    default:
        msgbox("Pressed Test 4.", MSGBOX_NPC)
}
```

## Stacked Dynamic-Choice Example

```pory
dynmultipush("First option", 0)
dynmultipush("Second option", 1)
if (flag(FLAG_SYS_GAME_CLEAR)) {
    dynmultipush("Secret option", 2)
}
dynmultistack(20, 8, TRUE, 4, FALSE, 0, NULL)
switch (var(VAR_RESULT)) {
    case 0:
        msgbox("Pressed First option.", MSGBOX_NPC)
    case 1:
        msgbox("Pressed Second option.", MSGBOX_NPC)
    case 2:
        msgbox("Pressed Secret option.", MSGBOX_NPC)
    default:
        msgbox("Pressed nothing.", MSGBOX_NPC)
}
```

## Project Baseline Pattern

Use this full interaction skeleton for NPC testing menus:

```pory
script MyScript {
    lock
    faceplayer

    // selector 1
    dynmultichoice(20, 8, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, "Test 1", "Test 2", "Test 3", "Test 4")
    switch (var(VAR_RESULT)) {
        case 0:
            msgbox("Pressed Test 1.", MSGBOX_NPC)
        case 1:
        case 2:
            msgbox("Pressed Test 2 or 3.", MSGBOX_NPC)
        default:
            msgbox("Pressed Test 4.", MSGBOX_NPC)
    }

    // selector 2
    dynmultipush("First option", 0)
    dynmultipush("Second option", 1)
    if (flag(FLAG_SYS_GAME_CLEAR)) {
        dynmultipush("Secret option", 2)
    }
    dynmultistack(20, 8, TRUE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE)
    switch (var(VAR_RESULT)) {
        case 0:
            msgbox("Pressed First option.", MSGBOX_NPC)
        case 1:
            msgbox("Pressed Second option.", MSGBOX_NPC)
        case 2:
            msgbox("Pressed Secret option.", MSGBOX_NPC)
        default:
            msgbox("Pressed nothing.", MSGBOX_NPC)
    }

    release
    end
}
```

## Functions signature

```
dynmultichoice(left, top, ignoreBPress, maxBeforeScroll, initialSelected, callbacks, "Option 1", "Option 2", "Option 3", ...)
dynmultistack(left, top, ignoreBPress, maxBeforeScroll, shouldSort, initialSelected, callbacks)
```

left: The x offset of the menu (in tiles / units of 8 pixels)
top (the y offset of the menu, in tiles / units of 8 pixels)
ignoreBPress: Whether the menu should stay open if the user presses the B Button
maxBeforeScroll: The maximum amount of items shown before the menu scrolls
initialSelected: Variable or static value that determines the initially selected item
callbacks: The event callbacks of the menu. For a simple menu supply DYN_MULTICHOICE_CB_NONE (recommended in most cases)
...: Any number of menu options can follow after these arguments
