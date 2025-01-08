<<<<<<< HEAD
# 1 "data/maps/MirageTower_3F/scripts.pory"

# 2 "data/maps/MirageTower_3F/scripts.pory"
MirageTower_3F_MapScripts::
# 3 "data/maps/MirageTower_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
# 4 "data/maps/MirageTower_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
# 5 "data/maps/MirageTower_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_3F_SetHoleWarp
# 6 "data/maps/MirageTower_3F/scripts.pory"
	.byte 0
# 7 "data/maps/MirageTower_3F/scripts.pory"

# 8 "data/maps/MirageTower_3F/scripts.pory"
MirageTower_3F_SetHoleWarp:
# 9 "data/maps/MirageTower_3F/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 10 "data/maps/MirageTower_3F/scripts.pory"
	setholewarp MAP_MIRAGE_TOWER_2F
# 11 "data/maps/MirageTower_3F/scripts.pory"
	end
=======
MirageTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_3F_SetHoleWarp
	.byte 0

MirageTower_3F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MIRAGE_TOWER_2F
	end

>>>>>>> upstream/master
