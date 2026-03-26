TestingGrounds_MapScripts::
	.byte 0

TestingGrounds_EventScript_TmRevendor::
	lock
	faceplayer
	message Text_TmsRevendor
	waitmessage
	special OpenTMRevendorShop
	waitstate
	msgbox Text_PleaseComeAgain
	release
	end

TestingGrounds_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM35_FROM_PALLET_FAT_MAN, TestingGrounds_EventScript_FatManAlreadyGaveTM
	msgbox TestingGrounds_Text_FatManTakeThisTM
	checkitemspace ITEM_TM35
	goto_if_eq VAR_RESULT, FALSE, TestingGrounds_EventScript_FatManNoRoomForTM
	giveitem_msg TestingGrounds_Text_ReceivedTM35FromFatMan, ITEM_TM35
	setflag FLAG_GOT_TM35_FROM_PALLET_FAT_MAN
	msgbox TestingGrounds_Text_FatManExplainsTM
	release
	end

TestingGrounds_EventScript_FatManNoRoomForTM::
    msgbox TestingGrounds_Text_FatManNoRoomForTM
	release
	end

TestingGrounds_EventScript_FatManAlreadyGaveTM::
    msgbox TestingGrounds_Text_FatManAlreadyGaveTM
	release
	end

TestingGround_EventScript_ToTheOrphanage::
	warp MAP_HAVEN_TOWN_ORPHANAGE, 8, 11
	waitstate
	end

TestingGrounds_EventScript_DebugTraversalUnlocks::
	lock
	faceplayer
	setflag FLAG_SYS_B_DASH
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_GOT_BIKE_VOUCHER
	setflag FLAG_GOT_BICYCLE
	setflag FLAG_GOT_OLD_ROD
	setflag FLAG_GOT_HM01
	setflag FLAG_GOT_HM02
	setflag FLAG_GOT_HM03
	setflag FLAG_GOT_HM04
	setflag FLAG_GOT_HM05
	setflag FLAG_GOT_HM06
	additem ITEM_BICYCLE
	additem ITEM_OLD_ROD
	additem ITEM_HM01
	additem ITEM_HM02
	additem ITEM_HM03
	additem ITEM_HM04
	additem ITEM_HM05
	additem ITEM_HM06
	additem ITEM_HM07
	additem ITEM_HM08
	msgbox TestingGrounds_Text_DebugTraversalUnlocksGranted
	release
	end
