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
	setflag FLAG_TEMP_B
# 12 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_TEMP_C
# 13 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_POKEBALL_CEDRIC_1
# 14 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_POKEBALL_CEDRIC_2
# 15 "data/maps/CedricHouse/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 2
	goto_if_ne CedricHouse_OnTransition_2
# 18 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_TEMP_0, 1
CedricHouse_OnTransition_1:
	end

CedricHouse_OnTransition_2:
# 16 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_CEDRIC_INSIDE
	goto CedricHouse_OnTransition_1


CedricHouse_CedricStart::
# 24 "data/maps/CedricHouse/scripts.pory"
	lockall
# 25 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_TEMP_0, 0
# 26 "data/maps/CedricHouse/scripts.pory"
	delay 60
# 27 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 28 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_0
# 29 "data/maps/CedricHouse/scripts.pory"
	dynmultipush CedricHouse_CedricStart_Text_1, 0
# 30 "data/maps/CedricHouse/scripts.pory"
	dynmultipush CedricHouse_CedricStart_Text_2, 1
# 31 "data/maps/CedricHouse/scripts.pory"
	dynmultipush CedricHouse_CedricStart_Text_3, 2
# 32 "data/maps/CedricHouse/scripts.pory"
	dynmultistack 20, 6, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 33 "data/maps/CedricHouse/scripts.pory"
	switch VAR_RESULT
# 34 "data/maps/CedricHouse/scripts.pory"
	case 0, CedricHouse_CedricStart_3
# 37 "data/maps/CedricHouse/scripts.pory"
	case 1, CedricHouse_CedricStart_4
# 39 "data/maps/CedricHouse/scripts.pory"
	case 2, CedricHouse_CedricStart_5
CedricHouse_CedricStart_1:
# 43 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_MYRTLE_INSIDE, CedricHouse_CedricStart_Movement_0
# 44 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_PLAYER, CedricHouse_CedricStart_Movement_0
# 45 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 46 "data/maps/CedricHouse/scripts.pory"
	playse SE_PIN
# 47 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_MOM_INSIDE, Common_Movement_ExclamationMark
# 48 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 49 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 50 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_7, MSGBOX_NPC
# 54 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_MYRTLE_INSIDE, CedricHouse_CedricStart_Movement_1
# 55 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_PLAYER, CedricHouse_CedricStart_Movement_2
# 56 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_MOM_INSIDE, CedricHouse_CedricStart_Movement_3
# 57 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 58 "data/maps/CedricHouse/scripts.pory"
	playse SE_DOOR
# 59 "data/maps/CedricHouse/scripts.pory"
	waitse
# 60 "data/maps/CedricHouse/scripts.pory"
	addobject LOCALID_CEDRIC_INSIDE
# 61 "data/maps/CedricHouse/scripts.pory"
	clearflag FLAG_TEMP_C
# 62 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 63 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, CedricHouse_CedricStart_Movement_4
# 64 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 65 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_MYRTLE_INSIDE, CedricHouse_CedricStart_Movement_5
# 66 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_PLAYER, CedricHouse_CedricStart_Movement_5
# 67 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 68 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_8, MSGBOX_NPC
# 70 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_9, MSGBOX_NPC
# 80 "data/maps/CedricHouse/scripts.pory"
	playse SE_BALL_BOUNCE_2
# 81 "data/maps/CedricHouse/scripts.pory"
	waitse
# 82 "data/maps/CedricHouse/scripts.pory"
	addobject LOCALID_POKEBALL_CEDRIC_1
# 83 "data/maps/CedricHouse/scripts.pory"
	addobject LOCALID_POKEBALL_CEDRIC_2
# 84 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_TEMP_A
# 85 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_TEMP_B
# 86 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 87 "data/maps/CedricHouse/scripts.pory"
	playse SE_PIN
# 88 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, Common_Movement_ExclamationMark
# 89 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 90 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_10, MSGBOX_NPC
# 92 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_11, MSGBOX_NPC
# 93 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_12, MSGBOX_NPC
# 98 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 99 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_13, MSGBOX_NPC
# 100 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, CedricHouse_CedricStart_Movement_6
# 101 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 102 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_14, MSGBOX_NPC
# 106 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, CedricHouse_CedricStart_Movement_7
# 107 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 108 "data/maps/CedricHouse/scripts.pory"
	setflag FLAG_TEMP_A
# 109 "data/maps/CedricHouse/scripts.pory"
	removeobject LOCALID_POKEBALL_CEDRIC_1
# 110 "data/maps/CedricHouse/scripts.pory"
	delay 30
# 111 "data/maps/CedricHouse/scripts.pory"
	applymovement LOCALID_CEDRIC_INSIDE, CedricHouse_CedricStart_Movement_8
# 112 "data/maps/CedricHouse/scripts.pory"
	waitmovement 0
# 113 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_15, MSGBOX_NPC
# 117 "data/maps/CedricHouse/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 3
# 118 "data/maps/CedricHouse/scripts.pory"
	warp MAP_HAVEN_TOWN, 10, 13
# 119 "data/maps/CedricHouse/scripts.pory"
	waitstate
# 120 "data/maps/CedricHouse/scripts.pory"
	releaseall
	end

CedricHouse_CedricStart_3:
# 35 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_4, MSGBOX_NPC
	goto CedricHouse_CedricStart_1

CedricHouse_CedricStart_4:
# 38 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_5, MSGBOX_NPC
	goto CedricHouse_CedricStart_1

CedricHouse_CedricStart_5:
# 40 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricStart_Text_6, MSGBOX_NPC
	goto CedricHouse_CedricStart_1


CedricHouse_CedricsMomAfterBattle::
# 125 "data/maps/CedricHouse/scripts.pory"
	lock
# 126 "data/maps/CedricHouse/scripts.pory"
	faceplayer
# 127 "data/maps/CedricHouse/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 4
	goto_if_ge CedricHouse_CedricsMomAfterBattle_2
# 133 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricsMomAfterBattle_Text_1, MSGBOX_NPC
CedricHouse_CedricsMomAfterBattle_1:
# 136 "data/maps/CedricHouse/scripts.pory"
	release
	end

CedricHouse_CedricsMomAfterBattle_2:
# 128 "data/maps/CedricHouse/scripts.pory"
	msgbox CedricHouse_CedricsMomAfterBattle_Text_0, MSGBOX_NPC
	goto CedricHouse_CedricsMomAfterBattle_1


# 43 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_0:
# 43 "data/maps/CedricHouse/scripts.pory"
	walk_right
	step_end

# 54 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_1:
# 54 "data/maps/CedricHouse/scripts.pory"
	walk_right
# 54 "data/maps/CedricHouse/scripts.pory"
	walk_right
# 54 "data/maps/CedricHouse/scripts.pory"
	step_end

# 55 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_2:
# 55 "data/maps/CedricHouse/scripts.pory"
	walk_right
# 55 "data/maps/CedricHouse/scripts.pory"
	walk_right
	step_end

# 56 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_3:
# 56 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 56 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 56 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 56 "data/maps/CedricHouse/scripts.pory"
	face_left
# 56 "data/maps/CedricHouse/scripts.pory"
	step_end

# 63 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_4:
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 63 "data/maps/CedricHouse/scripts.pory"
	walk_down
# 63 "data/maps/CedricHouse/scripts.pory"
	step_end

# 65 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_5:
# 65 "data/maps/CedricHouse/scripts.pory"
	face_up
# 65 "data/maps/CedricHouse/scripts.pory"
	step_end

# 100 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_6:
# 100 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 100 "data/maps/CedricHouse/scripts.pory"
	walk_right
# 100 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 100 "data/maps/CedricHouse/scripts.pory"
	walk_right
# 100 "data/maps/CedricHouse/scripts.pory"
	face_down
# 100 "data/maps/CedricHouse/scripts.pory"
	step_end

# 106 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_7:
# 106 "data/maps/CedricHouse/scripts.pory"
	face_right
# 106 "data/maps/CedricHouse/scripts.pory"
	step_end

# 111 "data/maps/CedricHouse/scripts.pory"
CedricHouse_CedricStart_Movement_8:
# 111 "data/maps/CedricHouse/scripts.pory"
	walk_left
# 111 "data/maps/CedricHouse/scripts.pory"
	face_down
# 111 "data/maps/CedricHouse/scripts.pory"
	step_end

CedricHouse_CedricStart_Text_0:
# 28 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: So, is it here?$"

CedricHouse_CedricStart_Text_1:
# 29 "data/maps/CedricHouse/scripts.pory"
	.string "Yes, it's here!$"

CedricHouse_CedricStart_Text_2:
# 30 "data/maps/CedricHouse/scripts.pory"
	.string "Yeah, but...$"

CedricHouse_CedricStart_Text_3:
# 31 "data/maps/CedricHouse/scripts.pory"
	.string "Yep. I should be going, though.$"

CedricHouse_CedricStart_Text_4:
# 35 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Good!\n"
	.string "Let's see your friend!$"

CedricHouse_CedricStart_Text_5:
# 38 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Let's go!$"

CedricHouse_CedricStart_Text_6:
# 40 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Nonsense!\n"
	.string "Let's go!$"

CedricHouse_CedricStart_Text_7:
# 50 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}'s Mom: {RIVAL2} dear!\n"
	.string "The professor is here!\p"
	.string "Myrtle, so nice to see you!.$"

CedricHouse_CedricStart_Text_8:
# 68 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}: Is this dad's friend?\n"
	.string "Does she have my POKéMON?$"

CedricHouse_CedricStart_Text_9:
# 70 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: Hello {RIVAL2},\n"
	.string "I'm Professor Myrtle.\p"
	.string "Your father... He's busy with\n"
	.string "his very important research, \l"
	.string "but he asked me to give you \l"
	.string "your very first POKéMON!\p"
	.string "Here, you can choose one of \n"
	.string "these three!$"

CedricHouse_CedricStart_Text_10:
# 90 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}: Wait...\n"
	.string "where's the third one?$"

CedricHouse_CedricStart_Text_11:
# 92 "data/maps/CedricHouse/scripts.pory"
	.string "Prof. Myrtle: I meant two!$"

CedricHouse_CedricStart_Text_12:
# 93 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}: Why does\n"
	.string "{PLAYER} have a POKéMON?\p"
	.string "Why did he get to choose \n"
	.string "first?!$"

CedricHouse_CedricStart_Text_13:
# 99 "data/maps/CedricHouse/scripts.pory"
	.string "It's not fair!$"

CedricHouse_CedricStart_Text_14:
# 102 "data/maps/CedricHouse/scripts.pory"
	.string "I'm going to get the strongest \n"
	.string "one!\p"
	.string "You'll see!$"

CedricHouse_CedricStart_Text_15:
# 113 "data/maps/CedricHouse/scripts.pory"
	.string "Let's go outside, {PLAYER}!\p"
	.string "We'll see who's the better\n"
	.string "trainer!$"

CedricHouse_CedricsMomAfterBattle_Text_0:
# 128 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}'s Mom: You have quite\l"
	.string "a talent for stirring trouble.\p"
	.string "If you're done upsetting my son,\l"
	.string "please leave him be.$"

CedricHouse_CedricsMomAfterBattle_Text_1:
# 133 "data/maps/CedricHouse/scripts.pory"
	.string "{RIVAL2}'s Mom: The professor and\n"
	.string "{RIVAL2} are talking right now.$"
