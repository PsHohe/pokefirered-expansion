HavenTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HavenTown_OnTransition
	.byte 0

HavenTown_OnTransition::
	setflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, HavenTown_OnTransition_End
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_OnTransition_End
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED, HavenTown_OnTransition_End
	clearflag FLAG_ORPHANAGE_ENVELOPE_HIDE_PARK_RUPERT
HavenTown_OnTransition_End::
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

HavenTown_MrRupertPark::
	msgbox HavenTown_Text_MrRupertPark, MSGBOX_NPC
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, HavenTown_MrRupertPark_End
	removeitem ITEM_LETTER
	setflag FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED
HavenTown_MrRupertPark_End::
	end

HavenTown_Movement_PlayerStepBackFromPark::
	walk_left
	step_end

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
