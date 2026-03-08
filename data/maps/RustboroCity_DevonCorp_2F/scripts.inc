# 1 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 3 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 4 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 5 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 6 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 7 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 8 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 9 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 10 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 11 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 12 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 13 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 14 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 15 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 16 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 17 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 18 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 19 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 20 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 21 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 22 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 23 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 24 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 25 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 26 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 27 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 28 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 29 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 30 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 31 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 32 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 33 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 34 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 35 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 36 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 37 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 38 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 39 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 40 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 41 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 42 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 43 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 44 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 45 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 46 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 47 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 48 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 49 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 50 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 51 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 52 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 53 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 54 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 55 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 56 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 57 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 58 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 59 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 60 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 61 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 62 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 63 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 64 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 65 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
# 66 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 67 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
# 68 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 69 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 70 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 71 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ This whole section has needless duplication and could be condensed considerably
# 72 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
# 73 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 74 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 75 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 76 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 78 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 79 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 80 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 81 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 82 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 83 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 84 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 85 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 86 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
# 87 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 88 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 89 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 90 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 91 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 92 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 93 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 94 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 95 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
# 96 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 97 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 98 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 99 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 100 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 101 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 102 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 103 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 104 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 105 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 106 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 107 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 108 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 109 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
# 110 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 111 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 112 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 113 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 114 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 115 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 116 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 117 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 118 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
# 119 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 120 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 121 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 122 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 123 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
# 124 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 125 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 126 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 127 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 128 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 129 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
# 130 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
# 131 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 132 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 133 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_LileepReady::
# 134 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 135 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 136 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
# 137 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 138 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 139 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
# 140 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 141 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 142 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
# 143 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 144 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 145 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
# 146 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 147 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 148 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
# 149 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
# 150 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 151 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 152 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 153 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
# 154 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 155 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 156 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 157 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 158 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 159 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 160 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 161 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 162 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
# 163 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 164 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 165 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 166 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 167 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 168 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 169 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 170 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
# 171 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 172 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 173 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 174 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 175 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
# 176 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 177 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 178 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 179 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 180 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 181 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 182 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 183 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 184 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
# 185 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 186 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 187 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 188 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 189 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 190 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
# 191 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 192 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 193 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
# 194 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
# 195 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 196 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 197 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 198 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
# 199 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 200 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 201 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 202 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 203 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 204 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 205 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 206 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 207 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
# 208 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 209 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 210 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 211 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 212 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 213 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 214 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 215 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
# 216 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 217 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 218 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 219 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 220 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
# 221 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 222 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 223 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 224 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 225 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 226 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 227 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 228 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 229 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
# 230 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 231 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 232 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 233 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 234 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 235 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
# 236 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
# 237 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 238 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 17, 6, MULTI_FOSSIL, FALSE
# 239 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 240 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
# 241 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
# 242 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 243 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 244 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 245 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 246 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
# 247 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 248 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 249 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 250 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
# 251 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 252 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 253 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 254 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
# 255 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 256 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 257 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 258 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 259 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 260 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 261 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 262 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 263 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 264 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 265 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 266 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 267 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 268 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 269 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 270 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 271 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 272 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 273 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 274 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with POKéMON.\p"
# 275 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 276 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 277 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 278 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 279 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS…\p"
# 280 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I haven't made much headway…$"
# 281 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 282 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 283 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 284 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKé BALLS!\p"
# 285 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The REPEAT BALL makes it easier to\n"
# 286 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch POKéMON you've caught before.\p"
# 287 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The TIMER BALL gets better at catching\n"
# 288 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON the longer a battle runs.\p"
# 289 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 290 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON CORPORATION.\p"
# 291 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 292 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 293 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 294 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the POKéNAV!\p"
# 295 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 296 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 297 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 298 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 299 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 300 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a POKéNAV!\p"
# 301 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 302 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "PRESIDENT's desire to learn about\l"
# 303 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of POKéMON.\p"
# 304 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 305 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 306 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 307 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the POKéNAV out.$"
# 308 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 309 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 310 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 311 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 312 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "POKéMON…\p"
# 313 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 314 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 315 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
# 316 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 317 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects POKéMON from fossils…\p"
# 318 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 319 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 320 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
# 321 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 322 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a POKéMON fossil?\p"
# 323 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that POKéMON\n"
# 324 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 325 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 326 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "FOSSIL REGENERATOR.$"
# 327 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 328 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
# 329 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 330 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "DEVON's technological expertise\n"
# 331 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 332 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 333 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
# 334 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 335 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have not one, but two, fossils?\p"
# 336 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 337 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate one POKéMON at a time.\p"
# 338 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to pick one of your\n"
# 339 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "fossils for regeneration?$"
# 340 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 341 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
# 342 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 343 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 344 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 345 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 346 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 347 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
# 348 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The FOSSIL REGENERATOR, which I made,\n"
# 349 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 350 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 351 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 352 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 353 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 354 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 355 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
# 356 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 357 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized POKéMON has been\n"
# 358 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 359 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient POKéMON.\n"
# 360 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 361 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 362 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
# 363 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 364 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the DEVON RESEARCHER.$"
# 365 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 366 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 367 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 368 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many POKéMON.\n"
# 369 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 370 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 371 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 372 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 373 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the POKéNAV…\p"
# 374 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 375 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 376 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 377 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 378 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 379 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 380 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 381 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 382 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist::
# 386 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lockall
# 387 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_MINI_LEGENDARY_SCIENTIST, MiniLegendSci_Met
# 390 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_0
# 391 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 392 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_1
# 393 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_2
# 394 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_3
# 401 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_4
# 402 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_5
# 403 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_6
# 404 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_7
# 405 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_8
# 406 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_9
# 407 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_10
# 408 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_11
# 409 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_12
# 410 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_13
# 411 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_14
# 412 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_15
# 413 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_MET_MINI_LEGENDARY_SCIENTIST
# 414 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_FirstMet
# 416 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Met:
# 424 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_FirstMet:
# 425 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_16
# 427 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Region:
# 429 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_17
# 430 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_REGION, FALSE
# 431 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 432 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_REGION_CHOICES - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_2
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_1:
# 437 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_18
# 438 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 446 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case REGION_CHOICE_KANTO, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_6
# 476 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case REGION_CHOICE_JOHTO, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_7
# 506 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case REGION_CHOICE_HOENN, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_8
# 546 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case REGION_CHOICE_SINNOH, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_9
# 606 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case REGION_CHOICE_UNOVA, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_10
# 647 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Region
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_4:
# 651 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 652 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary
# 654 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_End:
# 655 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_19
# 656 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_RESULT, 0
# 657 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_2:
# 433 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_End
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_1

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_6:
# 447 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Kanto:
# 448 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KANTO, FALSE
# 449 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 451 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 452 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case KANTO_CHOICE_MEWTWO, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_14
# 462 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case KANTO_CHOICE_BIRDS, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_15
# 473 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Region
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_12:
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_4

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_7:
# 477 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Johto:
# 478 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_JOHTO, FALSE
# 479 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 481 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 482 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case JOHTO_CHOICE_BEASTS, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_19
# 492 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case JOHTO_CHOICE_TOWER, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_20
# 503 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Region
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_17:
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_4

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_8:
# 507 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Hoenn:
# 508 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_HOENN, FALSE
# 509 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 511 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 512 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case HOENN_CHOICE_REGIS, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_24
# 522 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case HOENN_CHOICE_EON, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_25
# 532 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case HOENN_CHOICE_WEATHER, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_26
# 543 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Region
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_22:
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_4

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_9:
# 547 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Sinnoh:
# 548 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SINNOH, FALSE
# 549 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 551 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 552 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case SINNOH_CHOICE_LAKE, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_30
# 562 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case SINNOH_CHOICE_MYTH, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_31
# 572 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case SINNOH_CHOICE_HEATRAN, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_32
# 582 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case SINNOH_CHOICE_REGIGIGAS, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_33
# 592 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case SINNOH_CHOICE_CRESSELIA, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_34
# 603 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Region
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_28:
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_4

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_10:
# 607 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
MiniLegendSci_Unova:
# 608 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_UNOVA, FALSE
# 609 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 611 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 612 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case UNOVA_CHOICE_SWORDS, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_38
# 622 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case UNOVA_CHOICE_FORCES, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_39
# 632 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case UNOVA_CHOICE_TAO, RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_40
# 643 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Region
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_36:
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_4

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_14:
# 453 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_MEWTWO_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 454 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_MEWTWO, FALSE
# 455 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 457 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_MEWTWO - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_43
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_42:
# 460 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MEWTWO
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_12

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_15:
# 463 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_BIRD_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 464 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_BIRDS, FALSE
# 465 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 467 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_BIRDS - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_46
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_45:
# 470 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_BIRDS
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_12

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_19:
# 483 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_BEASTS_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 484 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_BEASTS, FALSE
# 485 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 487 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_BEASTS - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_49
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_48:
# 490 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_BEASTS
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_17

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_20:
# 493 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TOWER_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 494 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TOWER, FALSE
# 495 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 497 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TOWER - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_52
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_51:
# 500 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TOWER
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_17

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_24:
# 513 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_REGI_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 514 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_REGI, FALSE
# 515 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 517 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_REGIS - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_55
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_54:
# 520 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_REGIS
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_22

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_25:
# 523 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_EON_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 524 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_EON, FALSE
# 525 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 527 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_EON - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_58
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_57:
# 530 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_EON
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_22

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_26:
# 533 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_WEATHER_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 534 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_WEATHER, FALSE
# 535 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 537 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_WEATHER - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_61
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_60:
# 540 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_WEATHER
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_22

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_30:
# 553 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_LAKE_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 554 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_LAKE, FALSE
# 555 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 557 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_LAKE - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_64
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_63:
# 560 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_LAKE
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_28

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_31:
# 563 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_MYTH_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 564 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_MYTH, FALSE
# 565 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 567 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_MYTH - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_67
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_66:
# 570 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MYTH
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_28

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_32:
# 573 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_HEATRAN_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 574 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_HEATRAN, FALSE
# 575 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 577 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_HEATRAN - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_70
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_69:
# 580 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_HEATRAN
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_28

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_33:
# 583 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_REGIGIGAS_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 584 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_REGIGIGAS, FALSE
# 585 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 587 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_REGIGIGAS - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_73
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_72:
# 590 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_REGIGIGAS
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_28

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_34:
# 593 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_CRESSELIA_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 594 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_CRESSELIA, FALSE
# 595 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 597 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_CRESSELIA - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_76
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_75:
# 600 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_CRESSELIA
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_28

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_38:
# 613 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_SWORDS_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 614 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SWORDS, FALSE
# 615 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 617 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_SWORDS - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_79
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_78:
# 620 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_SWORDS
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_36

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_39:
# 623 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_FORCES_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 624 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_FORCES, FALSE
# 625 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 627 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_FORCES - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_82
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_81:
# 630 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_FORCES
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_36

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_40:
# 633 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAO_LINE, RustboroCity_DevonCorp_2F_EventScript_HasMon
# 634 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAO, FALSE
# 635 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 637 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAO - 1
	goto_if_gt RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_85
RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_84:
# 640 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAO
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_36

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_43:
# 458 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Kanto
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_42

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_46:
# 468 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Kanto
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_45

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_49:
# 488 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Johto
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_48

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_52:
# 498 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Johto
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_51

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_55:
# 518 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Hoenn
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_54

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_58:
# 528 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Hoenn
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_57

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_61:
# 538 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Hoenn
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_60

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_64:
# 558 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Sinnoh
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_63

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_67:
# 568 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Sinnoh
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_66

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_70:
# 578 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Sinnoh
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_69

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_73:
# 588 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Sinnoh
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_72

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_76:
# 598 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Sinnoh
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_75

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_79:
# 618 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Unova
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_78

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_82:
# 628 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Unova
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_81

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_85:
# 638 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_Unova
	goto RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_84


RustboroCity_DevonCorp_2F_EventScript_HasMon::
# 661 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_HasMon_Text_0
# 662 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_HasMon_Text_1
# 663 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_HasMon_Text_2
# 664 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_RESULT, 0
# 665 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_2F_EventScript_GiveLegendary::
# 670 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_TEMP_1
# 676 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_3
# 684 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_4
# 692 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_5
# 700 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 3, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_6
# 708 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 4, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_7
# 716 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 5, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_8
# 724 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 6, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_9
# 732 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 7, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_10
# 740 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 8, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_11
# 748 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 9, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_12
# 756 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 10, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_13
# 764 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 11, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_14
# 772 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 12, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_15
# 780 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 13, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_16
# 788 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 14, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_17
# 796 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 15, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_18
# 804 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 16, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_19
# 812 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 17, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_20
# 820 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 18, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_21
# 828 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 19, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_22
# 836 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 20, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_23
# 844 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 21, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_24
# 852 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 22, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_25
# 860 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 23, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_26
# 868 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 24, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_27
# 876 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 25, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_28
# 884 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 26, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_29
# 892 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 27, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_30
# 900 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 28, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_31
# 908 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 29, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_32
# 916 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 30, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_33
# 924 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 31, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_34
# 932 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 32, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_35
# 940 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 33, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_36
# 948 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 34, RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_37
# 958 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto MiniLegendSci_End
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1:
# 961 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_40
# 972 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_41
# 984 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_39:
# 988 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_Text_1
# 989 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_RESULT, 0
# 990 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_3:
# 677 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MEWTWO_V
# 678 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEWTWO_V
# 679 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_MEWTWO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 680 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_46
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_45:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_4:
# 685 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO_V
# 686 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_V
# 687 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ARTICUNO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 688 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_49
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_48:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_5:
# 693 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS_V
# 694 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_V
# 695 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ZAPDOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 696 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_52
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_51:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_6:
# 701 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES_V
# 702 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_V
# 703 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_MOLTRES_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 704 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_55
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_54:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_7:
# 709 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAIKOU_V
# 710 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAIKOU_V
# 711 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_RAIKOU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 712 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_58
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_57:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_8:
# 717 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI_V
# 718 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENTEI_V
# 719 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ENTEI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 720 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_61
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_60:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_9:
# 725 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE_V
# 726 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SUICUNE_V
# 727 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_SUICUNE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 728 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_64
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_63:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_10:
# 733 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_V
# 734 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LUGIA_V
# 735 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LUGIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 736 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_67
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_66:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_11:
# 741 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH_V
# 742 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HO_OH_V
# 743 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_HO_OH_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 744 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_70
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_69:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_12:
# 749 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIROCK_V
# 750 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIROCK_V
# 751 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_REGIROCK_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 752 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_73
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_72:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_13:
# 757 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGICE_V
# 758 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGICE_V
# 759 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_REGICE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 760 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_76
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_75:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_14:
# 765 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGISTEEL_V
# 766 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGISTEEL_V
# 767 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_REGISTEEL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 768 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_79
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_78:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_15:
# 773 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIAS_V
# 774 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIAS_V
# 775 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LATIAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 776 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_82
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_81:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_16:
# 781 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIOS_V
# 782 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIOS_V
# 783 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LATIOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 784 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_85
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_84:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_17:
# 789 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYOGRE_V
# 790 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYOGRE_V
# 791 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_KYOGRE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 792 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_88
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_87:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_18:
# 797 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON_V
# 798 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GROUDON_V
# 799 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_GROUDON_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 800 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_91
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_90:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_19:
# 805 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAYQUAZA_V
# 806 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAYQUAZA_V
# 807 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_RAYQUAZA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 808 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_94
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_93:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_20:
# 813 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_UXIE_V
# 814 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_UXIE_V
# 815 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_UXIE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 816 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_97
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_96:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_21:
# 821 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MESPRIT_V
# 822 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MESPRIT_V
# 823 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_MESPRIT_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 824 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_100
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_99:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_22:
# 829 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AZELF_V
# 830 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AZELF_V
# 831 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_AZELF_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 832 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_103
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_102:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_23:
# 837 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIALGA_V
# 838 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DIALGA_V
# 839 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_DIALGA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 840 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_106
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_105:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_24:
# 845 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PALKIA_V
# 846 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PALKIA_V
# 847 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_PALKIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 848 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_109
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_108:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_25:
# 853 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GIRATINA_V
# 854 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GIRATINA_V
# 855 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_GIRATINA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 856 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_112
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_111:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_26:
# 861 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEATRAN_V
# 862 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HEATRAN_V
# 863 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_HEATRAN_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 864 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_115
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_114:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_27:
# 869 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIGIGAS_V
# 870 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIGIGAS_V
# 871 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_REGIGIGAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 872 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_118
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_117:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_28:
# 877 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRESSELIA_V
# 878 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CRESSELIA_V
# 879 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_CRESSELIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 880 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_121
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_120:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_29:
# 885 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COBALION_V
# 886 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COBALION_V
# 887 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_COBALION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 888 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_124
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_123:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_30:
# 893 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TERRAKION_V
# 894 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TERRAKION_V
# 895 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_TERRAKION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 896 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_127
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_126:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_31:
# 901 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_VIRIZION_V
# 902 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VIRIZION_V
# 903 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_VIRIZION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 904 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_130
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_129:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_32:
# 909 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TORNADUS_V
# 910 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS_V
# 911 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_TORNADUS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 912 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_133
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_132:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_33:
# 917 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_THUNDURUS_V
# 918 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS_V
# 919 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_THUNDURUS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 920 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_136
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_135:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_34:
# 925 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LANDORUS_V
# 926 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS_V
# 927 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LANDORUS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 928 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_139
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_138:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_35:
# 933 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RESHIRAM_V
# 934 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RESHIRAM_V
# 935 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_RESHIRAM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 936 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_142
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_141:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_36:
# 941 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZEKROM_V
# 942 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZEKROM_V
# 943 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ZEKROM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 944 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_145
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_144:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_37:
# 949 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYUREM_V
# 950 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYUREM_V
# 951 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_KYUREM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 952 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_148
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_147:
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_40:
# 962 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 963 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_Text_0
# 964 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 965 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 966 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 967 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_151
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_150:
# 971 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_39

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_41:
# 973 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 974 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_Text_0
# 975 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 976 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 977 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 978 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 979 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_154
RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_153:
# 982 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_39

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_46:
# 681 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_MEWTWO_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_45

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_49:
# 689 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_48

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_52:
# 697 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_51

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_55:
# 705 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_54

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_58:
# 713 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_57

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_61:
# 721 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_60

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_64:
# 729 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_63

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_67:
# 737 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_66

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_70:
# 745 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_69

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_73:
# 753 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_72

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_76:
# 761 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_75

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_79:
# 769 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_78

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_82:
# 777 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_81

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_85:
# 785 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_84

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_88:
# 793 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_87

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_91:
# 801 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_90

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_94:
# 809 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_93

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_97:
# 817 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_96

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_100:
# 825 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_99

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_103:
# 833 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_102

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_106:
# 841 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_105

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_109:
# 849 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_108

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_112:
# 857 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_111

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_115:
# 865 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_HEATRAN_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_114

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_118:
# 873 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_REGIGIGAS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_117

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_121:
# 881 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_CRESSELIA_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_120

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_124:
# 889 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_123

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_127:
# 897 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_126

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_130:
# 905 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_129

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_133:
# 913 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_132

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_136:
# 921 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_135

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_139:
# 929 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_138

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_142:
# 937 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_141

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_145:
# 945 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_144

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_148:
# 953 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_147

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_151:
# 968 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 969 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_150

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_154:
# 980 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_153


RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_0:
# 390 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Come on... so close...$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_1:
# 392 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh! I didn't see you there!$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_2:
# 393 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm on the verge of a breakthrough in my\n"
	.string "research.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_3:
# 394 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "All I need is a sample of Unstable DNA...$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_4:
# 401 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait... you found an Unstable DNA\n"
	.string "sample?\n"
	.string "That's incredible!$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_5:
# 402 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "With this, I can stabilize my lab grown\n"
	.string "prototypes.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_6:
# 403 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I call them... PROTO-LEGENDS!$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_7:
# 404 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "They are breathtaking POKéMON, forged\n"
	.string "with fragments of legendary power.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_8:
# 405 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Now, don't expect them to be perfect...$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_9:
# 406 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "They remain in the early stages of\n"
	.string "development.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_10:
# 407 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Though my research shows remarkable\n"
	.string "traits.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_11:
# 408 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "They harness abilities unlike their\n"
	.string "legendary counterparts.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_12:
# 409 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And they mutate with unusual\n"
	.string "frequency!$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_13:
# 410 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Keep in mind, each prototype belongs to\n"
	.string "a distinct genetic line.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_14:
# 411 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Meaning I can only create one POKéMON\n"
	.string "per lineage.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_15:
# 412 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "This ensures there are no conflicts\n"
	.string "with their unstable genetics.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_16:
# 425 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please, accept a Proto-Legend as a\n"
	.string "thank you for the DNA sample.$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_17:
# 429 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "From which region would you like your\n"
	.string "Proto-Legend?$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_18:
# 437 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And which genetic line are you\n"
	.string "interested in?$"

RustboroCity_DevonCorp_2F_EventScript_MiniLegendaryScientist_Text_19:
# 655 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "If you come across any Unstable DNA\n"
	.string "samples, please come see me!$"

RustboroCity_DevonCorp_2F_EventScript_HasMon_Text_0:
# 661 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait... I see you already possess\n"
	.string "a Proto-Legend from that genetic line.$"

RustboroCity_DevonCorp_2F_EventScript_HasMon_Text_1:
# 662 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I cannot create multiple prototypes\n"
	.string "from the same lineage.$"

RustboroCity_DevonCorp_2F_EventScript_HasMon_Text_2:
# 663 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The genetic instability would be\n"
	.string "too unpredictable.$"

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_Text_0:
# 963 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"

RustboroCity_DevonCorp_2F_EventScript_GiveLegendary_Text_1:
# 988 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Enjoy your new Proto-Legend!$"
