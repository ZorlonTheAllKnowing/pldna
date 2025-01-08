#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Costar copies an ally's stat stages upon entering battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_FLAMIGO) { Ability(ABILITY_COSTAR); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SWORDS_DANCE); }
        TURN { SWITCH(opponentRight, 2); MOVE(playerLeft, MOVE_CELEBRATE); }
    } SCENE {
        // Turn 1 - buff up
<<<<<<< HEAD
        MESSAGE("Foe Wobbuffet used Swords Dance!");
=======
        MESSAGE("The opposing Wobbuffet used Swords Dance!");
>>>>>>> upstream/master
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        // Turn 2 - Switch into Flamigo
        MESSAGE("2 sent out Flamigo!");
        ABILITY_POPUP(opponentRight, ABILITY_COSTAR);
<<<<<<< HEAD
        MESSAGE("Foe Flamigo copied Foe Wobbuffet's stat changes!");
=======
        MESSAGE("The opposing Flamigo copied the opposing Wobbuffet's stat changes!");
>>>>>>> upstream/master
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

// Copy from Ruin ability tests
TO_DO_BATTLE_TEST("Costar's message displays correctly after all battlers fainted - Player");
TO_DO_BATTLE_TEST("Costar's message displays correctly after all battlers fainted - Opponent");
