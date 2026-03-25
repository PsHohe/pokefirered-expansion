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

HavenTown_Orphanage_2F_Thomas::
	lock
	faceplayer
	random 6
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, HavenTown_Orphanage_2F_ThomasFact1
	call_if_eq VAR_0x8008, 1, HavenTown_Orphanage_2F_ThomasFact2
	call_if_eq VAR_0x8008, 2, HavenTown_Orphanage_2F_ThomasFact3
	call_if_eq VAR_0x8008, 3, HavenTown_Orphanage_2F_ThomasFact4
	call_if_eq VAR_0x8008, 4, HavenTown_Orphanage_2F_ThomasFact5
	call_if_eq VAR_0x8008, 5, HavenTown_Orphanage_2F_ThomasFact6
	release
	end

HavenTown_Orphanage_2F_ThomasFact1::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact1, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact2::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact2, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact3::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact3, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact4::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact4, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact5::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact5, MSGBOX_NPC
	return

HavenTown_Orphanage_2F_ThomasFact6::
	msgbox HavenTown_Orphanage_2F_Text_ThomasFact6, MSGBOX_NPC
	return
