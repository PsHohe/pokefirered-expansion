HavenTownOrphanage_MapScripts::
	.byte 0

HavenTown_Orphanage_Mailbox::
    msgbox HavenTown_Orphanage_Text_Mailbox, MSGBOX_SIGN
	end

HavenTown_Orphanage_Zigzagoon::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
    msgbox HavenTown_Orphanage_Text_Zigzagoon
    waitmoncry
    release
    end

HavenTown_Orphanage_Iris::
	weightedmsgbox MSGBOX_NPC, HavenTown_Orphanage_Text_IrisCommon, HavenTown_Orphanage_Text_IrisMid, HavenTown_Orphanage_Text_IrisRare
	end

HavenTown_Orphanage_Teo::
	weightedmsgbox MSGBOX_NPC, HavenTown_Orphanage_Text_TeoCommon, HavenTown_Orphanage_Text_TeoMid, HavenTown_Orphanage_Text_TeoRare
	end
