<<<<<<< HEAD
# 1 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_SCIENTIST_1, 1
# 3 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 4 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_SCIENTIST_2, 3
# 5 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_SCIENTIST_3, 4
# 6 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_SCIENTIST_4, 5
# 7 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_SCIENTIST_5, 6
# 8 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_SCIENTIST_6, 7
# 9 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 8
# 10 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_MapScripts::
# 12 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleFactoryBattleRoom_OnTransition
# 13 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnWarp
# 14 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnFrame
# 15 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.byte 0
# 16 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 17 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 18 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_F
# 19 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_OnTransition:
# 21 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_settrainers
# 22 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	checkplayergender
# 23 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, MALE, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale
# 24 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale
# 25 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 26 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 27 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj
# 28 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 30 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj::
# 31 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 32 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 7, 9
# 33 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 34 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 35 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_OnWarp:
# 36 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects
# 37 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.2byte 0
# 38 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 39 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects::
# 40 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 41 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
# 42 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects
# 43 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	hideobjectat LOCALID_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
# 44 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects::
# 45 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 46 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 47 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale::
# 48 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 49 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 50 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 51 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale::
# 52 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 53 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 54 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_OnFrame:
# 56 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom
# 57 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.2byte 0
# 58 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 59 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle::
# 60 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn, MSGBOX_DEFAULT
# 61 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 62 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle
# 63 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 64 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 65 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
# 67 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent
# 68 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 69 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 70 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom::
# 71 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle
# 72 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 73 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
# 74 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
# 76 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_setopponentgfx
# 77 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 78 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 7, 1
# 79 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 80 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter
# 81 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent::
# 83 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland
# 84 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	palace_getopponentintro
# 85 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	lockall
# 86 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 87 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 88 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 89 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 90 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special HealPlayerParty
# 91 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
# 92 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 93 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 94 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 95 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	switch VAR_RESULT
# 96 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent
# 97 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost::
# 98 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 99 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby
# 100 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 101 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent::
# 102 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_get FACTORY_DATA_WIN_STREAK_SWAPS
# 103 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
# 104 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 105 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 106 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS  @ uses VAR_0x8006 above
# 107 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak::
# 108 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 109 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum::
# 110 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 111 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 112 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 113 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	switch VAR_RESULT
# 114 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
# 115 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 116 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 8
# 117 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 118 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon::
# 119 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 120 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby
# 121 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 122 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland::
# 123 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 124 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold
# 125 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
# 126 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
# 127 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 128 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
# 129 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead, MSGBOX_DEFAULT
# 130 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 131 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver::
# 132 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn, MSGBOX_DEFAULT
# 133 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
# 134 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver
# 135 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 136 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 137 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver::
# 138 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_getsymbols
# 139 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 140 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass, MSGBOX_DEFAULT
# 141 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 142 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
# 143 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 144 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 145 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol
# 146 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 147 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitfanfare
# 148 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_givesymbol
# 149 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred, MSGBOX_DEFAULT
# 150 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 151 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 152 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold::
# 153 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 154 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
# 155 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime, MSGBOX_DEFAULT
# 156 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 157 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold::
# 158 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn, MSGBOX_DEFAULT
# 159 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
# 160 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold
# 161 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 162 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 163 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold::
# 164 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_getsymbols
# 165 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 166 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass, MSGBOX_DEFAULT
# 167 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 168 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
# 169 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 170 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 171 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine
# 172 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmessage
# 173 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitfanfare
# 174 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_givesymbol
# 175 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou, MSGBOX_DEFAULT
# 176 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
# 177 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 178 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle::
# 179 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	closemessage
# 180 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 181 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special HealPlayerParty
# 182 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
# 183 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 184 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 185 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 186 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 187 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland::
# 189 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_get FACTORY_DATA_WIN_STREAK_SWAPS
# 190 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
# 191 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 192 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 193 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS  @ uses VAR_0x8006 above
# 194 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_get FACTORY_DATA_WIN_STREAK
# 195 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum
# 196 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 197 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, VAR_RESULT
# 198 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 199 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 200 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
# 201 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 202 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 203 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom:
# 204 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 206 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 207 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 208 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 209 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	face_right
# 210 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 211 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 212 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland:
# 213 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_right
# 214 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 215 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 216 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter:
# 217 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 218 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 219 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 220 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 221 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_down
# 222 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	face_left
# 223 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 224 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle:
# 226 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 227 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 228 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	walk_up
# 229 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	face_left
# 230 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	step_end
# 231 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 232 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby::
# 233 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 234 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles
# 235 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 4, 8
# 236 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 237 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 238 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 239 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles::
# 240 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 14, 8
# 241 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitstate
# 242 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	end
# 243 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 244 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle::
# 245 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_SCIENTIST_1, Common_Movement_WalkInPlaceFasterRight
# 246 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
# 247 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_SCIENTIST_3, Common_Movement_WalkInPlaceFasterRight
# 248 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_SCIENTIST_4, Common_Movement_WalkInPlaceFasterLeft
# 249 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_SCIENTIST_5, Common_Movement_WalkInPlaceFasterLeft
# 250 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	applymovement LOCALID_SCIENTIST_6, Common_Movement_WalkInPlaceFasterLeft
# 251 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	waitmovement 0
# 252 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	return
# 253 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 254 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn:
# 255 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Hey, hey!\n"
# 256 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Get a move on!$"
# 257 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 258 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead:
# 259 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Hey, my name's NOLAND!\n"
# 260 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'm basically in charge of this place,\l"
# 261 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "which is why I'm the FACTORY HEAD!\p"
# 262 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I had a look at your Battle Swap data.\p"
# 263 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You seem to have the right idea,\n"
# 264 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "but you're still square in your head!\p"
# 265 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Listen up, okay? Knowledge isn't only\n"
# 266 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "about reading books or doing desk work.\p"
# 267 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Just doing that sort of thing…\n"
# 268 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "It may as well be useless!\p"
# 269 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You have to experience things with\n"
# 270 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "your heart and your body, understand?\p"
# 271 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'll take you on under the same\n"
# 272 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "conditions as you.\p"
# 273 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'll be using rental POKéMON, too!$"
# 274 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 275 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn:
# 276 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Shake out every last bit of your\n"
# 277 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "knowledge and bring it on!$"
# 278 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 279 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass:
# 280 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "NOLAND: Smart going!\n"
# 281 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS.$"
# 282 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 283 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol:
# 284 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "The Knowledge Symbol was embossed\n"
# 285 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "on the FRONTIER PASS!$"
# 286 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 287 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred:
# 288 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Heh…\n"
# 289 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You're a pretty bright spark…\p"
# 290 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Next time, I'll come after you hard.\n"
# 291 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "No holds barred, understand?\p"
# 292 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You keep up your studies!$"
# 293 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime:
# 295 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "NOLAND: Hey, hey! How's it going?\n"
# 296 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You keeping up with your studies?\p"
# 297 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "…Oh?\p"
# 298 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You've taken on a harder look than\n"
# 299 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "the last time I saw you.\p"
# 300 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Now, this should be fun!\n"
# 301 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I'm getting excited, hey!$"
# 302 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 303 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn:
# 304 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "All right!\n"
# 305 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Bring it on!$"
# 306 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 307 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass:
# 308 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "NOLAND: What the…\n"
# 309 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "You're getting out of my league!\p"
# 310 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Sheesh!\n"
# 311 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Let's see that FRONTIER PASS!$"
# 312 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 313 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine:
# 314 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "The Knowledge Symbol took on\n"
# 315 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 316 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"

# 317 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou:
# 318 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "Pfft, man!\p"
# 319 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "That's absolutely the last time\n"
# 320 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "I lose to you!\p"
# 321 "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.pory"
	.string "We have to do this again, hey?$"
=======
.set LOCALID_SCIENTIST_1, 1
.set LOCALID_OPPONENT, 2
.set LOCALID_SCIENTIST_2, 3
.set LOCALID_SCIENTIST_3, 4
.set LOCALID_SCIENTIST_4, 5
.set LOCALID_SCIENTIST_5, 6
.set LOCALID_SCIENTIST_6, 7
.set LOCALID_PLAYER, 8

BattleFrontier_BattleFactoryBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleFactoryBattleRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryBattleRoom_OnFrame
	.byte 0

	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_F

BattleFrontier_BattleFactoryBattleRoom_OnTransition:
	frontier_settrainers
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale
	call_if_eq VAR_RESULT, FEMALE, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale
	frontier_getbrainstatus
	copyvar VAR_TEMP_F, VAR_RESULT
	goto_if_ne VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_SetUpFactoryHeadObj::
	call BattleFrontier_EventScript_SetBrainObjectGfx
	setobjectxyperm LOCALID_OPPONENT, 7, 9
	end

BattleFrontier_BattleFactoryBattleRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_HideObjects::
	setvar VAR_TEMP_1, 1
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects
	hideobjectat LOCALID_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM
BattleFrontier_BattleFactoryBattleRoom_EventScript_EndHideObjects::
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxMale::
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_SetPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

BattleFrontier_BattleFactoryBattleRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom
	.2byte 0

BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle::
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoom::
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_EnterRoomFactoryHeadBattle
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom
	waitmovement 0
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle
	factory_setopponentgfx
	removeobject LOCALID_OPPONENT
	setobjectxyperm LOCALID_OPPONENT, 7, 1
	addobject LOCALID_OPPONENT
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter
	waitmovement 0
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent::
	goto_if_ne VAR_TEMP_F, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland
	palace_getopponentintro
	lockall
	msgbox gStringVar4, MSGBOX_DEFAULT
	waitmessage
	closemessage
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedOpponent::
	factory_get FACTORY_DATA_WIN_STREAK_SWAPS
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
	addvar VAR_RESULT, 1
	setorcopyvar VAR_0x8006, VAR_RESULT
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS  @ uses VAR_0x8006 above
BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak::
	call BattleFrontier_EventScript_IncrementWinStreak
BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	switch VAR_RESULT
	case 7, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
	setvar VAR_0x8006, 1
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 8
	waitstate
BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby

BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNoland::
	switch VAR_TEMP_F
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandSilver::
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn, MSGBOX_DEFAULT
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandSilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
	waitmovement 0
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland

BattleFrontier_BattleFactoryBattleRoom_EventScript_IntroNolandGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime, MSGBOX_DEFAULT
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleNolandGold::
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn, MSGBOX_DEFAULT
	call BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNolandGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland
	waitmovement 0
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland

BattleFrontier_BattleFactoryBattleRoom_EventScript_DoNolandBattle::
	closemessage
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	return

BattleFrontier_BattleFactoryBattleRoom_EventScript_DefeatedNoland::
	factory_get FACTORY_DATA_WIN_STREAK_SWAPS
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementWinStreak
	addvar VAR_RESULT, 1
	setorcopyvar VAR_0x8006, VAR_RESULT
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS  @ uses VAR_0x8006 above
	factory_get FACTORY_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, MAX_STREAK, BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum
	addvar VAR_RESULT, 1
	factory_set FACTORY_DATA_WIN_STREAK, VAR_RESULT
	frontier_get FRONTIER_DATA_BATTLE_NUM
	addvar VAR_RESULT, 1
	goto BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyWon
	end

BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerEnterRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_PlayerApproachNoland:
	walk_right
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_OpponentEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_NolandMoveToBattle:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobby::
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
	goto_if_eq VAR_RESULT, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 4, 8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyDoubles::
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 14, 8
	waitstate
	end

BattleFrontier_BattleFactoryBattleRoom_EventScript_ScientistsFaceBattle::
	applymovement LOCALID_SCIENTIST_1, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_SCIENTIST_2, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_SCIENTIST_3, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_SCIENTIST_4, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SCIENTIST_5, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SCIENTIST_6, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_BattleFactoryBattleRoom_Text_GetAMoveOn:
	.string "Hey, hey!\n"
	.string "Get a move on!$"

BattleFrontier_BattleFactoryBattleRoom_Text_NolandImFactoryHead:
	.string "Hey, my name's NOLAND!\n"
	.string "I'm basically in charge of this place,\l"
	.string "which is why I'm the FACTORY HEAD!\p"
	.string "I had a look at your Battle Swap data.\p"
	.string "You seem to have the right idea,\n"
	.string "but you're still square in your head!\p"
	.string "Listen up, okay? Knowledge isn't only\n"
	.string "about reading books or doing desk work.\p"
	.string "Just doing that sort of thing…\n"
	.string "It may as well be useless!\p"
	.string "You have to experience things with\n"
	.string "your heart and your body, understand?\p"
	.string "I'll take you on under the same\n"
	.string "conditions as you.\p"
	.string "I'll be using rental POKéMON, too!$"

BattleFrontier_BattleFactoryBattleRoom_Text_ShakeOutKnowledgeBringItOn:
	.string "Shake out every last bit of your\n"
	.string "knowledge and bring it on!$"

BattleFrontier_BattleFactoryBattleRoom_Text_NolandLetsSeeFrontierPass:
	.string "NOLAND: Smart going!\n"
	.string "Let's see your FRONTIER PASS.$"

BattleFrontier_BattleFactoryBattleRoom_Text_ReceivedKnowledgeSymbol:
	.string "The Knowledge Symbol was embossed\n"
	.string "on the FRONTIER PASS!$"

BattleFrontier_BattleFactoryBattleRoom_Text_NextTimeNoHoldsBarred:
	.string "Heh…\n"
	.string "You're a pretty bright spark…\p"
	.string "Next time, I'll come after you hard.\n"
	.string "No holds barred, understand?\p"
	.string "You keep up your studies!$"

BattleFrontier_BattleFactoryBattleRoom_Text_HarderLookThanLastTime:
	.string "NOLAND: Hey, hey! How's it going?\n"
	.string "You keeping up with your studies?\p"
	.string "…Oh?\p"
	.string "You've taken on a harder look than\n"
	.string "the last time I saw you.\p"
	.string "Now, this should be fun!\n"
	.string "I'm getting excited, hey!$"

BattleFrontier_BattleFactoryBattleRoom_Text_AllRightBringItOn:
	.string "All right!\n"
	.string "Bring it on!$"

BattleFrontier_BattleFactoryBattleRoom_Text_OutOfMyLeagueLetsSeePass:
	.string "NOLAND: What the…\n"
	.string "You're getting out of my league!\p"
	.string "Sheesh!\n"
	.string "Let's see that FRONTIER PASS!$"

BattleFrontier_BattleFactoryBattleRoom_Text_KnowledgeSymbolTookGoldenShine:
	.string "The Knowledge Symbol took on\n"
	.string "a golden shine!$"

BattleFrontier_BattleFactoryBattleRoom_Text_LastTimeILoseToYou:
	.string "Pfft, man!\p"
	.string "That's absolutely the last time\n"
	.string "I lose to you!\p"
	.string "We have to do this again, hey?$"

>>>>>>> upstream/master
