ShadyForest_MapScripts::
	.byte 0

ShadyForest_EntranceSign::
	msgbox ShadyForest_Text_EntranceSign, MSGBOX_SIGN
	end

ShadyForest_BarrelSign::
	msgbox ShadyForest_Text_BarrelSign, MSGBOX_SIGN
	end

ShadyForest_WhirlpoolBarrel::
	msgbox ShadyForest_Text_WhirlpoolBarrelPrompt, MSGBOX_SIGN
	msgbox ShadyForest_Text_WhirlpoolJumpIn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ShadyForest_WhirlpoolBarrel_Enter
	closemessage
	end

ShadyForest_WhirlpoolBarrel_Enter:
	msgbox ShadyForest_Text_WhirlpoolBarrelEnter, MSGBOX_DEFAULT
	warp MAP_ROUTE129, 68, 18
	waitstate
	end

ShadyForest_Text_EntranceSign:
	.string "RESEARCH STATION ZERO\n"
	.string "! Restricted Area !\p"
	.string "Beyond this point, all records end.\p"
	.string "Proceed with caution.$"
	
ShadyForest_Text_BarrelSign:
	.string "These barrels are for research\n"
	.string "purposes only.\p"
	.string "Do not go near them unless\n"
	.string "you are a researcher.$"

ShadyForest_Text_WhirlpoolBarrelPrompt:
	.string "A wooden barrel is wedged in place.\p"
	.string "You can hear a pool of water\n"
	.string "churning at the bottom.$"

ShadyForest_Text_WhirlpoolJumpIn:
	.string "Jump in?$"

ShadyForest_Text_WhirlpoolBarrelEnter:
	.string "The current grabs you and pulls you in!$"
	
