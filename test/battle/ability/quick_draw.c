#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Quick Draw has a 30% chance of going first")
{
    PASSES_RANDOMLY(3, 10, RNG_QUICK_DRAW);
    GIVEN {
<<<<<<< HEAD
        PLAYER(SPECIES_SLOWBRO_GALARIAN) { Ability(ABILITY_QUICK_DRAW); Speed(1); }
=======
        PLAYER(SPECIES_SLOWBRO_GALAR) { Ability(ABILITY_QUICK_DRAW); Speed(1); }
>>>>>>> upstream/master
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_QUICK_DRAW);
        MESSAGE("Slowbro used Tackle!");
<<<<<<< HEAD
        MESSAGE("Foe Wobbuffet used Celebrate!");
=======
        MESSAGE("The opposing Wobbuffet used Celebrate!");
>>>>>>> upstream/master
    }
}

SINGLE_BATTLE_TEST("Quick Draw does not activate 70% of the time")
{
    PASSES_RANDOMLY(7, 10, RNG_QUICK_DRAW);
    GIVEN {
<<<<<<< HEAD
        PLAYER(SPECIES_SLOWBRO_GALARIAN) { Ability(ABILITY_QUICK_DRAW); Speed(1); }
=======
        PLAYER(SPECIES_SLOWBRO_GALAR) { Ability(ABILITY_QUICK_DRAW); Speed(1); }
>>>>>>> upstream/master
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_QUICK_DRAW);
<<<<<<< HEAD
        MESSAGE("Foe Wobbuffet used Celebrate!");
=======
        MESSAGE("The opposing Wobbuffet used Celebrate!");
>>>>>>> upstream/master
        MESSAGE("Slowbro used Tackle!");
    }
}
