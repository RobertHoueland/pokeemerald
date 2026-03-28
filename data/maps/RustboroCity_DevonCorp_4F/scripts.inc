# 1 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
RustboroCity_DevonCorp_4F_MapScripts::
# 3 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.byte 0

# 6 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
DrParkerExcited_MoveLeft:
# 7 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_left
# 7 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_left
# 8 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_down
# 9 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	delay_16
# 10 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_up
# 10 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_up
# 11 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_left
# 12 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	delay_16
# 13 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_right
# 14 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_up
# 15 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	delay_16
# 16 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_down
# 16 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_down
# 17 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_right
# 18 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_player
	step_end

# 21 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
DrParkerExcited_MoveRight:
# 22 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_right
# 22 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_right
# 23 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_down
# 24 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	delay_16
# 25 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_up
# 25 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_up
# 26 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_left
# 27 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	delay_16
# 28 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_right
# 29 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_up
# 30 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	delay_16
# 31 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_down
# 31 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_down
# 32 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_left
# 32 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_left
# 32 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	walk_left
# 33 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	face_player
	step_end

RustboroCity_DevonCorp_4F_EventScript_DrParker::
# 37 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 38 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_MET_DR_PARKER, Met_DrParker
# 39 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	GetDirectionToFace VAR_TEMP_0, LOCALID_DR_PARKER, OBJ_EVENT_ID_PLAYER
# 41 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_0
# 42 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	faceplayer
# 43 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_1
# 45 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_2
# 46 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_3
# 48 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkitem ITEM_UNSTABLE_DNA, 1
# 49 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_DrParker_2
RustboroCity_DevonCorp_4F_EventScript_DrParker_1:
# 53 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playse SE_PIN
# 54 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	applymovement LOCALID_DR_PARKER, Common_Movement_ExclamationMark
# 55 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmovement 0
# 56 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_4
# 57 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_5
# 59 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_TEMP_0, DIR_WEST
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_DrParker_5
# 64 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	applymovement LOCALID_DR_PARKER, DrParkerExcited_MoveLeft
RustboroCity_DevonCorp_4F_EventScript_DrParker_4:
# 66 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmovement 0
# 68 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_6
# 69 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_7
# 70 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_8
# 71 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_9
# 72 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_10
# 73 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_11
# 74 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_12
# 75 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_13
# 76 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_14
# 77 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_15
# 78 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_16
# 79 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_17
# 80 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_18
# 81 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_19
# 82 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_MET_DR_PARKER
# 83 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto FirstMeet_DrParker
# 85 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
Met_DrParker:
# 86 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	faceplayer
# 87 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkitem ITEM_UNSTABLE_DNA, 1
# 88 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_DrParker_9
RustboroCity_DevonCorp_4F_EventScript_DrParker_8:
# 91 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_20
# 92 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_21
# 93 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
FirstMeet_DrParker:
# 94 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_22
# 95 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
	return

RustboroCity_DevonCorp_4F_EventScript_DrParker_2:
# 50 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
	goto RustboroCity_DevonCorp_4F_EventScript_DrParker_1

RustboroCity_DevonCorp_4F_EventScript_DrParker_5:
# 61 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	applymovement LOCALID_DR_PARKER, DrParkerExcited_MoveRight
	goto RustboroCity_DevonCorp_4F_EventScript_DrParker_4

RustboroCity_DevonCorp_4F_EventScript_DrParker_9:
# 89 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
	goto RustboroCity_DevonCorp_4F_EventScript_DrParker_8


RustboroCity_DevonCorp_4F_EventScript_SelectRegion::
# 99 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_0
# 100 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_1, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_2, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_3, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_4, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_5, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_6, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_7, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_8
# 111 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 112 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_REGION_CHOICES - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectRegion_2
RustboroCity_DevonCorp_4F_EventScript_SelectRegion_1:
# 116 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_9
# 117 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 118 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_KANTO, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_5
# 120 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_JOHTO, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_6
# 122 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_HOENN, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_7
# 124 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_SINNOH, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_8
# 126 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_UNOVA, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_9
# 128 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_KALOS, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_10
# 130 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_ALOLA, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_11
# 137 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_2:
# 113 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion_1

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_5:
# 119 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_6:
# 121 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_7:
# 123 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_8:
# 125 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_9:
# 127 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_10:
# 129 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_11:
# 131 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	return


RustboroCity_DevonCorp_4F_EventScript_SelectKanto::
# 142 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KANTO, FALSE
# 143 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 145 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 146 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KANTO_CHOICE_MEWTWO, RustboroCity_DevonCorp_4F_EventScript_SelectKanto_3
# 156 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KANTO_CHOICE_BIRDS, RustboroCity_DevonCorp_4F_EventScript_SelectKanto_4
# 167 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectKanto_1:
# 170 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 171 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_3:
# 147 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_MEWTWO_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 148 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_MEWTWO, FALSE
# 149 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 151 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_MEWTWO - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKanto_7
RustboroCity_DevonCorp_4F_EventScript_SelectKanto_6:
# 154 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MEWTWO
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_1

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_4:
# 157 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_BIRD_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 158 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_BIRDS, FALSE
# 159 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 161 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_BIRDS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKanto_10
RustboroCity_DevonCorp_4F_EventScript_SelectKanto_9:
# 164 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_BIRDS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_1

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_7:
# 152 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_6

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_10:
# 162 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_9


RustboroCity_DevonCorp_4F_EventScript_SelectJohto::
# 175 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_JOHTO, FALSE
# 176 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 178 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 179 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case JOHTO_CHOICE_BEASTS, RustboroCity_DevonCorp_4F_EventScript_SelectJohto_3
# 189 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case JOHTO_CHOICE_TOWER, RustboroCity_DevonCorp_4F_EventScript_SelectJohto_4
# 200 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectJohto_1:
# 203 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 204 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_3:
# 180 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_BEASTS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 181 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_BEASTS, FALSE
# 182 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 184 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_BEASTS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectJohto_7
RustboroCity_DevonCorp_4F_EventScript_SelectJohto_6:
# 187 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_BEASTS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_1

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_4:
# 190 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TOWER_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 191 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TOWER, FALSE
# 192 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 194 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TOWER - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectJohto_10
RustboroCity_DevonCorp_4F_EventScript_SelectJohto_9:
# 197 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TOWER
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_1

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_7:
# 185 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_6

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_10:
# 195 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_9


RustboroCity_DevonCorp_4F_EventScript_SelectHoenn::
# 208 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_HOENN, FALSE
# 209 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 211 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 212 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case HOENN_CHOICE_REGIS, RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_3
# 222 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case HOENN_CHOICE_EON, RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_4
# 232 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case HOENN_CHOICE_WEATHER, RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_5
# 243 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1:
# 246 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 247 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_3:
# 213 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_REGI_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 214 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_REGI, FALSE
# 215 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 217 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_REGIS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_8
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_7:
# 220 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_REGIS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_4:
# 223 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_EON_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 224 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_EON, FALSE
# 225 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 227 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_EON - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_11
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_10:
# 230 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_EON
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_5:
# 233 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_WEATHER_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 234 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_WEATHER, FALSE
# 235 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 237 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_WEATHER - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_14
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_13:
# 240 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_WEATHER
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_8:
# 218 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_7

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_11:
# 228 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_10

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_14:
# 238 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_13


RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh::
# 251 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SINNOH, FALSE
# 252 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 254 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 255 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_LAKE, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_3
# 265 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_MYTH, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_4
# 275 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_RELIC, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_5
# 286 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1:
# 289 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 290 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_3:
# 256 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_LAKE_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 257 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_LAKE, FALSE
# 258 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 260 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_LAKE - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_8
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_7:
# 263 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_LAKE
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_4:
# 266 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_MYTH_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 267 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_MYTH, FALSE
# 268 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 270 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_MYTH - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_11
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_10:
# 273 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MYTH
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_5:
# 276 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_RELIC_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 277 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_RELIC, FALSE
# 278 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 280 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_RELIC - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_14
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_13:
# 283 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_RELIC
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_8:
# 261 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_7

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_11:
# 271 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_10

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_14:
# 281 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_13


RustboroCity_DevonCorp_4F_EventScript_SelectUnova::
# 294 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_UNOVA, FALSE
# 295 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 297 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 298 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_SWORDS, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_3
# 308 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_FORCES, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_4
# 318 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_TAO, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_5
# 329 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1:
# 332 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 333 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_3:
# 299 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_SWORDS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 300 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SWORDS, FALSE
# 301 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 303 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_SWORDS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_8
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_7:
# 306 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_SWORDS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_4:
# 309 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_FORCES_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 310 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_FORCES, FALSE
# 311 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 313 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_FORCES - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_11
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_10:
# 316 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_FORCES
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_5:
# 319 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAO_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 320 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAO, FALSE
# 321 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 323 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAO - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_14
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_13:
# 326 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAO
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_8:
# 304 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_7

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_11:
# 314 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_10

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_14:
# 324 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_13


RustboroCity_DevonCorp_4F_EventScript_SelectKalos::
# 337 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KALOS, FALSE
# 338 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 340 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 341 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KALOS_CHOICE_AURA, RustboroCity_DevonCorp_4F_EventScript_SelectKalos_3
# 352 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectKalos_1:
# 355 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 356 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectKalos_3:
# 342 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_AURA_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 343 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_AURA, FALSE
# 344 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 346 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_AURA - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKalos_6
RustboroCity_DevonCorp_4F_EventScript_SelectKalos_5:
# 349 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_AURA
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos_1

RustboroCity_DevonCorp_4F_EventScript_SelectKalos_6:
# 347 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos_5


RustboroCity_DevonCorp_4F_EventScript_SelectAlola::
# 360 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_ALOLA, FALSE
# 361 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 363 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 364 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_TAPUS, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_3
# 374 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_TYPENULL, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_4
# 384 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_LIGHT, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_5
# 395 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1:
# 398 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 399 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_3:
# 365 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAPUS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 366 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAPUS, FALSE
# 367 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 369 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAPUS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_8
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_7:
# 372 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAPUS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_4:
# 375 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TYPENULL_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 376 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TYPENULL, FALSE
# 377 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 379 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TYPENULL - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_11
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_10:
# 382 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TYPENULL
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_5:
# 385 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_LIGHT_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 386 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_LIGHT, FALSE
# 387 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 389 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_LIGHT - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_14
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_13:
# 392 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_LIGHT
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_8:
# 370 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_7

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_11:
# 380 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_10

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_14:
# 390 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_13


RustboroCity_DevonCorp_4F_EventScript_OfferShiny::
# 403 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_2, 0
# 404 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_0
# 405 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	showmoneybox 0, 0
# 406 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_1
# 407 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_2
# 408 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 409 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 411 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_OfferShiny_2
# 428 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_5
RustboroCity_DevonCorp_4F_EventScript_OfferShiny_1:
# 432 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_0x8004, ITEM_UNSTABLE_DNA
# 433 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 435 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary
	return

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_2:
# 413 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkmoney 50000
# 415 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_OfferShiny_5
# 421 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_4
# 422 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 423 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_5:
# 416 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	removemoney 50000
# 417 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playse SE_SHOP
# 418 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_2, 1
# 419 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_3
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny_1


RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd::
# 439 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd_Text_0
# 440 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 441 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_HasMon::
# 445 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_HasMon_Text_0
# 446 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_HasMon_Text_1
# 447 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_HasMon_Text_2
# 448 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 449 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_GiveLegendary::
# 453 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_TEMP_1
# 459 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 0, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_3
# 467 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 1, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_4
# 475 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 2, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_5
# 483 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 3, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_6
# 491 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 4, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_7
# 499 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 5, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_8
# 507 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 6, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_9
# 515 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 7, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_10
# 523 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 8, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_11
# 531 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 9, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_12
# 539 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 10, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_13
# 547 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 11, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_14
# 555 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 12, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_15
# 563 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 13, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_16
# 571 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 14, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_17
# 579 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 15, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_18
# 587 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 16, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_19
# 595 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 17, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_20
# 603 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 18, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_21
# 611 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 19, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_22
# 619 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 20, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_23
# 627 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 21, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_24
# 635 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 22, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_25
# 643 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 23, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_26
# 651 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 24, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_27
# 659 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 25, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_28
# 667 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 26, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_29
# 675 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 27, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_30
# 683 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 28, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_31
# 691 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 29, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_32
# 699 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 30, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_33
# 707 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 31, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_34
# 715 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 32, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_35
# 723 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 33, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_36
# 731 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 34, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_37
# 739 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 35, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_38
# 747 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 36, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_39
# 755 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 37, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_40
# 763 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 38, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_41
# 771 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 39, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_42
# 779 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 40, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_43
# 787 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 41, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_44
# 795 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 42, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_45
# 803 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 43, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_46
# 813 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1:
# 817 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_ne RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_49
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_48:
# 836 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_184
# 843 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_185
# 851 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_183:
# 854 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_2
# 855 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 856 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_3:
# 460 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MEWTWO_V
# 461 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEWTWO_V
# 462 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MEWTWO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 463 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_52
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_51:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_4:
# 468 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO_V
# 469 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_V
# 470 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ARTICUNO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 471 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_55
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_54:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_5:
# 476 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS_V
# 477 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_V
# 478 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZAPDOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 479 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_58
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_57:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_6:
# 484 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES_V
# 485 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_V
# 486 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MOLTRES_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 487 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_61
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_60:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_7:
# 492 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAIKOU_V
# 493 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAIKOU_V
# 494 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RAIKOU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 495 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_64
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_63:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_8:
# 500 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI_V
# 501 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENTEI_V
# 502 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ENTEI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 503 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_67
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_66:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_9:
# 508 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE_V
# 509 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SUICUNE_V
# 510 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_SUICUNE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 511 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_70
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_69:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_10:
# 516 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_V
# 517 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LUGIA_V
# 518 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LUGIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 519 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_73
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_72:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_11:
# 524 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH_V
# 525 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HO_OH_V
# 526 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_HO_OH_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 527 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_76
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_75:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_12:
# 532 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIROCK_V
# 533 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIROCK_V
# 534 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGIROCK_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 535 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_79
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_78:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_13:
# 540 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGICE_V
# 541 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGICE_V
# 542 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGICE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 543 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_82
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_81:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_14:
# 548 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGISTEEL_V
# 549 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGISTEEL_V
# 550 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGISTEEL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 551 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_85
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_84:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_15:
# 556 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIAS_V
# 557 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIAS_V
# 558 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LATIAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 559 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_88
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_87:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_16:
# 564 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIOS_V
# 565 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIOS_V
# 566 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LATIOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 567 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_91
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_90:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_17:
# 572 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYOGRE_V
# 573 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYOGRE_V
# 574 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_KYOGRE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 575 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_94
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_93:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_18:
# 580 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON_V
# 581 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GROUDON_V
# 582 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_GROUDON_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 583 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_97
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_96:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_19:
# 588 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAYQUAZA_V
# 589 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAYQUAZA_V
# 590 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RAYQUAZA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 591 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_100
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_99:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_20:
# 596 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_UXIE_V
# 597 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_UXIE_V
# 598 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_UXIE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 599 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_103
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_102:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_21:
# 604 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MESPRIT_V
# 605 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MESPRIT_V
# 606 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MESPRIT_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 607 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_106
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_105:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_22:
# 612 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AZELF_V
# 613 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AZELF_V
# 614 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_AZELF_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 615 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_109
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_108:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_23:
# 620 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIALGA_V
# 621 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DIALGA_V
# 622 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_DIALGA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 623 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_112
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_111:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_24:
# 628 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PALKIA_V
# 629 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PALKIA_V
# 630 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_PALKIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 631 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_115
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_114:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_25:
# 636 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GIRATINA_V
# 637 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GIRATINA_V
# 638 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_GIRATINA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 639 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_118
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_117:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_26:
# 644 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEATRAN_V
# 645 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HEATRAN_V
# 646 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_HEATRAN_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 647 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_121
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_120:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_27:
# 652 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIGIGAS_V
# 653 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIGIGAS_V
# 654 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGIGIGAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 655 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_124
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_123:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_28:
# 660 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRESSELIA_V
# 661 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CRESSELIA_V
# 662 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_CRESSELIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 663 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_127
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_126:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_29:
# 668 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COBALION_V
# 669 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COBALION_V
# 670 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_COBALION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 671 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_130
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_129:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_30:
# 676 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TERRAKION_V
# 677 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TERRAKION_V
# 678 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TERRAKION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 679 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_133
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_132:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_31:
# 684 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_VIRIZION_V
# 685 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VIRIZION_V
# 686 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_VIRIZION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 687 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_136
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_135:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_32:
# 692 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TORNADUS_V_INCARNATE
# 693 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS_V_INCARNATE
# 694 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TORNADUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 695 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_139
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_138:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_33:
# 700 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_THUNDURUS_V_INCARNATE
# 701 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS_V_INCARNATE
# 702 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_THUNDURUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 703 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_142
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_141:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_34:
# 708 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LANDORUS_V_INCARNATE
# 709 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS_V_INCARNATE
# 710 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LANDORUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 711 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_145
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_144:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_35:
# 716 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RESHIRAM_V
# 717 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RESHIRAM_V
# 718 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RESHIRAM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 719 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_148
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_147:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_36:
# 724 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZEKROM_V
# 725 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZEKROM_V
# 726 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZEKROM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 727 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_151
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_150:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_37:
# 732 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYUREM_V
# 733 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYUREM_V
# 734 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_KYUREM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 735 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_154
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_153:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_38:
# 740 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_XERNEAS_V_NEUTRAL
# 741 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_XERNEAS_V_NEUTRAL
# 742 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_XERNEAS_V_NEUTRAL, 5, ITEM_NONE, ITEM_BEAST_BALL
# 743 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_157
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_156:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_39:
# 748 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_YVELTAL_V
# 749 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_YVELTAL_V
# 750 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_YVELTAL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 751 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_160
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_159:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_40:
# 756 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZYGARDE_V
# 757 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZYGARDE_V
# 758 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZYGARDE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 759 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_163
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_162:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_41:
# 764 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_KOKO_V
# 765 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_KOKO_V
# 766 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_KOKO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 767 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_166
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_165:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_42:
# 772 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_LELE_V
# 773 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_LELE_V
# 774 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_LELE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 775 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_169
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_168:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_43:
# 780 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_BULU_V
# 781 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_BULU_V
# 782 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_BULU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 783 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_172
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_171:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_44:
# 788 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_FINI_V
# 789 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_FINI_V
# 790 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_FINI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 791 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_175
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_174:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_45:
# 796 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYPE_NULL_V
# 797 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYPE_NULL_V
# 798 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TYPE_NULL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 799 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_178
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_177:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_46:
# 804 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COSMOG_V
# 805 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COSMOG_V
# 806 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_COSMOG_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 807 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_181
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_180:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_49:
# 819 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_TEMP_2, 1
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_190
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_189:
# 824 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playmoncry VAR_TEMP_TRANSFERRED_SPECIES, CRY_MODE_ENCOUNTER
# 825 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 1
# 826 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_0
# 827 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	fadescreenspeed FADE_FROM_BLACK, 1
# 828 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmoncry
# 830 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 831 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_1
# 832 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmessage
# 833 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitfanfare
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_48

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_52:
# 464 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MEWTWO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_51

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_55:
# 472 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_54

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_58:
# 480 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_57

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_61:
# 488 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_60

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_64:
# 496 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_63

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_67:
# 504 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_66

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_70:
# 512 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_69

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_73:
# 520 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_72

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_76:
# 528 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_75

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_79:
# 536 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_78

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_82:
# 544 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_81

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_85:
# 552 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_84

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_88:
# 560 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_87

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_91:
# 568 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_90

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_94:
# 576 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_93

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_97:
# 584 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_96

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_100:
# 592 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_99

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_103:
# 600 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_102

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_106:
# 608 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_105

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_109:
# 616 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_108

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_112:
# 624 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_111

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_115:
# 632 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_114

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_118:
# 640 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_117

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_121:
# 648 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_120

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_124:
# 656 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_123

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_127:
# 664 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_126

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_130:
# 672 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_129

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_133:
# 680 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_132

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_136:
# 688 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_135

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_139:
# 696 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_138

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_142:
# 704 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_141

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_145:
# 712 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_144

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_148:
# 720 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_147

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_151:
# 728 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_150

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_154:
# 736 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_153

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_157:
# 744 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_156

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_160:
# 752 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_159

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_163:
# 760 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_162

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_166:
# 768 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_165

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_169:
# 776 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_168

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_172:
# 784 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_171

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_175:
# 792 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_174

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_178:
# 800 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TYPENULL_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_177

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_181:
# 808 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LIGHT_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_180

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_184:
# 837 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 838 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_193
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_192:
# 842 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_183

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_185:
# 844 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 845 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 846 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_196
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_195:
# 849 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_183

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_190:
# 820 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	callnative Script_SetLastGiftMonShiny
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_189

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_193:
# 839 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 840 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_192

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_196:
# 847 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_195


RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_0:
# 41 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Come on... so close...$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_1:
# 43 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Oh! I didn't see you there!$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_2:
# 45 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "I'm on the verge of a breakthrough\n"
	.string "in my research.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_3:
# 46 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "All I need is a sample of Unstable DNA...$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_4:
# 56 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR PARKER: Wait... you found an Unstable\n"
	.string "DNA sample?$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_5:
# 57 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "What an incredible day today is!!!$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_6:
# 68 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Wait...\n"
	.string "You got it from ROXANNE?$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_7:
# 69 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "How in the world did ROXANNE\n"
	.string "get that Unstable DNA?$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_8:
# 70 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "If you are willing to separate with it...$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_9:
# 71 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "I can finally stabilize my lab grown\n"
	.string "experiments.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_10:
# 72 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "I call them... PROTO-LEGENDS!$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_11:
# 73 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "They are breathtaking POKéMON, forged\n"
	.string "with fragments of legendary power.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_12:
# 74 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Now, don't expect them to be perfect...$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_13:
# 75 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "They remain in the early stages of\n"
	.string "development.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_14:
# 76 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Though my research shows remarkable\n"
	.string "traits.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_15:
# 77 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "They harness abilities unlike their\n"
	.string "legendary counterparts.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_16:
# 78 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "And they mutate with unusual\n"
	.string "frequency!$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_17:
# 79 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Keep in mind, each prototype belongs to\n"
	.string "a distinct genetic line.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_18:
# 80 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Meaning I can only create one\n"
	.string "POKéMON per lineage.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_19:
# 81 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "This ensures there are no conflicts\n"
	.string "with their unstable genetics.$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_20:
# 91 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Is that Unstable DNA I see?$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_21:
# 92 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Splendid! My research continues\n"
	.string "to evolve!$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_22:
# 94 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Please, accept a Proto-Legend as a\n"
	.string "thank you for the DNA sample.$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_0:
# 99 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "From which region would you like\nyour Proto-Legend?$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_1:
# 101 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "KANTO$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_2:
# 102 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "JOHTO$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_3:
# 103 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "HOENN$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_4:
# 104 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "SINNOH$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_5:
# 105 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "UNOVA$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_6:
# 106 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "KALOS$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_7:
# 107 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "ALOLA$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_8:
# 110 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{COLOR GREEN}EXIT$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_9:
# 116 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "And which genetic line are you\ninterested in?$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_0:
# 404 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Oh, I almost forgot!$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_1:
# 406 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "I could attempt to alter your\n"
	.string "Proto-Legend's color scheme.$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_2:
# 407 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "But it requires expensive materials.\n"
	.string "It'll cost you ¥50000.$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_3:
# 419 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Excellent! I'll prepare a special\n"
	.string "variant for you.$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_4:
# 421 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Come back when you have ¥50000.\n"
	.string "Your Proto-Legend will be waiting!$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_5:
# 428 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "OK, I'll get to work...$"

RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd_Text_0:
# 439 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "If you come across any Unstable DNA\n"
	.string "samples, please come see me!$"

RustboroCity_DevonCorp_4F_EventScript_HasMon_Text_0:
# 445 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Wait... I see you already possess\n"
	.string "a Proto-Legend from that genetic line.$"

RustboroCity_DevonCorp_4F_EventScript_HasMon_Text_1:
# 446 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "I cannot create multiple prototypes\n"
	.string "from the same lineage.$"

RustboroCity_DevonCorp_4F_EventScript_HasMon_Text_2:
# 447 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "The genetic instability would be\n"
	.string "too unpredictable.$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_0:
# 826 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{STR_VAR_1} materialized from the\n"
	.string "Unstable DNA!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_1:
# 831 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_2:
# 854 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Enjoy your new\n"
	.string "Proto-Legend!$"
