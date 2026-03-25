HavenTownOrphanage_MapScripts::
	.byte 0

HavenTown_Orphanage_Mailbox::
    msgbox HavenTown_Orphanage_Text_Mailbox, MSGBOX_SIGN
	end

HavenTown_Orphanage_Zigzagoon::
    msgbox HavenTown_Orphanage_Text_Zigzagoon
    end

HavenTown_Orphanage_Iris::
	weightedmsgbox MSGBOX_NPC, HavenTown_Orphanage_Text_IrisCommon, HavenTown_Orphanage_Text_IrisMid, HavenTown_Orphanage_Text_IrisRare
	end
