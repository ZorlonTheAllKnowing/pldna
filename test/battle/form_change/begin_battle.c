#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Xerneas changes into Active Form upon battle start")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS_NEUTRAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_XERNEAS_ACTIVE);
    }
}

SINGLE_BATTLE_TEST("Zacian changes into its Crowned Form when holding the Rusted Sword upon battle start")
{
    u16 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_RUSTED_SWORD; }
    GIVEN {
<<<<<<< HEAD
        PLAYER(SPECIES_ZACIAN_HERO_OF_MANY_BATTLES) { Item(item); }
=======
        PLAYER(SPECIES_ZACIAN_HERO) { Item(item); }
>>>>>>> upstream/master
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        if (item == ITEM_NONE)
<<<<<<< HEAD
            EXPECT_EQ(player->species, SPECIES_ZACIAN_HERO_OF_MANY_BATTLES);
        else
            EXPECT_EQ(player->species, SPECIES_ZACIAN_CROWNED_SWORD);
=======
            EXPECT_EQ(player->species, SPECIES_ZACIAN_HERO);
        else
            EXPECT_EQ(player->species, SPECIES_ZACIAN_CROWNED);
>>>>>>> upstream/master
    }
}

SINGLE_BATTLE_TEST("Zacian's Iron Head becomes Behemoth Blade upon form change")
{
    GIVEN {
<<<<<<< HEAD
        PLAYER(SPECIES_ZACIAN_HERO_OF_MANY_BATTLES) { Item(ITEM_RUSTED_SWORD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
=======
        PLAYER(SPECIES_ZACIAN_HERO) { Item(ITEM_RUSTED_SWORD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
>>>>>>> upstream/master
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
<<<<<<< HEAD
        ASSUME(player->species == SPECIES_ZACIAN_CROWNED_SWORD); // Assumes form change worked.
=======
        ASSUME(player->species == SPECIES_ZACIAN_CROWNED); // Assumes form change worked.
>>>>>>> upstream/master
        EXPECT_EQ(player->moves[0], MOVE_BEHEMOTH_BLADE);
    }
}

SINGLE_BATTLE_TEST("Zamazenta changes into its Crowned Form when holding the Rusted Shield upon battle start")
{
    u16 item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_RUSTED_SHIELD; }
    GIVEN {
<<<<<<< HEAD
        PLAYER(SPECIES_ZAMAZENTA_HERO_OF_MANY_BATTLES) { Item(item); }
=======
        PLAYER(SPECIES_ZAMAZENTA_HERO) { Item(item); }
>>>>>>> upstream/master
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        if (item == ITEM_NONE)
<<<<<<< HEAD
            EXPECT_EQ(player->species, SPECIES_ZAMAZENTA_HERO_OF_MANY_BATTLES);
        else
            EXPECT_EQ(player->species, SPECIES_ZAMAZENTA_CROWNED_SHIELD);
=======
            EXPECT_EQ(player->species, SPECIES_ZAMAZENTA_HERO);
        else
            EXPECT_EQ(player->species, SPECIES_ZAMAZENTA_CROWNED);
>>>>>>> upstream/master
    }
}

SINGLE_BATTLE_TEST("Zamazenta's Iron Head becomes Behemoth Bash upon form change")
{
    GIVEN {
<<<<<<< HEAD
        PLAYER(SPECIES_ZAMAZENTA_HERO_OF_MANY_BATTLES) { Item(ITEM_RUSTED_SHIELD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
=======
        PLAYER(SPECIES_ZAMAZENTA_HERO) { Item(ITEM_RUSTED_SHIELD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
>>>>>>> upstream/master
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
<<<<<<< HEAD
        ASSUME(player->species == SPECIES_ZAMAZENTA_CROWNED_SHIELD); // Assumes form change worked.
=======
        ASSUME(player->species == SPECIES_ZAMAZENTA_CROWNED); // Assumes form change worked.
>>>>>>> upstream/master
        EXPECT_EQ(player->moves[0], MOVE_BEHEMOTH_BASH);
    }
}
