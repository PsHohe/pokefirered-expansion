HavenTown_Orphanage_1F_MapScripts::
# 2 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_Orphanage_1F_OnTransition
# 3 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HavenTown_Orphanage_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HavenTown_Orphanage_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff
# 5 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, HavenTown_Orphanage_1F_EventScript_MarinaStartsEnvelopeQuest
	.2byte 0


HavenTown_Orphanage_1F_OnTransition::
# 10 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_TEMP_0, 0
# 11 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_TEMP_1, 0
# 13 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 4
	goto_if_eq HavenTown_Orphanage_1F_OnTransition_2
# 20 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_Orphanage_1F_OnTransition_5
# 20 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_MARINA_CALLED_PLAYER_DOWNSTAIRS, HavenTown_Orphanage_1F_OnTransition_5
# 26 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setobjectxyperm LOCALID_MARINA, 9, 2
# 27 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setobjectmovementtype LOCALID_MARINA, MOVEMENT_TYPE_FACE_RIGHT
# 28 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_TEMP_0, 1
	end

HavenTown_Orphanage_1F_OnTransition_2:
# 14 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setobjectxyperm LOCALID_MARINA, 8, 5
# 15 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setobjectmovementtype LOCALID_MARINA, MOVEMENT_TYPE_NONE
# 16 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_TEMP_1, 1
	end

HavenTown_Orphanage_1F_OnTransition_5:
# 21 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setobjectxyperm LOCALID_MARINA, 8, 5
# 22 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setobjectmovementtype LOCALID_MARINA, MOVEMENT_TYPE_NONE
	end


HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff::
# 33 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	lockall
# 34 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 35 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	playse SE_PIN
# 36 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	applymovement LOCALID_MARINA, Common_Movement_ExclamationMark
# 37 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	waitmovement 0
# 38 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	msgbox HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_Text_0, MSGBOX_NPC
# 47 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 48 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_2
HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_1:
# 56 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 5
# 57 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_TEMP_1, 0
# 58 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	releaseall
	end

HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_2:
# 49 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	message HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_Text_1
# 51 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	waitmessage
# 52 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 53 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	waitfanfare
	goto HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_1


HavenTown_Orphanage_1F_EventScript_MarinaStartsEnvelopeQuest::
# 63 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	lockall
# 64 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 65 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	playse SE_PIN
# 66 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	applymovement LOCALID_MARINA, Common_Movement_ExclamationMark
# 67 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	delay 40
# 68 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	waitmovement 0
# 69 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	applymovement LOCALID_MARINA, HavenTown_Orphanage_1F_Movement_MarinaApproachPlayer
# 70 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	waitmovement 0
# 71 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 72 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	waitmovement 0
# 73 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	msgbox HavenTown_Orphanage_1F_Text_MarinaNeedEnvelopeDelivered
# 74 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	giveitem_msg HavenTown_Orphanage_1F_Text_MarinaGaveEnvelope, ITEM_LETTER, 1, MUS_OBTAIN_KEY_ITEM
# 75 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED
# 76 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	setvar VAR_TEMP_0, 0
# 77 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	releaseall
	end


# 81 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
HavenTown_Orphanage_1F_Movement_MarinaApproachPlayer:
# 82 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	walk_right
# 83 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	walk_right
	step_end

HavenTown_Orphanage_1F_QuickRest::
# 87 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_Orphanage_1F_QuickRest_2
HavenTown_Orphanage_1F_QuickRest_1:
# 91 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_Orphanage_1F_QuickRest_5
HavenTown_Orphanage_1F_QuickRest_4:
# 95 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, HavenTown_Orphanage_1F_QuickRest_8
HavenTown_Orphanage_1F_QuickRest_7:
# 99 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	msgbox HavenTown_Orphanage_1F_Text_MarinaEnvelopeReminder, MSGBOX_NPC
	end

HavenTown_Orphanage_1F_QuickRest_2:
# 88 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto HavenTown_Orphanage_1F_QuickRest_Heal
	goto HavenTown_Orphanage_1F_QuickRest_1

HavenTown_Orphanage_1F_QuickRest_5:
# 92 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto HavenTown_Orphanage_1F_QuickRest_Heal
	goto HavenTown_Orphanage_1F_QuickRest_4

HavenTown_Orphanage_1F_QuickRest_8:
# 96 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	goto HavenTown_Orphanage_1F_QuickRest_Heal
	goto HavenTown_Orphanage_1F_QuickRest_7


HavenTown_Orphanage_1F_QuickRest_Heal::
# 104 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	msgbox HavenTown_Orphanage_1F_Text_YouShouldTakeQuickRest
# 105 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	closemessage
# 106 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 107 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	msgbox HavenTown_Orphanage_1F_Text_LookingGreatTakeCare
# 108 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	release
	end


HavenTown_Orphanage_1F_Vera::
# 113 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	weightedmsgbox MSGBOX_NPC, HavenTown_Orphanage_1F_Text_VeraCommon, HavenTown_Orphanage_1F_Text_VeraMid, HavenTown_Orphanage_1F_Text_VeraRare
	end


HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_Text_0:
# 38 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	.string "Mrs. Marina: {PLAYER}, look at\l"
	.string "you... You've grown so much.\p"
	.string "{RIVAL2} started training before you,\l"
	.string "and now it's your turn.\p"
	.string "No matter where you go,\l"
	.string "you'll always have a home here.\p"
	.string "The others will want to hear\l"
	.string "all about your adventures.$"

HavenTown_Orphanage_1F_EventScript_MarinaJourneySendoff_Text_1:
# 49 "data/maps/HavenTown_Orphanage_1F/scripts.pory"
	.string "Mrs. Marina gave you\n"
	.string "5 POKE BALLS.$"
