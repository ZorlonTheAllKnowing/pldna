<<<<<<< HEAD
# 1 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 4 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_MapScripts::
# 5 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
# 6 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
# 7 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.byte 0
# 8 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 9 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_OnWarp:
# 10 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
# 11 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.2byte 0
# 12 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 13 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth::
# 14 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 16 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 17 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 18 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_OnFrame:
# 19 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
# 20 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
# 21 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
# 22 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, SlateportCity_BattleTentLobby_EventScript_WonChallenge
# 23 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, SlateportCity_BattleTentLobby_EventScript_LostChallenge
# 24 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.2byte 0
# 25 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 26 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus::
# 27 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_getstatus
# 28 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 29 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 30 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving::
# 31 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 32 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 33 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 34 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 35 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 36 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 37 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 38 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 39 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 40 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_WonChallenge::
# 41 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 42 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
# 43 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 44 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_setrandomprize
# 45 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 46 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save 0
# 47 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 48 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 49 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_GivePrize::
# 50 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_giveprize
# 52 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 53 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
# 54 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 55 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
# 56 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 57 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 58 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitfanfare
# 59 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize
# 60 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 61 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize::
# 62 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
# 63 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize
# 64 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 65 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_LostChallenge::
# 66 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 67 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
# 68 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 69 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 70 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save 0
# 71 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 72 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 73 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 74 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_EndGivePrize::
# 75 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 76 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 77 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 78 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 79 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 80 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 81 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ResumeChallenge::
# 82 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 83 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
# 84 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 85 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save CHALLENGE_STATUS_SAVING
# 86 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 87 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 88 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 89 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 90 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 91 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge
# 92 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 93 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Attendant::
# 94 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lock
# 95 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	faceplayer
# 96 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_getprize
# 97 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_ne VAR_RESULT, ITEM_NONE, SlateportCity_BattleTentLobby_EventScript_GivePrize
# 98 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	special SavePlayerParty
# 99 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
# 100 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge::
# 101 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
# 102 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 103 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 104 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 105 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
# 106 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
# 107 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 108 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 109 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 110 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge::
# 111 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 112 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 113 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
# 114 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
# 115 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 116 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 117 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
# 118 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 119 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 120 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
# 121 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 122 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 123 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_init
# 124 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 125 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 126 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 127 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	delay 2
# 128 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 129 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
# 130 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
# 131 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 132 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_EnterChallenge::
# 133 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 134 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 135 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
# 136 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 2, 7
# 137 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
# 138 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitstate
# 139 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 140 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 141 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_WalkToDoor::
# 142 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
# 143 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
# 144 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmovement 0
# 145 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	opendoor 6, 1
# 146 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitdooranim
# 147 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
# 148 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
# 149 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmovement 0
# 150 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closedoor 6, 1
# 151 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitdooranim
# 152 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	return
# 153 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 154 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor:
# 155 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 156 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 157 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 158 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 159 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 160 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor:
# 161 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 162 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 163 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 164 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 165 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor:
# 166 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 167 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 168 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 169 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 170 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 171 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor:
# 172 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 173 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 174 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 175 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 176 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 177 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ExplainChallenge::
# 178 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
# 179 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge
# 180 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 181 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
# 182 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 183 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 184 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 185 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
# 186 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	special LoadPlayerParty
# 187 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_CancelChallenge::
# 188 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 189 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 190 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 191 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 192 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
@ Unused
# 193 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor::
# 194 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 195 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 196 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 197 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 198 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 199 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 200 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TormentGiver::
# 201 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lock
# 202 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	faceplayer
# 203 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_TORMENT, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
# 204 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
# 205 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	giveitem ITEM_TM_TORMENT
# 206 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 207 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setflag FLAG_RECEIVED_TM_TORMENT
# 208 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
# 209 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 210 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 211 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 212 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ReceivedTorment::
# 213 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
# 214 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 215 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 216 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 217 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Man::
# 218 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
# 219 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 220 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 221 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Girl::
# 222 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
# 223 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 224 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 225 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Woman::
# 226 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
# 227 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 228 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 229 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesBoard::
# 230 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 231 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 232 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 233 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 234 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 235 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard::
# 236 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 237 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 238 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	multichoice 17, 0, MULTI_SLATEPORT_TENT_RULES, FALSE
# 239 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 240 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
# 241 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
# 242 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
# 243 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
# 244 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
# 245 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
# 246 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
# 247 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 248 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 249 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesBasics::
# 250 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 251 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 252 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 253 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 254 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner::
# 255 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 256 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 257 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 258 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 259 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber::
# 260 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 261 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 262 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 263 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 264 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes::
# 265 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
# 266 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 267 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 268 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 269 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesMons::
# 270 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 271 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 272 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 273 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 274 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ExitRules::
# 275 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 276 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 277 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 278 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe:
# 279 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, like, I couldn't find myself any\n"
# 280 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "POKéMON that were, like, for me.\p"
# 281 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, I figured, like, hey, I should file\n"
# 282 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a complaint to the guy there?\p"
# 283 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "And he wouldn't hear me out, like, hey!\n"
# 284 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, like, total bummer, man!\p"
# 285 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, like, you! Zip it, you know?\n"
# 286 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Just, you know, take this!$"
# 287 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 288 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_ExplainTorment:
# 289 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "That's, like, TM41, you know?\n"
# 290 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, it's TORMENT, you hearing me?\p"
# 291 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Like, it won't let the other guy\n"
# 292 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "use the same move twice in a row, see?\p"
# 293 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, now, you listen here, like,\n"
# 294 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "I'm not laying a torment on you!$"
# 295 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 296 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons:
# 297 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "I don't really like BUG POKéMON,\n"
# 298 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "but maybe I'll try using some for\l"
# 299 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a change of pace.\p"
# 300 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Who knows, I might even get to like\n"
# 301 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "them!$"
# 302 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 303 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons:
# 304 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "You can battle all you want here even\n"
# 305 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "if you don't have any tough POKéMON.$"
# 306 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 307 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection:
# 308 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Wouldn't it be nice if they had more of\n"
# 309 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a selection?$"
=======
.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
	.byte 0

SlateportCity_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, SlateportCity_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, SlateportCity_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_WonChallenge::
	lockall
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
	waitmessage
	slateporttent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse
SlateportCity_BattleTentLobby_EventScript_GivePrize::
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
	slateporttent_giveprize
	switch VAR_RESULT
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize

SlateportCity_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	slateporttent_save 0
	playse SE_SAVE
	waitse

SlateportCity_BattleTentLobby_EventScript_EndGivePrize::
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

SlateportCity_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
	waitmessage
	slateporttent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge

SlateportCity_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	slateporttent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, SlateportCity_BattleTentLobby_EventScript_GivePrize
	special SavePlayerParty
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge::
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge

SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	slateporttent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
SlateportCity_BattleTentLobby_EventScript_EnterChallenge::
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 2, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

SlateportCity_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge

SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge

SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
SlateportCity_BattleTentLobby_EventScript_CancelChallenge::
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

@ Unused
SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor::
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentLobby_EventScript_TormentGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_TORMENT, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
	giveitem ITEM_TM_TORMENT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_TORMENT
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_ReceivedTorment::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_BattleTentLobby_EventScript_Man::
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Girl::
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_Woman::
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
	end

SlateportCity_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_SLATEPORT_TENT_RULES, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
	end

SlateportCity_BattleTentLobby_EventScript_RulesBasics::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_RulesMons::
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
	end

SlateportCity_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe:
	.string "So, like, I couldn't find myself any\n"
	.string "POKéMON that were, like, for me.\p"
	.string "So, I figured, like, hey, I should file\n"
	.string "a complaint to the guy there?\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"

SlateportCity_BattleTentLobby_Text_ExplainTorment:
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's TORMENT, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons:
	.string "I don't really like BUG POKéMON,\n"
	.string "but maybe I'll try using some for\l"
	.string "a change of pace.\p"
	.string "Who knows, I might even get to like\n"
	.string "them!$"

SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons:
	.string "You can battle all you want here even\n"
	.string "if you don't have any tough POKéMON.$"

SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection:
	.string "Wouldn't it be nice if they had more of\n"
	.string "a selection?$"

>>>>>>> upstream/master
