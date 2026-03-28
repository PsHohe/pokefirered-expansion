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
# 30 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_CEDRIC_MOM_OUTSIDE_HAVEN
# 33 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 3
	goto_if_ne HavenTown_OnTransition_8
HavenTown_OnTransition_7:
# 38 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_OnTransition_12
HavenTown_OnTransition_10:
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

HavenTown_OnTransition_8:
# 34 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_CEDRIC_OUTSIDE_HAVEN
# 35 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_CEDRIC_OUTSIDE
	goto HavenTown_OnTransition_7

HavenTown_OnTransition_11:
# 39 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	goto HavenTown_OnTransition_10

HavenTown_OnTransition_12:
# 38 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_OnTransition_11
	goto HavenTown_OnTransition_10


HavenTown_TownSign::
# 45 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_TownSign, MSGBOX_SIGN
	end


HavenTown_Rival2Mailbox::
# 50 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_Rival2Mailbox, MSGBOX_SIGN
	end


HavenTown_TrainerTips::
# 55 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end


HavenTown_ParkSign::
# 60 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkSign, MSGBOX_SIGN
	end


HavenTown_CedricsMom::
# 65 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_CedricsMom, MSGBOX_NPC
	end


HavenTown_ParkGateStopTrigger::
# 70 "data/maps/HavenTown/scripts.pory"
	lockall
# 71 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_ParkGateStopTrigger_4
HavenTown_ParkGateStopTrigger_1:
# 78 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_ParkGateStopTrigger_2:
# 74 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromPark
# 75 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 76 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ParkGateStop, MSGBOX_NPC
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_3:
# 73 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_ParkGateStopTrigger_2
	goto HavenTown_ParkGateStopTrigger_1

HavenTown_ParkGateStopTrigger_4:
# 72 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_ParkGateStopTrigger_3
	goto HavenTown_ParkGateStopTrigger_1


HavenTown_LeaveTownBlockedTrigger::
# 83 "data/maps/HavenTown/scripts.pory"
	lockall
# 84 "data/maps/HavenTown/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, HavenTown_LeaveTownBlockedTrigger_2
HavenTown_LeaveTownBlockedTrigger_1:
# 89 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_LeaveTownBlockedTrigger_2:
# 85 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_Movement_PlayerStepBackFromTownExit
# 86 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 87 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_LeaveTownBlocked, MSGBOX_NPC
	goto HavenTown_LeaveTownBlockedTrigger_1


HavenTown_MrRupertPark::
# 94 "data/maps/HavenTown/scripts.pory"
	lock
# 95 "data/maps/HavenTown/scripts.pory"
	faceplayer
# 97 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_MrRupertPark_2
# 103 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_MrRupertPark_5
# 109 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertPark, MSGBOX_NPC
# 110 "data/maps/HavenTown/scripts.pory"
	removeitem ITEM_LETTER
# 111 "data/maps/HavenTown/scripts.pory"
	message HavenTown_MrRupertPark_Text_0
# 112 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 113 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 114 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED
# 115 "data/maps/HavenTown/scripts.pory"
	closemessage
# 116 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StartMyrtleScene
	return

HavenTown_MrRupertPark_2:
# 98 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_RupertBadPeople, MSGBOX_NPC
# 99 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_MrRupertPark_5:
# 104 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MrRupertAfterQuest, MSGBOX_NPC
# 105 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_EventScript_StartMyrtleScene::
# 120 "data/maps/HavenTown/scripts.pory"
	lockall
# 121 "data/maps/HavenTown/scripts.pory"
	delay 90
# 122 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 1
# 123 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_PROF_MYRTLE
# 124 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 125 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 126 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_PROF_MYRTLE
# 127 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_1
# 128 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_GRUNT_2
# 129 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleWalkNorth
# 130 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 131 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_0, MSGBOX_NPC
# 132 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PLAYER, HavenTown_EventScript_StartMyrtleScene_Movement_0
# 133 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 134 "data/maps/HavenTown/scripts.pory"
	delay 30
# 135 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_1, MSGBOX_NPC
# 136 "data/maps/HavenTown/scripts.pory"
	playse SE_PIN
# 137 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, Common_Movement_ExclamationMark
# 138 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 139 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_ROCKET_HIDEOUT, TRUE
# 140 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsAmbushMyrtle, MSGBOX_NPC
# 141 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_Movement_GruntsWalkNorth
# 142 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_Movement_GruntsWalkNorth
# 143 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 144 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_PROF_MYRTLE, HavenTown_Movement_MyrtleGetsShoved
# 145 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 146 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_2, MSGBOX_NPC
# 147 "data/maps/HavenTown/scripts.pory"
	playse SE_BALL_BOUNCE_3
# 148 "data/maps/HavenTown/scripts.pory"
	waitse
# 149 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_TREECKO_BALL
# 150 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_MUDKIP_BALL
# 151 "data/maps/HavenTown/scripts.pory"
	addobject LOCALID_HAVEN_CHARMANDER_BALL
# 152 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 153 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 154 "data/maps/HavenTown/scripts.pory"
	clearflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 155 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_3, MSGBOX_NPC
# 157 "data/maps/HavenTown/scripts.pory"
	delay 30
# 158 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_4, MSGBOX_NPC
# 163 "data/maps/HavenTown/scripts.pory"
	delay 30
# 164 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StartMyrtleScene_Text_5, MSGBOX_NPC
# 166 "data/maps/HavenTown/scripts.pory"
	release
	end


HavenTown_ProfMyrtle::
# 171 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_eq HavenTown_ProfMyrtle_2
# 174 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleAfterEscort, MSGBOX_NPC
HavenTown_ProfMyrtle_1:
	end

HavenTown_ProfMyrtle_2:
# 172 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleRepeatInstruction, MSGBOX_NPC
	goto HavenTown_ProfMyrtle_1


HavenTown_Grunt1::
# 180 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_Grunt2::
# 185 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntGoAway, MSGBOX_NPC
	end


HavenTown_TreeckoBall::
# 190 "data/maps/HavenTown/scripts.pory"
	lock
# 191 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 0
# 192 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_TREECKO
# 193 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_MudkipBall::
# 197 "data/maps/HavenTown/scripts.pory"
	lock
# 198 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 1
# 199 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_MUDKIP
# 200 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_CharmanderBall::
# 204 "data/maps/HavenTown/scripts.pory"
	lock
# 205 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_2, 2
# 206 "data/maps/HavenTown/scripts.pory"
	setvar VAR_TEMP_3, SPECIES_CHARMANDER
# 207 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_ConfirmStarterChoice
	return


HavenTown_EventScript_ConfirmStarterChoice::
# 211 "data/maps/HavenTown/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 1
	goto_if_ne HavenTown_EventScript_ConfirmStarterChoice_2
# 216 "data/maps/HavenTown/scripts.pory"
	showmonpic VAR_TEMP_3, 10, 3
# 217 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ChooseStarterConfirm, MSGBOX_YESNO
# 218 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_ConfirmStarterChoice_5
HavenTown_EventScript_ConfirmStarterChoice_4:
# 222 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 223 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_2:
# 212 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_EventScript_ConfirmStarterChoice_5:
# 219 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterChosen
	goto HavenTown_EventScript_ConfirmStarterChoice_4


HavenTown_EventScript_StarterChosen::
# 228 "data/maps/HavenTown/scripts.pory"
	hidemonpic
# 229 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 230 "data/maps/HavenTown/scripts.pory"
	givemon VAR_TEMP_3, 5
# 231 "data/maps/HavenTown/scripts.pory"
	copyvar VAR_STARTER_MON, VAR_TEMP_2
# 232 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 233 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterChosen_Text_0, MSGBOX_NPC
# 234 "data/maps/HavenTown/scripts.pory"
	goto HavenTown_EventScript_StarterBattle
	return


HavenTown_EventScript_StarterBattle::
# 238 "data/maps/HavenTown/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ASHEN_GRUNT_HAVEN, HavenTown_Text_GruntBattleStart, HavenTown_Text_GruntBattleDefeat, HavenTown_EventScript_StarterBattleAfterBattle
	end


HavenTown_EventScript_StarterBattleAfterBattle::
# 243 "data/maps/HavenTown/scripts.pory"
	call HavenTown_EventScript_HideStarterBalls
# 244 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GruntsRetreat, MSGBOX_NPC
# 245 "data/maps/HavenTown/scripts.pory"
	closemessage
# 246 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_1, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 247 "data/maps/HavenTown/scripts.pory"
	applymovement LOCALID_GRUNT_2, HavenTown_EventScript_StarterBattleAfterBattle_Movement_0
# 248 "data/maps/HavenTown/scripts.pory"
	fadeoutbgm 4
# 249 "data/maps/HavenTown/scripts.pory"
	waitmovement 0
# 250 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 251 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 252 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_1
# 253 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_GRUNT_2
# 254 "data/maps/HavenTown/scripts.pory"
	playbgm MUS_PALLET, TRUE
# 255 "data/maps/HavenTown/scripts.pory"
	fadeinbgm 0
# 256 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleThanks, MSGBOX_NPC
# 257 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtlePresentation, MSGBOX_NPC
# 258 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_0
# 260 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 261 "data/maps/HavenTown/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESMAYBE, 1, TRUE
# 262 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_MyrtleComeWithMe, MSGBOX_NPC
# 263 "data/maps/HavenTown/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_3
# 264 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_1, MSGBOX_NPC
# 269 "data/maps/HavenTown/scripts.pory"
	message HavenTown_Text_ReceivedStarter
# 270 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 271 "data/maps/HavenTown/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 272 "data/maps/HavenTown/scripts.pory"
	waitfanfare
# 273 "data/maps/HavenTown/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 274 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HavenTown_EventScript_StarterBattleAfterBattle_2
HavenTown_EventScript_StarterBattleAfterBattle_1:
# 278 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_2, MSGBOX_NPC
# 284 "data/maps/HavenTown/scripts.pory"
	delay 30
# 285 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_EventScript_StarterBattleAfterBattle_Text_3, MSGBOX_NPC
# 287 "data/maps/HavenTown/scripts.pory"
	setvar VAR_MAP_SCENE_HAVEN_TOWN, 2
# 288 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
# 289 "data/maps/HavenTown/scripts.pory"
	warp MAP_CEDRIC_HOUSE, 5, 10
# 290 "data/maps/HavenTown/scripts.pory"
	waitstate
# 291 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_StarterBattleAfterBattle_2:
# 275 "data/maps/HavenTown/scripts.pory"
	setvar VAR_0x8004, 0
# 276 "data/maps/HavenTown/scripts.pory"
	call EventScript_ChangePokemonNickname
	goto HavenTown_EventScript_StarterBattleAfterBattle_1


HavenTown_EventScript_GreetFromWoman::
# 296 "data/maps/HavenTown/scripts.pory"
	lockall
# 297 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_GreetFromWoman
# 298 "data/maps/HavenTown/scripts.pory"
	waitmessage
# 299 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice1, 0
# 300 "data/maps/HavenTown/scripts.pory"
	dynmultipush HavenTown_Text_GreetFromWomanChoice2, 1
# 301 "data/maps/HavenTown/scripts.pory"
	dynmultistack 20, 8, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 302 "data/maps/HavenTown/scripts.pory"
	switch VAR_RESULT
# 303 "data/maps/HavenTown/scripts.pory"
	case 0, HavenTown_EventScript_GreetFromWoman_3
# 305 "data/maps/HavenTown/scripts.pory"
	case 1, HavenTown_EventScript_GreetFromWoman_4
# 306 "data/maps/HavenTown/scripts.pory"
	case MULTI_B_PRESSED, HavenTown_EventScript_GreetFromWoman_4
HavenTown_EventScript_GreetFromWoman_1:
# 309 "data/maps/HavenTown/scripts.pory"
	releaseall
	end

HavenTown_EventScript_GreetFromWoman_3:
# 304 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice1, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1

HavenTown_EventScript_GreetFromWoman_4:
# 307 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_ResponseToGreetFromWomanChoice2, MSGBOX_NPC
	goto HavenTown_EventScript_GreetFromWoman_1


HavenTown_EventScript_HideStarterBalls::
# 314 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_TREECKO_BALL
# 315 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_MUDKIP_BALL
# 316 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_HIDE_HAVEN_TOWN_CHARMANDER_BALL
# 317 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_TREECKO_BALL
# 318 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_MUDKIP_BALL
# 319 "data/maps/HavenTown/scripts.pory"
	removeobject LOCALID_HAVEN_CHARMANDER_BALL
	return


HavenTown_PotionItem::
# 324 "data/maps/HavenTown/scripts.pory"
	lock
# 325 "data/maps/HavenTown/scripts.pory"
	goto_if_set FLAG_GOT_HAVENTOWN_POTION, HavenTown_PotionItem_2
# 331 "data/maps/HavenTown/scripts.pory"
	finditem ITEM_POTION
# 332 "data/maps/HavenTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HavenTown_PotionItem_5
# 337 "data/maps/HavenTown/scripts.pory"
	setflag FLAG_GOT_HAVENTOWN_POTION
# 338 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_2:
# 326 "data/maps/HavenTown/scripts.pory"
	msgbox HavenTown_Text_PotionItemGone, MSGBOX_NPC
# 327 "data/maps/HavenTown/scripts.pory"
	release
	end

HavenTown_PotionItem_5:
# 333 "data/maps/HavenTown/scripts.pory"
	release
	end


# 342 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromPark:
# 343 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 346 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromTownExit:
# 347 "data/maps/HavenTown/scripts.pory"
	walk_left
	step_end

# 350 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_PlayerStepBackFromGrunts:
# 351 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

# 354 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleWalkNorth:
# 355 "data/maps/HavenTown/scripts.pory"
	walk_up
# 355 "data/maps/HavenTown/scripts.pory"
	walk_up
# 355 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 358 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_MyrtleGetsShoved:
# 359 "data/maps/HavenTown/scripts.pory"
	walk_up
# 360 "data/maps/HavenTown/scripts.pory"
	face_down
# 361 "data/maps/HavenTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 364 "data/maps/HavenTown/scripts.pory"
HavenTown_Movement_GruntsWalkNorth:
# 365 "data/maps/HavenTown/scripts.pory"
	walk_up
# 365 "data/maps/HavenTown/scripts.pory"
	walk_up
# 365 "data/maps/HavenTown/scripts.pory"
	walk_up
	step_end

# 132 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StartMyrtleScene_Movement_0:
# 132 "data/maps/HavenTown/scripts.pory"
	face_down
	step_end

# 246 "data/maps/HavenTown/scripts.pory"
HavenTown_EventScript_StarterBattleAfterBattle_Movement_0:
# 246 "data/maps/HavenTown/scripts.pory"
	walk_down
# 246 "data/maps/HavenTown/scripts.pory"
	walk_down
# 246 "data/maps/HavenTown/scripts.pory"
	walk_down
# 246 "data/maps/HavenTown/scripts.pory"
	walk_down
# 246 "data/maps/HavenTown/scripts.pory"
	walk_down
	step_end

HavenTown_MrRupertPark_Text_0:
# 111 "data/maps/HavenTown/scripts.pory"
	.string "You gave the letter to Mr. Rupert.$"

HavenTown_EventScript_StartMyrtleScene_Text_0:
# 131 "data/maps/HavenTown/scripts.pory"
	.string "Professor: Oh! Excuse me.$"

HavenTown_EventScript_StartMyrtleScene_Text_1:
# 135 "data/maps/HavenTown/scripts.pory"
	.string "Can you point me to Haven Town?$"

HavenTown_EventScript_StartMyrtleScene_Text_2:
# 146 "data/maps/HavenTown/scripts.pory"
	.string "Hey! Get off me!$"

HavenTown_EventScript_StartMyrtleScene_Text_3:
# 155 "data/maps/HavenTown/scripts.pory"
	.string "The professor dropped some\n"
	.string "pokeballs!$"

HavenTown_EventScript_StartMyrtleScene_Text_4:
# 158 "data/maps/HavenTown/scripts.pory"
	.string "Ashen Grunt: Now, now,\n"
	.string "professor!\p"
	.string "Just hand over your pokeballs\n"
	.string "and nobody gets hurt.$"

HavenTown_EventScript_StartMyrtleScene_Text_5:
# 164 "data/maps/HavenTown/scripts.pory"
	.string "Use one of the pokeballs\n"
	.string "to help her!$"

HavenTown_EventScript_StarterChosen_Text_0:
# 233 "data/maps/HavenTown/scripts.pory"
	.string "You pick up {STR_VAR_1}'s\n"
	.string "pokeball!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_0:
# 258 "data/maps/HavenTown/scripts.pory"
	.string "Do you know a kid by the name\n"
	.string "{RIVAL2}?$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_1:
# 264 "data/maps/HavenTown/scripts.pory"
	.string "You don't need to give me\n"
	.string "{STR_VAR_1} back,\l"
	.string "it's your partner now.\p"
	.string "I can see he already trusts you!$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_2:
# 278 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Take good care of\n"
	.string "{STR_VAR_1}!\p"
	.string "You can help your POKéMON grow\n"
	.string "stronger by battling with it.$"

HavenTown_EventScript_StarterBattleAfterBattle_Text_3:
# 285 "data/maps/HavenTown/scripts.pory"
	.string "Prof. Myrtle: Now, let's go\n"
	.string "to your friend's house!$"
