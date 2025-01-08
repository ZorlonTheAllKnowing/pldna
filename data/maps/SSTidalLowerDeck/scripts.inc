<<<<<<< HEAD
# 1 "data/maps/SSTidalLowerDeck/scripts.pory"

# 2 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_MapScripts::
# 3 "data/maps/SSTidalLowerDeck/scripts.pory"
	.byte 0
# 4 "data/maps/SSTidalLowerDeck/scripts.pory"

# 5 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_EventScript_Phillip::
# 6 "data/maps/SSTidalLowerDeck/scripts.pory"
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
# 7 "data/maps/SSTidalLowerDeck/scripts.pory"
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/SSTidalLowerDeck/scripts.pory"
	end
# 9 "data/maps/SSTidalLowerDeck/scripts.pory"

# 10 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_EventScript_Leonard::
# 11 "data/maps/SSTidalLowerDeck/scripts.pory"
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
# 12 "data/maps/SSTidalLowerDeck/scripts.pory"
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/SSTidalLowerDeck/scripts.pory"
	end
# 14 "data/maps/SSTidalLowerDeck/scripts.pory"

# 15 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_PhillipIntro:
# 16 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Arrrgh! I'm fed up and dog-tired of\n"
# 17 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "cleaning this huge place!\p"
# 18 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Let's have a quick battle!$"
# 19 "data/maps/SSTidalLowerDeck/scripts.pory"

# 20 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_PhillipDefeat:
# 21 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Little bro, I lost!$"
# 22 "data/maps/SSTidalLowerDeck/scripts.pory"

# 23 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_PhillipPostBattle:
# 24 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "We're the CLEANUP BROTHERS!\p"
# 25 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "The old one dumps the detergent,\n"
# 26 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "and the young one does the scrubbing!$"
# 27 "data/maps/SSTidalLowerDeck/scripts.pory"

# 28 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_LeonardIntro:
# 29 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "This is the bottom of the ship's hull.\n"
# 30 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "There's plenty of room.\l"
# 31 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "It'll be alright for a POKéMON battle.$"
# 32 "data/maps/SSTidalLowerDeck/scripts.pory"

# 33 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_LeonardDefeat:
# 34 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Big bro, I lost!$"
# 35 "data/maps/SSTidalLowerDeck/scripts.pory"

# 36 "data/maps/SSTidalLowerDeck/scripts.pory"
SSTidalLowerDeck_Text_LeonardPostBattle:
# 37 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "We're the CLEANUP BROTHERS!\p"
# 38 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "The old one dumps the detergent,\n"
# 39 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "and the young one does the scrubbing!$"
=======
SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! I'm fed up and dog-tired of\n"
	.string "cleaning this huge place!\p"
	.string "Let's have a quick battle!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Little bro, I lost!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "This is the bottom of the ship's hull.\n"
	.string "There's plenty of room.\l"
	.string "It'll be alright for a POKéMON battle.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Big bro, I lost!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

>>>>>>> upstream/master
