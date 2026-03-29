HavenTown_Orphanage_2F_MapScripts::
# 2 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_Orphanage_2F_OnTransition
# 3 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HavenTown_Orphanage_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HavenTown_Orphanage_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, HavenTown_Orphanage_2F_EventScript_MarinaCallsPlayerDownstairs
	.2byte 0


HavenTown_Orphanage_2F_OnTransition::
# 9 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	setvar VAR_TEMP_0, 0
# 11 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_Orphanage_2F_OnTransition_4
HavenTown_Orphanage_2F_OnTransition_1:
	end

HavenTown_Orphanage_2F_OnTransition_2:
# 14 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto HavenTown_Orphanage_2F_OnTransition_1

HavenTown_Orphanage_2F_OnTransition_3:
# 13 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, HavenTown_Orphanage_2F_OnTransition_2
	goto HavenTown_Orphanage_2F_OnTransition_1

HavenTown_Orphanage_2F_OnTransition_4:
# 12 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS, HavenTown_Orphanage_2F_OnTransition_3
	goto HavenTown_Orphanage_2F_OnTransition_1


HavenTown_Orphanage_2F_EventScript_MarinaCallsPlayerDownstairs::
# 21 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	lockall
# 22 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 23 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	playse SE_PIN
# 24 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 25 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	waitmovement 0
# 26 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_EventScript_MarinaCallsPlayerDownstairs_Text_0, MSGBOX_NPC
# 29 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	setflag FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS
# 30 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	setvar VAR_TEMP_0, 0
# 31 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	releaseall
	end


HavenTown_Orphanage_2F_Kangaskhan::
# 36 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	lock
# 37 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	faceplayer
# 38 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	waitse
# 39 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
# 40 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Kangaskhan_Text_0, MSGBOX_NPC
# 41 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	waitmoncry
# 42 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	release
	end


HavenTown_Orphanage_2F_ChoresSign::
# 47 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_ChoresSign_Text_0, MSGBOX_SIGN
	end


HavenTown_Orphanage_2F_Thomas::
# 54 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	lock
# 55 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	faceplayer
# 57 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_Orphanage_2F_Thomas_3
HavenTown_Orphanage_2F_Thomas_1:
# 64 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	random 6
# 65 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	switch VAR_RESULT
# 66 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	case 0, HavenTown_Orphanage_2F_Thomas_8
# 68 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	case 1, HavenTown_Orphanage_2F_Thomas_9
# 70 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	case 2, HavenTown_Orphanage_2F_Thomas_10
# 72 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	case 3, HavenTown_Orphanage_2F_Thomas_11
# 74 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	case 4, HavenTown_Orphanage_2F_Thomas_12
# 76 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	case 5, HavenTown_Orphanage_2F_Thomas_13
HavenTown_Orphanage_2F_Thomas_6:
# 80 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	release
	end

HavenTown_Orphanage_2F_Thomas_2:
# 59 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasMarinaWaitingDownstairs, MSGBOX_NPC
# 60 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	release
	end

HavenTown_Orphanage_2F_Thomas_3:
# 58 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS, HavenTown_Orphanage_2F_Thomas_2
	goto HavenTown_Orphanage_2F_Thomas_1

HavenTown_Orphanage_2F_Thomas_8:
# 67 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact1, MSGBOX_NPC
	goto HavenTown_Orphanage_2F_Thomas_6

HavenTown_Orphanage_2F_Thomas_9:
# 69 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact2, MSGBOX_NPC
	goto HavenTown_Orphanage_2F_Thomas_6

HavenTown_Orphanage_2F_Thomas_10:
# 71 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact3, MSGBOX_NPC
	goto HavenTown_Orphanage_2F_Thomas_6

HavenTown_Orphanage_2F_Thomas_11:
# 73 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact4, MSGBOX_NPC
	goto HavenTown_Orphanage_2F_Thomas_6

HavenTown_Orphanage_2F_Thomas_12:
# 75 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact5, MSGBOX_NPC
	goto HavenTown_Orphanage_2F_Thomas_6

HavenTown_Orphanage_2F_Thomas_13:
# 77 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact6, MSGBOX_NPC
	goto HavenTown_Orphanage_2F_Thomas_6


HavenTown_Orphanage_2F_EventScript_MarinaCallsPlayerDownstairs_Text_0:
# 26 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	.string "Mrs. Marina: {PLAYER}!\n"
	.string "Come downstairs right away, please!$"

HavenTown_Orphanage_2F_Kangaskhan_Text_0:
# 40 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	.string "Khaaaaaa!$"

HavenTown_Orphanage_2F_ChoresSign_Text_0:
# 47 "data/maps/HavenTown_Orphanage_2F/scripts.pory"
	.string "It's a list of chores for the week\n"
	.string "Every kid has one.$"
