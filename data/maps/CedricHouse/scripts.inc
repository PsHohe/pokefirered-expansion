CedricHouse_MapScripts::
# 2 "data/maps/CedricHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CedricHouse_OnTransition
# 3 "data/maps/CedricHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CedricHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CedricHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/CedricHouse/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, CedricHouse_CedricStart
	.2byte 0


CedricHouse_OnTransition::
# 9 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_TEMP_0, 0
# 10 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_TEMP_A
# 11 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_POKEBALL_CEDRIC_1
# 12 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_POKEBALL_CEDRIC_2
# 13 "data/maps/CedricHouse/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 2
	goto_if_ne CedricHouse_OnTransition_2
# 16 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_TEMP_0, 1
CedricHouse_OnTransition_1:
	end

CedricHouse_OnTransition_2:
# 14 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_CEDRIC_INSIDE
	goto CedricHouse_OnTransition_1


CedricHouse_CedricStart::
# 22 "data/maps/CedricHouse/scripts.pory"
	lockall
# 23 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_TEMP_0, 0
# 24 "data/maps/CedricHouse/scripts.pory"
	delay 60
# 25 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 26 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_0
# 27 "data/maps/CedricHouse/scripts.pory"
	dynmultipush CedricHouse_CedricStart_Text_1, 0
# 28 "data/maps/CedricHouse/scripts.pory"
	dynmultipush CedricHouse_CedricStart_Text_2, 1
# 29 "data/maps/CedricHouse/scripts.pory"
	dynmultipush CedricHouse_CedricStart_Text_3, 2
# 30 "data/maps/CedricHouse/scripts.pory"
	dynmultistack 20, 6, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 31 "data/maps/CedricHouse/scripts.pory"
	switch VAR_RESULT
# 32 "data/maps/CedricHouse/scripts.pory"
	case 0, CedricHouse_CedricStart_3
# 35 "data/maps/CedricHouse/scripts.pory"
	case 1, CedricHouse_CedricStart_4
# 37 "data/maps/CedricHouse/scripts.pory"
	case 2, CedricHouse_CedricStart_5
CedricHouse_CedricStart_1:
# 41 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_MYRTLE_INSIDE, CedricHouse_CedricStart_Movement_0
# 42 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_PLAYER, CedricHouse_CedricStart_Movement_0
# 43 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 44 "data/maps/CedricHouse/scripts.pory"
	playse SE_PIN
# 45 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_MOM_INSIDE, Common_Movement_ExclamationMark
# 46 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 47 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 48 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_7, MSGBOX_NPC
# 52 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_MYRTLE_INSIDE, CedricHouse_CedricStart_Movement_1
# 53 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_PLAYER, CedricHouse_CedricStart_Movement_1
# 54 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_MOM_INSIDE, CedricHouse_CedricStart_Movement_2
# 55 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 56 "data/maps/CedricHouse/scripts.pory"
	playse SE_DOOR
# 57 "data/maps/CedricHouse/scripts.pory"
	waitse
# 58 "data/maps/CedricHouse/scripts.pory"
	addobject LOCALID_CEDRIC_INSIDE
# 59 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_TEMP_A
# 60 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 61 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, CedricHouse_CedricStart_Movement_3
# 62 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 63 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_MYRTLE_INSIDE, CedricHouse_CedricStart_Movement_4
# 64 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_PLAYER, CedricHouse_CedricStart_Movement_4
# 65 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 66 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_8, MSGBOX_NPC
# 68 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_9, MSGBOX_NPC
# 78 "data/maps/CedricHouse/scripts.pory"
	playse SE_BALL_BOUNCE_2
# 79 "data/maps/CedricHouse/scripts.pory"
	waitse
# 80 "data/maps/CedricHouse/scripts.pory"
	addobject LOCALID_POKEBALL_CEDRIC_1
# 81 "data/maps/CedricHouse/scripts.pory"
	addobject LOCALID_POKEBALL_CEDRIC_2
# 82 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 83 "data/maps/CedricHouse/scripts.pory"
	playse SE_PIN
# 84 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, Common_Movement_ExclamationMark
# 85 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 86 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_10, MSGBOX_NPC
# 88 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_11, MSGBOX_NPC
# 89 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_12, MSGBOX_NPC
# 94 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 3
# 95 "data/maps/CedricHouse/scripts.pory"
	releaseall
	end

CedricHouse_CedricStart_3:
# 33 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_4, MSGBOX_NPC
	goto CedricHouse_CedricStart_1

CedricHouse_CedricStart_4:
# 36 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_5, MSGBOX_NPC
	goto CedricHouse_CedricStart_1

CedricHouse_CedricStart_5:
# 38 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_6, MSGBOX_NPC
	goto CedricHouse_CedricStart_1


# 41 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_0:
# 41 "data/maps/CedricHouse/scripts.pory"
	walk_right
	step_end

# 52 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_1:
# 52 "data/maps/CedricHouse/scripts.pory"
	walk_right
# 52 "data/maps/CedricHouse/scripts.pory"
	walk_right
	step_end

# 54 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_2:
# 54 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 54 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 54 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 54 "data/maps/CedricHouse/scripts.pory"
	face_left
	step_end

# 61 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_3:
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 61 "data/maps/CedricHouse/scripts.pory"
	walk_down
	step_end

# 63 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_4:
# 63 "data/maps/CedricHouse/scripts.pory"
	face_up
	step_end

CedricHouse_CedricStart_Text_0:
# 26 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: So, is it here?$"

CedricHouse_CedricStart_Text_1:
# 27 "data/maps/CedricHouse/scripts.pory"
	.string "Yes, it's here!$"

CedricHouse_CedricStart_Text_2:
# 28 "data/maps/CedricHouse/scripts.pory"
	.string "Yeah, but...$"

CedricHouse_CedricStart_Text_3:
# 29 "data/maps/CedricHouse/scripts.pory"
	.string "Yep. I should be going, though.$"

CedricHouse_CedricStart_Text_4:
# 33 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Good!\n"
	.string "Let's see your friend!$"

CedricHouse_CedricStart_Text_5:
# 36 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Let's go!$"

CedricHouse_CedricStart_Text_6:
# 38 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Nonsense!\n"
	.string "Let's go!$"

CedricHouse_CedricStart_Text_7:
# 48 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}'s Mom: {RIVAL2} dear!\n"
	.string "The professor is here!\p"
	.string "Myrtle, so nice to see you!.$"

CedricHouse_CedricStart_Text_8:
# 66 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}: Is this dad's friend?\n"
	.string "Does she have my POKéMON?$"

CedricHouse_CedricStart_Text_9:
# 68 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Hello {RIVAL2},\n"
	.string "I'm Professor Myrtle.\p"
	.string "Your father... He's busy with\n"
	.string "his very important research, \l"
	.string "but he asked me to give you \l"
	.string "your very first POKéMON!\p"
	.string "Here, you can choose one of \n"
	.string "these three!$"

CedricHouse_CedricStart_Text_10:
# 86 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}: Wait...\n"
	.string "where's the third one?$"

CedricHouse_CedricStart_Text_11:
# 88 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: I meant two!$"

CedricHouse_CedricStart_Text_12:
# 89 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}: Why does\n"
	.string "{PLAYER} have a POKéMON?\p"
	.string "Why did he get to choose \n"
	.string "first?!$"
