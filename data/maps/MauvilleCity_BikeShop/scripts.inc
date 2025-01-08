<<<<<<< HEAD
# 1 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 2 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_MapScripts::
# 3 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 5 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Rydel::
# 6 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	lock
# 7 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	faceplayer
# 8 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
# 9 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
# 10 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
# 11 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
# 12 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
# 13 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
# 14 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 15 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 16 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SkipGreeting::
# 17 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
# 18 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
# 19 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
# 20 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 21 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 22 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseBike::
# 23 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
# 24 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 25 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 21, 8, MULTI_BIKE, TRUE
# 26 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 27 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
# 28 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
# 29 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 30 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 31 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_NotFar::
# 32 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_DECLINED_BIKE
# 33 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
# 34 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 35 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 36 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 37 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_YesFar::
# 38 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_RECEIVED_BIKE
# 39 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
# 40 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 41 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 42 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_GetMachBike::
# 43 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
# 44 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 45 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 46 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 47 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 48 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 49 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_GetAcroBike::
# 50 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
# 51 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 52 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 53 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 54 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 55 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 56 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
# 57 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
# 58 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	special SwapRegisteredBike
# 59 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 60 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 61 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 62 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
# 63 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
# 64 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
# 65 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
# 66 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 67 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 68 "data/maps/MauvilleCity_BikeShop/scripts.pory"
@ If the player does not have a bike on them Rydel assumes its stored in the PC
# 69 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchBikes::
# 70 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
# 71 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_ACRO_BIKE
# 72 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
# 73 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_MACH_BIKE
# 74 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
# 75 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
# 76 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 77 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 78 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 79 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_KeepBike::
# 80 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
# 81 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 82 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 83 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 84 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
# 85 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	incrementgamestat GAME_STAT_TRADED_BIKES
# 86 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
# 87 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	removeitem ITEM_ACRO_BIKE
# 88 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 89 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 90 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 91 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 92 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
# 93 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	incrementgamestat GAME_STAT_TRADED_BIKES
# 94 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
# 95 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	removeitem ITEM_MACH_BIKE
# 96 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 97 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 98 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 99 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 100 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Assistant::
# 101 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
# 102 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 103 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 104 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
# 105 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
# 106 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 107 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 108 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 109 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 110 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
# 111 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
# 112 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
# 114 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
# 115 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
# 116 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
# 117 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
# 118 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 119 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 120 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HowToRide::
# 121 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
# 122 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 123 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 124 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 125 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 126 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HowToTurn::
# 127 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
# 128 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 129 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 130 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 131 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 132 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SandySlopes::
# 133 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_SandySlopes
# 134 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 135 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 136 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 137 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 138 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
# 139 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 140 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 141 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 142 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
# 143 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
# 144 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 145 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 146 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 147 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 148 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
# 149 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
# 150 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 151 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
# 152 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
# 153 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
# 154 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
# 155 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
# 156 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 157 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 158 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Wheelies::
# 159 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_Wheelies
# 160 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 161 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 162 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 163 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 164 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_BunnyHops::
# 165 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_BunnyHops
# 166 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 167 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 168 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 169 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 170 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Jumps::
# 171 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_Jumps
# 172 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 173 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 174 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 175 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 176 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
# 177 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 178 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 179 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 180 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_RydelGreeting:
# 181 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well, well, what have we here?\n"
# 182 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A most energetic customer!\p"
# 183 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Me? You may call me RYDEL.\n"
# 184 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm the owner of this cycle shop.$"
# 185 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 186 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
# 187 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Your RUNNING SHOES…\n"
# 188 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "They're awfully filthy.\p"
# 189 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Did you come from far away?$"
# 190 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 191 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
# 192 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Is that right?\p"
# 193 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Then, I guess you have no need for\n"
# 194 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "any of my BIKES.$"
# 195 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 196 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
# 197 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Hm, hm… … … … …\p"
# 198 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You're saying that you came all this\n"
# 199 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "way from LITTLEROOT?\p"
# 200 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "My goodness!\n"
# 201 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "That's ridiculously far!\p"
# 202 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you had one of my BIKES, you could\n"
# 203 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "go anywhere easily while feeling the\l"
# 204 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "gentle caress of the wind!\p"
# 205 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll tell you what!\n"
# 206 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll give you a BIKE!\p"
# 207 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh, wait a second!\p"
# 208 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I forgot to tell you that there are\n"
# 209 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "two kinds of BIKES!\p"
# 210 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "They are the MACH BIKE and\n"
# 211 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the ACRO BIKE!\p"
# 212 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The MACH BIKE is for cyclists who want\n"
# 213 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to feel the wind with their bodies!\p"
# 214 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "And an ACRO BIKE is for those who\n"
# 215 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "prefer technical rides!\p"
# 216 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm a real sweetheart, so you can\n"
# 217 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "have whichever one you like!\p"
# 218 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which one will you choose?$"
# 219 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 220 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ChoseMachBike:
# 221 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} chose the MACH BIKE.$"
# 222 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 223 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ChoseAcroBike:
# 224 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} chose the ACRO BIKE.$"
# 225 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 226 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
# 227 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: If you get the urge to switch\n"
# 228 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "BIKES, just come see me!$"
# 229 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 230 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_WantToSwitchBikes:
# 231 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Oh? Were you thinking about\n"
# 232 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "switching BIKES?$"
# 233 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 234 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_IllSwitchBikes:
# 235 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Okay, no problem!\n"
# 236 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll switch BIKES for you!$"
# 237 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 238 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
# 239 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} got the MACH BIKE exchanged\n"
# 240 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "for an ACRO BIKE.$"
# 241 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 242 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
# 243 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
# 244 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "for a MACH BIKE.$"
# 245 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 246 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HappyYouLikeIt:
# 247 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "RYDEL: Good, good!\n"
# 248 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm happy that you like it!$"
# 249 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 250 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
# 251 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh? What happened to that BIKE\n"
# 252 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I gave you?\p"
# 253 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh, I get it, you stored it using your PC.\p"
# 254 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well, take it out of PC storage,\n"
# 255 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "and I'll be happy to exchange it!\p"
# 256 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "May the wind always be at your back\n"
# 257 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "on your adventure!$"
# 258 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 259 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HandbooksAreInBack:
# 260 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm learning about BIKES while\n"
# 261 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I work here.\p"
# 262 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you need advice on how to ride your\n"
# 263 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "BIKE, there're a couple handbooks in\l"
# 264 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the back.$"
# 265 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 266 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
# 267 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It's a handbook on the MACH BIKE.\p"
# 268 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which page do you want to read?$"
# 269 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 270 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HowToRideMachBike:
# 271 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A BIKE moves in the direction that\n"
# 272 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the + Control Pad is pressed.\p"
# 273 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It will speed up once it gets rolling.\p"
# 274 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "To stop, release the + Control Pad.\n"
# 275 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The BIKE will slow to a stop.\p"
# 276 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 277 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 278 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HowToTurnMachBike:
# 279 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A MACH BIKE is speedy, but it can't\n"
# 280 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "stop very quickly.\p"
# 281 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It gets a little tricky to get around\n"
# 282 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "a corner.\p"
# 283 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Release the + Control Pad a little\n"
# 284 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "before the corner and slow down.\p"
# 285 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 286 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 287 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_SandySlopes:
# 288 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "There are small sandy slopes\n"
# 289 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "throughout the HOENN region.\p"
# 290 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The loose, crumbly sand makes it\n"
# 291 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "impossible to climb normally.\p"
# 292 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "But if you have a MACH BIKE, you can\n"
# 293 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "zip up a sandy slope.\p"
# 294 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 295 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 296 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
# 297 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It's a handbook on the ACRO BIKE.\p"
# 298 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which page do you want to read?$"
# 299 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 300 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_Wheelies:
# 301 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the B Button while riding,\n"
# 302 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "and the front wheel lifts up.\p"
# 303 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You can zip around with the front\n"
# 304 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "wheel up using the + Control Pad.\p"
# 305 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "This technique is called a wheelie.\p"
# 306 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 307 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 308 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BunnyHops:
# 309 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Keeping the B Button pressed,\n"
# 310 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "your BIKE can hop on the spot.\p"
# 311 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "This technique is called a bunny hop.\p"
# 312 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You can ride while hopping, too.\p"
# 313 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 314 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 315 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_Jumps:
# 316 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the B Button and the + Control\n"
# 317 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pad at the same time to jump.\p"
# 318 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the + Control Pad to the side\n"
# 319 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to jump sideways.\p"
# 320 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press it backwards to make the BIKE\n"
# 321 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "change directions while jumping.\p"
# 322 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
=======
MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my BIKES.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "Oh, wait a second!\p"
	.string "I forgot to tell you that there are\n"
	.string "two kinds of BIKES!\p"
	.string "They are the MACH BIKE and\n"
	.string "the ACRO BIKE!\p"
	.string "The MACH BIKE is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an ACRO BIKE is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} chose the MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} chose the ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: If you get the urge to switch\n"
	.string "BIKES, just come see me!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Were you thinking about\n"
	.string "switching BIKES?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Okay, no problem!\n"
	.string "I'll switch BIKES for you!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} got the MACH BIKE exchanged\n"
	.string "for an ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
	.string "for a MACH BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Good, good!\n"
	.string "I'm happy that you like it!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? What happened to that BIKE\n"
	.string "I gave you?\p"
	.string "Oh, I get it, you stored it using your PC.\p"
	.string "Well, take it out of PC storage,\n"
	.string "and I'll be happy to exchange it!\p"
	.string "May the wind always be at your back\n"
	.string "on your adventure!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "I'm learning about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "BIKE, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "It's a handbook on the MACH BIKE.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "A MACH BIKE is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a MACH BIKE, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "It's a handbook on the ACRO BIKE.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"

>>>>>>> upstream/master
