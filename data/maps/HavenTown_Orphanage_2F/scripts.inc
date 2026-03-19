HavenTown_Orphanage_2F_MapScripts::
	.byte 0

HavenTown_Orphanage_2F_Kangaskhan::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
    msgbox HavenTown_Orphanage_2F_Text_Kangaskhan
    waitmoncry
    release
    end

HavenTown_Orphanage_2F_ChoresSign::
    msgbox HavenTown_Orphanage_2F_Text_ChoresSign, MSGBOX_SIGN
    end
