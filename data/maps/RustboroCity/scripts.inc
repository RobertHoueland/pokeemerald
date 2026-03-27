# 1 "data/maps/RustboroCity/scripts.pory"

# 2 "data/maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 3 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 4 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 5 "data/maps/RustboroCity/scripts.pory"
	.byte 0
# 6 "data/maps/RustboroCity/scripts.pory"

# 7 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 8 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 9 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
# 10 "data/maps/RustboroCity/scripts.pory"
	end
# 11 "data/maps/RustboroCity/scripts.pory"

# 12 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 13 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
# 14 "data/maps/RustboroCity/scripts.pory"
	end
# 15 "data/maps/RustboroCity/scripts.pory"

# 16 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 17 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 18 "data/maps/RustboroCity/scripts.pory"
	return
# 19 "data/maps/RustboroCity/scripts.pory"

# 20 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 21 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 22 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_GYM_STATE, 2, RustboroCity_EventScript_DrParkerIntro
# 23 "data/maps/RustboroCity/scripts.pory"
    .2byte 0
# 24 "data/maps/RustboroCity/scripts.pory"

# 25 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 26 "data/maps/RustboroCity/scripts.pory"
	lockall
# 27 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 28 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 29 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 30 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 31 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 32 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_SCIENTIST
# 33 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 34 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 35 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 36 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_ExclamationMark
# 37 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 38 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_Delay48
# 39 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 40 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 41 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 42 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 43 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 44 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 45 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 46 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 47 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 48 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 49 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 50 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 51 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 52 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 53 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 54 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 55 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 56 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 57 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 58 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 59 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 60 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 61 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 62 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 63 "data/maps/RustboroCity/scripts.pory"

# 64 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 65 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 66 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 67 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 68 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 69 "data/maps/RustboroCity/scripts.pory"

# 70 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 71 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 72 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 73 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 74 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 75 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 76 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 77 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 78 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 79 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 80 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 81 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 82 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 83 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 84 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 85 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 86 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 87 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 88 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 89 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 90 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 91 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_SCIENTIST
# 92 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 93 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 94 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 95 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 96 "data/maps/RustboroCity/scripts.pory"
	end
# 97 "data/maps/RustboroCity/scripts.pory"

# 98 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 99 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 100 "data/maps/RustboroCity/scripts.pory"
	step_end
# 101 "data/maps/RustboroCity/scripts.pory"

# 102 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 103 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 104 "data/maps/RustboroCity/scripts.pory"
	step_end
# 105 "data/maps/RustboroCity/scripts.pory"

# 106 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 107 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 108 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 109 "data/maps/RustboroCity/scripts.pory"
	step_end
# 110 "data/maps/RustboroCity/scripts.pory"

# 111 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 112 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 113 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 114 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 115 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 116 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 117 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 118 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 119 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 120 "data/maps/RustboroCity/scripts.pory"
	step_end
# 121 "data/maps/RustboroCity/scripts.pory"

# 122 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 123 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 124 "data/maps/RustboroCity/scripts.pory"
	step_end
# 125 "data/maps/RustboroCity/scripts.pory"

# 126 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 127 "data/maps/RustboroCity/scripts.pory"
	lock
# 128 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 129 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 130 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 131 "data/maps/RustboroCity/scripts.pory"
	release
# 132 "data/maps/RustboroCity/scripts.pory"
	end
# 133 "data/maps/RustboroCity/scripts.pory"

# 134 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 135 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 136 "data/maps/RustboroCity/scripts.pory"
	release
# 137 "data/maps/RustboroCity/scripts.pory"
	end
# 138 "data/maps/RustboroCity/scripts.pory"

# 139 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 140 "data/maps/RustboroCity/scripts.pory"
	lock
# 141 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 142 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 143 "data/maps/RustboroCity/scripts.pory"
	release
# 144 "data/maps/RustboroCity/scripts.pory"
	end
# 145 "data/maps/RustboroCity/scripts.pory"

# 146 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 147 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 148 "data/maps/RustboroCity/scripts.pory"
	end
# 149 "data/maps/RustboroCity/scripts.pory"

# 150 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 151 "data/maps/RustboroCity/scripts.pory"
	lock
# 152 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 153 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 154 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 155 "data/maps/RustboroCity/scripts.pory"
	release
# 156 "data/maps/RustboroCity/scripts.pory"
	end
# 157 "data/maps/RustboroCity/scripts.pory"

# 158 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 159 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 160 "data/maps/RustboroCity/scripts.pory"
	release
# 161 "data/maps/RustboroCity/scripts.pory"
	end
# 162 "data/maps/RustboroCity/scripts.pory"

# 163 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 164 "data/maps/RustboroCity/scripts.pory"
	lock
# 165 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 166 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 167 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 168 "data/maps/RustboroCity/scripts.pory"
	release
# 169 "data/maps/RustboroCity/scripts.pory"
	end
# 170 "data/maps/RustboroCity/scripts.pory"

# 171 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 172 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 173 "data/maps/RustboroCity/scripts.pory"
	release
# 174 "data/maps/RustboroCity/scripts.pory"
	end
# 175 "data/maps/RustboroCity/scripts.pory"

# 176 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 177 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 178 "data/maps/RustboroCity/scripts.pory"
	end
# 179 "data/maps/RustboroCity/scripts.pory"

# 180 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 181 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 182 "data/maps/RustboroCity/scripts.pory"
	end
# 183 "data/maps/RustboroCity/scripts.pory"

# 184 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 185 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 186 "data/maps/RustboroCity/scripts.pory"
	end
# 187 "data/maps/RustboroCity/scripts.pory"

# 188 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 189 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 190 "data/maps/RustboroCity/scripts.pory"
	end
# 191 "data/maps/RustboroCity/scripts.pory"

# 192 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 193 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 194 "data/maps/RustboroCity/scripts.pory"
	end
# 195 "data/maps/RustboroCity/scripts.pory"

# 196 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 197 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 198 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 199 "data/maps/RustboroCity/scripts.pory"
	end
# 200 "data/maps/RustboroCity/scripts.pory"

# 201 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 202 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 203 "data/maps/RustboroCity/scripts.pory"
	end
# 204 "data/maps/RustboroCity/scripts.pory"

# 205 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 206 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 207 "data/maps/RustboroCity/scripts.pory"
	end
# 208 "data/maps/RustboroCity/scripts.pory"

# 209 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 210 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 211 "data/maps/RustboroCity/scripts.pory"
	end
# 212 "data/maps/RustboroCity/scripts.pory"

# 213 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 214 "data/maps/RustboroCity/scripts.pory"
	lock
# 215 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 216 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 217 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 218 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 219 "data/maps/RustboroCity/scripts.pory"
	release
# 220 "data/maps/RustboroCity/scripts.pory"
	end
# 221 "data/maps/RustboroCity/scripts.pory"

# 222 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 223 "data/maps/RustboroCity/scripts.pory"
	lock
# 224 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 225 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 226 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 227 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 228 "data/maps/RustboroCity/scripts.pory"
	release
# 229 "data/maps/RustboroCity/scripts.pory"
	end
# 230 "data/maps/RustboroCity/scripts.pory"

# 231 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 232 "data/maps/RustboroCity/scripts.pory"
	lock
# 233 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 234 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 235 "data/maps/RustboroCity/scripts.pory"
	release
# 236 "data/maps/RustboroCity/scripts.pory"
	end
# 237 "data/maps/RustboroCity/scripts.pory"

# 238 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 239 "data/maps/RustboroCity/scripts.pory"
	lockall
# 240 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 241 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 242 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 243 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 244 "data/maps/RustboroCity/scripts.pory"
	end
# 245 "data/maps/RustboroCity/scripts.pory"

# 246 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 247 "data/maps/RustboroCity/scripts.pory"
	lockall
# 248 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 249 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 250 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 251 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 252 "data/maps/RustboroCity/scripts.pory"
	end
# 253 "data/maps/RustboroCity/scripts.pory"

# 254 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 255 "data/maps/RustboroCity/scripts.pory"
	lockall
# 256 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 257 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 258 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 259 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 260 "data/maps/RustboroCity/scripts.pory"
	end
# 261 "data/maps/RustboroCity/scripts.pory"

# 262 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 263 "data/maps/RustboroCity/scripts.pory"
	lockall
# 264 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 265 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 266 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 267 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 268 "data/maps/RustboroCity/scripts.pory"
	end
# 269 "data/maps/RustboroCity/scripts.pory"

# 270 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 271 "data/maps/RustboroCity/scripts.pory"
	lockall
# 272 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 14, 21
# 273 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 274 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 275 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 276 "data/maps/RustboroCity/scripts.pory"
	end
# 277 "data/maps/RustboroCity/scripts.pory"

# 278 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 279 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 280 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 281 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 282 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_GRUNT
# 283 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 284 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_GRUNT, RustboroCity_Movement_GruntEscape
# 285 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 286 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_GRUNT
# 287 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 288 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 289 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 290 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 291 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 292 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 293 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 294 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 295 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_RUSTBORO_DEVON_EMPLOYEE, 30, 10
# 296 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 297 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 298 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 299 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 300 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 301 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 302 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 303 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 304 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 305 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 306 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 307 "data/maps/RustboroCity/scripts.pory"
	end
# 308 "data/maps/RustboroCity/scripts.pory"

# 309 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 310 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 311 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 312 "data/maps/RustboroCity/scripts.pory"
	return
# 313 "data/maps/RustboroCity/scripts.pory"

# 314 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 315 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 316 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 317 "data/maps/RustboroCity/scripts.pory"
	return
# 318 "data/maps/RustboroCity/scripts.pory"

# 319 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 320 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 321 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 322 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 323 "data/maps/RustboroCity/scripts.pory"
	return
# 324 "data/maps/RustboroCity/scripts.pory"

# 325 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 326 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 327 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 328 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 329 "data/maps/RustboroCity/scripts.pory"
	return
# 330 "data/maps/RustboroCity/scripts.pory"

# 331 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 332 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 333 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 334 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 335 "data/maps/RustboroCity/scripts.pory"
	return
# 336 "data/maps/RustboroCity/scripts.pory"

# 337 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 338 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 339 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 340 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 341 "data/maps/RustboroCity/scripts.pory"
	return
# 342 "data/maps/RustboroCity/scripts.pory"

# 343 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 344 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 345 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 346 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 347 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 348 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 349 "data/maps/RustboroCity/scripts.pory"
	return
# 350 "data/maps/RustboroCity/scripts.pory"

# 351 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 352 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 353 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 354 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 355 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 356 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 357 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 358 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 359 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 360 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 361 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 362 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 363 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 364 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 365 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 367 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 368 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 369 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 370 "data/maps/RustboroCity/scripts.pory"
	step_end
# 371 "data/maps/RustboroCity/scripts.pory"

# 372 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 373 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 374 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 375 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 376 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 377 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 378 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 379 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 380 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 381 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 382 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 383 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 384 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 385 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 386 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 387 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 388 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 389 "data/maps/RustboroCity/scripts.pory"
	step_end
# 390 "data/maps/RustboroCity/scripts.pory"

# 391 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 392 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 393 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 394 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 395 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 396 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 397 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 398 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 399 "data/maps/RustboroCity/scripts.pory"
	step_end
# 400 "data/maps/RustboroCity/scripts.pory"

# 401 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 402 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 404 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 405 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 406 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 407 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 408 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 409 "data/maps/RustboroCity/scripts.pory"
	step_end
# 410 "data/maps/RustboroCity/scripts.pory"

# 411 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 412 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 413 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 414 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 415 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 416 "data/maps/RustboroCity/scripts.pory"
	step_end
# 417 "data/maps/RustboroCity/scripts.pory"

# 418 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 419 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 420 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 421 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 422 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 423 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 424 "data/maps/RustboroCity/scripts.pory"
	step_end
# 425 "data/maps/RustboroCity/scripts.pory"

# 426 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 427 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 428 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 429 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 430 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 431 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 432 "data/maps/RustboroCity/scripts.pory"
	step_end
# 433 "data/maps/RustboroCity/scripts.pory"

# 434 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 435 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 436 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 437 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 438 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 439 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 440 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 441 "data/maps/RustboroCity/scripts.pory"
	step_end
# 442 "data/maps/RustboroCity/scripts.pory"

# 443 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 444 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 445 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 446 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 447 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 448 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 449 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 450 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 451 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 452 "data/maps/RustboroCity/scripts.pory"
	step_end
# 453 "data/maps/RustboroCity/scripts.pory"

# 454 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1::
# 455 "data/maps/RustboroCity/scripts.pory"
	lock
# 456 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 457 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 458 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 459 "data/maps/RustboroCity/scripts.pory"
	release
# 460 "data/maps/RustboroCity/scripts.pory"
	end
# 461 "data/maps/RustboroCity/scripts.pory"

# 462 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 463 "data/maps/RustboroCity/scripts.pory"
	waitse
# 464 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 465 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 466 "data/maps/RustboroCity/scripts.pory"
	end
# 467 "data/maps/RustboroCity/scripts.pory"

# 468 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 469 "data/maps/RustboroCity/scripts.pory"
	lockall
# 470 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 471 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 472 "data/maps/RustboroCity/scripts.pory"
	end
# 473 "data/maps/RustboroCity/scripts.pory"

# 474 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 475 "data/maps/RustboroCity/scripts.pory"
	lockall
# 476 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 477 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 478 "data/maps/RustboroCity/scripts.pory"
	end
# 479 "data/maps/RustboroCity/scripts.pory"

# 480 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 481 "data/maps/RustboroCity/scripts.pory"
	lockall
# 482 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 483 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 484 "data/maps/RustboroCity/scripts.pory"
	end
# 485 "data/maps/RustboroCity/scripts.pory"

# 486 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 487 "data/maps/RustboroCity/scripts.pory"
	lockall
# 488 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 489 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 490 "data/maps/RustboroCity/scripts.pory"
	end
# 491 "data/maps/RustboroCity/scripts.pory"

# 492 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods::
# 493 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 494 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 495 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 496 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 497 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 498 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 499 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE
# 500 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 501 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 502 "data/maps/RustboroCity/scripts.pory"
	end
# 503 "data/maps/RustboroCity/scripts.pory"

# 504 "data/maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 505 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 506 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 507 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 508 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 509 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 510 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 511 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 512 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 513 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 514 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 515 "data/maps/RustboroCity/scripts.pory"
	return
# 516 "data/maps/RustboroCity/scripts.pory"

# 517 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 518 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 519 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 520 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 521 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 522 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 523 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 524 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 525 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 526 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 527 "data/maps/RustboroCity/scripts.pory"
	return
# 528 "data/maps/RustboroCity/scripts.pory"

# 529 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 530 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 531 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 532 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 533 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 534 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 535 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 536 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 537 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 538 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 539 "data/maps/RustboroCity/scripts.pory"
	return
# 540 "data/maps/RustboroCity/scripts.pory"

# 541 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 542 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 543 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 544 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 545 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 546 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 547 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 548 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 549 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 550 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 551 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 552 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 553 "data/maps/RustboroCity/scripts.pory"
	return
# 554 "data/maps/RustboroCity/scripts.pory"

# 555 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 556 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 557 "data/maps/RustboroCity/scripts.pory"
	step_end
# 558 "data/maps/RustboroCity/scripts.pory"

# 559 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 560 "data/maps/RustboroCity/scripts.pory"
	lockall
# 561 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 562 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 563 "data/maps/RustboroCity/scripts.pory"
	end
# 564 "data/maps/RustboroCity/scripts.pory"

# 565 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 566 "data/maps/RustboroCity/scripts.pory"
	lockall
# 567 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 568 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 569 "data/maps/RustboroCity/scripts.pory"
	end
# 570 "data/maps/RustboroCity/scripts.pory"

# 571 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 572 "data/maps/RustboroCity/scripts.pory"
	lockall
# 573 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 574 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 575 "data/maps/RustboroCity/scripts.pory"
	end
# 576 "data/maps/RustboroCity/scripts.pory"

# 577 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 578 "data/maps/RustboroCity/scripts.pory"
	lockall
# 579 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 580 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 581 "data/maps/RustboroCity/scripts.pory"
	end
# 582 "data/maps/RustboroCity/scripts.pory"

# 583 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 584 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 585 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 586 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 587 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 588 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 589 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 590 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 591 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 592 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 593 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 594 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 595 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 596 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 597 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 598 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 599 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 600 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 601 "data/maps/RustboroCity/scripts.pory"
	end
# 602 "data/maps/RustboroCity/scripts.pory"

# 603 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 604 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 605 "data/maps/RustboroCity/scripts.pory"
	return
# 606 "data/maps/RustboroCity/scripts.pory"

# 607 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 608 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 609 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 610 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 611 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 612 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 613 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 614 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 615 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 616 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 617 "data/maps/RustboroCity/scripts.pory"
	return
# 618 "data/maps/RustboroCity/scripts.pory"

# 619 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 620 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 621 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 622 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 623 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 624 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 625 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 626 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 627 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
# 628 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 629 "data/maps/RustboroCity/scripts.pory"
	return
# 630 "data/maps/RustboroCity/scripts.pory"

# 631 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 632 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 633 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 634 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 635 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 636 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 637 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 638 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 639 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 640 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 641 "data/maps/RustboroCity/scripts.pory"
	return
# 642 "data/maps/RustboroCity/scripts.pory"

# 643 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 644 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 645 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 646 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 647 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 648 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 649 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 650 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 651 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 652 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 653 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 654 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 655 "data/maps/RustboroCity/scripts.pory"
	return
# 656 "data/maps/RustboroCity/scripts.pory"

# 657 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 658 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 659 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 660 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 661 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 662 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 663 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DEVON_EMPLOYEE, Common_Movement_Delay48
# 664 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 665 "data/maps/RustboroCity/scripts.pory"
	return
# 666 "data/maps/RustboroCity/scripts.pory"

# 667 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 668 "data/maps/RustboroCity/scripts.pory"
	lockall
# 669 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 670 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
# 671 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 672 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 673 "data/maps/RustboroCity/scripts.pory"

# 674 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 675 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 676 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 677 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 678 "data/maps/RustboroCity/scripts.pory"
	return
# 679 "data/maps/RustboroCity/scripts.pory"

# 680 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 681 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 682 "data/maps/RustboroCity/scripts.pory"
	return
# 683 "data/maps/RustboroCity/scripts.pory"

# 684 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 685 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 686 "data/maps/RustboroCity/scripts.pory"
	return
# 687 "data/maps/RustboroCity/scripts.pory"

# 688 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 689 "data/maps/RustboroCity/scripts.pory"
	lockall
# 690 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 691 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 692 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 693 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 694 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 695 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 696 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 697 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 698 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 699 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 700 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 701 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 702 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 703 "data/maps/RustboroCity/scripts.pory"

# 704 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 705 "data/maps/RustboroCity/scripts.pory"
	lockall
# 706 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 707 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 708 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 709 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 710 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 711 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 712 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 713 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 714 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 715 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 716 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 717 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 718 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 719 "data/maps/RustboroCity/scripts.pory"

# 720 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 721 "data/maps/RustboroCity/scripts.pory"
	lockall
# 722 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 723 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 724 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 725 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 726 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 727 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 728 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 729 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 730 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 731 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 732 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 733 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 734 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 735 "data/maps/RustboroCity/scripts.pory"

# 736 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 737 "data/maps/RustboroCity/scripts.pory"
	lockall
# 738 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 739 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 740 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 741 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 742 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 743 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 744 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 745 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 746 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 747 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 748 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 749 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 750 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 751 "data/maps/RustboroCity/scripts.pory"

# 752 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 753 "data/maps/RustboroCity/scripts.pory"
	lockall
# 754 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 755 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 756 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 757 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 758 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 759 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 760 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 761 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 762 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 763 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 764 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 765 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 766 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 767 "data/maps/RustboroCity/scripts.pory"

# 768 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 769 "data/maps/RustboroCity/scripts.pory"
	lockall
# 770 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 771 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 772 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 773 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 774 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 775 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 776 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 777 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 778 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 779 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 780 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 781 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 782 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 783 "data/maps/RustboroCity/scripts.pory"

# 784 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 785 "data/maps/RustboroCity/scripts.pory"
	lockall
# 786 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 787 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 788 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 789 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 790 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 791 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 792 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 793 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 794 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 795 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 796 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 797 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 798 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 799 "data/maps/RustboroCity/scripts.pory"

# 800 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 801 "data/maps/RustboroCity/scripts.pory"
	lockall
# 802 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 803 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 804 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 805 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 806 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
# 807 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 808 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
# 809 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 810 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 811 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 812 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 813 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 814 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 815 "data/maps/RustboroCity/scripts.pory"

# 816 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 817 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 818 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 819 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 820 "data/maps/RustboroCity/scripts.pory"
	end
# 821 "data/maps/RustboroCity/scripts.pory"

# 822 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 823 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 824 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 825 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 826 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 827 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 828 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 829 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 830 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 831 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 832 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 833 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 834 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 835 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 836 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 837 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 838 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 839 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 840 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 841 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 842 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 843 "data/maps/RustboroCity/scripts.pory"
	end
# 844 "data/maps/RustboroCity/scripts.pory"

# 845 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 846 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 847 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 848 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 849 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 850 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 851 "data/maps/RustboroCity/scripts.pory"
	end
# 852 "data/maps/RustboroCity/scripts.pory"

# 853 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 854 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 855 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 856 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 857 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 858 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 859 "data/maps/RustboroCity/scripts.pory"
	end
# 860 "data/maps/RustboroCity/scripts.pory"

# 861 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 862 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 863 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 864 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 865 "data/maps/RustboroCity/scripts.pory"
	end
# 866 "data/maps/RustboroCity/scripts.pory"

# 867 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 868 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 869 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 870 "data/maps/RustboroCity/scripts.pory"
	return
# 871 "data/maps/RustboroCity/scripts.pory"

# 872 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 873 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 874 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 875 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 876 "data/maps/RustboroCity/scripts.pory"
	end
# 877 "data/maps/RustboroCity/scripts.pory"

# 878 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 879 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 880 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 881 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 882 "data/maps/RustboroCity/scripts.pory"
	end
# 883 "data/maps/RustboroCity/scripts.pory"

# 884 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 885 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 886 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 887 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 888 "data/maps/RustboroCity/scripts.pory"
	end
# 889 "data/maps/RustboroCity/scripts.pory"

# 890 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 891 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 892 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 893 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 894 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 895 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 896 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 897 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 898 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 899 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 900 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 901 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 902 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 903 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 904 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 905 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 906 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 907 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 908 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 909 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 910 "data/maps/RustboroCity/scripts.pory"
	end
# 911 "data/maps/RustboroCity/scripts.pory"

# 912 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 913 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 914 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 915 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 916 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 917 "data/maps/RustboroCity/scripts.pory"
	end
# 918 "data/maps/RustboroCity/scripts.pory"

# 919 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 920 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 921 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 922 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 923 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 924 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 925 "data/maps/RustboroCity/scripts.pory"
	end
# 926 "data/maps/RustboroCity/scripts.pory"

# 927 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 928 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 929 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 930 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 931 "data/maps/RustboroCity/scripts.pory"
	end
# 932 "data/maps/RustboroCity/scripts.pory"

# 933 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 934 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 935 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 936 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 937 "data/maps/RustboroCity/scripts.pory"
	end
# 938 "data/maps/RustboroCity/scripts.pory"

# 939 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 940 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 941 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 942 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 943 "data/maps/RustboroCity/scripts.pory"
	end
# 944 "data/maps/RustboroCity/scripts.pory"

# 945 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 946 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 947 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 948 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 949 "data/maps/RustboroCity/scripts.pory"
	end
# 950 "data/maps/RustboroCity/scripts.pory"

# 951 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 952 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 953 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 954 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 955 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 956 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 957 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 958 "data/maps/RustboroCity/scripts.pory"
	step_end
# 959 "data/maps/RustboroCity/scripts.pory"

# 960 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 961 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 962 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 963 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 964 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 965 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 966 "data/maps/RustboroCity/scripts.pory"
	step_end
# 967 "data/maps/RustboroCity/scripts.pory"

# 968 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 969 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 970 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 971 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 972 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 973 "data/maps/RustboroCity/scripts.pory"
	step_end
# 974 "data/maps/RustboroCity/scripts.pory"

# 975 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 976 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 977 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 978 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 979 "data/maps/RustboroCity/scripts.pory"
	step_end
# 980 "data/maps/RustboroCity/scripts.pory"

# 981 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 982 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 983 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 984 "data/maps/RustboroCity/scripts.pory"
	step_end
# 985 "data/maps/RustboroCity/scripts.pory"

# 986 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 987 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 988 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 989 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 990 "data/maps/RustboroCity/scripts.pory"
	step_end
# 991 "data/maps/RustboroCity/scripts.pory"

# 992 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 993 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 994 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 995 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 996 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 997 "data/maps/RustboroCity/scripts.pory"
	step_end
# 998 "data/maps/RustboroCity/scripts.pory"

# 999 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1000 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1001 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1002 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1003 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1004 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1005 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1006 "data/maps/RustboroCity/scripts.pory"

# 1007 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1008 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1009 "data/maps/RustboroCity/scripts.pory"
	end
# 1010 "data/maps/RustboroCity/scripts.pory"

# 1011 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1012 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1013 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1014 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1015 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1016 "data/maps/RustboroCity/scripts.pory"

# 1017 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1018 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1019 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1020 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1021 "data/maps/RustboroCity/scripts.pory"

# 1022 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1023 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1024 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1025 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1026 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1027 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1028 "data/maps/RustboroCity/scripts.pory"

# 1029 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1030 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1031 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1032 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1033 "data/maps/RustboroCity/scripts.pory"

# 1034 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1035 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1036 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1037 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1038 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1039 "data/maps/RustboroCity/scripts.pory"

# 1040 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1041 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1042 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1043 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1044 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1045 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1046 "data/maps/RustboroCity/scripts.pory"

# 1047 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1048 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1049 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1050 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1051 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1052 "data/maps/RustboroCity/scripts.pory"

# 1053 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1054 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1055 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1056 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1057 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1058 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1059 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1060 "data/maps/RustboroCity/scripts.pory"

# 1061 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1062 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1063 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1064 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1065 "data/maps/RustboroCity/scripts.pory"

# 1066 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1067 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1068 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1069 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1070 "data/maps/RustboroCity/scripts.pory"

# 1071 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1072 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1073 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1074 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1075 "data/maps/RustboroCity/scripts.pory"

# 1076 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1077 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1078 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1079 "data/maps/RustboroCity/scripts.pory"

# 1080 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1081 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1082 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1083 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1084 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1085 "data/maps/RustboroCity/scripts.pory"

# 1086 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1087 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1088 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1089 "data/maps/RustboroCity/scripts.pory"

# 1090 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1091 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1092 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1093 "data/maps/RustboroCity/scripts.pory"

# 1094 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1095 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1096 "data/maps/RustboroCity/scripts.pory"
	.string "You're that fantastic TRAINER who\n"
# 1097 "data/maps/RustboroCity/scripts.pory"
	.string "helped me in PETALBURG WOODS!\p"
# 1098 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1099 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1100 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1101 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1102 "data/maps/RustboroCity/scripts.pory"

# 1103 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1104 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1105 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1106 "data/maps/RustboroCity/scripts.pory"

# 1107 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1108 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1109 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1110 "data/maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1111 "data/maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1112 "data/maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1113 "data/maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1114 "data/maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1115 "data/maps/RustboroCity/scripts.pory"

# 1116 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1117 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1118 "data/maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1119 "data/maps/RustboroCity/scripts.pory"

# 1120 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1121 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1122 "data/maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1123 "data/maps/RustboroCity/scripts.pory"

# 1124 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1125 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1126 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1127 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1128 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1129 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1130 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1131 "data/maps/RustboroCity/scripts.pory"

# 1132 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1133 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1134 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1135 "data/maps/RustboroCity/scripts.pory"

# 1136 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1137 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1138 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1139 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1140 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1141 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1142 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1143 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1144 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1145 "data/maps/RustboroCity/scripts.pory"

# 1146 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1147 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1148 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1149 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1150 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1151 "data/maps/RustboroCity/scripts.pory"

# 1152 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1153 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1154 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1155 "data/maps/RustboroCity/scripts.pory"

# 1156 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1157 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1158 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1159 "data/maps/RustboroCity/scripts.pory"

# 1160 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1161 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1162 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1163 "data/maps/RustboroCity/scripts.pory"

# 1164 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1165 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1166 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1167 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1168 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1169 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1170 "data/maps/RustboroCity/scripts.pory"

# 1171 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1172 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1173 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1174 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1175 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1176 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1177 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1178 "data/maps/RustboroCity/scripts.pory"

# 1179 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1180 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1181 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1182 "data/maps/RustboroCity/scripts.pory"

# 1183 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1184 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1185 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1186 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1187 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1188 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1189 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1190 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1191 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1192 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1193 "data/maps/RustboroCity/scripts.pory"

# 1194 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1195 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1196 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1197 "data/maps/RustboroCity/scripts.pory"

# 1198 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1199 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1200 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1201 "data/maps/RustboroCity/scripts.pory"

# 1202 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1203 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1204 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1205 "data/maps/RustboroCity/scripts.pory"

# 1206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1207 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1208 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1209 "data/maps/RustboroCity/scripts.pory"

# 1210 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1211 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1212 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1213 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1214 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1215 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1216 "data/maps/RustboroCity/scripts.pory"

# 1217 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1218 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1219 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1220 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1221 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1222 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1223 "data/maps/RustboroCity/scripts.pory"

# 1224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1225 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1226 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1227 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1228 "data/maps/RustboroCity/scripts.pory"

# 1229 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1230 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1231 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1232 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1233 "data/maps/RustboroCity/scripts.pory"

# 1234 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1235 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1236 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1237 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1238 "data/maps/RustboroCity/scripts.pory"

# 1239 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1240 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1241 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1242 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1243 "data/maps/RustboroCity/scripts.pory"

# 1244 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1245 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1246 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1247 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1248 "data/maps/RustboroCity/scripts.pory"

# 1249 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1250 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1251 "data/maps/RustboroCity/scripts.pory"

# 1252 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1253 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1254 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1255 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1256 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1257 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1258 "data/maps/RustboroCity/scripts.pory"

# 1259 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1260 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1261 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1262 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1263 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1264 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1265 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1266 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1267 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1268 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1269 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1270 "data/maps/RustboroCity/scripts.pory"

# 1271 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1272 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1273 "data/maps/RustboroCity/scripts.pory"

# 1274 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1275 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1276 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1277 "data/maps/RustboroCity/scripts.pory"

# 1278 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1279 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1280 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1281 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1282 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1283 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1284 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1285 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1286 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_OnTransition::
# 1290 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 1291 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 1292 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 6
	goto_if_eq RustboroCity_OnTransition_2
RustboroCity_OnTransition_1:
# 1295 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 1296 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 6
	goto_if_eq RustboroCity_OnTransition_5
RustboroCity_OnTransition_4:
# 1299 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_GYM_STATE, 1
	goto_if_eq RustboroCity_OnTransition_9
	return

RustboroCity_OnTransition_2:
# 1293 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_HideMapNamePopup
	goto RustboroCity_OnTransition_1

RustboroCity_OnTransition_5:
# 1297 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PositionScientistForExit
	goto RustboroCity_OnTransition_4

RustboroCity_OnTransition_7:
# 1301 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_GYM_STATE, 2
	return

RustboroCity_OnTransition_8:
# 1299 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 19
	goto_if_eq RustboroCity_OnTransition_7
	return

RustboroCity_OnTransition_9:
# 1299 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 27
	goto_if_eq RustboroCity_OnTransition_8
	return


RustboroCity_EventScript_DrParkerIntro::
# 1306 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1307 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DR_PARKER
# 1308 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RUSTBORO_DR_PARKER
# 1309 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_RUSTBORO_DR_PARKER, MOVEMENT_TYPE_FACE_RIGHT
# 1311 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_DrParkerIntro_Text_0
# 1312 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DR_PARKER, RustboroCity_EventScript_DrParkerIntro_Movement_0
# 1316 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1318 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DR_PARKER, RustboroCity_EventScript_DrParkerIntro_Movement_1
# 1329 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1331 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1332 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_DrParkerIntro_Text_1
# 1333 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_DrParkerIntro_Text_2
# 1334 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_DrParkerIntro_Text_3
# 1335 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_DrParkerIntro_Text_4
# 1336 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_DrParkerIntro_Text_5
# 1337 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1339 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RUSTBORO_DR_PARKER, RustboroCity_EventScript_DrParkerIntro_Movement_2
# 1342 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1344 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RUSTBORO_DR_PARKER
# 1345 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_GYM_STATE, 3
# 1346 "data/maps/RustboroCity/scripts.pory"
	releaseall
	return


# 1312 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DrParkerIntro_Movement_0:
# 1313 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 1313 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 1313 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1314 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 1318 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DrParkerIntro_Movement_1:
# 1319 "data/maps/RustboroCity/scripts.pory"
	face_up
# 1320 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1321 "data/maps/RustboroCity/scripts.pory"
	face_down
# 1322 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1323 "data/maps/RustboroCity/scripts.pory"
	face_left
# 1324 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1325 "data/maps/RustboroCity/scripts.pory"
	face_right
# 1326 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1327 "data/maps/RustboroCity/scripts.pory"
	face_player
	step_end

# 1339 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DrParkerIntro_Movement_2:
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_left
	step_end

RustboroCity_EventScript_DrParkerIntro_Text_0:
# 1311 "data/maps/RustboroCity/scripts.pory"
	.string "I know it's around here somewhere...$"

RustboroCity_EventScript_DrParkerIntro_Text_1:
# 1332 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, you're {PLAYER}?$"

RustboroCity_EventScript_DrParkerIntro_Text_2:
# 1333 "data/maps/RustboroCity/scripts.pory"
	.string "Did you happen to see anyone drop\n"
	.string "anything unusual around here?$"

RustboroCity_EventScript_DrParkerIntro_Text_3:
# 1334 "data/maps/RustboroCity/scripts.pory"
	.string "I'm DR. PARKER, a scientist over at\n"
	.string "DEVON CORPORATION.$"

RustboroCity_EventScript_DrParkerIntro_Text_4:
# 1335 "data/maps/RustboroCity/scripts.pory"
	.string "Just between you and me, I'm working on\n"
	.string "something in the attic of DEVON CORP.$"

RustboroCity_EventScript_DrParkerIntro_Text_5:
# 1336 "data/maps/RustboroCity/scripts.pory"
	.string "Let me know if you find anything that\n"
	.string "looks like it could be useful!$"
