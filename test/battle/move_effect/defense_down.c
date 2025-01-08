#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TAIL_WHIP].effect == EFFECT_DEFENSE_DOWN);
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Tail Whip lowers Defense", s16 damage)
=======
SINGLE_BATTLE_TEST("Tail Whip lowers Defense by 1 stage", s16 damage)
>>>>>>> upstream/master
{
    bool32 lowerDefense;
    PARAMETRIZE { lowerDefense = FALSE; }
    PARAMETRIZE { lowerDefense = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (lowerDefense) TURN { MOVE(player, MOVE_TAIL_WHIP); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (lowerDefense) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TAIL_WHIP, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
<<<<<<< HEAD
            MESSAGE("Foe Wobbuffet's Defense fell!");
=======
            MESSAGE("The opposing Wobbuffet's Defense fell!");
>>>>>>> upstream/master
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
