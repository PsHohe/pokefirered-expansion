TestingGrounds_MapScripts::
	.byte 0

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
