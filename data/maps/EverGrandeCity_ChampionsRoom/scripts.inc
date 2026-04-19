# 1 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
# 4 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
# 5 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
# 6 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnTransition:
# 9 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 10 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 11 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnWarp:
# 13 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
# 14 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 15 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
# 17 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 18 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 19 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_OnFrame:
# 21 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
# 22 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.2byte 0
# 23 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 24 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
# 25 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	lockall
# 26 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	removeobject LOCALID_PROCTOR_NIMA
# 27 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
# 28 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 29 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 30 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
# 31 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 32 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 33 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
# 34 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 35 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 36 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 37 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
# 38 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 39 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 40 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 41 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 42 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Wallace::
# 43 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
# 44 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceGreeting, MSGBOX_DEFAULT
# 45 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 46 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint
# 47 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_WallacePostgameChallenge
# 48 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_WallaceStartBattle
# 49 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 50 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 51 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_WallacePostgameChallenge::
# 52 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceBattleChallenge, MSGBOX_DEFAULT
# 53 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 54 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_WallaceStartBattle::
# 55 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
# 56 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
# 57 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 58 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 59 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Defeated::
# 60 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_ClearUnstableDNAFlags
# 61 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 62 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 63 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 64 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 65 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal
# 66 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 67 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 68 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 69 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 70 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
# 71 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
# 72 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
# 73 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
# 74 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 75 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
# 76 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
# 77 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 78 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 79 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_ClearUnstableDNAFlags::
# 80 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_SIDNEY
# 81 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_PHOEBE
# 82 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_GLACIA
# 83 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_DRAKE
# 84 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 85 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 86 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
# 87 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 88 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 89 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 90 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
# 91 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 92 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 93 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 94 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
# 95 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
# 96 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 97 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 99 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 100 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 101 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 102 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 103 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
# 104 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 105 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 106 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 107 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
# 108 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
# 109 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 110 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 111 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 112 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 113 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 114 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 115 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 116 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
# 117 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 118 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 119 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 120 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
# 121 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 122 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
# 123 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
# 124 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 125 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 126 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 127 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
# 128 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call ProfBirch_EventScript_RatePokedex
# 129 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
# 130 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
# 131 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 132 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 133 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
# 134 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 135 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
# 136 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 137 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 138 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
# 139 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 140 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
# 141 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
# 142 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 143 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 144 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 145 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 146 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
# 147 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 148 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
# 149 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
# 150 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 151 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
# 152 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 153 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 154 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 155 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 156 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 157 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 158 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 159 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 160 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
# 161 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
# 162 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 163 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 164 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
# 165 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
# 166 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 167 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 168 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
# 169 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
# 170 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 171 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 172 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 173 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 174 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 175 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
# 176 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
# 177 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 178 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 179 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 180 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
# 181 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 182 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 183 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 184 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 185 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
# 186 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 187 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 188 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 189 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 190 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 191 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 192 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 193 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
# 194 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 195 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 196 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 197 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 198 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 199 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 200 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 201 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 202 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 203 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 204 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
# 205 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 206 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 207 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 208 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 209 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 210 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 211 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 212 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 213 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 214 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 215 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
# 216 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 217 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 218 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 219 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 220 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
# 221 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 222 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 223 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 224 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 225 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 226 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
# 227 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 228 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 229 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 230 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 231 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 232 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
# 233 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 234 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 235 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 236 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 237 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 238 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 239 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 240 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 241 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 242 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 243 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
# 244 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That incident in SOOTOPOLIS CITY…\n"
# 245 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was superb work, putting an end\l"
# 246 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to that crisis all by yourself.\p"
# 247 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Oops!\p"
# 248 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It wouldn't be fair to say that you\n"
# 249 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "alone ended the crisis.\p"
# 250 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You overcame that difficult situation\n"
# 251 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "by working as one with your POKéMON.\p"
# 252 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "We TRAINERS raise POKéMON by giving\n"
# 253 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "them items and by teaching them new\l"
# 254 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "techniques for battle.\p"
# 255 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But we ourselves also learn many\n"
# 256 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "things from POKéMON.\p"
# 257 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And this is where your achievements\n"
# 258 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "are put to the test against what\l"
# 259 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "others like you have achieved.$"
# 260 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 261 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Defeat:
# 262 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 263 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was wonderful work.\n"
# 264 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You were elegant, infuriatingly so.\l"
# 265 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And yet it was utterly glorious!\p"
# 266 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 267 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 268 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 269 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 270 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
# 271 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: The POKéMON you sent into\n"
# 272 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "battle…\p"
# 273 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "At times they danced like a spring\n"
# 274 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "breeze, and at times they struck\l"
# 275 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "like lightning.\p"
# 276 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It was with light, yet surefooted,\n"
# 277 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "elegance that you led your POKéMON.\p"
# 278 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Even I felt bedazzled by your\n"
# 279 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "masterful performance!\p"
# 280 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You now stand at the glorious peak\n"
# 281 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "of the POKéMON LEAGUE.\p"
# 282 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I now proclaim you to be the new\n"
# 283 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "HOENN region…$"
# 284 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 285 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayAdvice:
# 286 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 287 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here's some advice before you challenge\n"
# 288 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION…$"
# 289 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 290 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
# 291 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Huh?\n"
# 292 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What, what, what?\p"
# 293 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 294 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Could it be that…\l"
# 295 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It's already over?$"
# 296 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 297 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
# 298 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}!\p"
# 299 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "How would you like some advice before\n"
# 300 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "you challenge the CHAMPION?…$"
# 301 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 302 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
# 303 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}…\p"
# 304 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Are you trying to tell me…\n"
# 305 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've beaten the CHAMPION?$"
# 306 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 307 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
# 308 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: See?\n"
# 309 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did I tell you, {RIVAL}?\p"
# 310 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Didn't I tell you that you don't need\n"
# 311 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to worry about {PLAYER}{KUN}?\p"
# 312 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 313 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
# 314 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "When I heard that you defeated your\n"
# 315 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "own father at the PETALBURG GYM,\l"
# 316 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I thought perhaps you had a chance…\p"
# 317 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But to think you've actually become\n"
# 318 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION!\p"
# 319 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Ah, yes!\p"
# 320 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What became of your POKéDEX?\n"
# 321 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here, let me see.$"
# 322 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 323 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
# 324 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: Anyways,\n"
# 325 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "congratulations!\p"
# 326 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, go proudly into the final room!$"
# 327 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 328 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
# 329 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 330 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "No, let me rephrase that properly.\p"
# 331 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "The new CHAMPION!\p"
# 332 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Come with me.$"
# 333 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 334 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
# 335 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: I'm sorry, but…\p"
# 336 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "From here on, only those TRAINERS who\n"
# 337 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "have become CHAMPIONS may enter.\p"
# 338 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You'll have to wait outside with\n"
# 339 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH.$"
# 340 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 341 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
# 342 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Groan…\p"
# 343 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 344 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 345 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I'm just joking! That's okay!\n"
# 346 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That's the rule!\p"
# 347 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 348 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Honestly, congratulations!$"
# 349 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 350 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
# 351 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: Whaaaat?! … … … … …\n"
# 352 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 353 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It can't be helped if that's the rule.\p"
# 354 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, way to go!\n"
# 355 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Congratulations!$"

EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint::
# 359 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_2
EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_1:
	return

EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_2:
# 360 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 361 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 362 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallacePreBattleHint
	goto EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_1


EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal::
# 368 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_2
# 372 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 32
# 373 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_SEALED_CHAMBER, TRUE
# 374 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_HIDE_PROCTOR_NIMA
# 375 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_PROCTOR_NIMA
# 376 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, Common_Movement_WalkDown
# 377 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitse
# 378 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 16
# 379 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal
# 380 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 381 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_Text_0
# 382 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 383 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal2
# 384 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 385 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 386 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 387 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_ProctorNimaReveal
# 388 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 389 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 390 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceProctorFollowup
# 391 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	fadedefaultbgm
# 392 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, EverGrandeCity_ChampionsRoom_Movement_ProctorNimaWalkAway
# 393 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 394 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PROCTOR_NIMA
# 395 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	removeobject LOCALID_PROCTOR_NIMA
	return

EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_2:
	return


# 399 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal:
# 400 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 401 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_down
# 401 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_down
# 402 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	face_left
# 403 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end

# 406 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal2:
# 407 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_down
# 408 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	face_player
	step_end

# 411 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ProctorNimaWalkAway:
# 412 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 412 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 412 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 413 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 414 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_Text_0:
# 381 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROCTOR NIMA: Enough, WALLACE.$"

EverGrandeCity_ChampionsRoom_Text_WallacePreBattleHint::
# 417 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Before we begin, a final word.\p"
	.string "Those sealed vials were not random\n"
	.string "gifts.\p"
	.string "I was told to watch for the TRAINER who\n"
	.string "could carry power without being\l"
	.string "consumed by it.\p"
	.string "Keep that in mind as we battle.$"

EverGrandeCity_ChampionsRoom_Text_WallaceGreeting::
# 425 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Welcome, {PLAYER}{KUN}.$"

EverGrandeCity_ChampionsRoom_Text_WallaceBattleChallenge::
# 429 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their POKéMON in HOENN?\p"
	.string "Show me right here and now!$"

EverGrandeCity_ChampionsRoom_Text_ProctorNimaReveal::
# 436 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, your LEAGUE assessment is\n"
	.string "finally complete.\p"
	.string "I am NIMA, acting Proctor of the trial\n"
	.string "you just participated in.\p"
	.string "PROCTOR NIMA: The UNSTABLE DNA\n"
	.string "samples were held in a restricted\l"
	.string "LEAGUE vault after an old research\l"
	.string "incident.\p"
	.string "Each handoff was authorized and\n"
	.string "tracked under my watch.$"

EverGrandeCity_ChampionsRoom_Text_WallaceProctorFollowup::
# 444 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: We have heard rumors about\n"
	.string "DR. PARKER, and his PROTO-LEGEND\l"
	.string "research at DEVON with our UNSTABLE\l"
	.string "DNA.\p"
	.string "When reports of his stabilization work\n"
	.string "reached the LEAGUE, the Proctor\l"
	.string "released controlled samples for field\l"
	.string "review.\p"
	.string "His work showed unstable power can be\n"
	.string "shaped. This trial showed who can be\l"
	.string "trusted to wield it.\p"
	.string "PROCTOR NIMA: The evaluation is over.\n"
	.string "My work here is complete. What you do\l"
	.string "with that power now is your choice.$"
