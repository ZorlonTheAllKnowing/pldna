# 1 "data/maps/aStupidCity/scripts.pory"
aStupidCity_MapScripts::
# 2 "data/maps/aStupidCity/scripts.pory"
	.byte 0

RainTrigger::
# 6 "data/maps/aStupidCity/scripts.pory"
	setweather WEATHER_RAIN
# 7 "data/maps/aStupidCity/scripts.pory"
	doweather
	return


SunTrigger::
# 11 "data/maps/aStupidCity/scripts.pory"
	setweather WEATHER_SUNNY
# 12 "data/maps/aStupidCity/scripts.pory"
	doweather
	return


giveBulbasaur::
# 16 "data/maps/aStupidCity/scripts.pory"
	lockall
# 17 "data/maps/aStupidCity/scripts.pory"
	msgbox giveBulbasaur_Text_0
# 18 "data/maps/aStupidCity/scripts.pory"
	givemon SPECIES_BULBASAUR, 10, ITEM_POKE_BALL
# 19 "data/maps/aStupidCity/scripts.pory"
	givemon SPECIES_IVYSAUR, 10, ITEM_POKE_BALL
# 20 "data/maps/aStupidCity/scripts.pory"
	givemon SPECIES_VENUSAUR, 10, ITEM_POKE_BALL
# 21 "data/maps/aStupidCity/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 22 "data/maps/aStupidCity/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 23 "data/maps/aStupidCity/scripts.pory"
	special SetUnlockedPokedexFlags
# 24 "data/maps/aStupidCity/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 25 "data/maps/aStupidCity/scripts.pory"
	special EnableNationalPokedex
# 26 "data/maps/aStupidCity/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 27 "data/maps/aStupidCity/scripts.pory"
	releaseall
	return


giveBulbasaur_Text_0:
# 17 "data/maps/aStupidCity/scripts.pory"
	.string "Take a Bulbsaur, Leave a Bulbasaur$"
