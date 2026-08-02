DistortionShrine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DistortionShrine_OnTransition
	.byte 0

DistortionShrine_OnTransition:
	setflag FLAG_LANDMARK_DISTORTION_SHRINE
	end

DistortionShrine_EventScript_SirBilliam::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GRISEOUS_ORB, DistortionShrine_EventScript_AlreadyGiven
	msgbox DistortionShrine_Text_SirBilliamIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIR_BILLIAM, DistortionShrine_Text_SirBilliamDefeat
	msgbox DistortionShrine_Text_SirBilliamReward, MSGBOX_DEFAULT
	giveitem ITEM_GRISEOUS_ORB
	setflag FLAG_RECEIVED_GRISEOUS_ORB
	release
	end

DistortionShrine_EventScript_AlreadyGiven::
	msgbox DistortionShrine_Text_SirBilliamPost, MSGBOX_DEFAULT
	release
	end

DistortionShrine_Text_SirBilliamIntro:
	.string "SIR BILLIAM: You have found your\n"
	.string "way into the distorted realm...\p"
	.string "I guard the GRISEOUS ORB, the\n"
	.string "key to the world unseen.\p"
	.string "If you wish to claim it, face\n"
	.string "the darkness within me!$"

DistortionShrine_Text_SirBilliamDefeat:
	.string "BILLIAM: The shadows bow to you.\n"
	.string "You have conquered the distortion.$"

DistortionShrine_Text_SirBilliamReward:
	.string "SIR BILLIAM: The GRISEOUS ORB is\n"
	.string "yours. It channels the might of\l"
	.string "Giratina, the being of antimatter.\p"
	.string "Use it wisely.$"

DistortionShrine_Text_SirBilliamPost:
	.string "SIR BILLIAM: The orb has passed\n"
	.string "through the veil to you.$"
