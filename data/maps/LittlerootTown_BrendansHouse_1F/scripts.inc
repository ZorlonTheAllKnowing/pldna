<<<<<<< HEAD
# 1 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_MOM, 1
# 3 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_RIVAL_MOM, 4
# 4 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 6 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_MapScripts::
# 7 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
# 8 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
# 10 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.byte 0
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 12 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnLoad:
# 13 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
# 14 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
# 18 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 19 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
# 20 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 21 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 22 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
# 23 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	checkplayergender
# 24 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
# 25 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 26 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 27 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
# 28 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
# 29 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 30 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 31 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnTransition:
# 32 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
# 33 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
# 34 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
# 35 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 36 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 37 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
# 38 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 8, 4
# 39 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 40 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 41 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 42 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 4, 5
# 44 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 46 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 47 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
# 48 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 9, 8
# 49 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 50 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
# 54 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnFrame:
# 55 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
# 56 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
# 57 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
# 58 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
# 59 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 60 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.2byte 0
# 61 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 62 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
# 63 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 64 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 65 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 66 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 67 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 68 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 69 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
# 70 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 71 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 72 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 73 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 74 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
# 75 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 76 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 77 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 78 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
# 79 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 80 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 81 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 82 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 83 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 84 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 85 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
# 86 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 87 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, MALE
# 88 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, LOCALID_MOM
# 89 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
# 90 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 91 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 92 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
# 93 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 94 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 95 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
# 96 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 97 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
# 98 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 100 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
# 101 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 102 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 103 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 104 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 105 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
# 106 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 107 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 108 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 109 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
# 110 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 111 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 112 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 113 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 114 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 115 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 116 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 117 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 118 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
# 119 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 120 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 121 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 122 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 123 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 124 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 125 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 126 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 127 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
# 128 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 129 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 130 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 131 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 132 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 133 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
# 134 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 135 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 136 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 137 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 138 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 139 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
# 140 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 141 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 142 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 143 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 144 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 145 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
# 146 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 147 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 10
# 148 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	addobject LOCALID_RIVAL
# 149 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 150 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 151 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 152 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 153 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 154 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 155 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
# 156 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 157 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
# 158 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
# 159 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
# 160 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 161 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 162 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
# 163 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
# 164 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
# 165 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 166 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	removeobject LOCALID_RIVAL
# 167 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
# 168 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 170 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 171 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 172 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 173 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 174 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	fadedefaultbgm
# 175 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 177 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 178 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
# 179 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 180 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 181 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 182 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 183 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
# 184 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
# 185 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 186 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 188 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
# 189 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
# 190 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 191 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 192 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 193 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
# 194 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
# 195 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 196 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 197 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 198 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
# 199 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 200 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 201 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 202 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 203 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 204 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 205 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 206 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 207 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 208 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
# 209 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 210 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 211 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 212 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 213 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 214 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
# 215 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 216 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 217 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 218 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 219 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 220 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 221 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 222 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 223 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 224 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
# 225 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
# 226 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
# 227 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 228 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 229 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 230 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
# 231 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
# 232 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
# 233 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 234 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 235 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 236 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
# 237 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
# 238 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
# 239 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 240 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 241 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 242 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
# 243 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 244 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 245 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 246 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 247 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 248 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
# 249 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 250 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 251 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 252 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 253 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 254 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 255 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 256 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 257 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
# 258 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 259 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 260 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 261 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 262 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 263 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
# 264 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 265 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 266 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 267 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 268 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 269 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 270 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 271 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
# 272 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 273 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 274 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 275 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 276 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 277 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 278 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 279 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 280 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 281 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 282 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 283 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
# 284 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 285 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 286 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 287 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 288 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 289 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 290 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 291 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsntItNiceInHere:
# 292 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See, {PLAYER}?\n"
# 293 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Isn't it nice in here, too?$"
# 294 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 295 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MoversPokemonGoSetClock:
# 296 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The mover's POKéMON do all the work\n"
# 297 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "of moving us in and cleaning up after.\l"
# 298 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This is so convenient!\p"
# 299 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "{PLAYER}, your room is upstairs.\n"
# 300 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go check it out, dear!\p"
# 301 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD bought you a new clock to mark\n"
# 302 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "our move here.\l"
# 303 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't forget to set it!$"
# 304 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 305 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ArentYouInterestedInRoom:
# 306 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, {PLAYER}?\p"
# 307 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Aren't you interested in seeing your\n"
# 308 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "very own room?$"
# 309 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 310 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoSetTheClock:
# 311 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}.\p"
# 312 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go set the clock in your room, honey.$"
# 313 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 314 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_OhComeQuickly:
# 315 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
# 316 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Quick! Come quickly!$"
# 317 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 318 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MaybeDadWillBeOn:
# 319 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Look! It's PETALBURG GYM!\n"
# 320 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Maybe DAD will be on!$"
# 321 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 322 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ItsOverWeMissedHim:
# 323 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh… It's over.\p"
# 324 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think DAD was on, but we missed him.\n"
# 325 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Too bad.$"
# 326 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 327 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
# 328 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes.\n"
# 329 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "One of DAD's friends lives in town.\p"
# 330 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "PROF. BIRCH is his name.\p"
# 331 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He lives right next door, so you should\n"
# 332 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "go over and introduce yourself.$"
# 333 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 334 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_SeeYouHoney:
# 335 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See you, honey!$"
# 336 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 337 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DidYouMeetProfBirch:
# 338 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Did you introduce yourself to\n"
# 339 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "PROF. BIRCH?$"
# 340 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 341 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_YouShouldRestABit:
# 342 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: How are you doing, {PLAYER}?\n"
# 343 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You look a little tired.\p"
# 344 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think you should rest a bit.$"
# 345 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 346 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TakeCareHoney:
# 347 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Take care, honey!$"
# 348 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 349 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
# 350 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
# 351 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Then here's something from your MOM!$"
# 352 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 353 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DontPushYourselfTooHard:
# 354 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't push yourself too hard, dear.\n"
# 355 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You can always come home.\p"
# 356 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go for it, honey!$"
# 357 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 358 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatAPokenav:
# 359 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: What is that, honey? A POKéNAV?\n"
# 360 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Someone from DEVON gave it to you?\p"
# 361 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Well, honey, how about registering\n"
# 362 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "your mom?\p"
# 363 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "… … …$"
# 364 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 365 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RegisteredMom:
# 366 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Registered MOM\n"
# 367 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "in the POKéNAV.$"
# 368 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 369 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth1:
# 370 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Fugiiiiih!$"
# 371 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 372 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth2:
# 373 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Huggoh, uggo uggo…$"
# 374 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 375 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ReportFromPetalburgGym:
# 376 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "INTERVIEWER: …We brought you this\n"
# 377 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "report from in front of PETALBURG GYM.$"
# 378 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 379 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TheresAMovieOnTV:
# 380 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There is a movie on TV.\p"
# 381 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Two men are dancing on a big piano\n"
# 382 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "keyboard.\p"
# 383 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Better get going!$"
# 384 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 385 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RunningShoesManual:
# 386 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's the instruction booklet for the\n"
# 387 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "RUNNING SHOES.\p"
# 388 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Press the B Button to run while\n"
# 389 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "wearing your RUNNING SHOES.\p"
# 390 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Lace up your RUNNING SHOES and hit\n"
# 391 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "the road running!”$"
# 392 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 393 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
# 394 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm?\p"
# 395 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 396 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's been a while since I saw you,\n"
# 397 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "but you look…stronger, somehow.\p"
# 398 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "That's the impression I get.\n"
# 399 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "But your old man hasn't given up yet!\p"
# 400 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes, I have something for you.\n"
# 401 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This came to you from someone named\l"
# 402 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MR. BRINEY.$"
# 403 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 404 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_PortsInSlateportLilycove:
# 405 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm, a TICKET for a ferry?\p"
# 406 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "If I recall, there are ferry ports in\n"
# 407 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "SLATEPORT and LILYCOVE.$"
# 408 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 409 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_BetterGetBackToGym:
# 410 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I'd better get back to PETALBURG GYM.\p"
# 411 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM, thanks for looking after the house\n"
# 412 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while I'm away.$"
# 413 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 414 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DadShouldStayLonger:
# 415 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: That DAD of yours…\p"
# 416 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He comes home for the first time in a\n"
# 417 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while, but all he talks about is POKéMON.\p"
# 418 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He should relax and stay a little longer.$"
# 419 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 420 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatABreakingStory:
# 421 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Is that a breaking news story?$"
# 422 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 423 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
# 424 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We bring you this emergency\n"
# 425 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "news flash!\p"
# 426 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "In various HOENN locales, there have\n"
# 427 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "been reports of a BZZT…colored\l"
# 428 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "POKéMON in flight.\p"
# 429 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The identity of this POKéMON is\n"
# 430 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "currently unknown.\p"
# 431 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We now return you to the regular\n"
# 432 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "movie program.$"
# 433 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 434 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_WhatColorDidTheySay:
# 435 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}, did you catch that?\p"
# 436 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "What color did the announcer say\n"
# 437 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "that POKéMON was?$"
# 438 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 439 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_StillUnknownPokemon:
# 440 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, isn't that something!\n"
# 441 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
=======
.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. BIRCH is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
>>>>>>> upstream/master
	.string "There are still unknown POKéMON.$"
