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
	case SINNOH_CHOICE_GIRATINA, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_5
# 340 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case SINNOH_CHOICE_RELIC, RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_6
# 351 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1:
# 354 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 355 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
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
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_9
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_8:
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
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_12
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_11:
# 328 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_MYTH
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_5:
# 331 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_GIRATINA_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 332 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_GIRATINA, FALSE
# 333 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 335 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_GIRATINA - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_15
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_14:
# 338 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_GIRATINA
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_6:
# 341 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_RELIC_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 342 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_RELIC, FALSE
# 343 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 345 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_RELIC - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_18
RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_17:
# 348 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_RELIC
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_1

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_9:
# 316 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_8

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_12:
# 326 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_11

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_15:
# 336 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_14

RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_18:
# 346 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh
	goto RustboroCity_DevonCorp_4F_EventScript_SelectSinnoh_17


RustboroCity_DevonCorp_4F_EventScript_SelectUnova::
# 359 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_UNOVA, FALSE
# 360 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 362 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 363 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_SWORDS, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_3
# 373 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_FORCES, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_4
# 383 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_TAO, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_5
# 393 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case UNOVA_CHOICE_KYUREM, RustboroCity_DevonCorp_4F_EventScript_SelectUnova_6
# 404 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1:
# 407 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 408 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_3:
# 364 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_SWORDS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 365 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_SWORDS, FALSE
# 366 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 368 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_SWORDS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_9
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_8:
# 371 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_SWORDS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_4:
# 374 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_FORCES_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 375 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_FORCES, FALSE
# 376 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 378 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_FORCES - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_12
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_11:
# 381 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_FORCES
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_5:
# 384 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAO_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 385 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAO, FALSE
# 386 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 388 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAO - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_15
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_14:
# 391 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAO
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_6:
# 394 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_KYUREM_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 395 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KYUREM, FALSE
# 396 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 398 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_KYUREM - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectUnova_18
RustboroCity_DevonCorp_4F_EventScript_SelectUnova_17:
# 401 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_KYUREM
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_1

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_9:
# 369 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_8

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_12:
# 379 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_11

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_15:
# 389 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_14

RustboroCity_DevonCorp_4F_EventScript_SelectUnova_18:
# 399 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova
	goto RustboroCity_DevonCorp_4F_EventScript_SelectUnova_17


RustboroCity_DevonCorp_4F_EventScript_SelectKalos::
# 412 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_KALOS, FALSE
# 413 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 415 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 416 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case KALOS_CHOICE_AURA, RustboroCity_DevonCorp_4F_EventScript_SelectKalos_3
# 427 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectKalos_1:
# 430 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 431 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectKalos_3:
# 417 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_AURA_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 418 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_AURA, FALSE
# 419 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 421 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_AURA - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectKalos_6
RustboroCity_DevonCorp_4F_EventScript_SelectKalos_5:
# 424 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_AURA
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos_1

RustboroCity_DevonCorp_4F_EventScript_SelectKalos_6:
# 422 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos
	goto RustboroCity_DevonCorp_4F_EventScript_SelectKalos_5


RustboroCity_DevonCorp_4F_EventScript_SelectAlola::
# 435 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_ALOLA, FALSE
# 436 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 438 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_RESULT
# 439 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_TAPUS, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_3
# 449 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_TYPENULL, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_4
# 459 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_COSMOG, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_5
# 469 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case ALOLA_CHOICE_NECROZMA, RustboroCity_DevonCorp_4F_EventScript_SelectAlola_6
# 480 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectRegion
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1:
# 483 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 484 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny
	return

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_3:
# 440 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TAPUS_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 441 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TAPUS, FALSE
# 442 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 444 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TAPUS - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_9
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_8:
# 447 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TAPUS
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_4:
# 450 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_TYPENULL_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 451 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_TYPENULL, FALSE
# 452 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 454 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_TYPENULL - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_12
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_11:
# 457 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_TYPENULL
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_5:
# 460 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_COSMOG_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 461 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_COSMOG, FALSE
# 462 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 464 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_COSMOG - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_15
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_14:
# 467 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_COSMOG
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_6:
# 470 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto_if_set FLAG_OBTAINED_NECROZMA_LINE, RustboroCity_DevonCorp_4F_EventScript_HasMon
# 471 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoice 0, 0, MULTI_MINI_LEGEND_NECROZMA, FALSE
# 472 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
# 474 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, NUM_CHOICES_NECROZMA - 1
	goto_if_gt RustboroCity_DevonCorp_4F_EventScript_SelectAlola_18
RustboroCity_DevonCorp_4F_EventScript_SelectAlola_17:
# 477 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	addvar VAR_RESULT, OFFSET_NECROZMA
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_1

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_9:
# 445 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_8

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_12:
# 455 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_11

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_15:
# 465 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_14

RustboroCity_DevonCorp_4F_EventScript_SelectAlola_18:
# 475 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola
	goto RustboroCity_DevonCorp_4F_EventScript_SelectAlola_17


RustboroCity_DevonCorp_4F_EventScript_OfferShiny::
# 488 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_2, 0
# 489 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_0
# 490 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	showmoneybox 0, 0
# 491 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_ShinyOffer
# 492 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 494 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_OfferShiny_2
# 514 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 515 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_2
RustboroCity_DevonCorp_4F_EventScript_OfferShiny_1:
# 519 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_0x8004, ITEM_UNSTABLE_DNA
# 520 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 522 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary
	return

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_2:
# 496 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	checkmoney 50000
# 498 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_OfferShiny_5
# 506 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 507 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_ShinyNoMoney
# 508 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 509 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_5:
# 499 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	removemoney 50000
# 500 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playse SE_SHOP
# 501 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitse
# 502 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	hidemoneybox
# 503 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_2, 1
# 504 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_1
	goto RustboroCity_DevonCorp_4F_EventScript_OfferShiny_1


RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd::
# 526 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd_Text_0
# 527 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 528 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_HasMon::
# 532 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_HasMonLine
# 533 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 534 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_GiveLegendary::
# 538 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	switch VAR_TEMP_1
# 544 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 0, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_3
# 552 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 1, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_4
# 560 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 2, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_5
# 568 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 3, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_6
# 576 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 4, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_7
# 584 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 5, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_8
# 592 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 6, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_9
# 600 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 7, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_10
# 608 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 8, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_11
# 616 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 9, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_12
# 624 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 10, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_13
# 632 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 11, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_14
# 640 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 12, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_15
# 648 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 13, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_16
# 656 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 14, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_17
# 664 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 15, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_18
# 672 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 16, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_19
# 680 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 17, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_20
# 688 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 18, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_21
# 696 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 19, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_22
# 704 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 20, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_23
# 712 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 21, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_24
# 720 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 22, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_25
# 728 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 23, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_26
# 736 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 24, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_27
# 744 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 25, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_28
# 752 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 26, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_29
# 760 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 27, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_30
# 768 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 28, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_31
# 776 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 29, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_32
# 784 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 30, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_33
# 792 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 31, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_34
# 800 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 32, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_35
# 808 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 33, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_36
# 816 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 34, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_37
# 824 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 35, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_38
# 832 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 36, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_39
# 840 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 37, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_40
# 848 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 38, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_41
# 856 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 39, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_42
# 864 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 40, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_43
# 872 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 41, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_44
# 880 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 42, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_45
# 888 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 43, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_46
# 896 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	case 44, RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_47
# 906 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1:
# 910 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_ne RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_50
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_49:
# 929 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_188
# 936 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_189
# 944 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_187:
# 947 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_2
# 948 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_RESULT, 0
# 949 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_3:
# 545 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MEWTWO_V
# 546 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MEWTWO_V
# 547 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MEWTWO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 548 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_53
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_52:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_4:
# 553 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ARTICUNO_V
# 554 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARTICUNO_V
# 555 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ARTICUNO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 556 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_56
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_55:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_5:
# 561 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZAPDOS_V
# 562 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZAPDOS_V
# 563 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZAPDOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 564 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_59
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_58:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_6:
# 569 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLTRES_V
# 570 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MOLTRES_V
# 571 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MOLTRES_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 572 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_62
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_61:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_7:
# 577 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAIKOU_V
# 578 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAIKOU_V
# 579 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RAIKOU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 580 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_65
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_64:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_8:
# 585 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI_V
# 586 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ENTEI_V
# 587 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ENTEI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 588 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_68
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_67:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_9:
# 593 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE_V
# 594 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SUICUNE_V
# 595 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_SUICUNE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 596 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_71
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_70:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_10:
# 601 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_V
# 602 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LUGIA_V
# 603 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LUGIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 604 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_74
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_73:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_11:
# 609 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH_V
# 610 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HO_OH_V
# 611 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_HO_OH_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 612 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_77
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_76:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_12:
# 617 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIROCK_V
# 618 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIROCK_V
# 619 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGIROCK_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 620 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_80
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_79:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_13:
# 625 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGICE_V
# 626 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGICE_V
# 627 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGICE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 628 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_83
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_82:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_14:
# 633 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGISTEEL_V
# 634 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGISTEEL_V
# 635 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGISTEEL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 636 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_86
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_85:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_15:
# 641 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIAS_V
# 642 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIAS_V
# 643 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LATIAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 644 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_89
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_88:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_16:
# 649 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LATIOS_V
# 650 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LATIOS_V
# 651 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LATIOS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 652 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_92
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_91:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_17:
# 657 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYOGRE_V
# 658 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYOGRE_V
# 659 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_KYOGRE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 660 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_95
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_94:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_18:
# 665 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROUDON_V
# 666 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GROUDON_V
# 667 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_GROUDON_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 668 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_98
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_97:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_19:
# 673 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RAYQUAZA_V
# 674 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RAYQUAZA_V
# 675 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RAYQUAZA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 676 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_101
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_100:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_20:
# 681 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_UXIE_V
# 682 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_UXIE_V
# 683 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_UXIE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 684 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_104
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_103:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_21:
# 689 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MESPRIT_V
# 690 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MESPRIT_V
# 691 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_MESPRIT_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 692 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_107
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_106:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_22:
# 697 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AZELF_V
# 698 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AZELF_V
# 699 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_AZELF_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 700 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_110
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_109:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_23:
# 705 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIALGA_V
# 706 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DIALGA_V
# 707 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_DIALGA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 708 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_113
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_112:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_24:
# 713 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PALKIA_V
# 714 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PALKIA_V
# 715 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_PALKIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 716 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_116
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_115:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_25:
# 721 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GIRATINA_V_ALTERED
# 722 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GIRATINA_V_ALTERED
# 723 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_GIRATINA_V_ALTERED, 5, ITEM_NONE, ITEM_BEAST_BALL
# 724 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_119
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_118:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_26:
# 729 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEATRAN_V
# 730 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_HEATRAN_V
# 731 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_HEATRAN_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 732 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_122
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_121:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_27:
# 737 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_REGIGIGAS_V
# 738 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_REGIGIGAS_V
# 739 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_REGIGIGAS_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 740 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_125
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_124:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_28:
# 745 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CRESSELIA_V
# 746 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CRESSELIA_V
# 747 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_CRESSELIA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 748 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_128
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_127:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_29:
# 753 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COBALION_V
# 754 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COBALION_V
# 755 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_COBALION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 756 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_131
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_130:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_30:
# 761 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TERRAKION_V
# 762 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TERRAKION_V
# 763 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TERRAKION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 764 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_134
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_133:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_31:
# 769 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_VIRIZION_V
# 770 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_VIRIZION_V
# 771 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_VIRIZION_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 772 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_137
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_136:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_32:
# 777 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TORNADUS_V_INCARNATE
# 778 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORNADUS_V_INCARNATE
# 779 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TORNADUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 780 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_140
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_139:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_33:
# 785 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_THUNDURUS_V_INCARNATE
# 786 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_THUNDURUS_V_INCARNATE
# 787 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_THUNDURUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 788 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_143
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_142:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_34:
# 793 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LANDORUS_V_INCARNATE
# 794 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LANDORUS_V_INCARNATE
# 795 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_LANDORUS_V_INCARNATE, 5, ITEM_NONE, ITEM_BEAST_BALL
# 796 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_146
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_145:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_35:
# 801 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_RESHIRAM_V
# 802 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RESHIRAM_V
# 803 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_RESHIRAM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 804 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_149
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_148:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_36:
# 809 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZEKROM_V
# 810 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZEKROM_V
# 811 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZEKROM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 812 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_152
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_151:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_37:
# 817 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KYUREM_V
# 818 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KYUREM_V
# 819 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_KYUREM_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 820 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_155
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_154:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_38:
# 825 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_XERNEAS_V_NEUTRAL
# 826 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_XERNEAS_V_NEUTRAL
# 827 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_XERNEAS_V_NEUTRAL, 5, ITEM_NONE, ITEM_BEAST_BALL
# 828 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_158
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_157:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_39:
# 833 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_YVELTAL_V
# 834 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_YVELTAL_V
# 835 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_YVELTAL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 836 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_161
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_160:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_40:
# 841 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ZYGARDE_V
# 842 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ZYGARDE_V
# 843 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_ZYGARDE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 844 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_164
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_163:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_41:
# 849 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_KOKO_V
# 850 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_KOKO_V
# 851 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_KOKO_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 852 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_167
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_166:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_42:
# 857 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_LELE_V
# 858 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_LELE_V
# 859 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_LELE_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 860 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_170
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_169:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_43:
# 865 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_BULU_V
# 866 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_BULU_V
# 867 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_BULU_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 868 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_173
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_172:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_44:
# 873 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TAPU_FINI_V
# 874 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TAPU_FINI_V
# 875 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TAPU_FINI_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 876 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_176
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_175:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_45:
# 881 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYPE_NULL_V
# 882 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYPE_NULL_V
# 883 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_TYPE_NULL_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 884 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_179
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_178:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_46:
# 889 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_COSMOG_V
# 890 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_COSMOG_V
# 891 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_COSMOG_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 892 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_182
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_181:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_47:
# 897 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NECROZMA_V
# 898 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_NECROZMA_V
# 899 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	givemon SPECIES_NECROZMA_V, 5, ITEM_NONE, ITEM_BEAST_BALL
# 900 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_lt RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_185
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_184:
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_1

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_50:
# 912 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_TEMP_2, 1
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_194
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_193:
# 917 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playmoncry VAR_TEMP_TRANSFERRED_SPECIES, CRY_MODE_ENCOUNTER
# 918 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 1
# 919 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_0
# 920 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	fadescreenspeed FADE_FROM_BLACK, 1
# 921 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmoncry
# 923 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 924 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	message RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_1
# 925 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitmessage
# 926 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	waitfanfare
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_49

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_53:
# 549 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MEWTWO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_52

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_56:
# 557 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_55

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_59:
# 565 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_58

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_62:
# 573 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BIRD_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_61

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_65:
# 581 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_64

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_68:
# 589 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_67

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_71:
# 597 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_BEASTS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_70

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_74:
# 605 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_73

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_77:
# 613 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TOWER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_76

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_80:
# 621 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_79

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_83:
# 629 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_82

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_86:
# 637 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_REGI_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_85

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_89:
# 645 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_88

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_92:
# 653 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_EON_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_91

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_95:
# 661 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_94

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_98:
# 669 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_97

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_101:
# 677 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_WEATHER_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_100

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_104:
# 685 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_103

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_107:
# 693 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_106

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_110:
# 701 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_LAKE_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_109

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_113:
# 709 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_112

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_116:
# 717 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_MYTH_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_115

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_119:
# 725 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_GIRATINA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_118

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_122:
# 733 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_121

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_125:
# 741 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_124

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_128:
# 749 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_RELIC_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_127

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_131:
# 757 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_130

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_134:
# 765 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_133

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_137:
# 773 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_SWORDS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_136

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_140:
# 781 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_139

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_143:
# 789 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_142

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_146:
# 797 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_FORCES_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_145

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_149:
# 805 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_148

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_152:
# 813 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAO_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_151

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_155:
# 821 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_KYUREM_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_154

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_158:
# 829 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_157

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_161:
# 837 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_160

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_164:
# 845 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_AURA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_163

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_167:
# 853 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_166

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_170:
# 861 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_169

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_173:
# 869 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_172

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_176:
# 877 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TAPUS_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_175

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_179:
# 885 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_TYPENULL_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_178

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_182:
# 893 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_COSMOG_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_181

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_185:
# 901 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	setflag FLAG_OBTAINED_NECROZMA_LINE
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_184

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_188:
# 930 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 931 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_197
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_196:
# 935 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_187

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_189:
# 937 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 938 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 939 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_200
RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_199:
# 942 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	closemessage
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_187

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_194:
# 913 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	callnative Script_SetLastGiftMonShiny
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_193

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_197:
# 932 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 933 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_196

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_200:
# 940 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_199


RustboroCity_DevonCorp_4F_EventScript_TableProtoLegends::
# 953 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 954 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_TableProtoLegends
# 955 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_MonitorMutations::
# 959 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 960 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_MonitorMutations
# 961 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_DisplayGeneticLines::
# 965 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 966 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DisplayGeneticLines
# 967 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	releaseall
	return


RustboroCity_DevonCorp_4F_EventScript_DisplayExperiment::
# 971 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	lockall
# 972 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	msgbox RustboroCity_DevonCorp_4F_Text_DisplayExperiment
# 973 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
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
# 489 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Oh, I almost forgot!$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_1:
# 504 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "Excellent! I'll prepare a special\n"
	.string "variant for you.$"

RustboroCity_DevonCorp_4F_EventScript_OfferShiny_Text_2:
# 515 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "OK, I'll get to work...$"

RustboroCity_DevonCorp_4F_EventScript_DrParkerEnd_Text_0:
# 526 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "If you come across any Unstable DNA\n"
	.string "samples, please come see me!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_0:
# 919 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{STR_VAR_1} materialized from the\n"
	.string "Unstable DNA!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_1:
# 924 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"

RustboroCity_DevonCorp_4F_EventScript_GiveLegendary_Text_2:
# 947 "data/maps/RustboroCity_DevonCorp_4F/scripts.pory"
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
