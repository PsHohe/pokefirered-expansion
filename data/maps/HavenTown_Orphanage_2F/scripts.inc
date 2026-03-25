HavenTown_Orphanage_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_Orphanage_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HavenTown_Orphanage_2F_OnFrame
	.byte 0

HavenTown_Orphanage_2F_OnTransition::
	setvar VAR_TEMP_0, 0
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_Orphanage_2F_OnTransition_End
	goto_if_set FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS, HavenTown_Orphanage_2F_OnTransition_End
	goto_if_set FLAG_SYS_POKEDEX_GET, HavenTown_Orphanage_2F_OnTransition_End
	setvar VAR_TEMP_0, 1
HavenTown_Orphanage_2F_OnTransition_End::
	end

HavenTown_Orphanage_2F_OnFrame::
	map_script_2 VAR_TEMP_0, 1, HavenTown_Orphanage_2F_EventScript_MarinaCallsPlayerDownstairs
	.2byte 0

HavenTown_Orphanage_2F_EventScript_MarinaCallsPlayerDownstairs::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox HavenTown_Orphanage_2F_Text_MarinaCallsPlayerDownstairs
	setflag FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS
	setvar VAR_TEMP_0, 0
	releaseall
	end

HavenTown_Orphanage_2F_Kangaskhan::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
    msgbox HavenTown_Orphanage_2F_Text_Kangaskhan
    waitmoncry
    release
    end

HavenTown_Orphanage_2F_ChoresSign::
    msgbox HavenTown_Orphanage_2F_Text_ChoresSign, MSGBOX_SIGN
    end

HavenTown_Orphanage_2F_Thomas::
	lock
	faceplayer
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_Orphanage_2F_ThomasRandomFact
	goto_if_unset FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS, HavenTown_Orphanage_2F_ThomasRandomFact
	msgbox HavenTown_Orphanage_2F_Text_ThomasMarinaWaitingDownstairs, MSGBOX_NPC
	release
	end

HavenTown_Orphanage_2F_ThomasRandomFact::
	random 6
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, HavenTown_Orphanage_2F_ThomasFact1
	call_if_eq VAR_0x8008, 1, HavenTown_Orphanage_2F_ThomasFact2
	call_if_eq VAR_0x8008, 2, HavenTown_Orphanage_2F_ThomasFact3
	call_if_eq VAR_0x8008, 3, HavenTown_Orphanage_2F_ThomasFact4
	call_if_eq VAR_0x8008, 4, HavenTown_Orphanage_2F_ThomasFact5
	call_if_eq VAR_0x8008, 5, HavenTown_Orphanage_2F_ThomasFact6
	release
	end

HavenTown_Orphanage_2F_ThomasFact1::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact1, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact2::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact2, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact3::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact3, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact4::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact4, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact5::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact5, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact6::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact6, MSGBOX_NPC
	return
