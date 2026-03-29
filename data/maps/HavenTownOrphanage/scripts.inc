HavenTownOrphanage_MapScripts::
	.byte 0


HavenTown_Orphanage_Mailbox::
# 5 "data/maps/HavenTownOrphanage/scripts.pory"
	msgbox HavenTown_Orphanage_Mailbox_Text_0, MSGBOX_SIGN
	end


HavenTown_Orphanage_Zigzagoon::
# 12 "data/maps/HavenTownOrphanage/scripts.pory"
	lock
# 13 "data/maps/HavenTownOrphanage/scripts.pory"
	faceplayer
# 14 "data/maps/HavenTownOrphanage/scripts.pory"
	waitse
# 15 "data/maps/HavenTownOrphanage/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
# 16 "data/maps/HavenTownOrphanage/scripts.pory"
	msgbox HavenTown_Orphanage_Zigzagoon_Text_0, MSGBOX_NPC
# 17 "data/maps/HavenTownOrphanage/scripts.pory"
	waitmoncry
# 18 "data/maps/HavenTownOrphanage/scripts.pory"
	release
	end


HavenTown_Orphanage_Iris::
# 23 "data/maps/HavenTownOrphanage/scripts.pory"
	weightedmsgbox MSGBOX_NPC, HavenTown_Orphanage_Text_IrisCommon, HavenTown_Orphanage_Text_IrisMid, HavenTown_Orphanage_Text_IrisRare
	end


HavenTown_Orphanage_Teo::
# 31 "data/maps/HavenTownOrphanage/scripts.pory"
	weightedmsgbox MSGBOX_NPC, HavenTown_Orphanage_Text_TeoCommon, HavenTown_Orphanage_Text_TeoMid, HavenTown_Orphanage_Text_TeoRare
	end


HavenTown_Orphanage_Mailbox_Text_0:
# 5 "data/maps/HavenTownOrphanage/scripts.pory"
	.string "HAVEN TOWN'S ORPHANAGE\n"
	.string "Run by Mrs. Marina$"

HavenTown_Orphanage_Zigzagoon_Text_0:
# 16 "data/maps/HavenTownOrphanage/scripts.pory"
	.string "Kee-kiiiiii!$"
