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
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_OnTransition_2
# 26 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 2
	goto_if_eq HavenTown_OnTransition_3
# 31 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 3
	goto_if_ne HavenTown_OnTransition_7
HavenTown_OnTransition_6:
# 36 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_OnTransition_11
HavenTown_OnTransition_9:
	end

HavenTown_OnTransition_2:
# 18 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 19 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 20 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 21 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 22 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 23 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 24 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
	end

HavenTown_OnTransition_3:
# 27 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
	end

HavenTown_OnTransition_7:
# 32 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_CEDRIC_OUTSIDE_HAVEN
# 33 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_CEDRIC_OUTSIDE
	goto HavenTown_OnTransition_6

HavenTown_OnTransition_10:
# 37 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	goto HavenTown_OnTransition_9

HavenTown_OnTransition_11:
# 36 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_OnTransition_10
	goto HavenTown_OnTransition_9


HavenTown_TownSign::
# 43 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_TownSign, MSGBOX_SIGN
	end


HavenTown_Rival2Mailbox::
# 48 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_Rival2Mailbox, MSGBOX_SIGN
	end


HavenTown_TrainerTips::
# 53 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end


HavenTown_ParkSign::
# 58 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkSign, MSGBOX_SIGN
	end


HavenTown_CedricsMom::
# 63 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_CedricsMom, MSGBOX_NPC
	end


HavenTown_ParkGateStopTrigger::
# 68 "data/maps/HavenTown/scripts.pory"
	lockall
# 69 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_ParkGateStopTrigger_4
HavenTown_ParkGateStopTrigger_1:
# 76 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_ParkGateStopTrigger_2:
# 72 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromPark
# 73 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkGateStop, MSGBOX_NPC
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_3:
# 71 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_ParkGateStopTrigger_2
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_4:
# 70 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_ParkGateStopTrigger_3
	goto HavenTown_ParkGateStopTrigger_1


HavenTown_LeaveTownBlockedTrigger::
# 81 "data/maps/HavenTown/scripts.pory"
	lockall
# 82 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, HavenTown_LeaveTownBlockedTrigger_2
HavenTown_LeaveTownBlockedTrigger_1:
# 87 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_LeaveTownBlockedTrigger_2:
# 83 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromTownExit
# 84 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 85 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_LeaveTownBlocked, MSGBOX_NPC
	goto HavenTown_LeaveTownBlockedTrigger_1


HavenTown_MrRupertPark::
# 92 "data/maps/HavenTown/scripts.pory"
	lock
# 93 "data/maps/HavenTown/scripts.pory"
	faceplayer
# 95 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_MrRupertPark_2
# 101 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_MrRupertPark_5
# 107 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertPark, MSGBOX_NPC
# 108 "data/maps/HavenTown/scripts.pory"
	removeitem ITEM_LETTER
# 109 "data/maps/HavenTown/scripts.pory"
	message HavenTown_MrRupertPark_Text_0
# 110 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 111 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 112 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED
# 113 "data/maps/HavenTown/scripts.pory"
	closemessage
# 114 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StartMyrtleScene
	return

HavenTown_MrRupertPark_2:
# 96 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_RupertBadPeople, MSGBOX_NPC
# 97 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_MrRupertPark_5:
# 102 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertAfterQuest, MSGBOX_NPC
# 103 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_EventScript_StartMyrtleScene::
# 118 "data/maps/HavenTown/scripts.pory"
	lockall
# 119 "data/maps/HavenTown/scripts.pory"
	delay 90
# 120 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 1
# 121 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 122 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 123 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 124 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_PROF_MYRTLE
# 125 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_1
# 126 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_2
# 127 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleWalkNorth
# 128 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 129 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_0, MSGBOX_NPC
# 130 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_EventScript_StartMyrtleScene_Movement_0
# 131 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/HavenTown/scripts.pory"
	delay 30
# 133 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_1, MSGBOX_NPC
# 134 "data/maps/HavenTown/scripts.pory"
	playse SE_PIN
# 135 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, Common_Movement_ExclamationMark
# 136 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 137 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_ROCKET_HIDEOUT, TRUE
# 138 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsAmbushMyrtle, MSGBOX_NPC
# 139 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_Movement_GruntsWalkNorth
# 140 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_Movement_GruntsWalkNorth
# 141 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 142 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleGetsShoved
# 143 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 144 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_2, MSGBOX_NPC
# 145 "data/maps/HavenTown/scripts.pory"
	playse SE_BALL_BOUNCE_3
# 146 "data/maps/HavenTown/scripts.pory"
	waitse
# 147 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_TREECKO_BALL
# 148 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_MUDKIP_BALL
# 149 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_HAVEN_CHARMANDER_BALL
# 150 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 151 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 152 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 153 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_3, MSGBOX_NPC
# 155 "data/maps/HavenTown/scripts.pory"
	delay 30
# 156 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_4, MSGBOX_NPC
# 161 "data/maps/HavenTown/scripts.pory"
	delay 30
# 162 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_5, MSGBOX_NPC
# 164 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_ProfMyrtle::
# 169 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_ProfMyrtle_2
# 172 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleAfterEscort, MSGBOX_NPC
HavenTown_ProfMyrtle_1:
	end

HavenTown_ProfMyrtle_2:
# 170 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleRepeatInstruction, MSGBOX_NPC
	goto HavenTown_ProfMyrtle_1


HavenTown_Grunt1::
# 178 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_Grunt2::
# 183 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_TreeckoBall::
# 188 "data/maps/HavenTown/scripts.pory"
	lock
# 189 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 0
# 190 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_TREECKO
# 191 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_MudkipBall::
# 195 "data/maps/HavenTown/scripts.pory"
	lock
# 196 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 1
# 197 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_MUDKIP
# 198 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_CharmanderBall::
# 202 "data/maps/HavenTown/scripts.pory"
	lock
# 203 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 2
# 204 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_CHARMANDER
# 205 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_EventScript_ConfirmStarterChoice::
# 209 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_ne HavenTown_EventScript_ConfirmStarterChoice_2
# 214 "data/maps/HavenTown/scripts.pory"
	showmonpic VAR_TEMP_3, 10, 3
# 215 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ChooseStarterConfirm, MSGBOX_YESNO
# 216 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_ConfirmStarterChoice_5
HavenTown_EventScript_ConfirmStarterChoice_4:
# 220 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 221 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_2:
# 210 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_5:
# 217 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterChosen
	goto HavenTown_EventScript_ConfirmStarterChoice_4


HavenTown_EventScript_StarterChosen::
# 226 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 227 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 228 "data/maps/HavenTown/scripts.pory"
	givemon VAR_TEMP_3, 5
# 229 "data/maps/HavenTown/scripts.pory"
	copyvar VAR_STARTER_MON, VAR_TEMP_2
# 230 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 231 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterChosen_Text_0, MSGBOX_NPC
# 232 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterBattle
	return


HavenTown_EventScript_StarterBattle::
# 236 "data/maps/HavenTown/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ASHEN_GRUNT_HAVEN, HavenTown_Text_GruntBattleStart, HavenTown_Text_GruntBattleDefeat, HavenTown_EventScript_StarterBattleAfterBattle
	end


HavenTown_EventScript_StarterBattleAfterBattle::
# 241 "data/maps/HavenTown/scripts.pory"
	call HavenTown_EventScript_HideStarterBalls
# 242 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsRetreat, MSGBOX_NPC
# 243 "data/maps/HavenTown/scripts.pory"
	closemessage
# 244 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 245 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 246 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 247 "data/maps/HavenTown/scripts.pory"
	fadeoutbgm 4
# 248 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 249 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 250 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 251 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 252 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_PALLET, TRUE
# 253 "data/maps/HavenTown/scripts.pory"
	fadeinbgm 0
# 254 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleThanks, MSGBOX_NPC
# 255 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtlePresentation, MSGBOX_NPC
# 256 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_0
# 258 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 259 "data/maps/HavenTown/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESMAYBE, 1, TRUE
# 260 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleComeWithMe, MSGBOX_NPC
# 261 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 262 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_1, MSGBOX_NPC
# 267 "data/maps/HavenTown/scripts.pory"
	message HavenTown_Text_ReceivedStarter
# 268 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 269 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 270 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 271 "data/maps/HavenTown/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 272 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_StarterBattleAfterBattle_2
HavenTown_EventScript_StarterBattleAfterBattle_1:
# 276 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_2, MSGBOX_NPC
# 282 "data/maps/HavenTown/scripts.pory"
	delay 30
# 283 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_3, MSGBOX_NPC
# 285 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 2
# 286 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 287 "data/maps/HavenTown/scripts.pory"
	warp MAP_CEDRIC_HOUSE, 5, 10
# 288 "data/maps/HavenTown/scripts.pory"
	waitstate
# 289 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_StarterBattleAfterBattle_2:
# 273 "data/maps/HavenTown/scripts.pory"
	setvar VAR_0x8004, 0
# 274 "data/maps/HavenTown/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto HavenTown_EventScript_StarterBattleAfterBattle_1


HavenTown_EventScript_GreetFromWoman::
# 294 "data/maps/HavenTown/scripts.pory"
	lockall
# 295 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GreetFromWoman
# 296 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 297 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice1, 0
# 298 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice2, 1
# 299 "data/maps/HavenTown/scripts.pory"
	dynmultistack 20, 8, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 300 "data/maps/HavenTown/scripts.pory"
	switch VAR_RESULT
# 301 "data/maps/HavenTown/scripts.pory"
	case 0, HavenTown_EventScript_GreetFromWoman_3
# 303 "data/maps/HavenTown/scripts.pory"
	case 1, HavenTown_EventScript_GreetFromWoman_4
# 304 "data/maps/HavenTown/scripts.pory"
	case MULTI_B_PRESSED, HavenTown_EventScript_GreetFromWoman_4
HavenTown_EventScript_GreetFromWoman_1:
# 307 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_GreetFromWoman_3:
# 302 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice1, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1

HavenTown_EventScript_GreetFromWoman_4:
# 305 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice2, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1


HavenTown_EventScript_HideStarterBalls::
# 312 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 313 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 314 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 315 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_TREECKO_BALL
# 316 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_MUDKIP_BALL
# 317 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_HAVEN_CHARMANDER_BALL
	return


HavenTown_PotionItem::
# 322 "data/maps/HavenTown/scripts.pory"
	lock
# 323 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_GOT_HAVENTOWN_POTION, HavenTown_PotionItem_2
# 329 "data/maps/HavenTown/scripts.pory"
	finditem ITEM_POTION
# 330 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HavenTown_PotionItem_5
# 335 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_GOT_HAVENTOWN_POTION
# 336 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_2:
# 324 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PotionItemGone, MSGBOX_NPC
# 325 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_5:
# 331 "data/maps/HavenTown/scripts.pory"
	release
	end


# 340 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromPark:
# 341 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 344 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromTownExit:
# 345 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 348 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromGrunts:
# 349 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

# 352 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleWalkNorth:
# 353 "data/maps/HavenTown/scripts.pory"
	walk_up
# 353 "data/maps/HavenTown/scripts.pory"
	walk_up
# 353 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 356 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleGetsShoved:
# 357 "data/maps/HavenTown/scripts.pory"
	walk_up
# 358 "data/maps/HavenTown/scripts.pory"
	face_down
# 359 "data/maps/HavenTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 362 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_GruntsWalkNorth:
# 363 "data/maps/HavenTown/scripts.pory"
	walk_up
# 363 "data/maps/HavenTown/scripts.pory"
	walk_up
# 363 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 130 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StartMyrtleScene_Movement_0:
# 130 "data/maps/HavenTown/scripts.pory"
	face_down
	step_end

# 244 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StarterBattleAfterBattle_Movement_0:
# 244 "data/maps/HavenTown/scripts.pory"
	walk_down
# 244 "data/maps/HavenTown/scripts.pory"
	walk_down
# 244 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

HavenTown_MrRupertPark_Text_0:
# 109 "data/maps/HavenTown/scripts.pory"
	.string "You gave the letter to Mr. Rupert.$"

HavenTown_EventScript_StartMyrtleScene_Text_0:
# 129 "data/maps/HavenTown/scripts.pory"
	.string "Professor: Oh! Excuse me.$"

HavenTown_EventScript_StartMyrtleScene_Text_1:
# 133 "data/maps/HavenTown/scripts.pory"
	.string "Can you point me to Haven Town?$"

HavenTown_EventScript_StartMyrtleScene_Text_2:
# 144 "data/maps/HavenTown/scripts.pory"
	.string "Hey! Get off me!$"

HavenTown_EventScript_StartMyrtleScene_Text_3:
# 153 "data/maps/HavenTown/scripts.pory"
	.string "The professor dropped some\n"
	.string "pokeballs!$"

HavenTown_EventScript_StartMyrtleScene_Text_4:
# 156 "data/maps/HavenTown/scripts.pory"
	.string "Ashen Grunt: Now, now,\n"
	.string "professor!\p"
	.string "Just hand over your pokeballs\n"
	.string "and nobody gets hurt.$"

HavenTown_EventScript_StartMyrtleScene_Text_5:
# 162 "data/maps/HavenTown/scripts.pory"
	.string "Use one of the pokeballs\n"
	.string "to help her!$"

HavenTown_EventScript_StarterChosen_Text_0:
# 231 "data/maps/HavenTown/scripts.pory"
	.string "You pick up {STR_VAR_1}'s\n"
	.string "pokeball!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_0:
# 256 "data/maps/HavenTown/scripts.pory"
	.string "Do you know a kid by the name\n"
	.string "{RIVAL2}?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_1:
# 262 "data/maps/HavenTown/scripts.pory"
	.string "You don't need to give me\n"
	.string "{STR_VAR_1} back,\l"
	.string "it's your partner now.\p"
	.string "I can see he already trusts you!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_2:
# 276 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Take good care of\n"
	.string "{STR_VAR_1}!\p"
	.string "You can help your POKéMON grow\n"
	.string "stronger by battling with it.$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_3:
# 283 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Now, let's go\n"
	.string "to your friend's house!$"
