<<<<<<< HEAD
# 1 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 2 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_MapScripts::
# 3 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
# 4 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 6 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_OnTransition:
# 7 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
# 8 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 9 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 10 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
# 11 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	lock
# 12 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
# 14 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
# 15 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	giveitem ITEM_TM_DIG
# 16 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 17 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM_DIG
# 18 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	release
# 19 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 20 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 21 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_ReceivedDig::
# 22 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
# 23 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	release
# 24 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 25 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 26 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_RockDisplay::
# 27 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
# 28 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 29 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 30 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_Bookshelf::
# 31 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
# 32 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 33 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 34 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
# 35 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "My big brother's the FOSSIL MANIAC…\n"
# 36 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "He's a nice guy who loves FOSSILS…\p"
# 37 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "He loves digging holes, too…\n"
# 38 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "He dug this hole by himself…\p"
# 39 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "You can have this, so you can DIG\n"
# 40 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "holes just like my big brother…$"
# 41 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 42 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
# 43 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "If you make a POKéMON DIG inside a\n"
# 44 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "cave, you're returned to the entrance…$"
# 45 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 46 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
# 47 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "Rocks in peculiar shapes fill\n"
# 48 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "the display case…$"
# 49 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 50 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_CrammedWithBooks:
# 51 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "THE COMPOSITION OF STRATA…\n"
# 52 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "HOW RAIN SHAPES THE LAND…\l"
# 53 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "STONES, SOIL, AND ROCK…\p"
# 54 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "It's crammed with books.$"
=======
Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "My big brother's the FOSSIL MANIAC…\n"
	.string "He's a nice guy who loves FOSSILS…\p"
	.string "He loves digging holes, too…\n"
	.string "He dug this hole by himself…\p"
	.string "You can have this, so you can DIG\n"
	.string "holes just like my big brother…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "If you make a POKéMON DIG inside a\n"
	.string "cave, you're returned to the entrance…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Rocks in peculiar shapes fill\n"
	.string "the display case…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "THE COMPOSITION OF STRATA…\n"
	.string "HOW RAIN SHAPES THE LAND…\l"
	.string "STONES, SOIL, AND ROCK…\p"
	.string "It's crammed with books.$"

>>>>>>> upstream/master
