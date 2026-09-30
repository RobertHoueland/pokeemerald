# 1 "data/maps/Route111/scripts.pory"

# 2 "data/maps/Route111/scripts.pory"
Route111_MapScripts::
# 3 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
# 4 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
# 5 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
# 6 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
# 7 "data/maps/Route111/scripts.pory"
	.byte 0
# 8 "data/maps/Route111/scripts.pory"

# 9 "data/maps/Route111/scripts.pory"
Route111_OnLoad:
# 10 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
# 11 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
# 12 "data/maps/Route111/scripts.pory"
	end
# 13 "data/maps/Route111/scripts.pory"

# 14 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseDesertRuins::
# 15 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
# 16 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
# 17 "data/maps/Route111/scripts.pory"
	return
# 18 "data/maps/Route111/scripts.pory"

# 19 "data/maps/Route111/scripts.pory"
@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
# 20 "data/maps/Route111/scripts.pory"
Route111_EventScript_ShowTemporaryMirageTower::
# 21 "data/maps/Route111/scripts.pory"
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
# 22 "data/maps/Route111/scripts.pory"
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
# 23 "data/maps/Route111/scripts.pory"
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
# 24 "data/maps/Route111/scripts.pory"
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
# 25 "data/maps/Route111/scripts.pory"
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
# 26 "data/maps/Route111/scripts.pory"
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
# 27 "data/maps/Route111/scripts.pory"
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
# 28 "data/maps/Route111/scripts.pory"
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
# 29 "data/maps/Route111/scripts.pory"
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
# 30 "data/maps/Route111/scripts.pory"
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
# 31 "data/maps/Route111/scripts.pory"
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
# 32 "data/maps/Route111/scripts.pory"
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
# 33 "data/maps/Route111/scripts.pory"
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
# 34 "data/maps/Route111/scripts.pory"
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
# 35 "data/maps/Route111/scripts.pory"
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
# 36 "data/maps/Route111/scripts.pory"
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
# 37 "data/maps/Route111/scripts.pory"
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
# 38 "data/maps/Route111/scripts.pory"
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
# 39 "data/maps/Route111/scripts.pory"
	return
# 40 "data/maps/Route111/scripts.pory"

# 41 "data/maps/Route111/scripts.pory"
Route111_OnTransition:
# 42 "data/maps/Route111/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 43 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_2, 0
# 44 "data/maps/Route111/scripts.pory"
	special SetMirageTowerVisibility
# 45 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
# 46 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
# 47 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
# 48 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CheckSetSandstorm
# 49 "data/maps/Route111/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 50 "data/maps/Route111/scripts.pory"
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
# 51 "data/maps/Route111/scripts.pory"
	end
# 52 "data/maps/Route111/scripts.pory"

# 53 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfx::
# 54 "data/maps/Route111/scripts.pory"
	checkplayergender
# 55 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route111_EventScript_SetFallingPlayerGfxMale
# 56 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route111_EventScript_SetFallingPlayerGfxFemale
# 57 "data/maps/Route111/scripts.pory"
	return
# 58 "data/maps/Route111/scripts.pory"

# 59 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxMale::
# 60 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 61 "data/maps/Route111/scripts.pory"
	return
# 62 "data/maps/Route111/scripts.pory"

# 63 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxFemale::
# 64 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 65 "data/maps/Route111/scripts.pory"
	return
# 66 "data/maps/Route111/scripts.pory"

# 67 "data/maps/Route111/scripts.pory"
Route111_EventScript_CheckSetSandstorm::
# 68 "data/maps/Route111/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 69 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
# 70 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
# 71 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
# 72 "data/maps/Route111/scripts.pory"
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
# 73 "data/maps/Route111/scripts.pory"
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
# 74 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetSandstorm::
# 75 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 76 "data/maps/Route111/scripts.pory"
Route111_EventScript_EndCheckSetSandstorm::
# 77 "data/maps/Route111/scripts.pory"
	return
# 78 "data/maps/Route111/scripts.pory"

# 79 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetWinstratesNotDefeated::
# 80 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
# 81 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
# 82 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
# 83 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
# 84 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTOR
# 85 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTORIA
# 86 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VIVI
# 87 "data/maps/Route111/scripts.pory"
	end
# 88 "data/maps/Route111/scripts.pory"

# 89 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetLayoutNoMirageTower::
# 90 "data/maps/Route111/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
# 91 "data/maps/Route111/scripts.pory"
	return
# 92 "data/maps/Route111/scripts.pory"

# 93 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetMirageTowerGone::
# 94 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 3
# 95 "data/maps/Route111/scripts.pory"
	return
# 96 "data/maps/Route111/scripts.pory"

# 97 "data/maps/Route111/scripts.pory"
Route111_OnWarp:
# 98 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
# 99 "data/maps/Route111/scripts.pory"
	.2byte 0
# 100 "data/maps/Route111/scripts.pory"

# 101 "data/maps/Route111/scripts.pory"
Route111_EventScript_HidePlayerForMirageTower::
# 102 "data/maps/Route111/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
# 103 "data/maps/Route111/scripts.pory"
	end
# 104 "data/maps/Route111/scripts.pory"

# 105 "data/maps/Route111/scripts.pory"
Route111_OnFrame:
# 106 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
# 107 "data/maps/Route111/scripts.pory"
	.2byte 0
# 108 "data/maps/Route111/scripts.pory"

# 109 "data/maps/Route111/scripts.pory"
Route111_EventScript_MirageTowerDisappear::
# 110 "data/maps/Route111/scripts.pory"
	lockall
# 111 "data/maps/Route111/scripts.pory"
	special StartMirageTowerShake
# 112 "data/maps/Route111/scripts.pory"
	delay 24
# 113 "data/maps/Route111/scripts.pory"
	playse SE_FALL
# 114 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_PLAYER_FALLING
# 115 "data/maps/Route111/scripts.pory"
	special StartPlayerDescendMirageTower
# 116 "data/maps/Route111/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
# 117 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
# 118 "data/maps/Route111/scripts.pory"
	delay 16
# 119 "data/maps/Route111/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 120 "data/maps/Route111/scripts.pory"
	delay 16
# 121 "data/maps/Route111/scripts.pory"
	special StartMirageTowerDisintegration
# 122 "data/maps/Route111/scripts.pory"
	special StartMirageTowerFossilFallAndSink
# 123 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 2
# 124 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 125 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
# 126 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
# 127 "data/maps/Route111/scripts.pory"
	releaseall
# 128 "data/maps/Route111/scripts.pory"
	end
# 129 "data/maps/Route111/scripts.pory"

# 130 "data/maps/Route111/scripts.pory"
Route111_EventScript_RootFossilDisappeared::
# 131 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
# 132 "data/maps/Route111/scripts.pory"
	releaseall
# 133 "data/maps/Route111/scripts.pory"
	end
# 134 "data/maps/Route111/scripts.pory"

# 135 "data/maps/Route111/scripts.pory"
@ Unused
# 136 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall::
# 137 "data/maps/Route111/scripts.pory"
	lock_anim
# 138 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 139 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 140 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 141 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 142 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 143 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route111/scripts.pory"
	step_end
# 145 "data/maps/Route111/scripts.pory"

# 146 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl::
# 147 "data/maps/Route111/scripts.pory"
	lock
# 148 "data/maps/Route111/scripts.pory"
	faceplayer
# 149 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 150 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 151 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 152 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 153 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 154 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 155 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 156 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 157 "data/maps/Route111/scripts.pory"
	release
# 158 "data/maps/Route111/scripts.pory"
	end
# 159 "data/maps/Route111/scripts.pory"

# 160 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry::
# 161 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 162 "data/maps/Route111/scripts.pory"
	release
# 163 "data/maps/Route111/scripts.pory"
	end
# 164 "data/maps/Route111/scripts.pory"

# 165 "data/maps/Route111/scripts.pory"
@ Unused
# 166 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp::
# 167 "data/maps/Route111/scripts.pory"
	lockall
# 168 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 169 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 170 "data/maps/Route111/scripts.pory"
	end
# 171 "data/maps/Route111/scripts.pory"

# 172 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown::
# 173 "data/maps/Route111/scripts.pory"
	lockall
# 174 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 175 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 176 "data/maps/Route111/scripts.pory"
	end
# 177 "data/maps/Route111/scripts.pory"

# 178 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft::
# 179 "data/maps/Route111/scripts.pory"
	lockall
# 180 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 181 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 182 "data/maps/Route111/scripts.pory"
	end
# 183 "data/maps/Route111/scripts.pory"

# 184 "data/maps/Route111/scripts.pory"
@ Unused
# 185 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight::
# 186 "data/maps/Route111/scripts.pory"
	lockall
# 187 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 188 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 189 "data/maps/Route111/scripts.pory"
	end
# 190 "data/maps/Route111/scripts.pory"

# 191 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger::
# 192 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES
# 193 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
# 194 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 195 "data/maps/Route111/scripts.pory"
	releaseall
# 196 "data/maps/Route111/scripts.pory"
	end
# 197 "data/maps/Route111/scripts.pory"

# 198 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess::
# 199 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 200 "data/maps/Route111/scripts.pory"
	closemessage
# 201 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
# 202 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
# 203 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
# 204 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
# 205 "data/maps/Route111/scripts.pory"
	releaseall
# 206 "data/maps/Route111/scripts.pory"
	end
# 207 "data/maps/Route111/scripts.pory"

# 208 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute::
# 209 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute
# 210 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 211 "data/maps/Route111/scripts.pory"
	return
# 212 "data/maps/Route111/scripts.pory"

# 213 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute::
# 214 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushDownFromRoute
# 215 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 216 "data/maps/Route111/scripts.pory"
	return
# 217 "data/maps/Route111/scripts.pory"

# 218 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute::
# 219 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushLeftFromRoute
# 220 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 221 "data/maps/Route111/scripts.pory"
	return
# 222 "data/maps/Route111/scripts.pory"

# 223 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute::
# 224 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushRightFromRoute
# 225 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 226 "data/maps/Route111/scripts.pory"
	return
# 227 "data/maps/Route111/scripts.pory"

# 228 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute:
# 229 "data/maps/Route111/scripts.pory"
	walk_up
# 230 "data/maps/Route111/scripts.pory"
	step_end
# 231 "data/maps/Route111/scripts.pory"

# 232 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute:
# 233 "data/maps/Route111/scripts.pory"
	walk_down
# 234 "data/maps/Route111/scripts.pory"
	step_end
# 235 "data/maps/Route111/scripts.pory"

# 236 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute:
# 237 "data/maps/Route111/scripts.pory"
	walk_left
# 238 "data/maps/Route111/scripts.pory"
	step_end
# 239 "data/maps/Route111/scripts.pory"

# 240 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute:
# 241 "data/maps/Route111/scripts.pory"
	walk_right
# 242 "data/maps/Route111/scripts.pory"
	step_end
# 243 "data/maps/Route111/scripts.pory"

# 244 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger::
# 245 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 246 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 247 "data/maps/Route111/scripts.pory"
	doweather
# 248 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 249 "data/maps/Route111/scripts.pory"
	end
# 250 "data/maps/Route111/scripts.pory"

# 251 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger::
# 252 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 253 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_DESERT
# 254 "data/maps/Route111/scripts.pory"
	doweather
# 255 "data/maps/Route111/scripts.pory"
	end
# 256 "data/maps/Route111/scripts.pory"

# 257 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor::
# 258 "data/maps/Route111/scripts.pory"
	lock
# 259 "data/maps/Route111/scripts.pory"
	faceplayer
# 260 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 261 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 262 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
# 263 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 264 "data/maps/Route111/scripts.pory"
	release
# 265 "data/maps/Route111/scripts.pory"
	end
# 266 "data/maps/Route111/scripts.pory"

# 267 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates::
# 268 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 269 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 270 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTOR, Common_Movement_WalkInPlaceFasterUp
# 271 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 272 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 273 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 274 "data/maps/Route111/scripts.pory"
	closemessage
# 275 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTOR, Route111_Movement_WinstrateEnterHouse
# 276 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 277 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICTOR
# 278 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 279 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 280 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 281 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 282 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VICTORIA
# 283 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateExitHouse
# 284 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 285 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 286 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 287 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 288 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Common_Movement_WalkInPlaceFasterUp
# 289 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 290 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 291 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 292 "data/maps/Route111/scripts.pory"
	closemessage
# 293 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 294 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 295 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICTORIA
# 296 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 297 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 298 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 299 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 300 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VIVI
# 301 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateExitHouse
# 302 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 303 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 304 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 305 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 306 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Common_Movement_WalkInPlaceFasterUp
# 307 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 308 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 309 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 310 "data/maps/Route111/scripts.pory"
	closemessage
# 311 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateEnterHouse
# 312 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 313 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VIVI
# 314 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 315 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 316 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 317 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 318 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VICKY
# 319 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateExitHouse
# 320 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 321 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 322 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 323 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 324 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 325 "data/maps/Route111/scripts.pory"
	closemessage
# 326 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Common_Movement_WalkInPlaceFasterUp
# 327 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 328 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 329 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateEnterHouse
# 330 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 331 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICKY
# 332 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 333 "data/maps/Route111/scripts.pory"
	release
# 334 "data/maps/Route111/scripts.pory"
	end
# 335 "data/maps/Route111/scripts.pory"

# 336 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor::
# 337 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 338 "data/maps/Route111/scripts.pory"
	waitdooranim
# 339 "data/maps/Route111/scripts.pory"
	return
# 340 "data/maps/Route111/scripts.pory"

# 341 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor::
# 342 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 343 "data/maps/Route111/scripts.pory"
	waitdooranim
# 344 "data/maps/Route111/scripts.pory"
	return
# 345 "data/maps/Route111/scripts.pory"

# 346 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse:
# 347 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 348 "data/maps/Route111/scripts.pory"
	walk_up
# 349 "data/maps/Route111/scripts.pory"
	step_end
# 350 "data/maps/Route111/scripts.pory"

# 351 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse:
# 352 "data/maps/Route111/scripts.pory"
	walk_down
# 353 "data/maps/Route111/scripts.pory"
	step_end
# 354 "data/maps/Route111/scripts.pory"

# 355 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate:
# 356 "data/maps/Route111/scripts.pory"
	delay_16
# 357 "data/maps/Route111/scripts.pory"
	delay_16
# 358 "data/maps/Route111/scripts.pory"
	delay_16
# 359 "data/maps/Route111/scripts.pory"
	step_end
# 360 "data/maps/Route111/scripts.pory"

# 361 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville::
# 362 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 363 "data/maps/Route111/scripts.pory"
	end
# 364 "data/maps/Route111/scripts.pory"

# 365 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign::
# 366 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 367 "data/maps/Route111/scripts.pory"
	end
# 368 "data/maps/Route111/scripts.pory"

# 369 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112::
# 370 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 371 "data/maps/Route111/scripts.pory"
	end
# 372 "data/maps/Route111/scripts.pory"

# 373 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113::
# 374 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 375 "data/maps/Route111/scripts.pory"
	end
# 376 "data/maps/Route111/scripts.pory"

# 377 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign::
# 378 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 379 "data/maps/Route111/scripts.pory"
	end
# 380 "data/maps/Route111/scripts.pory"

# 381 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef::
# 382 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 383 "data/maps/Route111/scripts.pory"
	end
# 384 "data/maps/Route111/scripts.pory"

# 385 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1::
# 386 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 387 "data/maps/Route111/scripts.pory"
	end
# 388 "data/maps/Route111/scripts.pory"

# 389 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2::
# 390 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 391 "data/maps/Route111/scripts.pory"
	end
# 392 "data/maps/Route111/scripts.pory"

# 393 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker::
# 394 "data/maps/Route111/scripts.pory"
	lock
# 395 "data/maps/Route111/scripts.pory"
	faceplayer
# 396 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
# 397 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
# 398 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 399 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 400 "data/maps/Route111/scripts.pory"
	release
# 401 "data/maps/Route111/scripts.pory"
	end
# 402 "data/maps/Route111/scripts.pory"

# 403 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone::
# 404 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 405 "data/maps/Route111/scripts.pory"
	release
# 406 "data/maps/Route111/scripts.pory"
	end
# 407 "data/maps/Route111/scripts.pory"

# 408 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated::
# 409 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 410 "data/maps/Route111/scripts.pory"
	release
# 411 "data/maps/Route111/scripts.pory"
	end
# 412 "data/maps/Route111/scripts.pory"

# 413 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible::
# 414 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 415 "data/maps/Route111/scripts.pory"
	release
# 416 "data/maps/Route111/scripts.pory"
	end
# 417 "data/maps/Route111/scripts.pory"

# 418 "data/maps/Route111/scripts.pory"
Route111_EventScript_RockSmashTipFatMan::
# 419 "data/maps/Route111/scripts.pory"
	lockall
# 420 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FacePlayer
# 421 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 422 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
# 423 "data/maps/Route111/scripts.pory"
	closemessage
# 424 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
# 425 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 426 "data/maps/Route111/scripts.pory"
	releaseall
# 427 "data/maps/Route111/scripts.pory"
	end
# 428 "data/maps/Route111/scripts.pory"

# 429 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew::
# 430 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 431 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 432 "data/maps/Route111/scripts.pory"
	end
# 433 "data/maps/Route111/scripts.pory"

# 434 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi::
# 435 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 436 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 437 "data/maps/Route111/scripts.pory"
	end
# 438 "data/maps/Route111/scripts.pory"

# 439 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau::
# 440 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 441 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 442 "data/maps/Route111/scripts.pory"
	end
# 443 "data/maps/Route111/scripts.pory"

# 444 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky::
# 445 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 446 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 447 "data/maps/Route111/scripts.pory"
	end
# 448 "data/maps/Route111/scripts.pory"

# 449 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty::
# 450 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 451 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 452 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
# 453 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 454 "data/maps/Route111/scripts.pory"
	release
# 455 "data/maps/Route111/scripts.pory"
	end
# 456 "data/maps/Route111/scripts.pory"

# 457 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty::
# 458 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 459 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 460 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 461 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 462 "data/maps/Route111/scripts.pory"
	release
# 463 "data/maps/Route111/scripts.pory"
	end
# 464 "data/maps/Route111/scripts.pory"

# 465 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty::
# 466 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 467 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 468 "data/maps/Route111/scripts.pory"
	end
# 469 "data/maps/Route111/scripts.pory"

# 470 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis::
# 471 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 472 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 473 "data/maps/Route111/scripts.pory"
	end
# 474 "data/maps/Route111/scripts.pory"

# 475 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene::
# 476 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 477 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 478 "data/maps/Route111/scripts.pory"
	end
# 479 "data/maps/Route111/scripts.pory"

# 480 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke::
# 481 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 482 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 483 "data/maps/Route111/scripts.pory"
	end
# 484 "data/maps/Route111/scripts.pory"

# 485 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton::
# 486 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 487 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 488 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
# 489 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 490 "data/maps/Route111/scripts.pory"
	release
# 491 "data/maps/Route111/scripts.pory"
	end
# 492 "data/maps/Route111/scripts.pory"

# 493 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton::
# 494 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 495 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 496 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 497 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 498 "data/maps/Route111/scripts.pory"
	release
# 499 "data/maps/Route111/scripts.pory"
	end
# 500 "data/maps/Route111/scripts.pory"

# 501 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton::
# 502 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 503 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 504 "data/maps/Route111/scripts.pory"
	end
# 505 "data/maps/Route111/scripts.pory"

# 506 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke::
# 507 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 508 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 509 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
# 510 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 511 "data/maps/Route111/scripts.pory"
	release
# 512 "data/maps/Route111/scripts.pory"
	end
# 513 "data/maps/Route111/scripts.pory"

# 514 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke::
# 515 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 516 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 517 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 518 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 519 "data/maps/Route111/scripts.pory"
	release
# 520 "data/maps/Route111/scripts.pory"
	end
# 521 "data/maps/Route111/scripts.pory"

# 522 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke::
# 523 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 524 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 525 "data/maps/Route111/scripts.pory"
	end
# 526 "data/maps/Route111/scripts.pory"

# 527 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden::
# 528 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 529 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 530 "data/maps/Route111/scripts.pory"
	end
# 531 "data/maps/Route111/scripts.pory"

# 532 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca::
# 533 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 534 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 535 "data/maps/Route111/scripts.pory"
	end
# 536 "data/maps/Route111/scripts.pory"

# 537 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron::
# 538 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 539 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 540 "data/maps/Route111/scripts.pory"
	end
# 541 "data/maps/Route111/scripts.pory"

# 542 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina::
# 543 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 544 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 545 "data/maps/Route111/scripts.pory"
	end
# 546 "data/maps/Route111/scripts.pory"

# 547 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia::
# 548 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 549 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 550 "data/maps/Route111/scripts.pory"
	end
# 551 "data/maps/Route111/scripts.pory"

# 552 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan::
# 553 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 554 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 555 "data/maps/Route111/scripts.pory"
	end
# 556 "data/maps/Route111/scripts.pory"

# 557 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden::
# 558 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 559 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 560 "data/maps/Route111/scripts.pory"
	end
# 561 "data/maps/Route111/scripts.pory"

# 562 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign::
# 563 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 564 "data/maps/Route111/scripts.pory"
	end
# 565 "data/maps/Route111/scripts.pory"

# 566 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily:
# 567 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 568 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 569 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 570 "data/maps/Route111/scripts.pory"
	.string "POKéMON battles?$"
# 571 "data/maps/Route111/scripts.pory"

# 572 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo:
# 573 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 574 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 575 "data/maps/Route111/scripts.pory"

# 576 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro:
# 577 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 578 "data/maps/Route111/scripts.pory"

# 579 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat:
# 580 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 581 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 582 "data/maps/Route111/scripts.pory"

# 583 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle:
# 584 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 585 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong TRAINER!$"
# 586 "data/maps/Route111/scripts.pory"

# 587 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro:
# 588 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 589 "data/maps/Route111/scripts.pory"
	.string "You must be quite the TRAINER to beat\n"
# 590 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 591 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 592 "data/maps/Route111/scripts.pory"

# 593 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat:
# 594 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 595 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 596 "data/maps/Route111/scripts.pory"

# 597 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle:
# 598 "data/maps/Route111/scripts.pory"
	.string "There's a strong TRAINER here!\n"
# 599 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 600 "data/maps/Route111/scripts.pory"

# 601 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro:
# 602 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 603 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 604 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 605 "data/maps/Route111/scripts.pory"

# 606 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat:
# 607 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 608 "data/maps/Route111/scripts.pory"

# 609 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle:
# 610 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 611 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 612 "data/maps/Route111/scripts.pory"

# 613 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro:
# 614 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 615 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 616 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 617 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 618 "data/maps/Route111/scripts.pory"

# 619 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat:
# 620 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 621 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 622 "data/maps/Route111/scripts.pory"

# 623 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle:
# 624 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 625 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 626 "data/maps/Route111/scripts.pory"

# 627 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks:
# 628 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your POKéMON some\n"
# 629 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 630 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 631 "data/maps/Route111/scripts.pory"
	.string "I've heard the POKéMON LEAGUE's\n"
# 632 "data/maps/Route111/scripts.pory"
	.string "ELITE FOUR are far stronger than\l"
# 633 "data/maps/Route111/scripts.pory"
	.string "any GYM LEADER.$"
# 634 "data/maps/Route111/scripts.pory"

# 635 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe:
# 636 "data/maps/Route111/scripts.pory"
	.string "I challenged the WINSTRATE family,\n"
# 637 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 638 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 639 "data/maps/Route111/scripts.pory"

# 640 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville:
# 641 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 642 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} MAUVILLE CITY$"
# 643 "data/maps/Route111/scripts.pory"

# 644 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign:
# 645 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 646 "data/maps/Route111/scripts.pory"
	.string "THE WINSTRATE'S HOUSE$"
# 647 "data/maps/Route111/scripts.pory"

# 648 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112:
# 649 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 650 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 112$"
# 651 "data/maps/Route111/scripts.pory"

# 652 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113:
# 653 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 654 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 113$"
# 655 "data/maps/Route111/scripts.pory"

# 656 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign:
# 657 "data/maps/Route111/scripts.pory"
	.string "OLD LADY'S REST STOP\n"
# 658 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 659 "data/maps/Route111/scripts.pory"

# 660 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef:
# 661 "data/maps/Route111/scripts.pory"
	.string "TRAINER TIPS\p"
# 662 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a POKéMON's\n"
# 663 "data/maps/Route111/scripts.pory"
	.string "powerfulness is SP. ATK. It stands for\l"
# 664 "data/maps/Route111/scripts.pory"
	.string "“SPECIAL ATTACK.”\p"
# 665 "data/maps/Route111/scripts.pory"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
# 666 "data/maps/Route111/scripts.pory"
	.string "DEFENSE.”$"
# 667 "data/maps/Route111/scripts.pory"

# 668 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere:
# 669 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 670 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 671 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 672 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 673 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the MIRAGE TOWER.$"
# 674 "data/maps/Route111/scripts.pory"

# 675 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible:
# 676 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 677 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 678 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 679 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 680 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 681 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 682 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 683 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 684 "data/maps/Route111/scripts.pory"

# 685 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown:
# 686 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 687 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 688 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 689 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 690 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 691 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 692 "data/maps/Route111/scripts.pory"

# 693 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince:
# 694 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 695 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 696 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 697 "data/maps/Route111/scripts.pory"
	.string "the MIRAGE TOWER…$"
# 698 "data/maps/Route111/scripts.pory"

# 699 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared:
# 700 "data/maps/Route111/scripts.pory"
	.string "The CLAW FOSSIL disappeared into\n"
# 701 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 702 "data/maps/Route111/scripts.pory"

# 703 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared:
# 704 "data/maps/Route111/scripts.pory"
	.string "The ROOT FOSSIL disappeared into\n"
# 705 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 706 "data/maps/Route111/scripts.pory"

# 707 "data/maps/Route111/scripts.pory"
Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
# 708 "data/maps/Route111/scripts.pory"
	.string "Oh, no!\p"
# 709 "data/maps/Route111/scripts.pory"
	.string "My uncle in MAUVILLE told me to take\n"
# 710 "data/maps/Route111/scripts.pory"
	.string "ROCK SMASH with me if I was going to\l"
# 711 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111!\p"
# 712 "data/maps/Route111/scripts.pory"
	.string "My uncle? He lives across from\n"
# 713 "data/maps/Route111/scripts.pory"
	.string "the bike shop in MAUVILLE.$"
# 714 "data/maps/Route111/scripts.pory"

# 715 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign:
# 716 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
# 717 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 718 "data/maps/Route111/scripts.pory"
	.string "TRAINERS!”$"

Route111_EventScript_Archaeologist::
# 783 "data/maps/Route111/scripts.pory"
	lockall
# 784 "data/maps/Route111/scripts.pory"
	faceplayer
# 785 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MET_ARCHAEOLOGIST, MetArchaeologist
# 788 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistFirstMeeting
# 789 "data/maps/Route111/scripts.pory"
	setflag FLAG_MET_ARCHAEOLOGIST
# 791 "data/maps/Route111/scripts.pory"
MetArchaeologist:
# 792 "data/maps/Route111/scripts.pory"
	checkitem ITEM_WIND_TABLET, 1
# 793 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_Archaeologist_2
# 793 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_GAVE_WIND_TABLET, Route111_EventScript_Archaeologist_2
Route111_EventScript_Archaeologist_1:
# 799 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistFirstClueHint
# 800 "data/maps/Route111/scripts.pory"
	releaseall
# 801 "data/maps/Route111/scripts.pory"
	end
# 803 "data/maps/Route111/scripts.pory"
Archaeologist_FoundFirstClue:
# 804 "data/maps/Route111/scripts.pory"
	checkitem ITEM_BOLT_TABLET, 1
# 805 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_Archaeologist_7
# 805 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_GAVE_BOLT_TABLET, Route111_EventScript_Archaeologist_7
Route111_EventScript_Archaeologist_6:
# 810 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_FOUND_FIRST_CLUE, Archaeologist_SecondClue
# 813 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_0
# 814 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, ITEM_WIND_TABLET
# 815 "data/maps/Route111/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 816 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_GAVE_WIND_TABLET
# 817 "data/maps/Route111/scripts.pory"
	waitse
# 818 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistWindTablet
# 819 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_FOUND_FIRST_CLUE
# 821 "data/maps/Route111/scripts.pory"
Archaeologist_SecondClue:
# 823 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistSecondClueRiddle
# 824 "data/maps/Route111/scripts.pory"
	delay 2
# 825 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_1
# 826 "data/maps/Route111/scripts.pory"
	releaseall
# 827 "data/maps/Route111/scripts.pory"
	end
# 829 "data/maps/Route111/scripts.pory"
Archaeologist_FoundSecondClue:
# 830 "data/maps/Route111/scripts.pory"
	checkitem ITEM_EARTH_TABLET, 1
# 831 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_Archaeologist_12
# 831 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_GAVE_EARTH_TABLET, Route111_EventScript_Archaeologist_12
Route111_EventScript_Archaeologist_11:
# 836 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_LOOK_THIRD_CLUE, Archaeologist_ThirdClue
# 839 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_2
# 840 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, ITEM_BOLT_TABLET
# 841 "data/maps/Route111/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 842 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_GAVE_BOLT_TABLET
# 844 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistBoltTabletFound
# 845 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ARCHAEOLOGIST, Route111_EventScript_Archaeologist_Movement_0
# 849 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 850 "data/maps/Route111/scripts.pory"
	playse SE_PIN
# 851 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ARCHAEOLOGIST, Common_Movement_ExclamationMark
# 852 "data/maps/Route111/scripts.pory"
	waitse
# 853 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 854 "data/maps/Route111/scripts.pory"
	faceplayer
# 856 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_3
# 857 "data/maps/Route111/scripts.pory"
	playse SE_M_SAND_ATTACK
# 858 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ARCHAEOLOGIST, Route111_EventScript_Archaeologist_Movement_1
# 868 "data/maps/Route111/scripts.pory"
	waitse
# 869 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 870 "data/maps/Route111/scripts.pory"
	closemessage
# 871 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_4
# 872 "data/maps/Route111/scripts.pory"
	faceplayer
# 873 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_LOOK_THIRD_CLUE
# 875 "data/maps/Route111/scripts.pory"
Archaeologist_ThirdClue:
# 877 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistThirdClueHint
# 878 "data/maps/Route111/scripts.pory"
	releaseall
# 879 "data/maps/Route111/scripts.pory"
	end
# 881 "data/maps/Route111/scripts.pory"
Archaeologist_FoundThirdClue:
# 882 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_FOUND_ALL_CLUES, Archaeologist_FoundAllClues
# 885 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistEarthTabletFound
# 886 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, ITEM_EARTH_TABLET
# 887 "data/maps/Route111/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 888 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_GAVE_EARTH_TABLET
# 890 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_5
# 891 "data/maps/Route111/scripts.pory"
	delay 16
# 892 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistTwoForms
# 893 "data/maps/Route111/scripts.pory"
	delay 16
# 894 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_6
# 895 "data/maps/Route111/scripts.pory"
	delay 16
# 896 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistRevealGlassExplanation
# 898 "data/maps/Route111/scripts.pory"
	giveitem ITEM_REVEAL_GLASS
# 899 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_FOUND_ALL_CLUES
# 900 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistFinalAdvice
# 901 "data/maps/Route111/scripts.pory"
	releaseall
# 902 "data/maps/Route111/scripts.pory"
	end
# 904 "data/maps/Route111/scripts.pory"
Archaeologist_FoundAllClues:
# 906 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_7
# 907 "data/maps/Route111/scripts.pory"
	releaseall
	return

Route111_EventScript_Archaeologist_2:
# 795 "data/maps/Route111/scripts.pory"
	goto Archaeologist_FoundFirstClue
	goto Route111_EventScript_Archaeologist_1

Route111_EventScript_Archaeologist_7:
# 807 "data/maps/Route111/scripts.pory"
	goto Archaeologist_FoundSecondClue
	goto Route111_EventScript_Archaeologist_6

Route111_EventScript_Archaeologist_12:
# 833 "data/maps/Route111/scripts.pory"
	goto Archaeologist_FoundThirdClue
	goto Route111_EventScript_Archaeologist_11


Route111_EventScript_TimeShrineTrigger::
# 911 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_2, 1
# 912 "data/maps/Route111/scripts.pory"
	playse SE_PIN
# 913 "data/maps/Route111/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_HISTORIAN, Route111_EventScript_TimeShrineSealed
# 914 "data/maps/Route111/scripts.pory"
	lockall
# 915 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_TimeShrineTrigger_Text_0
# 917 "data/maps/Route111/scripts.pory"
	releaseall
# 918 "data/maps/Route111/scripts.pory"
	playse SE_WARP_IN
# 919 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_ShrineWarpSpin
# 920 "data/maps/Route111/scripts.pory"
	delay 30
# 921 "data/maps/Route111/scripts.pory"
	warp MAP_TIME_SHRINE, 0
	end


Route111_EventScript_TimeShrineSealed::
# 926 "data/maps/Route111/scripts.pory"
	lockall
# 927 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_TimeShrineSealed_Text_0
# 929 "data/maps/Route111/scripts.pory"
	releaseall
	end


# 933 "data/maps/Route111/scripts.pory"
Route111_Movement_ShrineWarpSpin:
# 934 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_down
# 935 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_left
# 936 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 937 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_right
# 938 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_down
# 939 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_left
# 940 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 941 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_right
# 942 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_down
# 943 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_left
# 944 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 945 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_right
# 946 "data/maps/Route111/scripts.pory"
	step_end

Route111_Sign_FirstClue::
# 950 "data/maps/Route111/scripts.pory"
	lockall
# 951 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHECKED_ROUTE_111_ROCK, CheckedRock
# 953 "data/maps/Route111/scripts.pory"
	msgbox Route111_Sign_FirstClue_Text_0
# 954 "data/maps/Route111/scripts.pory"
	msgbox Route111_Sign_FirstClue_Text_1, MSGBOX_YESNO
# 955 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route111_Sign_FirstClue_2
Route111_Sign_FirstClue_1:
# 961 "data/maps/Route111/scripts.pory"
	releaseall
# 962 "data/maps/Route111/scripts.pory"
	end
# 964 "data/maps/Route111/scripts.pory"
CheckedRock:
# 965 "data/maps/Route111/scripts.pory"
	msgbox Route111_Sign_FirstClue_Text_2
# 966 "data/maps/Route111/scripts.pory"
	releaseall
	return

Route111_Sign_FirstClue_2:
# 956 "data/maps/Route111/scripts.pory"
	playse SE_M_SAND_ATTACK
# 957 "data/maps/Route111/scripts.pory"
	waitse
# 958 "data/maps/Route111/scripts.pory"
	giveitem ITEM_WIND_TABLET
# 959 "data/maps/Route111/scripts.pory"
	setflag FLAG_CHECKED_ROUTE_111_ROCK
	goto Route111_Sign_FirstClue_1


# 845 "data/maps/Route111/scripts.pory"
Route111_EventScript_Archaeologist_Movement_0:
# 846 "data/maps/Route111/scripts.pory"
	face_right
# 847 "data/maps/Route111/scripts.pory"
	delay_16
	step_end

# 858 "data/maps/Route111/scripts.pory"
Route111_EventScript_Archaeologist_Movement_1:
# 859 "data/maps/Route111/scripts.pory"
	face_up
# 860 "data/maps/Route111/scripts.pory"
	delay_16
# 861 "data/maps/Route111/scripts.pory"
	face_right
# 862 "data/maps/Route111/scripts.pory"
	delay_16
# 863 "data/maps/Route111/scripts.pory"
	face_up
# 864 "data/maps/Route111/scripts.pory"
	delay_16
# 865 "data/maps/Route111/scripts.pory"
	face_right
# 866 "data/maps/Route111/scripts.pory"
	delay_16
	step_end

Route111_EventScript_Archaeologist_Text_0:
# 813 "data/maps/Route111/scripts.pory"
	.string "Oh, you found the first clue!$"

Route111_EventScript_Archaeologist_Text_1:
# 825 "data/maps/Route111/scripts.pory"
	.string "I'm no good at riddles.$"

Route111_EventScript_Archaeologist_Text_2:
# 839 "data/maps/Route111/scripts.pory"
	.string "Ah, you found the BOLT TABLET!$"

Route111_EventScript_Archaeologist_Text_3:
# 856 "data/maps/Route111/scripts.pory"
	.string "According to my calculations, it should\n"
	.string "be right here!$"

Route111_EventScript_Archaeologist_Text_4:
# 871 "data/maps/Route111/scripts.pory"
	.string "That's odd, it looks as if someone has\n"
	.string "been digging here recently.$"

Route111_EventScript_Archaeologist_Text_5:
# 890 "data/maps/Route111/scripts.pory"
	.string "The ARCHAEOLOGIST laid the three\n"
	.string "tablets side by side in the sand.$"

Route111_EventScript_Archaeologist_Text_6:
# 894 "data/maps/Route111/scripts.pory"
	.string "The ARCHAEOLOGIST pulled an ornate\n"
	.string "glass from his satchel…$"

Route111_EventScript_Archaeologist_Text_7:
# 906 "data/maps/Route111/scripts.pory"
	.string "Thanks to you, I was able to\n"
	.string "solve the puzzle!$"

Route111_EventScript_TimeShrineTrigger_Text_0:
# 915 "data/maps/Route111/scripts.pory"
	.string "The sand shifts beneath your feet, and\n"
	.string "a hidden stairway opens into the earth!\p"
	.string "The warmth of ancient time calls to\n"
	.string "you...$"

Route111_EventScript_TimeShrineSealed_Text_0:
# 927 "data/maps/Route111/scripts.pory"
	.string "The ground here feels strangely warm,\n"
	.string "as if something sleeps beneath.\p"
	.string "A scholar of the ancient world might\n"
	.string "know how to awaken it.$"

Route111_Sign_FirstClue_Text_0:
# 953 "data/maps/Route111/scripts.pory"
	.string "The rock is heavy, but it can be\n"
	.string "lifted with some effort.$"

Route111_Sign_FirstClue_Text_1:
# 954 "data/maps/Route111/scripts.pory"
	.string "Lift the heavy rock?$"

Route111_Sign_FirstClue_Text_2:
# 965 "data/maps/Route111/scripts.pory"
	.string "An imprint of a tablet can be seen\n"
	.string "beneath the rock.$"

Route111_Text_ArchaeologistFirstMeeting::
# 721 "data/maps/Route111/scripts.pory"
	.string "Ah, a fellow explorer!\p"
	.string "I'm an ARCHAEOLOGIST, and I'm here to\n"
	.string "investigate the mysteries of HOENN!\p"
	.string "Have you heard the rumors about the\n"
	.string "FORCES OF NATURE?\p"
	.string "I have been studying these LEGENDARY\n"
	.string "POKéMON from a distant region.\p"
	.string "I'm following a puzzle I found in UNOVA,\n"
	.string "and it led me here!$"

Route111_Text_ArchaeologistFirstClueHint::
# 729 "data/maps/Route111/scripts.pory"
	.string "I'm stuck on the first clue:\p"
	.string "“Beneath a rock near the DESERT RUINS\n"
	.string "entrance, the first sleeps.”\p"
	.string "Wherever that could be…$"

Route111_Text_ArchaeologistWindTablet::
# 735 "data/maps/Route111/scripts.pory"
	.string "It's a WIND TABLET?\p"
	.string "I wonder if there are more\n"
	.string "tablets like this one.$"

Route111_Text_ArchaeologistSecondClueRiddle::
# 740 "data/maps/Route111/scripts.pory"
	.string "Here's the next clue in the puzzle:\p"
	.string "By the first stair that climbs the sky,\n"
	.string "beside its foot the next clue lies.$"

Route111_Text_ArchaeologistBoltTabletFound::
# 745 "data/maps/Route111/scripts.pory"
	.string "There is one part of the puzzle left.\n"
	.string "Perhaps it will lead to the final tablet!\p"
	.string "I've deciphered the last clue,\n"
	.string "and it says…$"

Route111_Text_ArchaeologistThirdClueHint::
# 750 "data/maps/Route111/scripts.pory"
	.string "Could it be…\n"
	.string "that someone found it already?\p"
	.string "Wait. I spoke with a merchant last week\n"
	.string "in MAUVILLE CITY.\p"
	.string "He mentioned that someone sold him a\n"
	.string "sandy relic.\p"
	.string "I figured it was probably a fossil, but…\p"
	.string "If we're lucky, the merchant\n"
	.string "might still have it!$"

Route111_Text_ArchaeologistEarthTabletFound::
# 758 "data/maps/Route111/scripts.pory"
	.string "You found the EARTH TABLET!\p"
	.string "To think it was sitting in that\n"
	.string "POKéMART this whole time.\p"
	.string "With all three tablets, I can decipher\n"
	.string "the mystery of the FORCES OF NATURE!$"

Route111_Text_ArchaeologistTwoForms::
# 764 "data/maps/Route111/scripts.pory"
	.string "Extraordinary… the engravings\n"
	.string "depict two forms.\p"
	.string "One wild and free.\n"
	.string "The other bound and purposeful.\p"
	.string "Of course! I brought this from UNOVA\n"
	.string "when I began my expedition.$"

Route111_Text_ArchaeologistRevealGlassExplanation::
# 770 "data/maps/Route111/scripts.pory"
	.string "Through the REVEAL GLASS, the\n"
	.string "engravings seem almost… alive.\p"
	.string "Yes! This confirms everything. The\n"
	.string "FORCES OF NATURE have a true\l"
	.string "form beyond what we know.\p"
	.string "I have documented everything I need.\n"
	.string "My research is complete.\p"
	.string "This REVEAL GLASS led me to the\n"
	.string "greatest discovery of my career.\p"
	.string "But my work is done. Take it.\n"
	.string "Something tells me you will have far\l"
	.string "more use for it than I will.$"

Route111_Text_ArchaeologistFinalAdvice::
# 778 "data/maps/Route111/scripts.pory"
	.string "Use it well. And if you ever find\nyourself in UNOVA… look up at the sky.$"
