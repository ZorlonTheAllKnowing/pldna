#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Population Bomb can hit ten times")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_POPULATION_BOMB].strikeCount == 10);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POPULATION_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
<<<<<<< HEAD
        MESSAGE("Hit 10 time(s)!");
=======
        MESSAGE("The Pokémon was hit 10 time(s)!");
>>>>>>> upstream/master
    }
}

TO_DO_BATTLE_TEST("Accuracy for Population Bomb is checked independently for each hit")
TO_DO_BATTLE_TEST("Accuracy for Population Bomb is only checked for the first hit with Skill Link")
TO_DO_BATTLE_TEST("Accuracy for Population Bomb is only checked for the first hit with Loaded Dice")
