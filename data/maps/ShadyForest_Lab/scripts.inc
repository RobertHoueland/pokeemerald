# 1 "data/maps/ShadyForest_Lab/scripts.pory"

# 2 "data/maps/ShadyForest_Lab/scripts.pory"
ShadyForest_Lab_MapScripts::
# 3 "data/maps/ShadyForest_Lab/scripts.pory"
	.byte 0

ShadyForest_Lab_EventScript_Myra::
# 34 "data/maps/ShadyForest_Lab/scripts.pory"
	lockall
# 35 "data/maps/ShadyForest_Lab/scripts.pory"
	faceplayer
# 36 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_MET_MYRA, Met_Myra
# 39 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox Myra_IntroText
# 40 "data/maps/ShadyForest_Lab/scripts.pory"
	setflag FLAG_MET_MYRA
# 41 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 42 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 44 "data/maps/ShadyForest_Lab/scripts.pory"
Met_Myra:
# 48 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_MYRA_PRISM_HINT, PrismHint_Given
# 50 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_OBTAINED_NECROZMA_LINE, PrismHint
# 52 "data/maps/ShadyForest_Lab/scripts.pory"
	goto Myra_Finished
# 53 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 54 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 56 "data/maps/ShadyForest_Lab/scripts.pory"
PrismHint:
# 57 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox Myra_PrismHint
# 58 "data/maps/ShadyForest_Lab/scripts.pory"
	setflag FLAG_MYRA_PRISM_HINT
# 59 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 60 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 62 "data/maps/ShadyForest_Lab/scripts.pory"
PrismHint_Given:
# 64 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_RECEIVED_SOLARIZER, Myra_Finished
# 65 "data/maps/ShadyForest_Lab/scripts.pory"
	goto_if_set FLAG_RECEIVED_LUNARIZER, Myra_Finished
# 66 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox ShadyForest_Lab_EventScript_Myra_Text_0
# 67 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 68 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 70 "data/maps/ShadyForest_Lab/scripts.pory"
Myra_Finished:
# 71 "data/maps/ShadyForest_Lab/scripts.pory"
	msgbox ShadyForest_Lab_EventScript_Myra_Text_1
# 72 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
# 73 "data/maps/ShadyForest_Lab/scripts.pory"
	end
# 75 "data/maps/ShadyForest_Lab/scripts.pory"
Mythical_Path_Unlocked:
# 77 "data/maps/ShadyForest_Lab/scripts.pory"
	releaseall
	return


ShadyForest_Lab_EventScript_Myra_Text_0:
# 66 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "MYRA: Don't forget to check out that\n"
	.string "strange fracturing light on ROUTE 114\l"
	.string "near METEOR FALLS!\p"
	.string "I'm sure it's tied to your NECROZMA-V.$"

ShadyForest_Lab_EventScript_Myra_Text_1:
# 71 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "MYRA: I think the ancient PARADOX\n"
	.string "POKéMON might be ancestors of modern\l"
	.string "POKéMON, and the future ones might be\l"
	.string "what they'll be someday. Maybe!!$"

Myra_IntroText::
# 6 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "MYRA: Oh my gosh, a visitor!\p"
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
	.string "there. Just don't annoy the big ones,\p"
	.string "I learned that the hard way.$"

Myra_PrismHint::
# 21 "data/maps/ShadyForest_Lab/scripts.pory"
	.string "Oh! You got NECROZMA-V?\p"
	.string "From DR. PARKER?\p"
	.string "That's amazing! It's like a living prism...\p"
	.string "Actually, I've been noticing something\n"
	.string "weird lately.\p"
	.string "There's this spot on ROUTE 114 near\n"
	.string "METEOR FALLS, where the light does this\l"
	.string "strange fracturing thing. It's like the\l"
	.string "air itself is splitting into rainbows.\p"
	.string "I think it might be connected to\n"
	.string "NECROZMA-V somehow. Maybe if you have\l"
	.string "the right POKéMON with you, you could\l"
	.string "unlock whatever's hiding there?$"
