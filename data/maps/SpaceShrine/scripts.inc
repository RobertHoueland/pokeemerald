SpaceShrine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SpaceShrine_OnTransition
	.byte 0

SpaceShrine_OnTransition:
	setflag FLAG_LANDMARK_SPACE_SHRINE
	end

SpaceShrine_EventScript_MsMadeline::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LUSTROUS_GLOBE, SpaceShrine_EventScript_AlreadyGiven
	msgbox SpaceShrine_Text_MsMadelineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MS_MADELINE, SpaceShrine_Text_MsMadelineDefeat
	msgbox SpaceShrine_Text_MsMadelineReward, MSGBOX_DEFAULT
	giveitem ITEM_LUSTROUS_GLOBE
	setflag FLAG_RECEIVED_LUSTROUS_GLOBE
	release
	end

SpaceShrine_EventScript_AlreadyGiven::
	msgbox SpaceShrine_Text_MsMadelinePost, MSGBOX_DEFAULT
	release
	end

SpaceShrine_Text_MsMadelineIntro:
	.string "MS. MADELINE: I see you have\n"
	.string "navigated the currents of space.\p"
	.string "The LUSTROUS GLOBE rests with me.\n"
	.string "To claim it, you must defeat me!$"

SpaceShrine_Text_MsMadelineDefeat:
	.string "MADELINE: You pierced the fabric of\n"
	.string "space itself. Well fought.$"

SpaceShrine_Text_MsMadelineReward:
	.string "MS. MADELINE: The LUSTROUS GLOBE\n"
	.string "is yours. It holds the essence of\l"
	.string "Palkia's spatial power.\p"
	.string "May it serve you well.$"

SpaceShrine_Text_MsMadelinePost:
	.string "MS. MADELINE: The globe has crossed\n"
	.string "dimensions to reach you.$"
