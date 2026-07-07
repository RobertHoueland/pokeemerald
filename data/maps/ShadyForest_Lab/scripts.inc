# 1 "data/maps/ShadyForest_Lab/scripts.pory"

# 2 "data/maps/ShadyForest_Lab/scripts.pory"
ShadyForest_Lab_MapScripts::
# 3 "data/maps/ShadyForest_Lab/scripts.pory"
	.byte 0

ShadyForest_Lab_EventScript_Myra::
# 21 "data/maps/ShadyForest_Lab/scripts.pory"
	lockall
# 22 "data/maps/ShadyForest_Lab/scripts.pory"
	faceplayer
# 23 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_MET_MYRA, Met_Myra
# 26 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox ShadyForest_Lab_EventScript_Myra_Text_0
# 27 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox Myra_IntroText
# 28 "data/maps/ShadyForest_Lab/scripts.pory"
	setflag FLAG_MET_MYRA
# 29 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 30 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 32 "data/maps/ShadyForest_Lab/scripts.pory"
Met_Myra:
# 33 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_MYRA_MYTHICAL_PATH_UNLOCKED, Mythical_Path_Unlocked
# 34 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox ShadyForest_Lab_EventScript_Myra_Text_1
# 35 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 36 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 38 "data/maps/ShadyForest_Lab/scripts.pory"
Mythical_Path_Unlocked:
# 39 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox ShadyForest_Lab_EventScript_Myra_Text_2
# 41 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
	return


ShadyForest_Lab_EventScript_Myra_Text_0:
# 26 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "MYRA: Oh my gosh, a visitor!$"

ShadyForest_Lab_EventScript_Myra_Text_1:
# 34 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "MYRA: I think the ancient PARADOX\n"
	.string "POKéMON might be ancestors of modern\l"
	.string "POKéMON, and the future ones might be\l"
	.string "what they'll be someday. Maybe!!$"

ShadyForest_Lab_EventScript_Myra_Text_2:
# 39 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "MYRA: Hello! I need to implement this\n"
	.string "still...$"

Myra_IntroText::
# 6 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "I was starting to think nobody could\n"
	.string "find this place!\p"
	.string "I'm MYRA, and this is basically my new\n"
	.string "home. So welcome!\p"
	.string "This place is super cool actually,\n"
	.string "there's a time rift right outside\l"
	.string "apparently! It's making POKéMON from\l"
	.string "the past and the future end up here\l"
	.string "somehow.\p"
	.string "I don't really understand it all, but it's\n"
	.string "a lot of fun to watch from my window.\p"
	.string "I've been calling them PARADOX POKéMON.\n"
	.string "It seems like there's ancient ones from\l"
	.string "a longgg time ago, and ones that\l"
	.string "shouldn't even exist yet.\p"
	.string "I guess different ones show up at\n"
	.string "different times of day...\p"
	.string "Anyways, you should go explore out\n"
	.string "there. Just don't annoy the big ones, I\l"
	.string "learned that the hard way.$"
