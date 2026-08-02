TimeShrine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TimeShrine_OnTransition
	.byte 0

TimeShrine_OnTransition:
	setflag FLAG_LANDMARK_TIME_SHRINE
	end

TimeShrine_EventScript_WardenAlec::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ADAMANT_CRYSTAL, TimeShrine_EventScript_AlreadyGiven
	msgbox TimeShrine_Text_WardenAlecIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WARDEN_ALEC, TimeShrine_Text_WardenAlecDefeat
	msgbox TimeShrine_Text_WardenAlecReward, MSGBOX_DEFAULT
	giveitem ITEM_ADAMANT_CRYSTAL
	setflag FLAG_RECEIVED_ADAMANT_CRYSTAL
	release
	end

TimeShrine_EventScript_AlreadyGiven::
	msgbox TimeShrine_Text_WardenAlecPost, MSGBOX_DEFAULT
	release
	end

TimeShrine_Text_WardenAlecIntro:
	.string "WARDEN ALEC: I have guarded the\n"
	.string "essence of time for countless ages.\p"
	.string "The ancient ones entrusted me with\n"
	.string "the ADAMANT CRYSTAL.\p"
	.string "You seek it. Then prove your\n"
	.string "strength against me!$"

TimeShrine_Text_WardenAlecDefeat:
	.string "WARDEN ALEC: Your strength... it bends\n"
	.string "time itself. The crystal is yours.$"

TimeShrine_Text_WardenAlecReward:
	.string "WARDEN ALEC: Take the ADAMANT\n"
	.string "CRYSTAL. It resonates with Dialga,\l"
	.string "the being of time.\p"
	.string "Channel its power wisely.$"

TimeShrine_Text_WardenAlecPost:
	.string "WARDEN ALEC: The crystal has found\n"
	.string "its rightful bearer. I am at peace.$"
