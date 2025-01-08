<<<<<<< HEAD
# 1 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_MapScripts::
# 3 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle3_OnResume
# 4 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle3_OnTransition
# 5 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.byte 0
# 6 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 7 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_OnResume:
# 8 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
# 9 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
# 10 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
# 11 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 12 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 13 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_OnTransition:
# 14 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_1, 0
# 15 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_2, 0
# 16 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_3, 0
# 17 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_4, 0
# 18 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 0
# 19 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_9, 0
# 20 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 21 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 22 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles::
# 23 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Up, FALSE
# 24 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Up, FALSE
# 25 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Up, FALSE
# 26 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Up, FALSE
# 27 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 1, Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile
# 28 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 2, Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile
# 29 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 3, Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile
# 30 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 4, Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile
# 31 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 32 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 33 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile::
# 34 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 35 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 36 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 37 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile::
# 38 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 39 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 40 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 41 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile::
# 42 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 43 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 44 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 45 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile::
# 46 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
# 47 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 48 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 49 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetDoorsState0::
# 50 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
# 51 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
# 52 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
# 53 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
# 54 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
# 55 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
# 56 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
# 57 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
# 58 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
# 59 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
# 60 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
# 61 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
# 62 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
# 63 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
# 64 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
# 65 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
# 66 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
# 67 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
# 68 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
# 69 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
# 70 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
# 71 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
# 72 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
# 73 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 14, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
# 74 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
# 75 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
# 76 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
# 77 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
# 78 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
# 79 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
# 80 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 81 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 82 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 83 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 84 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 85 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 86 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 87 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 88 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 89 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 90 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 91 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 92 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 93 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 94 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 95 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 96 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 97 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 98 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 99 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 100 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 101 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 102 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 103 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 104 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 105 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 106 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 107 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 108 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 109 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 110 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 111 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 112 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 113 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 114 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 115 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 116 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
# 117 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
# 118 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
# 119 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
# 120 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Open0, TRUE
# 121 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 17, METATILE_TrickHousePuzzle_RedDoorV_Open1, TRUE
# 122 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Open0, TRUE
# 123 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 5, METATILE_TrickHousePuzzle_RedDoorV_Open1, TRUE
# 124 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 125 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 126 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetDoorsState1::
# 127 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
# 128 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
# 129 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
# 130 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
# 131 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
# 132 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
# 133 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
# 134 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
# 135 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
# 136 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
# 137 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
# 138 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
# 139 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
# 140 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
# 141 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
# 142 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
# 143 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
# 144 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
# 145 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
# 146 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
# 147 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
# 148 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
# 149 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
# 150 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 14, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
# 151 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
# 152 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 5, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
# 153 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
# 154 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 17, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
# 155 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
# 156 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
# 157 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 158 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 159 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 160 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 161 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 162 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 163 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 164 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 165 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 166 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 167 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 168 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 169 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 170 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 171 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 172 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 173 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 174 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 175 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 176 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 177 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 178 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 179 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 180 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 181 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 182 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 183 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 184 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 185 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 186 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 187 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 188 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 189 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 190 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 191 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 192 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 193 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
# 194 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
# 195 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
# 196 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
# 197 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Retracted, TRUE
# 198 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, FALSE
# 199 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Retracted, TRUE
# 200 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, FALSE
# 201 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 202 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 203 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button1::
# 204 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 205 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 1
# 206 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 207 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 208 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 209 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button2::
# 210 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 211 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 2
# 212 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 213 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 214 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 215 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button3::
# 216 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 217 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 3
# 218 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 219 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 220 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 221 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button4::
# 222 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 223 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 4
# 224 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 225 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 226 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 227 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressButton::
# 228 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call Route110_TrickHousePuzzle3_EventScript_SetButton
# 229 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	playse SE_PIN
# 230 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
# 231 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_AlternateDoors
# 232 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 233 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 234 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton::
# 235 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_1, 0
# 236 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_2, 0
# 237 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_3, 0
# 238 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_4, 0
# 239 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 1, Route110_TrickHousePuzzle3_EventScript_SetButton1
# 240 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 2, Route110_TrickHousePuzzle3_EventScript_SetButton2
# 241 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 3, Route110_TrickHousePuzzle3_EventScript_SetButton3
# 242 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_8, 4, Route110_TrickHousePuzzle3_EventScript_SetButton4
# 243 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 244 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 245 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton1::
# 246 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_1, 1
# 247 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 248 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 249 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton2::
# 250 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_2, 1
# 251 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 252 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 253 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton3::
# 254 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_3, 1
# 255 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 256 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 257 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton4::
# 258 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_4, 1
# 259 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 260 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 261 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_AlternateDoors::
# 262 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
# 263 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
# 264 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	special DrawWholeMapView
# 265 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState
# 266 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetAltDoorState
# 267 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 268 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 269 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState::
# 270 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_9, 0
# 271 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	releaseall
# 272 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 273 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 274 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetAltDoorState::
# 275 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_9, 1
# 276 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	releaseall
# 277 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 278 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 279 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Scroll::
# 280 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 281 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle3_EventScript_FoundScroll
# 282 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 283 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 284 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 285 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_FoundScroll::
# 286 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 1
# 287 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 288 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 289 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 290 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Justin::
# 291 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	trainerbattle_single TRAINER_JUSTIN, Route110_TrickHousePuzzle3_Text_JustinIntro, Route110_TrickHousePuzzle3_Text_JustinDefeat
# 292 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
# 293 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 294 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 295 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Martha::
# 296 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	trainerbattle_single TRAINER_MARTHA, Route110_TrickHousePuzzle3_Text_MarthaIntro, Route110_TrickHousePuzzle3_Text_MarthaDefeat
# 297 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
# 298 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 299 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 300 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Alan::
# 301 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	trainerbattle_single TRAINER_ALAN, Route110_TrickHousePuzzle3_Text_AlanIntro, Route110_TrickHousePuzzle3_Text_AlanDefeat
# 302 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
# 303 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 304 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 305 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened:
# 306 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 307 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "on the door.\p"
# 308 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "“TRICK MASTER is coveted.”\n"
# 309 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "… … … … … … … …\p"
# 310 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "The lock clicked open!$"
# 311 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 312 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_JustinIntro:
# 313 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I keep coming back to this same place!$"
# 314 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 315 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_JustinDefeat:
# 316 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I'm already having trouble, and then\n"
# 317 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "you have to beat me? It's not fair!$"
# 318 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 319 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_JustinPostBattle:
# 320 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "It's full of doors here!\n"
# 321 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "It's too small and dark in here! Help!$"
# 322 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 323 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_MarthaIntro:
# 324 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't know what's going on here.\n"
# 325 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I'm starting to feel sad…$"
# 326 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 327 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_MarthaDefeat:
# 328 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "You… You're awful!$"
# 329 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 330 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_MarthaPostBattle:
# 331 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I know I'm weak!\n"
# 332 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "And, I have no sense of direction!$"
# 333 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 334 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_AlanIntro:
# 335 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't get it. What would anyone want\n"
# 336 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "with a house this bizarre?$"
# 337 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 338 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_AlanDefeat:
# 339 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't get it.\n"
# 340 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "How did I lose?$"
# 341 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 342 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_AlanPostBattle:
# 343 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't get it.\n"
# 344 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "How many traps are in this house?\p"
# 345 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "You may be the one to solve that.$"
=======
Route110_TrickHousePuzzle3_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle3_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle3_OnTransition
	.byte 0

Route110_TrickHousePuzzle3_OnResume:
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
	call_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	end

Route110_TrickHousePuzzle3_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	end

Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles::
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Up, FALSE
	call_if_eq VAR_TEMP_8, 1, Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile
	call_if_eq VAR_TEMP_8, 2, Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile
	call_if_eq VAR_TEMP_8, 3, Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile
	call_if_eq VAR_TEMP_8, 4, Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile::
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile::
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile::
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	return

Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile::
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	return

Route110_TrickHousePuzzle3_EventScript_SetDoorsState0::
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, FALSE
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, FALSE
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, FALSE
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, FALSE
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
	setmetatile 3, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
	setmetatile 3, 14, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
	setmetatile 6, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
	setmetatile 9, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, TRUE
	setmetatile 12, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, FALSE
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, FALSE
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, FALSE
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Open0, TRUE
	setmetatile 3, 17, METATILE_TrickHousePuzzle_RedDoorV_Open1, TRUE
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Open0, TRUE
	setmetatile 9, 5, METATILE_TrickHousePuzzle_RedDoorV_Open1, TRUE
	return

Route110_TrickHousePuzzle3_EventScript_SetDoorsState1::
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, FALSE
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, FALSE
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, TRUE
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, TRUE
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
	setmetatile 3, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
	setmetatile 3, 14, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
	setmetatile 6, 5, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
	setmetatile 9, 17, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, TRUE
	setmetatile 12, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, TRUE
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Retracted, TRUE
	setmetatile 3, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, FALSE
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Retracted, TRUE
	setmetatile 9, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, FALSE
	return

Route110_TrickHousePuzzle3_EventScript_Button1::
	lockall
	setvar VAR_TEMP_8, 1
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_Button2::
	lockall
	setvar VAR_TEMP_8, 2
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_Button3::
	lockall
	setvar VAR_TEMP_8, 3
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_Button4::
	lockall
	setvar VAR_TEMP_8, 4
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
	end

Route110_TrickHousePuzzle3_EventScript_PressButton::
	call Route110_TrickHousePuzzle3_EventScript_SetButton
	playse SE_PIN
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
	goto Route110_TrickHousePuzzle3_EventScript_AlternateDoors
	end

Route110_TrickHousePuzzle3_EventScript_SetButton::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	call_if_eq VAR_TEMP_8, 1, Route110_TrickHousePuzzle3_EventScript_SetButton1
	call_if_eq VAR_TEMP_8, 2, Route110_TrickHousePuzzle3_EventScript_SetButton2
	call_if_eq VAR_TEMP_8, 3, Route110_TrickHousePuzzle3_EventScript_SetButton3
	call_if_eq VAR_TEMP_8, 4, Route110_TrickHousePuzzle3_EventScript_SetButton4
	return

Route110_TrickHousePuzzle3_EventScript_SetButton1::
	setvar VAR_TEMP_1, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetButton2::
	setvar VAR_TEMP_2, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetButton3::
	setvar VAR_TEMP_3, 1
	return

Route110_TrickHousePuzzle3_EventScript_SetButton4::
	setvar VAR_TEMP_4, 1
	return

Route110_TrickHousePuzzle3_EventScript_AlternateDoors::
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
	call_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	special DrawWholeMapView
	goto_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState
	goto_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetAltDoorState
	end

Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState::
	setvar VAR_TEMP_9, 0
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_SetAltDoorState::
	setvar VAR_TEMP_9, 1
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle3_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle3_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle3_EventScript_Justin::
	trainerbattle_single TRAINER_JUSTIN, Route110_TrickHousePuzzle3_Text_JustinIntro, Route110_TrickHousePuzzle3_Text_JustinDefeat
	msgbox Route110_TrickHousePuzzle3_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA, Route110_TrickHousePuzzle3_Text_MarthaIntro, Route110_TrickHousePuzzle3_Text_MarthaDefeat
	msgbox Route110_TrickHousePuzzle3_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_EventScript_Alan::
	trainerbattle_single TRAINER_ALAN, Route110_TrickHousePuzzle3_Text_AlanIntro, Route110_TrickHousePuzzle3_Text_AlanDefeat
	msgbox Route110_TrickHousePuzzle3_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is coveted.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle3_Text_JustinIntro:
	.string "I keep coming back to this same place!$"

Route110_TrickHousePuzzle3_Text_JustinDefeat:
	.string "I'm already having trouble, and then\n"
	.string "you have to beat me? It's not fair!$"

Route110_TrickHousePuzzle3_Text_JustinPostBattle:
	.string "It's full of doors here!\n"
	.string "It's too small and dark in here! Help!$"

Route110_TrickHousePuzzle3_Text_MarthaIntro:
	.string "I don't know what's going on here.\n"
	.string "I'm starting to feel sad…$"

Route110_TrickHousePuzzle3_Text_MarthaDefeat:
	.string "You… You're awful!$"

Route110_TrickHousePuzzle3_Text_MarthaPostBattle:
	.string "I know I'm weak!\n"
	.string "And, I have no sense of direction!$"

Route110_TrickHousePuzzle3_Text_AlanIntro:
	.string "I don't get it. What would anyone want\n"
	.string "with a house this bizarre?$"

Route110_TrickHousePuzzle3_Text_AlanDefeat:
	.string "I don't get it.\n"
	.string "How did I lose?$"

Route110_TrickHousePuzzle3_Text_AlanPostBattle:
	.string "I don't get it.\n"
	.string "How many traps are in this house?\p"
	.string "You may be the one to solve that.$"

>>>>>>> upstream/master
