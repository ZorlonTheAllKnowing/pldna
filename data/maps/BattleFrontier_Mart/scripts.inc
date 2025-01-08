<<<<<<< HEAD
# 1 "data/maps/BattleFrontier_Mart/scripts.pory"

# 2 "data/maps/BattleFrontier_Mart/scripts.pory"
.set LOCALID_OLD_WOMAN, 2
# 3 "data/maps/BattleFrontier_Mart/scripts.pory"

# 4 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_MapScripts::
# 5 "data/maps/BattleFrontier_Mart/scripts.pory"
	.byte 0
# 6 "data/maps/BattleFrontier_Mart/scripts.pory"

# 7 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_Clerk::
# 8 "data/maps/BattleFrontier_Mart/scripts.pory"
	lock
# 9 "data/maps/BattleFrontier_Mart/scripts.pory"
	faceplayer
# 10 "data/maps/BattleFrontier_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 11 "data/maps/BattleFrontier_Mart/scripts.pory"
	waitmessage
# 12 "data/maps/BattleFrontier_Mart/scripts.pory"
	pokemart BattleFrontier_Mart_Pokemart
# 13 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 14 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 15 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 16 "data/maps/BattleFrontier_Mart/scripts.pory"

# 17 "data/maps/BattleFrontier_Mart/scripts.pory"
	.align 2
# 18 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Pokemart:
# 19 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 20 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 21 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_MAX_POTION
# 22 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 23 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 24 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_REVIVE
# 25 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 26 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_PROTEIN
# 27 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_CALCIUM
# 28 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_IRON
# 29 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_ZINC
# 30 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_CARBOS
# 31 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_HP_UP
# 32 "data/maps/BattleFrontier_Mart/scripts.pory"
	.2byte ITEM_NONE
# 33 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 34 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_Mart/scripts.pory"

# 36 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_OldMan::
# 37 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
# 38 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_Mart/scripts.pory"

# 40 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_OldWoman::
# 41 "data/maps/BattleFrontier_Mart/scripts.pory"
	lock
# 42 "data/maps/BattleFrontier_Mart/scripts.pory"
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
# 43 "data/maps/BattleFrontier_Mart/scripts.pory"
	waitmovement 0
# 44 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
# 45 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 46 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_Mart/scripts.pory"

# 48 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_Boy::
# 49 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
# 50 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 51 "data/maps/BattleFrontier_Mart/scripts.pory"

# 52 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_ChaperonGrandson:
# 53 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "We came here to chaperon our\n"
# 54 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "grandson.\p"
# 55 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "But since we're here, we thought\n"
# 56 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "we should get some souvenirs.$"
# 57 "data/maps/BattleFrontier_Mart/scripts.pory"

# 58 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_ProteinMakeNiceGift:
# 59 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "Dear, what do you think of this?\n"
# 60 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "Wouldn't this make a nice gift?\p"
# 61 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "It's…PRO…TE…IN?\n"
# 62 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "It sounds delicious, doesn't it?$"
# 63 "data/maps/BattleFrontier_Mart/scripts.pory"

# 64 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
# 65 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "A lot of the BATTLE FRONTIER's\n"
# 66 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "facilities don't allow the use of items\l"
# 67 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "during battles.\p"
# 68 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "That rule makes things tougher than\n"
# 69 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "they already are!$"
=======
.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "We came here to chaperon our\n"
	.string "grandson.\p"
	.string "But since we're here, we thought\n"
	.string "we should get some souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Dear, what do you think of this?\n"
	.string "Wouldn't this make a nice gift?\p"
	.string "It's…PRO…TE…IN?\n"
	.string "It sounds delicious, doesn't it?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "A lot of the BATTLE FRONTIER's\n"
	.string "facilities don't allow the use of items\l"
	.string "during battles.\p"
	.string "That rule makes things tougher than\n"
	.string "they already are!$"

>>>>>>> upstream/master
