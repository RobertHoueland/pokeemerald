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
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_WallacePostgameChallenge
# 46 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 47 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint
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
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_WallaceStartRematchBattle
# 56 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
# 57 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
# 58 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 59 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 60 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_WallaceStartRematchBattle::
# 61 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLACE_2, EverGrandeCity_ChampionsRoom_Text_DefeatRematch
# 62 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
# 63 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 64 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 65 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_Defeated::
# 66 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_ClearUnstableDNAFlags
# 67 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 68 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
# 69 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
# 70 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	special DrawWholeMapView
# 71 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal
# 72 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_DefeatedRematch
# 73 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 74 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 75 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_DOOR
# 76 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 77 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
# 78 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
# 79 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
# 80 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
# 81 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 82 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
# 83 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
# 84 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 85 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 86 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_DefeatedRematch::
# 87 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeechRematch, MSGBOX_DEFAULT
# 88 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 89 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 90 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
# 91 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 92 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 93 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 94 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
# 95 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 96 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 97 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 98 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 99 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 100 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 101 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 102 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 103 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_ClearUnstableDNAFlags::
# 104 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_SIDNEY
# 105 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_PHOEBE
# 106 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_GLACIA
# 107 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_RECEIVED_UNSTABLE_DNA_DRAKE
# 108 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 109 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 110 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
# 111 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, FALSE
# 112 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 113 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 114 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
# 115 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 116 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 117 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 118 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
# 119 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
# 120 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 121 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 122 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 123 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 124 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 125 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 126 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 127 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
# 128 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 129 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 130 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 131 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
# 132 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
# 133 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 40
# 134 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playse SE_PIN
# 135 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
# 136 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 137 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
# 138 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 139 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
# 140 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
# 141 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
# 142 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 143 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 144 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
# 145 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 146 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
# 147 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
# 148 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 149 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 150 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 151 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
# 152 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call ProfBirch_EventScript_RatePokedex
# 153 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
# 154 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
# 155 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 156 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 157 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
# 158 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 159 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
# 160 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 161 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 30
# 162 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
# 163 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
# 164 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
# 165 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
# 166 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 167 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 168 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 169 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 170 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
# 171 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	checkplayergender
# 172 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
# 173 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
# 174 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 175 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
# 176 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
# 177 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 178 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
# 179 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
# 180 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitstate
# 181 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	releaseall
# 182 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	end
# 183 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 184 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
# 185 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
# 186 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 187 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 188 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
# 189 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
# 190 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 191 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 192 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
# 193 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
# 194 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 195 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 196 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 197 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 198 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 199 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
# 200 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
# 201 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 202 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	return
# 203 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 204 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
# 205 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 206 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 207 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 208 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 209 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
# 210 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 211 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 212 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 213 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 214 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 215 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 216 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 217 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
# 218 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 219 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 220 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 221 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 222 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 223 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 224 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 225 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 226 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 227 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 228 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
# 229 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 230 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 231 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 232 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 233 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_up
# 234 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 235 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_right
# 236 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_16
# 237 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 238 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 239 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
# 240 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 241 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 242 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 243 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 244 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
# 245 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 246 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 247 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_down
# 248 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 249 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 250 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
# 251 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 252 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay_8
# 253 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	set_invisible
# 254 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 255 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 256 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
# 257 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 258 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 259 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 260 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 261 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 262 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 263 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 264 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_in_place_faster_left
# 265 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end
# 266 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 267 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
# 268 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That incident in SOOTOPOLIS CITY…\n"
# 269 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was superb work, putting an end\l"
# 270 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to that crisis all by yourself.\p"
# 271 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Oops!\p"
# 272 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It wouldn't be fair to say that you\n"
# 273 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "alone ended the crisis.\p"
# 274 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You overcame that difficult situation\n"
# 275 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "by working as one with your POKéMON.\p"
# 276 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "We TRAINERS raise POKéMON by giving\n"
# 277 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "them items and by teaching them new\l"
# 278 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "techniques for battle.\p"
# 279 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But we ourselves also learn many\n"
# 280 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "things from POKéMON.\p"
# 281 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And this is where your achievements\n"
# 282 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "are put to the test against what\l"
# 283 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "others like you have achieved.$"
# 284 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 285 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_Defeat:
# 286 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I, the CHAMPION, fall in defeat…\p"
# 287 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That was wonderful work.\n"
# 288 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You were elegant, infuriatingly so.\l"
# 289 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "And yet it was utterly glorious!\p"
# 290 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Kudos to you, {PLAYER}{KUN}!\p"
# 291 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You are a truly noble POKéMON\n"
# 292 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "TRAINER!$"
# 293 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 294 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_DefeatRematch:
# 295 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Once again, I am unseated.\p"
# 296 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Magnificent, {PLAYER}{KUN}.\p"
# 297 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've turned victory into an art form.$"
# 298 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 299 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
# 300 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: The POKéMON you sent into\n"
# 301 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "battle…\p"
# 302 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "At times they danced like a spring\n"
# 303 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "breeze, and at times they struck\l"
# 304 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "like lightning.\p"
# 305 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It was with light, yet surefooted,\n"
# 306 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "elegance that you led your POKéMON.\p"
# 307 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Even I felt bedazzled by your\n"
# 308 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "masterful performance!\p"
# 309 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You now stand at the glorious peak\n"
# 310 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "of the POKéMON LEAGUE.\p"
# 311 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I now proclaim you to be the new\n"
# 312 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "HOENN region…$"
# 313 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 314 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_PostBattleSpeechRematch:
# 315 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Splendid.\p"
# 316 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Your command is sharper than ever,\n"
# 317 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "and your team moved in perfect rhythm.\p"
# 318 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Let's record this victory in the\n"
# 319 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "HALL OF FAME once more.$"
# 320 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 321 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayAdvice:
# 322 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
# 323 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here's some advice before you challenge\n"
# 324 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION…$"
# 325 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 326 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
# 327 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Huh?\n"
# 328 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What, what, what?\p"
# 329 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 330 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Could it be that…\l"
# 331 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It's already over?$"
# 332 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 333 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
# 334 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}!\p"
# 335 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "How would you like some advice before\n"
# 336 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "you challenge the CHAMPION?…$"
# 337 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 338 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
# 339 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: {PLAYER}…\p"
# 340 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Are you trying to tell me…\n"
# 341 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You've beaten the CHAMPION?$"
# 342 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 343 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
# 344 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: See?\n"
# 345 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What did I tell you, {RIVAL}?\p"
# 346 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Didn't I tell you that you don't need\n"
# 347 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "to worry about {PLAYER}{KUN}?\p"
# 348 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 349 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}, you've finally done it.\p"
# 350 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "When I heard that you defeated your\n"
# 351 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "own father at the PETALBURG GYM,\l"
# 352 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I thought perhaps you had a chance…\p"
# 353 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "But to think you've actually become\n"
# 354 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "the CHAMPION!\p"
# 355 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Ah, yes!\p"
# 356 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "What became of your POKéDEX?\n"
# 357 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Here, let me see.$"
# 358 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 359 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
# 360 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH: Anyways,\n"
# 361 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "congratulations!\p"
# 362 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now, go proudly into the final room!$"
# 363 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 364 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
# 365 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 366 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "No, let me rephrase that properly.\p"
# 367 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "The new CHAMPION!\p"
# 368 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Come with me.$"
# 369 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 370 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
# 371 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: I'm sorry, but…\p"
# 372 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "From here on, only those TRAINERS who\n"
# 373 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "have become CHAMPIONS may enter.\p"
# 374 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "You'll have to wait outside with\n"
# 375 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "PROF. BIRCH.$"
# 376 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 377 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
# 378 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "MAY: Groan…\p"
# 379 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\n"
# 380 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 381 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "I'm just joking! That's okay!\n"
# 382 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "That's the rule!\p"
# 383 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}{KUN}!\n"
# 384 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Honestly, congratulations!$"
# 385 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"

# 386 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
# 387 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "BRENDAN: Whaaaat?! … … … … …\n"
# 388 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "… … … … … … … …\p"
# 389 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "It can't be helped if that's the rule.\p"
# 390 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "{PLAYER}, way to go!\n"
# 391 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Congratulations!$"

EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint::
# 395 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_2
EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_1:
	return

EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_2:
# 396 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 397 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 20
# 398 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallacePreBattleHint
	goto EverGrandeCity_ChampionsRoom_EventScript_TryWallacePreBattleHint_1


EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal::
# 404 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_2
# 408 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 32
# 409 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	playbgm MUS_SEALED_CHAMBER, TRUE
# 410 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	clearflag FLAG_HIDE_PROCTOR_NIMA
# 411 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	addobject LOCALID_PROCTOR_NIMA
# 412 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, Common_Movement_WalkDown
# 413 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitse
# 414 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	delay 16
# 415 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal
# 416 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 417 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_Text_0
# 418 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	closemessage
# 419 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal2
# 420 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 421 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 422 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 423 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_ProctorNimaReveal
# 424 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 425 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 426 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceProctorFollowup
# 427 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	fadedefaultbgm
# 428 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	applymovement LOCALID_PROCTOR_NIMA, EverGrandeCity_ChampionsRoom_Movement_ProctorNimaWalkAway
# 429 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	waitmovement 0
# 430 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	setflag FLAG_HIDE_PROCTOR_NIMA
# 431 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	removeobject LOCALID_PROCTOR_NIMA
	return

EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_2:
	return


# 435 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal:
# 436 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_right
# 437 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_down
# 437 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_down
# 438 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	face_left
# 439 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	step_end

# 442 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ProctorNimaReveal2:
# 443 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_down
# 444 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	face_player
	step_end

# 447 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
EverGrandeCity_ChampionsRoom_Movement_ProctorNimaWalkAway:
# 448 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 448 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 448 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
# 449 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_left
# 450 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_TryProctorReveal_Text_0:
# 417 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "???: Enough, WALLACE.$"

EverGrandeCity_ChampionsRoom_Text_WallacePreBattleHint::
# 453 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Before we begin, a final word.\p"
	.string "Those sealed vials were not random\n"
	.string "gifts.\p"
	.string "I was told to watch for the TRAINER who\n"
	.string "could carry power without being\l"
	.string "consumed by it.\p"
	.string "Keep that in mind as we battle.$"

EverGrandeCity_ChampionsRoom_Text_WallaceGreeting::
# 461 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "WALLACE: Welcome, {PLAYER}{KUN}.$"

EverGrandeCity_ChampionsRoom_Text_WallaceBattleChallenge::
# 465 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
	.string "Now!\p"
	.string "Who can most elegantly dance with\n"
	.string "their POKéMON in HOENN?\p"
	.string "Show me again, right here and now!$"

EverGrandeCity_ChampionsRoom_Text_ProctorNimaReveal::
# 472 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
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
# 480 "data/maps/EverGrandeCity_ChampionsRoom/scripts.pory"
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
