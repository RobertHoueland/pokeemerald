# 1 "data/maps/MauvilleCity_Mart/scripts.pory"

# 2 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_MapScripts::
# 3 "data/maps/MauvilleCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_Mart/scripts.pory"

# 5 "data/maps/MauvilleCity_Mart/scripts.pory"
	.align 2
# 6 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Pokemart:
# 7 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 8 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 9 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 10 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 11 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 12 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 13 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 14 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 15 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 16 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 17 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 18 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 19 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemartlistend
# 20 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Pokemart_TabletQuest:
# 21 "data/maps/MauvilleCity_Mart/scripts.pory"
    .2byte ITEM_EARTH_TABLET
# 22 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 23 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 24 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 25 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 26 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 27 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 28 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 29 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 30 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 31 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 32 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 33 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 34 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemartlistend
# 35 "data/maps/MauvilleCity_Mart/scripts.pory"

# 36 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_ExpertM::
# 37 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
# 38 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 39 "data/maps/MauvilleCity_Mart/scripts.pory"

# 40 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_Man::
# 41 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
# 42 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 43 "data/maps/MauvilleCity_Mart/scripts.pory"

# 44 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
# 45 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "There are items that temporarily\n"
# 46 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "elevate the stats of POKéMON.\p"
# 47 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "The ones I know you use in battle\n"
# 48 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "are X ATTACK and X DEFEND…\p"
# 49 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "I do believe that there are others\n"
# 50 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "like them.$"
# 51 "data/maps/MauvilleCity_Mart/scripts.pory"

# 52 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Text_DecisionsDetermineBattle:
# 53 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "Use a certain move, or use an item\n"
# 54 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "instead…\p"
# 55 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "The TRAINER's decisions determine how\n"
# 56 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "battles turn out, I think.$"

MauvilleCity_Mart_EventScript_Clerk::
# 67 "data/maps/MauvilleCity_Mart/scripts.pory"
	lockall
# 68 "data/maps/MauvilleCity_Mart/scripts.pory"
	faceplayer
# 69 "data/maps/MauvilleCity_Mart/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_LOOK_THIRD_CLUE, LookingForTablet
# 70 "data/maps/MauvilleCity_Mart/scripts.pory"
HasTablet:
# 71 "data/maps/MauvilleCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 72 "data/maps/MauvilleCity_Mart/scripts.pory"
	waitmessage
# 73 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemart MauvilleCity_Mart_Pokemart
# 74 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 75 "data/maps/MauvilleCity_Mart/scripts.pory"
	releaseall
# 76 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 78 "data/maps/MauvilleCity_Mart/scripts.pory"
LookingForTablet:
# 79 "data/maps/MauvilleCity_Mart/scripts.pory"
	checkitem ITEM_EARTH_TABLET, 1
# 80 "data/maps/MauvilleCity_Mart/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_Mart_EventScript_Clerk_2
MauvilleCity_Mart_EventScript_Clerk_1:
# 83 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Clerk_Tablet
# 84 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemart MauvilleCity_Mart_Pokemart_TabletQuest
# 85 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 86 "data/maps/MauvilleCity_Mart/scripts.pory"
	releaseall
	return

MauvilleCity_Mart_EventScript_Clerk_2:
# 81 "data/maps/MauvilleCity_Mart/scripts.pory"
	goto HasTablet
	goto MauvilleCity_Mart_EventScript_Clerk_1


MauvilleCity_Mart_Clerk_Tablet::
# 59 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "Welcome!\p"
	.string "How may I serve--\p"
	.string "Oh, you're looking for that old thing?\p"
	.string "I've got it right here! It's been\n"
	.string "getting sand everywhere.\p"
	.string "You can have it for free if you clean up\n"
	.string "the mess afterwards.$"
