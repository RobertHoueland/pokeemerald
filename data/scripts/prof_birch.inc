ProfBirch_EventScript_UpdateLocation::
	goto_if_eq VAR_PETALBURG_GYM_STATE, 0, Common_EventScript_NopReturn
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 0, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 1, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 2, ProfBirch_EventScript_MoveToRoute101
	call_if_eq VAR_BIRCH_STATE, 3, ProfBirch_EventScript_MoveToRoute101
	call_if_eq VAR_BIRCH_STATE, 4, ProfBirch_EventScript_MoveToRoute103
	call_if_eq VAR_BIRCH_STATE, 5, ProfBirch_EventScript_MoveToRoute103
	call_if_eq VAR_BIRCH_STATE, 6, ProfBirch_EventScript_MoveToLab
	call_if_eq VAR_BIRCH_STATE, 7, ProfBirch_EventScript_MoveToLab
	return

ProfBirch_EventScript_MoveToLab::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute101::
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

ProfBirch_EventScript_MoveToRoute103::
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	return

ProfBirch_EventScript_RatePokedexOrRegister::
	lock
	faceplayer
	goto_if_unset FLAG_SAW_BIRCH_SILVALLY_MSG, ProfBirch_EventScript_CheckSilvallyIntro
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch

ProfBirch_EventScript_CheckSilvallyIntro::
	goto_if_set FLAG_OBTAINED_TYPENULL_LINE, ProfBirch_EventScript_CheckSilvallyMemories
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch

ProfBirch_EventScript_CheckSilvallyMemories::
	setvar VAR_TEMP_2, 0
	msgbox gBirchSilvallyIntroText, MSGBOX_DEFAULT
	setflag FLAG_SAW_BIRCH_SILVALLY_MSG
	setvar VAR_TEMP_2, 1
ProfBirch_EventScript_SetupGiveMemory::
	setvar VAR_TEMP_1, 0
ProfBirch_EventScript_TryGiveMemory::
	specialvar VAR_RESULT, GetNextMemoryItemToGive
	goto_if_eq VAR_RESULT, ITEM_NONE, ProfBirch_EventScript_CheckGivenMemory
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	special BufferNextMemoryItemType
	bufferitemname STR_VAR_2, VAR_0x8004
	msgbox gBirchSilvallyGivesMemoryText, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	special SetNextMemoryItemFlag
	setvar VAR_TEMP_1, 1
	msgbox gBirchSilvallyAfterMemoryText, MSGBOX_DEFAULT
	goto ProfBirch_EventScript_TryGiveMemory

ProfBirch_EventScript_CheckGivenMemory::
	goto_if_eq VAR_TEMP_1, 1, ProfBirch_EventScript_CheckAllMemoriesGiven
	goto ProfBirch_EventScript_EndGiveMemory

ProfBirch_EventScript_CheckAllMemoriesGiven::
	specialvar VAR_RESULT, CheckHasAllMemories
	goto_if_eq VAR_RESULT, FALSE, ProfBirch_EventScript_EndGiveMemory
	msgbox gBirchSilvallyAllMemoriesGivenText, MSGBOX_DEFAULT
	goto ProfBirch_EventScript_EndGiveMemory

ProfBirch_EventScript_EndGiveMemory::
	release
	end

ProfBirch_EventScript_CheckMatchCall::
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch

gBirchSilvallyIntroText:
	.string "Ah, {PLAYER}!\n"
	.string "That POKéMON you discovered…\l"
	.string "It appears to be SILVALLY-V!\p"
	.string "I am incredibly curious where you\n"
	.string "found such a unique specimen…\l"
	.string "But I won't pry.\p"
	.string "Its potential is said to be endless,\n"
	.string "changing types depending on the\l"
	.string "RKS MEMORY CHIP it holds.\p"
	.string "In my field work, I've secured a few\n"
	.string "of these MEMORIES. I'll lend them if\l"
	.string "you impress me with your POKéDEX!$"

gBirchSilvallyGivesMemoryText:
	.string "Amazing! You've caught 5\n"
	.string "{STR_VAR_1}-type POKéMON!\p"
	.string "Please, take this MEMORY DISC!$"

gBirchSilvallyAfterMemoryText:
	.string "That MEMORY should draw out its true\n"
	.string "power!$"

gBirchSilvallyAllMemoriesGivenText:
	.string "Incredible! You've obtained every\n"
	.string "single MEMORY type I had to offer.\p"
	.string "Your dedication to the POKéDEX is\n"
	.string "truly remarkable!\p"
	.string "Please, use them well to unlock the\n"
	.string "true potential of SILVALLY-v!$"

ProfBirch_EventScript_AskRatePokedex::
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfBirch_EventScript_DeclineRating
	call ProfBirch_EventScript_RatePokedex
	goto_if_set FLAG_OBTAINED_TYPENULL_LINE, ProfBirch_EventScript_SetupGiveMemory
	release
	end

ProfBirch_EventScript_DeclineRating::
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfBirch_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfBirch_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfBirch_EventScript_ShowRatingMessage
	goto_if_eq VAR_0x800A, 0, Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num National seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num National caught
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	return
