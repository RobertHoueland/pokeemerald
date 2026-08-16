PrismChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PrismChamber_OnTransition
	.byte 0

PrismChamber_OnTransition:
	setflag FLAG_LANDMARK_PRISM_CHAMBER
	end

PrismChamber_EventScript_Rohde::
	lock
	faceplayer
	checkspecies SPECIES_SOLGALEO_V
	goto_if_eq VAR_RESULT, TRUE, PrismChamber_EventScript_HasSolgaleo
	checkspecies SPECIES_LUNALA_V
	goto_if_eq VAR_RESULT, TRUE, PrismChamber_EventScript_HasLunala
	msgbox PrismChamber_Text_RohdeDefault, MSGBOX_DEFAULT
	release
	end

PrismChamber_EventScript_HasSolgaleo::
	goto_if_set FLAG_RECEIVED_SOLARIZER, PrismChamber_EventScript_SolarizerAlreadyGiven
	msgbox PrismChamber_Text_RohdeSolgaleo, MSGBOX_DEFAULT
	giveitem ITEM_N_SOLARIZER
	setflag FLAG_RECEIVED_SOLARIZER
	release
	end

PrismChamber_EventScript_SolarizerAlreadyGiven::
	msgbox PrismChamber_Text_RohdeSolarizerAlreadyGiven, MSGBOX_DEFAULT
	release
	end

PrismChamber_EventScript_HasLunala::
	goto_if_set FLAG_RECEIVED_LUNARIZER, PrismChamber_EventScript_LunarizerAlreadyGiven
	msgbox PrismChamber_Text_RohdeLunala, MSGBOX_DEFAULT
	giveitem ITEM_N_LUNARIZER
	setflag FLAG_RECEIVED_LUNARIZER
	release
	end

PrismChamber_EventScript_LunarizerAlreadyGiven::
	msgbox PrismChamber_Text_RohdeLunarizerAlreadyGiven, MSGBOX_DEFAULT
	release
	end

PrismChamber_Text_RohdeDefault:
	.string "ROHDE: I guard the prism lenses that\n"
	.string "bind light and shadow.\p"
	.string "The lens of the sun and the lens of the\n"
	.string "moon can only be forged when their\l"
	.string "guardians walk beside a willing host.$"

PrismChamber_Text_RohdeSolgaleo:
	.string "ROHDE: Ah, SOLGALEO-V, the sun beast!\n"
	.string "Its radiance is blinding…\p"
	.string "Take the N-SOLARIZER. It will let\n"
	.string "NECROZMA merge with the light of\l"
	.string "the sun.$"

PrismChamber_Text_RohdeSolarizerAlreadyGiven:
	.string "ROHDE: The prism lens for the sun\n"
	.string "beast is already yours.$"

PrismChamber_Text_RohdeLunala:
	.string "ROHDE: Ah, LUNALA-V, the moon beast!\n"
	.string "Its glow is hauntingly beautiful…\p"
	.string "Take the N-LUNARIZER. It will let\n"
	.string "NECROZMA merge with the light of\l"
	.string "the moon.$"

PrismChamber_Text_RohdeLunarizerAlreadyGiven:
	.string "ROHDE: The prism lens for the moon\n"
	.string "beast is already yours.$"

