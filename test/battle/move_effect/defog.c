#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_DEFOG].effect == EFFECT_DEFOG);
    ASSUME(gMovesInfo[MOVE_REFLECT].effect == EFFECT_REFLECT);
    ASSUME(gMovesInfo[MOVE_LIGHT_SCREEN].effect == EFFECT_LIGHT_SCREEN);
    ASSUME(gMovesInfo[MOVE_MIST].effect == EFFECT_MIST);
    ASSUME(gMovesInfo[MOVE_SAFEGUARD].effect == EFFECT_SAFEGUARD);
    ASSUME(gMovesInfo[MOVE_AURORA_VEIL].effect == EFFECT_AURORA_VEIL);
    ASSUME(gMovesInfo[MOVE_STEALTH_ROCK].effect == EFFECT_STEALTH_ROCK);
    ASSUME(gMovesInfo[MOVE_SPIKES].effect == EFFECT_SPIKES);
    ASSUME(gMovesInfo[MOVE_TOXIC_SPIKES].effect == EFFECT_TOXIC_SPIKES);
    ASSUME(gMovesInfo[MOVE_STICKY_WEB].effect == EFFECT_STICKY_WEB);
    ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
    ASSUME(gMovesInfo[MOVE_SCREECH].effect == EFFECT_DEFENSE_DOWN_2);
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_GUST].category == DAMAGE_CATEGORY_SPECIAL);
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Defog lowers evasiveness by 1")
=======
SINGLE_BATTLE_TEST("Defog lowers evasiveness by 1 stage")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DEFOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
<<<<<<< HEAD
        MESSAGE("Foe Wobbuffet's evasiveness fell!");
=======
        MESSAGE("The opposing Wobbuffet's evasiveness fell!");
>>>>>>> upstream/master
    }
}

SINGLE_BATTLE_TEST("Defog does not lower evasiveness if target behind Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_DEFOG); }
    } SCENE {
<<<<<<< HEAD
        MESSAGE("Foe Wobbuffet used Substitute!");
=======
        MESSAGE("The opposing Wobbuffet used Substitute!");
>>>>>>> upstream/master
        MESSAGE("But it failed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
<<<<<<< HEAD
            MESSAGE("Foe Wobbuffet's evasiveness fell!");
=======
            MESSAGE("The opposing Wobbuffet's evasiveness fell!");
>>>>>>> upstream/master
        }
    }
}

<<<<<<< HEAD
DOUBLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes Reflect and Light Screen from opponent's side", s16 damagePhysical, s16 damageSpecial)
=======
TO_DO_BATTLE_TEST("Defog doesn't remove Reflect or Light Screen from the user's side");
DOUBLE_BATTLE_TEST("Defog removes Reflect and Light Screen from target's side", s16 damagePhysical, s16 damageSpecial)
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_REFLECT); MOVE(opponentRight, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); MOVE(playerRight, MOVE_GUST, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        if (move == MOVE_DEFOG) {
<<<<<<< HEAD
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Wobbuffet's evasiveness fell!");
            MESSAGE("Foe's Reflect wore off!");
            MESSAGE("Foe's Light Screen wore off!");
=======
            MESSAGE("The opposing team's Reflect wore off!");
            MESSAGE("The opposing team's Light Screen wore off!");
>>>>>>> upstream/master
        }
        MESSAGE("Wobbuffet used Tackle!");
        HP_BAR(opponentLeft, captureDamage: &results[i].damagePhysical);
        MESSAGE("Wobbuffet used Gust!");
        HP_BAR(opponentRight, captureDamage: &results[i].damageSpecial);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damagePhysical, Q_4_12(1.5), results[0].damagePhysical);
        EXPECT_MUL_EQ(results[1].damageSpecial, Q_4_12(1.5), results[0].damageSpecial);
    }
}

<<<<<<< HEAD
DOUBLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes Mist and Safeguard from opponent's side")
=======
TO_DO_BATTLE_TEST("Defog doesn't remove Mist or Safeguard from the user's side");
DOUBLE_BATTLE_TEST("Defog removes Mist and Safeguard from target's side")
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_MIST); MOVE(opponentRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SCREECH, target: opponentLeft); MOVE(playerRight, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, opponentRight);
        if (move == MOVE_DEFOG) {
<<<<<<< HEAD
            MESSAGE("Foe Wobbuffet is protected by MIST!");
            ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
            MESSAGE("Foe's Mist wore off!");
            MESSAGE("Foe's Safeguard wore off!");
=======
            ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
            MESSAGE("The opposing team's Mist wore off!");
            MESSAGE("The opposing team's Safeguard wore off!");
>>>>>>> upstream/master
        }
        MESSAGE("Wobbuffet used Screech!");
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
        else {
<<<<<<< HEAD
            MESSAGE("Foe Wobbuffet is protected by MIST!");
=======
            MESSAGE("The opposing Wobbuffet is protected by the mist!");
>>>>>>> upstream/master
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
        MESSAGE("Wobbuffet used Toxic!");
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, playerRight);
            STATUS_ICON(opponentRight, badPoison: TRUE);
        }
        else {
<<<<<<< HEAD
            MESSAGE("Foe Wobbuffet's party is protected by Safeguard!");
=======
            MESSAGE("The opposing Wobbuffet is protected by Safeguard!");
>>>>>>> upstream/master
            NOT STATUS_ICON(opponentRight, badPoison: TRUE);
        }
    }
}

<<<<<<< HEAD
DOUBLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes Stealth Rock and Sticky Web from player's side")
=======
TO_DO_BATTLE_TEST("Defog removes Stealth Rock and Sticky Web from target's side");
TO_DO_BATTLE_TEST("Defog doesn't remove Stealth Rock or Sticky Web from user's side (Gen 4-5)");
DOUBLE_BATTLE_TEST("Defog removes Stealth Rock and Sticky Web from user's side (Gen 6+)")
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STEALTH_ROCK); MOVE(opponentRight, MOVE_STICKY_WEB); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
<<<<<<< HEAD
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Wobbuffet's evasiveness fell!");
=======
        if (move == MOVE_DEFOG && B_DEFOG_EFFECT_CLEARING >= GEN_6) {
>>>>>>> upstream/master
            MESSAGE("The pointed stones disappeared from around your team!");
            MESSAGE("The sticky web has disappeared from the ground around your team!");
        }
        // Switch happens
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
<<<<<<< HEAD
        if (move != MOVE_DEFOG) {
            HP_BAR(playerLeft);
            MESSAGE("Pointed stones dug into Wobbuffet!");
            MESSAGE("Wobbuffet was caught in a Sticky Web!");
=======
        if (move != MOVE_DEFOG || B_DEFOG_EFFECT_CLEARING <= GEN_5) {
            HP_BAR(playerLeft);
            MESSAGE("Pointed stones dug into Wobbuffet!");
            MESSAGE("Wobbuffet was caught in a sticky web!");
>>>>>>> upstream/master
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Wobbuffet's Speed fell!");
        }
        else {
            NONE_OF {
                HP_BAR(playerLeft);
                MESSAGE("Pointed stones dug into Wobbuffet!");
<<<<<<< HEAD
                MESSAGE("Wobbuffet was caught in a Sticky Web!");
=======
                MESSAGE("Wobbuffet was caught in a sticky web!");
>>>>>>> upstream/master
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
                MESSAGE("Wobbuffet's Speed fell!");
            }
        }
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes Spikes from player's side")
=======
TO_DO_BATTLE_TEST("Defog removes Spikes from target's side");
TO_DO_BATTLE_TEST("Defog doesn't remove Spikes from user's side (Gen 4-5)");
SINGLE_BATTLE_TEST("Defog removes Spikes from user's side (Gen 6+)")
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPIKES); MOVE(player, move); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
<<<<<<< HEAD
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Wobbuffet's evasiveness fell!");
            MESSAGE("The spikes disappeared from the ground around your team!");
        }
        // Switch happens
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
        if (move != MOVE_DEFOG) {
            HP_BAR(player);
            MESSAGE("Wobbuffet is hurt by spikes!");
=======
        if (move == MOVE_DEFOG && B_DEFOG_EFFECT_CLEARING >= GEN_6)
            MESSAGE("The spikes disappeared from the ground around your team!");
        // Switch happens
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wobbuffet");
        if (move != MOVE_DEFOG || B_DEFOG_EFFECT_CLEARING <= GEN_5) {
            HP_BAR(player);
            MESSAGE("Wobbuffet was hurt by the spikes!");
>>>>>>> upstream/master
        }
        else {
            NONE_OF {
                HP_BAR(player);
<<<<<<< HEAD
                MESSAGE("Wobbuffet is hurt by spikes!");
=======
                MESSAGE("Wobbuffet was hurt by the spikes!");
>>>>>>> upstream/master
            }
        }
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes terrain")
=======
TO_DO_BATTLE_TEST("Defog doesn't remove terrain (Gen 4-7)");
SINGLE_BATTLE_TEST("Defog removes terrain (Gen 8+)")
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_PSYCHIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN; }
    PARAMETRIZE { move = MOVE_GRASSY_TERRAIN; }
    GIVEN {
<<<<<<< HEAD
        ASSUME(B_DEFOG_CLEARS_TERRAIN >= GEN_8);
=======
>>>>>>> upstream/master
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_DEFOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, opponent);
<<<<<<< HEAD
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's evasiveness fell!");
        if (move == MOVE_PSYCHIC_TERRAIN) {
            MESSAGE("The weirdness disappeared from the battlefield.");
        }
        else if (move == MOVE_ELECTRIC_TERRAIN) {
            MESSAGE("The electricity disappeared from the battlefield.");
        }
        else if (move == MOVE_MISTY_TERRAIN) {
            MESSAGE("The mist disappeared from the battlefield.");
        }
        else if (move == MOVE_GRASSY_TERRAIN) {
            MESSAGE("The grass disappeared from the battlefield.");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG, player);
    }
}

SINGLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes Toxic Spikes from opponent's side")
=======
        if (B_DEFOG_EFFECT_CLEARING >= GEN_8) {
            if (move == MOVE_PSYCHIC_TERRAIN) {
                MESSAGE("The weirdness disappeared from the battlefield!");
            }
            else if (move == MOVE_ELECTRIC_TERRAIN) {
                MESSAGE("The electricity disappeared from the battlefield.");
            }
            else if (move == MOVE_MISTY_TERRAIN) {
                MESSAGE("The mist disappeared from the battlefield.");
            }
            else if (move == MOVE_GRASSY_TERRAIN) {
                MESSAGE("The grass disappeared from the battlefield.");
            }
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG, player);
        } else {
            NONE_OF {
                MESSAGE("The weirdness disappeared from the battlefield!");
                MESSAGE("The electricity disappeared from the battlefield.");
                MESSAGE("The mist disappeared from the battlefield.");
                MESSAGE("The grass disappeared from the battlefield.");
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG, player);
            }
        }
    }
}

TO_DO_BATTLE_TEST("Defog removes Toxic Spikes from target's side");
TO_DO_BATTLE_TEST("Defog doesn't remove Toxic Spikes from user's side (Gen 4-5)");
SINGLE_BATTLE_TEST("Defog removes Toxic Spikes from user's side (Gen 6+)")
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, move); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
<<<<<<< HEAD
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Wobbuffet's evasiveness fell!");
            MESSAGE("The poison spikes disappeared from the ground around the opposing team!");
        }
        // Switch happens
        MESSAGE("2 sent out Wobbuffet!");
        if (move != MOVE_DEFOG) {
            MESSAGE("Foe Wobbuffet was poisoned!");
=======
        if (move == MOVE_DEFOG && B_DEFOG_EFFECT_CLEARING >= GEN_6)
            MESSAGE("The poison spikes disappeared from the ground around the opposing team!");
        // Switch happens
        MESSAGE("2 sent out Wobbuffet!");
        if (move != MOVE_DEFOG || B_DEFOG_EFFECT_CLEARING <= GEN_5) {
            MESSAGE("The opposing Wobbuffet was poisoned!");
>>>>>>> upstream/master
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        }
        else {
            NONE_OF {
<<<<<<< HEAD
                MESSAGE("Foe Wobbuffet was poisoned!");
=======
                MESSAGE("The opposing Wobbuffet was poisoned!");
>>>>>>> upstream/master
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

<<<<<<< HEAD
DOUBLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes Aurora Veil from player's side", s16 damagePhysical, s16 damageSpecial)
=======
TO_DO_BATTLE_TEST("Defog doesn't remove Aurora Veil from the user's side");
DOUBLE_BATTLE_TEST("Defog removes Aurora Veil from target's side", s16 damagePhysical, s16 damageSpecial)
>>>>>>> upstream/master
{
    u16 move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
        ASSUME(gSpeciesInfo[SPECIES_GLALIE].types[0] == TYPE_ICE);
        PLAYER(SPECIES_GLALIE) { Speed(4); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        OPPONENT(SPECIES_GLALIE) { Speed(2); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_AURORA_VEIL); }
        TURN { MOVE(opponentLeft, move, target: playerLeft); }
        TURN { MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); MOVE(opponentRight, MOVE_GUST, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURORA_VEIL, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Glalie's evasiveness fell!");
<<<<<<< HEAD
            MESSAGE("Ally's Aurora Veil wore off!");
        }
        MESSAGE("Foe Glalie used Tackle!");
        HP_BAR(playerLeft, captureDamage: &results[i].damagePhysical);
        MESSAGE("Foe Glalie used Gust!");
=======
            MESSAGE("Your team's Aurora Veil wore off!");
        }
        MESSAGE("The opposing Glalie used Tackle!");
        HP_BAR(playerLeft, captureDamage: &results[i].damagePhysical);
        MESSAGE("The opposing Glalie used Gust!");
>>>>>>> upstream/master
        HP_BAR(playerRight, captureDamage: &results[i].damageSpecial);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damagePhysical, Q_4_12(1.5), results[0].damagePhysical);
        EXPECT_MUL_EQ(results[1].damageSpecial, Q_4_12(1.5), results[0].damageSpecial);
    }
}

<<<<<<< HEAD
DOUBLE_BATTLE_TEST("Defog lowers evasiveness by 1 and removes everything it can")
=======
DOUBLE_BATTLE_TEST("Defog removes everything it can")
>>>>>>> upstream/master
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HAIL].effect == EFFECT_HAIL);
        ASSUME(gSpeciesInfo[SPECIES_GLALIE].types[0] == TYPE_ICE);
        PLAYER(SPECIES_GLALIE) { Speed(4); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        PLAYER(SPECIES_GLALIE) { Speed(12); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        OPPONENT(SPECIES_GLALIE) { Speed(2); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STICKY_WEB); MOVE(playerRight, MOVE_SPIKES); MOVE(opponentLeft, MOVE_STICKY_WEB); MOVE(opponentRight, MOVE_SPIKES); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); SWITCH(opponentLeft, 2); SWITCH(opponentRight, 3); }
        TURN { MOVE(playerLeft, MOVE_TOXIC_SPIKES); MOVE(playerRight, MOVE_STEALTH_ROCK); MOVE(opponentLeft, MOVE_TOXIC_SPIKES); MOVE(opponentRight, MOVE_STEALTH_ROCK); }
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_AURORA_VEIL); MOVE(opponentLeft, MOVE_AURORA_VEIL); MOVE(opponentRight, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(playerLeft, MOVE_REFLECT); MOVE(playerRight, MOVE_LIGHT_SCREEN); MOVE(opponentLeft, MOVE_REFLECT); MOVE(opponentRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, MOVE_MIST); MOVE(playerRight, MOVE_SAFEGUARD); MOVE(opponentLeft, MOVE_MIST); MOVE(opponentRight, MOVE_DEFOG, target: playerLeft); }
    } SCENE {
<<<<<<< HEAD
        MESSAGE("Foe Glalie used Defog!");
        MESSAGE("Glalie is protected by MIST!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, opponentRight);
        // Player side
        MESSAGE("Ally's Reflect wore off!");
        MESSAGE("Ally's Light Screen wore off!");
        MESSAGE("Ally's Mist wore off!");
        MESSAGE("Ally's Aurora Veil wore off!");
        MESSAGE("Ally's Safeguard wore off!");

        MESSAGE("The spikes disappeared from the ground around your team!");
        MESSAGE("The pointed stones disappeared from around your team!");
        MESSAGE("The poison spikes disappeared from the ground around your team!");
        MESSAGE("The sticky web has disappeared from the ground around your team!");

        // Opponent side
        MESSAGE("The spikes disappeared from the ground around the opposing team!");
        MESSAGE("The pointed stones disappeared from around the opposing team!");
        MESSAGE("The poison spikes disappeared from the ground around the opposing team!");
        MESSAGE("The sticky web has disappeared from the ground around the opposing team!");
=======
        MESSAGE("The opposing Glalie used Defog!");
        MESSAGE("Glalie is protected by the mist!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, opponentRight);
        // Player side
        MESSAGE("Your team's Reflect wore off!");
        MESSAGE("Your team's Light Screen wore off!");
        MESSAGE("Your team's Mist wore off!");
        MESSAGE("Your team's Aurora Veil wore off!");
        MESSAGE("Your team's Safeguard wore off!");

        if (B_DEFOG_EFFECT_CLEARING >= GEN_6) {
            MESSAGE("The spikes disappeared from the ground around your team!");
            MESSAGE("The pointed stones disappeared from around your team!");
            MESSAGE("The poison spikes disappeared from the ground around your team!");
            MESSAGE("The sticky web has disappeared from the ground around your team!");

            // Opponent side
            MESSAGE("The spikes disappeared from the ground around the opposing team!");
            MESSAGE("The pointed stones disappeared from around the opposing team!");
            MESSAGE("The poison spikes disappeared from the ground around the opposing team!");
            MESSAGE("The sticky web has disappeared from the ground around the opposing team!");
        }
    }
}

SINGLE_BATTLE_TEST("Defog is used on the correct side if opposing mon is behind a substitute with Screen up")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_DEFOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        MESSAGE("Wobbuffet used Defog!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        MESSAGE("The opposing Wobbuffet's evasiveness fell!");
        MESSAGE("The opposing team's Light Screen wore off!");
>>>>>>> upstream/master
    }
}
