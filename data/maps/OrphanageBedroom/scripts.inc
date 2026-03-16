OrphanageBedroom_MapScripts::
	.byte 0

Orphanage_PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, 1
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
	releaseall
	end

EventScript_Orphanage_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special AnimatePcTurnOff
	releaseall
	end

EventScript_Orphanage_PsyduckDoll::
	msgbox Orphanage_Text_PsyduckDoll, MSGBOX_SIGN
	end
