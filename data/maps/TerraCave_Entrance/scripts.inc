<<<<<<< HEAD
# 1 "data/maps/TerraCave_Entrance/scripts.pory"

# 2 "data/maps/TerraCave_Entrance/scripts.pory"
TerraCave_Entrance_MapScripts::
# 3 "data/maps/TerraCave_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_Entrance_OnTransition
# 4 "data/maps/TerraCave_Entrance/scripts.pory"
	.byte 0
# 5 "data/maps/TerraCave_Entrance/scripts.pory"

# 6 "data/maps/TerraCave_Entrance/scripts.pory"
TerraCave_Entrance_OnTransition:
# 7 "data/maps/TerraCave_Entrance/scripts.pory"
	setflag FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE
# 8 "data/maps/TerraCave_Entrance/scripts.pory"
	end
=======
TerraCave_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_Entrance_OnTransition
	.byte 0

TerraCave_Entrance_OnTransition:
	setflag FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE
	end

>>>>>>> upstream/master
