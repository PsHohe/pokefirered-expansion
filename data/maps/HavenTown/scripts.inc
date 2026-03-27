.equ PLAYER_STARTER_NUM, VAR_TEMP_2
.equ PLAYER_STARTER_SPECIES, VAR_TEMP_3

HavenTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_OnTransition
	.byte 0

HavenTown_OnTransition::
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	setflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	goto_if_eq VAR_MAP_SCENE_HAVEN_TOWN, 1, HavenTown_OnTransition_StarterScene
	goto_if_eq VAR_MAP_SCENE_HAVEN_TOWN, 2, HavenTown_OnTransition_PostStarter
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_OnTransition_End
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_OnTransition_End
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
HavenTown_OnTransition_End::
	end

HavenTown_OnTransition_StarterScene::
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	end

HavenTown_OnTransition_PostStarter::
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	end

HavenTown_TownSign::
	msgbox HavenTown_Text_TownSign, MSGBOX_SIGN
	end

HavenTown_Rival2Mailbox::
	msgbox HavenTown_Text_Rival2Mailbox, MSGBOX_SIGN
	end

HavenTown_TrainerTips::
	msgbox HavenTown_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end

HavenTown_ParkSign::
	msgbox HavenTown_Text_ParkSign, MSGBOX_SIGN
	end

HavenTown_CedricsMom::
	msgbox HavenTown_Text_CedricsMom, MSGBOX_NPC
	end

HavenTown_ParkGateStopTrigger::
	lockall
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_ParkGateStopTrigger_End
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_ParkGateStopTrigger_End
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_ParkGateStopTrigger_End
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromPark
	waitmovement 0
	msgbox HavenTown_Text_ParkGateStop, MSGBOX_NPC
HavenTown_ParkGateStopTrigger_End::
	releaseall
	end

HavenTown_LeaveTownBlockedTrigger::
	lockall
	goto_if_set FLAG_SYS_POKEMON_GET, HavenTown_LeaveTownBlockedTrigger_End
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromTownExit
	waitmovement 0
	msgbox HavenTown_Text_LeaveTownBlocked, MSGBOX_NPC
HavenTown_LeaveTownBlockedTrigger_End::
	releaseall
	end

HavenTown_ParkBlockedByGruntsTrigger::
	lockall
	goto_if_ne VAR_MAP_SCENE_HAVEN_TOWN, 1, HavenTown_ParkBlockedByGruntsTrigger_End
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromGrunts
	waitmovement 0
	msgbox HavenTown_Text_GruntsBlockPark, MSGBOX_NPC
HavenTown_ParkBlockedByGruntsTrigger_End::
	releaseall
	end

HavenTown_MrRupertPark::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_HAVEN_TOWN, 1, HavenTown_MrRupertPark_StarterScene
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_MrRupertPark_AfterQuest
	msgbox HavenTown_Text_MrRupertPark, MSGBOX_NPC
	removeitem ITEM_LETTER
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED
	goto HavenTown_EventScript_StartMyrtleScene

HavenTown_MrRupertPark_StarterScene::
	msgbox HavenTown_Text_RupertBadPeople, MSGBOX_NPC
	release
	end

HavenTown_MrRupertPark_AfterQuest::
	msgbox HavenTown_Text_MrRupertAfterQuest, MSGBOX_NPC
	release
	end

HavenTown_EventScript_StartMyrtleScene::
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 1
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
	addobject LOCALID_PROF_MYRTLE
	addobject LOCALID_GRUNT_1
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleWalkNorth
	waitmovement 0
	msgbox HavenTown_Text_MyrtleAsksDirections, MSGBOX_NPC
	delay 60
	playse SE_PIN
	waitmovement 0
	applymovement LOCALID_PROF_MYRTLE, Common_Movement_ExclamationMark
	msgbox HavenTown_Text_GruntsAmbushMyrtle, MSGBOX_NPC
	applymovement LOCALID_GRUNT_1, HavenTown_Movement_GruntsWalkNorth
	applymovement LOCALID_GRUNT_2, HavenTown_Movement_GruntsWalkNorth
	waitmovement 0
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleGetsShoved
	waitmovement 0
	addobject LOCALID_TREECKO_BALL
	addobject LOCALID_MUDKIP_BALL
	addobject LOCALID_HAVEN_CHARMANDER_BALL
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	closemessage
	msgbox HavenTown_Text_MyrtleUseOnePokemon, MSGBOX_NPC
	release
	end

HavenTown_ProfMyrtle::
	goto_if_eq VAR_MAP_SCENE_HAVEN_TOWN, 1, HavenTown_ProfMyrtle_StarterScene
	msgbox HavenTown_Text_MyrtleAfterEscort, MSGBOX_NPC
	end

HavenTown_ProfMyrtle_StarterScene::
	msgbox HavenTown_Text_MyrtleRepeatInstruction, MSGBOX_NPC
	end

HavenTown_Grunt1::
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end

HavenTown_Grunt2::
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end

HavenTown_TreeckoBall::
	lock
	setvar PLAYER_STARTER_NUM, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_TREECKO
	goto HavenTown_EventScript_ConfirmStarterChoice

HavenTown_MudkipBall::
	lock
	setvar PLAYER_STARTER_NUM, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_MUDKIP
	goto HavenTown_EventScript_ConfirmStarterChoice

HavenTown_CharmanderBall::
	lock
	setvar PLAYER_STARTER_NUM, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
	goto HavenTown_EventScript_ConfirmStarterChoice

HavenTown_EventScript_ConfirmStarterChoice::
	goto_if_ne VAR_MAP_SCENE_HAVEN_TOWN, 1, HavenTown_EventScript_StarterBallInactive
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	msgbox HavenTown_Text_ChooseStarterConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HavenTown_EventScript_StarterChosen
	goto_if_eq VAR_RESULT, NO, HavenTown_EventScript_StarterDeclined
	end

HavenTown_EventScript_StarterDeclined::
	hidemonpic
	release
	end

HavenTown_EventScript_StarterBallInactive::
	release
	end

HavenTown_EventScript_StarterChosen::
	hidemonpic
	setflag FLAG_SYS_POKEMON_GET
	givemon PLAYER_STARTER_SPECIES, 5
	copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message HavenTown_Text_ReceivedStarter
	waitmessage
	playfanfare MUS_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HavenTown_EventScript_GiveStarterNickname
	goto_if_eq VAR_RESULT, NO, HavenTown_EventScript_StarterBattle
	end

HavenTown_EventScript_GiveStarterNickname::
	setvar VAR_0x8004, 0
	call EventScript_ChangePokemonNickname
	goto HavenTown_EventScript_StarterBattle

HavenTown_EventScript_StarterBattle::
	msgbox HavenTown_Text_GruntBattleStart, MSGBOX_NPC
	trainerbattle_single TRAINER_TEAM_ASHEN_GRUNT_HAVEN, HavenTown_Text_GruntBattleStart, HavenTown_Text_GruntBattleDefeat, HavenTown_EventScript_StarterBattleAfterBattle
	end

HavenTown_EventScript_StarterBattleAfterBattle::
    call HavenTown_EventScript_HideStarterBalls
	msgbox HavenTown_Text_GruntsRetreat, MSGBOX_NPC
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox HavenTown_Text_MyrtleThanks, MSGBOX_NPC
	msgbox HavenTown_Text_MyrtlePresentation
	waitmessage
	multichoicedefault 20, 8, MULTI_YESMAYBE, 1, TRUE
	msgbox HavenTown_Text_MyrtleComeWithMe, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 2
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	setobjectxyperm LOCALID_PROF_MYRTLE, 10, 14
	setobjectmovementtype LOCALID_PROF_MYRTLE, MOVEMENT_TYPE_FACE_RIGHT
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	warp MAP_HAVEN_TOWN, 11, 14
	waitstate
	release
	end

HavenTown_EventScript_HideStarterBalls::
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	removeobject LOCALID_TREECKO_BALL
	removeobject LOCALID_MUDKIP_BALL
	removeobject LOCALID_HAVEN_CHARMANDER_BALL
	return

HavenTown_PotionItem::
	lock
	goto_if_set FLAG_GOT_HAVENTOWN_POTION, HavenTown_PotionItem_AlreadyTaken
	finditem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, HavenTown_PotionItem_End
	setflag FLAG_GOT_HAVENTOWN_POTION

HavenTown_PotionItem_End::
	release
	end

HavenTown_PotionItem_AlreadyTaken::
	msgbox HavenTown_Text_PotionItemGone, MSGBOX_NPC
	release
	end

HavenTown_Movement_PlayerStepBackFromPark::
	walk_left
	step_end

HavenTown_Movement_PlayerStepBackFromTownExit::
	walk_left
	step_end

HavenTown_Movement_PlayerStepBackFromGrunts::
	walk_down
	step_end

HavenTown_Movement_MyrtleWalkNorth::
	walk_up
	walk_up
	walk_up
	step_end

HavenTown_Movement_MyrtleGetsShoved::
	walk_up
	face_down
	walk_in_place_faster_down
	step_end

HavenTown_Movement_GruntsWalkNorth::
    walk_up
    walk_up
    walk_up
    step_end
