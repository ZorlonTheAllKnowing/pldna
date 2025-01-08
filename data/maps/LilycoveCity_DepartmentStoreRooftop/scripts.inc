<<<<<<< HEAD
# 1 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_MapScripts::
# 3 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
# 4 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.byte 0
# 5 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 6 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_OnTransition:
# 7 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	getpokenewsactive POKENEWS_LILYCOVE
# 8 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
# 9 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
# 10 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 12 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
# 13 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
# 14 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 15 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 16 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
# 17 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
# 18 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 19 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 20 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
# 21 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lock
# 22 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	faceplayer
# 23 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	message gText_HowMayIServeYou
# 24 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	waitmessage
# 25 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
# 26 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 27 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 28 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 29 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 30 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.align 2
# 31 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
# 32 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_MUD_BALL
# 33 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_FENCE_LENGTH
# 34 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_FENCE_WIDTH
# 35 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_TIRE
# 36 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_BREAKABLE_DOOR
# 37 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_SOLID_BOARD
# 38 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_SAND_ORNAMENT
# 39 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_STAND
# 40 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_SLIDE
# 41 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_TV
# 42 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_ROUND_TV
# 43 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_CUTE_TV
# 44 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_WAILMER_DOLL
# 45 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte DECOR_RHYDON_DOLL
# 46 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.2byte 0
# 47 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 48 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 50 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
# 51 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lock
# 52 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	faceplayer
# 53 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	getpokenewsactive POKENEWS_LILYCOVE
# 54 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
# 55 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
# 56 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 57 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 58 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 59 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
# 60 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
# 61 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	release
# 62 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 63 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 64 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
# 65 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
# 66 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 67 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 68 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
# 69 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	lockall
# 70 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
# 71 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	waitmessage
# 72 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	showmoneybox 0, 0
# 73 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
# 74 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 75 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 76 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
# 77 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
# 78 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 79 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	switch VAR_TEMP_1
# 80 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
# 81 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
# 82 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
# 83 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
# 85 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 87 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
# 88 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
# 89 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
# 90 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 91 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 92 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
# 93 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setvar VAR_TEMP_0, ITEM_SODA_POP
# 94 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
# 95 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 96 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 97 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
# 98 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	setvar VAR_TEMP_0, ITEM_LEMONADE
# 99 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
# 100 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 101 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 102 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
# 103 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkmoney 200
# 104 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 105 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 106 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
# 107 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkmoney 300
# 108 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 109 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 110 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
# 111 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkmoney 350
# 112 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 113 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 114 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
# 115 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	removemoney 200
# 116 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 117 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 118 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
# 119 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	removemoney 300
# 120 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 121 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 122 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
# 123 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	removemoney 350
# 124 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	return
# 125 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 126 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
# 127 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
# 128 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
# 129 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
# 130 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
# 131 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkitemspace VAR_TEMP_0
# 132 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
# 133 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
# 134 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
# 135 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
# 136 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	updatemoneybox
# 137 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname STR_VAR_1, VAR_TEMP_0
# 138 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	playse SE_VEND
# 139 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
# 140 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	additem VAR_TEMP_0
# 141 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname STR_VAR_2, VAR_TEMP_0
# 142 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
# 143 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 144 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	random 64  @ 1/64 chance of an additional drink dropping
# 145 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
# 146 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkitemspace VAR_TEMP_0
# 147 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
# 148 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	playse SE_VEND
# 149 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
# 150 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	additem VAR_TEMP_0
# 151 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname STR_VAR_2, VAR_TEMP_0
# 152 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
# 153 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 154 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
# 155 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
# 156 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	checkitemspace VAR_TEMP_0
# 157 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
# 158 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	playse SE_VEND
# 159 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
# 160 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	additem VAR_TEMP_0
# 161 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferitemname STR_VAR_2, VAR_TEMP_0
# 162 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
# 163 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 164 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
# 165 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 166 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 167 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
# 168 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
# 169 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	waitmessage
# 170 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
# 171 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 172 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 173 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
# 174 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 175 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
# 176 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 177 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 178 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
# 179 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
# 180 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
# 181 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 182 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 183 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
# 184 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	hidemoneybox
# 185 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	releaseall
# 186 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	end
# 187 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 188 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
# 189 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Don't they have set dates for their\n"
# 190 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "clear-out sales?\p"
# 191 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "I watch TV, but they never show any\n"
# 192 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "commercials.$"
# 193 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 194 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
# 195 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Yes! I've been waiting a long time for\n"
# 196 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "this clear-out sale.\p"
# 197 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "They have items that you can only get\n"
# 198 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "here. I'm going to load up, that I am!$"
# 199 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 200 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
# 201 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Ohh… I'm bone-dry thirsty!$"
# 202 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 203 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
# 204 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "It's a VENDING MACHINE.\n"
# 205 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Which drink would you like?$"
# 206 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 207 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
# 208 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Clang!\p"
# 209 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "A can of {STR_VAR_1} dropped down.$"
# 210 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 211 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
# 212 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Clang!\p"
# 213 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Score! An extra can of {STR_VAR_1}\n"
# 214 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "dropped down!$"
# 215 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 216 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
# 217 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
	.string "Not enough money…$"
# 218 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"

# 219 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
# 220 "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.pory"
=======
LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition:
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch TV, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
>>>>>>> upstream/master
	.string "Decided against buying a drink.$"
