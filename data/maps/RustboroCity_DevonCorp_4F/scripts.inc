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
# 108 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 109 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_MET_DR_PARKER, Met_DrParker
# 110 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	GetDirectionToFace VAR_TEMP_0, LOCALID_DR_PARKER, OBJ_EVENT_ID_PLAYER
# 112 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_0
# 113 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	faceplayer
# 114 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DrParkerGreeting
# 117 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkitem ITEM_UNSTABLE_DNA, 1
# 118 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_DrParker_2
RustboroCity_DevonCorp_4F_EventScript_DrParker_1:
# 122 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playse SE_PIN
# 123 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	applymovement LOCALID_DR_PARKER, Common_Movement_ExclamationMark
# 124 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitse
# 125 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmovement 0
# 126 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DrParkerFoundDna
# 128 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_TEMP_0, DIR_WEST
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_DrParker_5
# 133 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	applymovement LOCALID_DR_PARKER, DrParkerExcited_MoveLeft
RustboroCity_DevonCorp_4F_EventScript_DrParker_4:
# 135 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmovement 0
# 137 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DrParkerMainExplanation
# 138 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_MET_DR_PARKER
# 139 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto FirstMeet_DrParker
# 141 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
Met_DrParker:
# 142 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	faceplayer
# 143 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkitem ITEM_UNSTABLE_DNA, 1
# 144 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_DrParker_9
RustboroCity_DevonCorp_4F_EventScript_DrParker_8:
# 147 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DrParkerReturnWithDna
# 148 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
FirstMeet_DrParker:
# 149 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_1
# 150 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
	return

RustboroCity_DevonCorp_4F_EventScript_DrParker_2:
# 119 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
	goto RustboroCity_DevonCorp_4F_EventScript_DrParker_1

RustboroCity_DevonCorp_4F_EventScript_DrParker_5:
# 130 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	applymovement LOCALID_DR_PARKER, DrParkerExcited_MoveRight
	goto RustboroCity_DevonCorp_4F_EventScript_DrParker_4

RustboroCity_DevonCorp_4F_EventScript_DrParker_9:
# 145 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
	goto RustboroCity_DevonCorp_4F_EventScript_DrParker_8


RustboroCity_DevonCorp_4F_EventScript_SelectRegion::
# 154 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_0
# 155 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_1, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_2, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_3, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_4, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_5, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_6, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_7, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_8
# 166 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 167 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_REGION_CHOICES - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectRegion_2
RustboroCity_DevonCorp_4F_EventScript_SelectRegion_1:
# 171 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_9
# 172 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 173 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_KANTO, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_5
# 175 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_JOHTO, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_6
# 177 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_HOENN, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_7
# 179 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_SINNOH, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_8
# 181 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_UNOVA, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_9
# 183 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_KALOS, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_10
# 185 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case REGION_CHOICE_ALOLA, RustboroCity_DevonCorp_4F_EventScript_SelectRegion_11
# 192 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_2:
# 168 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion_1

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_5:
# 174 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_6:
# 176 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_7:
# 178 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_8:
# 180 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_9:
# 182 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_10:
# 184 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos
	return

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_11:
# 186 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	return


RustboroCity_DevonCorp_4F_EventScript_SelectKanto::
# 197 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KANTO, FALSE
# 198 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 200 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 201 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KANTO_CHOICE_MEWTWO, RustboroCity_DevonCorp_4F_EventScript_SelectKanto_3
# 211 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KANTO_CHOICE_BIRDS, RustboroCity_DevonCorp_4F_EventScript_SelectKanto_4
# 222 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectKanto_1:
# 225 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 226 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_3:
# 202 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_MEWTWO_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 203 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_MEWTWO, FALSE
# 204 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 206 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_MEWTWO - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKanto_7
RustboroCity_DevonCorp_4F_EventScript_SelectKanto_6:
# 209 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MEWTWO
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_1

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_4:
# 212 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_BIRD_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 213 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_BIRDS, FALSE
# 214 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 216 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_BIRDS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKanto_10
RustboroCity_DevonCorp_4F_EventScript_SelectKanto_9:
# 219 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_BIRDS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_1

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_7:
# 207 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_6

RustboroCity_DevonCorp_4F_EventScript_SelectKanto_10:
# 217 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKanto_9


RustboroCity_DevonCorp_4F_EventScript_SelectJohto::
# 230 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_JOHTO, FALSE
# 231 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 233 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 234 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case JOHTO_CHOICE_BEASTS, RustboroCity_DevonCorp_4F_EventScript_SelectJohto_3
# 244 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case JOHTO_CHOICE_TOWER, RustboroCity_DevonCorp_4F_EventScript_SelectJohto_4
# 255 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectJohto_1:
# 258 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 259 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_3:
# 235 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_BEASTS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 236 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_BEASTS, FALSE
# 237 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 239 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_BEASTS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectJohto_7
RustboroCity_DevonCorp_4F_EventScript_SelectJohto_6:
# 242 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_BEASTS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_1

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_4:
# 245 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TOWER_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 246 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TOWER, FALSE
# 247 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 249 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TOWER - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectJohto_10
RustboroCity_DevonCorp_4F_EventScript_SelectJohto_9:
# 252 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TOWER
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_1

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_7:
# 240 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_6

RustboroCity_DevonCorp_4F_EventScript_SelectJohto_10:
# 250 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto
	goto RustboroCity_DevonCorp_4F_EventScript_SelectJohto_9


RustboroCity_DevonCorp_4F_EventScript_SelectHoenn::
# 263 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_HOENN, FALSE
# 264 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 266 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 267 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case HOENN_CHOICE_REGIS, RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_3
# 277 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case HOENN_CHOICE_EON, RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_4
# 287 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case HOENN_CHOICE_WEATHER, RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_5
# 298 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1:
# 301 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 302 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_3:
# 268 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_REGI_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 269 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_REGI, FALSE
# 270 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 272 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_REGIS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_8
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_7:
# 275 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_REGIS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_4:
# 278 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_EON_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 279 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_EON, FALSE
# 280 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 282 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_EON - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_11
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_10:
# 285 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_EON
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_5:
# 288 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_WEATHER_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 289 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_WEATHER, FALSE
# 290 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 292 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_WEATHER - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_14
RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_13:
# 295 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_WEATHER
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_1

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_8:
# 273 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_7

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_11:
# 283 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_10

RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_14:
# 293 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn
	goto RustboroCity_DevonCorp_4F_EventScript_SelectHoenn_13


RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh::
# 306 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SINNOH, FALSE
# 307 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 309 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 310 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_LAKE, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_3
# 320 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_MYTH, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_4
# 330 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_RELIC, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_5
# 341 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1:
# 344 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 345 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_3:
# 311 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_LAKE_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 312 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_LAKE, FALSE
# 313 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 315 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_LAKE - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_8
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_7:
# 318 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_LAKE
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_4:
# 321 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_MYTH_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 322 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_MYTH, FALSE
# 323 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 325 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_MYTH - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_11
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_10:
# 328 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MYTH
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_5:
# 331 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_RELIC_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 332 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_RELIC, FALSE
# 333 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 335 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_RELIC - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_14
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_13:
# 338 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_RELIC
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_8:
# 316 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_7

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_11:
# 326 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_10

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_14:
# 336 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_13


RustboroCity_DevonCorp_4F_EventScript_SelectUnova::
# 349 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_UNOVA, FALSE
# 350 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 352 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 353 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_SWORDS, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_3
# 363 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_FORCES, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_4
# 373 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_TAO, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_5
# 384 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1:
# 387 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 388 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_3:
# 354 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_SWORDS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 355 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SWORDS, FALSE
# 356 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 358 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_SWORDS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_8
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_7:
# 361 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_SWORDS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_4:
# 364 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_FORCES_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 365 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_FORCES, FALSE
# 366 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 368 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_FORCES - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_11
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_10:
# 371 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_FORCES
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_5:
# 374 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAO_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 375 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAO, FALSE
# 376 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 378 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAO - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_14
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_13:
# 381 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAO
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_8:
# 359 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_7

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_11:
# 369 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_10

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_14:
# 379 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_13


RustboroCity_DevonCorp_4F_EventScript_SelectKalos::
# 392 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KALOS, FALSE
# 393 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 395 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 396 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KALOS_CHOICE_AURA, RustboroCity_DevonCorp_4F_EventScript_SelectKalos_3
# 407 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectKalos_1:
# 410 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 411 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectKalos_3:
# 397 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_AURA_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 398 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_AURA, FALSE
# 399 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 401 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_AURA - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKalos_6
RustboroCity_DevonCorp_4F_EventScript_SelectKalos_5:
# 404 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_AURA
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos_1

RustboroCity_DevonCorp_4F_EventScript_SelectKalos_6:
# 402 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos_5


RustboroCity_DevonCorp_4F_EventScript_SelectAlola::
# 415 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_ALOLA, FALSE
# 416 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 418 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 419 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_TAPUS, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_3
# 429 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_TYPENULL, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_4
# 439 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_COSMOG, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_5
# 449 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_NECROZMA, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_6
# 460 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1:
# 463 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 464 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_3:
# 420 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAPUS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 421 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAPUS, FALSE
# 422 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 424 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAPUS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_9
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_8:
# 427 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAPUS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_4:
# 430 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TYPENULL_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 431 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TYPENULL, FALSE
# 432 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 434 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TYPENULL - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_12
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_11:
# 437 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TYPENULL
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_5:
# 440 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_COSMOG_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 441 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_COSMOG, FALSE
# 442 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 444 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_COSMOG - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_15
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_14:
# 447 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_COSMOG
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_6:
# 450 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_NECROZMA_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 451 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_NECROZMA, FALSE
# 452 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 454 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_NECROZMA - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_18
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_17:
# 457 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_NECROZMA
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_9:
# 425 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_8

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_12:
# 435 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_11

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_15:
# 445 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_14

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_18:
# 455 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_17


RustboroCity_DevonCorp_4F_EventScript_OfferShiny::
# 468 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_2, 0
# 469 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_0
# 470 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	showmoneybox 0, 0
# 471 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_ShinyOffer
# 472 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 474 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_OfferShiny_2
# 494 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 495 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_2
RustboroCity_DevonCorp_4F_EventScript_OfferShiny_1:
# 499 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_0x8004, ITEM_UNSTABLE_DNA
# 500 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 502 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary
	return

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_2:
# 476 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkmoney 50000
# 478 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_OfferShiny_5
# 486 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 487 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_ShinyNoMoney
# 488 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 489 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_5:
# 479 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	removemoney 50000
# 480 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playse SE_SHOP
# 481 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitse
# 482 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 483 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_2, 1
# 484 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_1
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny_1


RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd::
# 506 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd_Text_0
# 507 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 508 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_HasMon::
# 512 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_HasMonLine
# 513 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 514 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_GiveLegendary::
# 518 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_TEMP_1
# 524 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 0, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_3
# 532 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 1, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_4
# 540 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 2, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_5
# 548 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 3, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_6
# 556 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 4, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_7
# 564 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 5, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_8
# 572 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 6, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_9
# 580 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 7, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_10
# 588 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 8, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_11
# 596 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 9, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_12
# 604 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 10, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_13
# 612 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 11, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_14
# 620 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 12, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_15
# 628 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 13, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_16
# 636 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 14, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_17
# 644 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 15, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_18
# 652 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 16, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_19
# 660 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 17, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_20
# 668 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 18, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_21
# 676 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 19, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_22
# 684 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 20, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_23
# 692 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 21, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_24
# 700 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 22, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_25
# 708 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 23, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_26
# 716 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 24, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_27
# 724 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 25, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_28
# 732 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 26, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_29
# 740 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 27, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_30
# 748 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 28, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_31
# 756 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 29, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_32
# 764 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 30, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_33
# 772 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 31, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_34
# 780 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 32, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_35
# 788 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 33, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_36
# 796 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 34, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_37
# 804 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 35, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_38
# 812 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 36, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_39
# 820 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 37, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_40
# 828 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 38, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_41
# 836 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 39, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_42
# 844 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 40, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_43
# 852 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 41, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_44
# 860 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 42, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_45
# 868 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 43, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_46
# 876 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 44, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_47
# 886 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1:
# 890 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_ne RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_50
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_49:
# 909 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_188
# 916 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_189
# 924 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_187:
# 927 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_2
# 928 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 929 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_3:
# 525 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MEWTWO_V
# 526 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEWTWO_V
# 527 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MEWTWO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 528 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_53
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_52:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_4:
# 533 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO_V
# 534 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_V
# 535 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ARTICUNO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 536 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_56
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_55:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_5:
# 541 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS_V
# 542 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_V
# 543 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZAPDOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 544 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_59
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_58:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_6:
# 549 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES_V
# 550 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_V
# 551 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MOLTRES_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 552 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_62
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_61:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_7:
# 557 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAIKOU_V
# 558 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAIKOU_V
# 559 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RAIKOU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 560 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_65
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_64:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_8:
# 565 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI_V
# 566 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENTEI_V
# 567 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ENTEI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 568 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_68
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_67:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_9:
# 573 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE_V
# 574 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SUICUNE_V
# 575 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_SUICUNE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 576 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_71
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_70:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_10:
# 581 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_V
# 582 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LUGIA_V
# 583 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LUGIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 584 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_74
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_73:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_11:
# 589 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH_V
# 590 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HO_OH_V
# 591 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_HO_OH_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 592 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_77
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_76:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_12:
# 597 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIROCK_V
# 598 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIROCK_V
# 599 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGIROCK_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 600 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_80
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_79:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_13:
# 605 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGICE_V
# 606 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGICE_V
# 607 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGICE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 608 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_83
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_82:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_14:
# 613 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGISTEEL_V
# 614 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGISTEEL_V
# 615 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGISTEEL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 616 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_86
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_85:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_15:
# 621 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIAS_V
# 622 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIAS_V
# 623 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LATIAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 624 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_89
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_88:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_16:
# 629 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIOS_V
# 630 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIOS_V
# 631 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LATIOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 632 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_92
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_91:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_17:
# 637 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYOGRE_V
# 638 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYOGRE_V
# 639 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_KYOGRE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 640 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_95
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_94:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_18:
# 645 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON_V
# 646 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GROUDON_V
# 647 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_GROUDON_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 648 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_98
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_97:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_19:
# 653 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAYQUAZA_V
# 654 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAYQUAZA_V
# 655 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RAYQUAZA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 656 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_101
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_100:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_20:
# 661 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_UXIE_V
# 662 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_UXIE_V
# 663 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_UXIE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 664 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_104
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_103:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_21:
# 669 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MESPRIT_V
# 670 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MESPRIT_V
# 671 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MESPRIT_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 672 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_107
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_106:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_22:
# 677 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AZELF_V
# 678 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AZELF_V
# 679 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_AZELF_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 680 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_110
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_109:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_23:
# 685 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIALGA_V
# 686 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DIALGA_V
# 687 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_DIALGA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 688 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_113
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_112:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_24:
# 693 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PALKIA_V
# 694 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PALKIA_V
# 695 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_PALKIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 696 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_116
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_115:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_25:
# 701 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GIRATINA_V_ALTERED
# 702 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GIRATINA_V_ALTERED
# 703 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_GIRATINA_V_ALTERED, 5, ITEM_NONE, ITEM_BEAST_BALL
# 704 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_119
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_118:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_26:
# 709 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEATRAN_V
# 710 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HEATRAN_V
# 711 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_HEATRAN_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 712 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_122
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_121:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_27:
# 717 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIGIGAS_V
# 718 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIGIGAS_V
# 719 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGIGIGAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 720 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_125
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_124:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_28:
# 725 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRESSELIA_V
# 726 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CRESSELIA_V
# 727 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_CRESSELIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 728 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_128
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_127:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_29:
# 733 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COBALION_V
# 734 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COBALION_V
# 735 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_COBALION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 736 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_131
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_130:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_30:
# 741 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TERRAKION_V
# 742 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TERRAKION_V
# 743 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TERRAKION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 744 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_134
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_133:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_31:
# 749 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_VIRIZION_V
# 750 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VIRIZION_V
# 751 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_VIRIZION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 752 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_137
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_136:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_32:
# 757 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TORNADUS_V_INCARNATE
# 758 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS_V_INCARNATE
# 759 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TORNADUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 760 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_140
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_139:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_33:
# 765 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_THUNDURUS_V_INCARNATE
# 766 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS_V_INCARNATE
# 767 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_THUNDURUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 768 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_143
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_142:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_34:
# 773 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LANDORUS_V_INCARNATE
# 774 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS_V_INCARNATE
# 775 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LANDORUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 776 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_146
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_145:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_35:
# 781 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RESHIRAM_V
# 782 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RESHIRAM_V
# 783 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RESHIRAM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 784 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_149
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_148:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_36:
# 789 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZEKROM_V
# 790 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZEKROM_V
# 791 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZEKROM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 792 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_152
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_151:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_37:
# 797 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYUREM_V
# 798 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYUREM_V
# 799 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_KYUREM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 800 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_155
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_154:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_38:
# 805 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_XERNEAS_V_NEUTRAL
# 806 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_XERNEAS_V_NEUTRAL
# 807 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_XERNEAS_V_NEUTRAL, 5, ITEM_NONE, ITEM_BEAST_BALL
# 808 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_158
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_157:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_39:
# 813 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_YVELTAL_V
# 814 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_YVELTAL_V
# 815 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_YVELTAL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 816 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_161
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_160:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_40:
# 821 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZYGARDE_V
# 822 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZYGARDE_V
# 823 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZYGARDE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 824 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_164
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_163:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_41:
# 829 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_KOKO_V
# 830 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_KOKO_V
# 831 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_KOKO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 832 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_167
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_166:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_42:
# 837 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_LELE_V
# 838 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_LELE_V
# 839 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_LELE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 840 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_170
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_169:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_43:
# 845 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_BULU_V
# 846 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_BULU_V
# 847 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_BULU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 848 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_173
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_172:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_44:
# 853 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_FINI_V
# 854 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_FINI_V
# 855 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_FINI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 856 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_176
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_175:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_45:
# 861 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYPE_NULL_V
# 862 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYPE_NULL_V
# 863 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TYPE_NULL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 864 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_179
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_178:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_46:
# 869 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COSMOG_V
# 870 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COSMOG_V
# 871 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_COSMOG_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 872 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_182
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_181:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_47:
# 877 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NECROZMA_V
# 878 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_NECROZMA_V
# 879 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_NECROZMA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 880 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_185
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_184:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_50:
# 892 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_TEMP_2, 1
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_194
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_193:
# 897 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playmoncry VAR_TEMP_TRANSFERRED_SPECIES, CRY_MODE_ENCOUNTER
# 898 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 1
# 899 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_0
# 900 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	fadescreenspeed FADE_FROM_BLACK, 1
# 901 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmoncry
# 903 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 904 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_1
# 905 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmessage
# 906 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitfanfare
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_49

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_53:
# 529 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MEWTWO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_52

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_56:
# 537 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_55

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_59:
# 545 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_58

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_62:
# 553 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_61

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_65:
# 561 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_64

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_68:
# 569 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_67

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_71:
# 577 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_70

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_74:
# 585 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_73

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_77:
# 593 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_76

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_80:
# 601 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_79

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_83:
# 609 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_82

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_86:
# 617 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_85

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_89:
# 625 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_88

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_92:
# 633 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_91

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_95:
# 641 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_94

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_98:
# 649 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_97

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_101:
# 657 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_100

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_104:
# 665 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_103

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_107:
# 673 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_106

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_110:
# 681 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_109

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_113:
# 689 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_112

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_116:
# 697 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_115

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_119:
# 705 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_118

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_122:
# 713 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_121

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_125:
# 721 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_124

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_128:
# 729 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_127

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_131:
# 737 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_130

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_134:
# 745 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_133

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_137:
# 753 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_136

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_140:
# 761 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_139

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_143:
# 769 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_142

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_146:
# 777 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_145

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_149:
# 785 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_148

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_152:
# 793 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_151

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_155:
# 801 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_154

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_158:
# 809 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_157

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_161:
# 817 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_160

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_164:
# 825 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_163

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_167:
# 833 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_166

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_170:
# 841 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_169

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_173:
# 849 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_172

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_176:
# 857 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_175

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_179:
# 865 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TYPENULL_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_178

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_182:
# 873 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_COSMOG_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_181

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_185:
# 881 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_NECROZMA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_184

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_188:
# 910 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 911 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_197
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_196:
# 915 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_187

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_189:
# 917 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 918 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 919 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_200
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_199:
# 922 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_187

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_194:
# 893 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	callnative Script_SetLastGiftMonShiny
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_193

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_197:
# 912 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 913 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_196

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_200:
# 920 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_199


RustboroCity_DevonCorp_4F_EventScript_TableProtoLegends::
# 933 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 934 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_TableProtoLegends
# 935 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_MonitorMutations::
# 939 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 940 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_MonitorMutations
# 941 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_DisplayGeneticLines::
# 945 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 946 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DisplayGeneticLines
# 947 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_DisplayExperiment::
# 951 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 952 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DisplayExperiment
# 953 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_0:
# 112 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Come on... so close...$"

RustboroCity_DevonCorp_4F_EventScript_DrParker_Text_1:
# 149 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Please, accept a Proto-Legend as a\n"
	.string "thank you for the DNA sample.$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_0:
# 154 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "From which region would you like\nyour Proto-Legend?$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_1:
# 156 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "KANTO$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_2:
# 157 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "JOHTO$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_3:
# 158 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "HOENN$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_4:
# 159 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "SINNOH$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_5:
# 160 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "UNOVA$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_6:
# 161 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "KALOS$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_7:
# 162 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "ALOLA$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_8:
# 165 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{COLOR GREEN}EXIT$"

RustboroCity_DevonCorp_4F_EventScript_SelectRegion_Text_9:
# 171 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "And which genetic line are you\ninterested in?$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_0:
# 469 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Oh, I almost forgot!$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_1:
# 484 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Excellent! I'll prepare a special\n"
	.string "variant for you.$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_2:
# 495 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "OK, I'll get to work...$"

RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd_Text_0:
# 506 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "If you come across any Unstable DNA\n"
	.string "samples, please come see me!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_0:
# 899 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{STR_VAR_1} materialized from the\n"
	.string "Unstable DNA!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_1:
# 904 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_2:
# 927 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Enjoy your new\n"
	.string "Proto-Legend!$"

RustboroCity_DevonCorp_4F_Text_DrParkerGreeting::
# 36 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Oh! I didn't see you there!\p"
	.string "I'm on the verge of a breakthrough\n"
	.string "in my research.\p"
	.string "All I need is a sample of Unstable DNA...$"

RustboroCity_DevonCorp_4F_Text_DrParkerFoundDna::
# 42 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Wait... you found an\n"
	.string "Unstable DNA sample?\p"
	.string "What an incredible day this is!!!$"

RustboroCity_DevonCorp_4F_Text_DrParkerMainExplanation::
# 47 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Wait...\n"
	.string "You got it from ROXANNE?\p"
	.string "How in the world did ROXANNE\n"
	.string "get that Unstable DNA?\p"
	.string "If you are willing to part with it...\n"
	.string "I can finally stabilize my lab-grown\l"
	.string "experiments.\p"
	.string "I call them... PROTO-LEGENDS!\p"
	.string "They are breathtaking POKéMON, forged\n"
	.string "with fragments of legendary power.\p"
	.string "Now, don't expect them to be perfect...\n"
	.string "They remain in the early stages of\l"
	.string "development.\p"
	.string "Though my research shows remarkable\n"
	.string "traits. They harness abilities unlike\l"
	.string "their legendary counterparts.\p"
	.string "And they mutate with unusual\n"
	.string "frequency!\p"
	.string "Keep in mind, each prototype belongs\n"
	.string "to a distinct genetic line.\p"
	.string "Meaning I can only create one POKéMON\n"
	.string "per lineage. This avoids conflicts\l"
	.string "with their unstable genetics.$"

RustboroCity_DevonCorp_4F_Text_DrParkerReturnWithDna::
# 64 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "DR. PARKER: Is that Unstable DNA I see?\p"
	.string "Splendid! My research continues\n"
	.string "to evolve!$"

RustboroCity_DevonCorp_4F_Text_ShinyOffer::
# 69 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "I could attempt to alter your\n"
	.string "Proto-Legend's color scheme.\p"
	.string "But it requires expensive materials.\n"
	.string "It'll cost you ¥50000.$"

RustboroCity_DevonCorp_4F_Text_ShinyNoMoney::
# 75 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Come back when you have ¥50000.\nYour Proto-Legend will be waiting!$"

RustboroCity_DevonCorp_4F_Text_HasMonLine::
# 79 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Wait... I see you already possess a\n"
	.string "Proto-Legend from that genetic line.\p"
	.string "I cannot create multiple prototypes\n"
	.string "from the same lineage.\p"
	.string "The genetic instability would be\n"
	.string "too unpredictable.$"

RustboroCity_DevonCorp_4F_Text_TableProtoLegends::
# 85 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Blueprints and sketches cover the\n"
	.string "table.\p"
	.string "Each page is labeled: PROTO-LEGENDS.\p"
	.string "Several failed drafts are crossed out:\n"
	.string "“Mutation cascade risk: CRITICAL.”$"

RustboroCity_DevonCorp_4F_Text_MonitorMutations::
# 92 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "A DEVON monitor displays mutation logs.\p"
	.string "Proto-Legends adapt rapidly under\n"
	.string "stress.\p"
	.string "Note: sudden mutations can alter\n"
	.string "abilities and battle tendencies.$"

RustboroCity_DevonCorp_4F_Text_DisplayGeneticLines::
# 98 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "A warning label reads:\n"
	.string "GENETIC LINEAGE CONTAINMENT PROTOCOL\p"
	.string "Only one Proto-Legend may be\n"
	.string "stabilized per genetic line.$"

RustboroCity_DevonCorp_4F_Text_DisplayExperiment::
# 103 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "A glass chamber hums softly.\nA glowing orb pulses inside.$"
