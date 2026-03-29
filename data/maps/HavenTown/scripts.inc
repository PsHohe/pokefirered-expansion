HavenTown_MapScripts::
# 5 "data/maps/HavenTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_OnTransition
# 6 "data/maps/HavenTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HavenTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HavenTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/HavenTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_HAVEN_TOWN, 3, HavenTown_EventScript_CedricOutsideChallenge
	.2byte 0


HavenTown_OnTransition::
# 12 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_0, 0
# 13 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 14 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 15 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 16 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 17 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 18 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 19 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 21 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_OnTransition_2
# 30 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 2
	goto_if_eq HavenTown_OnTransition_3
# 34 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_CEDRIC_MOM_OUTSIDE_HAVEN
# 37 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 3
	goto_if_ne HavenTown_OnTransition_8
# 41 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_CEDRIC_OUTSIDE_HAVEN
# 42 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_CEDRIC_OUTSIDE
HavenTown_OnTransition_7:
# 45 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_OnTransition_13
HavenTown_OnTransition_11:
# 49 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 5
	goto_if_ge HavenTown_OnTransition_17
HavenTown_OnTransition_16:
	end

HavenTown_OnTransition_2:
# 22 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 23 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 24 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 25 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 26 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 27 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 28 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	end

HavenTown_OnTransition_3:
# 31 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	end

HavenTown_OnTransition_8:
# 38 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_CEDRIC_OUTSIDE_HAVEN
# 39 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_CEDRIC_OUTSIDE
	goto HavenTown_OnTransition_7

HavenTown_OnTransition_12:
# 46 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	goto HavenTown_OnTransition_11

HavenTown_OnTransition_13:
# 45 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_OnTransition_12
	goto HavenTown_OnTransition_11

HavenTown_OnTransition_17:
# 50 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto HavenTown_OnTransition_16


HavenTown_TownSign::
# 56 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_TownSign, MSGBOX_SIGN
	end


HavenTown_Rival2Mailbox::
# 61 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_Rival2Mailbox, MSGBOX_SIGN
	end


HavenTown_TrainerTips::
# 66 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end


HavenTown_ParkSign::
# 71 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkSign, MSGBOX_SIGN
	end


HavenTown_CedricsMom::
# 76 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_CedricsMom, MSGBOX_NPC
	end


HavenTown_ParkGateStopTrigger::
# 81 "data/maps/HavenTown/scripts.pory"
	lockall
# 82 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_ParkGateStopTrigger_4
HavenTown_ParkGateStopTrigger_1:
# 89 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_ParkGateStopTrigger_2:
# 85 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromPark
# 86 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 87 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkGateStop, MSGBOX_NPC
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_3:
# 84 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_ParkGateStopTrigger_2
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_4:
# 83 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_ParkGateStopTrigger_3
	goto HavenTown_ParkGateStopTrigger_1


HavenTown_LeaveTownBlockedTrigger::
# 94 "data/maps/HavenTown/scripts.pory"
	lockall
# 95 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, HavenTown_LeaveTownBlockedTrigger_2
# 99 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 4
	goto_if_eq HavenTown_LeaveTownBlockedTrigger_3
HavenTown_LeaveTownBlockedTrigger_1:
# 106 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_LeaveTownBlockedTrigger_2:
# 96 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromTownExit
# 97 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 98 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_LeaveTownBlocked, MSGBOX_NPC
	goto HavenTown_LeaveTownBlockedTrigger_1

HavenTown_LeaveTownBlockedTrigger_3:
# 100 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromTownExit
# 101 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 102 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_LeaveTownBlockedTrigger_Text_0, MSGBOX_NPC
	goto HavenTown_LeaveTownBlockedTrigger_1


HavenTown_EventScript_CedricOutsideChallenge::
# 111 "data/maps/HavenTown/scripts.pory"
	lockall
# 112 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 4
# 113 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_OUTSIDE, HavenTown_Movement_CedricWalksOut
# 114 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerApproachesCedric
# 115 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 116 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_OUTSIDE, Common_Movement_ExclamationMark
# 117 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_EventScript_CedricOutsideChallenge_Movement_0
# 118 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 119 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 120 "data/maps/HavenTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_MYRTLE, 10, 13
# 121 "data/maps/HavenTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_MYRTLE, MOVEMENT_TYPE_FACE_RIGHT
# 122 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_PROF_MYRTLE
# 123 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleStepsInBeforeBattle
# 124 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 126 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, FALSE
# 127 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_CedricOutsideChallenge_Text_0, MSGBOX_NPC
# 129 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_CedricOutsideChallenge_Text_1, MSGBOX_NPC
# 137 "data/maps/HavenTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq HavenTown_EventScript_CedricOutsideChallenge_2
# 139 "data/maps/HavenTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq HavenTown_EventScript_CedricOutsideChallenge_3
# 142 "data/maps/HavenTown/scripts.pory"
	trainerbattle_earlyrival TRAINER_TEAM_CEDRIC_HAVEN_CHARMANDER, RIVAL_BATTLE_HEAL_AFTER, HavenTown_EventScript_CedricOutsideChallenge_Text_2, HavenTown_EventScript_CedricOutsideChallenge_Text_3
HavenTown_EventScript_CedricOutsideChallenge_1:
# 145 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_RIVAL_EXIT, FALSE
# 146 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HavenTown_EventScript_CedricOutsideChallenge_8
# 153 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_CedricOutsideChallenge_Text_5, MSGBOX_NPC
HavenTown_EventScript_CedricOutsideChallenge_7:
# 156 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_CEDRIC_OUTSIDE, HavenTown_Movement_CedricStormsOff
# 157 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 158 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_CEDRIC_OUTSIDE_HAVEN
# 159 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_CEDRIC_OUTSIDE
# 161 "data/maps/HavenTown/scripts.pory"
	fadeoutbgm 0
# 162 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_PALLET, TRUE
# 163 "data/maps/HavenTown/scripts.pory"
	fadeinbgm 0
# 165 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepsToMyrtle
# 166 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 167 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_CedricOutsideChallenge_Text_6, MSGBOX_NPC
# 180 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleLeavesForRidgepass
# 181 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 182 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 183 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_PROF_MYRTLE
# 184 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_CedricOutsideChallenge_2:
# 138 "data/maps/HavenTown/scripts.pory"
	trainerbattle_earlyrival TRAINER_TEAM_CEDRIC_HAVEN_SQUIRTLE, RIVAL_BATTLE_HEAL_AFTER, HavenTown_EventScript_CedricOutsideChallenge_Text_2, HavenTown_EventScript_CedricOutsideChallenge_Text_3
	goto HavenTown_EventScript_CedricOutsideChallenge_1

HavenTown_EventScript_CedricOutsideChallenge_3:
# 140 "data/maps/HavenTown/scripts.pory"
	trainerbattle_earlyrival TRAINER_TEAM_CEDRIC_HAVEN_BULBASAUR, RIVAL_BATTLE_HEAL_AFTER, HavenTown_EventScript_CedricOutsideChallenge_Text_2, HavenTown_EventScript_CedricOutsideChallenge_Text_3
	goto HavenTown_EventScript_CedricOutsideChallenge_1

HavenTown_EventScript_CedricOutsideChallenge_8:
# 147 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_CedricOutsideChallenge_Text_4, MSGBOX_NPC
	goto HavenTown_EventScript_CedricOutsideChallenge_7


HavenTown_MrRupertPark::
# 189 "data/maps/HavenTown/scripts.pory"
	lock
# 190 "data/maps/HavenTown/scripts.pory"
	faceplayer
# 192 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_MrRupertPark_2
# 198 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_MrRupertPark_5
# 204 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertPark, MSGBOX_NPC
# 205 "data/maps/HavenTown/scripts.pory"
	removeitem ITEM_LETTER
# 206 "data/maps/HavenTown/scripts.pory"
	message HavenTown_MrRupertPark_Text_0
# 207 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 208 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 209 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED
# 210 "data/maps/HavenTown/scripts.pory"
	closemessage
# 211 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StartMyrtleScene
	return

HavenTown_MrRupertPark_2:
# 193 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_RupertBadPeople, MSGBOX_NPC
# 194 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_MrRupertPark_5:
# 199 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertAfterQuest, MSGBOX_NPC
# 200 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_EventScript_StartMyrtleScene::
# 215 "data/maps/HavenTown/scripts.pory"
	lockall
# 216 "data/maps/HavenTown/scripts.pory"
	delay 90
# 217 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 1
# 218 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 219 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 220 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 221 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_PROF_MYRTLE
# 222 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_1
# 223 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_2
# 224 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleWalkNorth
# 225 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 226 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_0, MSGBOX_NPC
# 227 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_EventScript_StartMyrtleScene_Movement_0
# 228 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 229 "data/maps/HavenTown/scripts.pory"
	delay 30
# 230 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_1, MSGBOX_NPC
# 231 "data/maps/HavenTown/scripts.pory"
	playse SE_PIN
# 232 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, Common_Movement_ExclamationMark
# 233 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 234 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_ROCKET_HIDEOUT, TRUE
# 235 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsAmbushMyrtle, MSGBOX_NPC
# 236 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_Movement_GruntsWalkNorth
# 237 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_Movement_GruntsWalkNorth
# 238 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 239 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleGetsShoved
# 240 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 241 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_2, MSGBOX_NPC
# 242 "data/maps/HavenTown/scripts.pory"
	playse SE_BALL_BOUNCE_3
# 243 "data/maps/HavenTown/scripts.pory"
	waitse
# 244 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_TREECKO_BALL
# 245 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_MUDKIP_BALL
# 246 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_HAVEN_CHARMANDER_BALL
# 247 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 248 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 249 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 250 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_3, MSGBOX_NPC
# 252 "data/maps/HavenTown/scripts.pory"
	delay 30
# 253 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_4, MSGBOX_NPC
# 258 "data/maps/HavenTown/scripts.pory"
	delay 30
# 259 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_5, MSGBOX_NPC
# 261 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_ProfMyrtle::
# 266 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_ProfMyrtle_2
# 269 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleAfterEscort, MSGBOX_NPC
HavenTown_ProfMyrtle_1:
	end

HavenTown_ProfMyrtle_2:
# 267 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleRepeatInstruction, MSGBOX_NPC
	goto HavenTown_ProfMyrtle_1


HavenTown_Grunt1::
# 275 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_Grunt2::
# 280 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_TreeckoBall::
# 285 "data/maps/HavenTown/scripts.pory"
	lock
# 286 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 0
# 287 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_TREECKO
# 288 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_MudkipBall::
# 292 "data/maps/HavenTown/scripts.pory"
	lock
# 293 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 1
# 294 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_MUDKIP
# 295 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_CharmanderBall::
# 299 "data/maps/HavenTown/scripts.pory"
	lock
# 300 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 2
# 301 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_CHARMANDER
# 302 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_EventScript_ConfirmStarterChoice::
# 306 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_ne HavenTown_EventScript_ConfirmStarterChoice_2
# 311 "data/maps/HavenTown/scripts.pory"
	showmonpic VAR_TEMP_3, 10, 3
# 312 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ChooseStarterConfirm, MSGBOX_YESNO
# 313 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_ConfirmStarterChoice_5
HavenTown_EventScript_ConfirmStarterChoice_4:
# 317 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 318 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_2:
# 307 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_5:
# 314 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterChosen
	goto HavenTown_EventScript_ConfirmStarterChoice_4


HavenTown_EventScript_StarterChosen::
# 323 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 324 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 325 "data/maps/HavenTown/scripts.pory"
	givemon VAR_TEMP_3, 5
# 326 "data/maps/HavenTown/scripts.pory"
	copyvar VAR_STARTER_MON, VAR_TEMP_2
# 327 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 328 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterChosen_Text_0, MSGBOX_NPC
# 329 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterBattle
	return


HavenTown_EventScript_StarterBattle::
# 333 "data/maps/HavenTown/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ASHEN_GRUNT_HAVEN, HavenTown_Text_GruntBattleStart, HavenTown_Text_GruntBattleDefeat, HavenTown_EventScript_StarterBattleAfterBattle
	end


HavenTown_EventScript_StarterBattleAfterBattle::
# 338 "data/maps/HavenTown/scripts.pory"
	call HavenTown_EventScript_HideStarterBalls
# 339 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsRetreat, MSGBOX_NPC
# 340 "data/maps/HavenTown/scripts.pory"
	closemessage
# 341 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 342 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 343 "data/maps/HavenTown/scripts.pory"
	fadeoutbgm 4
# 344 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 345 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 346 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 347 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 348 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 349 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_PALLET, TRUE
# 350 "data/maps/HavenTown/scripts.pory"
	fadeinbgm 0
# 351 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleThanks, MSGBOX_NPC
# 352 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtlePresentation, MSGBOX_NPC
# 353 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_0
# 355 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 356 "data/maps/HavenTown/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESMAYBE, 1, TRUE
# 357 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleComeWithMe, MSGBOX_NPC
# 358 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 359 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_1, MSGBOX_NPC
# 364 "data/maps/HavenTown/scripts.pory"
	message HavenTown_Text_ReceivedStarter
# 365 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 366 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 367 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 368 "data/maps/HavenTown/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 369 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_StarterBattleAfterBattle_2
HavenTown_EventScript_StarterBattleAfterBattle_1:
# 373 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_2, MSGBOX_NPC
# 379 "data/maps/HavenTown/scripts.pory"
	special HealPlayerParty
# 380 "data/maps/HavenTown/scripts.pory"
	delay 30
# 381 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_3, MSGBOX_NPC
# 383 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 2
# 384 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 385 "data/maps/HavenTown/scripts.pory"
	warp MAP_CEDRIC_HOUSE, 5, 10
# 386 "data/maps/HavenTown/scripts.pory"
	waitstate
# 387 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_StarterBattleAfterBattle_2:
# 370 "data/maps/HavenTown/scripts.pory"
	setvar VAR_0x8004, 0
# 371 "data/maps/HavenTown/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto HavenTown_EventScript_StarterBattleAfterBattle_1


HavenTown_EventScript_GreetFromWoman::
# 392 "data/maps/HavenTown/scripts.pory"
	lockall
# 393 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GreetFromWoman
# 394 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 395 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice1, 0
# 396 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice2, 1
# 397 "data/maps/HavenTown/scripts.pory"
	dynmultistack 20, 8, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 398 "data/maps/HavenTown/scripts.pory"
	switch VAR_RESULT
# 399 "data/maps/HavenTown/scripts.pory"
	case 0, HavenTown_EventScript_GreetFromWoman_3
# 401 "data/maps/HavenTown/scripts.pory"
	case 1, HavenTown_EventScript_GreetFromWoman_4
# 402 "data/maps/HavenTown/scripts.pory"
	case MULTI_B_PRESSED, HavenTown_EventScript_GreetFromWoman_4
HavenTown_EventScript_GreetFromWoman_1:
# 405 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_GreetFromWoman_3:
# 400 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice1, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1

HavenTown_EventScript_GreetFromWoman_4:
# 403 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice2, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1


HavenTown_EventScript_HideStarterBalls::
# 410 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 411 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 412 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 413 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_TREECKO_BALL
# 414 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_MUDKIP_BALL
# 415 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_HAVEN_CHARMANDER_BALL
	return


HavenTown_PotionItem::
# 420 "data/maps/HavenTown/scripts.pory"
	lock
# 421 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_GOT_HAVENTOWN_POTION, HavenTown_PotionItem_2
# 427 "data/maps/HavenTown/scripts.pory"
	finditem ITEM_POTION
# 428 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HavenTown_PotionItem_5
# 433 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_GOT_HAVENTOWN_POTION
# 434 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_2:
# 422 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PotionItemGone, MSGBOX_NPC
# 423 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_5:
# 429 "data/maps/HavenTown/scripts.pory"
	release
	end


# 438 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromPark:
# 439 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 442 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromTownExit:
# 443 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 446 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromGrunts:
# 447 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

# 450 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleWalkNorth:
# 451 "data/maps/HavenTown/scripts.pory"
	walk_up
# 451 "data/maps/HavenTown/scripts.pory"
	walk_up
# 451 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 454 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleGetsShoved:
# 455 "data/maps/HavenTown/scripts.pory"
	walk_up
# 456 "data/maps/HavenTown/scripts.pory"
	face_down
# 457 "data/maps/HavenTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 460 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_GruntsWalkNorth:
# 461 "data/maps/HavenTown/scripts.pory"
	walk_up
# 461 "data/maps/HavenTown/scripts.pory"
	walk_up
# 461 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 464 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_CedricWalksOut:
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 465 "data/maps/HavenTown/scripts.pory"
	walk_right
# 466 "data/maps/HavenTown/scripts.pory"
	face_left
# 467 "data/maps/HavenTown/scripts.pory"
	step_end

# 470 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerApproachesCedric:
# 471 "data/maps/HavenTown/scripts.pory"
	walk_right
# 471 "data/maps/HavenTown/scripts.pory"
	walk_right
# 471 "data/maps/HavenTown/scripts.pory"
	walk_right
# 471 "data/maps/HavenTown/scripts.pory"
	walk_right
# 471 "data/maps/HavenTown/scripts.pory"
	walk_right
# 472 "data/maps/HavenTown/scripts.pory"
	step_end

# 475 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_CedricStormsOff:
# 476 "data/maps/HavenTown/scripts.pory"
	walk_left
# 477 "data/maps/HavenTown/scripts.pory"
	walk_down
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 478 "data/maps/HavenTown/scripts.pory"
	walk_left
# 479 "data/maps/HavenTown/scripts.pory"
	walk_down
# 479 "data/maps/HavenTown/scripts.pory"
	walk_down
# 480 "data/maps/HavenTown/scripts.pory"
	walk_left
# 480 "data/maps/HavenTown/scripts.pory"
	walk_left
# 480 "data/maps/HavenTown/scripts.pory"
	walk_left
# 480 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 483 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepsToMyrtle:
# 484 "data/maps/HavenTown/scripts.pory"
	walk_left
# 484 "data/maps/HavenTown/scripts.pory"
	walk_left
# 484 "data/maps/HavenTown/scripts.pory"
	walk_left
# 484 "data/maps/HavenTown/scripts.pory"
	walk_left
# 485 "data/maps/HavenTown/scripts.pory"
	step_end

# 488 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleStepsInBeforeBattle:
# 489 "data/maps/HavenTown/scripts.pory"
	walk_right
# 489 "data/maps/HavenTown/scripts.pory"
	walk_right
	step_end

# 492 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleLeavesForRidgepass:
# 493 "data/maps/HavenTown/scripts.pory"
	walk_down
# 493 "data/maps/HavenTown/scripts.pory"
	walk_down
# 493 "data/maps/HavenTown/scripts.pory"
	walk_down
# 494 "data/maps/HavenTown/scripts.pory"
	walk_right
# 494 "data/maps/HavenTown/scripts.pory"
	walk_right
# 494 "data/maps/HavenTown/scripts.pory"
	walk_right
# 494 "data/maps/HavenTown/scripts.pory"
	walk_right
# 494 "data/maps/HavenTown/scripts.pory"
	walk_right
# 494 "data/maps/HavenTown/scripts.pory"
	walk_right
	step_end

# 117 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_CedricOutsideChallenge_Movement_0:
# 117 "data/maps/HavenTown/scripts.pory"
	face_right
	step_end

# 227 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StartMyrtleScene_Movement_0:
# 227 "data/maps/HavenTown/scripts.pory"
	face_down
	step_end

# 341 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StarterBattleAfterBattle_Movement_0:
# 341 "data/maps/HavenTown/scripts.pory"
	walk_down
# 341 "data/maps/HavenTown/scripts.pory"
	walk_down
# 341 "data/maps/HavenTown/scripts.pory"
	walk_down
# 341 "data/maps/HavenTown/scripts.pory"
	walk_down
# 341 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

HavenTown_LeaveTownBlockedTrigger_Text_0:
# 102 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle told you to let Mrs.\n"
	.string "Marina know before leaving.\p"
	.string "You should visit the orphanage first.$"

HavenTown_EventScript_CedricOutsideChallenge_Text_0:
# 127 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: Hah! You're finally here.\n"
	.string "Let's see whose POKeMON is stronger!$"

HavenTown_EventScript_CedricOutsideChallenge_Text_1:
# 129 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: This battle won't\n"
	.string "be easy, {PLAYER}.\p"
	.string "I'll observe it from here.\p"
	.string "Show me how you and your partner\n"
	.string "handle a real challenge.$"

HavenTown_EventScript_CedricOutsideChallenge_Text_2:
# 138 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: What?!\n"
	.string "I lost?!$"

HavenTown_EventScript_CedricOutsideChallenge_Text_3:
# 138 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: See? I won!$"

HavenTown_EventScript_CedricOutsideChallenge_Text_4:
# 147 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: Hah! That's what\n"
	.string "I expected.\p"
	.string "Train harder if you want to\n"
	.string "keep up with me!$"

HavenTown_EventScript_CedricOutsideChallenge_Text_5:
# 153 "data/maps/HavenTown/scripts.pory"
	.string "{RIVAL2}: This doesn't count!\n"
	.string "Next time, I'll crush you for sure!$"

HavenTown_EventScript_CedricOutsideChallenge_Text_6:
# 167 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Good battle,\n"
	.string "{PLAYER}.\p"
	.string "You stayed focused and adapted\n"
	.string "well out there.\p"
	.string "Meet me in Ridgepass Town.\n"
	.string "I have something for you there.\p"
	.string "Tell the orphanage if you're\n"
	.string "starting your journey.\p"
	.string "They deserve to hear it from you.$"

HavenTown_MrRupertPark_Text_0:
# 206 "data/maps/HavenTown/scripts.pory"
	.string "You gave the letter to Mr. Rupert.$"

HavenTown_EventScript_StartMyrtleScene_Text_0:
# 226 "data/maps/HavenTown/scripts.pory"
	.string "Professor: Oh! Excuse me.$"

HavenTown_EventScript_StartMyrtleScene_Text_1:
# 230 "data/maps/HavenTown/scripts.pory"
	.string "Can you point me to Haven Town?$"

HavenTown_EventScript_StartMyrtleScene_Text_2:
# 241 "data/maps/HavenTown/scripts.pory"
	.string "Hey! Get off me!$"

HavenTown_EventScript_StartMyrtleScene_Text_3:
# 250 "data/maps/HavenTown/scripts.pory"
	.string "The professor dropped some\n"
	.string "pokeballs!$"

HavenTown_EventScript_StartMyrtleScene_Text_4:
# 253 "data/maps/HavenTown/scripts.pory"
	.string "Ashen Grunt: Now, now,\n"
	.string "professor!\p"
	.string "Just hand over your pokeballs\n"
	.string "and nobody gets hurt.$"

HavenTown_EventScript_StartMyrtleScene_Text_5:
# 259 "data/maps/HavenTown/scripts.pory"
	.string "Use one of the pokeballs\n"
	.string "to help her!$"

HavenTown_EventScript_StarterChosen_Text_0:
# 328 "data/maps/HavenTown/scripts.pory"
	.string "You pick up {STR_VAR_1}'s\n"
	.string "pokeball!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_0:
# 353 "data/maps/HavenTown/scripts.pory"
	.string "Do you know a kid by the name\n"
	.string "{RIVAL2}?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_1:
# 359 "data/maps/HavenTown/scripts.pory"
	.string "You don't need to give me\n"
	.string "{STR_VAR_1} back,\l"
	.string "it's your partner now.\p"
	.string "I can see he already trusts you!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_2:
# 373 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Take good care of\n"
	.string "{STR_VAR_1}!\p"
	.string "You can help your POKéMON grow\n"
	.string "stronger by battling with it.$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_3:
# 381 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Now, let's go\n"
	.string "to your friend's house!$"
