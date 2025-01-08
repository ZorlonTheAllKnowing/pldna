<<<<<<< HEAD
# 1 "data/maps/PetalburgCity_Mart/scripts.pory"

# 2 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_MapScripts::
# 3 "data/maps/PetalburgCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgCity_Mart/scripts.pory"

# 5 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Clerk::
# 6 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 7 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/PetalburgCity_Mart/scripts.pory"
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
# 11 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Basic
# 12 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 13 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 14 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 15 "data/maps/PetalburgCity_Mart/scripts.pory"

# 16 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 17 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Basic:
# 18 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 19 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 20 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 21 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 22 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 23 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 24 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 25 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 26 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 27 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 28 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 29 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 30 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 31 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 32 "data/maps/PetalburgCity_Mart/scripts.pory"

# 33 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_ExpandedItems::
# 34 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Expanded
# 35 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 36 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 37 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 38 "data/maps/PetalburgCity_Mart/scripts.pory"

# 39 "data/maps/PetalburgCity_Mart/scripts.pory"
	.align 2
# 40 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Expanded:
# 41 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 42 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 43 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 44 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 45 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 46 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 47 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_AWAKENING
# 48 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 49 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 50 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 51 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 52 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 53 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_ORANGE_MAIL
# 54 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 55 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 56 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 57 "data/maps/PetalburgCity_Mart/scripts.pory"

# 58 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Woman::
# 59 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
# 60 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 61 "data/maps/PetalburgCity_Mart/scripts.pory"

# 62 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Boy::
# 63 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
# 64 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 65 "data/maps/PetalburgCity_Mart/scripts.pory"

# 66 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Man::
# 67 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
# 68 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 69 "data/maps/PetalburgCity_Mart/scripts.pory"

# 70 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_WeakWillGrowStronger:
# 71 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Even if a POKéMON is weak now,\n"
# 72 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "it will grow stronger.\p"
# 73 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "The most important thing is love!\n"
# 74 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Love for your POKéMON!$"
# 75 "data/maps/PetalburgCity_Mart/scripts.pory"

# 76 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_RepelIsUseful:
# 77 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you use REPEL?\n"
# 78 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "It keeps POKéMON away, so it's\l"
# 79 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "useful when you're in a hurry.$"
# 80 "data/maps/PetalburgCity_Mart/scripts.pory"

# 81 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
# 82 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you have any ANTIDOTES with\n"
# 83 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "you?\p"
# 84 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "If you walk around with a poisoned\n"
# 85 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "POKéMON, it will lose HP until it faints.\l"
# 86 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Take some ANTIDOTES with you.$"
=======
PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_ExpandedItems::
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_Woman::
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger:
	.string "Even if a POKéMON is weak now,\n"
	.string "it will grow stronger.\p"
	.string "The most important thing is love!\n"
	.string "Love for your POKéMON!$"

PetalburgCity_Mart_Text_RepelIsUseful:
	.string "Do you use REPEL?\n"
	.string "It keeps POKéMON away, so it's\l"
	.string "useful when you're in a hurry.$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
	.string "Do you have any ANTIDOTES with\n"
	.string "you?\p"
	.string "If you walk around with a poisoned\n"
	.string "POKéMON, it will lose HP until it faints.\l"
	.string "Take some ANTIDOTES with you.$"

>>>>>>> upstream/master
