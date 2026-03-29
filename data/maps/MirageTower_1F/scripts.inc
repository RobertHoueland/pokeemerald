# 1 "data/maps/MirageTower_1F/scripts.pory"

# 2 "data/maps/MirageTower_1F/scripts.pory"
MirageTower_1F_MapScripts::
# 3 "data/maps/MirageTower_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_1F_OnTransition
# 4 "data/maps/MirageTower_1F/scripts.pory"
	.byte 0
# 5 "data/maps/MirageTower_1F/scripts.pory"

# 6 "data/maps/MirageTower_1F/scripts.pory"
MirageTower_1F_OnTransition:
# 7 "data/maps/MirageTower_1F/scripts.pory"
	setflag FLAG_ENTERED_MIRAGE_TOWER
# 8 "data/maps/MirageTower_1F/scripts.pory"
	setflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 9 "data/maps/MirageTower_1F/scripts.pory"
	setflag FLAG_LANDMARK_MIRAGE_TOWER
# 10 "data/maps/MirageTower_1F/scripts.pory"
	end

MirageTower_1F_Event_SecondClue::
# 22 "data/maps/MirageTower_1F/scripts.pory"
	lockall
# 23 "data/maps/MirageTower_1F/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_FOUND_SECOND_CLUE, AlreadyHaveSecondClue
# 24 "data/maps/MirageTower_1F/scripts.pory"
	goto_if_set FLAG_ARCHAEOLOGIST_FOUND_FIRST_CLUE, SecondClueMetArchaeologist
# 26 "data/maps/MirageTower_1F/scripts.pory"
AlreadyHaveSecondClue:
# 28 "data/maps/MirageTower_1F/scripts.pory"
	msgbox MirageTower_1F_Event_SecondClue_Text_0
# 29 "data/maps/MirageTower_1F/scripts.pory"
	releaseall
# 30 "data/maps/MirageTower_1F/scripts.pory"
	end
# 32 "data/maps/MirageTower_1F/scripts.pory"
SecondClueMetArchaeologist:
# 34 "data/maps/MirageTower_1F/scripts.pory"
	addobject LOCALID_MIRAGE_TOWER_YOUNGSTER
# 35 "data/maps/MirageTower_1F/scripts.pory"
	setobjectmovementtype LOCALID_MIRAGE_TOWER_YOUNGSTER, MOVEMENT_TYPE_FACE_RIGHT
# 37 "data/maps/MirageTower_1F/scripts.pory"
	applymovement LOCALID_MIRAGE_TOWER_YOUNGSTER, MirageTower_1F_Event_SecondClue_Movement_0
# 41 "data/maps/MirageTower_1F/scripts.pory"
	waitmovement 0
# 43 "data/maps/MirageTower_1F/scripts.pory"
	msgbox MirageTower_Text_RicardFindersKeepers
# 44 "data/maps/MirageTower_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_RICARD, MirageTower_Text_RicardDefeat
# 45 "data/maps/MirageTower_1F/scripts.pory"
	giveitem ITEM_BOLT_TABLET
# 46 "data/maps/MirageTower_1F/scripts.pory"
	setflag FLAG_ARCHAEOLOGIST_FOUND_SECOND_CLUE
# 47 "data/maps/MirageTower_1F/scripts.pory"
	msgbox MirageTower_1F_Event_SecondClue_Text_1
# 48 "data/maps/MirageTower_1F/scripts.pory"
	closemessage
# 50 "data/maps/MirageTower_1F/scripts.pory"
	applymovement LOCALID_MIRAGE_TOWER_YOUNGSTER, MirageTower_1F_Event_SecondClue_Movement_1
# 53 "data/maps/MirageTower_1F/scripts.pory"
	waitmovement 0
# 54 "data/maps/MirageTower_1F/scripts.pory"
	removeobject LOCALID_MIRAGE_TOWER_YOUNGSTER
# 55 "data/maps/MirageTower_1F/scripts.pory"
	releaseall
	return


# 37 "data/maps/MirageTower_1F/scripts.pory"
MirageTower_1F_Event_SecondClue_Movement_0:
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 38 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_right
# 39 "data/maps/MirageTower_1F/scripts.pory"
	face_player
	step_end

# 50 "data/maps/MirageTower_1F/scripts.pory"
MirageTower_1F_Event_SecondClue_Movement_1:
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
# 51 "data/maps/MirageTower_1F/scripts.pory"
	walk_faster_left
	step_end

MirageTower_1F_Event_SecondClue_Text_0:
# 28 "data/maps/MirageTower_1F/scripts.pory"
	.string "A strange imprint lies in the sand,\n"
	.string "as if something was buried here.$"

MirageTower_1F_Event_SecondClue_Text_1:
# 47 "data/maps/MirageTower_1F/scripts.pory"
	.string "I couldn't read the symbols on that\n"
	.string "thing anyways.$"

MirageTower_Text_RicardFindersKeepers::
# 13 "data/maps/MirageTower_1F/scripts.pory"
	.string "Oh, are you looking for that tablet that\n"
	.string "was lying around?\p"
	.string "Finders keepers!$"

MirageTower_Text_RicardDefeat::
# 17 "data/maps/MirageTower_1F/scripts.pory"
	.string "Wow, you're really strong!\nI guess you can have the tablet.$"
