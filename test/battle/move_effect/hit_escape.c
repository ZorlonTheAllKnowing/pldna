#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_U_TURN].effect == EFFECT_HIT_ESCAPE);
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn switches the user out")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn switches the user out")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        SEND_IN_MESSAGE("Wynaut");
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn does not switch the user out if the battle ends")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if the battle ends")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn does not switch the user out if no replacements")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if no replacements")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn does not switch the user out if replacements fainted")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if replacements fainted")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn does not switch the user out if Wimp Out activates")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if Wimp Out activates")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WIMPOD) { MaxHP(200); HP(101); Ability(ABILITY_WIMP_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_WIMP_OUT);
        MESSAGE("2 sent out Wobbuffet!");
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn switches the user out if Wimp Out fails to activate")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn switches the user out if Wimp Out fails to activate")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WIMPOD) { MaxHP(200); HP(101); Ability(ABILITY_WIMP_OUT); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent);
        SEND_IN_MESSAGE("Wynaut");
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("U-turn switches the user out after Ice Face activates")
=======
SINGLE_BATTLE_TEST("Hit Escape: U-turn switches the user out after Ice Face activates")
>>>>>>> upstream/master
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_U_TURN].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_BEEDRILL);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_EISCUE) { Ability(ABILITY_ICE_FACE); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_ICE_FACE);
<<<<<<< HEAD
        MESSAGE("Foe Eiscue transformed!");
=======
        MESSAGE("The opposing Eiscue transformed!");
>>>>>>> upstream/master
        SEND_IN_MESSAGE("Wynaut");
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Held items are consumed immediately after a mon switched in by U-turn and Intimidate activates after it: player side")
=======
SINGLE_BATTLE_TEST("Hit Escape: Held items are consumed immediately after a mon switched in by U-turn and Intimidate activates after it: player side")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ELECTRIC_SEED); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("2 sent out Wynaut!");
        NOT ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Held items are consumed immediately after a mon switched in by U-turn and Intimidate activates after it: opposing side")
=======
SINGLE_BATTLE_TEST("Hit Escape: Held items are consumed immediately after a mon switched in by U-turn and Intimidate activates after it: opposing side")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE);  }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_ELECTRIC_SEED); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        MESSAGE("2 sent out Wynaut!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

<<<<<<< HEAD
SINGLE_BATTLE_TEST("Electric Seed boost is received by the right pokemon after U-turn and Intimidate")
=======
SINGLE_BATTLE_TEST("Hit Escape: Electric Seed boost is received by the right pokemon after U-turn and Intimidate")
>>>>>>> upstream/master
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ELECTRIC_SEED); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}
