OldManHouse_MapScripts::
# 2 "data/maps/OldManHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldManHouse_Orphanage_1F_OnTransition
	.byte 0


OldManHouse_Orphanage_1F_OnTransition::
# 6 "data/maps/OldManHouse/scripts.pory"
	compare VAR_MAP_SCENE_HAVEN_TOWN, 4
	goto_if_ge OldManHouse_Orphanage_1F_OnTransition_2
# 11 "data/maps/OldManHouse/scripts.pory"
	clearflag FLAG_TEMP_D
# 12 "data/maps/OldManHouse/scripts.pory"
	removeobject LOCALID_MR_RUPERT
	end

	end

OldManHouse_Orphanage_1F_OnTransition_2:
# 7 "data/maps/OldManHouse/scripts.pory"
	setflag FLAG_TEMP_D
# 8 "data/maps/OldManHouse/scripts.pory"
	addobject LOCALID_MR_RUPERT
	end


OldManHouse_MrRupert::
# 19 "data/maps/OldManHouse/scripts.pory"
	msgbox OldManHouse_MrRupert_Text_0, MSGBOX_NPC
	end


OldManHouse_MrRupertWife::
# 26 "data/maps/OldManHouse/scripts.pory"
	goto_if_unset FLAG_ORPHANAGE_ENVELOPE_QUEST_STARTED, OldManHouse_MrRupertWife_2
# 33 "data/maps/OldManHouse/scripts.pory"
	goto_if_set FLAG_ORPHANAGE_ENVELOPE_QUEST_FINISHED, OldManHouse_MrRupertWife_5
# 42 "data/maps/OldManHouse/scripts.pory"
	setflag FLAG_ORPHANAGE_ENVELOPE_WIFE_TALKED
# 43 "data/maps/OldManHouse/scripts.pory"
	msgbox OldManHouse_MrRupertWife_Text_2, MSGBOX_NPC
	end

OldManHouse_MrRupertWife_2:
# 27 "data/maps/OldManHouse/scripts.pory"
	msgbox OldManHouse_MrRupertWife_Text_0, MSGBOX_NPC
	end

OldManHouse_MrRupertWife_5:
# 34 "data/maps/OldManHouse/scripts.pory"
	msgbox OldManHouse_MrRupertWife_Text_1, MSGBOX_NPC
	end


OldManHouse_MrRupert_Text_0:
# 19 "data/maps/OldManHouse/scripts.pory"
	.string "Mr. Rupert: I love the park,\n"
	.string "but sometimes my knees hurt.$"

OldManHouse_MrRupertWife_Text_0:
# 27 "data/maps/OldManHouse/scripts.pory"
	.string "My husband takes little walks\n"
	.string "to clear his head.$"

OldManHouse_MrRupertWife_Text_1:
# 34 "data/maps/OldManHouse/scripts.pory"
	.string "Rupert mentioned meeting you in\n"
	.string "the park.\p"
	.string "He seemed thoughtful$"

OldManHouse_MrRupertWife_Text_2:
# 43 "data/maps/OldManHouse/scripts.pory"
	.string "Oh, you're looking for my\n"
	.string "husband?\p"
	.string "He went for a walk in the PARK\n"
	.string "to the east.$"
