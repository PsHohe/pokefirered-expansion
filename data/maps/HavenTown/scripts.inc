HavenTown_MapScripts::
# 5 "data/maps/HavenTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_OnTransition
	.byte 0


HavenTown_OnTransition::
# 9 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 10 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 11 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 12 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 13 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 14 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 15 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 17 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_CEDRIC_START
# 19 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_OnTransition_2
# 28 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 2
	goto_if_eq HavenTown_OnTransition_3
# 33 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_OnTransition_8
HavenTown_OnTransition_6:
	end

HavenTown_OnTransition_2:
# 20 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 21 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 22 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 23 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 24 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 25 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 26 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	end

HavenTown_OnTransition_3:
# 29 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	end

HavenTown_OnTransition_7:
# 34 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	goto HavenTown_OnTransition_6

HavenTown_OnTransition_8:
# 33 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_OnTransition_7
	goto HavenTown_OnTransition_6


HavenTown_TownSign::
# 40 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_TownSign, MSGBOX_SIGN
	end


HavenTown_Rival2Mailbox::
# 45 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_Rival2Mailbox, MSGBOX_SIGN
	end


HavenTown_TrainerTips::
# 50 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end


HavenTown_ParkSign::
# 55 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkSign, MSGBOX_SIGN
	end


HavenTown_CedricsMom::
# 60 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_CedricsMom, MSGBOX_NPC
	end


HavenTown_ParkGateStopTrigger::
# 65 "data/maps/HavenTown/scripts.pory"
	lockall
# 66 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_ParkGateStopTrigger_4
HavenTown_ParkGateStopTrigger_1:
# 73 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_ParkGateStopTrigger_2:
# 69 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromPark
# 70 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 71 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkGateStop, MSGBOX_NPC
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_3:
# 68 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_ParkGateStopTrigger_2
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_4:
# 67 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_ParkGateStopTrigger_3
	goto HavenTown_ParkGateStopTrigger_1


HavenTown_LeaveTownBlockedTrigger::
# 78 "data/maps/HavenTown/scripts.pory"
	lockall
# 79 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, HavenTown_LeaveTownBlockedTrigger_2
HavenTown_LeaveTownBlockedTrigger_1:
# 84 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_LeaveTownBlockedTrigger_2:
# 80 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromTownExit
# 81 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 82 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_LeaveTownBlocked, MSGBOX_NPC
	goto HavenTown_LeaveTownBlockedTrigger_1


HavenTown_MrRupertPark::
# 89 "data/maps/HavenTown/scripts.pory"
	lock
# 90 "data/maps/HavenTown/scripts.pory"
	faceplayer
# 92 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_MrRupertPark_2
# 98 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_MrRupertPark_5
# 104 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertPark, MSGBOX_NPC
# 105 "data/maps/HavenTown/scripts.pory"
	removeitem ITEM_LETTER
# 106 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED
# 107 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StartMyrtleScene
	return

HavenTown_MrRupertPark_2:
# 93 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_RupertBadPeople, MSGBOX_NPC
# 94 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_MrRupertPark_5:
# 99 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertAfterQuest, MSGBOX_NPC
# 100 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_EventScript_StartMyrtleScene::
# 111 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 1
# 112 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 113 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 114 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 115 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_PROF_MYRTLE
# 116 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_1
# 117 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_2
# 118 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleWalkNorth
# 119 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 120 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleAsksDirections, MSGBOX_NPC
# 121 "data/maps/HavenTown/scripts.pory"
	delay 60
# 122 "data/maps/HavenTown/scripts.pory"
	playse SE_PIN
# 123 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 124 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, Common_Movement_ExclamationMark
# 125 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_ROCKET_HIDEOUT, TRUE
# 126 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsAmbushMyrtle, MSGBOX_NPC
# 127 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_Movement_GruntsWalkNorth
# 128 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_Movement_GruntsWalkNorth
# 129 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 130 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleGetsShoved
# 131 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_0, MSGBOX_NPC
# 133 "data/maps/HavenTown/scripts.pory"
	playse SE_BALL_BOUNCE_3
# 134 "data/maps/HavenTown/scripts.pory"
	delay 20
# 135 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_TREECKO_BALL
# 136 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_MUDKIP_BALL
# 137 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_HAVEN_CHARMANDER_BALL
# 138 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 139 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 140 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 141 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleUseOnePokemon, MSGBOX_NPC
# 142 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_ProfMyrtle::
# 147 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_ProfMyrtle_2
# 150 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleAfterEscort, MSGBOX_NPC
HavenTown_ProfMyrtle_1:
	end

HavenTown_ProfMyrtle_2:
# 148 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleRepeatInstruction, MSGBOX_NPC
	goto HavenTown_ProfMyrtle_1


HavenTown_Grunt1::
# 156 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_Grunt2::
# 161 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_TreeckoBall::
# 166 "data/maps/HavenTown/scripts.pory"
	lock
# 167 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 0
# 168 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_TREECKO
# 169 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_MudkipBall::
# 173 "data/maps/HavenTown/scripts.pory"
	lock
# 174 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 1
# 175 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_MUDKIP
# 176 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_CharmanderBall::
# 180 "data/maps/HavenTown/scripts.pory"
	lock
# 181 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 2
# 182 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_CHARMANDER
# 183 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_EventScript_ConfirmStarterChoice::
# 187 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_ne HavenTown_EventScript_ConfirmStarterChoice_2
# 192 "data/maps/HavenTown/scripts.pory"
	showmonpic VAR_TEMP_3, 10, 3
# 193 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ChooseStarterConfirm, MSGBOX_YESNO
# 194 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_ConfirmStarterChoice_5
HavenTown_EventScript_ConfirmStarterChoice_4:
# 198 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 199 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_2:
# 188 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_5:
# 195 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterChosen
	goto HavenTown_EventScript_ConfirmStarterChoice_4


HavenTown_EventScript_StarterChosen::
# 204 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 205 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 206 "data/maps/HavenTown/scripts.pory"
	givemon VAR_TEMP_3, 5
# 207 "data/maps/HavenTown/scripts.pory"
	copyvar VAR_STARTER_MON, VAR_TEMP_2
# 208 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 209 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterChosen_Text_0, MSGBOX_NPC
# 210 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterBattle
	return


HavenTown_EventScript_StarterBattle::
# 214 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntBattleStart, MSGBOX_NPC
# 215 "data/maps/HavenTown/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ASHEN_GRUNT_HAVEN, HavenTown_Text_GruntBattleStart, HavenTown_Text_GruntBattleDefeat, HavenTown_EventScript_StarterBattleAfterBattle
	end


HavenTown_EventScript_StarterBattleAfterBattle::
# 220 "data/maps/HavenTown/scripts.pory"
	call HavenTown_EventScript_HideStarterBalls
# 221 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsRetreat, MSGBOX_NPC
# 222 "data/maps/HavenTown/scripts.pory"
	closemessage
# 223 "data/maps/HavenTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 224 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 225 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 226 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 227 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 228 "data/maps/HavenTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 229 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_PALLET, TRUE
# 230 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleThanks, MSGBOX_NPC
# 231 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtlePresentation, MSGBOX_NPC
# 232 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_0
# 234 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 235 "data/maps/HavenTown/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESMAYBE, 1, TRUE
# 236 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleComeWithMe, MSGBOX_NPC
# 237 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 238 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_1, MSGBOX_NPC
# 240 "data/maps/HavenTown/scripts.pory"
	message HavenTown_Text_ReceivedStarter
# 241 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 242 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 243 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 244 "data/maps/HavenTown/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 245 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_StarterBattleAfterBattle_2
HavenTown_EventScript_StarterBattleAfterBattle_1:
# 249 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_2, MSGBOX_NPC
# 252 "data/maps/HavenTown/scripts.pory"
	fadescreen FADE_TO_BLACK
# 253 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 2
# 254 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 255 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 256 "data/maps/HavenTown/scripts.pory"
	warp MAP_HAVEN_TOWN, 11, 16
# 257 "data/maps/HavenTown/scripts.pory"
	delay 60
# 258 "data/maps/HavenTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_MYRTLE_2, MOVEMENT_TYPE_FACE_RIGHT
# 259 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_3
# 260 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_EventScript_StarterBattleAfterBattle_Text_4, 0
# 261 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_EventScript_StarterBattleAfterBattle_Text_5, 1
# 262 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_EventScript_StarterBattleAfterBattle_Text_6, 2
# 263 "data/maps/HavenTown/scripts.pory"
	dynmultistack 20, 8, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 264 "data/maps/HavenTown/scripts.pory"
	switch VAR_RESULT
# 265 "data/maps/HavenTown/scripts.pory"
	case 0, HavenTown_EventScript_StarterBattleAfterBattle_6
# 267 "data/maps/HavenTown/scripts.pory"
	case 1, HavenTown_EventScript_StarterBattleAfterBattle_7
# 269 "data/maps/HavenTown/scripts.pory"
	case 2, HavenTown_EventScript_StarterBattleAfterBattle_8
HavenTown_EventScript_StarterBattleAfterBattle_4:
# 272 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE_2, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 273 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 274 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 275 "data/maps/HavenTown/scripts.pory"
	delay 30
# 276 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_MOM, Common_Movement_ExclamationMark
# 277 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 278 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_10, MSGBOX_NPC
# 279 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_MOM, HavenTown_EventScript_StarterBattleAfterBattle_Movement_1
# 280 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 281 "data/maps/HavenTown/scripts.pory"
	playse SE_DOOR
# 282 "data/maps/HavenTown/scripts.pory"
	waitse
# 283 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_CEDRIC_START
# 284 "data/maps/HavenTown/scripts.pory"
	delay 30
# 285 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_START, Common_Movement_ExclamationMark
# 286 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 287 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_11, MSGBOX_NPC
# 288 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_12, MSGBOX_NPC
# 292 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_START, Common_Movement_QuestionMark
# 293 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 294 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_13, MSGBOX_NPC
# 295 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_14, MSGBOX_NPC
# 296 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_15, MSGBOX_NPC
# 297 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_StarterBattleAfterBattle_2:
# 246 "data/maps/HavenTown/scripts.pory"
	setvar VAR_0x8004, 0
# 247 "data/maps/HavenTown/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto HavenTown_EventScript_StarterBattleAfterBattle_1

HavenTown_EventScript_StarterBattleAfterBattle_6:
# 266 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_7, MSGBOX_NPC
	goto HavenTown_EventScript_StarterBattleAfterBattle_4

HavenTown_EventScript_StarterBattleAfterBattle_7:
# 268 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_8, MSGBOX_NPC
	goto HavenTown_EventScript_StarterBattleAfterBattle_4

HavenTown_EventScript_StarterBattleAfterBattle_8:
# 270 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_9, MSGBOX_NPC
	goto HavenTown_EventScript_StarterBattleAfterBattle_4


HavenTown_EventScript_GreetFromWoman::
# 302 "data/maps/HavenTown/scripts.pory"
	lockall
# 303 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GreetFromWoman
# 304 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 305 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice1, 0
# 306 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice2, 1
# 307 "data/maps/HavenTown/scripts.pory"
	dynmultistack 20, 8, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 308 "data/maps/HavenTown/scripts.pory"
	switch VAR_RESULT
# 309 "data/maps/HavenTown/scripts.pory"
	case 0, HavenTown_EventScript_GreetFromWoman_3
# 311 "data/maps/HavenTown/scripts.pory"
	case 1, HavenTown_EventScript_GreetFromWoman_4
# 312 "data/maps/HavenTown/scripts.pory"
	case MULTI_B_PRESSED, HavenTown_EventScript_GreetFromWoman_4
HavenTown_EventScript_GreetFromWoman_1:
# 315 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_GreetFromWoman_3:
# 310 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice1, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1

HavenTown_EventScript_GreetFromWoman_4:
# 313 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice2, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1


HavenTown_EventScript_HideStarterBalls::
# 320 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 321 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 322 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 323 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_TREECKO_BALL
# 324 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_MUDKIP_BALL
# 325 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_HAVEN_CHARMANDER_BALL
	return


HavenTown_PotionItem::
# 330 "data/maps/HavenTown/scripts.pory"
	lock
# 331 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_GOT_HAVENTOWN_POTION, HavenTown_PotionItem_2
# 337 "data/maps/HavenTown/scripts.pory"
	finditem ITEM_POTION
# 338 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HavenTown_PotionItem_5
# 343 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_GOT_HAVENTOWN_POTION
# 344 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_2:
# 332 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PotionItemGone, MSGBOX_NPC
# 333 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_5:
# 339 "data/maps/HavenTown/scripts.pory"
	release
	end


# 348 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromPark:
# 349 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 352 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromTownExit:
# 353 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 356 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromGrunts:
# 357 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

# 360 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleWalkNorth:
# 361 "data/maps/HavenTown/scripts.pory"
	walk_up
# 361 "data/maps/HavenTown/scripts.pory"
	walk_up
# 361 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 364 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleGetsShoved:
# 365 "data/maps/HavenTown/scripts.pory"
	walk_up
# 366 "data/maps/HavenTown/scripts.pory"
	face_down
# 367 "data/maps/HavenTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 370 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_GruntsWalkNorth:
# 371 "data/maps/HavenTown/scripts.pory"
	walk_up
# 371 "data/maps/HavenTown/scripts.pory"
	walk_up
# 371 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 272 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StarterBattleAfterBattle_Movement_0:
# 272 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 279 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StarterBattleAfterBattle_Movement_1:
# 279 "data/maps/HavenTown/scripts.pory"
	face_left
# 279 "data/maps/HavenTown/scripts.pory"
	walk_left
# 279 "data/maps/HavenTown/scripts.pory"
	face_down
	step_end

HavenTown_EventScript_StartMyrtleScene_Text_0:
# 132 "data/maps/HavenTown/scripts.pory"
	.string "Hey! Get off me!$"

HavenTown_EventScript_StarterChosen_Text_0:
# 209 "data/maps/HavenTown/scripts.pory"
	.string "You pick up {STR_VAR_1}'s pokeball!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_0:
# 232 "data/maps/HavenTown/scripts.pory"
	.string "Do you know a kid by the name\n"
	.string "{RIVAL2}?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_1:
# 238 "data/maps/HavenTown/scripts.pory"
	.string "You don't need to give me\n"
	.string "{STR_VAR_1} back, it's your partner\l"
	.string "now.\p"
	.string "I can see he already trusts you!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_2:
# 249 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Take good care of\n"
	.string "{STR_VAR_1}!\p"
	.string "You can help your POKéMON grow\n"
	.string "stronger by battling with it.$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_3:
# 259 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: So, is it here?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_4:
# 260 "data/maps/HavenTown/scripts.pory"
	.string "Yes, it's here!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_5:
# 261 "data/maps/HavenTown/scripts.pory"
	.string "Yeah, but...$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_6:
# 262 "data/maps/HavenTown/scripts.pory"
	.string "Yep. I should be going, though.$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_7:
# 266 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Good! Let's see your\n"
	.string "friend!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_8:
# 268 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Let's go!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_9:
# 270 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Nonsense!\n"
	.string "Let's go!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_10:
# 278 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}'s Mom: {RIVAL2} dear!\n"
	.string "The professor is here!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_11:
# 287 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: Oh, is this dad's friend?\n"
	.string "Does she have my POKéMON?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_12:
# 288 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Hello {RIVAL2}, I'm Professor\n"
	.string "Myrtle.\p"
	.string "Your father, he... He's busy with his\n"
	.string "very important research, but he asked\l"
	.string "me to give you your first POKéMON.\p"
	.string "Here, you can choose one of these\n"
	.string "three!\p"
	.string "I mean two!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_13:
# 294 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: Wait, where's the third one?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_14:
# 295 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Well ...$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_15:
# 296 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: Why does {PLAYER} has a POKéMON?\p"
	.string "Why did he get to choose first?!$"
