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
	waitstate
# 113 "data/maps/Route111/scripts.pory"
	delay 24
# 114 "data/maps/Route111/scripts.pory"
	playse SE_FALL
# 115 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_PLAYER_FALLING
# 116 "data/maps/Route111/scripts.pory"
	special StartPlayerDescendMirageTower
# 117 "data/maps/Route111/scripts.pory"
	waitstate
# 118 "data/maps/Route111/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_LITTLEROOT_TOWN
# 119 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
# 120 "data/maps/Route111/scripts.pory"
	delay 16
# 121 "data/maps/Route111/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 122 "data/maps/Route111/scripts.pory"
	delay 16
# 123 "data/maps/Route111/scripts.pory"
	special StartMirageTowerDisintegration
# 124 "data/maps/Route111/scripts.pory"
	waitstate
# 125 "data/maps/Route111/scripts.pory"
	special StartMirageTowerFossilFallAndSink
# 126 "data/maps/Route111/scripts.pory"
	waitstate
# 127 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 2
# 128 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 129 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
# 130 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
# 131 "data/maps/Route111/scripts.pory"
	releaseall
# 132 "data/maps/Route111/scripts.pory"
	end
# 133 "data/maps/Route111/scripts.pory"

# 134 "data/maps/Route111/scripts.pory"
Route111_EventScript_RootFossilDisappeared::
# 135 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
# 136 "data/maps/Route111/scripts.pory"
	releaseall
# 137 "data/maps/Route111/scripts.pory"
	end
# 138 "data/maps/Route111/scripts.pory"

# 139 "data/maps/Route111/scripts.pory"
@ Unused
# 140 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall::
# 141 "data/maps/Route111/scripts.pory"
	lock_anim
# 142 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 143 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 145 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 146 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 147 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 148 "data/maps/Route111/scripts.pory"
	step_end
# 149 "data/maps/Route111/scripts.pory"

# 150 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl::
# 151 "data/maps/Route111/scripts.pory"
	lock
# 152 "data/maps/Route111/scripts.pory"
	faceplayer
# 153 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 154 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 155 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 156 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 157 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 158 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 159 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 160 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 161 "data/maps/Route111/scripts.pory"
	release
# 162 "data/maps/Route111/scripts.pory"
	end
# 163 "data/maps/Route111/scripts.pory"

# 164 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry::
# 165 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 166 "data/maps/Route111/scripts.pory"
	release
# 167 "data/maps/Route111/scripts.pory"
	end
# 168 "data/maps/Route111/scripts.pory"

# 169 "data/maps/Route111/scripts.pory"
@ Unused
# 170 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp::
# 171 "data/maps/Route111/scripts.pory"
	lockall
# 172 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 173 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 174 "data/maps/Route111/scripts.pory"
	end
# 175 "data/maps/Route111/scripts.pory"

# 176 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown::
# 177 "data/maps/Route111/scripts.pory"
	lockall
# 178 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 179 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 180 "data/maps/Route111/scripts.pory"
	end
# 181 "data/maps/Route111/scripts.pory"

# 182 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft::
# 183 "data/maps/Route111/scripts.pory"
	lockall
# 184 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 185 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 186 "data/maps/Route111/scripts.pory"
	end
# 187 "data/maps/Route111/scripts.pory"

# 188 "data/maps/Route111/scripts.pory"
@ Unused
# 189 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight::
# 190 "data/maps/Route111/scripts.pory"
	lockall
# 191 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 192 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 193 "data/maps/Route111/scripts.pory"
	end
# 194 "data/maps/Route111/scripts.pory"

# 195 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger::
# 196 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES
# 197 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
# 198 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 199 "data/maps/Route111/scripts.pory"
	releaseall
# 200 "data/maps/Route111/scripts.pory"
	end
# 201 "data/maps/Route111/scripts.pory"

# 202 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess::
# 203 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 204 "data/maps/Route111/scripts.pory"
	closemessage
# 205 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
# 206 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
# 207 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
# 208 "data/maps/Route111/scripts.pory"
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
# 209 "data/maps/Route111/scripts.pory"
	releaseall
# 210 "data/maps/Route111/scripts.pory"
	end
# 211 "data/maps/Route111/scripts.pory"

# 212 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute::
# 213 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute
# 214 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 215 "data/maps/Route111/scripts.pory"
	return
# 216 "data/maps/Route111/scripts.pory"

# 217 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute::
# 218 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushDownFromRoute
# 219 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 220 "data/maps/Route111/scripts.pory"
	return
# 221 "data/maps/Route111/scripts.pory"

# 222 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute::
# 223 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushLeftFromRoute
# 224 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 225 "data/maps/Route111/scripts.pory"
	return
# 226 "data/maps/Route111/scripts.pory"

# 227 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute::
# 228 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_PushRightFromRoute
# 229 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route111/scripts.pory"
	return
# 231 "data/maps/Route111/scripts.pory"

# 232 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute:
# 233 "data/maps/Route111/scripts.pory"
	walk_up
# 234 "data/maps/Route111/scripts.pory"
	step_end
# 235 "data/maps/Route111/scripts.pory"

# 236 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute:
# 237 "data/maps/Route111/scripts.pory"
	walk_down
# 238 "data/maps/Route111/scripts.pory"
	step_end
# 239 "data/maps/Route111/scripts.pory"

# 240 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute:
# 241 "data/maps/Route111/scripts.pory"
	walk_left
# 242 "data/maps/Route111/scripts.pory"
	step_end
# 243 "data/maps/Route111/scripts.pory"

# 244 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute:
# 245 "data/maps/Route111/scripts.pory"
	walk_right
# 246 "data/maps/Route111/scripts.pory"
	step_end
# 247 "data/maps/Route111/scripts.pory"

# 248 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger::
# 249 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 250 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 251 "data/maps/Route111/scripts.pory"
	doweather
# 252 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 253 "data/maps/Route111/scripts.pory"
	end
# 254 "data/maps/Route111/scripts.pory"

# 255 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger::
# 256 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 257 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_DESERT
# 258 "data/maps/Route111/scripts.pory"
	doweather
# 259 "data/maps/Route111/scripts.pory"
	end
# 260 "data/maps/Route111/scripts.pory"

# 261 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor::
# 262 "data/maps/Route111/scripts.pory"
	lock
# 263 "data/maps/Route111/scripts.pory"
	faceplayer
# 264 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 265 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 266 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
# 267 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 268 "data/maps/Route111/scripts.pory"
	release
# 269 "data/maps/Route111/scripts.pory"
	end
# 270 "data/maps/Route111/scripts.pory"

# 271 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates::
# 272 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 273 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 274 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTOR, Common_Movement_WalkInPlaceFasterUp
# 275 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 276 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 277 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 278 "data/maps/Route111/scripts.pory"
	closemessage
# 279 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTOR, Route111_Movement_WinstrateEnterHouse
# 280 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 281 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICTOR
# 282 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 283 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 284 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 285 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 286 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VICTORIA
# 287 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateExitHouse
# 288 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 289 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 290 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 291 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 292 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Common_Movement_WalkInPlaceFasterUp
# 293 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 294 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 295 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 296 "data/maps/Route111/scripts.pory"
	closemessage
# 297 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 298 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 299 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICTORIA
# 300 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 301 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 302 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 303 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 304 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VIVI
# 305 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateExitHouse
# 306 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 307 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 308 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 309 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 310 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Common_Movement_WalkInPlaceFasterUp
# 311 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 312 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 313 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 314 "data/maps/Route111/scripts.pory"
	closemessage
# 315 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VIVI, Route111_Movement_WinstrateEnterHouse
# 316 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 317 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VIVI
# 318 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 319 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 320 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 321 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 322 "data/maps/Route111/scripts.pory"
	addobject LOCALID_ROUTE111_VICKY
# 323 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateExitHouse
# 324 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 325 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 326 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 327 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 328 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 329 "data/maps/Route111/scripts.pory"
	closemessage
# 330 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Common_Movement_WalkInPlaceFasterUp
# 331 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 332 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 333 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_VICKY, Route111_Movement_WinstrateEnterHouse
# 334 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 335 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_ROUTE111_VICKY
# 336 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 337 "data/maps/Route111/scripts.pory"
	release
# 338 "data/maps/Route111/scripts.pory"
	end
# 339 "data/maps/Route111/scripts.pory"

# 340 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor::
# 341 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 342 "data/maps/Route111/scripts.pory"
	waitdooranim
# 343 "data/maps/Route111/scripts.pory"
	return
# 344 "data/maps/Route111/scripts.pory"

# 345 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor::
# 346 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 347 "data/maps/Route111/scripts.pory"
	waitdooranim
# 348 "data/maps/Route111/scripts.pory"
	return
# 349 "data/maps/Route111/scripts.pory"

# 350 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse:
# 351 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 352 "data/maps/Route111/scripts.pory"
	walk_up
# 353 "data/maps/Route111/scripts.pory"
	step_end
# 354 "data/maps/Route111/scripts.pory"

# 355 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse:
# 356 "data/maps/Route111/scripts.pory"
	walk_down
# 357 "data/maps/Route111/scripts.pory"
	step_end
# 358 "data/maps/Route111/scripts.pory"

# 359 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate:
# 360 "data/maps/Route111/scripts.pory"
	delay_16
# 361 "data/maps/Route111/scripts.pory"
	delay_16
# 362 "data/maps/Route111/scripts.pory"
	delay_16
# 363 "data/maps/Route111/scripts.pory"
	step_end
# 364 "data/maps/Route111/scripts.pory"

# 365 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville::
# 366 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 367 "data/maps/Route111/scripts.pory"
	end
# 368 "data/maps/Route111/scripts.pory"

# 369 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign::
# 370 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 371 "data/maps/Route111/scripts.pory"
	end
# 372 "data/maps/Route111/scripts.pory"

# 373 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112::
# 374 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 375 "data/maps/Route111/scripts.pory"
	end
# 376 "data/maps/Route111/scripts.pory"

# 377 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113::
# 378 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 379 "data/maps/Route111/scripts.pory"
	end
# 380 "data/maps/Route111/scripts.pory"

# 381 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign::
# 382 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 383 "data/maps/Route111/scripts.pory"
	end
# 384 "data/maps/Route111/scripts.pory"

# 385 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef::
# 386 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 387 "data/maps/Route111/scripts.pory"
	end
# 388 "data/maps/Route111/scripts.pory"

# 389 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1::
# 390 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 391 "data/maps/Route111/scripts.pory"
	end
# 392 "data/maps/Route111/scripts.pory"

# 393 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2::
# 394 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 395 "data/maps/Route111/scripts.pory"
	end
# 396 "data/maps/Route111/scripts.pory"

# 397 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker::
# 398 "data/maps/Route111/scripts.pory"
	lock
# 399 "data/maps/Route111/scripts.pory"
	faceplayer
# 400 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
# 401 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
# 402 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 403 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 404 "data/maps/Route111/scripts.pory"
	release
# 405 "data/maps/Route111/scripts.pory"
	end
# 406 "data/maps/Route111/scripts.pory"

# 407 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone::
# 408 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 409 "data/maps/Route111/scripts.pory"
	release
# 410 "data/maps/Route111/scripts.pory"
	end
# 411 "data/maps/Route111/scripts.pory"

# 412 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated::
# 413 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 414 "data/maps/Route111/scripts.pory"
	release
# 415 "data/maps/Route111/scripts.pory"
	end
# 416 "data/maps/Route111/scripts.pory"

# 417 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible::
# 418 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 419 "data/maps/Route111/scripts.pory"
	release
# 420 "data/maps/Route111/scripts.pory"
	end
# 421 "data/maps/Route111/scripts.pory"

# 422 "data/maps/Route111/scripts.pory"
Route111_EventScript_RockSmashTipFatMan::
# 423 "data/maps/Route111/scripts.pory"
	lockall
# 424 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FacePlayer
# 425 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 426 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
# 427 "data/maps/Route111/scripts.pory"
	closemessage
# 428 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ROUTE111_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
# 429 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 430 "data/maps/Route111/scripts.pory"
	releaseall
# 431 "data/maps/Route111/scripts.pory"
	end
# 432 "data/maps/Route111/scripts.pory"

# 433 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew::
# 434 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 435 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 436 "data/maps/Route111/scripts.pory"
	end
# 437 "data/maps/Route111/scripts.pory"

# 438 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi::
# 439 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 440 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 441 "data/maps/Route111/scripts.pory"
	end
# 442 "data/maps/Route111/scripts.pory"

# 443 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau::
# 444 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 445 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 446 "data/maps/Route111/scripts.pory"
	end
# 447 "data/maps/Route111/scripts.pory"

# 448 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky::
# 449 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 450 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 451 "data/maps/Route111/scripts.pory"
	end
# 452 "data/maps/Route111/scripts.pory"

# 453 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty::
# 454 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 455 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 456 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
# 457 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 458 "data/maps/Route111/scripts.pory"
	release
# 459 "data/maps/Route111/scripts.pory"
	end
# 460 "data/maps/Route111/scripts.pory"

# 461 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty::
# 462 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 463 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 464 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 465 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 466 "data/maps/Route111/scripts.pory"
	release
# 467 "data/maps/Route111/scripts.pory"
	end
# 468 "data/maps/Route111/scripts.pory"

# 469 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty::
# 470 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 471 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 472 "data/maps/Route111/scripts.pory"
	end
# 473 "data/maps/Route111/scripts.pory"

# 474 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis::
# 475 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 476 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 477 "data/maps/Route111/scripts.pory"
	end
# 478 "data/maps/Route111/scripts.pory"

# 479 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene::
# 480 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 481 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 482 "data/maps/Route111/scripts.pory"
	end
# 483 "data/maps/Route111/scripts.pory"

# 484 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke::
# 485 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 486 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 487 "data/maps/Route111/scripts.pory"
	end
# 488 "data/maps/Route111/scripts.pory"

# 489 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton::
# 490 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 491 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 492 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
# 493 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 494 "data/maps/Route111/scripts.pory"
	release
# 495 "data/maps/Route111/scripts.pory"
	end
# 496 "data/maps/Route111/scripts.pory"

# 497 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton::
# 498 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 499 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 500 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 501 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 502 "data/maps/Route111/scripts.pory"
	release
# 503 "data/maps/Route111/scripts.pory"
	end
# 504 "data/maps/Route111/scripts.pory"

# 505 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton::
# 506 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 507 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 508 "data/maps/Route111/scripts.pory"
	end
# 509 "data/maps/Route111/scripts.pory"

# 510 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke::
# 511 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 512 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 513 "data/maps/Route111/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
# 514 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 515 "data/maps/Route111/scripts.pory"
	release
# 516 "data/maps/Route111/scripts.pory"
	end
# 517 "data/maps/Route111/scripts.pory"

# 518 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke::
# 519 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 520 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 521 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 522 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 523 "data/maps/Route111/scripts.pory"
	release
# 524 "data/maps/Route111/scripts.pory"
	end
# 525 "data/maps/Route111/scripts.pory"

# 526 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke::
# 527 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 528 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 529 "data/maps/Route111/scripts.pory"
	end
# 530 "data/maps/Route111/scripts.pory"

# 531 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden::
# 532 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 533 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 534 "data/maps/Route111/scripts.pory"
	end
# 535 "data/maps/Route111/scripts.pory"

# 536 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca::
# 537 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 538 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 539 "data/maps/Route111/scripts.pory"
	end
# 540 "data/maps/Route111/scripts.pory"

# 541 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron::
# 542 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 543 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 544 "data/maps/Route111/scripts.pory"
	end
# 545 "data/maps/Route111/scripts.pory"

# 546 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina::
# 547 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 548 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 549 "data/maps/Route111/scripts.pory"
	end
# 550 "data/maps/Route111/scripts.pory"

# 551 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia::
# 552 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 553 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 554 "data/maps/Route111/scripts.pory"
	end
# 555 "data/maps/Route111/scripts.pory"

# 556 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan::
# 557 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 558 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 559 "data/maps/Route111/scripts.pory"
	end
# 560 "data/maps/Route111/scripts.pory"

# 561 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden::
# 562 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 563 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 564 "data/maps/Route111/scripts.pory"
	end
# 565 "data/maps/Route111/scripts.pory"

# 566 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign::
# 567 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 568 "data/maps/Route111/scripts.pory"
	end
# 569 "data/maps/Route111/scripts.pory"

# 570 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily:
# 571 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 572 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 573 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 574 "data/maps/Route111/scripts.pory"
	.string "POKéMON battles?$"
# 575 "data/maps/Route111/scripts.pory"

# 576 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo:
# 577 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 578 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 579 "data/maps/Route111/scripts.pory"

# 580 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro:
# 581 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 582 "data/maps/Route111/scripts.pory"

# 583 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat:
# 584 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 585 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 586 "data/maps/Route111/scripts.pory"

# 587 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle:
# 588 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 589 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong TRAINER!$"
# 590 "data/maps/Route111/scripts.pory"

# 591 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro:
# 592 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 593 "data/maps/Route111/scripts.pory"
	.string "You must be quite the TRAINER to beat\n"
# 594 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 595 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 596 "data/maps/Route111/scripts.pory"

# 597 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat:
# 598 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 599 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 600 "data/maps/Route111/scripts.pory"

# 601 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle:
# 602 "data/maps/Route111/scripts.pory"
	.string "There's a strong TRAINER here!\n"
# 603 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 604 "data/maps/Route111/scripts.pory"

# 605 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro:
# 606 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 607 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 608 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 609 "data/maps/Route111/scripts.pory"

# 610 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat:
# 611 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 612 "data/maps/Route111/scripts.pory"

# 613 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle:
# 614 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 615 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 616 "data/maps/Route111/scripts.pory"

# 617 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro:
# 618 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 619 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 620 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 621 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 622 "data/maps/Route111/scripts.pory"

# 623 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat:
# 624 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 625 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 626 "data/maps/Route111/scripts.pory"

# 627 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle:
# 628 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 629 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 630 "data/maps/Route111/scripts.pory"

# 631 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks:
# 632 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your POKéMON some\n"
# 633 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 634 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 635 "data/maps/Route111/scripts.pory"
	.string "I've heard the POKéMON LEAGUE's\n"
# 636 "data/maps/Route111/scripts.pory"
	.string "ELITE FOUR are far stronger than\l"
# 637 "data/maps/Route111/scripts.pory"
	.string "any GYM LEADER.$"
# 638 "data/maps/Route111/scripts.pory"

# 639 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe:
# 640 "data/maps/Route111/scripts.pory"
	.string "I challenged the WINSTRATE family,\n"
# 641 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 642 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 643 "data/maps/Route111/scripts.pory"

# 644 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville:
# 645 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 646 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} MAUVILLE CITY$"
# 647 "data/maps/Route111/scripts.pory"

# 648 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign:
# 649 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 650 "data/maps/Route111/scripts.pory"
	.string "THE WINSTRATE'S HOUSE$"
# 651 "data/maps/Route111/scripts.pory"

# 652 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112:
# 653 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 654 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 112$"
# 655 "data/maps/Route111/scripts.pory"

# 656 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113:
# 657 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111\n"
# 658 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 113$"
# 659 "data/maps/Route111/scripts.pory"

# 660 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign:
# 661 "data/maps/Route111/scripts.pory"
	.string "OLD LADY'S REST STOP\n"
# 662 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 663 "data/maps/Route111/scripts.pory"

# 664 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef:
# 665 "data/maps/Route111/scripts.pory"
	.string "TRAINER TIPS\p"
# 666 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a POKéMON's\n"
# 667 "data/maps/Route111/scripts.pory"
	.string "powerfulness is SP. ATK. It stands for\l"
# 668 "data/maps/Route111/scripts.pory"
	.string "“SPECIAL ATTACK.”\p"
# 669 "data/maps/Route111/scripts.pory"
	.string "Likewise, SP. DEF stands for “SPECIAL\n"
# 670 "data/maps/Route111/scripts.pory"
	.string "DEFENSE.”$"
# 671 "data/maps/Route111/scripts.pory"

# 672 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere:
# 673 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 674 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 675 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 676 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 677 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the MIRAGE TOWER.$"
# 678 "data/maps/Route111/scripts.pory"

# 679 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible:
# 680 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 681 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 682 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 683 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 684 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 685 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 686 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 687 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 688 "data/maps/Route111/scripts.pory"

# 689 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown:
# 690 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 691 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 692 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 693 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 694 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 695 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 696 "data/maps/Route111/scripts.pory"

# 697 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince:
# 698 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 699 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 700 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 701 "data/maps/Route111/scripts.pory"
	.string "the MIRAGE TOWER…$"
# 702 "data/maps/Route111/scripts.pory"

# 703 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared:
# 704 "data/maps/Route111/scripts.pory"
	.string "The CLAW FOSSIL disappeared into\n"
# 705 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 706 "data/maps/Route111/scripts.pory"

# 707 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared:
# 708 "data/maps/Route111/scripts.pory"
	.string "The ROOT FOSSIL disappeared into\n"
# 709 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 710 "data/maps/Route111/scripts.pory"

# 711 "data/maps/Route111/scripts.pory"
Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
# 712 "data/maps/Route111/scripts.pory"
	.string "Oh, no!\p"
# 713 "data/maps/Route111/scripts.pory"
	.string "My uncle in MAUVILLE told me to take\n"
# 714 "data/maps/Route111/scripts.pory"
	.string "ROCK SMASH with me if I was going to\l"
# 715 "data/maps/Route111/scripts.pory"
	.string "ROUTE 111!\p"
# 716 "data/maps/Route111/scripts.pory"
	.string "My uncle? He lives across from\n"
# 717 "data/maps/Route111/scripts.pory"
	.string "the bike shop in MAUVILLE.$"
# 718 "data/maps/Route111/scripts.pory"

# 719 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign:
# 720 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} TRAINER HILL ENTRANCE\p"
# 721 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 722 "data/maps/Route111/scripts.pory"
	.string "TRAINERS!”$"

Route111_EventScript_Archaeologist::
# 787 "data/maps/Route111/scripts.pory"
	lockall
# 788 "data/maps/Route111/scripts.pory"
	faceplayer
# 789 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MET_ARCHAEOLOGIST, MetArchaeologist
# 792 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistFirstMeeting
# 793 "data/maps/Route111/scripts.pory"
	setflag FLAG_MET_ARCHAEOLOGIST
# 795 "data/maps/Route111/scripts.pory"
MetArchaeologist:
# 796 "data/maps/Route111/scripts.pory"
	checkitem ITEM_WIND_TABLET, 1
# 797 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_Archaeologist_2
# 797 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_GAVE_WIND_TABLET, Route111_EventScript_Archaeologist_2
Route111_EventScript_Archaeologist_1:
# 803 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistFirstClueHint
# 804 "data/maps/Route111/scripts.pory"
	releaseall
# 805 "data/maps/Route111/scripts.pory"
	end
# 807 "data/maps/Route111/scripts.pory"
Archaeologist_FoundFirstClue:
# 808 "data/maps/Route111/scripts.pory"
	checkitem ITEM_BOLT_TABLET, 1
# 809 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_Archaeologist_7
# 809 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_GAVE_BOLT_TABLET, Route111_EventScript_Archaeologist_7
Route111_EventScript_Archaeologist_6:
# 814 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_FOUND_FIRST_CLUE, Archaeologist_SecondClue
# 817 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_0
# 818 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, ITEM_WIND_TABLET
# 819 "data/maps/Route111/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 820 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_GAVE_WIND_TABLET
# 821 "data/maps/Route111/scripts.pory"
	waitse
# 822 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistWindTablet
# 823 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_FOUND_FIRST_CLUE
# 825 "data/maps/Route111/scripts.pory"
Archaeologist_SecondClue:
# 827 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistSecondClueRiddle
# 828 "data/maps/Route111/scripts.pory"
	delay 2
# 829 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_1
# 830 "data/maps/Route111/scripts.pory"
	releaseall
# 831 "data/maps/Route111/scripts.pory"
	end
# 833 "data/maps/Route111/scripts.pory"
Archaeologist_FoundSecondClue:
# 834 "data/maps/Route111/scripts.pory"
	checkitem ITEM_EARTH_TABLET, 1
# 835 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_Archaeologist_12
# 835 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_GAVE_EARTH_TABLET, Route111_EventScript_Archaeologist_12
Route111_EventScript_Archaeologist_11:
# 840 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_LOOK_THIRD_CLUE, Archaeologist_ThirdClue
# 843 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_2
# 844 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, ITEM_BOLT_TABLET
# 845 "data/maps/Route111/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 846 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_GAVE_BOLT_TABLET
# 848 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistBoltTabletFound
# 849 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ARCHAEOLOGIST, Route111_EventScript_Archaeologist_Movement_0
# 853 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 854 "data/maps/Route111/scripts.pory"
	playse SE_PIN
# 855 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ARCHAEOLOGIST, Common_Movement_ExclamationMark
# 856 "data/maps/Route111/scripts.pory"
	waitse
# 857 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 858 "data/maps/Route111/scripts.pory"
	faceplayer
# 860 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_3
# 861 "data/maps/Route111/scripts.pory"
	playse SE_M_SAND_ATTACK
# 862 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_ARCHAEOLOGIST, Route111_EventScript_Archaeologist_Movement_1
# 872 "data/maps/Route111/scripts.pory"
	waitse
# 873 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 874 "data/maps/Route111/scripts.pory"
	closemessage
# 875 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_4
# 876 "data/maps/Route111/scripts.pory"
	faceplayer
# 877 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_LOOK_THIRD_CLUE
# 879 "data/maps/Route111/scripts.pory"
Archaeologist_ThirdClue:
# 881 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistThirdClueHint
# 882 "data/maps/Route111/scripts.pory"
	releaseall
# 883 "data/maps/Route111/scripts.pory"
	end
# 885 "data/maps/Route111/scripts.pory"
Archaeologist_FoundThirdClue:
# 886 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_FOUND_ALL_CLUES, Archaeologist_FoundAllClues
# 889 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistEarthTabletFound
# 890 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, ITEM_EARTH_TABLET
# 891 "data/maps/Route111/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 892 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_GAVE_EARTH_TABLET
# 894 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_5
# 895 "data/maps/Route111/scripts.pory"
	delay 16
# 896 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistTwoForms
# 897 "data/maps/Route111/scripts.pory"
	delay 16
# 898 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_6
# 899 "data/maps/Route111/scripts.pory"
	delay 16
# 900 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistRevealGlassExplanation
# 902 "data/maps/Route111/scripts.pory"
	giveitem ITEM_REVEAL_GLASS
# 903 "data/maps/Route111/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_FOUND_ALL_CLUES
# 904 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ArchaeologistFinalAdvice
# 905 "data/maps/Route111/scripts.pory"
	releaseall
# 906 "data/maps/Route111/scripts.pory"
	end
# 908 "data/maps/Route111/scripts.pory"
Archaeologist_FoundAllClues:
# 910 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Archaeologist_Text_7
# 911 "data/maps/Route111/scripts.pory"
	releaseall
	return

Route111_EventScript_Archaeologist_2:
# 799 "data/maps/Route111/scripts.pory"
	goto Archaeologist_FoundFirstClue
	goto Route111_EventScript_Archaeologist_1

Route111_EventScript_Archaeologist_7:
# 811 "data/maps/Route111/scripts.pory"
	goto Archaeologist_FoundSecondClue
	goto Route111_EventScript_Archaeologist_6

Route111_EventScript_Archaeologist_12:
# 837 "data/maps/Route111/scripts.pory"
	goto Archaeologist_FoundThirdClue
	goto Route111_EventScript_Archaeologist_11


Route111_EventScript_TimeShrineTrigger::
# 915 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_2, 1
# 916 "data/maps/Route111/scripts.pory"
	playse SE_PIN
# 917 "data/maps/Route111/scripts.pory"
	goto_if_unset FLAG_TALKED_TO_HISTORIAN, Route111_EventScript_TimeShrineSealed
# 918 "data/maps/Route111/scripts.pory"
	lockall
# 919 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_TimeShrineTrigger_Text_0
# 921 "data/maps/Route111/scripts.pory"
	releaseall
# 922 "data/maps/Route111/scripts.pory"
	playse SE_WARP_IN
# 923 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_PLAYER, Route111_Movement_ShrineWarpSpin
# 924 "data/maps/Route111/scripts.pory"
	delay 30
# 925 "data/maps/Route111/scripts.pory"
	warp MAP_TIME_SHRINE, 0
	end


Route111_EventScript_TimeShrineSealed::
# 930 "data/maps/Route111/scripts.pory"
	lockall
# 931 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_TimeShrineSealed_Text_0
# 933 "data/maps/Route111/scripts.pory"
	releaseall
	end


# 937 "data/maps/Route111/scripts.pory"
Route111_Movement_ShrineWarpSpin:
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
	walk_in_place_faster_down
# 947 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_left
# 948 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_up
# 949 "data/maps/Route111/scripts.pory"
	walk_in_place_faster_right
# 950 "data/maps/Route111/scripts.pory"
	step_end

Route111_Sign_FirstClue::
# 954 "data/maps/Route111/scripts.pory"
	lockall
# 955 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHECKED_ROUTE_111_ROCK, CheckedRock
# 957 "data/maps/Route111/scripts.pory"
	msgbox Route111_Sign_FirstClue_Text_0
# 958 "data/maps/Route111/scripts.pory"
	msgbox Route111_Sign_FirstClue_Text_1, MSGBOX_YESNO
# 959 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route111_Sign_FirstClue_2
Route111_Sign_FirstClue_1:
# 965 "data/maps/Route111/scripts.pory"
	releaseall
# 966 "data/maps/Route111/scripts.pory"
	end
# 968 "data/maps/Route111/scripts.pory"
CheckedRock:
# 969 "data/maps/Route111/scripts.pory"
	msgbox Route111_Sign_FirstClue_Text_2
# 970 "data/maps/Route111/scripts.pory"
	releaseall
	return

Route111_Sign_FirstClue_2:
# 960 "data/maps/Route111/scripts.pory"
	playse SE_M_SAND_ATTACK
# 961 "data/maps/Route111/scripts.pory"
	waitse
# 962 "data/maps/Route111/scripts.pory"
	giveitem ITEM_WIND_TABLET
# 963 "data/maps/Route111/scripts.pory"
	setflag FLAG_CHECKED_ROUTE_111_ROCK
	goto Route111_Sign_FirstClue_1


# 849 "data/maps/Route111/scripts.pory"
Route111_EventScript_Archaeologist_Movement_0:
# 850 "data/maps/Route111/scripts.pory"
	face_right
# 851 "data/maps/Route111/scripts.pory"
	delay_16
	step_end

# 862 "data/maps/Route111/scripts.pory"
Route111_EventScript_Archaeologist_Movement_1:
# 863 "data/maps/Route111/scripts.pory"
	face_up
# 864 "data/maps/Route111/scripts.pory"
	delay_16
# 865 "data/maps/Route111/scripts.pory"
	face_right
# 866 "data/maps/Route111/scripts.pory"
	delay_16
# 867 "data/maps/Route111/scripts.pory"
	face_up
# 868 "data/maps/Route111/scripts.pory"
	delay_16
# 869 "data/maps/Route111/scripts.pory"
	face_right
# 870 "data/maps/Route111/scripts.pory"
	delay_16
	step_end

Route111_EventScript_Archaeologist_Text_0:
# 817 "data/maps/Route111/scripts.pory"
	.string "Oh, you found the first clue!$"

Route111_EventScript_Archaeologist_Text_1:
# 829 "data/maps/Route111/scripts.pory"
	.string "I'm no good at riddles.$"

Route111_EventScript_Archaeologist_Text_2:
# 843 "data/maps/Route111/scripts.pory"
	.string "Ah, you found the BOLT TABLET!$"

Route111_EventScript_Archaeologist_Text_3:
# 860 "data/maps/Route111/scripts.pory"
	.string "According to my calculations, it should\n"
	.string "be right here!$"

Route111_EventScript_Archaeologist_Text_4:
# 875 "data/maps/Route111/scripts.pory"
	.string "That's odd, it looks as if someone has\n"
	.string "been digging here recently.$"

Route111_EventScript_Archaeologist_Text_5:
# 894 "data/maps/Route111/scripts.pory"
	.string "The ARCHAEOLOGIST laid the three\n"
	.string "tablets side by side in the sand.$"

Route111_EventScript_Archaeologist_Text_6:
# 898 "data/maps/Route111/scripts.pory"
	.string "The ARCHAEOLOGIST pulled an ornate\n"
	.string "glass from his satchel…$"

Route111_EventScript_Archaeologist_Text_7:
# 910 "data/maps/Route111/scripts.pory"
	.string "Thanks to you, I was able to\n"
	.string "solve the puzzle!$"

Route111_EventScript_TimeShrineTrigger_Text_0:
# 919 "data/maps/Route111/scripts.pory"
	.string "The sand shifts beneath your feet, and\n"
	.string "a hidden stairway opens into the earth!\p"
	.string "The warmth of ancient time calls to\n"
	.string "you...$"

Route111_EventScript_TimeShrineSealed_Text_0:
# 931 "data/maps/Route111/scripts.pory"
	.string "The ground here feels strangely warm,\n"
	.string "as if something sleeps beneath.\p"
	.string "A scholar of the ancient world might\n"
	.string "know how to awaken it.$"

Route111_Sign_FirstClue_Text_0:
# 957 "data/maps/Route111/scripts.pory"
	.string "The rock is heavy, but it can be\n"
	.string "lifted with some effort.$"

Route111_Sign_FirstClue_Text_1:
# 958 "data/maps/Route111/scripts.pory"
	.string "Lift the heavy rock?$"

Route111_Sign_FirstClue_Text_2:
# 969 "data/maps/Route111/scripts.pory"
	.string "An imprint of a tablet can be seen\n"
	.string "beneath the rock.$"

Route111_Text_ArchaeologistFirstMeeting::
# 725 "data/maps/Route111/scripts.pory"
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
# 733 "data/maps/Route111/scripts.pory"
	.string "I'm stuck on the first clue:\p"
	.string "“Beneath a rock near the DESERT RUINS\n"
	.string "entrance, the first sleeps.”\p"
	.string "Wherever that could be…$"

Route111_Text_ArchaeologistWindTablet::
# 739 "data/maps/Route111/scripts.pory"
	.string "It's a WIND TABLET?\p"
	.string "I wonder if there are more\n"
	.string "tablets like this one.$"

Route111_Text_ArchaeologistSecondClueRiddle::
# 744 "data/maps/Route111/scripts.pory"
	.string "Here's the next clue in the puzzle:\p"
	.string "By the first stair that climbs the sky,\n"
	.string "beside its foot the next clue lies.$"

Route111_Text_ArchaeologistBoltTabletFound::
# 749 "data/maps/Route111/scripts.pory"
	.string "There is one part of the puzzle left.\n"
	.string "Perhaps it will lead to the final tablet!\p"
	.string "I've deciphered the last clue,\n"
	.string "and it says…$"

Route111_Text_ArchaeologistThirdClueHint::
# 754 "data/maps/Route111/scripts.pory"
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
# 762 "data/maps/Route111/scripts.pory"
	.string "You found the EARTH TABLET!\p"
	.string "To think it was sitting in that\n"
	.string "POKéMART this whole time.\p"
	.string "With all three tablets, I can decipher\n"
	.string "the mystery of the FORCES OF NATURE!$"

Route111_Text_ArchaeologistTwoForms::
# 768 "data/maps/Route111/scripts.pory"
	.string "Extraordinary… the engravings\n"
	.string "depict two forms.\p"
	.string "One wild and free.\n"
	.string "The other bound and purposeful.\p"
	.string "Of course! I brought this from UNOVA\n"
	.string "when I began my expedition.$"

Route111_Text_ArchaeologistRevealGlassExplanation::
# 774 "data/maps/Route111/scripts.pory"
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
# 782 "data/maps/Route111/scripts.pory"
	.string "Use it well. And if you ever find\nyourself in UNOVA… look up at the sky.$"
