SealedChamber_InnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_InnerRoom_OnTransition
	.byte 0

SealedChamber_InnerRoom_OnTransition:
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_InnerRoom_EventScript_BrailleBackWall::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
	specialvar VAR_RESULT, CheckRelicanthWailord
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect::
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	releaseall
	end

SealedChamber_InnerRoom_EventScript_Historian::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0

	call_if_set FLAG_RECEIVED_ADAMANT_CRYSTAL, SealedChamber_InnerRoom_EventScript_CountEssence
	call_if_set FLAG_RECEIVED_LUSTROUS_GLOBE, SealedChamber_InnerRoom_EventScript_CountEssence
	call_if_set FLAG_RECEIVED_GRISEOUS_ORB, SealedChamber_InnerRoom_EventScript_CountEssence
	
	goto_if_eq VAR_TEMP_1, 3, SealedChamber_InnerRoom_EventScript_HistorianAllDone
	goto_if_ge VAR_TEMP_1, 1, SealedChamber_InnerRoom_EventScript_HistorianRemind
	goto_if_set FLAG_TALKED_TO_HISTORIAN, SealedChamber_InnerRoom_EventScript_HistorianRemind

	msgbox SealedChamber_InnerRoom_Text_HistorianIntro, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_HISTORIAN
	release
	end

SealedChamber_InnerRoom_EventScript_CountEssence::
	addvar VAR_TEMP_1, 1
	return

SealedChamber_InnerRoom_EventScript_HistorianRemind::
	msgbox SealedChamber_InnerRoom_Text_HistorianRemind, MSGBOX_DEFAULT
	release
	end

SealedChamber_InnerRoom_EventScript_HistorianAllDone::
	msgbox SealedChamber_InnerRoom_Text_HistorianAllDone, MSGBOX_DEFAULT
	release
	end

SealedChamber_InnerRoom_Text_HistorianIntro:
	.string "Ah, a visitor... I am ELDRIC THORNE,\n"
	.string "last keeper of the ORDER OF THE\l"
	.string "GENESIS STONE.\p"
	.string "These walls tell more than the\n"
	.string "tale of the sealed titans.\p"
	.string "Long before the REGIS were locked\n"
	.string "away, this chamber bore witness to\l"
	.string "beings of far greater power.\p"
	.string "DIALGA, who commands time.\n"
	.string "PALKIA, who governs space.\l"
	.string "GIRATINA, who rules the world beyond.\p"
	.string "The ancients forged three crystallized\n"
	.string "essences to channel their might-\l"
	.string "The ADAMANT CRYSTAL,\l"
	.string "the LUSTROUS GLOBE,\l"
	.string "and the GRISEOUS ORB.\p"
	.string "They sealed them in three hidden\n"
	.string "shrines, guarded by chosen wardens.\p"
	.string "I have spent my life deciphering\n"
	.string "the clues to their locations.\p"
	.string "The TIME SHRINE lies near the desert\n"
	.string "ruins on ROUTE 111.\p"
	.string "The SPACE SHRINE is hidden in the\n"
	.string "waters of ROUTE 105.\p"
	.string "The DISTORTION SHRINE rests near\n"
	.string "the ancient tomb on ROUTE 120.\p"
	.string "I am too old for such journeys.\n"
	.string "But you... you have the strength.\p"
	.string "Seek the shrines. Defeat the wardens.\n"
	.string "Claim the essences. The world's balance\l"
	.string "may one day depend on them.$"

SealedChamber_InnerRoom_Text_HistorianRemind:
	.string "ELDRIC: Have you found the shrines yet?\n"
	.string "The TIME SHRINE on ROUTE 111,\l"
	.string "the SPACE SHRINE on ROUTE 105,\l"
	.string "and the DISTORTION SHRINE on\l"
	.string "ROUTE 120.\p"
	.string "The wardens are powerful. Come\n"
	.string "prepared.$"

SealedChamber_InnerRoom_Text_HistorianAllDone:
	.string "ELDRIC: You have recovered all three\n"
	.string "crystallized essences!\p"
	.string "DIALGA, PALKIA, and GIRATINA--\n"
	.string "their power can now be harnessed.\p"
	.string "The ancient order would be proud.\n"
	.string "You carry the legacy of the genesis.$"

