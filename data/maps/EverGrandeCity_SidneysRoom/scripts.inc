<<<<<<< HEAD
# 1 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
# 4 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
# 5 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
# 6 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
# 7 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.byte 0
# 8 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 9 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnTransition:
# 10 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
# 11 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
# 12 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 13 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 14 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnLoad:
# 15 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
# 16 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
# 17 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 18 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 19 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
# 20 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 21 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	return
# 22 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 23 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
# 24 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 25 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	return
# 26 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 27 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnWarp:
# 28 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
# 29 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.2byte 0
# 30 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 31 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
# 32 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 33 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 34 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 35 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_OnFrame:
# 36 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
# 37 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.2byte 0
# 38 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 39 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
# 40 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	lockall
# 41 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 42 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 1
# 43 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	releaseall
# 44 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 45 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 46 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_Sidney::
# 47 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	lock
# 48 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	faceplayer
# 49 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
# 50 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 51 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 52 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
# 53 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
# 54 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 55 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 56 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
# 57 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 58 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 59 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 60 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 61 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_EventScript_Defeated::
# 62 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
# 63 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 64 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 65 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	release
# 66 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	end
# 67 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 68 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_IntroSpeech:
# 69 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Welcome, challenger!\n"
# 70 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
# 71 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I like that look you're giving me.\n"
# 72 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "I guess you'll give me a good match.\l"
# 73 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "That's good! Looking real good!\p"
# 74 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "All right! You and me, let's enjoy\n"
# 75 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "a battle that can only be staged\l"
# 76 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "here in the POKéMON LEAGUE!$"
# 77 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 78 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_Defeat:
# 79 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, how do you like that? I lost!\n"
# 80 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Eh, it was fun, so it doesn't matter.$"
# 81 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"

# 82 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
# 83 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Well, listen to what this loser has\n"
# 84 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "to say.\p"
# 85 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "You've got what it takes to go far.\n"
# 86 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "Now, go on to the next room and enjoy\l"
# 87 "data/maps/EverGrandeCity_SidneysRoom/scripts.pory"
	.string "your next battle!$"
=======
EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	end

EverGrandeCity_SidneysRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech:
	.string "Welcome, challenger!\n"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the POKéMON LEAGUE!$"

EverGrandeCity_SidneysRoom_Text_Defeat:
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the next room and enjoy\l"
	.string "your next battle!$"

>>>>>>> upstream/master
