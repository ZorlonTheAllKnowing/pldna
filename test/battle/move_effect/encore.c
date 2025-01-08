#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_ENCORE].effect == EFFECT_ENCORE);
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns for player: Encore used before move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
        // TURN { FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
        TURN { MOVE(player, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, player);
=======
SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns: Encore used before move")
{
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    u32 speedPlayer, speedOpponent;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; speedPlayer = 10; speedOpponent = 20; }
    PARAMETRIZE { encoreUser = player; encoreTarget = opponent; speedPlayer = 20; speedOpponent = 10; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOpponent); }
    } WHEN {
        TURN { MOVE(encoreUser, MOVE_CELEBRATE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { MOVE(encoreUser, MOVE_ENCORE); MOVE(encoreTarget, MOVE_CELEBRATE); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
>>>>>>> upstream/master
    }
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns for player: Encore used after move")
{
<<<<<<< HEAD
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_ENCORE); }
        TURN { FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
        TURN { FORCED_MOVE(player); }
        TURN { MOVE(player, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, player);
    }
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns for opponent: Encore used before move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_ENCORE); MOVE(opponent, MOVE_CELEBRATE); }
        // TURN { FORCED_MOVE(opponent); }
        TURN { FORCED_MOVE(opponent); }
        TURN { FORCED_MOVE(opponent); }
        TURN { MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
    }
}

SINGLE_BATTLE_TEST("Encore forces consecutive move uses for 3 turns for opponent: Encore used after move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ENCORE); }
        TURN { FORCED_MOVE(opponent); }
        TURN { FORCED_MOVE(opponent); }
        TURN { FORCED_MOVE(opponent); }
        TURN { MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponent);
=======
    struct BattlePokemon *encoreUser = NULL;
    struct BattlePokemon *encoreTarget = NULL;
    u32 speedPlayer, speedOpponent;
    PARAMETRIZE { encoreUser = opponent; encoreTarget = player; speedPlayer = 20; speedOpponent = 10; }
    PARAMETRIZE { encoreUser = player; encoreTarget = opponent; speedPlayer = 10; speedOpponent = 20; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPlayer); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOpponent); }
    } WHEN {
        TURN { MOVE(encoreTarget, MOVE_CELEBRATE); MOVE(encoreUser, MOVE_ENCORE); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { FORCED_MOVE(encoreTarget); }
        TURN { MOVE(encoreTarget, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, encoreUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, encoreTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, encoreTarget);
>>>>>>> upstream/master
    }
}

SINGLE_BATTLE_TEST("Encore has no effect if no previous move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
<<<<<<< HEAD
        MESSAGE("Foe Wobbuffet used Encore!");
=======
        MESSAGE("The opposing Wobbuffet used Encore!");
>>>>>>> upstream/master
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Encore overrides the chosen move if it occurs first")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}
<<<<<<< HEAD
=======

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Encore")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("But it failed!");
        MESSAGE("Wobbuffet used Max Flare!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can be encored immediately after reverting")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }; // yes, this speed is necessary
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN { MOVE(player, MOVE_ARM_THRUST, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("The opposing Wobbuffet used Encore!");
        MESSAGE("Wobbuffet used Arm Thrust!");
    }
}

TO_DO_BATTLE_TEST("Encore's effect ends if the encored move runs out of PP");
TO_DO_BATTLE_TEST("Encore lasts for 2-6 turns (Gen 2-3)");
TO_DO_BATTLE_TEST("Encore lasts for 4-8 turns (Gen 4)");
TO_DO_BATTLE_TEST("Encore lasts for 3 turns (Gen 5+)");
TO_DO_BATTLE_TEST("Encore randomly chooses an opponent target");
>>>>>>> upstream/master
