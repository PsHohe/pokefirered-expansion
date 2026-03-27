TestingTilesets_MapScripts::
	.byte 0


MyScript::
# 6 "data/maps/TestingTilesets/scripts.pory"
	lock
# 7 "data/maps/TestingTilesets/scripts.pory"
	faceplayer
# 8 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_0
# 9 "data/maps/TestingTilesets/scripts.pory"
	dynmultichoice 20, 8, FALSE, 4, 0, NULL, MyScript_Text_1, MyScript_Text_2, MyScript_Text_3, MyScript_Text_4
# 10 "data/maps/TestingTilesets/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/TestingTilesets/scripts.pory"
	case 0, MyScript_3
# 13 "data/maps/TestingTilesets/scripts.pory"
	case 1, MyScript_4
# 14 "data/maps/TestingTilesets/scripts.pory"
	case 2, MyScript_4
# 17 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_7, MSGBOX_NPC
MyScript_1:
# 19 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_8
# 20 "data/maps/TestingTilesets/scripts.pory"
	dynmultipush MyScript_Text_9, 0
# 21 "data/maps/TestingTilesets/scripts.pory"
	dynmultipush MyScript_Text_10, 1
# 22 "data/maps/TestingTilesets/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MyScript_7
MyScript_6:
# 25 "data/maps/TestingTilesets/scripts.pory"
	dynmultistack 20, 8, TRUE, 4, FALSE, 0, NULL
# 26 "data/maps/TestingTilesets/scripts.pory"
	switch VAR_RESULT
# 27 "data/maps/TestingTilesets/scripts.pory"
	case 0, MyScript_11
# 29 "data/maps/TestingTilesets/scripts.pory"
	case 1, MyScript_12
# 31 "data/maps/TestingTilesets/scripts.pory"
	case 2, MyScript_13
# 34 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_15, MSGBOX_NPC
MyScript_9:
# 36 "data/maps/TestingTilesets/scripts.pory"
	release
	end

MyScript_3:
# 12 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_5, MSGBOX_NPC
	goto MyScript_1

MyScript_4:
# 15 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_6, MSGBOX_NPC
	goto MyScript_1

MyScript_7:
# 23 "data/maps/TestingTilesets/scripts.pory"
	dynmultipush MyScript_Text_11, 2
	goto MyScript_6

MyScript_11:
# 28 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_12, MSGBOX_NPC
	goto MyScript_9

MyScript_12:
# 30 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_13, MSGBOX_NPC
	goto MyScript_9

MyScript_13:
# 32 "data/maps/TestingTilesets/scripts.pory"
	msgbox MyScript_Text_14, MSGBOX_NPC
	goto MyScript_9


MyScript_Text_0:
# 8 "data/maps/TestingTilesets/scripts.pory"
	.string "The first test is working!$"

MyScript_Text_1:
# 9 "data/maps/TestingTilesets/scripts.pory"
	.string "Test 1$"

MyScript_Text_2:
# 9 "data/maps/TestingTilesets/scripts.pory"
	.string "Test 2$"

MyScript_Text_3:
# 9 "data/maps/TestingTilesets/scripts.pory"
	.string "Test 3$"

MyScript_Text_4:
# 9 "data/maps/TestingTilesets/scripts.pory"
	.string "Test 4$"

MyScript_Text_5:
# 12 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed Test 1.$"

MyScript_Text_6:
# 15 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed Test 2 or 3.$"

MyScript_Text_7:
# 17 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed Test 4.$"

MyScript_Text_8:
# 19 "data/maps/TestingTilesets/scripts.pory"
	.string "Now let's move to the multipush test,\n"
	.string "which involves multiple dynamic\l"
	.string "selections!$"

MyScript_Text_9:
# 20 "data/maps/TestingTilesets/scripts.pory"
	.string "First option$"

MyScript_Text_10:
# 21 "data/maps/TestingTilesets/scripts.pory"
	.string "Second option$"

MyScript_Text_11:
# 23 "data/maps/TestingTilesets/scripts.pory"
	.string "Secret option$"

MyScript_Text_12:
# 28 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed First option.$"

MyScript_Text_13:
# 30 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed Second option.$"

MyScript_Text_14:
# 32 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed Secret option.$"

MyScript_Text_15:
# 34 "data/maps/TestingTilesets/scripts.pory"
	.string "Pressed nothing.$"
