#include "battle_dynamax.h"
#include "battle_anim_scripts.h"
#include "constants/battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_z_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/contest.h"

// The Gen. 4+ contest data comes from urpg's contest movedex.

<<<<<<< HEAD
#if B_EXPANDED_MOVE_NAMES == TRUE
#define HANDLE_EXPANDED_MOVE_NAME(_name, ...) COMPOUND_STRING(DEFAULT(_name, __VA_ARGS__))
#else
#define HANDLE_EXPANDED_MOVE_NAME(_name, ...) COMPOUND_STRING(_name)
#endif

=======
>>>>>>> upstream/master
#if B_BINDING_TURNS >= GEN_5
#define BINDING_TURNS "4 or 5"
#else
#define BINDING_TURNS "2 to 5"
#endif

/* First arg is the charge turn string id, second arg depends on effect
EFFECT_SEMI_INVULNERABLE/EFFECT_SKY_DROP: semi-invulnerable STATUS3 to apply to battler
EFFECT_TWO_TURNS_ATTACK/EFFECT_SOLAR_BEAM: weather in which to skip charge turn */
#define TWO_TURN_ARG(stringid, ...) (stringid) __VA_OPT__(| ((__VA_ARGS__) << 16))

// Shared Move Description entries

const u8 gNotDoneYetDescription[] = _(
    "This move can't be used. Its\n"
    "effect is in development.");

static const u8 sNullDescription[] = _("");

static const u8 sMegaDrainDescription[] = _(
    "An attack that absorbs\n"
    "half the damage inflicted.");

static const u8 sHyperBeamDescription[] = _(
    "Powerful, but leaves the\n"
    "user immobile the next turn.");

static const u8 sRevengeDescription[] = _(
    "An attack that gains power\n"
    "if injured by the foe.");

static const u8 sPluckDescription[] = _(
    "Eats the foe's held Berry\n"
    "gaining its effect.");

static const u8 sHealingWishDescription[] = _(
    "The user faints to heal up\n"
    "the recipient.");

static const u8 sWringOutDescription[] = _(
    "The higher the foe's HP\n"
    "the more damage caused.");

static const u8 sUTurnDescription[] = _(
    "Does damage then switches\n"
    "out the user.");

static const u8 sStormThrowDescription[] = _(
    "This attack always results\n"
    "in a critical hit.");

static const u8 sCircleThrowDescription[] = _(
    "Knocks the foe away to end\n"
    "the battle.");

static const u8 sChipAwayDescription[] = _(
    "Strikes through the foe's\n"
    "stat changes.");

static const u8 sHeavySlamDescription[] = _(
    "Does more damage if the\n"
    "user outweighs the foe.");

static const u8 sPsyshockDescription[] = _(
    "Attacks with a psychic wave\n"
    "that does physical damage.");

static const u8 sLavaPlumeDescription[] = _(
    "Scarlet flames torch\n"
    "everything around the user.");

static const u8 sShadowForceDescription[] = _(
    "Vanishes on the first turn\n"
    "then strikes the next turn.");

static const u8 sFalseSwipeDescription[] = _(
    "An attack that leaves the\n"
    "foe with at least 1 HP.");

static const u8 sDrainingKissDescription[] = _(
    "An attack that absorbs over\n"
    "half the damage inflicted.");

static const u8 sCloseCombatDescription[] = _(
    "A strong attack but lowers\n"
    "the defensive stats.");

static const u8 sHyperspaceHoleDescription[] = _(
    "Uses a warp hole to attack.\n"
    "Can't be evaded.");

static const u8 sSuckerPunchDescription[] = _(
    "Strikes first if the foe\n"
    "is preparing an attack.");

static const u8 sFeintDescription[] = _(
    "An attack that hits foes\n"
    "using moves like Protect.");

const struct MoveInfo gMovesInfo[MOVES_COUNT_DYNAMAX] =
{
    [MOVE_NONE] =
    {
        .name = COMPOUND_STRING("-"),
        .description = COMPOUND_STRING(""),
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .sketchBanned = TRUE,
        .assistBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_NONE,
=======
        .battleAnimScript = gBattleAnimMove_None,
>>>>>>> upstream/master
    },

    [MOVE_POUND] =
    {
        .name = COMPOUND_STRING("Pound"),
        .description = COMPOUND_STRING(
            "Pounds the foe with\n"
            "forelegs or tail."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_POUND,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POUND,
=======
        .battleAnimScript = gBattleAnimMove_Pound,
>>>>>>> upstream/master
    },

    [MOVE_KARATE_CHOP] =
    {
        .name = COMPOUND_STRING("Karate Chop"),
        .description = COMPOUND_STRING(
            "A chopping attack with a\n"
            "high critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_KARATE_CHOP,
=======
        .battleAnimScript = gBattleAnimMove_KarateChop,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .name = COMPOUND_STRING("Double Slap"),
        .description = COMPOUND_STRING(
            "Repeatedly slaps the foe\n"
            "2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_SLAP,
=======
        .battleAnimScript = gBattleAnimMove_DoubleSlap,
>>>>>>> upstream/master
    },

    [MOVE_COMET_PUNCH] =
    {
        .name = COMPOUND_STRING("Comet Punch"),
        .description = COMPOUND_STRING(
            "Repeatedly punches the foe\n"
            "2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COMET_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_CometPunch,
>>>>>>> upstream/master
    },

    [MOVE_MEGA_PUNCH] =
    {
        .name = COMPOUND_STRING("Mega Punch"),
        .description = COMPOUND_STRING(
            "A strong punch thrown with\n"
            "incredible power."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_MEGA_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_MegaPunch,
>>>>>>> upstream/master
    },

    [MOVE_PAY_DAY] =
    {
        .name = COMPOUND_STRING("Pay Day"),
        .description = COMPOUND_STRING(
            "Throws coins at the foe.\n"
            "Money is recovered after."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PAY_DAY,
=======
        .battleAnimScript = gBattleAnimMove_PayDay,
>>>>>>> upstream/master
    },

    [MOVE_FIRE_PUNCH] =
    {
        .name = COMPOUND_STRING("Fire Punch"),
        .description = COMPOUND_STRING(
            "A fiery punch that may burn\n"
            "the foe."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_ICE_PUNCH, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRE_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_FirePunch,
>>>>>>> upstream/master
    },

    [MOVE_ICE_PUNCH] =
    {
        .name = COMPOUND_STRING("Ice Punch"),
        .description = COMPOUND_STRING(
            "An icy punch that may\n"
        #if B_USE_FROSTBITE == TRUE
            "leave the foe with frostbite."),
        #else
            "freeze the foe."),
        #endif
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_ICE_PUNCH,
        .contestComboMoves = {COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_THUNDER_PUNCH},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_IcePunch,
>>>>>>> upstream/master
    },

    [MOVE_THUNDER_PUNCH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ThunderPunch", "Thunder Punch"),
=======
        .name = COMPOUND_STRING("Thunder Punch"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "An electrified punch that\n"
            "may paralyze the foe."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_THUNDER_PUNCH,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDER_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_ThunderPunch,
>>>>>>> upstream/master
    },

    [MOVE_SCRATCH] =
    {
        .name = COMPOUND_STRING("Scratch"),
        .description = COMPOUND_STRING(
            "Scratches the foe with\n"
            "sharp claws."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCRATCH,
        .contestComboMoves = {COMBO_STARTER_LEER},
<<<<<<< HEAD
        .battleAnimScript = Move_SCRATCH,
=======
        .battleAnimScript = gBattleAnimMove_Scratch,
>>>>>>> upstream/master
    },

    [MOVE_VISE_GRIP] =
    {
        .name = COMPOUND_STRING("Vise Grip"),
        .description = COMPOUND_STRING(
            "Grips the foe with large and\n"
            "powerful pincers."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_VICE_GRIP,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_VISE_GRIP,
=======
        .battleAnimScript = gBattleAnimMove_ViseGrip,
>>>>>>> upstream/master
    },

    [MOVE_GUILLOTINE] =
    {
        .name = COMPOUND_STRING("Guillotine"),
        .description = COMPOUND_STRING(
            "A powerful pincer attack\n"
            "that may cause fainting."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
<<<<<<< HEAD
        .battleAnimScript = Move_GUILLOTINE,
=======
        .battleAnimScript = gBattleAnimMove_Guillotine,
>>>>>>> upstream/master
    },

    [MOVE_RAZOR_WIND] =
    {
        .name = COMPOUND_STRING("Razor Wind"),
        .description = COMPOUND_STRING(
            "A 2-turn move that strikes\n"
            "the foe on the 2nd turn."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .argument = TWO_TURN_ARG(STRINGID_PKMNWHIPPEDWHIRLWIND),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RAZOR_WIND,
=======
        .battleAnimScript = gBattleAnimMove_RazorWind,
>>>>>>> upstream/master
    },

    [MOVE_SWORDS_DANCE] =
    {
        .name = COMPOUND_STRING("Swords Dance"),
        .description = COMPOUND_STRING(
            "A fighting dance that\n"
            "sharply raises Attack."),
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SWORDS_DANCE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SWORDS_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_SwordsDance,
>>>>>>> upstream/master
    },

    [MOVE_CUT] =
    {
        .name = COMPOUND_STRING("Cut"),
        .description = COMPOUND_STRING(
            "Cuts the foe with sharp\n"
            "scythes, claws, etc."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_CUT,
=======
        .battleAnimScript = gBattleAnimMove_Cut,
>>>>>>> upstream/master
    },

    [MOVE_GUST] =
    {
        .name = COMPOUND_STRING("Gust"),
        .description = COMPOUND_STRING(
            "Strikes the foe with a gust\n"
            "of wind whipped up by wings."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .damagesAirborneDoubleDamage = TRUE,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GUST,
=======
        .battleAnimScript = gBattleAnimMove_Gust,
>>>>>>> upstream/master
    },

    [MOVE_WING_ATTACK] =
    {
        .name = COMPOUND_STRING("Wing Attack"),
        .description = COMPOUND_STRING(
            "Strikes the foe with wings\n"
            "spread wide."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WING_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_WingAttack,
>>>>>>> upstream/master
    },

    [MOVE_WHIRLWIND] =
    {
        .name = COMPOUND_STRING("Whirlwind"),
        .description = COMPOUND_STRING(
            "Blows away the foe with\n"
            "wind and ends the battle."),
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .windMove = TRUE,
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WHIRLWIND,
=======
        .battleAnimScript = gBattleAnimMove_Whirlwind,
>>>>>>> upstream/master
    },

    [MOVE_FLY] =
    {
        .name = COMPOUND_STRING("Fly"),
        .description = COMPOUND_STRING(
            "Flies up on the first turn,\n"
            "then strikes the next turn."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNFLEWHIGH, COMPRESS_BITS(STATUS3_ON_AIR)),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLY,
=======
        .battleAnimScript = gBattleAnimMove_Fly,
>>>>>>> upstream/master
    },

    [MOVE_BIND] =
    {
        .name = COMPOUND_STRING("Bind"),
        .description = COMPOUND_STRING(
            "Binds and squeezes the foe\n"
            "for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_VICE_GRIP},
<<<<<<< HEAD
        .battleAnimScript = Move_BIND,
=======
        .battleAnimScript = gBattleAnimMove_Bind,
>>>>>>> upstream/master
    },

    [MOVE_SLAM] =
    {
        .name = COMPOUND_STRING("Slam"),
        .description = COMPOUND_STRING(
            "Slams the foe with a long\n"
            "tail, vine, etc."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_POUND},
<<<<<<< HEAD
        .battleAnimScript = Move_SLAM,
=======
        .battleAnimScript = gBattleAnimMove_Slam,
>>>>>>> upstream/master
    },

    [MOVE_VINE_WHIP] =
    {
        .name = COMPOUND_STRING("Vine Whip"),
        .description = COMPOUND_STRING(
            "Strikes the foe with\n"
            "slender, whiplike vines."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 45 : 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_VINE_WHIP,
=======
        .battleAnimScript = gBattleAnimMove_VineWhip,
>>>>>>> upstream/master
    },

    [MOVE_STOMP] =
    {
        .name = COMPOUND_STRING("Stomp"),
        .description = COMPOUND_STRING(
            "Stomps the enemy with a big\n"
            "foot. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER},
<<<<<<< HEAD
        .battleAnimScript = Move_STOMP,
=======
        .battleAnimScript = gBattleAnimMove_Stomp,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_KICK] =
    {
        .name = COMPOUND_STRING("Double Kick"),
        .description = COMPOUND_STRING(
            "A double-kicking attack\n"
            "that strikes the foe twice."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_KICK,
=======
        .battleAnimScript = gBattleAnimMove_DoubleKick,
>>>>>>> upstream/master
    },

    [MOVE_MEGA_KICK] =
    {
        .name = COMPOUND_STRING("Mega Kick"),
        .description = COMPOUND_STRING(
            "An extremely powerful kick\n"
            "with intense force."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_MEGA_KICK,
=======
        .battleAnimScript = gBattleAnimMove_MegaKick,
>>>>>>> upstream/master
    },

    [MOVE_JUMP_KICK] =
    {
        .name = COMPOUND_STRING("Jump Kick"),
        .description = COMPOUND_STRING(
            "A strong jumping kick. May\n"
            "miss and hurt the kicker."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .power = 85,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_JUMP_KICK,
=======
        .battleAnimScript = gBattleAnimMove_JumpKick,
>>>>>>> upstream/master
    },

    [MOVE_ROLLING_KICK] =
    {
        .name = COMPOUND_STRING("Rolling Kick"),
        .description = COMPOUND_STRING(
            "A fast kick delivered from\n"
            "a rapid spin."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROLLING_KICK,
=======
        .battleAnimScript = gBattleAnimMove_RollingKick,
>>>>>>> upstream/master
    },

    [MOVE_SAND_ATTACK] =
    {
        .name = COMPOUND_STRING("Sand Attack"),
        .description = COMPOUND_STRING(
            "Reduces the foe's accuracy\n"
            "by hurling sand in its face."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SAND_ATTACK,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM},
<<<<<<< HEAD
        .battleAnimScript = Move_SAND_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_SandAttack,
>>>>>>> upstream/master
    },

    [MOVE_HEADBUTT] =
    {
        .name = COMPOUND_STRING("Headbutt"),
        .description = COMPOUND_STRING(
            "A ramming attack that may\n"
            "cause flinching."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_HEADBUTT,
=======
        .battleAnimScript = gBattleAnimMove_Headbutt,
>>>>>>> upstream/master
    },

    [MOVE_HORN_ATTACK] =
    {
        .name = COMPOUND_STRING("Horn Attack"),
        .description = COMPOUND_STRING(
            "Jabs the foe with sharp\n"
            "horns."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_HORN_ATTACK,
        .contestComboMoves = {COMBO_STARTER_LEER},
<<<<<<< HEAD
        .battleAnimScript = Move_HORN_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_HornAttack,
>>>>>>> upstream/master
    },

    [MOVE_FURY_ATTACK] =
    {
        .name = COMPOUND_STRING("Fury Attack"),
        .description = COMPOUND_STRING(
            "Jabs the foe 2 to 5 times\n"
            "with sharp horns, etc."),
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK},
<<<<<<< HEAD
        .battleAnimScript = Move_FURY_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_FuryAttack,
>>>>>>> upstream/master
    },

    [MOVE_HORN_DRILL] =
    {
        .name = COMPOUND_STRING("Horn Drill"),
        .description = COMPOUND_STRING(
            "A one-hit KO attack that\n"
            "uses a horn like a drill."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HORN_ATTACK},
<<<<<<< HEAD
        .battleAnimScript = Move_HORN_DRILL,
=======
        .battleAnimScript = gBattleAnimMove_HornDrill,
>>>>>>> upstream/master
    },

    [MOVE_TACKLE] =
    {
        .name = COMPOUND_STRING("Tackle"),
        .description = COMPOUND_STRING(
            "Charges the foe with a full-\n"
            "body tackle."),
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 50,
        #else
            .power = 35,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 95,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN, COMBO_STARTER_LEER},
<<<<<<< HEAD
        .battleAnimScript = Move_TACKLE,
=======
        .battleAnimScript = gBattleAnimMove_Tackle,
>>>>>>> upstream/master
    },

    [MOVE_BODY_SLAM] =
    {
        .name = COMPOUND_STRING("Body Slam"),
        .description = COMPOUND_STRING(
            "A full-body slam that may\n"
            "cause paralysis."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BODY_SLAM,
=======
        .battleAnimScript = gBattleAnimMove_BodySlam,
>>>>>>> upstream/master
    },

    [MOVE_WRAP] =
    {
        .name = COMPOUND_STRING("Wrap"),
        .description = COMPOUND_STRING(
            "Wraps and squeezes the foe\n"
            BINDING_TURNS" times with vines, etc."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WRAP,
=======
        .battleAnimScript = gBattleAnimMove_Wrap,
>>>>>>> upstream/master
    },

    [MOVE_TAKE_DOWN] =
    {
        .name = COMPOUND_STRING("Take Down"),
        .description = COMPOUND_STRING(
            "A reckless charge attack\n"
            "that also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .recoil = 25,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
<<<<<<< HEAD
        .battleAnimScript = Move_TAKE_DOWN,
=======
        .battleAnimScript = gBattleAnimMove_TakeDown,
>>>>>>> upstream/master
    },

    [MOVE_THRASH] =
    {
        .name = COMPOUND_STRING("Thrash"),
        .description = COMPOUND_STRING(
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAGE},
<<<<<<< HEAD
        .battleAnimScript = Move_THRASH,
=======
        .battleAnimScript = gBattleAnimMove_Thrash,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .name = COMPOUND_STRING("Double-Edge"),
        .description = COMPOUND_STRING(
            "A life-risking tackle that\n"
            "also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .recoil = 33,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_EDGE,
=======
        .battleAnimScript = gBattleAnimMove_DoubleEdge,
>>>>>>> upstream/master
    },

    [MOVE_TAIL_WHIP] =
    {
        .name = COMPOUND_STRING("Tail Whip"),
        .description = COMPOUND_STRING(
            "Wags the tail to lower the\n"
            "foe's Defense."),
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
<<<<<<< HEAD
        .battleAnimScript = Move_TAIL_WHIP,
=======
        .battleAnimScript = gBattleAnimMove_TailWhip,
>>>>>>> upstream/master
    },

    [MOVE_POISON_STING] =
    {
        .name = COMPOUND_STRING("Poison Sting"),
        .description = COMPOUND_STRING(
            "A toxic attack with barbs,\n"
            "etc., that may poison."),
        .effect = EFFECT_HIT,
        .power = 15,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POISON_STING,
=======
        .battleAnimScript = gBattleAnimMove_PoisonSting,
>>>>>>> upstream/master
    },

    [MOVE_TWINEEDLE] =
    {
        .name = COMPOUND_STRING("Twineedle"),
        .description = COMPOUND_STRING(
            "Stingers on the forelegs\n"
            "jab the foe twice."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .strikeCount = 2,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TWINEEDLE,
=======
        .battleAnimScript = gBattleAnimMove_Twineedle,
>>>>>>> upstream/master
    },

    [MOVE_PIN_MISSILE] =
    {
        .name = COMPOUND_STRING("Pin Missile"),
        .description = COMPOUND_STRING(
            "Sharp pins are fired to\n"
            "strike 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 14,
        .type = TYPE_BUG,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PIN_MISSILE,
=======
        .battleAnimScript = gBattleAnimMove_PinMissile,
>>>>>>> upstream/master
    },

    [MOVE_LEER] =
    {
        .name = COMPOUND_STRING("Leer"),
        .description = COMPOUND_STRING(
            "Frightens the foe with a\n"
            "leer to lower Defense."),
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_LEER,
        .contestComboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE},
<<<<<<< HEAD
        .battleAnimScript = Move_LEER,
=======
        .battleAnimScript = gBattleAnimMove_Leer,
>>>>>>> upstream/master
    },

    [MOVE_BITE] =
    {
        .name = COMPOUND_STRING("Bite"),
        .description = COMPOUND_STRING(
            "Bites with vicious fangs.\n"
            "May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE},
<<<<<<< HEAD
        .battleAnimScript = Move_BITE,
=======
        .battleAnimScript = gBattleAnimMove_Bite,
>>>>>>> upstream/master
    },

    [MOVE_GROWL] =
    {
        .name = COMPOUND_STRING("Growl"),
        .description = COMPOUND_STRING(
            "Growls cutely to reduce the\n"
            "foe's Attack."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
<<<<<<< HEAD
        .battleAnimScript = Move_GROWL,
=======
        .battleAnimScript = gBattleAnimMove_Growl,
>>>>>>> upstream/master
    },

    [MOVE_ROAR] =
    {
        .name = COMPOUND_STRING("Roar"),
        .description = COMPOUND_STRING(
            "Makes the foe flee to end\n"
            "the battle."),
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .soundMove = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROAR,
=======
        .battleAnimScript = gBattleAnimMove_Roar,
>>>>>>> upstream/master
    },

    [MOVE_SING] =
    {
        .name = COMPOUND_STRING("Sing"),
        .description = COMPOUND_STRING(
            "A soothing song lulls the\n"
            "foe into a deep slumber."),
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SING,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SING,
=======
        .battleAnimScript = gBattleAnimMove_Sing,
>>>>>>> upstream/master
    },

    [MOVE_SUPERSONIC] =
    {
        .name = COMPOUND_STRING("Supersonic"),
        .description = COMPOUND_STRING(
            "Emits bizarre sound waves\n"
            "that may confuse the foe."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SUPERSONIC,
=======
        .battleAnimScript = gBattleAnimMove_Supersonic,
>>>>>>> upstream/master
    },

    [MOVE_SONIC_BOOM] =
    {
        .name = COMPOUND_STRING("Sonic Boom"),
        .description = COMPOUND_STRING(
            "Launches shock waves that\n"
            "always inflict 20 HP damage."),
        .effect = EFFECT_FIXED_DAMAGE_ARG,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = 20,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SONIC_BOOM,
=======
        .battleAnimScript = gBattleAnimMove_SonicBoom,
>>>>>>> upstream/master
    },

    [MOVE_DISABLE] =
    {
        .name = COMPOUND_STRING("Disable"),
        .description = COMPOUND_STRING(
            "Psychically disables one of\n"
            "the foe's moves."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DISABLE,
=======
        .battleAnimScript = gBattleAnimMove_Disable,
>>>>>>> upstream/master
    },

    [MOVE_ACID] =
    {
        .name = COMPOUND_STRING("Acid"),
        .description = COMPOUND_STRING(
            "Sprays a hide-melting acid.\n"
        #if B_UPDATED_MOVE_DATA >= GEN_4
            "May lower Sp. Def."),
        #else
            "May lower Defense."),
        #endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_4 ? MOVE_EFFECT_SP_DEF_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ACID,
=======
        .battleAnimScript = gBattleAnimMove_Acid,
>>>>>>> upstream/master
    },

    [MOVE_EMBER] =
    {
        .name = COMPOUND_STRING("Ember"),
        .description = COMPOUND_STRING(
            "A weak fire attack that may\n"
            "inflict a burn."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_EMBER,
=======
        .battleAnimScript = gBattleAnimMove_Ember,
>>>>>>> upstream/master
    },

    [MOVE_FLAMETHROWER] =
    {
        .name = COMPOUND_STRING("Flamethrower"),
        .description = COMPOUND_STRING(
            "A powerful fire attack that\n"
            "may inflict a burn."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_FLAMETHROWER,
=======
        .battleAnimScript = gBattleAnimMove_Flamethrower,
>>>>>>> upstream/master
    },

    [MOVE_MIST] =
    {
        .name = COMPOUND_STRING("Mist"),
        .description = COMPOUND_STRING(
            "Creates a mist that stops\n"
            "reduction of abilities."),
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIST,
=======
        .battleAnimScript = gBattleAnimMove_Mist,
>>>>>>> upstream/master
    },

    [MOVE_WATER_GUN] =
    {
        .name = COMPOUND_STRING("Water Gun"),
        .description = COMPOUND_STRING(
            "Squirts water to attack\n"
            "the foe."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT},
<<<<<<< HEAD
        .battleAnimScript = Move_WATER_GUN,
=======
        .battleAnimScript = gBattleAnimMove_WaterGun,
>>>>>>> upstream/master
    },

    [MOVE_HYDRO_PUMP] =
    {
        .name = COMPOUND_STRING("Hydro Pump"),
        .description = COMPOUND_STRING(
            "Blasts water at high power\n"
            "to strike the foe."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_HYDRO_PUMP,
=======
        .battleAnimScript = gBattleAnimMove_HydroPump,
>>>>>>> upstream/master
    },

    [MOVE_SURF] =
    {
        .name = COMPOUND_STRING("Surf"),
        .description = COMPOUND_STRING(
            "Creates a huge wave, then\n"
            "crashes it down on the foe."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? MOVE_TARGET_FOES_AND_ALLY : MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesUnderwater = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SURF,
        .contestComboMoves = {COMBO_STARTER_DIVE, COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_SURF,
=======
        .battleAnimScript = gBattleAnimMove_Surf,
>>>>>>> upstream/master
    },

    [MOVE_ICE_BEAM] =
    {
        .name = COMPOUND_STRING("Ice Beam"),
        .description = COMPOUND_STRING(
            "Blasts the foe with an icy\n"
        #if B_USE_FROSTBITE == TRUE
            "beam. May cause frostbite."),
        #else
            "beam that may freeze it."),
        #endif
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
<<<<<<< HEAD
            // The following effect is also relevant in battle_pike.c
=======
            // The following effect is also relevant in battle_Pike.c
>>>>>>> upstream/master
            // If you cherry-pick this to use something other than the config, make sure to update it there too
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_IceBeam,
>>>>>>> upstream/master
    },

    [MOVE_BLIZZARD] =
    {
        .name = COMPOUND_STRING("Blizzard"),
        .description = COMPOUND_STRING(
            "Hits the foe with an icy\n"
        #if B_USE_FROSTBITE == TRUE
            "storm. May cause frostbite."),
        #else
            "storm that may freeze it."),
        #endif
        .effect = B_BLIZZARD_HAIL >= GEN_4 ? EFFECT_BLIZZARD : EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ICE,
        .accuracy = 70,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_POWDER_SNOW},
<<<<<<< HEAD
        .battleAnimScript = Move_BLIZZARD,
=======
        .battleAnimScript = gBattleAnimMove_Blizzard,
>>>>>>> upstream/master
    },

    [MOVE_PSYBEAM] =
    {
        .name = COMPOUND_STRING("Psybeam"),
        .description = COMPOUND_STRING(
            "Fires a peculiar ray that\n"
            "may confuse the foe."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYBEAM,
=======
        .battleAnimScript = gBattleAnimMove_Psybeam,
>>>>>>> upstream/master
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .name = COMPOUND_STRING("Bubble Beam"),
        .description = COMPOUND_STRING(
            "Forcefully sprays bubbles\n"
            "that may lower Speed."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_BUBBLE_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_BubbleBeam,
>>>>>>> upstream/master
    },

    [MOVE_AURORA_BEAM] =
    {
        .name = COMPOUND_STRING("Aurora Beam"),
        .description = COMPOUND_STRING(
            "Fires a rainbow-colored\n"
            "beam that may lower Attack."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_AURORA_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_AuroraBeam,
>>>>>>> upstream/master
    },

    [MOVE_HYPER_BEAM] =
    {
        .name = COMPOUND_STRING("Hyper Beam"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HYPER_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_HyperBeam,
>>>>>>> upstream/master
    },

    [MOVE_PECK] =
    {
        .name = COMPOUND_STRING("Peck"),
        .description = COMPOUND_STRING(
            "Attacks the foe with a\n"
            "jabbing beak, etc."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PECK,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PECK,
=======
        .battleAnimScript = gBattleAnimMove_Peck,
>>>>>>> upstream/master
    },

    [MOVE_DRILL_PECK] =
    {
        .name = COMPOUND_STRING("Drill Peck"),
        .description = COMPOUND_STRING(
            "A corkscrewing attack with\n"
            "the beak acting as a drill."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PECK},
<<<<<<< HEAD
        .battleAnimScript = Move_DRILL_PECK,
=======
        .battleAnimScript = gBattleAnimMove_DrillPeck,
>>>>>>> upstream/master
    },

    [MOVE_SUBMISSION] =
    {
        .name = COMPOUND_STRING("Submission"),
        .description = COMPOUND_STRING(
            "A reckless body slam that\n"
            "also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 25,
        .recoil = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_SUBMISSION,
=======
        .battleAnimScript = gBattleAnimMove_Submission,
>>>>>>> upstream/master
    },

    [MOVE_LOW_KICK] =
    {
        .name = COMPOUND_STRING("Low Kick"),
        .description = COMPOUND_STRING(
            "A kick that inflicts more\n"
            "damage on heavier foes."),
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LOW_KICK,
=======
        .battleAnimScript = gBattleAnimMove_LowKick,
>>>>>>> upstream/master
    },

    [MOVE_COUNTER] =
    {
        .name = COMPOUND_STRING("Counter"),
        .description = COMPOUND_STRING(
            "Retaliates any physical hit\n"
            "with double the power."),
        .effect = EFFECT_COUNTER,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .meFirstBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT},
<<<<<<< HEAD
        .battleAnimScript = Move_COUNTER,
=======
        .battleAnimScript = gBattleAnimMove_Counter,
>>>>>>> upstream/master
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .name = COMPOUND_STRING("Seismic Toss"),
        .description = COMPOUND_STRING(
            "Inflicts damage identical\n"
            "to the user's level."),
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT},
<<<<<<< HEAD
        .battleAnimScript = Move_SEISMIC_TOSS,
=======
        .battleAnimScript = gBattleAnimMove_SeismicToss,
>>>>>>> upstream/master
    },

    [MOVE_STRENGTH] =
    {
        .name = COMPOUND_STRING("Strength"),
        .description = COMPOUND_STRING(
            "Builds enormous power,\n"
            "then slams the foe."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STRENGTH,
=======
        .battleAnimScript = gBattleAnimMove_Strength,
>>>>>>> upstream/master
    },

    [MOVE_ABSORB] =
    {
        .name = COMPOUND_STRING("Absorb"),
        .description = COMPOUND_STRING(
            "An attack that absorbs\n"
            "half the damage inflicted."),
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 25 : 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_ABSORB,
=======
        .battleAnimScript = gBattleAnimMove_Absorb,
>>>>>>> upstream/master
    },

    [MOVE_MEGA_DRAIN] =
    {
        .name = COMPOUND_STRING("Mega Drain"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 15 : 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .zMove = { .powerOverride = 120 },
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_MEGA_DRAIN,
=======
        .battleAnimScript = gBattleAnimMove_MegaDrain,
>>>>>>> upstream/master
    },

    [MOVE_LEECH_SEED] =
    {
        .name = COMPOUND_STRING("Leech Seed"),
        .description = COMPOUND_STRING(
            "Plants a seed on the foe to\n"
            "steal HP on every turn."),
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LEECH_SEED,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_WORRY_SEED},
<<<<<<< HEAD
        .battleAnimScript = Move_LEECH_SEED,
=======
        .battleAnimScript = gBattleAnimMove_LeechSeed,
>>>>>>> upstream/master
    },

    [MOVE_GROWTH] =
    {
        .name = COMPOUND_STRING("Growth"),
        .description = COMPOUND_STRING(
        #if B_GROWTH_STAT_RAISE >= GEN_5
            "Forces the body to grow,\n"
            "raising Attack and Sp. Atk."),
        #else
            "Forces the body to grow\n"
            "and heightens Sp. Atk."),
        #endif
        .effect = B_GROWTH_STAT_RAISE >= GEN_5 ? EFFECT_GROWTH : EFFECT_SPECIAL_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_GROWTH,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GROWTH,
=======
        .battleAnimScript = gBattleAnimMove_Growth,
>>>>>>> upstream/master
    },

    [MOVE_RAZOR_LEAF] =
    {
        .name = COMPOUND_STRING("Razor Leaf"),
        .description = COMPOUND_STRING(
            "Cuts the enemy with leaves.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .criticalHitStage = 1,
        .pp = 25,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_RAZOR_LEAF,
=======
        .battleAnimScript = gBattleAnimMove_RazorLeaf,
>>>>>>> upstream/master
    },

    [MOVE_SOLAR_BEAM] =
    {
        .name = COMPOUND_STRING("Solar Beam"),
        .description = COMPOUND_STRING(
            "Absorbs light in one turn,\n"
            "then attacks next turn."),
        .effect = EFFECT_SOLAR_BEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNTOOKSUNLIGHT, B_WEATHER_SUN),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_SOLAR_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_SolarBeam,
>>>>>>> upstream/master
    },

    [MOVE_POISON_POWDER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PoisonPowder", "Poison Powder"),
=======
        .name = COMPOUND_STRING("Poison Powder"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Scatters a toxic powder\n"
            "that may poison the foe."),
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
<<<<<<< HEAD
        .battleAnimScript = Move_POISON_POWDER,
=======
        .battleAnimScript = gBattleAnimMove_PoisonPowder,
>>>>>>> upstream/master
    },

    [MOVE_STUN_SPORE] =
    {
        .name = COMPOUND_STRING("Stun Spore"),
        .description = COMPOUND_STRING(
            "Scatters a powder that may\n"
            "paralyze the foe."),
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
<<<<<<< HEAD
        .battleAnimScript = Move_STUN_SPORE,
=======
        .battleAnimScript = gBattleAnimMove_StunSpore,
>>>>>>> upstream/master
    },

    [MOVE_SLEEP_POWDER] =
    {
        .name = COMPOUND_STRING("Sleep Powder"),
        .description = COMPOUND_STRING(
            "Scatters a powder that may\n"
            "cause the foe to sleep."),
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWEET_SCENT},
<<<<<<< HEAD
        .battleAnimScript = Move_SLEEP_POWDER,
=======
        .battleAnimScript = gBattleAnimMove_SleepPowder,
>>>>>>> upstream/master
    },

    [MOVE_PETAL_DANCE] =
    {
        .name = COMPOUND_STRING("Petal Dance"),
        .description = COMPOUND_STRING(
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_PETAL_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_PetalDance,
>>>>>>> upstream/master
    },

    [MOVE_STRING_SHOT] =
    {
        .name = COMPOUND_STRING("String Shot"),
        .description = COMPOUND_STRING(
            "Binds the foe with string\n"
            "to reduce its Speed."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_SPEED_DOWN_2 : EFFECT_SPEED_DOWN,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_STRING_SHOT,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STRING_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_StringShot,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_RAGE] =
    {
        .name = COMPOUND_STRING("Dragon Rage"),
        .description = COMPOUND_STRING(
            "Launches shock waves that\n"
            "always inflict 40 HP damage."),
        .effect = EFFECT_FIXED_DAMAGE_ARG,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_4) || (B_UPDATED_MOVE_FLAGS < GEN_3),
        .argument = 40,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RAGE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_RAGE,
=======
        .battleAnimScript = gBattleAnimMove_DragonRage,
>>>>>>> upstream/master
    },

    [MOVE_FIRE_SPIN] =
    {
        .name = COMPOUND_STRING("Fire Spin"),
        .description = COMPOUND_STRING(
            "Traps the foe in a ring of\n"
            "fire for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRE_SPIN,
=======
        .battleAnimScript = gBattleAnimMove_FireSpin,
>>>>>>> upstream/master
    },

    [MOVE_THUNDER_SHOCK] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ThunderShock", "Thunder Shock"),
=======
        .name = COMPOUND_STRING("Thunder Shock"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "An electrical attack that\n"
            "may paralyze the foe."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDER_SHOCK,
=======
        .battleAnimScript = gBattleAnimMove_ThunderShock,
>>>>>>> upstream/master
    },

    [MOVE_THUNDERBOLT] =
    {
        .name = COMPOUND_STRING("Thunderbolt"),
        .description = COMPOUND_STRING(
            "A strong electrical attack\n"
            "that may paralyze the foe."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDERBOLT,
=======
        .battleAnimScript = gBattleAnimMove_Thunderbolt,
>>>>>>> upstream/master
    },

    [MOVE_THUNDER_WAVE] =
    {
        .name = COMPOUND_STRING("Thunder Wave"),
        .description = COMPOUND_STRING(
            "A weak jolt of electricity\n"
            "that paralyzes the foe."),
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 90 : 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDER_WAVE,
=======
        .battleAnimScript = gBattleAnimMove_ThunderWave,
>>>>>>> upstream/master
    },

    [MOVE_THUNDER] =
    {
        .name = COMPOUND_STRING("Thunder"),
        .description = COMPOUND_STRING(
            "A lightning attack that may\n"
            "cause paralysis."),
        .effect = EFFECT_THUNDER,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesAirborne = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDER,
=======
        .battleAnimScript = gBattleAnimMove_Thunder,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_THROW] =
    {
        .name = COMPOUND_STRING("Rock Throw"),
        .description = COMPOUND_STRING(
            "Throws small rocks to\n"
            "strike the foe."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ROCK_THROW,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_THROW,
=======
        .battleAnimScript = gBattleAnimMove_RockThrow,
>>>>>>> upstream/master
    },

    [MOVE_EARTHQUAKE] =
    {
        .name = COMPOUND_STRING("Earthquake"),
        .description = COMPOUND_STRING(
            "A powerful quake, but has\n"
            "no effect on flying foes."),
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_EARTHQUAKE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EARTHQUAKE,
=======
        .battleAnimScript = gBattleAnimMove_Earthquake,
>>>>>>> upstream/master
    },

    [MOVE_FISSURE] =
    {
        .name = COMPOUND_STRING("Fissure"),
        .description = COMPOUND_STRING(
            "A one-hit KO move that\n"
            "drops the foe in a fissure."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 30,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE},
<<<<<<< HEAD
        .battleAnimScript = Move_FISSURE,
=======
        .battleAnimScript = gBattleAnimMove_Fissure,
>>>>>>> upstream/master
    },

    [MOVE_DIG] =
    {
        .name = COMPOUND_STRING("Dig"),
        .description = COMPOUND_STRING(
            "Digs underground the first\n"
            "turn and strikes next turn."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 80 : 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .skyBattleBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNDUGHOLE, COMPRESS_BITS(STATUS3_UNDERGROUND)),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DIG,
=======
        .battleAnimScript = gBattleAnimMove_Dig,
>>>>>>> upstream/master
    },

    [MOVE_TOXIC] =
    {
        .name = COMPOUND_STRING("Toxic"),
        .description = COMPOUND_STRING(
            "Poisons the foe with an\n"
            "intensifying toxin."),
        .effect = EFFECT_TOXIC,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TOXIC,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TOXIC,
=======
        .battleAnimScript = gBattleAnimMove_Toxic,
>>>>>>> upstream/master
    },

    [MOVE_CONFUSION] =
    {
        .name = COMPOUND_STRING("Confusion"),
        .description = COMPOUND_STRING(
            "A psychic attack that may\n"
            "cause confusion."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CONFUSION,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
<<<<<<< HEAD
        .battleAnimScript = Move_CONFUSION,
=======
        .battleAnimScript = gBattleAnimMove_Confusion,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHIC] =
    {
        .name = COMPOUND_STRING("Psychic"),
        .description = COMPOUND_STRING(
            "A powerful psychic attack\n"
            "that may lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHIC,
=======
        .battleAnimScript = gBattleAnimMove_Psychic,
>>>>>>> upstream/master
    },

    [MOVE_HYPNOSIS] =
    {
        .name = COMPOUND_STRING("Hypnosis"),
        .description = COMPOUND_STRING(
            "A hypnotizing move that\n"
            "may induce sleep."),
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPNOSIS,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HYPNOSIS,
=======
        .battleAnimScript = gBattleAnimMove_Hypnosis,
>>>>>>> upstream/master
    },

    [MOVE_MEDITATE] =
    {
        .name = COMPOUND_STRING("Meditate"),
        .description = COMPOUND_STRING(
            "Meditates in a peaceful\n"
            "fashion to raise Attack."),
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_MEDITATE,
=======
        .battleAnimScript = gBattleAnimMove_Meditate,
>>>>>>> upstream/master
    },

    [MOVE_AGILITY] =
    {
        .name = COMPOUND_STRING("Agility"),
        .description = COMPOUND_STRING(
            "Relaxes the body to sharply\n"
            "boost Speed."),
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
<<<<<<< HEAD
        .battleAnimScript = Move_AGILITY,
=======
        .battleAnimScript = gBattleAnimMove_Agility,
>>>>>>> upstream/master
    },

    [MOVE_QUICK_ATTACK] =
    {
        .name = COMPOUND_STRING("Quick Attack"),
        .description = COMPOUND_STRING(
            "An extremely fast attack\n"
            "that always strikes first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DOUBLE_TEAM},
<<<<<<< HEAD
        .battleAnimScript = Move_QUICK_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_QuickAttack,
>>>>>>> upstream/master
    },

    [MOVE_RAGE] =
    {
        .name = COMPOUND_STRING("Rage"),
        .description = COMPOUND_STRING(
            "Raises the user's Attack\n"
            "every time it is hit."),
        .effect = EFFECT_RAGE,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_RAGE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RAGE,
=======
        .battleAnimScript = gBattleAnimMove_Rage,
>>>>>>> upstream/master
    },

    [MOVE_TELEPORT] =
    {
        .name = COMPOUND_STRING("Teleport"),
        .description = COMPOUND_STRING(
            "A psychic move for fleeing\n"
            "from battle instantly."),
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = -6,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
<<<<<<< HEAD
        .battleAnimScript = Move_TELEPORT,
=======
        .battleAnimScript = gBattleAnimMove_Teleport,
>>>>>>> upstream/master
    },

    [MOVE_NIGHT_SHADE] =
    {
        .name = COMPOUND_STRING("Night Shade"),
        .description = COMPOUND_STRING(
            "Inflicts damage identical\n"
            "to the user's level."),
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NIGHT_SHADE,
=======
        .battleAnimScript = gBattleAnimMove_NightShade,
>>>>>>> upstream/master
    },

    [MOVE_MIMIC] =
    {
        .name = COMPOUND_STRING("Mimic"),
        .description = COMPOUND_STRING(
            "Copies a move used by the\n"
            "foe during one battle."),
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresSubstitute = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_2,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIMIC,
=======
        .battleAnimScript = gBattleAnimMove_Mimic,
>>>>>>> upstream/master
    },

    [MOVE_SCREECH] =
    {
        .name = COMPOUND_STRING("Screech"),
        .description = COMPOUND_STRING(
            "Emits a screech to sharply\n"
            "reduce the foe's Defense."),
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SCREECH,
=======
        .battleAnimScript = gBattleAnimMove_Screech,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .name = COMPOUND_STRING("Double Team"),
        .description = COMPOUND_STRING(
            "Creates illusory copies to\n"
            "raise evasiveness."),
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DOUBLE_TEAM,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_TEAM,
=======
        .battleAnimScript = gBattleAnimMove_DoubleTeam,
>>>>>>> upstream/master
    },

    [MOVE_RECOVER] =
    {
        .name = COMPOUND_STRING("Recover"),
        .description = COMPOUND_STRING(
            "Recovers up to half the\n"
            "user's maximum HP."),
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RECOVER,
=======
        .battleAnimScript = gBattleAnimMove_Recover,
>>>>>>> upstream/master
    },

    [MOVE_HARDEN] =
    {
        .name = COMPOUND_STRING("Harden"),
        .description = COMPOUND_STRING(
            "Stiffens the body's \n"
            "muscles to raise Defense."),
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HARDEN,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HARDEN,
=======
        .battleAnimScript = gBattleAnimMove_Harden,
>>>>>>> upstream/master
    },

    [MOVE_MINIMIZE] =
    {
        .name = COMPOUND_STRING("Minimize"),
        .description = COMPOUND_STRING(
            "Minimizes the user's size\n"
            "to raise evasiveness."),
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MINIMIZE,
=======
        .battleAnimScript = gBattleAnimMove_Minimize,
>>>>>>> upstream/master
    },

    [MOVE_SMOKESCREEN] =
    {
        .name = COMPOUND_STRING("Smokescreen"),
        .description = COMPOUND_STRING(
            "Lowers the foe's accuracy\n"
            "using smoke, ink, etc."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SMOG},
<<<<<<< HEAD
        .battleAnimScript = Move_SMOKESCREEN,
=======
        .battleAnimScript = gBattleAnimMove_Smokescreen,
>>>>>>> upstream/master
    },

    [MOVE_CONFUSE_RAY] =
    {
        .name = COMPOUND_STRING("Confuse Ray"),
        .description = COMPOUND_STRING(
            "A sinister ray that\n"
            "confuses the foe."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CONFUSE_RAY,
=======
        .battleAnimScript = gBattleAnimMove_ConfuseRay,
>>>>>>> upstream/master
    },

    [MOVE_WITHDRAW] =
    {
        .name = COMPOUND_STRING("Withdraw"),
        .description = COMPOUND_STRING(
            "Withdraws the body into its\n"
            "hard shell to raise Defense."),
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_WITHDRAW,
=======
        .battleAnimScript = gBattleAnimMove_Withdraw,
>>>>>>> upstream/master
    },

    [MOVE_DEFENSE_CURL] =
    {
        .name = COMPOUND_STRING("Defense Curl"),
        .description = COMPOUND_STRING(
            "Curls up to conceal weak\n"
            "spots and raise Defense."),
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_DEFENSE_CURL,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DEFENSE_CURL,
=======
        .battleAnimScript = gBattleAnimMove_DefenseCurl,
>>>>>>> upstream/master
    },

    [MOVE_BARRIER] =
    {
        .name = COMPOUND_STRING("Barrier"),
        .description = COMPOUND_STRING(
            "Creates a barrier that\n"
            "sharply raises Defense."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BARRIER,
=======
        .battleAnimScript = gBattleAnimMove_Barrier,
>>>>>>> upstream/master
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .name = COMPOUND_STRING("Light Screen"),
        .description = COMPOUND_STRING(
            "Creates a wall of light that\n"
            "lowers Sp. Atk damage."),
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_LIGHT_SCREEN,
=======
        .battleAnimScript = gBattleAnimMove_LightScreen,
>>>>>>> upstream/master
    },

    [MOVE_HAZE] =
    {
        .name = COMPOUND_STRING("Haze"),
        .description = COMPOUND_STRING(
            "Creates a black haze that\n"
            "eliminates all stat changes."),
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_HAZE,
=======
        .battleAnimScript = gBattleAnimMove_Haze,
>>>>>>> upstream/master
    },

    [MOVE_REFLECT] =
    {
        .name = COMPOUND_STRING("Reflect"),
        .description = COMPOUND_STRING(
            "Creates a wall of light that\n"
            "weakens physical attacks."),
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_REFLECT,
=======
        .battleAnimScript = gBattleAnimMove_Reflect,
>>>>>>> upstream/master
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .name = COMPOUND_STRING("Focus Energy"),
        .description = COMPOUND_STRING(
            "Focuses power to raise the\n"
            "critical-hit ratio."),
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .argument = STATUS2_FOCUS_ENERGY,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_FOCUS_ENERGY,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FOCUS_ENERGY,
=======
        .battleAnimScript = gBattleAnimMove_FocusEnergy,
>>>>>>> upstream/master
    },

    [MOVE_BIDE] =
    {
        .name = COMPOUND_STRING("Bide"),
        .description = COMPOUND_STRING(
            "Endures attack for 2\n"
            "turns to retaliate double."),
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_4 ? 1 : 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BIDE,
=======
        .battleAnimScript = gBattleAnimMove_Bide,
>>>>>>> upstream/master
    },

    [MOVE_METRONOME] =
    {
        .name = COMPOUND_STRING("Metronome"),
        .description = COMPOUND_STRING(
            "Waggles a finger to use any\n"
            "Pokémon move at random."),
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_METRONOME,
=======
        .battleAnimScript = gBattleAnimMove_Metronome,
>>>>>>> upstream/master
    },

    [MOVE_MIRROR_MOVE] =
    {
        .name = COMPOUND_STRING("Mirror Move"),
        .description = COMPOUND_STRING(
            "Counters the foe's attack\n"
            "with the same move."),
        .effect = EFFECT_MIRROR_MOVE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_2 },
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_3,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIRROR_MOVE,
=======
        .battleAnimScript = gBattleAnimMove_MirrorMove,
>>>>>>> upstream/master
    },

    [MOVE_SELF_DESTRUCT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SelfDestruct", "Self-Destruct"),
=======
        .name = COMPOUND_STRING("Self-Destruct"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Inflicts severe damage but\n"
            "makes the user faint."),
        .effect = EFFECT_EXPLOSION,
        .power = 200,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SELF_DESTRUCT,
=======
        .battleAnimScript = gBattleAnimMove_SelfDestruct,
>>>>>>> upstream/master
    },

    [MOVE_EGG_BOMB] =
    {
        .name = COMPOUND_STRING("Egg Bomb"),
        .description = COMPOUND_STRING(
            "An egg is forcibly hurled at\n"
            "the foe."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SOFT_BOILED},
<<<<<<< HEAD
        .battleAnimScript = Move_EGG_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_EggBomb,
>>>>>>> upstream/master
    },

    [MOVE_LICK] =
    {
        .name = COMPOUND_STRING("Lick"),
        .description = COMPOUND_STRING(
            "Licks with a long tongue to\n"
            "injure. May also paralyze."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LICK,
=======
        .battleAnimScript = gBattleAnimMove_Lick,
>>>>>>> upstream/master
    },

    [MOVE_SMOG] =
    {
        .name = COMPOUND_STRING("Smog"),
        .description = COMPOUND_STRING(
            "An exhaust-gas attack\n"
            "that may also poison."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 30 : 20,
        .type = TYPE_POISON,
        .accuracy = 70,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SMOG,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SMOG,
=======
        .battleAnimScript = gBattleAnimMove_Smog,
>>>>>>> upstream/master
    },

    [MOVE_SLUDGE] =
    {
        .name = COMPOUND_STRING("Sludge"),
        .description = COMPOUND_STRING(
            "Sludge is hurled to inflict\n"
            "damage. May also poison."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE,
        .contestComboMoves = {COMBO_STARTER_SLUDGE_BOMB},
<<<<<<< HEAD
        .battleAnimScript = Move_SLUDGE,
=======
        .battleAnimScript = gBattleAnimMove_Sludge,
>>>>>>> upstream/master
    },

    [MOVE_BONE_CLUB] =
    {
        .name = COMPOUND_STRING("Bone Club"),
        .description = COMPOUND_STRING(
            "Clubs the foe with a bone.\n"
            "May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_CLUB,
        .contestComboMoves = {COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
<<<<<<< HEAD
        .battleAnimScript = Move_BONE_CLUB,
=======
        .battleAnimScript = gBattleAnimMove_BoneClub,
>>>>>>> upstream/master
    },

    [MOVE_FIRE_BLAST] =
    {
        .name = COMPOUND_STRING("Fire Blast"),
        .description = COMPOUND_STRING(
            "Incinerates everything it\n"
            "strikes. May cause a burn."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRE_BLAST,
=======
        .battleAnimScript = gBattleAnimMove_FireBlast,
>>>>>>> upstream/master
    },

    [MOVE_WATERFALL] =
    {
        .name = COMPOUND_STRING("Waterfall"),
        .description = COMPOUND_STRING(
            "Charges the foe with speed\n"
            "to climb waterfalls."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_FLINCH,
                .chance = 20,
            }),
        #endif
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_WATERFALL,
=======
        .battleAnimScript = gBattleAnimMove_Waterfall,
>>>>>>> upstream/master
    },

    [MOVE_CLAMP] =
    {
        .name = COMPOUND_STRING("Clamp"),
        .description = COMPOUND_STRING(
            "Traps and squeezes the\n"
            "foe for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 75,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 15 : 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_CLAMP,
=======
        .battleAnimScript = gBattleAnimMove_Clamp,
>>>>>>> upstream/master
    },

    [MOVE_SWIFT] =
    {
        .name = COMPOUND_STRING("Swift"),
        .description = COMPOUND_STRING(
            "Sprays star-shaped rays\n"
            "that never miss."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SWIFT,
=======
        .battleAnimScript = gBattleAnimMove_Swift,
>>>>>>> upstream/master
    },

    [MOVE_SKULL_BASH] =
    {
        .name = COMPOUND_STRING("Skull Bash"),
        .description = COMPOUND_STRING(
            "Tucks in the head, then\n"
            "attacks on the next turn."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNLOWEREDHEAD),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SKULL_BASH,
=======
        .battleAnimScript = gBattleAnimMove_SkullBash,
>>>>>>> upstream/master
    },

    [MOVE_SPIKE_CANNON] =
    {
        .name = COMPOUND_STRING("Spike Cannon"),
        .description = COMPOUND_STRING(
            "Launches sharp spikes that\n"
            "strike 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIKE_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_SpikeCannon,
>>>>>>> upstream/master
    },

    [MOVE_CONSTRICT] =
    {
        .name = COMPOUND_STRING("Constrict"),
        .description = COMPOUND_STRING(
            "Constricts to inflict pain.\n"
            "May lower Speed."),
        .effect = EFFECT_HIT,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CONSTRICT,
=======
        .battleAnimScript = gBattleAnimMove_Constrict,
>>>>>>> upstream/master
    },

    [MOVE_AMNESIA] =
    {
        .name = COMPOUND_STRING("Amnesia"),
        .description = COMPOUND_STRING(
            "Forgets about something\n"
            "and sharply raises Sp. Def."),
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AMNESIA,
=======
        .battleAnimScript = gBattleAnimMove_Amnesia,
>>>>>>> upstream/master
    },

    [MOVE_KINESIS] =
    {
        .name = COMPOUND_STRING("Kinesis"),
        .description = COMPOUND_STRING(
            "Distracts the foe.\n"
            "May lower accuracy."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_KINESIS,
        .contestComboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_PSYCHIC},
<<<<<<< HEAD
        .battleAnimScript = Move_KINESIS,
=======
        .battleAnimScript = gBattleAnimMove_Kinesis,
>>>>>>> upstream/master
    },

    [MOVE_SOFT_BOILED] =
    {
        .name = COMPOUND_STRING("Soft-Boiled"),
        .description = COMPOUND_STRING(
            "Recovers up to half the\n"
            "user's maximum HP."),
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SOFT_BOILED,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SOFT_BOILED,
=======
        .battleAnimScript = gBattleAnimMove_SoftBoiled,
>>>>>>> upstream/master
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("HighJumpKick", "High Jump Kick"),
=======
        .name = COMPOUND_STRING("High Jump Kick"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A jumping knee kick. If it\n"
            "misses, the user is hurt."),
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 130,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 100,
        #else
            .power = 85,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_HIGH_JUMP_KICK,
=======
        .battleAnimScript = gBattleAnimMove_HighJumpKick,
>>>>>>> upstream/master
    },

    [MOVE_GLARE] =
    {
        .name = COMPOUND_STRING("Glare"),
        .description = COMPOUND_STRING(
            "Intimidates and frightens\n"
            "the foe into paralysis."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LEER},
<<<<<<< HEAD
        .battleAnimScript = Move_GLARE,
=======
        .battleAnimScript = gBattleAnimMove_Glare,
>>>>>>> upstream/master
    },

    [MOVE_DREAM_EATER] =
    {
        .name = COMPOUND_STRING("Dream Eater"),
        .description = COMPOUND_STRING(
            "Takes one half the damage\n"
            "inflicted on a sleeping foe."),
        .effect = EFFECT_DREAM_EATER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_HYPNOSIS},
<<<<<<< HEAD
        .battleAnimScript = Move_DREAM_EATER,
=======
        .battleAnimScript = gBattleAnimMove_DreamEater,
>>>>>>> upstream/master
    },

    [MOVE_POISON_GAS] =
    {
        .name = COMPOUND_STRING("Poison Gas"),
        .description = COMPOUND_STRING(
            "Envelops the foe in a toxic\n"
            "gas that may poison."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 90,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 80,
        #else
            .accuracy = 55,
        #endif
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? MOVE_TARGET_BOTH : MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POISON_GAS,
=======
        .battleAnimScript = gBattleAnimMove_PoisonGas,
>>>>>>> upstream/master
    },

    [MOVE_BARRAGE] =
    {
        .name = COMPOUND_STRING("Barrage"),
        .description = COMPOUND_STRING(
            "Hurls round objects at the\n"
            "foe 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BARRAGE,
=======
        .battleAnimScript = gBattleAnimMove_Barrage,
>>>>>>> upstream/master
    },

    [MOVE_LEECH_LIFE] =
    {
        .name = COMPOUND_STRING("Leech Life"),
        .description = COMPOUND_STRING(
            "An attack that steals half\n"
            "the damage inflicted."),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 80 : 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_7 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LEECH_LIFE,
=======
        .battleAnimScript = gBattleAnimMove_LeechLife,
>>>>>>> upstream/master
    },

    [MOVE_LOVELY_KISS] =
    {
        .name = COMPOUND_STRING("Lovely Kiss"),
        .description = COMPOUND_STRING(
            "Demands a kiss with a scary\n"
            "face that induces sleep."),
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LOVELY_KISS,
=======
        .battleAnimScript = gBattleAnimMove_LovelyKiss,
>>>>>>> upstream/master
    },

    [MOVE_SKY_ATTACK] =
    {
        .name = COMPOUND_STRING("Sky Attack"),
        .description = COMPOUND_STRING(
            "Searches out weak spots,\n"
            "then strikes the next turn."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .criticalHitStage = B_UPDATED_MOVE_DATA >= GEN_3,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(B_UPDATED_MOVE_DATA >= GEN_4 ? STRINGID_CLOAKEDINAHARSHLIGHT : STRINGID_PKMNISGLOWING),
    #if B_UPDATED_MOVE_DATA >= GEN_3
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
    #endif
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SKY_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_SkyAttack,
>>>>>>> upstream/master
    },

    [MOVE_TRANSFORM] =
    {
        .name = COMPOUND_STRING("Transform"),
        .description = COMPOUND_STRING(
            "Alters the user's cells to\n"
            "become a copy of the foe."),
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TRANSFORM,
=======
        .battleAnimScript = gBattleAnimMove_Transform,
>>>>>>> upstream/master
    },

    [MOVE_BUBBLE] =
    {
        .name = COMPOUND_STRING("Bubble"),
        .description = COMPOUND_STRING(
            "An attack using bubbles.\n"
            "May lower the foe's Speed."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 40 : 20,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_BUBBLE,
=======
        .battleAnimScript = gBattleAnimMove_Bubble,
>>>>>>> upstream/master
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .name = COMPOUND_STRING("Dizzy Punch"),
        .description = COMPOUND_STRING(
            "A rhythmic punch that may\n"
            "confuse the foe."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DIZZY_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_DizzyPunch,
>>>>>>> upstream/master
    },

    [MOVE_SPORE] =
    {
        .name = COMPOUND_STRING("Spore"),
        .description = COMPOUND_STRING(
            "Scatters a cloud of spores\n"
            "that always induce sleep."),
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPORE,
=======
        .battleAnimScript = gBattleAnimMove_Spore,
>>>>>>> upstream/master
    },

    [MOVE_FLASH] =
    {
        .name = COMPOUND_STRING("Flash"),
        .description = COMPOUND_STRING(
            "Looses a powerful blast of\n"
            "light that cuts accuracy."),
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 70,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLASH,
=======
        .battleAnimScript = gBattleAnimMove_Flash,
>>>>>>> upstream/master
    },

    [MOVE_PSYWAVE] =
    {
        .name = COMPOUND_STRING("Psywave"),
        .description = COMPOUND_STRING(
            "Attacks with a psychic\n"
            "wave of varying intensity."),
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 80,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYWAVE,
=======
        .battleAnimScript = gBattleAnimMove_Psywave,
>>>>>>> upstream/master
    },

    [MOVE_SPLASH] =
    {
        .name = COMPOUND_STRING("Splash"),
        .description = COMPOUND_STRING(
            "It's just a splash...\n"
            "Has no effect whatsoever."),
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_3 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPLASH,
=======
        .battleAnimScript = gBattleAnimMove_Splash,
>>>>>>> upstream/master
    },

    [MOVE_ACID_ARMOR] =
    {
        .name = COMPOUND_STRING("Acid Armor"),
        .description = COMPOUND_STRING(
            "Liquifies the user's body\n"
            "to sharply raise Defense."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ACID_ARMOR,
=======
        .battleAnimScript = gBattleAnimMove_AcidArmor,
>>>>>>> upstream/master
    },

    [MOVE_CRABHAMMER] =
    {
        .name = COMPOUND_STRING("Crabhammer"),
        .description = COMPOUND_STRING(
            "Hammers with a pincer. Has a\n"
            "high critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 85,
        .criticalHitStage = 1,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_CRABHAMMER,
=======
        .battleAnimScript = gBattleAnimMove_Crabhammer,
>>>>>>> upstream/master
    },

    [MOVE_EXPLOSION] =
    {
        .name = COMPOUND_STRING("Explosion"),
        .description = COMPOUND_STRING(
            "Inflicts severe damage but\n"
            "makes the user faint."),
        .effect = EFFECT_EXPLOSION,
        .power = 250,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EXPLOSION,
=======
        .battleAnimScript = gBattleAnimMove_Explosion,
>>>>>>> upstream/master
    },

    [MOVE_FURY_SWIPES] =
    {
        .name = COMPOUND_STRING("Fury Swipes"),
        .description = COMPOUND_STRING(
            "Rakes the foe with sharp\n"
            "claws, etc., 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH},
<<<<<<< HEAD
        .battleAnimScript = Move_FURY_SWIPES,
=======
        .battleAnimScript = gBattleAnimMove_FurySwipes,
>>>>>>> upstream/master
    },

    [MOVE_BONEMERANG] =
    {
        .name = COMPOUND_STRING("Bonemerang"),
        .description = COMPOUND_STRING(
            "Throws a bone boomerang\n"
            "that strikes twice."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONEMERANG,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
<<<<<<< HEAD
        .battleAnimScript = Move_BONEMERANG,
=======
        .battleAnimScript = gBattleAnimMove_Bonemerang,
>>>>>>> upstream/master
    },

    [MOVE_REST] =
    {
        .name = COMPOUND_STRING("Rest"),
        .description = COMPOUND_STRING(
            "The user sleeps for 2 turns,\n"
            "restoring HP and status."),
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_REST,
        .contestComboMoves = {COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN},
<<<<<<< HEAD
        .battleAnimScript = Move_REST,
=======
        .battleAnimScript = gBattleAnimMove_Rest,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_SLIDE] =
    {
        .name = COMPOUND_STRING("Rock Slide"),
        .description = COMPOUND_STRING(
            "Large boulders are hurled.\n"
            "May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_SLIDE,
=======
        .battleAnimScript = gBattleAnimMove_RockSlide,
>>>>>>> upstream/master
    },

    [MOVE_HYPER_FANG] =
    {
        .name = COMPOUND_STRING("Hyper Fang"),
        .description = COMPOUND_STRING(
            "Attacks with sharp fangs.\n"
            "May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HYPER_FANG,
=======
        .battleAnimScript = gBattleAnimMove_HyperFang,
>>>>>>> upstream/master
    },

    [MOVE_SHARPEN] =
    {
        .name = COMPOUND_STRING("Sharpen"),
        .description = COMPOUND_STRING(
            "Reduces the polygon count\n"
            "and raises Attack."),
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHARPEN,
=======
        .battleAnimScript = gBattleAnimMove_Sharpen,
>>>>>>> upstream/master
    },

    [MOVE_CONVERSION] =
    {
        .name = COMPOUND_STRING("Conversion"),
        .description = COMPOUND_STRING(
            "Changes the user's type\n"
            "into a known move's type."),
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CONVERSION,
=======
        .battleAnimScript = gBattleAnimMove_Conversion,
>>>>>>> upstream/master
    },

    [MOVE_TRI_ATTACK] =
    {
        .name = COMPOUND_STRING("Tri Attack"),
        .description = COMPOUND_STRING(
            "Fires three types of beams\n"
            "at the same time."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TRI_ATTACK,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON},
<<<<<<< HEAD
        .battleAnimScript = Move_TRI_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_TriAttack,
>>>>>>> upstream/master
    },

    [MOVE_SUPER_FANG] =
    {
        .name = COMPOUND_STRING("Super Fang"),
        .description = COMPOUND_STRING(
            "Attacks with sharp fangs\n"
            "and cuts half the foe's HP."),
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
<<<<<<< HEAD
        .battleAnimScript = Move_SUPER_FANG,
=======
        .battleAnimScript = gBattleAnimMove_SuperFang,
>>>>>>> upstream/master
    },

    [MOVE_SLASH] =
    {
        .name = COMPOUND_STRING("Slash"),
        .description = COMPOUND_STRING(
            "Slashes with claws, etc. Has\n"
            "a high critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCRATCH, COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_SLASH,
=======
        .battleAnimScript = gBattleAnimMove_Slash,
>>>>>>> upstream/master
    },

    [MOVE_SUBSTITUTE] =
    {
        .name = COMPOUND_STRING("Substitute"),
        .description = COMPOUND_STRING(
            "Creates a decoy using 1/4\n"
            "of the user's maximum HP."),
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SUBSTITUTE,
=======
        .battleAnimScript = gBattleAnimMove_Substitute,
>>>>>>> upstream/master
    },

    [MOVE_STRUGGLE] =
    {
        .name = COMPOUND_STRING("Struggle"),
        .description = COMPOUND_STRING(
            "Used only if all PP are gone.\n"
            "Also hurts the user a little."),
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_RECOIL_HP_25,
            .accuracy = 0,
            .mirrorMoveBanned = TRUE,
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_RECOIL_HP_25,
                .self = TRUE,
            }),
        #else
            .effect = EFFECT_HIT,
            .accuracy = 100,
            .recoil = 25,
        #endif
        .power = 50,
        .type = TYPE_NORMAL,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_STRUGGLE,
=======
        .battleAnimScript = gBattleAnimMove_Struggle,
>>>>>>> upstream/master
    },

    [MOVE_SKETCH] =
    {
        .name = COMPOUND_STRING("Sketch"),
        .description = COMPOUND_STRING(
            "Copies the foe's last move\n"
            "permanently."),
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SKETCH,
=======
        .battleAnimScript = gBattleAnimMove_Sketch,
>>>>>>> upstream/master
    },

    [MOVE_TRIPLE_KICK] =
    {
        .name = COMPOUND_STRING("Triple Kick"),
        .description = COMPOUND_STRING(
            "Kicks the foe 3 times in a\n"
            "row with rising intensity."),
        .effect = EFFECT_TRIPLE_KICK,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_TRIPLE_KICK,
=======
        .battleAnimScript = gBattleAnimMove_TripleKick,
>>>>>>> upstream/master
    },

    [MOVE_THIEF] =
    {
        .name = COMPOUND_STRING("Thief"),
        .description = COMPOUND_STRING(
            "While attacking, it may\n"
            "steal the foe's held item."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEAL_ITEM,
        }),
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_THIEF,
=======
        .battleAnimScript = gBattleAnimMove_Thief,
>>>>>>> upstream/master
    },

    [MOVE_SPIDER_WEB] =
    {
        .name = COMPOUND_STRING("Spider Web"),
        .description = COMPOUND_STRING(
            "Ensnares the foe to stop it\n"
            "from fleeing or switching."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = (B_UPDATED_MOVE_FLAGS >= GEN_6) || (B_UPDATED_MOVE_FLAGS <= GEN_3),
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STRING_SHOT},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIDER_WEB,
=======
        .battleAnimScript = gBattleAnimMove_SpiderWeb,
>>>>>>> upstream/master
    },

    [MOVE_MIND_READER] =
    {
        .name = COMPOUND_STRING("Mind Reader"),
        .description = COMPOUND_STRING(
            "Senses the foe's action to\n"
            "ensure the next move's hit."),
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_MIND_READER,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIND_READER,
=======
        .battleAnimScript = gBattleAnimMove_MindReader,
>>>>>>> upstream/master
    },

    [MOVE_NIGHTMARE] =
    {
        .name = COMPOUND_STRING("Nightmare"),
        .description = COMPOUND_STRING(
            "Inflicts 1/4 damage on a\n"
            "sleeping foe every turn."),
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 100 : 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS <= GEN_3,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NIGHTMARE,
=======
        .battleAnimScript = gBattleAnimMove_Nightmare,
>>>>>>> upstream/master
    },

    [MOVE_FLAME_WHEEL] =
    {
        .name = COMPOUND_STRING("Flame Wheel"),
        .description = COMPOUND_STRING(
            "A fiery charge attack that\n"
            "may inflict a burn."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_FLAME_WHEEL,
=======
        .battleAnimScript = gBattleAnimMove_FlameWheel,
>>>>>>> upstream/master
    },

    [MOVE_SNORE] =
    {
        .name = COMPOUND_STRING("Snore"),
        .description = COMPOUND_STRING(
            "A loud attack that can be\n"
            "used only while asleep."),
        .effect = EFFECT_SNORE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
<<<<<<< HEAD
        .battleAnimScript = Move_SNORE,
=======
        .battleAnimScript = gBattleAnimMove_Snore,
>>>>>>> upstream/master
    },

    [MOVE_CURSE] =
    {
        .name = COMPOUND_STRING("Curse"),
        .description = COMPOUND_STRING(
            "A move that functions\n"
            "differently for GHOSTS."),
        .effect = EFFECT_CURSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_5 ? TYPE_GHOST : TYPE_MYSTERY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_CURSE },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_CURSE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CURSE,
=======
        .battleAnimScript = gBattleAnimMove_Curse,
>>>>>>> upstream/master
    },

    [MOVE_FLAIL] =
    {
        .name = COMPOUND_STRING("Flail"),
        .description = COMPOUND_STRING(
            "Inflicts more damage when\n"
            "the user's HP is down."),
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
<<<<<<< HEAD
        .battleAnimScript = Move_FLAIL,
=======
        .battleAnimScript = gBattleAnimMove_Flail,
>>>>>>> upstream/master
    },

    [MOVE_CONVERSION_2] =
    {
        .name = COMPOUND_STRING("Conversion 2"),
        .description = COMPOUND_STRING(
            "Makes the user resistant\n"
            "to the last attack's type."),
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = B_UPDATED_MOVE_DATA >= GEN_5 ? MOVE_TARGET_SELECTED : MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CONVERSION_2,
=======
        .battleAnimScript = gBattleAnimMove_Conversion2,
>>>>>>> upstream/master
    },

    [MOVE_AEROBLAST] =
    {
        .name = COMPOUND_STRING("Aeroblast"),
        .description = COMPOUND_STRING(
            "Launches a vacuumed blast.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = 1,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AEROBLAST,
=======
        .battleAnimScript = gBattleAnimMove_Aeroblast,
>>>>>>> upstream/master
    },

    [MOVE_COTTON_SPORE] =
    {
        .name = COMPOUND_STRING("Cotton Spore"),
        .description = COMPOUND_STRING(
            "Spores cling to the foe,\n"
            "sharply reducing Speed."),
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 40,
        .target = B_UPDATED_MOVE_DATA >= GEN_6 ? MOVE_TARGET_BOTH : MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COTTON_SPORE,
=======
        .battleAnimScript = gBattleAnimMove_CottonSpore,
>>>>>>> upstream/master
    },

    [MOVE_REVERSAL] =
    {
        .name = COMPOUND_STRING("Reversal"),
        .description = COMPOUND_STRING(
            "Inflicts more damage when\n"
            "the user's HP is down."),
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
<<<<<<< HEAD
        .battleAnimScript = Move_REVERSAL,
=======
        .battleAnimScript = gBattleAnimMove_Reversal,
>>>>>>> upstream/master
    },

    [MOVE_SPITE] =
    {
        .name = COMPOUND_STRING("Spite"),
        .description = COMPOUND_STRING(
            "Spitefully cuts the PP\n"
            "of the foe's last move."),
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE},
<<<<<<< HEAD
        .battleAnimScript = Move_SPITE,
=======
        .battleAnimScript = gBattleAnimMove_Spite,
>>>>>>> upstream/master
    },

    [MOVE_POWDER_SNOW] =
    {
        .name = COMPOUND_STRING("Powder Snow"),
        .description = COMPOUND_STRING(
            "Blasts the foe with a snowy\n"
        #if B_USE_FROSTBITE == TRUE
            "gust. May cause frostbite."),
        #else
            "gust. May cause freezing."),
        #endif
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_POWDER_SNOW,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_POWDER_SNOW,
=======
        .battleAnimScript = gBattleAnimMove_PowderSnow,
>>>>>>> upstream/master
    },

    [MOVE_PROTECT] =
    {
        .name = COMPOUND_STRING("Protect"),
        .description = COMPOUND_STRING(
            "Evades attack, but may fail\n"
            "if used in succession."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 4 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HARDEN},
<<<<<<< HEAD
        .battleAnimScript = Move_PROTECT,
=======
        .battleAnimScript = gBattleAnimMove_Protect,
>>>>>>> upstream/master
    },

    [MOVE_MACH_PUNCH] =
    {
        .name = COMPOUND_STRING("Mach Punch"),
        .description = COMPOUND_STRING(
            "A punch is thrown at wicked\n"
            "speed to strike first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MACH_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_MachPunch,
>>>>>>> upstream/master
    },

    [MOVE_SCARY_FACE] =
    {
        .name = COMPOUND_STRING("Scary Face"),
        .description = COMPOUND_STRING(
            "Frightens with a scary face\n"
            "to sharply reduce Speed."),
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCARY_FACE,
        .contestComboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_RAGE},
<<<<<<< HEAD
        .battleAnimScript = Move_SCARY_FACE,
=======
        .battleAnimScript = gBattleAnimMove_ScaryFace,
>>>>>>> upstream/master
    },

    [MOVE_FEINT_ATTACK] =
    {
        .name = COMPOUND_STRING("Feint Attack"),
        .description = COMPOUND_STRING(
            "Draws the foe close, then\n"
            "strikes without fail."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND},
<<<<<<< HEAD
        .battleAnimScript = Move_FEINT_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_FeintAttack,
>>>>>>> upstream/master
    },

    [MOVE_SWEET_KISS] =
    {
        .name = COMPOUND_STRING("Sweet Kiss"),
        .description = COMPOUND_STRING(
            "Demands a kiss with a cute\n"
            "look. May cause confusion."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
<<<<<<< HEAD
        .battleAnimScript = Move_SWEET_KISS,
=======
        .battleAnimScript = gBattleAnimMove_SweetKiss,
>>>>>>> upstream/master
    },

    [MOVE_BELLY_DRUM] =
    {
        .name = COMPOUND_STRING("Belly Drum"),
        .description = COMPOUND_STRING(
            "Maximizes Attack while\n"
            "sacrificing HP."),
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BELLY_DRUM,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BELLY_DRUM,
=======
        .battleAnimScript = gBattleAnimMove_BellyDrum,
>>>>>>> upstream/master
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .name = COMPOUND_STRING("Sludge Bomb"),
        .description = COMPOUND_STRING(
            "Sludge is hurled to inflict\n"
            "damage. May also poison."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SLUDGE_BOMB,
        .contestComboMoves = {COMBO_STARTER_SLUDGE},
<<<<<<< HEAD
        .battleAnimScript = Move_SLUDGE_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_SludgeBomb,
>>>>>>> upstream/master
    },

    [MOVE_MUD_SLAP] =
    {
        .name = COMPOUND_STRING("Mud-Slap"),
        .description = COMPOUND_STRING(
            "Hurls mud in the foe's face\n"
            "to reduce its accuracy."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SLAP,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_SANDSTORM},
<<<<<<< HEAD
        .battleAnimScript = Move_MUD_SLAP,
=======
        .battleAnimScript = gBattleAnimMove_MudSlap,
>>>>>>> upstream/master
    },

    [MOVE_OCTAZOOKA] =
    {
        .name = COMPOUND_STRING("Octazooka"),
        .description = COMPOUND_STRING(
            "Fires a lump of ink to\n"
            "damage and cut accuracy."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_OCTAZOOKA,
=======
        .battleAnimScript = gBattleAnimMove_Octazooka,
>>>>>>> upstream/master
    },

    [MOVE_SPIKES] =
    {
        .name = COMPOUND_STRING("Spikes"),
        .description = COMPOUND_STRING(
            "Sets spikes that hurt a \n"
            "foe switching in."),
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIKES,
=======
        .battleAnimScript = gBattleAnimMove_Spikes,
>>>>>>> upstream/master
    },

    [MOVE_ZAP_CANNON] =
    {
        .name = COMPOUND_STRING("Zap Cannon"),
        .description = COMPOUND_STRING(
            "Powerful and sure to cause\n"
            "paralysis, but inaccurate."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON},
<<<<<<< HEAD
        .battleAnimScript = Move_ZAP_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_ZapCannon,
>>>>>>> upstream/master
    },

    [MOVE_FORESIGHT] =
    {
        .name = COMPOUND_STRING("Foresight"),
        .description = COMPOUND_STRING(
            "Negates the foe's efforts\n"
            "to heighten evasiveness."),
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 0 : 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FORESIGHT,
=======
        .battleAnimScript = gBattleAnimMove_Foresight,
>>>>>>> upstream/master
    },

    [MOVE_DESTINY_BOND] =
    {
        .name = COMPOUND_STRING("Destiny Bond"),
        .description = COMPOUND_STRING(
            "If the user faints, the foe\n"
            "is also made to faint."),
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE, COMBO_STARTER_MEAN_LOOK},
<<<<<<< HEAD
        .battleAnimScript = Move_DESTINY_BOND,
=======
        .battleAnimScript = gBattleAnimMove_DestinyBond,
>>>>>>> upstream/master
    },

    [MOVE_PERISH_SONG] =
    {
        .name = COMPOUND_STRING("Perish Song"),
        .description = COMPOUND_STRING(
            "Any Pokémon hearing this\n"
            "song faints in 3 turns."),
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING},
<<<<<<< HEAD
        .battleAnimScript = Move_PERISH_SONG,
=======
        .battleAnimScript = gBattleAnimMove_PerishSong,
>>>>>>> upstream/master
    },

    [MOVE_ICY_WIND] =
    {
        .name = COMPOUND_STRING("Icy Wind"),
        .description = COMPOUND_STRING(
            "A chilling attack that\n"
            "lowers the foe's Speed."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_ICY_WIND,
=======
        .battleAnimScript = gBattleAnimMove_IcyWind,
>>>>>>> upstream/master
    },

    [MOVE_DETECT] =
    {
        .name = COMPOUND_STRING("Detect"),
        .description = COMPOUND_STRING(
            "Evades attack, but may fail\n"
            "if used in succession."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 4 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT},
<<<<<<< HEAD
        .battleAnimScript = Move_DETECT,
=======
        .battleAnimScript = gBattleAnimMove_Detect,
>>>>>>> upstream/master
    },

    [MOVE_BONE_RUSH] =
    {
        .name = COMPOUND_STRING("Bone Rush"),
        .description = COMPOUND_STRING(
            "Strikes the foe with a bone\n"
            "in hand 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_BONE_RUSH,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_SHADOW_BONE},
<<<<<<< HEAD
        .battleAnimScript = Move_BONE_RUSH,
=======
        .battleAnimScript = gBattleAnimMove_BoneRush,
>>>>>>> upstream/master
    },

    [MOVE_LOCK_ON] =
    {
        .name = COMPOUND_STRING("Lock-On"),
        .description = COMPOUND_STRING(
            "Locks on to the foe to\n"
            "ensure the next move hits."),
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_LOCK_ON,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LOCK_ON,
=======
        .battleAnimScript = gBattleAnimMove_LockOn,
>>>>>>> upstream/master
    },

    [MOVE_OUTRAGE] =
    {
        .name = COMPOUND_STRING("Outrage"),
        .description = COMPOUND_STRING(
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 120 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_OUTRAGE,
=======
        .battleAnimScript = gBattleAnimMove_Outrage,
>>>>>>> upstream/master
    },

    [MOVE_SANDSTORM] =
    {
        .name = COMPOUND_STRING("Sandstorm"),
        .description = COMPOUND_STRING(
            "Causes a sandstorm that\n"
            "rages for several turns."),
        .effect = EFFECT_SANDSTORM,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SANDSTORM,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SANDSTORM,
=======
        .battleAnimScript = gBattleAnimMove_Sandstorm,
>>>>>>> upstream/master
    },

    [MOVE_GIGA_DRAIN] =
    {
        .name = COMPOUND_STRING("Giga Drain"),
        .description = COMPOUND_STRING(
            "An attack that steals half\n"
            "the damage inflicted."),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 10 : 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_GIGA_DRAIN,
=======
        .battleAnimScript = gBattleAnimMove_GigaDrain,
>>>>>>> upstream/master
    },

    [MOVE_ENDURE] =
    {
        .name = COMPOUND_STRING("Endure"),
        .description = COMPOUND_STRING(
            "Endures any attack for\n"
            "1 turn, leaving at least 1HP."),
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 4 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_ENDURE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ENDURE,
=======
        .battleAnimScript = gBattleAnimMove_Endure,
>>>>>>> upstream/master
    },

    [MOVE_CHARM] =
    {
        .name = COMPOUND_STRING("Charm"),
        .description = COMPOUND_STRING(
            "Charms the foe and sharply\n"
            "reduces its Attack."),
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_CHARM,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CHARM,
=======
        .battleAnimScript = gBattleAnimMove_Charm,
>>>>>>> upstream/master
    },

    [MOVE_ROLLOUT] =
    {
        .name = COMPOUND_STRING("Rollout"),
        .description = COMPOUND_STRING(
            "An attack lasting 5 turns\n"
            "with rising intensity."),
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN},
<<<<<<< HEAD
        .battleAnimScript = Move_ROLLOUT,
=======
        .battleAnimScript = gBattleAnimMove_Rollout,
>>>>>>> upstream/master
    },

    [MOVE_FALSE_SWIPE] =
    {
        .name = COMPOUND_STRING("False Swipe"),
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_FALSE_SWIPE,
=======
        .battleAnimScript = gBattleAnimMove_FalseSwipe,
>>>>>>> upstream/master
    },

    [MOVE_SWAGGER] =
    {
        .name = COMPOUND_STRING("Swagger"),
        .description = COMPOUND_STRING(
            "Confuses the foe, but also\n"
            "sharply raises Attack."),
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 85 : 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SWAGGER,
=======
        .battleAnimScript = gBattleAnimMove_Swagger,
>>>>>>> upstream/master
    },

    [MOVE_MILK_DRINK] =
    {
        .name = COMPOUND_STRING("Milk Drink"),
        .description = COMPOUND_STRING(
            "Recovers up to half the\n"
            "user's maximum HP."),
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MILK_DRINK,
=======
        .battleAnimScript = gBattleAnimMove_MilkDrink,
>>>>>>> upstream/master
    },

    [MOVE_SPARK] =
    {
        .name = COMPOUND_STRING("Spark"),
        .description = COMPOUND_STRING(
            "An electrified tackle that\n"
            "may paralyze the foe."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_SPARK,
=======
        .battleAnimScript = gBattleAnimMove_Spark,
>>>>>>> upstream/master
    },

    [MOVE_FURY_CUTTER] =
    {
        .name = COMPOUND_STRING("Fury Cutter"),
        .description = COMPOUND_STRING(
            "An attack that intensifies\n"
            "on each successive hit."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_FURY_CUTTER,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_FURY_CUTTER,
=======
        .battleAnimScript = gBattleAnimMove_FuryCutter,
>>>>>>> upstream/master
    },

    [MOVE_STEEL_WING] =
    {
        .name = COMPOUND_STRING("Steel Wing"),
        .description = COMPOUND_STRING(
            "Strikes the foe with hard\n"
            "wings spread wide."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STEEL_WING,
=======
        .battleAnimScript = gBattleAnimMove_SteelWing,
>>>>>>> upstream/master
    },

    [MOVE_MEAN_LOOK] =
    {
        .name = COMPOUND_STRING("Mean Look"),
        .description = COMPOUND_STRING(
            "Fixes the foe with a mean\n"
            "look that prevents escape."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = (B_UPDATED_MOVE_FLAGS >= GEN_6) || (B_UPDATED_MOVE_FLAGS <= GEN_3),
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_MEAN_LOOK,
        .contestComboMoves = {COMBO_STARTER_CURSE},
<<<<<<< HEAD
        .battleAnimScript = Move_MEAN_LOOK,
=======
        .battleAnimScript = gBattleAnimMove_MeanLook,
>>>>>>> upstream/master
    },

    [MOVE_ATTRACT] =
    {
        .name = COMPOUND_STRING("Attract"),
        .description = COMPOUND_STRING(
            "Makes the opposite gender\n"
            "less likely to attack."),
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ATTRACT,
=======
        .battleAnimScript = gBattleAnimMove_Attract,
>>>>>>> upstream/master
    },

    [MOVE_SLEEP_TALK] =
    {
        .name = COMPOUND_STRING("Sleep Talk"),
        .description = COMPOUND_STRING(
            "Uses an available move\n"
            "randomly while asleep."),
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_REST},
<<<<<<< HEAD
        .battleAnimScript = Move_SLEEP_TALK,
=======
        .battleAnimScript = gBattleAnimMove_SleepTalk,
>>>>>>> upstream/master
    },

    [MOVE_HEAL_BELL] =
    {
        .name = COMPOUND_STRING("Heal Bell"),
        .description = COMPOUND_STRING(
            "Chimes soothingly to heal\n"
            "all status abnormalities."),
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = B_UPDATED_MOVE_FLAGS != GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HEAL_BELL,
        .contestComboMoves = {COMBO_STARTER_LUCKY_CHANT},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAL_BELL,
=======
        .battleAnimScript = gBattleAnimMove_HealBell,
>>>>>>> upstream/master
    },

    [MOVE_RETURN] =
    {
        .name = COMPOUND_STRING("Return"),
        .description = COMPOUND_STRING(
            "An attack that increases\n"
            "in power with friendship."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RETURN,
=======
        .battleAnimScript = gBattleAnimMove_Return,
>>>>>>> upstream/master
    },

    [MOVE_PRESENT] =
    {
        .name = COMPOUND_STRING("Present"),
        .description = COMPOUND_STRING(
            "A gift in the form of a\n"
            "bomb. May restore HP."),
        .effect = EFFECT_PRESENT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PRESENT,
=======
        .battleAnimScript = gBattleAnimMove_Present,
>>>>>>> upstream/master
    },

    [MOVE_FRUSTRATION] =
    {
        .name = COMPOUND_STRING("Frustration"),
        .description = COMPOUND_STRING(
            "An attack that is stronger\n"
            "if the Trainer is disliked."),
        .effect = EFFECT_FRUSTRATION,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FRUSTRATION,
=======
        .battleAnimScript = gBattleAnimMove_Frustration,
>>>>>>> upstream/master
    },

    [MOVE_SAFEGUARD] =
    {
        .name = COMPOUND_STRING("Safeguard"),
        .description = COMPOUND_STRING(
            "A mystical force prevents\n"
            "all status problems."),
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SAFEGUARD,
=======
        .battleAnimScript = gBattleAnimMove_Safeguard,
>>>>>>> upstream/master
    },

    [MOVE_PAIN_SPLIT] =
    {
        .name = COMPOUND_STRING("Pain Split"),
        .description = COMPOUND_STRING(
            "Adds the user and foe's HP,\n"
            "then shares them equally."),
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
<<<<<<< HEAD
        .battleAnimScript = Move_PAIN_SPLIT,
=======
        .battleAnimScript = gBattleAnimMove_PainSplit,
>>>>>>> upstream/master
    },

    [MOVE_SACRED_FIRE] =
    {
        .name = COMPOUND_STRING("Sacred Fire"),
        .description = COMPOUND_STRING(
            "A mystical fire attack that\n"
            "may inflict a burn."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_SACRED_FIRE,
=======
        .battleAnimScript = gBattleAnimMove_SacredFire,
>>>>>>> upstream/master
    },

    [MOVE_MAGNITUDE] =
    {
        .name = COMPOUND_STRING("Magnitude"),
        .description = COMPOUND_STRING(
            "A ground-shaking attack\n"
            "of random intensity."),
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesUnderground = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGNITUDE,
=======
        .battleAnimScript = gBattleAnimMove_Magnitude,
>>>>>>> upstream/master
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DynamicPunch", "Dynamic Punch"),
=======
        .name = COMPOUND_STRING("Dynamic Punch"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Powerful and sure to cause\n"
            "confusion, but inaccurate."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_DYNAMIC_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_DynamicPunch,
>>>>>>> upstream/master
    },

    [MOVE_MEGAHORN] =
    {
        .name = COMPOUND_STRING("Megahorn"),
        .description = COMPOUND_STRING(
            "A brutal ramming attack\n"
            "using out-thrust horns."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MEGAHORN,
=======
        .battleAnimScript = gBattleAnimMove_Megahorn,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_BREATH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DragonBreath", "Dragon Breath"),
=======
        .name = COMPOUND_STRING("Dragon Breath"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Strikes the foe with an\n"
            "incredible blast of breath."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresKingsRock = B_UPDATED_MOVE_FLAGS < GEN_3,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_BREATH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_BREATH,
=======
        .battleAnimScript = gBattleAnimMove_DragonBreath,
>>>>>>> upstream/master
    },

    [MOVE_BATON_PASS] =
    {
        .name = COMPOUND_STRING("Baton Pass"),
        .description = COMPOUND_STRING(
            "Switches out the user while\n"
            "keeping effects in play."),
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BATON_PASS,
=======
        .battleAnimScript = gBattleAnimMove_BatonPass,
>>>>>>> upstream/master
    },

    [MOVE_ENCORE] =
    {
        .name = COMPOUND_STRING("Encore"),
        .description = COMPOUND_STRING(
            "Makes the foe repeat its\n"
            "last move over 2 to 6 turns."),
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .encoreBanned = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ENCORE,
=======
        .battleAnimScript = gBattleAnimMove_Encore,
>>>>>>> upstream/master
    },

    [MOVE_PURSUIT] =
    {
        .name = COMPOUND_STRING("Pursuit"),
        .description = COMPOUND_STRING(
            "Inflicts bad damage if used\n"
            "on a foe switching out."),
        .effect = EFFECT_PURSUIT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresKingsRock = (B_UPDATED_MOVE_FLAGS == GEN_3 || B_UPDATED_MOVE_FLAGS == GEN_4),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PURSUIT,
=======
        .battleAnimScript = gBattleAnimMove_Pursuit,
>>>>>>> upstream/master
    },

    [MOVE_RAPID_SPIN] =
    {
        .name = COMPOUND_STRING("Rapid Spin"),
        .description = COMPOUND_STRING(
            "Spins the body at high\n"
            "speed to strike the foe."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 50 : 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAPID_SPIN,
            .self = TRUE,
        }
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
            ,{
                .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
                .self = TRUE,
                .chance = 100,
            }
        #endif
        ),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RAPID_SPIN,
=======
        .battleAnimScript = gBattleAnimMove_RapidSpin,
>>>>>>> upstream/master
    },

    [MOVE_SWEET_SCENT] =
    {
        .name = COMPOUND_STRING("Sweet Scent"),
        .description = COMPOUND_STRING(
            "Allures the foe to reduce\n"
            "evasiveness."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_SWEET_SCENT,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SWEET_SCENT,
=======
        .battleAnimScript = gBattleAnimMove_SweetScent,
>>>>>>> upstream/master
    },

    [MOVE_IRON_TAIL] =
    {
        .name = COMPOUND_STRING("Iron Tail"),
        .description = COMPOUND_STRING(
            "Attacks with a rock-hard\n"
            "tail. May lower Defense."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 75,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_IRON_TAIL,
=======
        .battleAnimScript = gBattleAnimMove_IronTail,
>>>>>>> upstream/master
    },

    [MOVE_METAL_CLAW] =
    {
        .name = COMPOUND_STRING("Metal Claw"),
        .description = COMPOUND_STRING(
            "A claw attack that may\n"
            "raise the user's Attack."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 35,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND},
<<<<<<< HEAD
        .battleAnimScript = Move_METAL_CLAW,
=======
        .battleAnimScript = gBattleAnimMove_MetalClaw,
>>>>>>> upstream/master
    },

    [MOVE_VITAL_THROW] =
    {
        .name = COMPOUND_STRING("Vital Throw"),
        .description = COMPOUND_STRING(
            "Makes the user's move last,\n"
            "but it never misses."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = -1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT},
<<<<<<< HEAD
        .battleAnimScript = Move_VITAL_THROW,
=======
        .battleAnimScript = gBattleAnimMove_VitalThrow,
>>>>>>> upstream/master
    },

    [MOVE_MORNING_SUN] =
    {
        .name = COMPOUND_STRING("Morning Sun"),
        .description = COMPOUND_STRING(
            "Restores HP. The amount\n"
            "varies with the weather."),
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_MORNING_SUN,
=======
        .battleAnimScript = gBattleAnimMove_MorningSun,
>>>>>>> upstream/master
    },

    [MOVE_SYNTHESIS] =
    {
        .name = COMPOUND_STRING("Synthesis"),
        .description = COMPOUND_STRING(
            "Restores HP. The amount\n"
            "varies with the weather."),
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_SYNTHESIS,
=======
        .battleAnimScript = gBattleAnimMove_Synthesis,
>>>>>>> upstream/master
    },

    [MOVE_MOONLIGHT] =
    {
        .name = COMPOUND_STRING("Moonlight"),
        .description = COMPOUND_STRING(
            "Restores HP. The amount\n"
            "varies with the weather."),
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .type = B_UPDATED_MOVE_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_MOONLIGHT,
=======
        .battleAnimScript = gBattleAnimMove_Moonlight,
>>>>>>> upstream/master
    },

    [MOVE_HIDDEN_POWER] =
    {
        .name = COMPOUND_STRING("Hidden Power"),
        .description = COMPOUND_STRING(
            "The effectiveness varies\n"
            "with the user."),
        .power = B_HIDDEN_POWER_DMG >= GEN_6 ? 60 : 1,
        .effect = EFFECT_HIDDEN_POWER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HIDDEN_POWER,
=======
        .battleAnimScript = gBattleAnimMove_HiddenPower,
>>>>>>> upstream/master
    },

    [MOVE_CROSS_CHOP] =
    {
        .name = COMPOUND_STRING("Cross Chop"),
        .description = COMPOUND_STRING(
            "A double-chopping attack.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .criticalHitStage = 1,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_CROSS_CHOP,
=======
        .battleAnimScript = gBattleAnimMove_CrossChop,
>>>>>>> upstream/master
    },

    [MOVE_TWISTER] =
    {
        .name = COMPOUND_STRING("Twister"),
        .description = COMPOUND_STRING(
            "Whips up a vicious twister\n"
            "to tear at the foe."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesAirborneDoubleDamage = TRUE,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TWISTER,
=======
        .battleAnimScript = gBattleAnimMove_Twister,
>>>>>>> upstream/master
    },

    [MOVE_RAIN_DANCE] =
    {
        .name = COMPOUND_STRING("Rain Dance"),
        .description = COMPOUND_STRING(
            "Boosts the power of Water-\n"
            "type moves for 5 turns."),
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_RAIN_DANCE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RAIN_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_RainDance,
>>>>>>> upstream/master
    },

    [MOVE_SUNNY_DAY] =
    {
        .name = COMPOUND_STRING("Sunny Day"),
        .description = COMPOUND_STRING(
            "Boosts the power of Fire-\n"
            "type moves for 5 turns."),
        .effect = EFFECT_SUNNY_DAY,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_SUNNY_DAY,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SUNNY_DAY,
=======
        .battleAnimScript = gBattleAnimMove_SunnyDay,
>>>>>>> upstream/master
    },

    [MOVE_CRUNCH] =
    {
        .name = COMPOUND_STRING("Crunch"),
        .description = COMPOUND_STRING(
            "Crunches with sharp fangs.\n"
        #if B_UPDATED_MOVE_DATA >= GEN_4
            "May lower Defense."),
        #else
            "May lower Sp. Def."),
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
            .additionalEffects = ADDITIONAL_EFFECTS({
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
        #else
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
        #endif
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCARY_FACE},
<<<<<<< HEAD
        .battleAnimScript = Move_CRUNCH,
=======
        .battleAnimScript = gBattleAnimMove_Crunch,
>>>>>>> upstream/master
    },

    [MOVE_MIRROR_COAT] =
    {
        .name = COMPOUND_STRING("Mirror Coat"),
        .description = COMPOUND_STRING(
            "Counters the foe's special\n"
            "attack at double the power."),
        .effect = EFFECT_MIRROR_COAT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TAUNT},
<<<<<<< HEAD
        .battleAnimScript = Move_MIRROR_COAT,
=======
        .battleAnimScript = gBattleAnimMove_MirrorCoat,
>>>>>>> upstream/master
    },

    [MOVE_PSYCH_UP] =
    {
        .name = COMPOUND_STRING("Psych Up"),
        .description = COMPOUND_STRING(
            "Copies the foe's effect(s)\n"
            "and gives to the user."),
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCH_UP,
=======
        .battleAnimScript = gBattleAnimMove_PsychUp,
>>>>>>> upstream/master
    },

    [MOVE_EXTREME_SPEED] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ExtremeSpeed", "Extreme Speed"),
=======
        .name = COMPOUND_STRING("Extreme Speed"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "An extremely fast and\n"
            "powerful attack."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 2 : 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EXTREME_SPEED,
=======
        .battleAnimScript = gBattleAnimMove_ExtremeSpeed,
>>>>>>> upstream/master
    },

    [MOVE_ANCIENT_POWER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("AncientPower", "Ancient Power"),
=======
        .name = COMPOUND_STRING("Ancient Power"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "An attack that may raise\n"
            "all stats."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ANCIENT_POWER,
=======
        .battleAnimScript = gBattleAnimMove_AncientPower,
>>>>>>> upstream/master
    },

    [MOVE_SHADOW_BALL] =
    {
        .name = COMPOUND_STRING("Shadow Ball"),
        .description = COMPOUND_STRING(
            "Hurls a black blob that may\n"
            "lower the foe's Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHADOW_BALL,
=======
        .battleAnimScript = gBattleAnimMove_ShadowBall,
>>>>>>> upstream/master
    },

    [MOVE_FUTURE_SIGHT] =
    {
        .name = COMPOUND_STRING("Future Sight"),
        .description = COMPOUND_STRING(
            "Heightens inner power to\n"
            "strike 2 turns later."),
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 90,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
<<<<<<< HEAD
        .battleAnimScript = Move_FUTURE_SIGHT,
=======
        .battleAnimScript = gBattleAnimMove_FutureSight,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_SMASH] =
    {
        .name = COMPOUND_STRING("Rock Smash"),
        .description = COMPOUND_STRING(
            "A rock-crushing attack\n"
            "that may lower Defense."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 40 : 20,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_SMASH,
=======
        .battleAnimScript = gBattleAnimMove_RockSmash,
>>>>>>> upstream/master
    },

    [MOVE_WHIRLPOOL] =
    {
        .name = COMPOUND_STRING("Whirlpool"),
        .description = COMPOUND_STRING(
            "Traps and hurts the foe in\n"
            "a whirlpool for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_WATER,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .damagesUnderwater = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_WHIRLPOOL,
=======
        .battleAnimScript = gBattleAnimMove_Whirlpool,
>>>>>>> upstream/master
    },

    [MOVE_BEAT_UP] =
    {
        .name = COMPOUND_STRING("Beat Up"),
        .description = COMPOUND_STRING(
            "Summons party Pokémon to\n"
            "join in the attack."),
        .effect = EFFECT_BEAT_UP,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 1 : 10,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BEAT_UP,
=======
        .battleAnimScript = gBattleAnimMove_BeatUp,
>>>>>>> upstream/master
    },

    [MOVE_FAKE_OUT] =
    {
        .name = COMPOUND_STRING("Fake Out"),
        .description = COMPOUND_STRING(
            "A 1st-turn, 1st-strike move\n"
            "that causes flinching."),
        .priority = B_UPDATED_MOVE_DATA >= GEN_5 ? 3 : 1,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_FAKE_OUT,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FAKE_OUT,
=======
        .battleAnimScript = gBattleAnimMove_FakeOut,
>>>>>>> upstream/master
    },

    [MOVE_UPROAR] =
    {
        .name = COMPOUND_STRING("Uproar"),
        .description = COMPOUND_STRING(
                                    #if B_UPROAR_TURNS >= GEN_5
                                       "Causes an uproar for 2 to 5\n"
                                    #else
                                       "Causes an uproar for 3\n"
                                    #endif
                                       "turns and prevents sleep."),
        .effect = EFFECT_UPROAR,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_UPROAR,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_UPROAR,
=======
        .battleAnimScript = gBattleAnimMove_Uproar,
>>>>>>> upstream/master
    },

    [MOVE_STOCKPILE] =
    {
        .name = COMPOUND_STRING("Stockpile"),
        .description = COMPOUND_STRING(
            "Charges up power for up to\n"
            "3 turns."),
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_4 ? 20 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_STOCKPILE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STOCKPILE,
=======
        .battleAnimScript = gBattleAnimMove_Stockpile,
>>>>>>> upstream/master
    },

    [MOVE_SPIT_UP] =
    {
        .name = COMPOUND_STRING("Spit Up"),
        .description = COMPOUND_STRING(
            "Releases stockpiled power\n"
            "(the more the better)."),
        .effect = EFFECT_SPIT_UP,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 1 : 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIT_UP,
=======
        .battleAnimScript = gBattleAnimMove_SpitUp,
>>>>>>> upstream/master
    },

    [MOVE_SWALLOW] =
    {
        .name = COMPOUND_STRING("Swallow"),
        .description = COMPOUND_STRING(
            "Absorbs stockpiled power\n"
            "and restores HP."),
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_STOCKPILE},
<<<<<<< HEAD
        .battleAnimScript = Move_SWALLOW,
=======
        .battleAnimScript = gBattleAnimMove_Swallow,
>>>>>>> upstream/master
    },

    [MOVE_HEAT_WAVE] =
    {
        .name = COMPOUND_STRING("Heat Wave"),
        .description = COMPOUND_STRING(
            "Exhales a hot breath on the\n"
            "foe. May inflict a burn."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 100,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAT_WAVE,
=======
        .battleAnimScript = gBattleAnimMove_HeatWave,
>>>>>>> upstream/master
    },

    [MOVE_HAIL] =
    {
        .name = COMPOUND_STRING("Hail"),
        .description = COMPOUND_STRING(
            "Summons a hailstorm that\n"
            "strikes every turn."),
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_HAIL,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HAIL,
=======
        .battleAnimScript = gBattleAnimMove_Hail,
>>>>>>> upstream/master
    },

    [MOVE_TORMENT] =
    {
        .name = COMPOUND_STRING("Torment"),
        .description = COMPOUND_STRING(
            "Torments the foe and stops\n"
            "successive use of a move."),
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TORMENT,
=======
        .battleAnimScript = gBattleAnimMove_Torment,
>>>>>>> upstream/master
    },

    [MOVE_FLATTER] =
    {
        .name = COMPOUND_STRING("Flatter"),
        .description = COMPOUND_STRING(
            "Confuses the foe, but\n"
            "raises its Sp. Atk."),
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
<<<<<<< HEAD
        .battleAnimScript = Move_FLATTER,
=======
        .battleAnimScript = gBattleAnimMove_Flatter,
>>>>>>> upstream/master
    },

    [MOVE_WILL_O_WISP] =
    {
        .name = COMPOUND_STRING("Will-O-Wisp"),
        .description = COMPOUND_STRING(
            "Inflicts a burn on the foe\n"
            "with intense fire."),
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 75,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_WILL_O_WISP,
=======
        .battleAnimScript = gBattleAnimMove_WillOWisp,
>>>>>>> upstream/master
    },

    [MOVE_MEMENTO] =
    {
        .name = COMPOUND_STRING("Memento"),
        .description = COMPOUND_STRING(
            "The user faints and lowers\n"
            "the foe's abilities."),
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MEMENTO,
=======
        .battleAnimScript = gBattleAnimMove_Memento,
>>>>>>> upstream/master
    },

    [MOVE_FACADE] =
    {
        .name = COMPOUND_STRING("Facade"),
        .description = COMPOUND_STRING(
            "Boosts Attack when burned,\n"
            "paralyzed, or poisoned."),
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FACADE,
=======
        .battleAnimScript = gBattleAnimMove_Facade,
>>>>>>> upstream/master
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .name = COMPOUND_STRING("Focus Punch"),
        .description = COMPOUND_STRING(
            "A powerful loyalty attack.\n"
            "The user flinches if hit."),
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = TRUE,
        .punchingMove = TRUE,
        .meFirstBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_FOCUS_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_FocusPunch,
>>>>>>> upstream/master
    },

    [MOVE_SMELLING_SALTS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SmellngSalts", "Smelling Salts"),
=======
        .name = COMPOUND_STRING("Smelling Salts"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Powerful against paralyzed\n"
            "foes, but also heals them."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SMELLING_SALTS,
=======
        .battleAnimScript = gBattleAnimMove_SmellingSalts,
>>>>>>> upstream/master
    },

    [MOVE_FOLLOW_ME] =
    {
        .name = COMPOUND_STRING("Follow Me"),
        .description = COMPOUND_STRING(
            "Draws attention to make\n"
            "foes attack only the user."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FOLLOW_ME,
=======
        .battleAnimScript = gBattleAnimMove_FollowMe,
>>>>>>> upstream/master
    },

    [MOVE_NATURE_POWER] =
    {
        .name = COMPOUND_STRING("Nature Power"),
        .description = COMPOUND_STRING(
            "The type of attack varies\n"
            "depending on the location."),
        .effect = EFFECT_NATURE_POWER,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NATURE_POWER,
=======
        .battleAnimScript = gBattleAnimMove_NaturePower,
>>>>>>> upstream/master
    },

    [MOVE_CHARGE] =
    {
        .name = COMPOUND_STRING("Charge"),
        .description = COMPOUND_STRING(
            "Charges power to boost the\n"
            "electric move used next."),
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CHARGE,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CHARGE,
=======
        .battleAnimScript = gBattleAnimMove_Charge,
>>>>>>> upstream/master
    },

    [MOVE_TAUNT] =
    {
        .name = COMPOUND_STRING("Taunt"),
        .description = COMPOUND_STRING(
            "Taunts the foe into only\n"
            "using attack moves."),
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_TAUNT,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TAUNT,
=======
        .battleAnimScript = gBattleAnimMove_Taunt,
>>>>>>> upstream/master
    },

    [MOVE_HELPING_HAND] =
    {
        .name = COMPOUND_STRING("Helping Hand"),
        .description = COMPOUND_STRING(
            "Boosts the power of the\n"
            "recipient's moves."),
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = B_UPDATED_MOVE_DATA >= GEN_4 ? MOVE_TARGET_ALLY : MOVE_TARGET_USER,
        .priority = 5,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HELPING_HAND,
=======
        .battleAnimScript = gBattleAnimMove_HelpingHand,
>>>>>>> upstream/master
    },

    [MOVE_TRICK] =
    {
        .name = COMPOUND_STRING("Trick"),
        .description = COMPOUND_STRING(
            "Tricks the foe into trading\n"
            "held items."),
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TRICK,
=======
        .battleAnimScript = gBattleAnimMove_Trick,
>>>>>>> upstream/master
    },

    [MOVE_ROLE_PLAY] =
    {
        .name = COMPOUND_STRING("Role Play"),
        .description = COMPOUND_STRING(
            "Mimics the target and\n"
            "copies its special ability."),
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROLE_PLAY,
=======
        .battleAnimScript = gBattleAnimMove_RolePlay,
>>>>>>> upstream/master
    },

    [MOVE_WISH] =
    {
        .name = COMPOUND_STRING("Wish"),
        .description = COMPOUND_STRING(
            "A wish that restores HP.\n"
            "It takes time to work."),
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WISH,
=======
        .battleAnimScript = gBattleAnimMove_Wish,
>>>>>>> upstream/master
    },

    [MOVE_ASSIST] =
    {
        .name = COMPOUND_STRING("Assist"),
        .description = COMPOUND_STRING(
            "Attacks randomly with one\n"
            "of the partner's moves."),
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_4,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ASSIST,
=======
        .battleAnimScript = gBattleAnimMove_Assist,
>>>>>>> upstream/master
    },

    [MOVE_INGRAIN] =
    {
        .name = COMPOUND_STRING("Ingrain"),
        .description = COMPOUND_STRING(
            "Lays roots that restore HP.\n"
            "The user can't switch out."),
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_INGRAIN,
=======
        .battleAnimScript = gBattleAnimMove_Ingrain,
>>>>>>> upstream/master
    },

    [MOVE_SUPERPOWER] =
    {
        .name = COMPOUND_STRING("Superpower"),
        .description = COMPOUND_STRING(
            "Boosts strength sharply,\n"
            "but lowers abilities."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_DEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_SUPERPOWER,
=======
        .battleAnimScript = gBattleAnimMove_Superpower,
>>>>>>> upstream/master
    },

    [MOVE_MAGIC_COAT] =
    {
        .name = COMPOUND_STRING("Magic Coat"),
        .description = COMPOUND_STRING(
            "Reflects special effects\n"
            "back to the attacker."),
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGIC_COAT,
=======
        .battleAnimScript = gBattleAnimMove_MagicCoat,
>>>>>>> upstream/master
    },

    [MOVE_RECYCLE] =
    {
        .name = COMPOUND_STRING("Recycle"),
        .description = COMPOUND_STRING(
            "Recycles a used item for\n"
            "one more use."),
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RECYCLE,
=======
        .battleAnimScript = gBattleAnimMove_Recycle,
>>>>>>> upstream/master
    },

    [MOVE_REVENGE] =
    {
        .name = COMPOUND_STRING("Revenge"),
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_REVENGE,
        .contestComboMoves = {COMBO_STARTER_PAYBACK},
<<<<<<< HEAD
        .battleAnimScript = Move_REVENGE,
=======
        .battleAnimScript = gBattleAnimMove_Revenge,
>>>>>>> upstream/master
    },

    [MOVE_BRICK_BREAK] =
    {
        .name = COMPOUND_STRING("Brick Break"),
        .description = COMPOUND_STRING(
            "Destroys barriers such as\n"
            "REFLECT and causes damage."),
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_BRICK_BREAK,
=======
        .battleAnimScript = gBattleAnimMove_BrickBreak,
>>>>>>> upstream/master
    },

    [MOVE_YAWN] =
    {
        .name = COMPOUND_STRING("Yawn"),
        .description = COMPOUND_STRING(
            "Lulls the foe into yawning,\n"
            "then sleeping next turn."),
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_YAWN,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_YAWN,
=======
        .battleAnimScript = gBattleAnimMove_Yawn,
>>>>>>> upstream/master
    },

    [MOVE_KNOCK_OFF] =
    {
        .name = COMPOUND_STRING("Knock Off"),
        .description = COMPOUND_STRING(
            "Knocks down the foe's held\n"
            "item to prevent its use."),
        .effect = EFFECT_KNOCK_OFF,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_KNOCK_OFF,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT},
<<<<<<< HEAD
        .battleAnimScript = Move_KNOCK_OFF,
=======
        .battleAnimScript = gBattleAnimMove_KnockOff,
>>>>>>> upstream/master
    },

    [MOVE_ENDEAVOR] =
    {
        .name = COMPOUND_STRING("Endeavor"),
        .description = COMPOUND_STRING(
            "Gains power if the user's HP\n"
            "is lower than the foe's HP."),
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ENDURE},
<<<<<<< HEAD
        .battleAnimScript = Move_ENDEAVOR,
=======
        .battleAnimScript = gBattleAnimMove_Endeavor,
>>>>>>> upstream/master
    },

    [MOVE_ERUPTION] =
    {
        .name = COMPOUND_STRING("Eruption"),
        .description = COMPOUND_STRING(
            "The higher the user's HP,\n"
            "the more damage caused."),
<<<<<<< HEAD
        .effect = EFFECT_ERUPTION,
=======
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
>>>>>>> upstream/master
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_ENDURE, COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_ERUPTION,
=======
        .battleAnimScript = gBattleAnimMove_Eruption,
>>>>>>> upstream/master
    },

    [MOVE_SKILL_SWAP] =
    {
        .name = COMPOUND_STRING("Skill Swap"),
        .description = COMPOUND_STRING(
            "The user swaps special\n"
            "abilities with the target."),
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SKILL_SWAP,
=======
        .battleAnimScript = gBattleAnimMove_SkillSwap,
>>>>>>> upstream/master
    },

    [MOVE_IMPRISON] =
    {
        .name = COMPOUND_STRING("Imprison"),
        .description = COMPOUND_STRING(
            "Prevents foes from using\n"
            "moves known by the user."),
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_IMPRISON,
=======
        .battleAnimScript = gBattleAnimMove_Imprison,
>>>>>>> upstream/master
    },

    [MOVE_REFRESH] =
    {
        .name = COMPOUND_STRING("Refresh"),
        .description = COMPOUND_STRING(
            "Heals poisoning, paralysis,\n"
            "or a burn."),
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SING, COMBO_STARTER_WATER_SPORT},
<<<<<<< HEAD
        .battleAnimScript = Move_REFRESH,
=======
        .battleAnimScript = gBattleAnimMove_Refresh,
>>>>>>> upstream/master
    },

    [MOVE_GRUDGE] =
    {
        .name = COMPOUND_STRING("Grudge"),
        .description = COMPOUND_STRING(
            "If the user faints, deletes\n"
            "all PP of foe's last move."),
        .effect = EFFECT_GRUDGE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_FOLLOW_ME },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CURSE},
<<<<<<< HEAD
        .battleAnimScript = Move_GRUDGE,
=======
        .battleAnimScript = gBattleAnimMove_Grudge,
>>>>>>> upstream/master
    },

    [MOVE_SNATCH] =
    {
        .name = COMPOUND_STRING("Snatch"),
        .description = COMPOUND_STRING(
            "Steals the effects of the\n"
            "move the target uses next."),
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresSubstitute = TRUE,
        .forcePressure = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SNATCH,
=======
        .battleAnimScript = gBattleAnimMove_Snatch,
>>>>>>> upstream/master
    },

    [MOVE_SECRET_POWER] =
    {
        .name = COMPOUND_STRING("Secret Power"),
        .description = COMPOUND_STRING(
            "An attack with effects\n"
            "that vary by location."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SECRET_POWER,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SECRET_POWER,
=======
        .battleAnimScript = gBattleAnimMove_SecretPower,
>>>>>>> upstream/master
    },

    [MOVE_DIVE] =
    {
        .name = COMPOUND_STRING("Dive"),
        .description = COMPOUND_STRING(
            "Dives underwater the first\n"
            "turn and strikes next turn."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 80 : 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .skyBattleBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNHIDUNDERWATER, COMPRESS_BITS(STATUS3_UNDERWATER)),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_DIVE,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF},
<<<<<<< HEAD
        .battleAnimScript = Move_DIVE,
=======
        .battleAnimScript = gBattleAnimMove_Dive,
>>>>>>> upstream/master
    },

    [MOVE_ARM_THRUST] =
    {
        .name = COMPOUND_STRING("Arm Thrust"),
        .description = COMPOUND_STRING(
            "Straight-arm punches that\n"
            "strike the foe 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_ARM_THRUST,
=======
        .battleAnimScript = gBattleAnimMove_ArmThrust,
>>>>>>> upstream/master
    },

    [MOVE_CAMOUFLAGE] =
    {
        .name = COMPOUND_STRING("Camouflage"),
        .description = COMPOUND_STRING(
            "Alters the Pokémon's type\n"
            "depending on the location."),
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CAMOUFLAGE,
=======
        .battleAnimScript = gBattleAnimMove_Camouflage,
>>>>>>> upstream/master
    },

    [MOVE_TAIL_GLOW] =
    {
        .name = COMPOUND_STRING("Tail Glow"),
        .description = COMPOUND_STRING(
            "Flashes a light that sharply\n"
            "raises Sp. Atk."),
        .effect = B_UPDATED_MOVE_DATA >= GEN_5 ? EFFECT_SPECIAL_ATTACK_UP_3 : EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TAIL_GLOW,
=======
        .battleAnimScript = gBattleAnimMove_TailGlow,
>>>>>>> upstream/master
    },

    [MOVE_LUSTER_PURGE] =
    {
        .name = COMPOUND_STRING("Luster Purge"),
        .description = COMPOUND_STRING(
            "Attacks with a burst of\n"
            "light. May lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_LUSTER_PURGE,
=======
        .battleAnimScript = gBattleAnimMove_LusterPurge,
>>>>>>> upstream/master
    },

    [MOVE_MIST_BALL] =
    {
        .name = COMPOUND_STRING("Mist Ball"),
        .description = COMPOUND_STRING(
            "Attacks with a flurry of\n"
            "down. May lower Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = (B_UPDATED_MOVE_DATA >= GEN_9) ? 95 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_MIST_BALL,
=======
        .battleAnimScript = gBattleAnimMove_MistBall,
>>>>>>> upstream/master
    },

    [MOVE_FEATHER_DANCE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FeatherDance", "Feather Dance"),
=======
        .name = COMPOUND_STRING("Feather Dance"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Envelops the foe with down\n"
            "to sharply reduce Attack."),
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FEATHER_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_FeatherDance,
>>>>>>> upstream/master
    },

    [MOVE_TEETER_DANCE] =
    {
        .name = COMPOUND_STRING("Teeter Dance"),
        .description = COMPOUND_STRING(
            "Confuses all Pokémon on\n"
            "the scene."),
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .danceMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_4,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TEETER_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_TeeterDance,
>>>>>>> upstream/master
    },

    [MOVE_BLAZE_KICK] =
    {
        .name = COMPOUND_STRING("Blaze Kick"),
        .description = COMPOUND_STRING(
            "A kick with a high critical-\n"
            "hit ratio. May cause a burn."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .criticalHitStage = 1,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_BLAZE_KICK,
=======
        .battleAnimScript = gBattleAnimMove_BlazeKick,
>>>>>>> upstream/master
    },

    [MOVE_MUD_SPORT] =
    {
        .name = COMPOUND_STRING("Mud Sport"),
        .description = COMPOUND_STRING(
            "Covers the user in mud to\n"
            "raise electrical resistance."),
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MUD_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM, COMBO_STARTER_WATER_SPORT},
<<<<<<< HEAD
        .battleAnimScript = Move_MUD_SPORT,
=======
        .battleAnimScript = gBattleAnimMove_MudSport,
>>>>>>> upstream/master
    },

    [MOVE_ICE_BALL] =
    {
        .name = COMPOUND_STRING("Ice Ball"),
        .description = COMPOUND_STRING(
            "A 5-turn attack that gains\n"
            "power on successive hits."),
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .instructBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_BALL,
=======
        .battleAnimScript = gBattleAnimMove_IceBall,
>>>>>>> upstream/master
    },

    [MOVE_NEEDLE_ARM] =
    {
        .name = COMPOUND_STRING("Needle Arm"),
        .description = COMPOUND_STRING(
            "Attacks with thorny arms.\n"
            "May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NEEDLE_ARM,
=======
        .battleAnimScript = gBattleAnimMove_NeedleArm,
>>>>>>> upstream/master
    },

    [MOVE_SLACK_OFF] =
    {
        .name = COMPOUND_STRING("Slack Off"),
        .description = COMPOUND_STRING(
            "Slacks off and restores\n"
            "half the maximum HP."),
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SLACK_OFF,
=======
        .battleAnimScript = gBattleAnimMove_SlackOff,
>>>>>>> upstream/master
    },

    [MOVE_HYPER_VOICE] =
    {
        .name = COMPOUND_STRING("Hyper Voice"),
        .description = COMPOUND_STRING(
            "A loud attack that uses\n"
            "sound waves to injure."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HYPER_VOICE,
=======
        .battleAnimScript = gBattleAnimMove_HyperVoice,
>>>>>>> upstream/master
    },

    [MOVE_POISON_FANG] =
    {
        .name = COMPOUND_STRING("Poison Fang"),
        .description = COMPOUND_STRING(
            "A sharp-fanged attack.\n"
            "May badly poison the foe."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POISON_FANG,
=======
        .battleAnimScript = gBattleAnimMove_PoisonFang,
>>>>>>> upstream/master
    },

    [MOVE_CRUSH_CLAW] =
    {
        .name = COMPOUND_STRING("Crush Claw"),
        .description = COMPOUND_STRING(
            "Tears at the foe with sharp\n"
            "claws. May lower Defense."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_CRUSH_CLAW,
=======
        .battleAnimScript = gBattleAnimMove_CrushClaw,
>>>>>>> upstream/master
    },

    [MOVE_BLAST_BURN] =
    {
        .name = COMPOUND_STRING("Blast Burn"),
        .description = COMPOUND_STRING(
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_BLAST_BURN,
=======
        .battleAnimScript = gBattleAnimMove_BlastBurn,
>>>>>>> upstream/master
    },

    [MOVE_HYDRO_CANNON] =
    {
        .name = COMPOUND_STRING("Hydro Cannon"),
        .description = COMPOUND_STRING(
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_HYDRO_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_HydroCannon,
>>>>>>> upstream/master
    },

    [MOVE_METEOR_MASH] =
    {
        .name = COMPOUND_STRING("Meteor Mash"),
        .description = COMPOUND_STRING(
            "Fires a meteor-like punch.\n"
            "May raise Attack."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 100,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_METEOR_MASH,
=======
        .battleAnimScript = gBattleAnimMove_MeteorMash,
>>>>>>> upstream/master
    },

    [MOVE_ASTONISH] =
    {
        .name = COMPOUND_STRING("Astonish"),
        .description = COMPOUND_STRING(
            "An attack that may shock\n"
            "the foe into flinching."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ASTONISH,
=======
        .battleAnimScript = gBattleAnimMove_Astonish,
>>>>>>> upstream/master
    },

    [MOVE_WEATHER_BALL] =
    {
        .name = COMPOUND_STRING("Weather Ball"),
        .description = COMPOUND_STRING(
            "The move's type and power\n"
            "change with the weather."),
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SANDSTORM, COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_WEATHER_BALL,
=======
        .battleAnimScript = gBattleAnimMove_WeatherBall,
>>>>>>> upstream/master
    },

    [MOVE_AROMATHERAPY] =
    {
        .name = COMPOUND_STRING("Aromatherapy"),
        .description = COMPOUND_STRING(
            "Heals all status problems\n"
            "with a soothing scent."),
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AROMATHERAPY,
=======
        .battleAnimScript = gBattleAnimMove_Aromatherapy,
>>>>>>> upstream/master
    },

    [MOVE_FAKE_TEARS] =
    {
        .name = COMPOUND_STRING("Fake Tears"),
        .description = COMPOUND_STRING(
            "Feigns crying to sharply\n"
            "lower the foe's Sp. Def."),
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FAKE_TEARS,
=======
        .battleAnimScript = gBattleAnimMove_FakeTears,
>>>>>>> upstream/master
    },

    [MOVE_AIR_CUTTER] =
    {
        .name = COMPOUND_STRING("Air Cutter"),
        .description = COMPOUND_STRING(
            "Hacks with razorlike wind.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 55,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .criticalHitStage = 1,
        .pp = 25,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AIR_CUTTER,
=======
        .battleAnimScript = gBattleAnimMove_AirCutter,
>>>>>>> upstream/master
    },

    [MOVE_OVERHEAT] =
    {
        .name = COMPOUND_STRING("Overheat"),
        .description = COMPOUND_STRING(
            "Allows a full-power attack,\n"
            "but sharply lowers Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = B_UPDATED_MOVE_DATA < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_OVERHEAT,
=======
        .battleAnimScript = gBattleAnimMove_Overheat,
>>>>>>> upstream/master
    },

    [MOVE_ODOR_SLEUTH] =
    {
        .name = COMPOUND_STRING("Odor Sleuth"),
        .description = COMPOUND_STRING(
            "Negates the foe's efforts\n"
            "to heighten evasiveness."),
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_4 ? 0 : 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ODOR_SLEUTH,
=======
        .battleAnimScript = gBattleAnimMove_OdorSleuth,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_TOMB] =
    {
        .name = COMPOUND_STRING("Rock Tomb"),
        .description = COMPOUND_STRING(
            "Stops the foe from moving\n"
            "with rocks and cuts Speed."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 95 : 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ROCK_THROW},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_TOMB,
=======
        .battleAnimScript = gBattleAnimMove_RockTomb,
>>>>>>> upstream/master
    },

    [MOVE_SILVER_WIND] =
    {
        .name = COMPOUND_STRING("Silver Wind"),
        .description = COMPOUND_STRING(
            "A powdery attack that may\n"
            "raise abilities."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SILVER_WIND,
=======
        .battleAnimScript = gBattleAnimMove_SilverWind,
>>>>>>> upstream/master
    },

    [MOVE_METAL_SOUND] =
    {
        .name = COMPOUND_STRING("Metal Sound"),
        .description = COMPOUND_STRING(
            "Emits a horrible screech\n"
            "that sharply lowers Sp. Def."),
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_METAL_SOUND,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_METAL_SOUND,
=======
        .battleAnimScript = gBattleAnimMove_MetalSound,
>>>>>>> upstream/master
    },

    [MOVE_GRASS_WHISTLE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("GrassWhistle", "Grass Whistle"),
=======
        .name = COMPOUND_STRING("Grass Whistle"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Lulls the foe into sleep\n"
            "with a pleasant melody."),
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GRASS_WHISTLE,
=======
        .battleAnimScript = gBattleAnimMove_GrassWhistle,
>>>>>>> upstream/master
    },

    [MOVE_TICKLE] =
    {
        .name = COMPOUND_STRING("Tickle"),
        .description = COMPOUND_STRING(
            "Makes the foe laugh to\n"
            "lower Attack and Defense."),
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TICKLE,
=======
        .battleAnimScript = gBattleAnimMove_Tickle,
>>>>>>> upstream/master
    },

    [MOVE_COSMIC_POWER] =
    {
        .name = COMPOUND_STRING("Cosmic Power"),
        .description = COMPOUND_STRING(
            "Raises Defense and Sp. Def\n"
            "with a mystic power."),
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COSMIC_POWER,
=======
        .battleAnimScript = gBattleAnimMove_CosmicPower,
>>>>>>> upstream/master
    },

    [MOVE_WATER_SPOUT] =
    {
        .name = COMPOUND_STRING("Water Spout"),
        .description = COMPOUND_STRING(
            "Inflicts more damage if the\n"
            "user's HP is high."),
<<<<<<< HEAD
        .effect = EFFECT_ERUPTION,
=======
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
>>>>>>> upstream/master
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_WATER_SPOUT,
=======
        .battleAnimScript = gBattleAnimMove_WaterSpout,
>>>>>>> upstream/master
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .name = COMPOUND_STRING("Signal Beam"),
        .description = COMPOUND_STRING(
            "A strange beam attack that\n"
            "may confuse the foe."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SIGNAL_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_SignalBeam,
>>>>>>> upstream/master
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .name = COMPOUND_STRING("Shadow Punch"),
        .description = COMPOUND_STRING(
            "An unavoidable punch that\n"
            "is thrown from shadows."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHADOW_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_ShadowPunch,
>>>>>>> upstream/master
    },

    [MOVE_EXTRASENSORY] =
    {
        .name = COMPOUND_STRING("Extrasensory"),
        .description = COMPOUND_STRING(
            "Attacks with a peculiar\n"
            "power. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 20 : 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_4,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EXTRASENSORY,
=======
        .battleAnimScript = gBattleAnimMove_Extrasensory,
>>>>>>> upstream/master
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .name = COMPOUND_STRING("Sky Uppercut"),
        .description = COMPOUND_STRING(
            "An uppercut thrown as if\n"
            "leaping into the sky."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .damagesAirborne = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_SKY_UPPERCUT,
=======
        .battleAnimScript = gBattleAnimMove_SkyUppercut,
>>>>>>> upstream/master
    },

    [MOVE_SAND_TOMB] =
    {
        .name = COMPOUND_STRING("Sand Tomb"),
        .description = COMPOUND_STRING(
            "Traps and hurts the foe in\n"
            "quicksand for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 35 : 15,
        .type = TYPE_GROUND,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 85 : 70,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
<<<<<<< HEAD
        .battleAnimScript = Move_SAND_TOMB,
=======
        .battleAnimScript = gBattleAnimMove_SandTomb,
>>>>>>> upstream/master
    },

    [MOVE_SHEER_COLD] =
    {
        .name = COMPOUND_STRING("Sheer Cold"),
        .description = COMPOUND_STRING(
            "A chilling attack that\n"
            "causes fainting if it hits."),
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 30,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_SHEER_COLD,
=======
        .battleAnimScript = gBattleAnimMove_SheerCold,
>>>>>>> upstream/master
    },

    [MOVE_MUDDY_WATER] =
    {
        .name = COMPOUND_STRING("Muddy Water"),
        .description = COMPOUND_STRING(
            "Attacks with muddy water.\n"
            "May lower accuracy."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 95,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_MUDDY_WATER,
=======
        .battleAnimScript = gBattleAnimMove_MuddyWater,
>>>>>>> upstream/master
    },

    [MOVE_BULLET_SEED] =
    {
        .name = COMPOUND_STRING("Bullet Seed"),
        .description = COMPOUND_STRING(
            "Shoots 2 to 5 seeds in a row\n"
            "to strike the foe."),
        .effect = EFFECT_MULTI_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_BULLET_SEED,
=======
        .battleAnimScript = gBattleAnimMove_BulletSeed,
>>>>>>> upstream/master
    },

    [MOVE_AERIAL_ACE] =
    {
        .name = COMPOUND_STRING("Aerial Ace"),
        .description = COMPOUND_STRING(
            "An extremely speedy and\n"
            "unavoidable attack."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AERIAL_ACE,
=======
        .battleAnimScript = gBattleAnimMove_AerialAce,
>>>>>>> upstream/master
    },

    [MOVE_ICICLE_SPEAR] =
    {
        .name = COMPOUND_STRING("Icicle Spear"),
        .description = COMPOUND_STRING(
            "Attacks the foe by firing\n"
            "2 to 5 icicles in a row."),
        .effect = EFFECT_MULTI_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 25 : 10,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ICICLE_SPEAR,
=======
        .battleAnimScript = gBattleAnimMove_IcicleSpear,
>>>>>>> upstream/master
    },

    [MOVE_IRON_DEFENSE] =
    {
        .name = COMPOUND_STRING("Iron Defense"),
        .description = COMPOUND_STRING(
            "Hardens the body's surface\n"
            "to sharply raise Defense."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_IRON_DEFENSE,
=======
        .battleAnimScript = gBattleAnimMove_IronDefense,
>>>>>>> upstream/master
    },

    [MOVE_BLOCK] =
    {
        .name = COMPOUND_STRING("Block"),
        .description = COMPOUND_STRING(
            "Blocks the foe's way to\n"
            "prevent escape."),
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = (B_UPDATED_MOVE_FLAGS >= GEN_6) || (B_UPDATED_MOVE_FLAGS <= GEN_3),
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BLOCK,
=======
        .battleAnimScript = gBattleAnimMove_Block,
>>>>>>> upstream/master
    },

    [MOVE_HOWL] =
    {
        .name = COMPOUND_STRING("Howl"),
        .description = COMPOUND_STRING(
            "Howls to raise the spirit\n"
            "and boosts Attack."),
        .power = 0,
        .effect = B_UPDATED_MOVE_DATA >= GEN_8 ? EFFECT_ATTACK_UP_USER_ALLY : EFFECT_ATTACK_UP,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
<<<<<<< HEAD
        .target = MOVE_TARGET_USER,
=======
        .target = MOVE_TARGET_USER, // Targeting is handled through the script
>>>>>>> upstream/master
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HOWL,
=======
        .battleAnimScript = gBattleAnimMove_Howl,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_CLAW] =
    {
        .name = COMPOUND_STRING("Dragon Claw"),
        .description = COMPOUND_STRING(
            "Slashes the foe with sharp\n"
            "claws."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_CLAW,
=======
        .battleAnimScript = gBattleAnimMove_DragonClaw,
>>>>>>> upstream/master
    },

    [MOVE_FRENZY_PLANT] =
    {
        .name = COMPOUND_STRING("Frenzy Plant"),
        .description = COMPOUND_STRING(
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_FRENZY_PLANT,
=======
        .battleAnimScript = gBattleAnimMove_FrenzyPlant,
>>>>>>> upstream/master
    },

    [MOVE_BULK_UP] =
    {
        .name = COMPOUND_STRING("Bulk Up"),
        .description = COMPOUND_STRING(
            "Bulks up the body to boost\n"
            "both Attack and Defense."),
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BULK_UP,
=======
        .battleAnimScript = gBattleAnimMove_BulkUp,
>>>>>>> upstream/master
    },

    [MOVE_BOUNCE] =
    {
        .name = COMPOUND_STRING("Bounce"),
        .description = COMPOUND_STRING(
            "Bounces up, then down the\n"
            "next turn. May paralyze."),
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNSPRANGUP, COMPRESS_BITS(STATUS3_ON_AIR)),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BOUNCE,
=======
        .battleAnimScript = gBattleAnimMove_Bounce,
>>>>>>> upstream/master
    },

    [MOVE_MUD_SHOT] =
    {
        .name = COMPOUND_STRING("Mud Shot"),
        .description = COMPOUND_STRING(
            "Hurls mud at the foe and\n"
            "reduces Speed."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
<<<<<<< HEAD
        .battleAnimScript = Move_MUD_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_MudShot,
>>>>>>> upstream/master
    },

    [MOVE_POISON_TAIL] =
    {
        .name = COMPOUND_STRING("Poison Tail"),
        .description = COMPOUND_STRING(
            "Has a high critical-hit\n"
            "ratio. May also poison."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POISON_TAIL,
=======
        .battleAnimScript = gBattleAnimMove_PoisonTail,
>>>>>>> upstream/master
    },

    [MOVE_COVET] =
    {
        .name = COMPOUND_STRING("Covet"),
        .description = COMPOUND_STRING(
            "Cutely begs to obtain an\n"
            "item held by the foe."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 60 : 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 25 : 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = B_UPDATED_MOVE_DATA >= GEN_4,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEAL_ITEM,
        }),
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COVET,
=======
        .battleAnimScript = gBattleAnimMove_Covet,
>>>>>>> upstream/master
    },

    [MOVE_VOLT_TACKLE] =
    {
        .name = COMPOUND_STRING("Volt Tackle"),
        .description = COMPOUND_STRING(
            "A life-risking tackle that\n"
            "slightly hurts the user."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .recoil = 33,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .additionalEffects = ADDITIONAL_EFFECTS({
                .moveEffect = MOVE_EFFECT_PARALYSIS,
                .chance = 10,
            }),
        #endif
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_VOLT_TACKLE,
=======
        .battleAnimScript = gBattleAnimMove_VoltTackle,
>>>>>>> upstream/master
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .name = COMPOUND_STRING("Magical Leaf"),
        .description = COMPOUND_STRING(
            "Attacks with a strange leaf\n"
            "that cannot be evaded."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGICAL_LEAF,
=======
        .battleAnimScript = gBattleAnimMove_MagicalLeaf,
>>>>>>> upstream/master
    },

    [MOVE_WATER_SPORT] =
    {
        .name = COMPOUND_STRING("Water Sport"),
        .description = COMPOUND_STRING(
            "The user becomes soaked to\n"
            "raise resistance to fire."),
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_WATER_SPORT,
        .contestComboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_WATER_SPORT,
=======
        .battleAnimScript = gBattleAnimMove_WaterSport,
>>>>>>> upstream/master
    },

    [MOVE_CALM_MIND] =
    {
        .name = COMPOUND_STRING("Calm Mind"),
        .description = COMPOUND_STRING(
            "Raises Sp. Atk and Sp. Def\n"
            "by focusing the mind."),
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_CALM_MIND,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CALM_MIND,
=======
        .battleAnimScript = gBattleAnimMove_CalmMind,
>>>>>>> upstream/master
    },

    [MOVE_LEAF_BLADE] =
    {
        .name = COMPOUND_STRING("Leaf Blade"),
        .description = COMPOUND_STRING(
            "Slashes with a sharp leaf.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_4 ? 90 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LEAF_BLADE,
=======
        .battleAnimScript = gBattleAnimMove_LeafBlade,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_DANCE] =
    {
        .name = COMPOUND_STRING("Dragon Dance"),
        .description = COMPOUND_STRING(
            "A mystical dance that ups\n"
            "Attack and Speed."),
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_DANCE,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_DragonDance,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_BLAST] =
    {
        .name = COMPOUND_STRING("Rock Blast"),
        .description = COMPOUND_STRING(
            "Hurls boulders at the foe\n"
            "2 to 5 times in a row."),
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 90 : 80,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_BLAST,
=======
        .battleAnimScript = gBattleAnimMove_RockBlast,
>>>>>>> upstream/master
    },

    [MOVE_SHOCK_WAVE] =
    {
        .name = COMPOUND_STRING("Shock Wave"),
        .description = COMPOUND_STRING(
            "A fast and unavoidable\n"
            "electric attack."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_SHOCK_WAVE,
=======
        .battleAnimScript = gBattleAnimMove_ShockWave,
>>>>>>> upstream/master
    },

    [MOVE_WATER_PULSE] =
    {
        .name = COMPOUND_STRING("Water Pulse"),
        .description = COMPOUND_STRING(
            "Attacks with ultrasonic\n"
            "waves. May confuse the foe."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_WATER_PULSE,
=======
        .battleAnimScript = gBattleAnimMove_WaterPulse,
>>>>>>> upstream/master
    },

    [MOVE_DOOM_DESIRE] =
    {
        .name = COMPOUND_STRING("Doom Desire"),
        .description = COMPOUND_STRING(
            "Summons strong sunlight to\n"
            "attack 2 turns later."),
        .effect = EFFECT_FUTURE_SIGHT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 120,
        .type = TYPE_STEEL,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 100 : 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DOOM_DESIRE,
=======
        .battleAnimScript = gBattleAnimMove_DoomDesire,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .name = COMPOUND_STRING("Psycho Boost"),
        .description = COMPOUND_STRING(
            "Allows a full-power attack,\n"
            "but sharply lowers Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CALM_MIND},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHO_BOOST,
=======
        .battleAnimScript = gBattleAnimMove_PsychoBoost,
>>>>>>> upstream/master
    },

    [MOVE_ROOST] =
    {
        .name = COMPOUND_STRING("Roost"),
        .description = COMPOUND_STRING(
            "Restores the user's HP by\n"
            "half of its max HP."),
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_BRAVE_BIRD},
<<<<<<< HEAD
        .battleAnimScript = Move_ROOST,
=======
        .battleAnimScript = gBattleAnimMove_Roost,
>>>>>>> upstream/master
    },

    [MOVE_GRAVITY] =
    {
        .name = COMPOUND_STRING("Gravity"),
        .description = COMPOUND_STRING(
            "Gravity is intensified\n"
            "negating levitation."),
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GRAVITY,
=======
        .battleAnimScript = gBattleAnimMove_Gravity,
>>>>>>> upstream/master
    },

    [MOVE_MIRACLE_EYE] =
    {
        .name = COMPOUND_STRING("Miracle Eye"),
        .description = COMPOUND_STRING(
            "Negate evasiveness and\n"
            "Dark-type's immunities."),
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIRACLE_EYE,
=======
        .battleAnimScript = gBattleAnimMove_MiracleEye,
>>>>>>> upstream/master
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        .name = COMPOUND_STRING("Wake-Up Slap"),
        .description = COMPOUND_STRING(
            "Powerful against sleeping\n"
            "foes, but also heals them."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 70 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = STATUS1_SLEEP,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WAKE_UP_SLAP,
=======
        .battleAnimScript = gBattleAnimMove_WakeUpSlap,
>>>>>>> upstream/master
    },

    [MOVE_HAMMER_ARM] =
    {
        .name = COMPOUND_STRING("Hammer Arm"),
        .description = COMPOUND_STRING(
            "A swinging fist attack\n"
            "that also lowers Speed."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_HAMMER_ARM,
=======
        .battleAnimScript = gBattleAnimMove_HammerArm,
>>>>>>> upstream/master
    },

    [MOVE_GYRO_BALL] =
    {
        .name = COMPOUND_STRING("Gyro Ball"),
        .description = COMPOUND_STRING(
            "A high-speed spin that does\n"
            "more damage to faster foes."),
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GYRO_BALL,
=======
        .battleAnimScript = gBattleAnimMove_GyroBall,
>>>>>>> upstream/master
    },

    [MOVE_HEALING_WISH] =
    {
        .name = COMPOUND_STRING("Healing Wish"),
        .description = sHealingWishDescription,
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .healingMove = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEALING_WISH,
=======
        .battleAnimScript = gBattleAnimMove_HealingWish,
>>>>>>> upstream/master
    },

    [MOVE_BRINE] =
    {
        .name = COMPOUND_STRING("Brine"),
        .description = COMPOUND_STRING(
            "Does double damage to foes\n"
            "with half HP."),
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_BRINE,
=======
        .battleAnimScript = gBattleAnimMove_Brine,
>>>>>>> upstream/master
    },

    [MOVE_NATURAL_GIFT] =
    {
        .name = COMPOUND_STRING("Natural Gift"),
        .description = COMPOUND_STRING(
            "The effectiveness varies\n"
            "with the held Berry."),
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NATURAL_GIFT,
=======
        .battleAnimScript = gBattleAnimMove_NaturalGift,
>>>>>>> upstream/master
    },

    [MOVE_FEINT] =
    {
        .name = COMPOUND_STRING("Feint"),
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 30 : 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FEINT,
=======
        .battleAnimScript = gBattleAnimMove_Feint,
>>>>>>> upstream/master
    },

    [MOVE_PLUCK] =
    {
        .name = COMPOUND_STRING("Pluck"),
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PLUCK,
=======
        .battleAnimScript = gBattleAnimMove_Pluck,
>>>>>>> upstream/master
    },

    [MOVE_TAILWIND] =
    {
        .name = COMPOUND_STRING("Tailwind"),
        .description = COMPOUND_STRING(
            "Whips up a turbulent breeze\n"
            "that raises Speed."),
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .snatchAffected = TRUE,
        .windMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TAILWIND,
=======
        .battleAnimScript = gBattleAnimMove_Tailwind,
>>>>>>> upstream/master
    },

    [MOVE_ACUPRESSURE] =
    {
        .name = COMPOUND_STRING("Acupressure"),
        .description = COMPOUND_STRING(
            "The user sharply raises\n"
            "one of its stats."),
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER | MOVE_TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .snatchAffected = B_UPDATED_MOVE_FLAGS < GEN_5,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ACUPRESSURE,
=======
        .battleAnimScript = gBattleAnimMove_Acupressure,
>>>>>>> upstream/master
    },

    [MOVE_METAL_BURST] =
    {
        .name = COMPOUND_STRING("Metal Burst"),
        .description = COMPOUND_STRING(
            "Retaliates any hit with\n"
            "greater power."),
        .effect = EFFECT_METAL_BURST,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .meFirstBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_METAL_SOUND},
<<<<<<< HEAD
        .battleAnimScript = Move_METAL_BURST,
=======
        .battleAnimScript = gBattleAnimMove_MetalBurst,
>>>>>>> upstream/master
    },

    [MOVE_U_TURN] =
    {
        .name = COMPOUND_STRING("U-turn"),
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_U_TURN,
=======
        .battleAnimScript = gBattleAnimMove_UTurn,
>>>>>>> upstream/master
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .name = COMPOUND_STRING("Close Combat"),
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
<<<<<<< HEAD
        .battleAnimScript = Move_CLOSE_COMBAT,
=======
        .battleAnimScript = gBattleAnimMove_CloseCombat,
>>>>>>> upstream/master
    },

    [MOVE_PAYBACK] =
    {
        .name = COMPOUND_STRING("Payback"),
        .description = COMPOUND_STRING(
            "An attack that gains power\n"
            "if the user moves last."),
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_PAYBACK,
        .contestComboMoves = {COMBO_STARTER_REVENGE},
<<<<<<< HEAD
        .battleAnimScript = Move_PAYBACK,
=======
        .battleAnimScript = gBattleAnimMove_Payback,
>>>>>>> upstream/master
    },

    [MOVE_ASSURANCE] =
    {
        .name = COMPOUND_STRING("Assurance"),
        .description = COMPOUND_STRING(
            "An attack that gains power\n"
            "if the foe has been hurt."),
        .effect = EFFECT_ASSURANCE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PAYBACK, COMBO_STARTER_REVENGE},
<<<<<<< HEAD
        .battleAnimScript = Move_ASSURANCE,
=======
        .battleAnimScript = gBattleAnimMove_Assurance,
>>>>>>> upstream/master
    },

    [MOVE_EMBARGO] =
    {
        .name = COMPOUND_STRING("Embargo"),
        .description = COMPOUND_STRING(
            "Prevents the foe from\n"
            "using any items."),
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EMBARGO,
=======
        .battleAnimScript = gBattleAnimMove_Embargo,
>>>>>>> upstream/master
    },

    [MOVE_FLING] =
    {
        .name = COMPOUND_STRING("Fling"),
        .description = COMPOUND_STRING(
            "The effectiveness varies\n"
            "with the held item."),
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLING,
=======
        .battleAnimScript = gBattleAnimMove_Fling,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        .name = COMPOUND_STRING("Psycho Shift"),
        .description = COMPOUND_STRING(
            "Transfers status problems\n"
            "to the foe."),
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHO_SHIFT,
=======
        .battleAnimScript = gBattleAnimMove_PsychoShift,
>>>>>>> upstream/master
    },

    [MOVE_TRUMP_CARD] =
    {
        .name = COMPOUND_STRING("Trump Card"),
        .description = COMPOUND_STRING(
            "The less PP the move has\n"
            "the more damage it does."),
        .effect = EFFECT_TRUMP_CARD,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TRUMP_CARD,
=======
        .battleAnimScript = gBattleAnimMove_TrumpCard,
>>>>>>> upstream/master
    },

    [MOVE_HEAL_BLOCK] =
    {
        .name = COMPOUND_STRING("Heal Block"),
        .description = COMPOUND_STRING(
            "Prevents the foe from\n"
            "recovering any HP."),
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_2 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAL_BLOCK,
=======
        .battleAnimScript = gBattleAnimMove_HealBlock,
>>>>>>> upstream/master
    },

    [MOVE_WRING_OUT] =
    {
        .name = COMPOUND_STRING("Wring Out"),
        .description = sWringOutDescription,
<<<<<<< HEAD
        .effect = EFFECT_VARY_POWER_BASED_ON_HP,
        .power = 1,
=======
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
>>>>>>> upstream/master
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .argument = 120,
=======
>>>>>>> upstream/master
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WRING_OUT,
=======
        .battleAnimScript = gBattleAnimMove_WringOut,
>>>>>>> upstream/master
    },

    [MOVE_POWER_TRICK] =
    {
        .name = COMPOUND_STRING("Power Trick"),
        .description = COMPOUND_STRING(
            "The user swaps its Attack\n"
            "and Defense stats."),
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_TRICK,
=======
        .battleAnimScript = gBattleAnimMove_PowerTrick,
>>>>>>> upstream/master
    },

    [MOVE_GASTRO_ACID] =
    {
        .name = COMPOUND_STRING("Gastro Acid"),
        .description = COMPOUND_STRING(
            "Stomach acid suppresses\n"
            "the foe's ability."),
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GASTRO_ACID,
=======
        .battleAnimScript = gBattleAnimMove_GastroAcid,
>>>>>>> upstream/master
    },

    [MOVE_LUCKY_CHANT] =
    {
        .name = COMPOUND_STRING("Lucky Chant"),
        .description = COMPOUND_STRING(
            "Prevents the foe from\n"
            "landing critical hits."),
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_LUCKY_CHANT,
        .contestComboMoves = {COMBO_STARTER_HEAL_BELL},
<<<<<<< HEAD
        .battleAnimScript = Move_LUCKY_CHANT,
=======
        .battleAnimScript = gBattleAnimMove_LuckyChant,
>>>>>>> upstream/master
    },

    [MOVE_ME_FIRST] =
    {
        .name = COMPOUND_STRING("Me First"),
        .description = COMPOUND_STRING(
            "Executes the foe's attack\n"
            "with greater power."),
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ME_FIRST,
=======
        .battleAnimScript = gBattleAnimMove_MeFirst,
>>>>>>> upstream/master
    },

    [MOVE_COPYCAT] =
    {
        .name = COMPOUND_STRING("Copycat"),
        .description = COMPOUND_STRING(
            "The user mimics the last\n"
            "move used by a foe."),
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .mimicBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COPYCAT,
=======
        .battleAnimScript = gBattleAnimMove_Copycat,
>>>>>>> upstream/master
    },

    [MOVE_POWER_SWAP] =
    {
        .name = COMPOUND_STRING("Power Swap"),
        .description = COMPOUND_STRING(
            "Swaps changes to Attack\n"
            "and Sp. Atk with the foe."),
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_SWAP,
=======
        .battleAnimScript = gBattleAnimMove_PowerSwap,
>>>>>>> upstream/master
    },

    [MOVE_GUARD_SWAP] =
    {
        .name = COMPOUND_STRING("Guard Swap"),
        .description = COMPOUND_STRING(
            "Swaps changes to Defense\n"
            "and Sp. Def with the foe."),
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GUARD_SWAP,
=======
        .battleAnimScript = gBattleAnimMove_GuardSwap,
>>>>>>> upstream/master
    },

    [MOVE_PUNISHMENT] =
    {
        .name = COMPOUND_STRING("Punishment"),
        .description = COMPOUND_STRING(
            "Does more damage if the\n"
            "foe has powered up."),
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PUNISHMENT,
=======
        .battleAnimScript = gBattleAnimMove_Punishment,
>>>>>>> upstream/master
    },

    [MOVE_LAST_RESORT] =
    {
        .name = COMPOUND_STRING("Last Resort"),
        .description = COMPOUND_STRING(
            "Can only be used if every\n"
            "other move has been used."),
        .effect = EFFECT_LAST_RESORT,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 140 : 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LAST_RESORT,
=======
        .battleAnimScript = gBattleAnimMove_LastResort,
>>>>>>> upstream/master
    },

    [MOVE_WORRY_SEED] =
    {
        .name = COMPOUND_STRING("Worry Seed"),
        .description = COMPOUND_STRING(
            "Plants a seed on the foe\n"
            "giving it Insomnia."),
        .effect = EFFECT_WORRY_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_WORRY_SEED,
        .contestComboMoves = {COMBO_STARTER_LEECH_SEED},
<<<<<<< HEAD
        .battleAnimScript = Move_WORRY_SEED,
=======
        .battleAnimScript = gBattleAnimMove_WorrySeed,
>>>>>>> upstream/master
    },

    [MOVE_SUCKER_PUNCH] =
    {
        .name = COMPOUND_STRING("Sucker Punch"),
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 70 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SUCKER_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_SuckerPunch,
>>>>>>> upstream/master
    },

    [MOVE_TOXIC_SPIKES] =
    {
        .name = COMPOUND_STRING("Toxic Spikes"),
        .description = COMPOUND_STRING(
            "Sets spikes that poison a\n"
            "foe switching in."),
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .forcePressure = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TOXIC_SPIKES,
=======
        .battleAnimScript = gBattleAnimMove_ToxicSpikes,
>>>>>>> upstream/master
    },

    [MOVE_HEART_SWAP] =
    {
        .name = COMPOUND_STRING("Heart Swap"),
        .description = COMPOUND_STRING(
            "Swaps any stat changes\n"
            "with the foe."),
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_BOOST_CRITS },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEART_SWAP,
=======
        .battleAnimScript = gBattleAnimMove_HeartSwap,
>>>>>>> upstream/master
    },

    [MOVE_AQUA_RING] =
    {
        .name = COMPOUND_STRING("Aqua Ring"),
        .description = COMPOUND_STRING(
            "Forms a veil of water\n"
            "that restores HP."),
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AQUA_RING,
=======
        .battleAnimScript = gBattleAnimMove_AquaRing,
>>>>>>> upstream/master
    },

    [MOVE_MAGNET_RISE] =
    {
        .name = COMPOUND_STRING("Magnet Rise"),
        .description = COMPOUND_STRING(
            "The user levitates with\n"
            "electromagnetism."),
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_EVSN_UP_1 },
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGNET_RISE,
=======
        .battleAnimScript = gBattleAnimMove_MagnetRise,
>>>>>>> upstream/master
    },

    [MOVE_FLARE_BLITZ] =
    {
        .name = COMPOUND_STRING("Flare Blitz"),
        .description = COMPOUND_STRING(
            "A charge that may burn the\n"
            "foe. Also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .recoil = 33,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_FLARE_BLITZ,
=======
        .battleAnimScript = gBattleAnimMove_FlareBlitz,
>>>>>>> upstream/master
    },

    [MOVE_FORCE_PALM] =
    {
        .name = COMPOUND_STRING("Force Palm"),
        .description = COMPOUND_STRING(
            "A shock wave attack that\n"
            "may paralyze the foe."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FORCE_PALM,
=======
        .battleAnimScript = gBattleAnimMove_ForcePalm,
>>>>>>> upstream/master
    },

    [MOVE_AURA_SPHERE] =
    {
        .name = COMPOUND_STRING("Aura Sphere"),
        .description = COMPOUND_STRING(
            "Attacks with an aura blast\n"
            "that cannot be evaded."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 90,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AURA_SPHERE,
=======
        .battleAnimScript = gBattleAnimMove_AuraSphere,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_POLISH] =
    {
        .name = COMPOUND_STRING("Rock Polish"),
        .description = COMPOUND_STRING(
            "Polishes the body to\n"
            "sharply raise Speed."),
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_POLISH,
=======
        .battleAnimScript = gBattleAnimMove_RockPolish,
>>>>>>> upstream/master
    },

    [MOVE_POISON_JAB] =
    {
        .name = COMPOUND_STRING("Poison Jab"),
        .description = COMPOUND_STRING(
            "A stabbing attack that\n"
            "may poison the foe."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POISON_JAB,
=======
        .battleAnimScript = gBattleAnimMove_PoisonJab,
>>>>>>> upstream/master
    },

    [MOVE_DARK_PULSE] =
    {
        .name = COMPOUND_STRING("Dark Pulse"),
        .description = COMPOUND_STRING(
            "Attacks with a horrible\n"
            "aura. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DARK_PULSE,
=======
        .battleAnimScript = gBattleAnimMove_DarkPulse,
>>>>>>> upstream/master
    },

    [MOVE_NIGHT_SLASH] =
    {
        .name = COMPOUND_STRING("Night Slash"),
        .description = COMPOUND_STRING(
            "Hits as soon as possible.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NIGHT_SLASH,
=======
        .battleAnimScript = gBattleAnimMove_NightSlash,
>>>>>>> upstream/master
    },

    [MOVE_AQUA_TAIL] =
    {
        .name = COMPOUND_STRING("Aqua Tail"),
        .description = COMPOUND_STRING(
            "The user swings its tail\n"
            "like a wave to attack."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_AQUA_TAIL,
=======
        .battleAnimScript = gBattleAnimMove_AquaTail,
>>>>>>> upstream/master
    },

    [MOVE_SEED_BOMB] =
    {
        .name = COMPOUND_STRING("Seed Bomb"),
        .description = COMPOUND_STRING(
            "A barrage of hard seeds\n"
            "is fired at the foe."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SEED_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_SeedBomb,
>>>>>>> upstream/master
    },

    [MOVE_AIR_SLASH] =
    {
        .name = COMPOUND_STRING("Air Slash"),
        .description = COMPOUND_STRING(
            "Attacks with a blade of\n"
            "air. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AIR_SLASH,
=======
        .battleAnimScript = gBattleAnimMove_AirSlash,
>>>>>>> upstream/master
    },

    [MOVE_X_SCISSOR] =
    {
        .name = COMPOUND_STRING("X-Scissor"),
        .description = COMPOUND_STRING(
            "Slashes the foe with crossed\n"
            "scythes, claws, etc."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SWORDS_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_X_SCISSOR,
=======
        .battleAnimScript = gBattleAnimMove_XScissor,
>>>>>>> upstream/master
    },

    [MOVE_BUG_BUZZ] =
    {
        .name = COMPOUND_STRING("Bug Buzz"),
        .description = COMPOUND_STRING(
            "A damaging sound wave that\n"
            "may lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BUG_BUZZ,
=======
        .battleAnimScript = gBattleAnimMove_BugBuzz,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_PULSE] =
    {
        .name = COMPOUND_STRING("Dragon Pulse"),
        .description = COMPOUND_STRING(
            "Generates a shock wave to\n"
            "damage the foe."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 85 : 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_PULSE,
=======
        .battleAnimScript = gBattleAnimMove_DragonPulse,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_RUSH] =
    {
        .name = COMPOUND_STRING("Dragon Rush"),
        .description = COMPOUND_STRING(
            "Tackles the foe with menace.\n"
            "May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_RUSH,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_TAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_RUSH,
=======
        .battleAnimScript = gBattleAnimMove_DragonRush,
>>>>>>> upstream/master
    },

    [MOVE_POWER_GEM] =
    {
        .name = COMPOUND_STRING("Power Gem"),
        .description = COMPOUND_STRING(
            "Attacks with rays of light\n"
            "that sparkle like diamonds."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_GEM,
=======
        .battleAnimScript = gBattleAnimMove_PowerGem,
>>>>>>> upstream/master
    },

    [MOVE_DRAIN_PUNCH] =
    {
        .name = COMPOUND_STRING("Drain Punch"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_5 ? 10 : 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAIN_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_DrainPunch,
>>>>>>> upstream/master
    },

    [MOVE_VACUUM_WAVE] =
    {
        .name = COMPOUND_STRING("Vacuum Wave"),
        .description = COMPOUND_STRING(
            "Whirls its fists to send\n"
            "a wave that strikes first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_VACUUM_WAVE,
=======
        .battleAnimScript = gBattleAnimMove_VacuumWave,
>>>>>>> upstream/master
    },

    [MOVE_FOCUS_BLAST] =
    {
        .name = COMPOUND_STRING("Focus Blast"),
        .description = COMPOUND_STRING(
            "Attacks at full power.\n"
            "May lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_FOCUS_ENERGY},
<<<<<<< HEAD
        .battleAnimScript = Move_FOCUS_BLAST,
=======
        .battleAnimScript = gBattleAnimMove_FocusBlast,
>>>>>>> upstream/master
    },

    [MOVE_ENERGY_BALL] =
    {
        .name = COMPOUND_STRING("Energy Ball"),
        .description = COMPOUND_STRING(
            "Draws power from nature to\n"
            "attack. May lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 90 : 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_ENERGY_BALL,
=======
        .battleAnimScript = gBattleAnimMove_EnergyBall,
>>>>>>> upstream/master
    },

    [MOVE_BRAVE_BIRD] =
    {
        .name = COMPOUND_STRING("Brave Bird"),
        .description = COMPOUND_STRING(
            "A low altitude charge that\n"
            "also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .recoil = 33,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_BRAVE_BIRD,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BRAVE_BIRD,
=======
        .battleAnimScript = gBattleAnimMove_BraveBird,
>>>>>>> upstream/master
    },

    [MOVE_EARTH_POWER] =
    {
        .name = COMPOUND_STRING("Earth Power"),
        .description = COMPOUND_STRING(
            "Makes the ground erupt with\n"
            "power. May lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EARTH_POWER,
=======
        .battleAnimScript = gBattleAnimMove_EarthPower,
>>>>>>> upstream/master
    },

    [MOVE_SWITCHEROO] =
    {
        .name = COMPOUND_STRING("Switcheroo"),
        .description = COMPOUND_STRING(
            "Swaps items with the foe\n"
            "faster than the eye can see."),
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SWITCHEROO,
=======
        .battleAnimScript = gBattleAnimMove_Switcheroo,
>>>>>>> upstream/master
    },

    [MOVE_GIGA_IMPACT] =
    {
        .name = COMPOUND_STRING("Giga Impact"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GIGA_IMPACT,
=======
        .battleAnimScript = gBattleAnimMove_GigaImpact,
>>>>>>> upstream/master
    },

    [MOVE_NASTY_PLOT] =
    {
        .name = COMPOUND_STRING("Nasty Plot"),
        .description = COMPOUND_STRING(
            "Thinks bad thoughts to\n"
            "sharply boost Sp. Atk."),
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NASTY_PLOT,
=======
        .battleAnimScript = gBattleAnimMove_NastyPlot,
>>>>>>> upstream/master
    },

    [MOVE_BULLET_PUNCH] =
    {
        .name = COMPOUND_STRING("Bullet Punch"),
        .description = COMPOUND_STRING(
            "Punches as fast as a bul-\n"
            "let. It always hits first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BULLET_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_BulletPunch,
>>>>>>> upstream/master
    },

    [MOVE_AVALANCHE] =
    {
        .name = COMPOUND_STRING("Avalanche"),
        .description = sRevengeDescription,
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = -4,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AVALANCHE,
=======
        .battleAnimScript = gBattleAnimMove_Avalanche,
>>>>>>> upstream/master
    },

    [MOVE_ICE_SHARD] =
    {
        .name = COMPOUND_STRING("Ice Shard"),
        .description = COMPOUND_STRING(
            "Hurls a chunk of ice that\n"
            "always strike first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_SHARD,
=======
        .battleAnimScript = gBattleAnimMove_IceShard,
>>>>>>> upstream/master
    },

    [MOVE_SHADOW_CLAW] =
    {
        .name = COMPOUND_STRING("Shadow Claw"),
        .description = COMPOUND_STRING(
            "Strikes with a shadow claw.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHADOW_CLAW,
=======
        .battleAnimScript = gBattleAnimMove_ShadowClaw,
>>>>>>> upstream/master
    },

    [MOVE_THUNDER_FANG] =
    {
        .name = COMPOUND_STRING("Thunder Fang"),
        .description = COMPOUND_STRING(
            "May cause flinching or\n"
            "leave the foe paralyzed."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_THUNDER_FANG,
        .contestComboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_FANG, COMBO_STARTER_ICE_FANG},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDER_FANG,
=======
        .battleAnimScript = gBattleAnimMove_ThunderFang,
>>>>>>> upstream/master
    },

    [MOVE_ICE_FANG] =
    {
        .name = COMPOUND_STRING("Ice Fang"),
        .description = COMPOUND_STRING(
            "May cause flinching or\n"
        #if B_USE_FROSTBITE == TRUE
            "leave the foe with frostbite."),
        #else
            "leave the foe frozen."),
        #endif
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_ICE_FANG,
        .contestComboMoves = {COMBO_STARTER_FIRE_FANG, COMBO_STARTER_THUNDER_FANG},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_FANG,
=======
        .battleAnimScript = gBattleAnimMove_IceFang,
>>>>>>> upstream/master
    },

    [MOVE_FIRE_FANG] =
    {
        .name = COMPOUND_STRING("Fire Fang"),
        .description = COMPOUND_STRING(
            "May cause flinching or\n"
            "leave the foe with a burn."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_FIRE_FANG,
        .contestComboMoves = {COMBO_STARTER_ICE_FANG, COMBO_STARTER_THUNDER_FANG},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRE_FANG,
=======
        .battleAnimScript = gBattleAnimMove_FireFang,
>>>>>>> upstream/master
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .name = COMPOUND_STRING("Shadow Sneak"),
        .description = COMPOUND_STRING(
            "Extends the user's shadow\n"
            "to strike first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHADOW_SNEAK,
=======
        .battleAnimScript = gBattleAnimMove_ShadowSneak,
>>>>>>> upstream/master
    },

    [MOVE_MUD_BOMB] =
    {
        .name = COMPOUND_STRING("Mud Bomb"),
        .description = COMPOUND_STRING(
            "Throws a blob of mud to\n"
            "damage and cut accuracy."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MUD_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_MudBomb,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHO_CUT] =
    {
        .name = COMPOUND_STRING("Psycho Cut"),
        .description = COMPOUND_STRING(
            "Tears with psychic blades.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHO_CUT,
=======
        .battleAnimScript = gBattleAnimMove_PsychoCut,
>>>>>>> upstream/master
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .name = COMPOUND_STRING("Zen Headbutt"),
        .description = COMPOUND_STRING(
            "Hits with a strong head-\n"
            "butt. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ZEN_HEADBUTT,
=======
        .battleAnimScript = gBattleAnimMove_ZenHeadbutt,
>>>>>>> upstream/master
    },

    [MOVE_MIRROR_SHOT] =
    {
        .name = COMPOUND_STRING("Mirror Shot"),
        .description = COMPOUND_STRING(
            "Emits a flash of energy to\n"
            "damage and cut accuracy."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIRROR_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_MirrorShot,
>>>>>>> upstream/master
    },

    [MOVE_FLASH_CANNON] =
    {
        .name = COMPOUND_STRING("Flash Cannon"),
        .description = COMPOUND_STRING(
            "Releases a blast of light\n"
            "that may lower Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLASH_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_FlashCannon,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_CLIMB] =
    {
        .name = COMPOUND_STRING("Rock Climb"),
        .description = COMPOUND_STRING(
            "A charging attack that may\n"
            "confuse the foe."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_CLIMB,
=======
        .battleAnimScript = gBattleAnimMove_RockClimb,
>>>>>>> upstream/master
    },

    [MOVE_DEFOG] =
    {
        .name = COMPOUND_STRING("Defog"),
        .description = COMPOUND_STRING(
            "Removes obstacles and\n"
            "lowers evasion."),
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        //.ignoresSubstitute = TRUE,
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DEFOG,
=======
        .battleAnimScript = gBattleAnimMove_Defog,
>>>>>>> upstream/master
    },

    [MOVE_TRICK_ROOM] =
    {
        .name = COMPOUND_STRING("Trick Room"),
        .description = COMPOUND_STRING(
            "Slower Pokémon get to move\n"
            "first for 5 turns."),
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ACC_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TRICK_ROOM,
=======
        .battleAnimScript = gBattleAnimMove_TrickRoom,
>>>>>>> upstream/master
    },

    [MOVE_DRACO_METEOR] =
    {
        .name = COMPOUND_STRING("Draco Meteor"),
        .description = COMPOUND_STRING(
            "Casts comets onto the foe.\n"
            "Harshly lowers the Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRACO_METEOR,
=======
        .battleAnimScript = gBattleAnimMove_DracoMeteor,
>>>>>>> upstream/master
    },

    [MOVE_DISCHARGE] =
    {
        .name = COMPOUND_STRING("Discharge"),
        .description = COMPOUND_STRING(
            "Zaps the foes with electri-\n"
            "city. May paralyze them."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_DISCHARGE,
=======
        .battleAnimScript = gBattleAnimMove_Discharge,
>>>>>>> upstream/master
    },

    [MOVE_LAVA_PLUME] =
    {
        .name = COMPOUND_STRING("Lava Plume"),
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_LAVA_PLUME,
=======
        .battleAnimScript = gBattleAnimMove_LavaPlume,
>>>>>>> upstream/master
    },

    [MOVE_LEAF_STORM] =
    {
        .name = COMPOUND_STRING("Leaf Storm"),
        .description = COMPOUND_STRING(
            "Whips up a storm of leaves.\n"
            "Harshly lowers the Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 130 : 140,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LEAF_STORM,
=======
        .battleAnimScript = gBattleAnimMove_LeafStorm,
>>>>>>> upstream/master
    },

    [MOVE_POWER_WHIP] =
    {
        .name = COMPOUND_STRING("Power Whip"),
        .description = COMPOUND_STRING(
            "Violently lashes the foe\n"
            "with vines or tentacles."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_WHIP,
=======
        .battleAnimScript = gBattleAnimMove_PowerWhip,
>>>>>>> upstream/master
    },

    [MOVE_ROCK_WRECKER] =
    {
        .name = COMPOUND_STRING("Rock Wrecker"),
        .description = sHyperBeamDescription,
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROCK_WRECKER,
=======
        .battleAnimScript = gBattleAnimMove_RockWrecker,
>>>>>>> upstream/master
    },

    [MOVE_CROSS_POISON] =
    {
        .name = COMPOUND_STRING("Cross Poison"),
        .description = COMPOUND_STRING(
            "A slash that may poison a\n"
            "foe and do critical damage."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_POISON,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CROSS_POISON,
=======
        .battleAnimScript = gBattleAnimMove_CrossPoison,
>>>>>>> upstream/master
    },

    [MOVE_GUNK_SHOT] =
    {
        .name = COMPOUND_STRING("Gunk Shot"),
        .description = COMPOUND_STRING(
            "Shoots filthy garbage at\n"
            "the foe. May also poison."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 70,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GUNK_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_GunkShot,
>>>>>>> upstream/master
    },

    [MOVE_IRON_HEAD] =
    {
        .name = COMPOUND_STRING("Iron Head"),
        .description = COMPOUND_STRING(
            "Slams the foe with a hard\n"
            "head. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_IRON_HEAD,
=======
        .battleAnimScript = gBattleAnimMove_IronHead,
>>>>>>> upstream/master
    },

    [MOVE_MAGNET_BOMB] =
    {
        .name = COMPOUND_STRING("Magnet Bomb"),
        .description = COMPOUND_STRING(
            "Launches a magnet that\n"
            "strikes without fail."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGNET_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_MagnetBomb,
>>>>>>> upstream/master
    },

    [MOVE_STONE_EDGE] =
    {
        .name = COMPOUND_STRING("Stone Edge"),
        .description = COMPOUND_STRING(
            "Stabs the foe with stones.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .criticalHitStage = 1,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STONE_EDGE,
=======
        .battleAnimScript = gBattleAnimMove_StoneEdge,
>>>>>>> upstream/master
    },

    [MOVE_CAPTIVATE] =
    {
        .name = COMPOUND_STRING("Captivate"),
        .description = COMPOUND_STRING(
            "Makes the opposite gender\n"
            "sharply reduce its Sp. Atk."),
        .effect = EFFECT_CAPTIVATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARM},
<<<<<<< HEAD
        .battleAnimScript = Move_CAPTIVATE,
=======
        .battleAnimScript = gBattleAnimMove_Captivate,
>>>>>>> upstream/master
    },

    [MOVE_STEALTH_ROCK] =
    {
        .name = COMPOUND_STRING("Stealth Rock"),
        .description = COMPOUND_STRING(
            "Sets floating stones that\n"
            "hurt a foe switching in."),
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .forcePressure = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STEALTH_ROCK,
=======
        .battleAnimScript = gBattleAnimMove_StealthRock,
>>>>>>> upstream/master
    },

    [MOVE_GRASS_KNOT] =
    {
        .name = COMPOUND_STRING("Grass Knot"),
        .description = COMPOUND_STRING(
            "A snare attack that does\n"
            "more damage to heavier foes."),
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GRASS_KNOT,
=======
        .battleAnimScript = gBattleAnimMove_GrassKnot,
>>>>>>> upstream/master
    },

    [MOVE_CHATTER] =
    {
        .name = COMPOUND_STRING("Chatter"),
        .description = COMPOUND_STRING(
            "Attacks with a sound wave\n"
            "that causes confusion."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_6,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .chance = 100,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .chance = 10,
        #else
            .chance = 31,
        #endif
        }),
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CHATTER,
=======
        .battleAnimScript = gBattleAnimMove_Chatter,
>>>>>>> upstream/master
    },

    [MOVE_JUDGMENT] =
    {
        .name = COMPOUND_STRING("Judgment"),
        .description = COMPOUND_STRING(
            "The type varies with the\n"
            "kind of Plate held."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = HOLD_EFFECT_PLATE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_JUDGMENT,
=======
        .battleAnimScript = gBattleAnimMove_Judgment,
>>>>>>> upstream/master
    },

    [MOVE_BUG_BITE] =
    {
        .name = COMPOUND_STRING("Bug Bite"),
        .description = sPluckDescription,
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BUG_BITE,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BUG_BITE,
=======
        .battleAnimScript = gBattleAnimMove_BugBite,
>>>>>>> upstream/master
    },

    [MOVE_CHARGE_BEAM] =
    {
        .name = COMPOUND_STRING("Charge Beam"),
        .description = COMPOUND_STRING(
            "Fires a beam of electricity.\n"
            "May raise Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 70,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_CHARGE_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_ChargeBeam,
>>>>>>> upstream/master
    },

    [MOVE_WOOD_HAMMER] =
    {
        .name = COMPOUND_STRING("Wood Hammer"),
        .description = COMPOUND_STRING(
            "Slams the body into a foe.\n"
            "The user gets hurt too."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .recoil = 33,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WOOD_HAMMER,
=======
        .battleAnimScript = gBattleAnimMove_WoodHammer,
>>>>>>> upstream/master
    },

    [MOVE_AQUA_JET] =
    {
        .name = COMPOUND_STRING("Aqua Jet"),
        .description = COMPOUND_STRING(
            "Strikes first by dashing\n"
            "at the foe at a high speed."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_AQUA_JET,
=======
        .battleAnimScript = gBattleAnimMove_AquaJet,
>>>>>>> upstream/master
    },

    [MOVE_ATTACK_ORDER] =
    {
        .name = COMPOUND_STRING("Attack Order"),
        .description = COMPOUND_STRING(
            "Underlings pummel the foe.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_ATTACK_ORDER,
        .contestComboMoves = {COMBO_STARTER_DEFEND_ORDER, COMBO_STARTER_HEAL_ORDER},
<<<<<<< HEAD
        .battleAnimScript = Move_ATTACK_ORDER,
=======
        .battleAnimScript = gBattleAnimMove_AttackOrder,
>>>>>>> upstream/master
    },

    [MOVE_DEFEND_ORDER] =
    {
        .name = COMPOUND_STRING("Defend Order"),
        .description = COMPOUND_STRING(
            "Raises Defense and Sp. Def\n"
            "with a living shield."),
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_DEFEND_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_HEAL_ORDER},
<<<<<<< HEAD
        .battleAnimScript = Move_DEFEND_ORDER,
=======
        .battleAnimScript = gBattleAnimMove_DefendOrder,
>>>>>>> upstream/master
    },

    [MOVE_HEAL_ORDER] =
    {
        .name = COMPOUND_STRING("Heal Order"),
        .description = COMPOUND_STRING(
            "The user's underlings show\n"
            "up to heal half its max HP."),
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HEAL_ORDER,
        .contestComboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_DEFEND_ORDER},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAL_ORDER,
=======
        .battleAnimScript = gBattleAnimMove_HealOrder,
>>>>>>> upstream/master
    },

    [MOVE_HEAD_SMASH] =
    {
        .name = COMPOUND_STRING("Head Smash"),
        .description = COMPOUND_STRING(
            "A life-risking headbutt that\n"
            "seriously hurts the user."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .recoil = 50,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAD_SMASH,
=======
        .battleAnimScript = gBattleAnimMove_HeadSmash,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_HIT] =
    {
        .name = COMPOUND_STRING("Double Hit"),
        .description = COMPOUND_STRING(
            "Slams the foe with a tail\n"
            "etc. Strikes twice."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_HIT,
=======
        .battleAnimScript = gBattleAnimMove_DoubleHit,
>>>>>>> upstream/master
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .name = COMPOUND_STRING("Roar of Time"),
        .description = COMPOUND_STRING(
            "Powerful, but leaves the\n"
            "user immobile the next turn."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROAR_OF_TIME,
=======
        .battleAnimScript = gBattleAnimMove_RoarOfTime,
>>>>>>> upstream/master
    },

    [MOVE_SPACIAL_REND] =
    {
        .name = COMPOUND_STRING("Spacial Rend"),
        .description = COMPOUND_STRING(
            "Tears the foe, and space.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .criticalHitStage = 1,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPACIAL_REND,
=======
        .battleAnimScript = gBattleAnimMove_SpacialRend,
>>>>>>> upstream/master
    },

    [MOVE_LUNAR_DANCE] =
    {
        .name = COMPOUND_STRING("Lunar Dance"),
        .description = sHealingWishDescription,
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = B_UPDATED_MOVE_FLAGS >= GEN_5,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LUNAR_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_LunarDance,
>>>>>>> upstream/master
    },

    [MOVE_CRUSH_GRIP] =
    {
        .name = COMPOUND_STRING("Crush Grip"),
        .description = sWringOutDescription,
<<<<<<< HEAD
        .effect = EFFECT_VARY_POWER_BASED_ON_HP,
        .power = 1,
=======
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 120,
>>>>>>> upstream/master
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .argument = 120,
=======
>>>>>>> upstream/master
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CRUSH_GRIP,
=======
        .battleAnimScript = gBattleAnimMove_CrushGrip,
>>>>>>> upstream/master
    },

    [MOVE_MAGMA_STORM] =
    {
        .name = COMPOUND_STRING("Magma Storm"),
        .description = COMPOUND_STRING(
            "Traps the foe in a vortex\n"
            "of fire for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 100 : 120,
        .type = TYPE_FIRE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_5 ? 75 : 70,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGMA_STORM,
=======
        .battleAnimScript = gBattleAnimMove_MagmaStorm,
>>>>>>> upstream/master
    },

    [MOVE_DARK_VOID] =
    {
        .name = COMPOUND_STRING("Dark Void"),
        .description = COMPOUND_STRING(
            "Drags the foe into total\n"
            "darkness, inducing Sleep."),
        .effect = EFFECT_DARK_VOID,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 80,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DARK_VOID,
=======
        .battleAnimScript = gBattleAnimMove_DarkVoid,
>>>>>>> upstream/master
    },

    [MOVE_SEED_FLARE] =
    {
        .name = COMPOUND_STRING("Seed Flare"),
        .description = COMPOUND_STRING(
            "Generates a shock wave that\n"
            "sharply reduces Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SEED_FLARE,
=======
        .battleAnimScript = gBattleAnimMove_SeedFlare,
>>>>>>> upstream/master
    },

    [MOVE_OMINOUS_WIND] =
    {
        .name = COMPOUND_STRING("Ominous Wind"),
        .description = COMPOUND_STRING(
            "A repulsive attack that may\n"
            "raise all stats."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_OMINOUS_WIND,
=======
        .battleAnimScript = gBattleAnimMove_OminousWind,
>>>>>>> upstream/master
    },

    [MOVE_SHADOW_FORCE] =
    {
        .name = COMPOUND_STRING("Shadow Force"),
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS == GEN_6,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_VANISHEDINSTANTLY, COMPRESS_BITS(STATUS3_PHANTOM_FORCE)),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHADOW_FORCE,
=======
        .battleAnimScript = gBattleAnimMove_ShadowForce,
>>>>>>> upstream/master
    },

    [MOVE_HONE_CLAWS] =
    {
        .name = COMPOUND_STRING("Hone Claws"),
        .description = COMPOUND_STRING(
            "Sharpens its claws to raise\n"
            "Attack and Accuracy."),
        .effect = EFFECT_ATTACK_ACCURACY_UP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HONE_CLAWS,
=======
        .battleAnimScript = gBattleAnimMove_HoneClaws,
>>>>>>> upstream/master
    },

    [MOVE_WIDE_GUARD] =
    {
        .name = COMPOUND_STRING("Wide Guard"),
        .description = COMPOUND_STRING(
            "Evades wide-ranging attacks\n"
            "for one turn."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WIDE_GUARD,
=======
        .battleAnimScript = gBattleAnimMove_WideGuard,
>>>>>>> upstream/master
    },

    [MOVE_GUARD_SPLIT] =
    {
        .name = COMPOUND_STRING("Guard Split"),
        .description = COMPOUND_STRING(
            "Averages changes to Defense\n"
            "and Sp. Def with the foe."),
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GUARD_SPLIT,
=======
        .battleAnimScript = gBattleAnimMove_GuardSplit,
>>>>>>> upstream/master
    },

    [MOVE_POWER_SPLIT] =
    {
        .name = COMPOUND_STRING("Power Split"),
        .description = COMPOUND_STRING(
            "Averages changes to Attack\n"
            "and Sp. Atk with the foe."),
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_SPLIT,
=======
        .battleAnimScript = gBattleAnimMove_PowerSplit,
>>>>>>> upstream/master
    },

    [MOVE_WONDER_ROOM] =
    {
        .name = COMPOUND_STRING("Wonder Room"),
        .description = COMPOUND_STRING(
            "Defense and Sp. Def stats\n"
            "are swapped for 5 turns."),
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WONDER_ROOM,
=======
        .battleAnimScript = gBattleAnimMove_WonderRoom,
>>>>>>> upstream/master
    },

    [MOVE_PSYSHOCK] =
    {
        .name = COMPOUND_STRING("Psyshock"),
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYSHOCK,
=======
        .battleAnimScript = gBattleAnimMove_Psyshock,
>>>>>>> upstream/master
    },

    [MOVE_VENOSHOCK] =
    {
        .name = COMPOUND_STRING("Venoshock"),
        .description = COMPOUND_STRING(
            "Does double damage if the\n"
            "foe is poisoned."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = STATUS1_PSN_ANY,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
<<<<<<< HEAD
        .battleAnimScript = Move_VENOSHOCK,
=======
        .battleAnimScript = gBattleAnimMove_Venoshock,
>>>>>>> upstream/master
    },

    [MOVE_AUTOTOMIZE] =
    {
        .name = COMPOUND_STRING("Autotomize"),
        .description = COMPOUND_STRING(
            "Sheds additional weight to\n"
            "sharply boost Speed."),
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AUTOTOMIZE,
=======
        .battleAnimScript = gBattleAnimMove_Autotomize,
>>>>>>> upstream/master
    },

    [MOVE_RAGE_POWDER] =
    {
        .name = COMPOUND_STRING("Rage Powder"),
        .description = COMPOUND_STRING(
            "Scatters powder to make\n"
            "foes attack only the user."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 2 : 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .powderMove = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RAGE_POWDER,
=======
        .battleAnimScript = gBattleAnimMove_RagePowder,
>>>>>>> upstream/master
    },

    [MOVE_TELEKINESIS] =
    {
        .name = COMPOUND_STRING("Telekinesis"),
        .description = COMPOUND_STRING(
            "Makes the foe float. It is\n"
            "easier to hit for 3 turns."),
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .gravityBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TELEKINESIS,
=======
        .battleAnimScript = gBattleAnimMove_Telekinesis,
>>>>>>> upstream/master
    },

    [MOVE_MAGIC_ROOM] =
    {
        .name = COMPOUND_STRING("Magic Room"),
        .description = COMPOUND_STRING(
            "Hold items lose their\n"
            "effects for 5 turns."),
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = B_UPDATED_MOVE_DATA >= GEN_6 ? 0 : -7,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGIC_ROOM,
=======
        .battleAnimScript = gBattleAnimMove_MagicRoom,
>>>>>>> upstream/master
    },

    [MOVE_SMACK_DOWN] =
    {
        .name = COMPOUND_STRING("Smack Down"),
        .description = COMPOUND_STRING(
            "Throws a rock to knock the\n"
            "foe down to the ground."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SMACK_DOWN,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SMACK_DOWN,
=======
        .battleAnimScript = gBattleAnimMove_SmackDown,
>>>>>>> upstream/master
    },

    [MOVE_STORM_THROW] =
    {
        .name = COMPOUND_STRING("Storm Throw"),
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STORM_THROW,
=======
        .battleAnimScript = gBattleAnimMove_StormThrow,
>>>>>>> upstream/master
    },

    [MOVE_FLAME_BURST] =
    {
        .name = COMPOUND_STRING("Flame Burst"),
        .description = COMPOUND_STRING(
            "A bursting flame that does\n"
            "damage to all foes."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLAME_BURST,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLAME_BURST,
=======
        .battleAnimScript = gBattleAnimMove_FlameBurst,
>>>>>>> upstream/master
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .name = COMPOUND_STRING("Sludge Wave"),
        .description = COMPOUND_STRING(
            "Swamps the foe with a wave\n"
            "of sludge. May also poison."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SLUDGE_WAVE,
=======
        .battleAnimScript = gBattleAnimMove_SludgeWave,
>>>>>>> upstream/master
    },

    [MOVE_QUIVER_DANCE] =
    {
        .name = COMPOUND_STRING("Quiver Dance"),
        .description = COMPOUND_STRING(
            "Dances to raise Sp. Atk\n"
            "Sp. Def and Speed."),
        .effect = EFFECT_QUIVER_DANCE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_QUIVER_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_QuiverDance,
>>>>>>> upstream/master
    },

    [MOVE_HEAVY_SLAM] =
    {
        .name = COMPOUND_STRING("Heavy Slam"),
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_7,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAVY_SLAM,
=======
        .battleAnimScript = gBattleAnimMove_HeavySlam,
>>>>>>> upstream/master
    },

    [MOVE_SYNCHRONOISE] =
    {
        .name = COMPOUND_STRING("Synchronoise"),
        .description = COMPOUND_STRING(
            "An odd shock wave that only\n"
            "damages same-type foes."),
        .effect = EFFECT_SYNCHRONOISE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 10 : 15,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SYNCHRONOISE,
=======
        .battleAnimScript = gBattleAnimMove_Synchronoise,
>>>>>>> upstream/master
    },

    [MOVE_ELECTRO_BALL] =
    {
        .name = COMPOUND_STRING("Electro Ball"),
        .description = COMPOUND_STRING(
            "Hurls an orb that does more\n"
            "damage to slower foes."),
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ELECTRO_BALL,
=======
        .battleAnimScript = gBattleAnimMove_ElectroBall,
>>>>>>> upstream/master
    },

    [MOVE_SOAK] =
    {
        .name = COMPOUND_STRING("Soak"),
        .description = COMPOUND_STRING(
            "Sprays water at the foe\n"
            "making it Water-type."),
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SOAK,
=======
        .battleAnimScript = gBattleAnimMove_Soak,
>>>>>>> upstream/master
    },

    [MOVE_FLAME_CHARGE] =
    {
        .name = COMPOUND_STRING("Flame Charge"),
        .description = COMPOUND_STRING(
            "Attacks in a cloak of\n"
            "flames. Raises Speed."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLAME_CHARGE,
=======
        .battleAnimScript = gBattleAnimMove_FlameCharge,
>>>>>>> upstream/master
    },

    [MOVE_COIL] =
    {
        .name = COMPOUND_STRING("Coil"),
        .description = COMPOUND_STRING(
<<<<<<< HEAD
            "Coils up to raise Attack\n"
=======
            "Coils up to raise Attack,\n"
>>>>>>> upstream/master
            "Defense and Accuracy."),
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COIL,
=======
        .battleAnimScript = gBattleAnimMove_Coil,
>>>>>>> upstream/master
    },

    [MOVE_LOW_SWEEP] =
    {
        .name = COMPOUND_STRING("Low Sweep"),
        .description = COMPOUND_STRING(
            "Attacks the foe's legs\n"
            "lowering its Speed."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LOW_SWEEP,
=======
        .battleAnimScript = gBattleAnimMove_LowSweep,
>>>>>>> upstream/master
    },

    [MOVE_ACID_SPRAY] =
    {
        .name = COMPOUND_STRING("Acid Spray"),
        .description = COMPOUND_STRING(
            "Sprays a hide-melting acid.\n"
            "Sharply reduces Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ACID_SPRAY,
=======
        .battleAnimScript = gBattleAnimMove_AcidSpray,
>>>>>>> upstream/master
    },

    [MOVE_FOUL_PLAY] =
    {
        .name = COMPOUND_STRING("Foul Play"),
        .description = COMPOUND_STRING(
            "The higher the foe's Attack\n"
            "the more damage caused."),
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FOUL_PLAY,
=======
        .battleAnimScript = gBattleAnimMove_FoulPlay,
>>>>>>> upstream/master
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .name = COMPOUND_STRING("Simple Beam"),
        .description = COMPOUND_STRING(
            "A beam that changes the\n"
            "foe's ability to Simple."),
        .effect = EFFECT_SIMPLE_BEAM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SIMPLE_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_SimpleBeam,
>>>>>>> upstream/master
    },

    [MOVE_ENTRAINMENT] =
    {
        .name = COMPOUND_STRING("Entrainment"),
        .description = COMPOUND_STRING(
            "Makes the foe mimic the\n"
            "user, gaining its ability."),
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ENTRAINMENT,
=======
        .battleAnimScript = gBattleAnimMove_Entrainment,
>>>>>>> upstream/master
    },

    [MOVE_AFTER_YOU] =
    {
        .name = COMPOUND_STRING("After You"),
        .description = COMPOUND_STRING(
            "Helps out the foe, letting\n"
            "it move next."),
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AFTER_YOU,
=======
        .battleAnimScript = gBattleAnimMove_AfterYou,
>>>>>>> upstream/master
    },

    [MOVE_ROUND] =
    {
        .name = COMPOUND_STRING("Round"),
        .description = COMPOUND_STRING(
            "A song that inflicts damage.\n"
            "Others can join in too."),
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ROUND,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROUND,
=======
        .battleAnimScript = gBattleAnimMove_Round,
>>>>>>> upstream/master
    },

    [MOVE_ECHOED_VOICE] =
    {
        .name = COMPOUND_STRING("Echoed Voice"),
        .description = COMPOUND_STRING(
            "Does more damage every turn\n"
            "it is used."),
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ECHOED_VOICE,
=======
        .battleAnimScript = gBattleAnimMove_EchoedVoice,
>>>>>>> upstream/master
    },

    [MOVE_CHIP_AWAY] =
    {
        .name = COMPOUND_STRING("Chip Away"),
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CHIP_AWAY,
=======
        .battleAnimScript = gBattleAnimMove_ChipAway,
>>>>>>> upstream/master
    },

    [MOVE_CLEAR_SMOG] =
    {
        .name = COMPOUND_STRING("Clear Smog"),
        .description = COMPOUND_STRING(
            "Attacks with white haze that\n"
            "eliminates all stat changes."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CLEAR_SMOG,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CLEAR_SMOG,
=======
        .battleAnimScript = gBattleAnimMove_ClearSmog,
>>>>>>> upstream/master
    },

    [MOVE_STORED_POWER] =
    {
        .name = COMPOUND_STRING("Stored Power"),
        .description = COMPOUND_STRING(
            "The higher the user's stats\n"
            "the more damage caused."),
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STORED_POWER,
=======
        .battleAnimScript = gBattleAnimMove_StoredPower,
>>>>>>> upstream/master
    },

    [MOVE_QUICK_GUARD] =
    {
        .name = COMPOUND_STRING("Quick Guard"),
        .description = COMPOUND_STRING(
            "Evades priority attacks\n"
            "for one turn."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_QUICK_GUARD,
=======
        .battleAnimScript = gBattleAnimMove_QuickGuard,
>>>>>>> upstream/master
    },

    [MOVE_ALLY_SWITCH] =
    {
        .name = COMPOUND_STRING("Ally Switch"),
        .description = COMPOUND_STRING(
            "The user switches places\n"
            "with its partner."),
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = B_UPDATED_MOVE_DATA >= GEN_7 ? 2 : 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ALLY_SWITCH,
=======
        .battleAnimScript = gBattleAnimMove_AllySwitch,
>>>>>>> upstream/master
    },

    [MOVE_SCALD] =
    {
        .name = COMPOUND_STRING("Scald"),
        .description = COMPOUND_STRING(
            "Shoots boiling water at the\n"
            "foe. May inflict a burn."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SCALD,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SCALD,
=======
        .battleAnimScript = gBattleAnimMove_Scald,
>>>>>>> upstream/master
    },

    [MOVE_SHELL_SMASH] =
    {
        .name = COMPOUND_STRING("Shell Smash"),
        .description = COMPOUND_STRING(
            "Raises offensive stats, but\n"
            "lowers defensive stats."),
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHELL_SMASH,
=======
        .battleAnimScript = gBattleAnimMove_ShellSmash,
>>>>>>> upstream/master
    },

    [MOVE_HEAL_PULSE] =
    {
        .name = COMPOUND_STRING("Heal Pulse"),
        .description = COMPOUND_STRING(
            "Recovers up to half the\n"
            "target's maximum HP."),
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAL_PULSE,
=======
        .battleAnimScript = gBattleAnimMove_HealPulse,
>>>>>>> upstream/master
    },

    [MOVE_HEX] =
    {
        .name = COMPOUND_STRING("Hex"),
        .description = COMPOUND_STRING(
            "Does double damage if the\n"
            "foe has a status problem."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 65 : 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 160 },
        .argument = STATUS1_ANY,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
<<<<<<< HEAD
        .battleAnimScript = Move_HEX,
=======
        .battleAnimScript = gBattleAnimMove_Hex,
>>>>>>> upstream/master
    },

    [MOVE_SKY_DROP] =
    {
        .name = COMPOUND_STRING("Sky Drop"),
        .description = COMPOUND_STRING(
            "Takes the foe into the sky\n"
            "then drops it the next turn."),
        .effect = EFFECT_SKY_DROP,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .gravityBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNTOOKTARGETHIGH, COMPRESS_BITS(STATUS3_ON_AIR)),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SKY_DROP,
=======
        .battleAnimScript = gBattleAnimMove_SkyDrop,
>>>>>>> upstream/master
    },

    [MOVE_SHIFT_GEAR] =
    {
        .name = COMPOUND_STRING("Shift Gear"),
        .description = COMPOUND_STRING(
            "Rotates its gears to raise\n"
            "Attack and Speed."),
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHIFT_GEAR,
=======
        .battleAnimScript = gBattleAnimMove_ShiftGear,
>>>>>>> upstream/master
    },

    [MOVE_CIRCLE_THROW] =
    {
        .name = COMPOUND_STRING("Circle Throw"),
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CIRCLE_THROW,
=======
        .battleAnimScript = gBattleAnimMove_CircleThrow,
>>>>>>> upstream/master
    },

    [MOVE_INCINERATE] =
    {
        .name = COMPOUND_STRING("Incinerate"),
        .description = COMPOUND_STRING(
            "Burns up Berries and Gems\n"
            "preventing their use."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 30,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_INCINERATE,
        }),
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_INCINERATE,
=======
        .battleAnimScript = gBattleAnimMove_Incinerate,
>>>>>>> upstream/master
    },

    [MOVE_QUASH] =
    {
        .name = COMPOUND_STRING("Quash"),
        .description = COMPOUND_STRING(
            "Suppresses the foe, making\n"
            "it move last."),
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_QUASH,
=======
        .battleAnimScript = gBattleAnimMove_Quash,
>>>>>>> upstream/master
    },

    [MOVE_ACROBATICS] =
    {
        .name = COMPOUND_STRING("Acrobatics"),
        .description = COMPOUND_STRING(
            "Does double damage if the\n"
            "user has no item."),
        .effect = EFFECT_ACROBATICS,
        .power = 55,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ACROBATICS,
=======
        .battleAnimScript = gBattleAnimMove_Acrobatics,
>>>>>>> upstream/master
    },

    [MOVE_REFLECT_TYPE] =
    {
        .name = COMPOUND_STRING("Reflect Type"),
        .description = COMPOUND_STRING(
            "The user reflects the foe's\n"
            "type, copying it."),
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_REFLECT_TYPE,
=======
        .battleAnimScript = gBattleAnimMove_ReflectType,
>>>>>>> upstream/master
    },

    [MOVE_RETALIATE] =
    {
        .name = COMPOUND_STRING("Retaliate"),
        .description = COMPOUND_STRING(
            "An attack that does more\n"
            "damage if an ally fainted."),
        .effect = EFFECT_RETALIATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RETALIATE,
=======
        .battleAnimScript = gBattleAnimMove_Retaliate,
>>>>>>> upstream/master
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .name = COMPOUND_STRING("Final Gambit"),
        .description = COMPOUND_STRING(
            "The user faints to damage\n"
            "the foe equal to its HP."),
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FINAL_GAMBIT,
=======
        .battleAnimScript = gBattleAnimMove_FinalGambit,
>>>>>>> upstream/master
    },

    [MOVE_BESTOW] =
    {
        .name = COMPOUND_STRING("Bestow"),
        .description = COMPOUND_STRING(
            "The user gives its held\n"
            "item to the foe."),
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_2 },
        .ignoresProtect = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BESTOW,
=======
        .battleAnimScript = gBattleAnimMove_Bestow,
>>>>>>> upstream/master
    },

    [MOVE_INFERNO] =
    {
        .name = COMPOUND_STRING("Inferno"),
        .description = COMPOUND_STRING(
            "Powerful and sure to inflict\n"
            "a burn, but inaccurate."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_INFERNO,
=======
        .battleAnimScript = gBattleAnimMove_Inferno,
>>>>>>> upstream/master
    },

    [MOVE_WATER_PLEDGE] =
    {
        .name = COMPOUND_STRING("Water Pledge"),
        .description = COMPOUND_STRING(
            "Attacks with a column of\n"
            "water. May make a rainbow."),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WATER_PLEDGE,
=======
        .battleAnimScript = gBattleAnimMove_WaterPledge,
>>>>>>> upstream/master
    },

    [MOVE_FIRE_PLEDGE] =
    {
        .name = COMPOUND_STRING("Fire Pledge"),
        .description = COMPOUND_STRING(
            "Attacks with a column of\n"
            "fire. May burn the grass."),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRE_PLEDGE,
=======
        .battleAnimScript = gBattleAnimMove_FirePledge,
>>>>>>> upstream/master
    },

    [MOVE_GRASS_PLEDGE] =
    {
        .name = COMPOUND_STRING("Grass Pledge"),
        .description = COMPOUND_STRING(
            "Attacks with a column of\n"
            "grass. May create a swamp."),
        .effect = EFFECT_PLEDGE,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 80 : 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GRASS_PLEDGE,
=======
        .battleAnimScript = gBattleAnimMove_GrassPledge,
>>>>>>> upstream/master
    },

    [MOVE_VOLT_SWITCH] =
    {
        .name = COMPOUND_STRING("Volt Switch"),
        .description = sUTurnDescription,
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_VOLT_SWITCH,
=======
        .battleAnimScript = gBattleAnimMove_VoltSwitch,
>>>>>>> upstream/master
    },

    [MOVE_STRUGGLE_BUG] =
    {
        .name = COMPOUND_STRING("Struggle Bug"),
        .description = COMPOUND_STRING(
            "Resisting, the user attacks\n"
            "the foe. Lowers Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STRUGGLE_BUG,
=======
        .battleAnimScript = gBattleAnimMove_StruggleBug,
>>>>>>> upstream/master
    },

    [MOVE_BULLDOZE] =
    {
        .name = COMPOUND_STRING("Bulldoze"),
        .description = COMPOUND_STRING(
            "Stomps down on the ground.\n"
            "Lowers Speed."),
        .effect = EFFECT_EARTHQUAKE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BULLDOZE,
=======
        .battleAnimScript = gBattleAnimMove_Bulldoze,
>>>>>>> upstream/master
    },

    [MOVE_FROST_BREATH] =
    {
        .name = COMPOUND_STRING("Frost Breath"),
        .description = sStormThrowDescription,
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 60 : 40,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .alwaysCriticalHit = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FROST_BREATH,
=======
        .battleAnimScript = gBattleAnimMove_FrostBreath,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_TAIL] =
    {
        .name = COMPOUND_STRING("Dragon Tail"),
        .description = sCircleThrowDescription,
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = COMBO_STARTER_DRAGON_TAIL,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_TAIL,
=======
        .battleAnimScript = gBattleAnimMove_DragonTail,
>>>>>>> upstream/master
    },

    [MOVE_WORK_UP] =
    {
        .name = COMPOUND_STRING("Work Up"),
        .description = COMPOUND_STRING(
            "The user is roused.\n"
            "Ups Attack and Sp. Atk."),
        .effect = EFFECT_ATTACK_SPATK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WORK_UP,
=======
        .battleAnimScript = gBattleAnimMove_WorkUp,
>>>>>>> upstream/master
    },

    [MOVE_ELECTROWEB] =
    {
        .name = COMPOUND_STRING("Electroweb"),
        .description = COMPOUND_STRING(
            "Snares the foe with an\n"
            "electric net. Lowers Speed."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ELECTROWEB,
=======
        .battleAnimScript = gBattleAnimMove_Electroweb,
>>>>>>> upstream/master
    },

    [MOVE_WILD_CHARGE] =
    {
        .name = COMPOUND_STRING("Wild Charge"),
        .description = COMPOUND_STRING(
            "An electrical tackle that\n"
            "also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .recoil = 25,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WILD_CHARGE,
=======
        .battleAnimScript = gBattleAnimMove_WildCharge,
>>>>>>> upstream/master
    },

    [MOVE_DRILL_RUN] =
    {
        .name = COMPOUND_STRING("Drill Run"),
        .description = COMPOUND_STRING(
            "Spins its body like a drill.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .criticalHitStage = 1,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRILL_RUN,
=======
        .battleAnimScript = gBattleAnimMove_DrillRun,
>>>>>>> upstream/master
    },

    [MOVE_DUAL_CHOP] =
    {
        .name = COMPOUND_STRING("Dual Chop"),
        .description = COMPOUND_STRING(
            "Attacks with brutal hits\n"
            "that strike twice."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DUAL_CHOP,
=======
        .battleAnimScript = gBattleAnimMove_DualChop,
>>>>>>> upstream/master
    },

    [MOVE_HEART_STAMP] =
    {
        .name = COMPOUND_STRING("Heart Stamp"),
        .description = COMPOUND_STRING(
            "A sudden blow after a cute\n"
            "act. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEART_STAMP,
=======
        .battleAnimScript = gBattleAnimMove_HeartStamp,
>>>>>>> upstream/master
    },

    [MOVE_HORN_LEECH] =
    {
        .name = COMPOUND_STRING("Horn Leech"),
        .description = sMegaDrainDescription,
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HORN_LEECH,
=======
        .battleAnimScript = gBattleAnimMove_HornLeech,
>>>>>>> upstream/master
    },

    [MOVE_SACRED_SWORD] =
    {
        .name = COMPOUND_STRING("Sacred Sword"),
        .description = sChipAwayDescription,
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_6 ? 15 : 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .slicingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SACRED_SWORD,
=======
        .battleAnimScript = gBattleAnimMove_SacredSword,
>>>>>>> upstream/master
    },

    [MOVE_RAZOR_SHELL] =
    {
        .name = COMPOUND_STRING("Razor Shell"),
        .description = COMPOUND_STRING(
            "Tears at the foe with sharp\n"
            "shells. May lower Defense."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RAZOR_SHELL,
=======
        .battleAnimScript = gBattleAnimMove_RazorShell,
>>>>>>> upstream/master
    },

    [MOVE_HEAT_CRASH] =
    {
        .name = COMPOUND_STRING("Heat Crash"),
        .description = sHeavySlamDescription,
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAT_CRASH,
=======
        .battleAnimScript = gBattleAnimMove_HeatCrash,
>>>>>>> upstream/master
    },

    [MOVE_LEAF_TORNADO] =
    {
        .name = COMPOUND_STRING("Leaf Tornado"),
        .description = COMPOUND_STRING(
            "Circles the foe with leaves\n"
            "to damage and cut accuracy."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        //.windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LEAF_TORNADO,
=======
        .battleAnimScript = gBattleAnimMove_LeafTornado,
>>>>>>> upstream/master
    },

    [MOVE_STEAMROLLER] =
    {
        .name = COMPOUND_STRING("Steamroller"),
        .description = COMPOUND_STRING(
            "Crushes the foe with its\n"
            "body. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STEAMROLLER,
=======
        .battleAnimScript = gBattleAnimMove_Steamroller,
>>>>>>> upstream/master
    },

    [MOVE_COTTON_GUARD] =
    {
        .name = COMPOUND_STRING("Cotton Guard"),
        .description = COMPOUND_STRING(
            "Wraps its body in cotton.\n"
            "Drastically raises Defense."),
        .effect = EFFECT_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COTTON_GUARD,
=======
        .battleAnimScript = gBattleAnimMove_CottonGuard,
>>>>>>> upstream/master
    },

    [MOVE_NIGHT_DAZE] =
    {
        .name = COMPOUND_STRING("Night Daze"),
        .description = COMPOUND_STRING(
            "Looses a pitch-black shock\n"
            "wave. May lower accuracy."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ACC_MINUS_1,
            .chance = 40,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NIGHT_DAZE,
=======
        .battleAnimScript = gBattleAnimMove_NightDaze,
>>>>>>> upstream/master
    },

    [MOVE_PSYSTRIKE] =
    {
        .name = COMPOUND_STRING("Psystrike"),
        .description = sPsyshockDescription,
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYSTRIKE,
=======
        .battleAnimScript = gBattleAnimMove_Psystrike,
>>>>>>> upstream/master
    },

    [MOVE_TAIL_SLAP] =
    {
        .name = COMPOUND_STRING("Tail Slap"),
        .description = COMPOUND_STRING(
            "Strikes the foe with its\n"
            "tail 2 to 5 times."),
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TAIL_SLAP,
=======
        .battleAnimScript = gBattleAnimMove_TailSlap,
>>>>>>> upstream/master
    },

    [MOVE_HURRICANE] =
    {
        .name = COMPOUND_STRING("Hurricane"),
        .description = COMPOUND_STRING(
            "Traps the foe in a fierce\n"
            "wind. May cause confusion."),
        .effect = EFFECT_THUNDER,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 110 : 120,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .damagesAirborne = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HURRICANE,
=======
        .battleAnimScript = gBattleAnimMove_Hurricane,
>>>>>>> upstream/master
    },

    [MOVE_HEAD_CHARGE] =
    {
        .name = COMPOUND_STRING("Head Charge"),
        .description = COMPOUND_STRING(
            "A charge using guard hair.\n"
            "It hurts the user a little."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .recoil = 25,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HEAD_CHARGE,
=======
        .battleAnimScript = gBattleAnimMove_HeadCharge,
>>>>>>> upstream/master
    },

    [MOVE_GEAR_GRIND] =
    {
        .name = COMPOUND_STRING("Gear Grind"),
        .description = COMPOUND_STRING(
            "Throws two steel gears\n"
            "that strike twice."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 180 },
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GEAR_GRIND,
=======
        .battleAnimScript = gBattleAnimMove_GearGrind,
>>>>>>> upstream/master
    },

    [MOVE_SEARING_SHOT] =
    {
        .name = COMPOUND_STRING("Searing Shot"),
        .description = sLavaPlumeDescription,
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SEARING_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_SearingShot,
>>>>>>> upstream/master
    },

    [MOVE_TECHNO_BLAST] =
    {
        .name = COMPOUND_STRING("Techno Blast"),
        .description = COMPOUND_STRING(
            "The type varies with the\n"
            "kind of Drive held."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_6 ? 120 : 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = HOLD_EFFECT_DRIVE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TECHNO_BLAST,
=======
        .battleAnimScript = gBattleAnimMove_TechnoBlast,
>>>>>>> upstream/master
    },

    [MOVE_RELIC_SONG] =
    {
        .name = COMPOUND_STRING("Relic Song"),
        .description = COMPOUND_STRING(
            "Attacks with an ancient\n"
            "song. May induce sleep."),
        .effect = EFFECT_RELIC_SONG,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = STATUS1_SLEEP,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_RELIC_SONG,
=======
        .battleAnimScript = gBattleAnimMove_RelicSong,
>>>>>>> upstream/master
    },

    [MOVE_SECRET_SWORD] =
    {
        .name = COMPOUND_STRING("Secret Sword"),
        .description = COMPOUND_STRING(
            "Cuts with a long horn that\n"
            "does physical damage."),
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SECRET_SWORD,
=======
        .battleAnimScript = gBattleAnimMove_SecretSword,
>>>>>>> upstream/master
    },

    [MOVE_GLACIATE] =
    {
        .name = COMPOUND_STRING("Glaciate"),
        .description = COMPOUND_STRING(
            "Blows very cold air at the\n"
            "foe. It lowers their Speed."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GLACIATE,
=======
        .battleAnimScript = gBattleAnimMove_Glaciate,
>>>>>>> upstream/master
    },

    [MOVE_BOLT_STRIKE] =
    {
        .name = COMPOUND_STRING("Bolt Strike"),
        .description = COMPOUND_STRING(
            "Strikes with a great amount\n"
            "of lightning. May paralyze."),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BOLT_STRIKE,
=======
        .battleAnimScript = gBattleAnimMove_BoltStrike,
>>>>>>> upstream/master
    },

    [MOVE_BLUE_FLARE] =
    {
        .name = COMPOUND_STRING("Blue Flare"),
        .description = COMPOUND_STRING(
            "Engulfs the foe in a blue\n"
            "flame. May inflict a burn."),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BLUE_FLARE,
=======
        .battleAnimScript = gBattleAnimMove_BlueFlare,
>>>>>>> upstream/master
    },

    [MOVE_FIERY_DANCE] =
    {
        .name = COMPOUND_STRING("Fiery Dance"),
        .description = COMPOUND_STRING(
            "Dances cloaked in flames.\n"
            "May raise Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FIERY_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_FieryDance,
>>>>>>> upstream/master
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .name = COMPOUND_STRING("Freeze Shock"),
        .description = COMPOUND_STRING(
            "A powerful 2-turn move that\n"
            "may paralyze the foe."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_CLOAKEDINAFREEZINGLIGHT),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FREEZE_SHOCK,
=======
        .battleAnimScript = gBattleAnimMove_FreezeShock,
>>>>>>> upstream/master
    },

    [MOVE_ICE_BURN] =
    {
        .name = COMPOUND_STRING("Ice Burn"),
        .description = COMPOUND_STRING(
            "A powerful 2-turn move that\n"
            "may inflict a burn."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_CLOAKEDINAFREEZINGLIGHT),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_BURN,
=======
        .battleAnimScript = gBattleAnimMove_IceBurn,
>>>>>>> upstream/master
    },

    [MOVE_SNARL] =
    {
        .name = COMPOUND_STRING("Snarl"),
        .description = COMPOUND_STRING(
            "Yells and rants at the foe\n"
            "lowering its Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SNARL,
=======
        .battleAnimScript = gBattleAnimMove_Snarl,
>>>>>>> upstream/master
    },

    [MOVE_ICICLE_CRASH] =
    {
        .name = COMPOUND_STRING("Icicle Crash"),
        .description = COMPOUND_STRING(
            "Drops large icicles on the\n"
            "foe. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ICICLE_CRASH,
=======
        .battleAnimScript = gBattleAnimMove_IcicleCrash,
>>>>>>> upstream/master
    },

    [MOVE_V_CREATE] =
    {
        .name = COMPOUND_STRING("V-create"),
        .description = COMPOUND_STRING(
            "Very powerful, but lowers\n"
            "Defense, Sp. Def and Speed."),
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 220 },
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_V_CREATE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_V_CREATE,
=======
        .battleAnimScript = gBattleAnimMove_VCreate,
>>>>>>> upstream/master
    },

    [MOVE_FUSION_FLARE] =
    {
        .name = COMPOUND_STRING("Fusion Flare"),
        .description = COMPOUND_STRING(
            "Summons a fireball. Works\n"
            "well with a thunderbolt."),
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FUSION_FLARE,
=======
        .battleAnimScript = gBattleAnimMove_FusionFlare,
>>>>>>> upstream/master
    },

    [MOVE_FUSION_BOLT] =
    {
        .name = COMPOUND_STRING("Fusion Bolt"),
        .description = COMPOUND_STRING(
            "Summons a thunderbolt.\n"
            "Works well with a fireball."),
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FUSION_BOLT,
=======
        .battleAnimScript = gBattleAnimMove_FusionBolt,
>>>>>>> upstream/master
    },

    [MOVE_FLYING_PRESS] =
    {
        .name = COMPOUND_STRING("Flying Press"),
        .description = COMPOUND_STRING(
            "This attack does Fighting\n"
            "and Flying-type damage."),
        .effect = EFFECT_TWO_TYPED_MOVE,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 100 : 80,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .zMove = { .powerOverride = 170 },
        .argument = TYPE_FLYING,
        .makesContact = TRUE,
        .minimizeDoubleDamage = TRUE,
        .gravityBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLYING_PRESS,
=======
        .battleAnimScript = gBattleAnimMove_FlyingPress,
>>>>>>> upstream/master
    },

    [MOVE_MAT_BLOCK] =
    {
        .name = COMPOUND_STRING("Mat Block"),
        .description = COMPOUND_STRING(
            "Evades damaging moves\n"
            "for one turn."),
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAT_BLOCK,
=======
        .battleAnimScript = gBattleAnimMove_MatBlock,
>>>>>>> upstream/master
    },

    [MOVE_BELCH] =
    {
        .name = COMPOUND_STRING("Belch"),
        .description = COMPOUND_STRING(
            "Lets out a loud belch.\n"
            "Must eat a Berry to use it."),
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BELCH,
=======
        .battleAnimScript = gBattleAnimMove_Belch,
>>>>>>> upstream/master
    },

    [MOVE_ROTOTILLER] =
    {
        .name = COMPOUND_STRING("Rototiller"),
        .description = COMPOUND_STRING(
            "Ups the Attack and Sp. Atk\n"
            "of Grass-type Pokémon."),
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ROTOTILLER,
=======
        .battleAnimScript = gBattleAnimMove_Rototiller,
>>>>>>> upstream/master
    },

    [MOVE_STICKY_WEB] =
    {
        .name = COMPOUND_STRING("Sticky Web"),
        .description = COMPOUND_STRING(
            "Weaves a sticky net that\n"
            "slows foes switching in."),
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .magicCoatAffected = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STICKY_WEB,
=======
        .battleAnimScript = gBattleAnimMove_StickyWeb,
>>>>>>> upstream/master
    },

    [MOVE_FELL_STINGER] =
    {
        .name = COMPOUND_STRING("Fell Stinger"),
        .description = COMPOUND_STRING(
            "If it knocks out a foe\n"
            "the Attack stat is raised."),
        .effect = EFFECT_FELL_STINGER,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 50 : 30,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FELL_STINGER,
=======
        .battleAnimScript = gBattleAnimMove_FellStinger,
>>>>>>> upstream/master
    },

    [MOVE_PHANTOM_FORCE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PhantomForce", "Phantom Force"),
=======
        .name = COMPOUND_STRING("Phantom Force"),
>>>>>>> upstream/master
        .description = sShadowForceDescription,
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .makesContact = TRUE,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS == GEN_6,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_VANISHEDINSTANTLY, COMPRESS_BITS(STATUS3_PHANTOM_FORCE)),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PHANTOM_FORCE,
=======
        .battleAnimScript = gBattleAnimMove_PhantomForce,
>>>>>>> upstream/master
    },

    [MOVE_TRICK_OR_TREAT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("TrickOrTreat", "Trick-or-Treat"),
=======
        .name = COMPOUND_STRING("Trick-or-Treat"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Goes trick-or-treating\n"
            "making the foe Ghost-type."),
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TYPE_GHOST,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TRICK_OR_TREAT,
=======
        .battleAnimScript = gBattleAnimMove_TrickOrTreat,
>>>>>>> upstream/master
    },

    [MOVE_NOBLE_ROAR] =
    {
        .name = COMPOUND_STRING("Noble Roar"),
        .description = COMPOUND_STRING(
            "Intimidates the foe, to cut\n"
            "Attack and Sp. Atk."),
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .magicCoatAffected = TRUE,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NOBLE_ROAR,
=======
        .battleAnimScript = gBattleAnimMove_NobleRoar,
>>>>>>> upstream/master
    },

    [MOVE_ION_DELUGE] =
    {
        .name = COMPOUND_STRING("Ion Deluge"),
        .description = COMPOUND_STRING(
            "Electrifies Normal-type\n"
            "moves with charged atoms."),
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ION_DELUGE,
=======
        .battleAnimScript = gBattleAnimMove_IonDeluge,
>>>>>>> upstream/master
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ParabolcChrg", "Parabolic Charge"),
=======
        .name = COMPOUND_STRING("Parabolic Charge"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Damages adjacent Pokémon\n"
            "and heals up by half of it."),
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 65 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PARABOLIC_CHARGE,
=======
        .battleAnimScript = gBattleAnimMove_ParabolicCharge,
>>>>>>> upstream/master
    },

    [MOVE_FORESTS_CURSE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("Forest'sCurs", "Forest's Curse"),
=======
        .name = COMPOUND_STRING("Forest's Curse"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Puts a curse on the foe\n"
            "making the foe Grass-type."),
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TYPE_GRASS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FORESTS_CURSE,
=======
        .battleAnimScript = gBattleAnimMove_ForestsCurse,
>>>>>>> upstream/master
    },

    [MOVE_PETAL_BLIZZARD] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PetalBlizzrd", "Petal Blizzard"),
=======
        .name = COMPOUND_STRING("Petal Blizzard"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Stirs up a violent storm\n"
            "of petals to attack."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PETAL_BLIZZARD,
=======
        .battleAnimScript = gBattleAnimMove_PetalBlizzard,
>>>>>>> upstream/master
    },

    [MOVE_FREEZE_DRY] =
    {
        .name = COMPOUND_STRING("Freeze-Dry"),
        .description = COMPOUND_STRING(
            "Super effective on Water-\n"
        #if B_USE_FROSTBITE == TRUE
            "types. May cause frostbite."),
        #else
            "types. May cause freezing."),
        #endif
        .effect = EFFECT_SUPER_EFFECTIVE_ON_ARG,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = TYPE_WATER,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FREEZE_DRY,
=======
        .battleAnimScript = gBattleAnimMove_FreezeDry,
>>>>>>> upstream/master
    },

    [MOVE_DISARMING_VOICE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DisrmngVoice", "Disarming Voice"),
=======
        .name = COMPOUND_STRING("Disarming Voice"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Lets out a charming cry\n"
            "that cannot be evaded."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DISARMING_VOICE,
=======
        .battleAnimScript = gBattleAnimMove_DisarmingVoice,
>>>>>>> upstream/master
    },

    [MOVE_PARTING_SHOT] =
    {
        .name = COMPOUND_STRING("Parting Shot"),
        .description = COMPOUND_STRING(
            "Lowers the foe's Attack and\n"
            "Sp. Atk, then switches out."),
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESTORE_REPLACEMENT_HP },
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PARTING_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_PartingShot,
>>>>>>> upstream/master
    },

    [MOVE_TOPSY_TURVY] =
    {
        .name = COMPOUND_STRING("Topsy-Turvy"),
        .description = COMPOUND_STRING(
            "Swaps all stat changes that\n"
            "affect the target."),
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_7 ? 0 : 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TOPSY_TURVY,
=======
        .battleAnimScript = gBattleAnimMove_TopsyTurvy,
>>>>>>> upstream/master
    },

    [MOVE_DRAINING_KISS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DrainingKiss", "Draining Kiss"),
=======
        .name = COMPOUND_STRING("Draining Kiss"),
>>>>>>> upstream/master
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
        .makesContact = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAINING_KISS,
=======
        .battleAnimScript = gBattleAnimMove_DrainingKiss,
>>>>>>> upstream/master
    },

    [MOVE_CRAFTY_SHIELD] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("CraftyShield", "Crafty Shield"),
=======
        .name = COMPOUND_STRING("Crafty Shield"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Evades status moves for\n"
            "one turn."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CRAFTY_SHIELD,
=======
        .battleAnimScript = gBattleAnimMove_CraftyShield,
>>>>>>> upstream/master
    },

    [MOVE_FLOWER_SHIELD] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FlowerShield", "Flower Shield"),
=======
        .name = COMPOUND_STRING("Flower Shield"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Raises the Defense of\n"
            "Grass-type Pokémon."),
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
<<<<<<< HEAD
        .target = MOVE_TARGET_ALL_BATTLERS,
=======
        .target = MOVE_TARGET_USER, // The targeting of Flower Shield is handled through a script
>>>>>>> upstream/master
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLOWER_SHIELD,
=======
        .battleAnimScript = gBattleAnimMove_FlowerShield,
>>>>>>> upstream/master
    },

    [MOVE_GRASSY_TERRAIN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("GrssyTerrain", "Grassy Terrain"),
=======
        .name = COMPOUND_STRING("Grassy Terrain"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "The ground turns to grass\n"
            "for 5 turns. Restores HP."),
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_GRASSY_TERRAIN,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GRASSY_TERRAIN,
=======
        .battleAnimScript = gBattleAnimMove_GrassyTerrain,
>>>>>>> upstream/master
    },

    [MOVE_MISTY_TERRAIN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MistyTerrain", "Misty Terrain"),
=======
        .name = COMPOUND_STRING("Misty Terrain"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Covers the ground with mist\n"
            "for 5 turns. Blocks status."),
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = COMBO_STARTER_MISTY_TERRAIN,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MISTY_TERRAIN,
=======
        .battleAnimScript = gBattleAnimMove_MistyTerrain,
>>>>>>> upstream/master
    },

    [MOVE_ELECTRIFY] =
    {
        .name = COMPOUND_STRING("Electrify"),
        .description = COMPOUND_STRING(
            "Electrifies the foe, making\n"
            "its next move Electric-type."),
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ELECTRIFY,
=======
        .battleAnimScript = gBattleAnimMove_Electrify,
>>>>>>> upstream/master
    },

    [MOVE_PLAY_ROUGH] =
    {
        .name = COMPOUND_STRING("Play Rough"),
        .description = COMPOUND_STRING(
            "Plays rough with the foe.\n"
            "May lower Attack."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PLAY_ROUGH,
=======
        .battleAnimScript = gBattleAnimMove_PlayRough,
>>>>>>> upstream/master
    },

    [MOVE_FAIRY_WIND] =
    {
        .name = COMPOUND_STRING("Fairy Wind"),
        .description = COMPOUND_STRING(
            "Stirs up a fairy wind to\n"
            "strike the foe."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FAIRY_WIND,
=======
        .battleAnimScript = gBattleAnimMove_FairyWind,
>>>>>>> upstream/master
    },

    [MOVE_MOONBLAST] =
    {
        .name = COMPOUND_STRING("Moonblast"),
        .description = COMPOUND_STRING(
            "Attacks with the power of\n"
            "the moon. May lower Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MOONBLAST,
=======
        .battleAnimScript = gBattleAnimMove_Moonblast,
>>>>>>> upstream/master
    },

    [MOVE_BOOMBURST] =
    {
        .name = COMPOUND_STRING("Boomburst"),
        .description = COMPOUND_STRING(
            "Attacks everything with a\n"
            "destructive sound wave."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BOOMBURST,
=======
        .battleAnimScript = gBattleAnimMove_Boomburst,
>>>>>>> upstream/master
    },

    [MOVE_FAIRY_LOCK] =
    {
        .name = COMPOUND_STRING("Fairy Lock"),
        .description = COMPOUND_STRING(
            "Locks down the battlefield\n"
            "preventing escape next turn."),
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FAIRY_LOCK,
=======
        .battleAnimScript = gBattleAnimMove_FairyLock,
>>>>>>> upstream/master
    },

    [MOVE_KINGS_SHIELD] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("King'sShield", "King's Shield"),
=======
        .name = COMPOUND_STRING("King's Shield"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Evades damage, and sharply\n"
            "reduces Attack if struck."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_KINGS_SHIELD,
=======
        .battleAnimScript = gBattleAnimMove_KingsShield,
>>>>>>> upstream/master
    },

    [MOVE_PLAY_NICE] =
    {
        .name = COMPOUND_STRING("Play Nice"),
        .description = COMPOUND_STRING(
            "Befriend the foe, lowering\n"
            "its Attack without fail."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PLAY_NICE,
=======
        .battleAnimScript = gBattleAnimMove_PlayNice,
>>>>>>> upstream/master
    },

    [MOVE_CONFIDE] =
    {
        .name = COMPOUND_STRING("Confide"),
        .description = COMPOUND_STRING(
            "Shares a secret with the\n"
            "foe, lowering Sp. Atk."),
        .effect = EFFECT_SPECIAL_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CONFIDE,
=======
        .battleAnimScript = gBattleAnimMove_Confide,
>>>>>>> upstream/master
    },

    [MOVE_DIAMOND_STORM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DiamondStorm", "Diamond Storm"),
=======
        .name = COMPOUND_STRING("Diamond Storm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Whips up a storm of\n"
            "diamonds. May up Defense."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = B_UPDATED_MOVE_DATA >= GEN_7 ? MOVE_EFFECT_DEF_PLUS_2:  MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 50,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DIAMOND_STORM,
=======
        .battleAnimScript = gBattleAnimMove_DiamondStorm,
>>>>>>> upstream/master
    },

    [MOVE_STEAM_ERUPTION] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SteamErption", "Steam Eruption"),
=======
        .name = COMPOUND_STRING("Steam Eruption"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Immerses the foe in heated\n"
            "steam. May inflict a burn."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
<<<<<<< HEAD
        .battleAnimScript = Move_STEAM_ERUPTION,
=======
        .battleAnimScript = gBattleAnimMove_SteamEruption,
>>>>>>> upstream/master
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("HyprspceHole", "Hyperspace Hole"),
=======
        .name = COMPOUND_STRING("Hyperspace Hole"),
>>>>>>> upstream/master
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FEINT,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_HOLE,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_FURY},
<<<<<<< HEAD
        .battleAnimScript = Move_HYPERSPACE_HOLE,
=======
        .battleAnimScript = gBattleAnimMove_HyperspaceHole,
>>>>>>> upstream/master
    },

    [MOVE_WATER_SHURIKEN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("WatrShuriken", "Water Shuriken"),
=======
        .name = COMPOUND_STRING("Water Shuriken"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Throws 2 to 5 stars that\n"
            "are sure to strike first."),
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = B_UPDATED_MOVE_DATA >= GEN_7 ? DAMAGE_CATEGORY_SPECIAL : DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WATER_SHURIKEN,
=======
        .battleAnimScript = gBattleAnimMove_WaterShuriken,
>>>>>>> upstream/master
    },

    [MOVE_MYSTICAL_FIRE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MysticalFire", "Mystical Fire"),
=======
        .name = COMPOUND_STRING("Mystical Fire"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Breathes a special, hot\n"
            "fire. Lowers Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_7 ? 75 : 65,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MYSTICAL_FIRE,
=======
        .battleAnimScript = gBattleAnimMove_MysticalFire,
>>>>>>> upstream/master
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .name = COMPOUND_STRING("Spiky Shield"),
        .description = COMPOUND_STRING(
            "Evades attack, and damages\n"
            "the foe if struck."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIKY_SHIELD,
=======
        .battleAnimScript = gBattleAnimMove_SpikyShield,
>>>>>>> upstream/master
    },

    [MOVE_AROMATIC_MIST] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("AromaticMist", "Aromatic Mist"),
=======
        .name = COMPOUND_STRING("Aromatic Mist"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Raises the Sp. Def of a\n"
            "partner Pokémon."),
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AROMATIC_MIST,
=======
        .battleAnimScript = gBattleAnimMove_AromaticMist,
>>>>>>> upstream/master
    },

    [MOVE_EERIE_IMPULSE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("EerieImpulse", "Eerie Impulse"),
=======
        .name = COMPOUND_STRING("Eerie Impulse"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Exposes the foe to a pulse\n"
            "that sharply cuts Sp. Atk."),
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EERIE_IMPULSE,
=======
        .battleAnimScript = gBattleAnimMove_EerieImpulse,
>>>>>>> upstream/master
    },

    [MOVE_VENOM_DRENCH] =
    {
        .name = COMPOUND_STRING("Venom Drench"),
        .description = COMPOUND_STRING(
            "Lowers the Attack, Sp. Atk\n"
            "and Speed of a poisoned foe."),
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
<<<<<<< HEAD
        .battleAnimScript = Move_VENOM_DRENCH,
=======
        .battleAnimScript = gBattleAnimMove_VenomDrench,
>>>>>>> upstream/master
    },

    [MOVE_POWDER] =
    {
        .name = COMPOUND_STRING("Powder"),
        .description = COMPOUND_STRING(
            "Damages the foe if it uses\n"
            "a Fire-type move."),
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_2 },
        .powderMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWDER,
=======
        .battleAnimScript = gBattleAnimMove_Powder,
>>>>>>> upstream/master
    },

    [MOVE_GEOMANCY] =
    {
        .name = COMPOUND_STRING("Geomancy"),
        .description = COMPOUND_STRING(
            "Raises Sp. Atk, Sp. Def and\n"
            "Speed on the 2nd turn."),
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .skyBattleBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKNMABSORBINGPOWER),
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GEOMANCY,
=======
        .battleAnimScript = gBattleAnimMove_Geomancy,
>>>>>>> upstream/master
    },

    [MOVE_MAGNETIC_FLUX] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MagneticFlux", "Magnetic Flux"),
=======
        .name = COMPOUND_STRING("Magnetic Flux"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Boosts the defenses of\n"
            "those with Plus or Minus."),
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGNETIC_FLUX,
=======
        .battleAnimScript = gBattleAnimMove_MagneticFlux,
>>>>>>> upstream/master
    },

    [MOVE_HAPPY_HOUR] =
    {
        .name = COMPOUND_STRING("Happy Hour"),
        .description = COMPOUND_STRING(
            "Doubles the amount of\n"
            "Prize Money received."),
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HAPPY_HOUR,
=======
        .battleAnimScript = gBattleAnimMove_HappyHour,
>>>>>>> upstream/master
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ElctrcTrrain", "Electric Terrain"),
=======
        .name = COMPOUND_STRING("Electric Terrain"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Electrifies the ground for\n"
            "5 turns. Prevents sleep."),
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = COMBO_STARTER_ELECTRIC_TERRAIN,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ELECTRIC_TERRAIN,
=======
        .battleAnimScript = gBattleAnimMove_ElectricTerrain,
>>>>>>> upstream/master
    },

    [MOVE_DAZZLING_GLEAM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DazzlngGleam", "Dazzling Gleam"),
=======
        .name = COMPOUND_STRING("Dazzling Gleam"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Damages foes by emitting\n"
            "a bright flash."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DAZZLING_GLEAM,
=======
        .battleAnimScript = gBattleAnimMove_DazzlingGleam,
>>>>>>> upstream/master
    },

    [MOVE_CELEBRATE] =
    {
        .name = COMPOUND_STRING("Celebrate"),
        .description = COMPOUND_STRING(
            "Congratulates you on your\n"
            "special day."),
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CELEBRATE,
=======
        .battleAnimScript = gBattleAnimMove_Celebrate,
>>>>>>> upstream/master
    },

    [MOVE_HOLD_HANDS] =
    {
        .name = COMPOUND_STRING("Hold Hands"),
        .description = COMPOUND_STRING(
            "The user and ally hold hands\n"
            "making them happy."),
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .mimicBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HOLD_HANDS,
=======
        .battleAnimScript = gBattleAnimMove_HoldHands,
>>>>>>> upstream/master
    },

    [MOVE_BABY_DOLL_EYES] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BabyDollEyes", "Baby-Doll Eyes"),
=======
        .name = COMPOUND_STRING("Baby-Doll Eyes"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Lowers the foe's Attack\n"
            "before it can move."),
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BABY_DOLL_EYES,
=======
        .battleAnimScript = gBattleAnimMove_BabyDollEyes,
>>>>>>> upstream/master
    },

    [MOVE_NUZZLE] =
    {
        .name = COMPOUND_STRING("Nuzzle"),
        .description = COMPOUND_STRING(
            "Rubs its cheecks against\n"
            "the foe, paralyzing it."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NUZZLE,
=======
        .battleAnimScript = gBattleAnimMove_Nuzzle,
>>>>>>> upstream/master
    },

    [MOVE_HOLD_BACK] =
    {
        .name = COMPOUND_STRING("Hold Back"),
        .description = sFalseSwipeDescription,
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HOLD_BACK,
=======
        .battleAnimScript = gBattleAnimMove_HoldBack,
>>>>>>> upstream/master
    },

    [MOVE_INFESTATION] =
    {
        .name = COMPOUND_STRING("Infestation"),
        .description = COMPOUND_STRING(
            "The foe is infested and\n"
            "attacked for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_INFESTATION,
=======
        .battleAnimScript = gBattleAnimMove_Infestation,
>>>>>>> upstream/master
    },

    [MOVE_POWER_UP_PUNCH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PowerUpPunch", "Power-Up Punch"),
=======
        .name = COMPOUND_STRING("Power-Up Punch"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A hard punch that raises\n"
            "the user's Attack."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_UP_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_PowerUpPunch,
>>>>>>> upstream/master
    },

    [MOVE_OBLIVION_WING] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("OblivionWing", "Oblivion Wing"),
=======
        .name = COMPOUND_STRING("Oblivion Wing"),
>>>>>>> upstream/master
        .description = sDrainingKissDescription,
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_OBLIVION_WING,
=======
        .battleAnimScript = gBattleAnimMove_OblivionWing,
>>>>>>> upstream/master
    },

    [MOVE_THOUSAND_ARROWS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ThousndArrws", "Thousand Arrows"),
=======
        .name = COMPOUND_STRING("Thousand Arrows"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Can hit Flying foes, then\n"
            "knocks them to the ground."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .damagesAirborne = TRUE,
        .ignoreTypeIfFlyingAndUngrounded = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SMACK_DOWN,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_ARROWS,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_WAVES},
<<<<<<< HEAD
        .battleAnimScript = Move_THOUSAND_ARROWS,
=======
        .battleAnimScript = gBattleAnimMove_ThousandArrows,
>>>>>>> upstream/master
    },

    [MOVE_THOUSAND_WAVES] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ThousndWaves", "Thousand Waves"),
=======
        .name = COMPOUND_STRING("Thousand Waves"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Those hit by the wave can\n"
            "no longer escape."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .skyBattleBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_THOUSAND_WAVES,
        .contestComboMoves = {COMBO_STARTER_THOUSAND_ARROWS},
<<<<<<< HEAD
        .battleAnimScript = Move_THOUSAND_WAVES,
=======
        .battleAnimScript = gBattleAnimMove_ThousandWaves,
>>>>>>> upstream/master
    },

    [MOVE_LANDS_WRATH] =
    {
        .name = COMPOUND_STRING("Land's Wrath"),
        .description = COMPOUND_STRING(
            "Gathers the energy of the\n"
            "land to attack every foe."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LANDS_WRATH,
=======
        .battleAnimScript = gBattleAnimMove_LandsWrath,
>>>>>>> upstream/master
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("LightOfRuin", "Light Of Ruin"),
=======
        .name = COMPOUND_STRING("Light Of Ruin"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Fires a great beam of light\n"
            "that also hurts the user."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .recoil = 50,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_LIGHT_OF_RUIN,
=======
        .battleAnimScript = gBattleAnimMove_LightOfRuin,
>>>>>>> upstream/master
    },

    [MOVE_ORIGIN_PULSE] =
    {
        .name = COMPOUND_STRING("Origin Pulse"),
        .description = COMPOUND_STRING(
            "Beams of glowing blue light\n"
            "blast both foes."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ORIGIN_PULSE,
=======
        .battleAnimScript = gBattleAnimMove_OriginPulse,
>>>>>>> upstream/master
    },

    [MOVE_PRECIPICE_BLADES] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PrcipceBldes", "Precipice Blades"),
=======
        .name = COMPOUND_STRING("Precipice Blades"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Fearsome blades of stone\n"
            "attack both foes."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PRECIPICE_BLADES,
=======
        .battleAnimScript = gBattleAnimMove_PrecipiceBlades,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_ASCENT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DragonAscent", "Dragon Ascent"),
=======
        .name = COMPOUND_STRING("Dragon Ascent"),
>>>>>>> upstream/master
        .description = sCloseCombatDescription,
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_ASCENT,
=======
        .battleAnimScript = gBattleAnimMove_DragonAscent,
>>>>>>> upstream/master
    },

    [MOVE_HYPERSPACE_FURY] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("HyprspceFury", "Hyperspace Fury"),
=======
        .name = COMPOUND_STRING("Hyperspace Fury"),
>>>>>>> upstream/master
        .description = sHyperspaceHoleDescription,
        .effect = EFFECT_HYPERSPACE_FURY,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .metronomeBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            // Feint move effect handled in script as it goes before animation
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_HYPERSPACE_FURY,
        .contestComboMoves = {COMBO_STARTER_HYPERSPACE_HOLE},
<<<<<<< HEAD
        .battleAnimScript = Move_HYPERSPACE_FURY,
=======
        .battleAnimScript = gBattleAnimMove_HyperspaceFury,
>>>>>>> upstream/master
    },

    [MOVE_SHORE_UP] =
    {
        .name = COMPOUND_STRING("Shore Up"),
        .description = COMPOUND_STRING(
            "Restores the user's HP.\n"
            "More HP in a sandstorm."),
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 5 : 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .healingMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SANDSTORM},
<<<<<<< HEAD
        .battleAnimScript = Move_SHORE_UP,
=======
        .battleAnimScript = gBattleAnimMove_ShoreUp,
>>>>>>> upstream/master
    },

    [MOVE_FIRST_IMPRESSION] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FrstImpressn", "First Impression"),
=======
        .name = COMPOUND_STRING("First Impression"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits hard and first.\n"
            "Only works first turn."),
        .effect = EFFECT_FIRST_TURN_ONLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MOVE_FIRST_IMPRESSION,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRST_IMPRESSION,
=======
        .battleAnimScript = gBattleAnimMove_FirstImpression,
>>>>>>> upstream/master
    },

    [MOVE_BANEFUL_BUNKER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BanefulBunkr", "Baneful Bunker"),
=======
        .name = COMPOUND_STRING("Baneful Bunker"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Protects user and poisons\n"
            "foes on contact."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BANEFUL_BUNKER,
=======
        .battleAnimScript = gBattleAnimMove_BanefulBunker,
>>>>>>> upstream/master
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SpiritShackl", "Spirit Shackle"),
=======
        .name = COMPOUND_STRING("Spirit Shackle"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "After being hit, foes can\n"
            "no longer escape."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIRIT_SHACKLE,
=======
        .battleAnimScript = gBattleAnimMove_SpiritShackle,
>>>>>>> upstream/master
    },

    [MOVE_DARKEST_LARIAT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DarkstLariat", "Darkest Lariat"),
=======
        .name = COMPOUND_STRING("Darkest Lariat"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Swings the arms to strike\n"
            "It ignores stat changes."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetDefenseEvasionStages = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DARKEST_LARIAT,
=======
        .battleAnimScript = gBattleAnimMove_DarkestLariat,
>>>>>>> upstream/master
    },

    [MOVE_SPARKLING_ARIA] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SparklngAria", "Sparkling Aria"),
=======
        .name = COMPOUND_STRING("Sparkling Aria"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Sings with bubbles. Cures\n"
            "burns on contact."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = STATUS1_BURN,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_STATUS,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SCALD},
<<<<<<< HEAD
        .battleAnimScript = Move_SPARKLING_ARIA,
=======
        .battleAnimScript = gBattleAnimMove_SparklingAria,
>>>>>>> upstream/master
    },

    [MOVE_ICE_HAMMER] =
    {
        .name = COMPOUND_STRING("Ice Hammer"),
        .description = COMPOUND_STRING(
            "Swings the fist to strike.\n"
            "Lowers the user's Speed."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_HAMMER,
=======
        .battleAnimScript = gBattleAnimMove_IceHammer,
>>>>>>> upstream/master
    },

    [MOVE_FLORAL_HEALING] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FloralHealng", "Floral Healing"),
=======
        .name = COMPOUND_STRING("Floral Healing"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Restores an ally's HP.\n"
            "Heals more on grass."),
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .argument = MOVE_EFFECT_FLORAL_HEALING,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLORAL_HEALING,
=======
        .battleAnimScript = gBattleAnimMove_FloralHealing,
>>>>>>> upstream/master
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("HighHorsepwr", "High Horsepower"),
=======
        .name = COMPOUND_STRING("High Horsepower"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Slams hard into the foe with\n"
            "its entire body."),
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_HIGH_HORSEPOWER,
=======
        .battleAnimScript = gBattleAnimMove_HighHorsepower,
>>>>>>> upstream/master
    },

    [MOVE_STRENGTH_SAP] =
    {
        .name = COMPOUND_STRING("Strength Sap"),
        .description = COMPOUND_STRING(
            "Saps the foe's Attack to\n"
            "heal HP, then drops Attack."),
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .magicCoatAffected = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STRENGTH_SAP,
=======
        .battleAnimScript = gBattleAnimMove_StrengthSap,
>>>>>>> upstream/master
    },

    [MOVE_SOLAR_BLADE] =
    {
        .name = COMPOUND_STRING("Solar Blade"),
        .description = COMPOUND_STRING(
            "Charges first turn, then\n"
            "chops with a blade of light."),
        .effect = EFFECT_SOLAR_BEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_PKMNTOOKSUNLIGHT, B_WEATHER_SUN),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_SOLAR_BLADE,
=======
        .battleAnimScript = gBattleAnimMove_SolarBlade,
>>>>>>> upstream/master
    },

    [MOVE_LEAFAGE] =
    {
        .name = COMPOUND_STRING("Leafage"),
        .description = COMPOUND_STRING(
            "Attacks with a flurry of\n"
            "small leaves."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GROWTH},
<<<<<<< HEAD
        .battleAnimScript = Move_LEAFAGE,
=======
        .battleAnimScript = gBattleAnimMove_Leafage,
>>>>>>> upstream/master
    },

    [MOVE_SPOTLIGHT] =
    {
        .name = COMPOUND_STRING("Spotlight"),
        .description = COMPOUND_STRING(
            "Makes the foe attack the\n"
            "spotlighted Pokémon."),
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPDEF_UP_1 },
        .magicCoatAffected = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPOTLIGHT,
=======
        .battleAnimScript = gBattleAnimMove_Spotlight,
>>>>>>> upstream/master
    },

    [MOVE_TOXIC_THREAD] =
    {
        .name = COMPOUND_STRING("Toxic Thread"),
        .description = COMPOUND_STRING(
            "Attacks with a thread that\n"
            "poisons and drops Speed."),
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_TOXIC},
<<<<<<< HEAD
        .battleAnimScript = Move_TOXIC_THREAD,
=======
        .battleAnimScript = gBattleAnimMove_ToxicThread,
>>>>>>> upstream/master
    },

    [MOVE_LASER_FOCUS] =
    {
        .name = COMPOUND_STRING("Laser Focus"),
        .description = COMPOUND_STRING(
            "Guarantees the next move\n"
            "will be a critical hit."),
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LASER_FOCUS,
=======
        .battleAnimScript = gBattleAnimMove_LaserFocus,
>>>>>>> upstream/master
    },

    [MOVE_GEAR_UP] =
    {
        .name = COMPOUND_STRING("Gear Up"),
        .description = COMPOUND_STRING(
            "Boosts the attacks of\n"
            "those with Plus or Minus."),
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GEAR_UP,
=======
        .battleAnimScript = gBattleAnimMove_GearUp,
>>>>>>> upstream/master
    },

    [MOVE_THROAT_CHOP] =
    {
        .name = COMPOUND_STRING("Throat Chop"),
        .description = COMPOUND_STRING(
            "Chops the throat to disable\n"
            "sound moves for a while."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THROAT_CHOP,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_THROAT_CHOP,
=======
        .battleAnimScript = gBattleAnimMove_ThroatChop,
>>>>>>> upstream/master
    },

    [MOVE_POLLEN_PUFF] =
    {
        .name = COMPOUND_STRING("Pollen Puff"),
        .description = COMPOUND_STRING(
            "Explodes on foes, but\n"
            "restores ally's HP."),
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POLLEN_PUFF,
=======
        .battleAnimScript = gBattleAnimMove_PollenPuff,
>>>>>>> upstream/master
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .name = COMPOUND_STRING("Anchor Shot"),
        .description = COMPOUND_STRING(
            "Strangles the foe with a\n"
            "chain. The foe can't escape."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PREVENT_ESCAPE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ANCHOR_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_AnchorShot,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PsychcTrrain", "Psychic Terrain"),
=======
        .name = COMPOUND_STRING("Psychic Terrain"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "The ground turns weird for\n"
            "5 turns. Blocks priority."),
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = COMBO_STARTER_PSYCHIC_TERRAIN,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHIC_TERRAIN,
=======
        .battleAnimScript = gBattleAnimMove_PsychicTerrain,
>>>>>>> upstream/master
    },

    [MOVE_LUNGE] =
    {
        .name = COMPOUND_STRING("Lunge"),
        .description = COMPOUND_STRING(
            "Lunges at the foe to lower\n"
            "its Attack stat."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LUNGE,
=======
        .battleAnimScript = gBattleAnimMove_Lunge,
>>>>>>> upstream/master
    },

    [MOVE_FIRE_LASH] =
    {
        .name = COMPOUND_STRING("Fire Lash"),
        .description = COMPOUND_STRING(
            "Whips the foe with fire\n"
            "lowering its Defense."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_FIRE_LASH,
=======
        .battleAnimScript = gBattleAnimMove_FireLash,
>>>>>>> upstream/master
    },

    [MOVE_POWER_TRIP] =
    {
        .name = COMPOUND_STRING("Power Trip"),
        .description = COMPOUND_STRING(
            "It hits harder the more\n"
            "stat boosts the user has."),
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_TRIP,
=======
        .battleAnimScript = gBattleAnimMove_PowerTrip,
>>>>>>> upstream/master
    },

    [MOVE_BURN_UP] =
    {
        .name = COMPOUND_STRING("Burn Up"),
        .description = COMPOUND_STRING(
            "Burns out the user fully\n"
            "removing the Fire type."),
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .argument = TYPE_FIRE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_SUNNY_DAY},
<<<<<<< HEAD
        .battleAnimScript = Move_BURN_UP,
=======
        .battleAnimScript = gBattleAnimMove_BurnUp,
>>>>>>> upstream/master
    },

    [MOVE_SPEED_SWAP] =
    {
        .name = COMPOUND_STRING("Speed Swap"),
        .description = COMPOUND_STRING(
            "Swaps user's Speed with\n"
            "the target's."),
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresSubstitute = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPEED_SWAP,
=======
        .battleAnimScript = gBattleAnimMove_SpeedSwap,
>>>>>>> upstream/master
    },

    [MOVE_SMART_STRIKE] =
    {
        .name = COMPOUND_STRING("Smart Strike"),
        .description = COMPOUND_STRING(
            "Hits with an accurate\n"
            "horn that never misses."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SMART_STRIKE,
=======
        .battleAnimScript = gBattleAnimMove_SmartStrike,
>>>>>>> upstream/master
    },

    [MOVE_PURIFY] =
    {
        .name = COMPOUND_STRING("Purify"),
        .description = COMPOUND_STRING(
            "Cures the foe's status\n"
            "to restore HP."),
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_ALL_STATS_UP_1 },
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PURIFY,
=======
        .battleAnimScript = gBattleAnimMove_Purify,
>>>>>>> upstream/master
    },

    [MOVE_REVELATION_DANCE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("RvlationDnce", "Revelation Dance"),
=======
        .name = COMPOUND_STRING("Revelation Dance"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Dances with mystical power.\n"
            "Matches user's first type."),
        .effect = EFFECT_REVELATION_DANCE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .danceMove = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_REVELATION_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_RevelationDance,
>>>>>>> upstream/master
    },

    [MOVE_CORE_ENFORCER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("CoreEnforcer", "Core Enforcer"),
=======
        .name = COMPOUND_STRING("Core Enforcer"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits with a ray that\n"
            "nullifies the foe's ability."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .zMove = { .powerOverride = 140 },
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CORE_ENFORCER,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CORE_ENFORCER,
=======
        .battleAnimScript = gBattleAnimMove_CoreEnforcer,
>>>>>>> upstream/master
    },

    [MOVE_TROP_KICK] =
    {
        .name = COMPOUND_STRING("Trop Kick"),
        .description = COMPOUND_STRING(
            "An intense kick from the\n"
            "tropics. Lowers Attack."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TROP_KICK,
=======
        .battleAnimScript = gBattleAnimMove_TropKick,
>>>>>>> upstream/master
    },

    [MOVE_INSTRUCT] =
    {
        .name = COMPOUND_STRING("Instruct"),
        .description = COMPOUND_STRING(
            "Orders the target to use\n"
            "its last move again."),
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPATK_UP_1 },
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_INSTRUCT,
=======
        .battleAnimScript = gBattleAnimMove_Instruct,
>>>>>>> upstream/master
    },

    [MOVE_BEAK_BLAST] =
    {
        .name = COMPOUND_STRING("Beak Blast"),
        .description = COMPOUND_STRING(
            "Heats up beak to attack.\n"
            "Burns foe on contact."),
        .effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .ballisticMove = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BEAK_BLAST,
=======
        .battleAnimScript = gBattleAnimMove_BeakBlast,
>>>>>>> upstream/master
    },

    [MOVE_CLANGING_SCALES] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ClngngScales", "Clanging Scales"),
=======
        .name = COMPOUND_STRING("Clanging Scales"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Makes a big noise with\n"
            "its scales. Drops Defense."),
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .soundMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CLANGING_SCALES,
=======
        .battleAnimScript = gBattleAnimMove_ClangingScales,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_HAMMER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DragonHammer", "Dragon Hammer"),
=======
        .name = COMPOUND_STRING("Dragon Hammer"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Swings its whole body\n"
            "like a hammer to damage."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_HAMMER,
=======
        .battleAnimScript = gBattleAnimMove_DragonHammer,
>>>>>>> upstream/master
    },

    [MOVE_BRUTAL_SWING] =
    {
        .name = COMPOUND_STRING("Brutal Swing"),
        .description = COMPOUND_STRING(
            "Violently swings around\n"
            "to hurt everyone nearby."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BRUTAL_SWING,
=======
        .battleAnimScript = gBattleAnimMove_BrutalSwing,
>>>>>>> upstream/master
    },

    [MOVE_AURORA_VEIL] =
    {
        .name = COMPOUND_STRING("Aurora Veil"),
        .description = COMPOUND_STRING(
            "Weakens all attacks, but\n"
            "only usable with hail."),
        .effect = EFFECT_AURORA_VEIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_HAIL},
<<<<<<< HEAD
        .battleAnimScript = Move_AURORA_VEIL,
=======
        .battleAnimScript = gBattleAnimMove_AuroraVeil,
>>>>>>> upstream/master
    },

    [MOVE_SHELL_TRAP] =
    {
        .name = COMPOUND_STRING("Shell Trap"),
        .description = COMPOUND_STRING(
            "Sets a shell trap that\n"
            "damages on contact."),
        .effect = EFFECT_SHELL_TRAP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = -3,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .assistBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHELL_TRAP,
=======
        .battleAnimScript = gBattleAnimMove_ShellTrap,
>>>>>>> upstream/master
    },

    [MOVE_FLEUR_CANNON] =
    {
        .name = COMPOUND_STRING("Fleur Cannon"),
        .description = COMPOUND_STRING(
            "A strong ray that harshly\n"
            "lowers Sp. Attack."),
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_2,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLEUR_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_FleurCannon,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHIC_FANGS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PsychicFangs", "Psychic Fangs"),
=======
        .name = COMPOUND_STRING("Psychic Fangs"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Chomps with psychic fangs.\n"
            "Destroys any barriers."),
        .effect = EFFECT_BRICK_BREAK,
        .power = 85,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHIC_FANGS,
=======
        .battleAnimScript = gBattleAnimMove_PsychicFangs,
>>>>>>> upstream/master
    },

    [MOVE_STOMPING_TANTRUM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("StmpngTantrm", "Stomping Tantrum"),
=======
        .name = COMPOUND_STRING("Stomping Tantrum"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Stomps around angrily.\n"
            "Stronger after a failure."),
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STOMPING_TANTRUM,
=======
        .battleAnimScript = gBattleAnimMove_StompingTantrum,
>>>>>>> upstream/master
    },

    [MOVE_SHADOW_BONE] =
    {
        .name = COMPOUND_STRING("Shadow Bone"),
        .description = COMPOUND_STRING(
            "Strikes with a haunted\n"
            "bone. Might drop Defense."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = COMBO_STARTER_SHADOW_BONE,
        .contestComboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH},
<<<<<<< HEAD
        .battleAnimScript = Move_SHADOW_BONE,
=======
        .battleAnimScript = gBattleAnimMove_ShadowBone,
>>>>>>> upstream/master
    },

    [MOVE_ACCELEROCK] =
    {
        .name = COMPOUND_STRING("Accelerock"),
        .description = COMPOUND_STRING(
            "Hits with a high-speed\n"
            "rock that always goes first."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ACCELEROCK,
=======
        .battleAnimScript = gBattleAnimMove_Accelerock,
>>>>>>> upstream/master
    },

    [MOVE_LIQUIDATION] =
    {
        .name = COMPOUND_STRING("Liquidation"),
        .description = COMPOUND_STRING(
            "Slams the foe with water.\n"
            "Can lower Defense."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_RAIN_DANCE},
<<<<<<< HEAD
        .battleAnimScript = Move_LIQUIDATION,
=======
        .battleAnimScript = gBattleAnimMove_Liquidation,
>>>>>>> upstream/master
    },

    [MOVE_PRISMATIC_LASER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PrsmaticLasr", "Prismatic Laser"),
=======
        .name = COMPOUND_STRING("Prismatic Laser"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A high power laser that\n"
            "forces recharge next turn."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PRISMATIC_LASER,
=======
        .battleAnimScript = gBattleAnimMove_PrismaticLaser,
>>>>>>> upstream/master
    },

    [MOVE_SPECTRAL_THIEF] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SpectrlThief", "Spectral Thief"),
=======
        .name = COMPOUND_STRING("Spectral Thief"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Steals the target's stat\n"
            "boosts, then attacks."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresSubstitute = TRUE,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPECTRAL_THIEF,
        }),
        .contestEffect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPECTRAL_THIEF,
=======
        .battleAnimScript = gBattleAnimMove_SpectralThief,
>>>>>>> upstream/master
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SnsteelStrke", "Sunsteel Strike"),
=======
        .name = COMPOUND_STRING("Sunsteel Strike"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A sun-fueled strike that\n"
            "ignores abilities."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SUNSTEEL_STRIKE,
=======
        .battleAnimScript = gBattleAnimMove_SunsteelStrike,
>>>>>>> upstream/master
    },

    [MOVE_MOONGEIST_BEAM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MoongestBeam", "Moongeist Beam"),
=======
        .name = COMPOUND_STRING("Moongeist Beam"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A moon-powered beam that\n"
            "ignores abilities."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MOONGEIST_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_MoongeistBeam,
>>>>>>> upstream/master
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .name = COMPOUND_STRING("Tearful Look"),
        .description = COMPOUND_STRING(
            "The user tears up, dropping\n"
            "Attack and Sp. Attack."),
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_DEF_UP_1 },
        .ignoresProtect = TRUE,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TEARFUL_LOOK,
=======
        .battleAnimScript = gBattleAnimMove_TearfulLook,
>>>>>>> upstream/master
    },

    [MOVE_ZING_ZAP] =
    {
        .name = COMPOUND_STRING("Zing Zap"),
        .description = COMPOUND_STRING(
            "An electrified impact that\n"
            "can cause flinching."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_CHARGE},
<<<<<<< HEAD
        .battleAnimScript = Move_ZING_ZAP,
=======
        .battleAnimScript = gBattleAnimMove_ZingZap,
>>>>>>> upstream/master
    },

    [MOVE_NATURES_MADNESS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("Natur'sMadns", "Nature's Madness"),
=======
        .name = COMPOUND_STRING("Nature's Madness"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Halves the foe's HP with\n"
            "the power of nature."),
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = B_UPDATED_MOVE_FLAGS >= GEN_8,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NATURES_MADNESS,
=======
        .battleAnimScript = gBattleAnimMove_NaturesMadness,
>>>>>>> upstream/master
    },

    [MOVE_MULTI_ATTACK] =
    {
        .name = COMPOUND_STRING("Multi-Attack"),
        .description = COMPOUND_STRING(
            "An attack that changes\n"
            "with Memories."),
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = HOLD_EFFECT_MEMORY,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MULTI_ATTACK,
=======
        .battleAnimScript = gBattleAnimMove_MultiAttack,
>>>>>>> upstream/master
    },

    [MOVE_MIND_BLOWN] =
    {
        .name = COMPOUND_STRING("Mind Blown"),
        .description = COMPOUND_STRING(
            "It explodes the user's head\n"
            "to damage everything around."),
        .effect = EFFECT_MIND_BLOWN,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MIND_BLOWN,
=======
        .battleAnimScript = gBattleAnimMove_MindBlown,
>>>>>>> upstream/master
    },

    [MOVE_PLASMA_FISTS] =
    {
        .name = COMPOUND_STRING("Plasma Fists"),
        .description = COMPOUND_STRING(
            "Hits with electrical fists.\n"
            "Normal moves turn Electric."),
<<<<<<< HEAD
        .effect = EFFECT_PLASMA_FISTS,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PLASMA_FISTS,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ION_DELUGE,
            .chance = 100,
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_PlasmaFists,
>>>>>>> upstream/master
    },

    [MOVE_PHOTON_GEYSER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PhotonGeyser", "Photon Geyser"),
=======
        .name = COMPOUND_STRING("Photon Geyser"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "User's highest attack stat\n"
            "determines its category."),
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PHOTON_GEYSER,
=======
        .battleAnimScript = gBattleAnimMove_PhotonGeyser,
>>>>>>> upstream/master
    },

    [MOVE_ZIPPY_ZAP] =
    {
        .name = COMPOUND_STRING("Zippy Zap"),
        .description = COMPOUND_STRING(
            "Electric bursts always go\n"
            "first and land a critical hit."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .alwaysCriticalHit = TRUE,
        .metronomeBanned = TRUE,
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EVS_PLUS_1,
            .chance = 100,
<<<<<<< HEAD
        }),
        #endif
        .battleAnimScript = Move_ZIPPY_ZAP,
=======
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        #endif
        .battleAnimScript = gBattleAnimMove_ZippyZap,
>>>>>>> upstream/master
    },

    [MOVE_SPLISHY_SPLASH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SplishySplsh", "Splishy Splash"),
=======
        .name = COMPOUND_STRING("Splishy Splash"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A huge electrified wave that\n"
            "may paralyze the foe."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_SPLISHY_SPLASH,
=======
        .battleAnimScript = gBattleAnimMove_SplishySplash,
>>>>>>> upstream/master
    },

    [MOVE_FLOATY_FALL] =
    {
        .name = COMPOUND_STRING("Floaty Fall"),
        .description = COMPOUND_STRING(
            "Floats in air and dives at\n"
            "angle. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .gravityBanned = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
<<<<<<< HEAD
        }),
        .battleAnimScript = Move_FLOATY_FALL,
=======
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_FloatyFall,
>>>>>>> upstream/master
    },

    [MOVE_PIKA_PAPOW] =
    {
        .name = COMPOUND_STRING("Pika Papow"),
        .description = COMPOUND_STRING(
            "Pikachu's love increases its\n"
            "power. It never misses."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_PIKA_PAPOW,
=======
        .battleAnimScript = gBattleAnimMove_PikaPapow,
>>>>>>> upstream/master
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BouncyBubble", "Bouncy Bubble"),
=======
        .name = COMPOUND_STRING("Bouncy Bubble"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "An attack that absorbs\n"
        #if B_UPDATED_MOVE_DATA >= GEN_8
            "all the damage inflicted."),
        #else
            "half the damage inflicted."),
        #endif
        .effect = EFFECT_ABSORB,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 50, // restores 100% HP instead of 50% HP
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .healingMove = B_HEAL_BLOCKING >= GEN_6,
<<<<<<< HEAD
        .battleAnimScript = Move_BOUNCY_BUBBLE,
=======
        .battleAnimScript = gBattleAnimMove_BouncyBubble,
>>>>>>> upstream/master
    },

    [MOVE_BUZZY_BUZZ] =
    {
        .name = COMPOUND_STRING("Buzzy Buzz"),
        .description = COMPOUND_STRING(
            "Shoots a jolt of electricity\n"
            "that always paralyzes."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
<<<<<<< HEAD
        }),
        .battleAnimScript = Move_BUZZY_BUZZ,
=======
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_BuzzyBuzz,
>>>>>>> upstream/master
    },

    [MOVE_SIZZLY_SLIDE] =
    {
        .name = COMPOUND_STRING("Sizzly Slide"),
        .description = COMPOUND_STRING(
            "User cloaked in fire charges.\n"
            "Leaves the foe with a burn."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 60 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 20 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 100,
<<<<<<< HEAD
        }),
        .battleAnimScript = Move_SIZZLY_SLIDE,
=======
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_SizzlySlide,
>>>>>>> upstream/master
    },

    [MOVE_GLITZY_GLOW] =
    {
        .name = COMPOUND_STRING("Glitzy Glow"),
        .description = COMPOUND_STRING(
            "Telekinetic force that sets\n"
            "wall, lowering Sp. Atk damage."),
<<<<<<< HEAD
        .effect = EFFECT_GLITZY_GLOW,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_GLITZY_GLOW,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LIGHT_SCREEN,
            .chance = 100,
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_GlitzyGlow,
>>>>>>> upstream/master
    },

    [MOVE_BADDY_BAD] =
    {
        .name = COMPOUND_STRING("Baddy Bad"),
        .description = COMPOUND_STRING(
            "Acting badly, attacks. Sets\n"
            "wall, lowering Attack damage."),
<<<<<<< HEAD
        .effect = EFFECT_BADDY_BAD,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 80 : 90,
        .type = TYPE_DARK,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 95 : 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_BADDY_BAD,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REFLECT,
            .chance = 100,
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_BaddyBad,
>>>>>>> upstream/master
    },

    [MOVE_SAPPY_SEED] =
    {
        .name = COMPOUND_STRING("Sappy Seed"),
        .description = COMPOUND_STRING(
            "Giant stalk scatters seeds\n"
            "that drain HP every turn."),
<<<<<<< HEAD
        .effect = EFFECT_SAPPY_SEED,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_GRASS,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SAPPY_SEED,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_LEECH_SEED,
            .chance = 100,
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_SappySeed,
>>>>>>> upstream/master
    },

    [MOVE_FREEZY_FROST] =
    {
        .name = COMPOUND_STRING("Freezy Frost"),
        .description = COMPOUND_STRING(
            "Crystal from cold haze hits.\n"
            "Eliminates all stat changes."),
<<<<<<< HEAD
        .effect = EFFECT_FREEZY_FROST,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 100 : 90,
        .type = TYPE_ICE,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 90 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_FREEZY_FROST,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_HAZE,
            .chance = 100,
            .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_FreezyFrost,
>>>>>>> upstream/master
    },

    [MOVE_SPARKLY_SWIRL] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SparklySwirl", "Sparkly Swirl"),
        .description = COMPOUND_STRING(
            "Wrap foe with whirlwind of\n"
            "scent. Heals party's status."),
        .effect = EFFECT_SPARKLY_SWIRL,
=======
        .name = COMPOUND_STRING("Sparkly Swirl"),
        .description = COMPOUND_STRING(
            "Wrap foe with whirlwind of\n"
            "scent. Heals party's status."),
        .effect = EFFECT_SPARKLY_SWIRL, // Temprorary
>>>>>>> upstream/master
        .power = B_UPDATED_MOVE_DATA >= GEN_8 ? 120 : 90,
        .type = TYPE_FAIRY,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_8 ? 85 : 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_8 ? 5 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SPARKLY_SWIRL,
=======
        // .additionalEffects = ADDITIONAL_EFFECTS({
        //     .moveEffect = 0, // MOVE_EFFECT_AROMATHERAPY, Added 0 for Sheer Force boost
        //     .chance = 100,
        //     .sheerForceBoost = SHEER_FORCE_NO_BOOST,
        // }),
        .battleAnimScript = gBattleAnimMove_SparklySwirl,
>>>>>>> upstream/master
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("VeeveeVolley", "Veevee Volley"),
=======
        .name = COMPOUND_STRING("Veevee Volley"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Eevee's love increases its\n"
            "power. It never misses."),
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .mirrorMoveBanned = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_VEEVEE_VOLLEY,
=======
        .battleAnimScript = gBattleAnimMove_VeeveeVolley,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DublIronBash", "Double Iron Bash"),
=======
        .name = COMPOUND_STRING("Double Iron Bash"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "The user spins and hits with\n"
            "its arms. May cause flinch."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 2,
        .minimizeDoubleDamage = B_UPDATED_MOVE_FLAGS < GEN_8,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_IRON_BASH,
=======
        .battleAnimScript = gBattleAnimMove_DoubleIronBash,
>>>>>>> upstream/master
    },

    [MOVE_DYNAMAX_CANNON] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DynamxCannon", "Dynamax Cannon"),
=======
        .name = COMPOUND_STRING("Dynamax Cannon"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Unleashes core energy.\n"
            "2x against Dynamaxed foes."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .mimicBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DYNAMAX_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_DynamaxCannon,
>>>>>>> upstream/master
    },

    [MOVE_SNIPE_SHOT] =
    {
        .name = COMPOUND_STRING("Snipe Shot"),
        .description = COMPOUND_STRING(
            "The user ignores effects\n"
            "that draw in moves."),
        .effect = EFFECT_SNIPE_SHOT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SNIPE_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_SnipeShot,
>>>>>>> upstream/master
    },

    [MOVE_JAW_LOCK] =
    {
        .name = COMPOUND_STRING("Jaw Lock"),
        .description = COMPOUND_STRING(
            "Prevents the user and\n"
            "the target from escaping."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TRAP_BOTH,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_JAW_LOCK,
=======
        .battleAnimScript = gBattleAnimMove_JawLock,
>>>>>>> upstream/master
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .name = COMPOUND_STRING("Stuff Cheeks"),
        .description = COMPOUND_STRING(
            "Consumes the user's Berry,\n"
            "then sharply raises Def."),
        .effect = EFFECT_STUFF_CHEEKS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STUFF_CHEEKS,
=======
        .battleAnimScript = gBattleAnimMove_StuffCheeks,
>>>>>>> upstream/master
    },

    [MOVE_NO_RETREAT] =
    {
        .name = COMPOUND_STRING("No Retreat"),
        .description = COMPOUND_STRING(
            "Raises all of the user's\n"
            "stats but prevents escape."),
        .effect = EFFECT_NO_RETREAT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_NO_RETREAT,
=======
        .battleAnimScript = gBattleAnimMove_NoRetreat,
>>>>>>> upstream/master
    },

    [MOVE_TAR_SHOT] =
    {
        .name = COMPOUND_STRING("Tar Shot"),
        .description = COMPOUND_STRING(
            "Lowers the foe's Speed and\n"
            "makes it weak to Fire."),
        .effect = EFFECT_TAR_SHOT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TAR_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_TarShot,
>>>>>>> upstream/master
    },

    [MOVE_MAGIC_POWDER] =
    {
        .name = COMPOUND_STRING("Magic Powder"),
        .description = COMPOUND_STRING(
            "Magic powder changes the\n"
            "target into a Psychic-type."),
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .argument = TYPE_PSYCHIC,
        .magicCoatAffected = TRUE,
        .powderMove = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_MAGIC_POWDER,
=======
        .battleAnimScript = gBattleAnimMove_MagicPowder,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_DARTS] =
    {
        .name = COMPOUND_STRING("Dragon Darts"),
        .description = COMPOUND_STRING(
            "The user attacks twice. Two\n"
            "targets are hit once each."),
        .effect = EFFECT_DRAGON_DARTS,
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .strikeCount = 2,
        .parentalBondBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_DARTS,
=======
        .battleAnimScript = gBattleAnimMove_DragonDarts,
>>>>>>> upstream/master
    },

    [MOVE_TEATIME] =
    {
        .name = COMPOUND_STRING("Teatime"),
        .description = COMPOUND_STRING(
            "All Pokémon have teatime\n"
            "and eat their Berries."),
        .effect = EFFECT_TEATIME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TEATIME,
=======
        .battleAnimScript = gBattleAnimMove_Teatime,
>>>>>>> upstream/master
    },

    [MOVE_OCTOLOCK] =
    {
        .name = COMPOUND_STRING("Octolock"),
        .description = COMPOUND_STRING(
            "Traps the foe to lower Def\n"
<<<<<<< HEAD
            "and Sp. Def fall each turn."),
=======
            "and Sp. Def each turn."),
>>>>>>> upstream/master
        .effect = EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_OCTOLOCK,
=======
        .battleAnimScript = gBattleAnimMove_Octolock,
>>>>>>> upstream/master
    },

    [MOVE_BOLT_BEAK] =
    {
        .name = COMPOUND_STRING("Bolt Beak"),
        .description = COMPOUND_STRING(
            "Double power if the user\n"
            "moves before the target."),
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BOLT_BEAK,
=======
        .battleAnimScript = gBattleAnimMove_BoltBeak,
>>>>>>> upstream/master
    },

    [MOVE_FISHIOUS_REND] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FishiousRend", "Fishious Rend"),
=======
        .name = COMPOUND_STRING("Fishious Rend"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Double power if the user\n"
            "moves before the target."),
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .bitingMove = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FISHIOUS_REND,
=======
        .battleAnimScript = gBattleAnimMove_FishiousRend,
>>>>>>> upstream/master
    },

    [MOVE_COURT_CHANGE] =
    {
        .name = COMPOUND_STRING("Court Change"),
        .description = COMPOUND_STRING(
            "The user swaps effects on\n"
            "either side of the field."),
        .effect = EFFECT_COURT_CHANGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .contestEffect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COURT_CHANGE,
=======
        .battleAnimScript = gBattleAnimMove_CourtChange,
>>>>>>> upstream/master
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ClngrousSoul", "Clangorous Soul"),
=======
        .name = COMPOUND_STRING("Clangorous Soul"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "The user uses some of its\n"
            "HP to raise all its stats."),
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .soundMove = TRUE,
        .danceMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CLANGOROUS_SOUL,
=======
        .battleAnimScript = gBattleAnimMove_ClangorousSoul,
>>>>>>> upstream/master
    },

    [MOVE_BODY_PRESS] =
    {
        .name = COMPOUND_STRING("Body Press"),
        .description = COMPOUND_STRING(
            "Does more damage the\n"
            "higher the user's Def."),
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BODY_PRESS,
=======
        .battleAnimScript = gBattleAnimMove_BodyPress,
>>>>>>> upstream/master
    },

    [MOVE_DECORATE] =
    {
        .name = COMPOUND_STRING("Decorate"),
        .description = COMPOUND_STRING(
            "The user sharply raises\n"
            "the target's Atk and Sp.Atk."),
        .effect = EFFECT_DECORATE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DECORATE,
=======
        .battleAnimScript = gBattleAnimMove_Decorate,
>>>>>>> upstream/master
    },

    [MOVE_DRUM_BEATING] =
    {
        .name = COMPOUND_STRING("Drum Beating"),
        .description = COMPOUND_STRING(
            "Plays a drum to attack.\n"
            "The foe's Speed is lowered."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRUM_BEATING,
=======
        .battleAnimScript = gBattleAnimMove_DrumBeating,
>>>>>>> upstream/master
    },

    [MOVE_SNAP_TRAP] =
    {
        .name = COMPOUND_STRING("Snap Trap"),
        .description = COMPOUND_STRING(
            "Snares the target in a snap\n"
            "trap for four to five turns."),
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SNAP_TRAP,
=======
        .battleAnimScript = gBattleAnimMove_SnapTrap,
>>>>>>> upstream/master
    },

    [MOVE_PYRO_BALL] =
    {
        .name = COMPOUND_STRING("Pyro Ball"),
        .description = COMPOUND_STRING(
            "Launches a fiery ball at the\n"
            "target. It may cause a burn."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .thawsUser = TRUE,
        .ballisticMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_PYRO_BALL,
=======
        .battleAnimScript = gBattleAnimMove_PyroBall,
>>>>>>> upstream/master
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BehemthBlade", "Behemoth Blade"),
=======
        .name = COMPOUND_STRING("Behemoth Blade"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Strikes as a sword. Deals 2x\n"
            "damage to Dynamaxed foes."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BEHEMOTH_BLADE,
=======
        .battleAnimScript = gBattleAnimMove_BehemothBlade,
>>>>>>> upstream/master
    },

    [MOVE_BEHEMOTH_BASH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BehemothBash", "Behemoth Bash"),
=======
        .name = COMPOUND_STRING("Behemoth Bash"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Attacks as a shield. Deals 2x\n"
            "damage to Dynamaxed foes."),
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .assistBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BEHEMOTH_BASH,
=======
        .battleAnimScript = gBattleAnimMove_BehemothBash,
>>>>>>> upstream/master
    },

    [MOVE_AURA_WHEEL] =
    {
        .name = COMPOUND_STRING("Aura Wheel"),
        .description = COMPOUND_STRING(
            "Raises Speed to attack. The\n"
            "Type is based on its form."),
        .effect = EFFECT_AURA_WHEEL,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_AURA_WHEEL,
=======
        .battleAnimScript = gBattleAnimMove_AuraWheel,
>>>>>>> upstream/master
    },

    [MOVE_BREAKING_SWIPE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BreakngSwipe", "Breaking Swipe"),
=======
        .name = COMPOUND_STRING("Breaking Swipe"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Swings its tail to attack.\n"
            "Lowers the Atk of those hit."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BREAKING_SWIPE,
=======
        .battleAnimScript = gBattleAnimMove_BreakingSwipe,
>>>>>>> upstream/master
    },

    [MOVE_BRANCH_POKE] =
    {
        .name = COMPOUND_STRING("Branch Poke"),
        .description = COMPOUND_STRING(
            "The user pokes the target\n"
            "with a pointed branch."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BRANCH_POKE,
=======
        .battleAnimScript = gBattleAnimMove_BranchPoke,
>>>>>>> upstream/master
    },

    [MOVE_OVERDRIVE] =
    {
        .name = COMPOUND_STRING("Overdrive"),
        .description = COMPOUND_STRING(
            "The user twangs its guitar,\n"
            "causing strong vibrations."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_OVERDRIVE,
=======
        .battleAnimScript = gBattleAnimMove_Overdrive,
>>>>>>> upstream/master
    },

    [MOVE_APPLE_ACID] =
    {
        .name = COMPOUND_STRING("Apple Acid"),
        .description = COMPOUND_STRING(
            "Attacks with tart apple acid\n"
            "to lower the foe's Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_APPLE_ACID,
=======
        .battleAnimScript = gBattleAnimMove_AppleAcid,
>>>>>>> upstream/master
    },

    [MOVE_GRAV_APPLE] =
    {
        .name = COMPOUND_STRING("Grav Apple"),
        .description = COMPOUND_STRING(
            "Drops an apple from above.\n"
            "Lowers the foe's Defense."),
        .effect = EFFECT_GRAV_APPLE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GRAV_APPLE,
=======
        .battleAnimScript = gBattleAnimMove_GravApple,
>>>>>>> upstream/master
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .name = COMPOUND_STRING("Spirit Break"),
        .description = COMPOUND_STRING(
            "Attacks with spirit-breaking\n"
            "force. Lowers Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SPIRIT_BREAK,
=======
        .battleAnimScript = gBattleAnimMove_SpiritBreak,
>>>>>>> upstream/master
    },

    [MOVE_STRANGE_STEAM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("StrangeSteam", "Strange Steam"),
=======
        .name = COMPOUND_STRING("Strange Steam"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Emits a strange steam to\n"
            "potentially confuse the foe."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STRANGE_STEAM,
=======
        .battleAnimScript = gBattleAnimMove_StrangeSteam,
>>>>>>> upstream/master
    },

    [MOVE_LIFE_DEW] =
    {
        .name = COMPOUND_STRING("Life Dew"),
        .description = COMPOUND_STRING(
            "Scatters water to restore\n"
            "the HP of itself and allies."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LIFE_DEW,
=======
        .battleAnimScript = gBattleAnimMove_LifeDew,
>>>>>>> upstream/master
    },

    [MOVE_OBSTRUCT] =
    {
        .name = COMPOUND_STRING("Obstruct"),
        .description = COMPOUND_STRING(
            "Protects itself, harshly\n"
            "lowering Def on contact."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_OBSTRUCT,
=======
        .battleAnimScript = gBattleAnimMove_Obstruct,
>>>>>>> upstream/master
    },

    [MOVE_FALSE_SURRENDER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FalsSurrendr", "False Surrender"),
=======
        .name = COMPOUND_STRING("False Surrender"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Bows to stab the foe\n"
            "with hair. It never misses."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FALSE_SURRENDER,
=======
        .battleAnimScript = gBattleAnimMove_FalseSurrender,
>>>>>>> upstream/master
    },

    [MOVE_METEOR_ASSAULT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MeteorAssalt", "Meteor Assault"),
=======
        .name = COMPOUND_STRING("Meteor Assault"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Attacks with a thick leek.\n"
            "The user must then rest."),
        .effect = EFFECT_HIT,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .instructBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_METEOR_ASSAULT,
=======
        .battleAnimScript = gBattleAnimMove_MeteorAssault,
>>>>>>> upstream/master
    },

    [MOVE_ETERNABEAM] =
    {
        .name = COMPOUND_STRING("Eternabeam"),
        .description = COMPOUND_STRING(
            "Eternatus' strongest move.\n"
            "The user rests next turn."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RECHARGE,
            .self = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ETERNABEAM,
=======
        .battleAnimScript = gBattleAnimMove_Eternabeam,
>>>>>>> upstream/master
    },

    [MOVE_STEEL_BEAM] =
    {
        .name = COMPOUND_STRING("Steel Beam"),
        .description = COMPOUND_STRING(
            "Fires a beam of steel from\n"
            "its body. It hurts the user."),
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STEEL_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_SteelBeam,
>>>>>>> upstream/master
    },

    [MOVE_EXPANDING_FORCE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ExpandngForc", "Expanding Force"),
=======
        .name = COMPOUND_STRING("Expanding Force"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Power goes up and damages\n"
            "all foes on Psychic Terrain."),
        .effect = EFFECT_EXPANDING_FORCE,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_PSYCHIC_TERRAIN},
<<<<<<< HEAD
        .battleAnimScript = Move_EXPANDING_FORCE,
=======
        .battleAnimScript = gBattleAnimMove_ExpandingForce,
>>>>>>> upstream/master
    },

    [MOVE_STEEL_ROLLER] =
    {
        .name = COMPOUND_STRING("Steel Roller"),
        .description = COMPOUND_STRING(
            "Destroys terrain. Fails if\n"
            "ground isn't terrain."),
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = ARG_TRY_REMOVE_TERRAIN_FAIL, // Remove a field terrain if there is one and hit, otherwise fail.
        .skyBattleBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_STEEL_ROLLER,
=======
        .battleAnimScript = gBattleAnimMove_SteelRoller,
>>>>>>> upstream/master
    },

    [MOVE_SCALE_SHOT] =
    {
        .name = COMPOUND_STRING("Scale Shot"),
        .description = COMPOUND_STRING(
            "Shoots scales 2 to 5 times.\n"
            "Ups Speed, lowers defense."),
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MOVE_EFFECT_SCALE_SHOT,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SCALE_SHOT,
=======
        .battleAnimScript = gBattleAnimMove_ScaleShot,
>>>>>>> upstream/master
    },

    [MOVE_METEOR_BEAM] =
    {
        .name = COMPOUND_STRING("Meteor Beam"),
        .description = COMPOUND_STRING(
            "A 2-turn move that raises\n"
            "Sp. Attack before attacking."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 120,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .instructBanned = TRUE,
        .argument = TWO_TURN_ARG(STRINGID_METEORBEAMCHARGING),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
        }),
        .contestEffect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_METEOR_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_MeteorBeam,
>>>>>>> upstream/master
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ShellSideArm", "Shell Side Arm"),
=======
        .name = COMPOUND_STRING("Shell Side Arm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Deals better of physical and\n"
            "special damage. May poison."),
        .effect = EFFECT_SHELL_SIDE_ARM,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SHELL_SIDE_ARM,
=======
        .battleAnimScript = gBattleAnimMove_ShellSideArm,
>>>>>>> upstream/master
    },

    [MOVE_MISTY_EXPLOSION] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MstyExplsion", "Misty Explosion"),
=======
        .name = COMPOUND_STRING("Misty Explosion"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hit everything and faint.\n"
            "Powers up on Misty Terrain."),
        .effect = EFFECT_EXPLOSION,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_MISTY_TERRAIN},
<<<<<<< HEAD
        .battleAnimScript = Move_MISTY_EXPLOSION,
=======
        .battleAnimScript = gBattleAnimMove_MistyExplosion,
>>>>>>> upstream/master
    },

    [MOVE_GRASSY_GLIDE] =
    {
        .name = COMPOUND_STRING("Grassy Glide"),
        .description = COMPOUND_STRING(
            "Gliding on ground, hits. Goes\n"
            "first on Grassy Terrain."),
        .effect = EFFECT_GRASSY_GLIDE,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 55 : 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .contestEffect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_GRASSY_TERRAIN},
<<<<<<< HEAD
        .battleAnimScript = Move_GRASSY_GLIDE,
=======
        .battleAnimScript = gBattleAnimMove_GrassyGlide,
>>>>>>> upstream/master
    },

    [MOVE_RISING_VOLTAGE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("RisngVoltage", "Rising Voltage"),
=======
        .name = COMPOUND_STRING("Rising Voltage"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "This move's power doubles\n"
            "when on Electric Terrain."),
        .effect = EFFECT_RISING_VOLTAGE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN},
<<<<<<< HEAD
        .battleAnimScript = Move_RISING_VOLTAGE,
=======
        .battleAnimScript = gBattleAnimMove_RisingVoltage,
>>>>>>> upstream/master
    },

    [MOVE_TERRAIN_PULSE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("TerrainPulse", "Terrain Pulse"),
=======
        .name = COMPOUND_STRING("Terrain Pulse"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Type and power changes\n"
            "depending on the terrain."),
        .effect = EFFECT_TERRAIN_PULSE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .pulseMove = TRUE,
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN, COMBO_STARTER_MISTY_TERRAIN, COMBO_STARTER_GRASSY_TERRAIN, COMBO_STARTER_PSYCHIC_TERRAIN},
<<<<<<< HEAD
        .battleAnimScript = Move_TERRAIN_PULSE,
=======
        .battleAnimScript = gBattleAnimMove_TerrainPulse,
>>>>>>> upstream/master
    },

    [MOVE_SKITTER_SMACK] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SkitterSmack", "Skitter Smack"),
=======
        .name = COMPOUND_STRING("Skitter Smack"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "User skitters behind foe to\n"
            "attack. Lowers foe's Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SKITTER_SMACK,
=======
        .battleAnimScript = gBattleAnimMove_SkitterSmack,
>>>>>>> upstream/master
    },

    [MOVE_BURNING_JEALOUSY] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BrningJelosy", "Burning Jealousy"),
=======
        .name = COMPOUND_STRING("Burning Jealousy"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Foes that have stats upped\n"
            "during the turn get burned."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_BURNING_JEALOUSY,
=======
        .battleAnimScript = gBattleAnimMove_BurningJealousy,
>>>>>>> upstream/master
    },

    [MOVE_LASH_OUT] =
    {
        .name = COMPOUND_STRING("Lash Out"),
        .description = COMPOUND_STRING(
            "If stats lowered during this\n"
            "turn, power is doubled."),
        .effect = EFFECT_LASH_OUT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_LASH_OUT,
=======
        .battleAnimScript = gBattleAnimMove_LashOut,
>>>>>>> upstream/master
    },

    [MOVE_POLTERGEIST] =
    {
        .name = COMPOUND_STRING("Poltergeist"),
        .description = COMPOUND_STRING(
            "Control foe's item to attack.\n"
            "Fails if foe has no item."),
        .effect = EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_POLTERGEIST,
=======
        .battleAnimScript = gBattleAnimMove_Poltergeist,
>>>>>>> upstream/master
    },

    [MOVE_CORROSIVE_GAS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("CorrosiveGas", "Corrosive Gas"),
=======
        .name = COMPOUND_STRING("Corrosive Gas"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Highly acidic gas melts items\n"
            "held by surrounding Pokémon."),
        .effect = EFFECT_CORROSIVE_GAS,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .contestEffect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_CORROSIVE_GAS,
=======
        .battleAnimScript = gBattleAnimMove_CorrosiveGas,
>>>>>>> upstream/master
    },

    [MOVE_COACHING] =
    {
        .name = COMPOUND_STRING("Coaching"),
        .description = COMPOUND_STRING(
            "Properly coaches allies to\n"
            "up their Attack and Defense."),
        .effect = EFFECT_COACHING,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_COACHING,
=======
        .battleAnimScript = gBattleAnimMove_Coaching,
>>>>>>> upstream/master
    },

    [MOVE_FLIP_TURN] =
    {
        .name = COMPOUND_STRING("Flip Turn"),
        .description = COMPOUND_STRING(
            "Attacks and rushes back to\n"
            "switch with a party Pokémon."),
        .effect = EFFECT_HIT_ESCAPE,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .contestEffect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FLIP_TURN,
=======
        .battleAnimScript = gBattleAnimMove_FlipTurn,
>>>>>>> upstream/master
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .name = COMPOUND_STRING("Triple Axel"),
        .description = COMPOUND_STRING(
            "A 3-kick attack that gets\n"
            "more powerful with each hit."),
        .effect = EFFECT_TRIPLE_KICK,
        .power = 20,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_TRIPLE_AXEL,
=======
        .battleAnimScript = gBattleAnimMove_TripleAxel,
>>>>>>> upstream/master
    },

    [MOVE_DUAL_WINGBEAT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DualWingbeat", "Dual Wingbeat"),
=======
        .name = COMPOUND_STRING("Dual Wingbeat"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "User slams the target with\n"
            "wings and hits twice in a row."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 2,
        .contestEffect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DUAL_WINGBEAT,
=======
        .battleAnimScript = gBattleAnimMove_DualWingbeat,
>>>>>>> upstream/master
    },

    [MOVE_SCORCHING_SANDS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ScorchngSnds", "Scorching Sands"),
=======
        .name = COMPOUND_STRING("Scorching Sands"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Throws scorching sand at\n"
            "the target. May leave a burn."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SCORCHING_SANDS,
=======
        .battleAnimScript = gBattleAnimMove_ScorchingSands,
>>>>>>> upstream/master
    },

    [MOVE_JUNGLE_HEALING] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("JungleHealng", "Jungle Healing"),
=======
        .name = COMPOUND_STRING("Jungle Healing"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Heals HP and status of\n"
            "itself and allies in battle."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .ignoresSubstitute = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_JUNGLE_HEALING,
=======
        .battleAnimScript = gBattleAnimMove_JungleHealing,
>>>>>>> upstream/master
    },

    [MOVE_WICKED_BLOW] =
    {
        .name = COMPOUND_STRING("Wicked Blow"),
        .description = COMPOUND_STRING(
            "Mastering the Dark style,\n"
            "strikes with a critical hit."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_WICKED_BLOW,
=======
        .battleAnimScript = gBattleAnimMove_WickedBlow,
>>>>>>> upstream/master
    },

    [MOVE_SURGING_STRIKES] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SurgngStrkes", "Surging Strikes"),
=======
        .name = COMPOUND_STRING("Surging Strikes"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Mastering the Water style,\n"
            "strikes with 3 critical hits."),
        .effect = EFFECT_HIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .alwaysCriticalHit = TRUE,
        .punchingMove = TRUE,
        .strikeCount = 3,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_SURGING_STRIKES,
=======
        .battleAnimScript = gBattleAnimMove_SurgingStrikes,
>>>>>>> upstream/master
    },

    [MOVE_THUNDER_CAGE] =
    {
        .name = COMPOUND_STRING("Thunder Cage"),
        .description = COMPOUND_STRING(
            "Traps the foe in a cage of\n"
            "electricity for "BINDING_TURNS" turns."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_WRAP,
        }),
        .contestEffect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDER_CAGE,
=======
        .battleAnimScript = gBattleAnimMove_ThunderCage,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_ENERGY] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("DragonEnergy", "Dragon Energy"),
        .description = COMPOUND_STRING(
            "The higher the user's HP\n"
            "the more damage caused."),
        .effect = EFFECT_ERUPTION,
=======
        .name = COMPOUND_STRING("Dragon Energy"),
        .description = COMPOUND_STRING(
            "The higher the user's HP\n"
            "the more damage caused."),
        .effect = EFFECT_POWER_BASED_ON_USER_HP,
>>>>>>> upstream/master
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_ENERGY,
=======
        .battleAnimScript = gBattleAnimMove_DragonEnergy,
>>>>>>> upstream/master
    },

    [MOVE_FREEZING_GLARE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("FreezngGlare", "Freezing Glare"),
=======
        .name = COMPOUND_STRING("Freezing Glare"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Shoots psychic power from\n"
        #if B_USE_FROSTBITE == TRUE
            "the eyes. May frostbite."),
        #else
            "the eyes. May freeze the foe."),
        #endif
        .power = 90,
        .effect = EFFECT_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
            .chance = 10,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FREEZING_GLARE,
=======
        .battleAnimScript = gBattleAnimMove_FreezingGlare,
>>>>>>> upstream/master
    },

    [MOVE_FIERY_WRATH] =
    {
        .name = COMPOUND_STRING("Fiery Wrath"),
        .description = COMPOUND_STRING(
            "An attack fueled by your\n"
            "wrath. May cause flinching."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 20,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_FIERY_WRATH,
=======
        .battleAnimScript = gBattleAnimMove_FieryWrath,
>>>>>>> upstream/master
    },

    [MOVE_THUNDEROUS_KICK] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ThnderusKick", "Thunderous Kick"),
=======
        .name = COMPOUND_STRING("Thunderous Kick"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Uses a lightning-like kick\n"
            "to hit. Lowers foe's Defense."),
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 100,
        }),
        .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDEROUS_KICK,
=======
        .battleAnimScript = gBattleAnimMove_ThunderousKick,
>>>>>>> upstream/master
    },

    [MOVE_GLACIAL_LANCE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("GlacialLance", "Glacial Lance"),
=======
        .name = COMPOUND_STRING("Glacial Lance"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hurls a blizzard-cloaked\n"
            "icicle lance at foes."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 130,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_GLACIAL_LANCE,
=======
        .battleAnimScript = gBattleAnimMove_GlacialLance,
>>>>>>> upstream/master
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("AstrlBarrage", "Astral Barrage"),
=======
        .name = COMPOUND_STRING("Astral Barrage"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Sends a frightful amount\n"
            "of small ghosts at foes."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .contestEffect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_ASTRAL_BARRAGE,
=======
        .battleAnimScript = gBattleAnimMove_AstralBarrage,
>>>>>>> upstream/master
    },

    [MOVE_EERIE_SPELL] =
    {
        .name = COMPOUND_STRING("Eerie Spell"),
        .description = COMPOUND_STRING(
            "Attacks with psychic power.\n"
            "Foe's last move has 3 PP cut."),
<<<<<<< HEAD
        .effect = EFFECT_EERIE_SPELL,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .contestEffect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .contestComboStarterId = 0,
        .contestComboMoves = {0},
<<<<<<< HEAD
        .battleAnimScript = Move_EERIE_SPELL,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_EERIE_SPELL,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_EerieSpell,
>>>>>>> upstream/master
    },

    [MOVE_DIRE_CLAW] =
    {
        .name = COMPOUND_STRING("Dire Claw"),
        .description = COMPOUND_STRING(
            "High critical hit chance. May\n"
            "paralyze, poison or drowse."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DIRE_CLAW,
            .chance = 50,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_DIRE_CLAW,
=======
        .battleAnimScript = gBattleAnimMove_DireClaw,
>>>>>>> upstream/master
    },

    [MOVE_PSYSHIELD_BASH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PsyshieldBsh", "Psyshield Bash"),
=======
        .name = COMPOUND_STRING("Psyshield Bash"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits a foe with psychic\n"
            "energy. May raise Defense."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_PSYSHIELD_BASH,
=======
        .battleAnimScript = gBattleAnimMove_PsyshieldBash,
>>>>>>> upstream/master
    },

    [MOVE_POWER_SHIFT] =
    {
        .name = COMPOUND_STRING("Power Shift"),
        .description = COMPOUND_STRING(
            "The user swaps its Attack\n"
            "and Defense stats."),
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_POWER_SHIFT,
=======
        .battleAnimScript = gBattleAnimMove_PowerShift,
>>>>>>> upstream/master
},

    [MOVE_STONE_AXE] =
    {
        .name = COMPOUND_STRING("Stone Axe"),
        .description = COMPOUND_STRING(
            "High critical hit ratio. Sets\n"
            "Splinters that hurt the foe."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STEALTH_ROCK,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_STONE_AXE,
=======
        .battleAnimScript = gBattleAnimMove_StoneAxe,
>>>>>>> upstream/master
    },

    [MOVE_SPRINGTIDE_STORM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SprngtdeStrm", "Springtide Storm"),
=======
        .name = COMPOUND_STRING("Springtide Storm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Wraps a foe in fierce winds.\n"
            "Varies with the user's form."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_SPRINGTIDE_STORM,
=======
        .battleAnimScript = gBattleAnimMove_SpringtideStorm,
>>>>>>> upstream/master
    },

    [MOVE_MYSTICAL_POWER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MystcalPower", "Mystical Power"),
=======
        .name = COMPOUND_STRING("Mystical Power"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A mysterious power strikes,\n"
            "raising the user's Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_MYSTICAL_POWER,
=======
        .battleAnimScript = gBattleAnimMove_MysticalPower,
>>>>>>> upstream/master
    },

    [MOVE_RAGING_FURY] =
    {
        .name = COMPOUND_STRING("Raging Fury"),
        .description = COMPOUND_STRING(
            "A rampage of 2 to 3 turns\n"
            "that confuses the user."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_THRASH,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_RAGING_FURY,
=======
        .battleAnimScript = gBattleAnimMove_RagingFury,
>>>>>>> upstream/master
    },

    [MOVE_WAVE_CRASH] =
    {
        .name = COMPOUND_STRING("Wave Crash"),
        .description = COMPOUND_STRING(
            "A slam shrouded in water.\n"
            "It also hurts the user."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 75,
        .type = TYPE_WATER,
        .accuracy = 100,
        .recoil = 33,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
<<<<<<< HEAD
        .battleAnimScript = Move_WAVE_CRASH,
=======
        .battleAnimScript = gBattleAnimMove_WaveCrash,
>>>>>>> upstream/master
    },

    [MOVE_CHLOROBLAST] =
    {
        .name = COMPOUND_STRING("Chloroblast"),
        .description = COMPOUND_STRING(
            "A user-hurting blast of\n"
            "amassed chlorophyll."),
        .effect = EFFECT_MAX_HP_50_RECOIL,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 150 : 120,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .battleAnimScript = Move_CHLOROBLAST,
=======
        .battleAnimScript = gBattleAnimMove_Chloroblast,
>>>>>>> upstream/master
    },

    [MOVE_MOUNTAIN_GALE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MountainGale", "Mountain Gale"),
=======
        .name = COMPOUND_STRING("Mountain Gale"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Giant chunks of ice damage\n"
            "the foe. It may flinch."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_MOUNTAIN_GALE,
=======
        .battleAnimScript = gBattleAnimMove_MountainGale,
>>>>>>> upstream/master
    },

    [MOVE_VICTORY_DANCE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("VictoryDance", "Victory Dance"),
=======
        .name = COMPOUND_STRING("Victory Dance"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Dances to raise Attack,\n"
            "Defense and Speed."),
        .effect = EFFECT_VICTORY_DANCE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .danceMove = TRUE,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_VICTORY_DANCE,
=======
        .battleAnimScript = gBattleAnimMove_VictoryDance,
>>>>>>> upstream/master
    },

    [MOVE_HEADLONG_RUSH] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("HeadlongRush", "Headlong Rush"),
=======
        .name = COMPOUND_STRING("Headlong Rush"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits with a full-body tackle.\n"
            "Lowers the users's defenses."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 120 : 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_HEADLONG_RUSH,
=======
        .battleAnimScript = gBattleAnimMove_HeadlongRush,
>>>>>>> upstream/master
    },

    [MOVE_BARB_BARRAGE] =
    {
        .name = COMPOUND_STRING("Barb Barrage"),
        .description = COMPOUND_STRING(
            "Can poison on impact. Powers\n"
            "up against poisoned foes."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = STATUS1_PSN_ANY,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 50,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_BARB_BARRAGE,
=======
        .battleAnimScript = gBattleAnimMove_BarbBarrage,
>>>>>>> upstream/master
    },

    [MOVE_ESPER_WING] =
    {
        .name = COMPOUND_STRING("Esper Wing"),
        .description = COMPOUND_STRING(
            "High critical hit ratio.\n"
            "Ups the user's Speed."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 80 : 75,
        .type = TYPE_PSYCHIC,
        .accuracy = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 90,
        .criticalHitStage = 1,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_ESPER_WING,
=======
        .battleAnimScript = gBattleAnimMove_EsperWing,
>>>>>>> upstream/master
    },

    [MOVE_BITTER_MALICE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BitterMalice", "Bitter Malice"),
=======
        .name = COMPOUND_STRING("Bitter Malice"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A spine-chilling resentment.\n"
            "Lowers the foe's Attack."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 75 : 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_BITTER_MALICE,
=======
        .battleAnimScript = gBattleAnimMove_BitterMalice,
>>>>>>> upstream/master
    },

    [MOVE_SHELTER] =
    {
        .name = COMPOUND_STRING("Shelter"),
        .description = COMPOUND_STRING(
            "The user hardens their skin,\n"
            "sharply raising its Defense."),
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SHELTER,
=======
        .battleAnimScript = gBattleAnimMove_Shelter,
>>>>>>> upstream/master
    },

    [MOVE_TRIPLE_ARROWS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("TripleArrows", "Triple Arrows"),
=======
        .name = COMPOUND_STRING("Triple Arrows"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "High critical hit ratio.\n"
            "May lower Defense or flinch."),
        .effect = EFFECT_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 90 : 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 15,
        .criticalHitStage = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_MINUS_1,
            .chance = 50,
        },
        {
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_TRIPLE_ARROWS,
=======
        .battleAnimScript = gBattleAnimMove_TripleArrows,
>>>>>>> upstream/master
    },

    [MOVE_INFERNAL_PARADE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("InfrnlParade", "Infernal Parade"),
=======
        .name = COMPOUND_STRING("Infernal Parade"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hurts a foe harder if it has\n"
            "an ailment. May leave a burn."),
        .effect = EFFECT_DOUBLE_POWER_ON_ARG_STATUS,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = STATUS1_ANY,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_INFERNAL_PARADE,
=======
        .battleAnimScript = gBattleAnimMove_InfernalParade,
>>>>>>> upstream/master
    },

    [MOVE_CEASELESS_EDGE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("CeaslessEdge", "Ceaseless Edge"),
=======
        .name = COMPOUND_STRING("Ceaseless Edge"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "High critical hit ratio. Sets\n"
            "Splinters that hurt the foe."),
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPIKES,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_CEASELESS_EDGE,
=======
        .battleAnimScript = gBattleAnimMove_CeaselessEdge,
>>>>>>> upstream/master
    },

    [MOVE_BLEAKWIND_STORM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BlekwndStorm", "Bleakwind Storm"),
=======
        .name = COMPOUND_STRING("Bleakwind Storm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits with brutal, cold winds.\n"
            "May lower the foe's Speed."),
        .effect = EFFECT_RAIN_ALWAYS_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_FLYING,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_BLEAKWIND_STORM,
=======
        .battleAnimScript = gBattleAnimMove_BleakwindStorm,
>>>>>>> upstream/master
    },

    [MOVE_WILDBOLT_STORM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("WildbltStorm", "Wildbolt Storm"),
=======
        .name = COMPOUND_STRING("Wildbolt Storm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits with a brutal tempest.\n"
            "May inflict paralysis."),
        .effect = EFFECT_RAIN_ALWAYS_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_ELECTRIC,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 20,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_WILDBOLT_STORM,
=======
        .battleAnimScript = gBattleAnimMove_WildboltStorm,
>>>>>>> upstream/master
    },

    [MOVE_SANDSEAR_STORM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SndsearStorm", "Sandsear Storm"),
=======
        .name = COMPOUND_STRING("Sandsear Storm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Hits with brutally hot sand.\n"
            "May inflict a burn."),
        .effect = EFFECT_RAIN_ALWAYS_HIT,
        .power = B_UPDATED_MOVE_DATA >= GEN_9 ? 100 : 95,
        .type = TYPE_GROUND,
        .accuracy = 80,
        .pp = B_UPDATED_MOVE_DATA >= GEN_9 ? 10 : 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .windMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_SANDSEAR_STORM,
=======
        .battleAnimScript = gBattleAnimMove_SandsearStorm,
>>>>>>> upstream/master
    },

    [MOVE_LUNAR_BLESSING] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("LunarBlessng", "Lunar Blessing"),
=======
        .name = COMPOUND_STRING("Lunar Blessing"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "The user heals and cures\n"
            "itself and its ally."),
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .healingMove = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_LUNAR_BLESSING,
=======
        .battleAnimScript = gBattleAnimMove_LunarBlessing,
>>>>>>> upstream/master
    },

    [MOVE_TAKE_HEART] =
    {
        .name = COMPOUND_STRING("Take Heart"),
        .description = COMPOUND_STRING(
            "The user lifts its spirits to\n"
            "heal and strengthen itself."),
        .effect = EFFECT_TAKE_HEART,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_TAKE_HEART,
=======
        .battleAnimScript = gBattleAnimMove_TakeHeart,
>>>>>>> upstream/master
    },

    [MOVE_TERA_BLAST] =
    {
        .name = COMPOUND_STRING("Tera Blast"),
        .description = COMPOUND_STRING(
            "If the user's Terastallized,\n"
            "it hits with its Tera-type."),
        .effect = EFFECT_TERA_BLAST,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .forcePressure = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TERA_BLAST,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_TERA_BLAST,
=======
        .battleAnimScript = gBattleAnimMove_TeraBlast,
>>>>>>> upstream/master
    },

    [MOVE_SILK_TRAP] =
    {
        .name = COMPOUND_STRING("Silk Trap"),
        .description = COMPOUND_STRING(
            "Protects itself, lowering\n"
            "Speed on contact."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SILK_TRAP,
=======
        .battleAnimScript = gBattleAnimMove_SilkTrap,
>>>>>>> upstream/master
    },

    [MOVE_AXE_KICK] =
    {
        .name = COMPOUND_STRING("Axe Kick"),
        .description = COMPOUND_STRING(
            "May miss and hurt the kicker.\n"
            "May cause confusion."),
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_AXE_KICK,
=======
        .battleAnimScript = gBattleAnimMove_AxeKick,
>>>>>>> upstream/master
    },

    [MOVE_LAST_RESPECTS] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("LastRespects", "Last Respects"),
=======
        .name = COMPOUND_STRING("Last Respects"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "This move deals more damage\n"
            "for each defeated ally."),
        .effect = EFFECT_LAST_RESPECTS,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE, // Only since it isn't implemented yet
<<<<<<< HEAD
        .battleAnimScript = Move_LAST_RESPECTS,
=======
        .battleAnimScript = gBattleAnimMove_LastRespects,
>>>>>>> upstream/master
    },

    [MOVE_LUMINA_CRASH] =
    {
        .name = COMPOUND_STRING("Lumina Crash"),
        .description = COMPOUND_STRING(
            "A mind-affecting light\n"
            "harshly lowers Sp. Def."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_DEF_MINUS_2,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_LUMINA_CRASH,
=======
        .battleAnimScript = gBattleAnimMove_LuminaCrash,
>>>>>>> upstream/master
    },

    [MOVE_ORDER_UP] =
    {
        .name = COMPOUND_STRING("Order Up"),
        .description = COMPOUND_STRING(
            "Boosts a user's stats\n"
            "depending on Tatsugiri."),
<<<<<<< HEAD
        .effect = EFFECT_PLACEHOLDER, // EFFECT_ORDER_UP
=======
        .effect = EFFECT_ORDER_UP,
>>>>>>> upstream/master
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_ORDER_UP,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ORDER_UP,
            .self = TRUE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_OrderUp,
>>>>>>> upstream/master
    },

    [MOVE_JET_PUNCH] =
    {
        .name = COMPOUND_STRING("Jet Punch"),
        .description = COMPOUND_STRING(
            "A punch is thrown at blinding\n"
            "speed to strike first."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_JET_PUNCH,
=======
        .battleAnimScript = gBattleAnimMove_JetPunch,
>>>>>>> upstream/master
    },

    [MOVE_SPICY_EXTRACT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SpicyExtract", "Spicy Extract"),
=======
        .name = COMPOUND_STRING("Spicy Extract"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Sharply ups target's Attack,\n"
            "harshly lowers its Defense."),
        .effect = EFFECT_SPICY_EXTRACT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .magicCoatAffected = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SPICY_EXTRACT,
=======
        .battleAnimScript = gBattleAnimMove_SpicyExtract,
>>>>>>> upstream/master
    },

    [MOVE_SPIN_OUT] =
    {
        .name = COMPOUND_STRING("Spin Out"),
        .description = COMPOUND_STRING(
            "Furiously strains its legs.\n"
            "Harshly lowers user's Speed."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_2,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_SPIN_OUT,
=======
        .battleAnimScript = gBattleAnimMove_SpinOut,
>>>>>>> upstream/master
    },

    [MOVE_POPULATION_BOMB] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PoplatinBomb", "Population Bomb"),
=======
        .name = COMPOUND_STRING("Population Bomb"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "The user's fellows hit one\n"
            "to ten times in a row."),
        .effect = EFFECT_POPULATION_BOMB,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .metronomeBanned = TRUE,
        .strikeCount = 10,
<<<<<<< HEAD
        .battleAnimScript = Move_POPULATION_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_PopulationBomb,
>>>>>>> upstream/master
    },

    [MOVE_ICE_SPINNER] =
    {
        .name = COMPOUND_STRING("Ice Spinner"),
        .description = COMPOUND_STRING(
            "Ice-covered feet hit a foe\n"
            "and destroy the terrain."),
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 80,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .argument = ARG_TRY_REMOVE_TERRAIN_HIT, // Remove the active field terrain if there is one.
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
<<<<<<< HEAD
        .battleAnimScript = Move_ICE_SPINNER,
=======
        .battleAnimScript = gBattleAnimMove_IceSpinner,
>>>>>>> upstream/master
    },

    [MOVE_GLAIVE_RUSH] =
    {
        .name = COMPOUND_STRING("Glaive Rush"),
        .description = COMPOUND_STRING(
            "Foe attacks next turn can't\n"
            "miss and do double damage."),
        .effect = EFFECT_GLAIVE_RUSH,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_GLAIVE_RUSH,
=======
        .battleAnimScript = gBattleAnimMove_GlaiveRush,
>>>>>>> upstream/master
    },

    [MOVE_REVIVAL_BLESSING] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("RevivlBlesng", "Revival Blessing"),
=======
        .name = COMPOUND_STRING("Revival Blessing"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Revives a fainted party {PKMN}\n"
            "and restores half of its HP."),
        .effect = EFFECT_REVIVAL_BLESSING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .healingMove = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
<<<<<<< HEAD
        .battleAnimScript = Move_REVIVAL_BLESSING,
=======
        .battleAnimScript = gBattleAnimMove_RevivalBlessing,
>>>>>>> upstream/master
    },

    [MOVE_SALT_CURE] =
    {
        .name = COMPOUND_STRING("Salt Cure"),
        .description = COMPOUND_STRING(
            "Hurts foe every turn. Double\n"
            "damage to Steel and Water."),
<<<<<<< HEAD
        .effect = EFFECT_SALT_CURE,
=======
        .effect = EFFECT_HIT,
>>>>>>> upstream/master
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SALT_CURE,
=======
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SALT_CURE,
            .chance = 100,
        }),
        .battleAnimScript = gBattleAnimMove_SaltCure,
>>>>>>> upstream/master
    },

    [MOVE_TRIPLE_DIVE] =
    {
        .name = COMPOUND_STRING("Triple Dive"),
        .description = COMPOUND_STRING(
            "Hits target with splashes\n"
            "of water 3 times in a row."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .strikeCount = 3,
<<<<<<< HEAD
        .battleAnimScript = Move_TRIPLE_DIVE,
=======
        .battleAnimScript = gBattleAnimMove_TripleDive,
>>>>>>> upstream/master
    },

    [MOVE_MORTAL_SPIN] =
    {
        .name = COMPOUND_STRING("Mortal Spin"),
        .description = COMPOUND_STRING(
            "Erases trap moves and Leech\n"
            "Seed. Poisons adjacent foes."),
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_RAPID_SPIN,
            .self = TRUE,
        },
        {
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_MORTAL_SPIN,
=======
        .battleAnimScript = gBattleAnimMove_MortalSpin,
>>>>>>> upstream/master
    },

    [MOVE_DOODLE] =
    {
        .name = COMPOUND_STRING("Doodle"),
        .description = COMPOUND_STRING(
            "Changes user's and ally's\n"
            "Ability into the target's."),
        .effect = EFFECT_DOODLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_DOODLE,
=======
        .battleAnimScript = gBattleAnimMove_Doodle,
>>>>>>> upstream/master
    },

    [MOVE_FILLET_AWAY] =
    {
        .name = COMPOUND_STRING("Fillet Away"),
        .description = COMPOUND_STRING(
            "Sharply boosts offenses and\n"
            "Speed by using its own HP."),
        .effect = EFFECT_FILLET_AWAY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RECOVER_HP },
        .snatchAffected = TRUE,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_FILLET_AWAY,
=======
        .battleAnimScript = gBattleAnimMove_FilletAway,
>>>>>>> upstream/master
    },

    [MOVE_KOWTOW_CLEAVE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("KowtowCleave", "Kowtow Cleave"),
=======
        .name = COMPOUND_STRING("Kowtow Cleave"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "User slashes the foe after\n"
            "kowtowing. It never misses."),
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_KOWTOW_CLEAVE,
=======
        .battleAnimScript = gBattleAnimMove_KowtowCleave,
>>>>>>> upstream/master
    },

    [MOVE_FLOWER_TRICK] =
    {
        .name = COMPOUND_STRING("Flower Trick"),
        .description = COMPOUND_STRING(
            "Rigged bouquet. Always gets\n"
            "a critical hit, never missing."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .alwaysCriticalHit = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_FLOWER_TRICK,
=======
        .battleAnimScript = gBattleAnimMove_FlowerTrick,
>>>>>>> upstream/master
    },

    [MOVE_TORCH_SONG] =
    {
        .name = COMPOUND_STRING("Torch Song"),
        .description = COMPOUND_STRING(
            "Flames scorch the target.\n"
            "Boosts the user's Sp. Atk."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_TORCH_SONG,
=======
        .battleAnimScript = gBattleAnimMove_TorchSong,
>>>>>>> upstream/master
    },

    [MOVE_AQUA_STEP] =
    {
        .name = COMPOUND_STRING("Aqua Step"),
        .description = COMPOUND_STRING(
            "Hits with light, fluid dance\n"
            "steps. Ups the user's Speed."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .danceMove = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_AQUA_STEP,
=======
        .battleAnimScript = gBattleAnimMove_AquaStep,
>>>>>>> upstream/master
    },

    [MOVE_RAGING_BULL] =
    {
        .name = COMPOUND_STRING("Raging Bull"),
        .description = COMPOUND_STRING(
            "Tackle that breaks barriers.\n"
            "User's form determines type."),
        .effect = EFFECT_RAGING_BULL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_RAGING_BULL,
=======
        .battleAnimScript = gBattleAnimMove_RagingBull,
>>>>>>> upstream/master
    },

    [MOVE_MAKE_IT_RAIN] =
    {
        .name = COMPOUND_STRING("Make It Rain"),
        .description = COMPOUND_STRING(
            "Lowers the user's Sp. Atk.\n"
            "Money is recovered after."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PAYDAY,
        },
        {
            .moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_MAKE_IT_RAIN,
=======
        .battleAnimScript = gBattleAnimMove_MakeItRain,
>>>>>>> upstream/master
    },

    [MOVE_RUINATION] =
    {
        .name = COMPOUND_STRING("Ruination"),
        .description = COMPOUND_STRING(
            "Summons a ruinous disaster\n"
            "and cuts half the foe's HP."),
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_RUINATION,
=======
        .battleAnimScript = gBattleAnimMove_Ruination,
>>>>>>> upstream/master
    },

    [MOVE_COLLISION_COURSE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ColisinCours", "Collision Course"),
=======
        .name = COMPOUND_STRING("Collision Course"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Prehistoric explosion that's\n"
            "stronger if super effective."),
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_COLLISION_COURSE,
=======
        .battleAnimScript = gBattleAnimMove_CollisionCourse,
>>>>>>> upstream/master
    },

    [MOVE_ELECTRO_DRIFT] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ElectroDrift", "Electro Drift"),
=======
        .name = COMPOUND_STRING("Electro Drift"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Futuristic electricity. It's\n"
            "stronger if super effective."),
        .effect = EFFECT_COLLISION_COURSE,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_ELECTRO_DRIFT,
=======
        .battleAnimScript = gBattleAnimMove_ElectroDrift,
>>>>>>> upstream/master
    },

    [MOVE_SHED_TAIL] =
    {
        .name = COMPOUND_STRING("Shed Tail"),
        .description = COMPOUND_STRING(
            "Creates a Substitute for\n"
            "itself before switching out."),
        .effect = EFFECT_SHED_TAIL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SHED_TAIL,
=======
        .battleAnimScript = gBattleAnimMove_ShedTail,
>>>>>>> upstream/master
    },

    [MOVE_CHILLY_RECEPTION] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ChilReceptin", "Chilly Reception"),
=======
        .name = COMPOUND_STRING("Chilly Reception"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Bad joke summons snowstorm.\n"
            "The user also switches out."),
        .effect = EFFECT_CHILLY_RECEPTION,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_CHILLY_RECEPTION,
=======
        .battleAnimScript = gBattleAnimMove_ChillyReception,
>>>>>>> upstream/master
    },

    [MOVE_TIDY_UP] =
    {
        .name = COMPOUND_STRING("Tidy Up"),
        .description = COMPOUND_STRING(
            "User tidies up hazards and\n"
            "raises its Attack and Speed."),
        .effect = EFFECT_TIDY_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_TIDY_UP,
=======
        .battleAnimScript = gBattleAnimMove_TidyUp,
>>>>>>> upstream/master
    },

    [MOVE_SNOWSCAPE] =
    {
        .name = COMPOUND_STRING("Snowscape"),
        .description = COMPOUND_STRING(
            "Summons a snowstorm that\n"
            "lasts for five turns."),
        .effect = EFFECT_SNOWSCAPE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_SPD_UP_1 },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SNOWSCAPE,
=======
        .battleAnimScript = gBattleAnimMove_Snowscape,
>>>>>>> upstream/master
    },

    [MOVE_POUNCE] =
    {
        .name = COMPOUND_STRING("Pounce"),
        .description = COMPOUND_STRING(
            "The user pounces on the foe,\n"
            "lowering its Speed."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_MINUS_1,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_POUNCE,
=======
        .battleAnimScript = gBattleAnimMove_Pounce,
>>>>>>> upstream/master
    },

    [MOVE_TRAILBLAZE] =
    {
        .name = COMPOUND_STRING("Trailblaze"),
        .description = COMPOUND_STRING(
            "The user attacks suddenly,\n"
            "raising its Speed."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SPD_PLUS_1,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_TRAILBLAZE,
=======
        .battleAnimScript = gBattleAnimMove_Trailblaze,
>>>>>>> upstream/master
    },

    [MOVE_CHILLING_WATER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("ChillingWatr", "Chilling Water"),
=======
        .name = COMPOUND_STRING("Chilling Water"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A shower with ice-cold water\n"
            "lowers the target's Attack."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ATK_MINUS_1,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_CHILLING_WATER,
=======
        .battleAnimScript = gBattleAnimMove_ChillingWater,
>>>>>>> upstream/master
    },

    [MOVE_HYPER_DRILL] =
    {
        .name = COMPOUND_STRING("Hyper Drill"),
        .description = COMPOUND_STRING(
            "A spinning pointed part\n"
            "bypasses a foe's Protect."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_HYPER_DRILL,
=======
        .battleAnimScript = gBattleAnimMove_HyperDrill,
>>>>>>> upstream/master
    },

    [MOVE_TWIN_BEAM] =
    {
        .name = COMPOUND_STRING("Twin Beam"),
        .description = COMPOUND_STRING(
            "Mystical eye-beams that hit\n"
            "the target twice in a row."),
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_TWIN_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_TwinBeam,
>>>>>>> upstream/master
    },

    [MOVE_RAGE_FIST] =
    {
        .name = COMPOUND_STRING("Rage Fist"),
        .description = COMPOUND_STRING(
            "The more the user has been\n"
            "hit, the stronger the move."),
        .effect = EFFECT_RAGE_FIST,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .punchingMove = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_RAGE_FIST,
=======
        .battleAnimScript = gBattleAnimMove_RageFist,
>>>>>>> upstream/master
    },

    [MOVE_ARMOR_CANNON] =
    {
        .name = COMPOUND_STRING("Armor Cannon"),
        .description = COMPOUND_STRING(
            "A strong attack but lowers\n"
            "the defensive stats."),
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_DEF_SPDEF_DOWN,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_ARMOR_CANNON,
=======
        .battleAnimScript = gBattleAnimMove_ArmorCannon,
>>>>>>> upstream/master
    },

    [MOVE_BITTER_BLADE] =
    {
        .name = COMPOUND_STRING("Bitter Blade"),
        .description = COMPOUND_STRING(
            "An attack that absorbs\n"
            "half the damage inflicted."),
        .effect = EFFECT_ABSORB,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = Move_BITTER_BLADE,
=======
        .argument = 50,
        .makesContact = TRUE,
        .slicingMove = TRUE,
        .healingMove = TRUE,
        .battleAnimScript = gBattleAnimMove_BitterBlade,
>>>>>>> upstream/master
    },

    [MOVE_DOUBLE_SHOCK] =
    {
        .name = COMPOUND_STRING("Double Shock"),
        .description = COMPOUND_STRING(
            "Discharges all electricity,\n"
            "losing the Electric type."),
        .effect = EFFECT_FAIL_IF_NOT_ARG_TYPE,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .metronomeBanned = TRUE,
        .argument = TYPE_ELECTRIC,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_REMOVE_ARG_TYPE,
            .self = TRUE,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_DOUBLE_SHOCK,
=======
        .battleAnimScript = gBattleAnimMove_DoubleShock,
>>>>>>> upstream/master
    },

    [MOVE_GIGATON_HAMMER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("GigatonHammr", "Gigaton Hammer"),
=======
        .name = COMPOUND_STRING("Gigaton Hammer"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Swings a huge hammer. Can't\n"
            "be used twice in a row."),
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .cantUseTwice = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_GIGATON_HAMMER,
=======
        .battleAnimScript = gBattleAnimMove_GigatonHammer,
>>>>>>> upstream/master
    },

    [MOVE_COMEUPPANCE] =
    {
        .name = COMPOUND_STRING("Comeuppance"),
        .description = COMPOUND_STRING(
            "Retaliates strongly against\n"
            "who last hurt the user."),
        .effect = EFFECT_METAL_BURST,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .meFirstBanned = TRUE,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_COMEUPPANCE,
=======
        .battleAnimScript = gBattleAnimMove_Comeuppance,
>>>>>>> upstream/master
    },

    [MOVE_AQUA_CUTTER] =
    {
        .name = COMPOUND_STRING("Aqua Cutter"),
        .description = COMPOUND_STRING(
            "Pressurized water cut with a\n"
            "high critical-hit ratio."),
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .criticalHitStage = 1,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .slicingMove = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_AQUA_CUTTER,
=======
        .battleAnimScript = gBattleAnimMove_AquaCutter,
>>>>>>> upstream/master
    },

    [MOVE_BLAZING_TORQUE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BlazngTorque", "Blazing Torque"),
=======
        .name = COMPOUND_STRING("Blazing Torque"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_BLAZING_TORQUE,
=======
        .battleAnimScript = gBattleAnimMove_BlazingTorque,
>>>>>>> upstream/master
    },

    [MOVE_WICKED_TORQUE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("WickedTorque", "Wicked Torque"),
=======
        .name = COMPOUND_STRING("Wicked Torque"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SLEEP,
            .chance = 10,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_WICKED_TORQUE,
=======
        .battleAnimScript = gBattleAnimMove_WickedTorque,
>>>>>>> upstream/master
    },

    [MOVE_NOXIOUS_TORQUE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("NoxiusTorque", "Noxious Torque"),
=======
        .name = COMPOUND_STRING("Noxious Torque"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_POISON,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_NOXIOUS_TORQUE,
=======
        .battleAnimScript = gBattleAnimMove_NoxiousTorque,
>>>>>>> upstream/master
    },

    [MOVE_COMBAT_TORQUE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("CombatTorque", "Combat Torque"),
=======
        .name = COMPOUND_STRING("Combat Torque"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_COMBAT_TORQUE,
=======
        .battleAnimScript = gBattleAnimMove_CombatTorque,
>>>>>>> upstream/master
    },

    [MOVE_MAGICAL_TORQUE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MagiclTorque", "Magical Torque"),
=======
        .name = COMPOUND_STRING("Magical Torque"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING("---"),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .mirrorMoveBanned = TRUE,
        .meFirstBanned = TRUE,
        .mimicBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .sleepTalkBanned = TRUE,
        .instructBanned = TRUE,
        .encoreBanned = TRUE,
        .assistBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .chance = 30,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_MAGICAL_TORQUE,
=======
        .battleAnimScript = gBattleAnimMove_MagicalTorque,
>>>>>>> upstream/master
    },

    [MOVE_PSYBLADE] =
    {
        .name = COMPOUND_STRING("Psyblade"),
        .description = COMPOUND_STRING(
            "This move's power increases\n"
            "when on Electric Terrain."),
        .effect = EFFECT_PSYBLADE,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .slicingMove = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_PSYBLADE,
=======
        .battleAnimScript = gBattleAnimMove_Psyblade,
>>>>>>> upstream/master
    },

    [MOVE_HYDRO_STEAM] =
    {
        .name = COMPOUND_STRING("Hydro Steam"),
        .description = COMPOUND_STRING(
            "This move's power increases\n"
            "under harsh sunlight."),
        .effect = EFFECT_HYDRO_STEAM,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .thawsUser = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_HYDRO_STEAM,
=======
        .battleAnimScript = gBattleAnimMove_HydroSteam,
>>>>>>> upstream/master
    },

    [MOVE_BLOOD_MOON] =
    {
        .name = COMPOUND_STRING("Blood Moon"),
        .description = COMPOUND_STRING(
            "Unleashes the blood moon.\n"
            "Can't be used twice in a row."),
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .cantUseTwice = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_BLOOD_MOON,
=======
        .battleAnimScript = gBattleAnimMove_BloodMoon,
>>>>>>> upstream/master
    },

    [MOVE_MATCHA_GOTCHA] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MatchaGotcha", "Matcha Gotcha"),
=======
        .name = COMPOUND_STRING("Matcha Gotcha"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Absorbs half the damage\n"
            "inflicted. May cause a burn."),
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 15,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
=======
        .argument = 50,
>>>>>>> upstream/master
        .thawsUser = TRUE,
        .metronomeBanned = TRUE,
        .healingMove = B_EXTRAPOLATED_MOVE_FLAGS,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_BURN,
            .chance = 20,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_MATCHA_GOTCHA,
=======
        .battleAnimScript = gBattleAnimMove_MatchaGotcha,
>>>>>>> upstream/master
    },

    [MOVE_SYRUP_BOMB] =
    {
        .name = COMPOUND_STRING("Syrup Bomb"),
        .description = COMPOUND_STRING(
            "Lowers the foe's speed\n"
            "each turn for 3 turns."),
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ballisticMove = TRUE,
        .metronomeBanned = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SYRUP_BOMB,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_SYRUP_BOMB,
=======
        .battleAnimScript = gBattleAnimMove_SyrupBomb,
>>>>>>> upstream/master
    },

    [MOVE_IVY_CUDGEL] =
    {
        .name = COMPOUND_STRING("Ivy Cudgel"),
        .description = COMPOUND_STRING(
            "Type changes with held mask.\n"
            "High critical-hit ratio."),
        .effect = EFFECT_IVY_CUDGEL,
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .criticalHitStage = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .metronomeBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_IVY_CUDGEL,
=======
        .battleAnimScript = gBattleAnimMove_IvyCudgel,
>>>>>>> upstream/master
    },

    [MOVE_ELECTRO_SHOT] =
    {
        .name = COMPOUND_STRING("Electro Shot"),
        .description = COMPOUND_STRING(
            "Gathers electricity, then\n"
            "fires a high-voltage shot."),
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = TWO_TURN_ARG(STRINGID_ELECTROSHOTCHARGING, B_WEATHER_RAIN),
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_SP_ATK_PLUS_1,
            .self = TRUE,
            .onChargeTurnOnly = TRUE,
<<<<<<< HEAD
        }, SHEER_FORCE_HACK),
        .battleAnimScript = Move_ELECTRO_SHOT,
=======
            .sheerForceBoost = SHEER_FORCE_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_ElectroShot,
>>>>>>> upstream/master
    },

    [MOVE_TERA_STARSTORM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("TeraStarstrm", "Tera Starstorm"),
=======
        .name = COMPOUND_STRING("Tera Starstorm"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "In Terapagos's Stellar\n"
            "Form, it hits all foes."),
        .effect = EFFECT_TERA_STARSTORM,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .assistBanned = TRUE,
        .copycatBanned = TRUE,
        .mimicBanned = TRUE,
        .sketchBanned = (B_SKETCH_BANS >= GEN_9),
<<<<<<< HEAD
        .battleAnimScript = Move_TERA_STARSTORM,
=======
        .battleAnimScript = gBattleAnimMove_TeraStarstorm,
>>>>>>> upstream/master
    },

    [MOVE_FICKLE_BEAM] =
    {
        .name = COMPOUND_STRING("Fickle Beam"),
        .description = COMPOUND_STRING(
            "Shoots a beam of light.\n"
            "Sometimes twice as strong."),
        .effect = EFFECT_FICKLE_BEAM,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .battleAnimScript = Move_FICKLE_BEAM,
=======
        .battleAnimScript = gBattleAnimMove_FickleBeam,
>>>>>>> upstream/master
    },

    [MOVE_BURNING_BULWARK] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("BurnngBulwrk", "Burning Bulwark"),
=======
        .name = COMPOUND_STRING("Burning Bulwark"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Evades attack, and burns\n"
            "the foe if struck."),
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
        .zMove = { .effect = Z_EFFECT_RESET_STATS },
        .ignoresProtect = TRUE,
        .mirrorMoveBanned = TRUE,
        .metronomeBanned = TRUE,
        .copycatBanned = TRUE,
        .assistBanned = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_BURNING_BULWARK,
=======
        .battleAnimScript = gBattleAnimMove_BurningBulwark,
>>>>>>> upstream/master
    },

    [MOVE_THUNDERCLAP] =
    {
        .name = COMPOUND_STRING("Thunderclap"),
        .description = sSuckerPunchDescription,
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .battleAnimScript = Move_THUNDERCLAP,
=======
        .battleAnimScript = gBattleAnimMove_Thunderclap,
>>>>>>> upstream/master
    },

    [MOVE_MIGHTY_CLEAVE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MightyCleave", "Mighty Cleave"),
=======
        .name = COMPOUND_STRING("Mighty Cleave"),
>>>>>>> upstream/master
        .description = sFeintDescription,
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .ignoresProtect = TRUE,
        .slicingMove = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_MIGHTY_CLEAVE,
=======
        .battleAnimScript = gBattleAnimMove_MightyCleave,
>>>>>>> upstream/master
    },

    [MOVE_TACHYON_CUTTER] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("TachyonCuttr", "Tachyon Cutter"),
=======
        .name = COMPOUND_STRING("Tachyon Cutter"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Launches particle blades at\n"
            "the target. Strikes twice."),
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .strikeCount = 2,
        .slicingMove = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_TACHYON_CUTTER,
=======
        .battleAnimScript = gBattleAnimMove_TachyonCutter,
>>>>>>> upstream/master
    },

    [MOVE_HARD_PRESS] =
    {
        .name = COMPOUND_STRING("Hard Press"),
        .description = sWringOutDescription,
<<<<<<< HEAD
        .effect = EFFECT_VARY_POWER_BASED_ON_HP,
        .power = 1,
=======
        .effect = EFFECT_POWER_BASED_ON_TARGET_HP,
        .power = 100,
>>>>>>> upstream/master
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .argument = 100,
        .makesContact = TRUE,
        .battleAnimScript = Move_HARD_PRESS,
=======
        .makesContact = TRUE,
        .battleAnimScript = gBattleAnimMove_HardPress,
>>>>>>> upstream/master
    },

    [MOVE_DRAGON_CHEER] =
    {
        .name = COMPOUND_STRING("Dragon Cheer"),
        .description = COMPOUND_STRING(
            "Increases allies' critical hit\n"
            "ratio, especially if Dragons."),
        .effect = EFFECT_DRAGON_CHEER,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 15,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
        .ignoresSubstitute = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_DRAGON_CHEER,
=======
        .battleAnimScript = gBattleAnimMove_DragonCheer,
>>>>>>> upstream/master
    },

    [MOVE_ALLURING_VOICE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("AllurngVoice", "Alluring Voice"),
=======
        .name = COMPOUND_STRING("Alluring Voice"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Confuses foe if its stats\n"
            "were boosted this turn."),
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_CONFUSION,
            .onlyIfTargetRaisedStats = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_ALLURING_VOICE,
=======
        .battleAnimScript = gBattleAnimMove_AlluringVoice,
>>>>>>> upstream/master
    },

    [MOVE_TEMPER_FLARE] =
    {
        .name = COMPOUND_STRING("Temper Flare"),
        .description = COMPOUND_STRING(
            "A desperation attack. Power\n"
            "doubles if last move failed."),
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_TEMPER_FLARE,
=======
        .battleAnimScript = gBattleAnimMove_TemperFlare,
>>>>>>> upstream/master
    },

    [MOVE_SUPERCELL_SLAM] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("SuprcellSlam", "Supercell Slam"),
=======
        .name = COMPOUND_STRING("Supercell Slam"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "An electrified slam. If it\n"
            "misses, the user is hurt."),
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SUPERCELL_SLAM,
=======
        .minimizeDoubleDamage = TRUE,
        .battleAnimScript = gBattleAnimMove_SupercellSlam,
>>>>>>> upstream/master
    },

    [MOVE_PSYCHIC_NOISE] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("PsychicNoise", "Psychic Noise"),
=======
        .name = COMPOUND_STRING("Psychic Noise"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "Unpleasant sound waves that\n"
            "damage and prevent healing."),
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PSYCHIC_NOISE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_PSYCHIC_NOISE,
=======
        .battleAnimScript = gBattleAnimMove_PsychicNoise,
>>>>>>> upstream/master
    },

    [MOVE_UPPER_HAND] =
    {
        .effect = EFFECT_UPPER_HAND,
        .name = COMPOUND_STRING("Upper Hand"),
        .description = COMPOUND_STRING(
            "Makes the target flinch if\n"
            "readying a priority move."),
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .makesContact = TRUE,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_FLINCH,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_UPPER_HAND,
=======
        .battleAnimScript = gBattleAnimMove_UpperHand,
>>>>>>> upstream/master
    },

    [MOVE_MALIGNANT_CHAIN] =
    {
<<<<<<< HEAD
        .name = HANDLE_EXPANDED_MOVE_NAME("MalignntChan", "Malignant Chain"),
=======
        .name = COMPOUND_STRING("Malignant Chain"),
>>>>>>> upstream/master
        .description = COMPOUND_STRING(
            "A corrosive chain attack\n"
            "that may badly poison."),
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 5,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_TOXIC,
            .chance = 50,
<<<<<<< HEAD
        }),
        .battleAnimScript = Move_MALIGNANT_CHAIN,
=======
            .sheerForceBoost = SHEER_FORCE_BOOST,
        }),
        .battleAnimScript = gBattleAnimMove_MalignantChain,
>>>>>>> upstream/master
    },

    // Z-Moves
    [MOVE_BREAKNECK_BLITZ] =
    {
        .name = COMPOUND_STRING("Breakneck Blitz"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,    //determined from move type
<<<<<<< HEAD
        .battleAnimScript = Move_BREAKNECK_BLITZ,
=======
        .battleAnimScript = gBattleAnimMove_BreakneckBlitz,
>>>>>>> upstream/master
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
        .name = COMPOUND_STRING("All Out Pummeling"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_ALL_OUT_PUMMELING,
=======
        .battleAnimScript = gBattleAnimMove_AllOutPummeling,
>>>>>>> upstream/master
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
        .name = COMPOUND_STRING("Supersonic Skystrike"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_SUPERSONIC_SKYSTRIKE,
=======
        .battleAnimScript = gBattleAnimMove_SupersonicSkystrike,
>>>>>>> upstream/master
    },
    [MOVE_ACID_DOWNPOUR] =
    {
        .name = COMPOUND_STRING("Acid Downpour"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_ACID_DOWNPOUR,
=======
        .battleAnimScript = gBattleAnimMove_AcidDownpour,
>>>>>>> upstream/master
    },
    [MOVE_TECTONIC_RAGE] =
    {
        .name = COMPOUND_STRING("Tectonic Rage"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
<<<<<<< HEAD
        .battleAnimScript = Move_TECTONIC_RAGE,
=======
        .battleAnimScript = gBattleAnimMove_TectonicRage,
>>>>>>> upstream/master
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
        .name = COMPOUND_STRING("Continental Crush"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_CONTINENTAL_CRUSH,
=======
        .battleAnimScript = gBattleAnimMove_ContinentalCrush,
>>>>>>> upstream/master
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
        .name = COMPOUND_STRING("Savage Spin Out"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_SAVAGE_SPIN_OUT,
=======
        .battleAnimScript = gBattleAnimMove_SavageSpinOut,
>>>>>>> upstream/master
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
        .name = COMPOUND_STRING("Never Ending Nightmare"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_NEVER_ENDING_NIGHTMARE,
=======
        .battleAnimScript = gBattleAnimMove_NeverEndingNightmare,
>>>>>>> upstream/master
    },
    [MOVE_CORKSCREW_CRASH] =
    {
        .name = COMPOUND_STRING("Corkscrew Crash"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_CORKSCREW_CRASH,
=======
        .battleAnimScript = gBattleAnimMove_CorkscrewCrash,
>>>>>>> upstream/master
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
        .name = COMPOUND_STRING("Inferno Overdrive"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_INFERNO_OVERDRIVE,
=======
        .battleAnimScript = gBattleAnimMove_InfernoOverdrive,
>>>>>>> upstream/master
    },
    [MOVE_HYDRO_VORTEX] =
    {
        .name = COMPOUND_STRING("Hydro Vortex"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_HYDRO_VORTEX,
=======
        .battleAnimScript = gBattleAnimMove_HydroVortex,
>>>>>>> upstream/master
    },
    [MOVE_BLOOM_DOOM] =
    {
        .name = COMPOUND_STRING("Bloom Doom"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_BLOOM_DOOM,
=======
        .battleAnimScript = gBattleAnimMove_BloomDoom,
>>>>>>> upstream/master
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
        .name = COMPOUND_STRING("Gigavolt Havoc"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_GIGAVOLT_HAVOC,
=======
        .battleAnimScript = gBattleAnimMove_GigavoltHavoc,
>>>>>>> upstream/master
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
        .name = COMPOUND_STRING("Shattered Psyche"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_SHATTERED_PSYCHE,
=======
        .battleAnimScript = gBattleAnimMove_ShatteredPsyche,
>>>>>>> upstream/master
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
        .name = COMPOUND_STRING("Subzero Slammer"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_SUBZERO_SLAMMER,
=======
        .battleAnimScript = gBattleAnimMove_SubzeroSlammer,
>>>>>>> upstream/master
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
        .name = COMPOUND_STRING("Devastating Drake"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_DEVASTATING_DRAKE,
=======
        .battleAnimScript = gBattleAnimMove_DevastatingDrake,
>>>>>>> upstream/master
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
        .name = COMPOUND_STRING("Black Hole Eclipse"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_BLACK_HOLE_ECLIPSE,
=======
        .battleAnimScript = gBattleAnimMove_BlackHoleEclipse,
>>>>>>> upstream/master
    },
    [MOVE_TWINKLE_TACKLE] =
    {
        .name = COMPOUND_STRING("Twinkle Tackle"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_TWINKLE_TACKLE,
=======
        .battleAnimScript = gBattleAnimMove_TwinkleTackle,
>>>>>>> upstream/master
    },
    [MOVE_CATASTROPIKA] =
    {
        .name = COMPOUND_STRING("Catastropika"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_CATASTROPIKA,
=======
        .battleAnimScript = gBattleAnimMove_Catastropika,
>>>>>>> upstream/master
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
        .name = COMPOUND_STRING("10,000,000 Volt Thunderbolt"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .criticalHitStage = 2,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .battleAnimScript = Move_10000000_VOLT_THUNDERBOLT,
=======
        .battleAnimScript = gBattleAnimMove_10000000VoltThunderbolt,
>>>>>>> upstream/master
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
        .name = COMPOUND_STRING("Stoked Sparksurfer"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 175,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_PARALYSIS,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_STOKED_SPARKSURFER,
=======
        .battleAnimScript = gBattleAnimMove_StokedSparksurfer,
>>>>>>> upstream/master
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
        .name = COMPOUND_STRING("Extreme Evoboost"),
        .description = sNullDescription,
        .effect = EFFECT_EXTREME_EVOBOOST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .category = DAMAGE_CATEGORY_STATUS,
<<<<<<< HEAD
        .battleAnimScript = Move_EXTREME_EVOBOOST,
=======
        .battleAnimScript = gBattleAnimMove_ExtremeEvoboost,
>>>>>>> upstream/master
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
        .name = COMPOUND_STRING("Pulverizing Pancake"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_PULVERIZING_PANCAKE,
=======
        .battleAnimScript = gBattleAnimMove_PulverizingPancake,
>>>>>>> upstream/master
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
        .name = COMPOUND_STRING("Genesis Supernova"),
        .description = sNullDescription,
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 185,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .argument = ARG_SET_PSYCHIC_TERRAIN, // Set Psychic Terrain. If there's a different field terrain active, overwrite it.
<<<<<<< HEAD
        .battleAnimScript = Move_GENESIS_SUPERNOVA,
=======
        .battleAnimScript = gBattleAnimMove_GenesisSupernova,
>>>>>>> upstream/master
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
        .name = COMPOUND_STRING("Sinister Arrow Raid"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_SINISTER_ARROW_RAID,
=======
        .battleAnimScript = gBattleAnimMove_SinisterArrowRaid,
>>>>>>> upstream/master
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
        .name = COMPOUND_STRING("Malicious Moonsault"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_MALICIOUS_MOONSAULT,
=======
        .battleAnimScript = gBattleAnimMove_MaliciousMoonsault,
>>>>>>> upstream/master
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
        .name = COMPOUND_STRING("Oceanic Operetta"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .battleAnimScript = Move_OCEANIC_OPERETTA,
=======
        .battleAnimScript = gBattleAnimMove_OceanicOperetta,
>>>>>>> upstream/master
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
        .name = COMPOUND_STRING("Splintered Stormshards"),
        .description = sNullDescription,
        .effect = EFFECT_HIT_SET_REMOVE_TERRAIN,
        .power = 190,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = ARG_TRY_REMOVE_TERRAIN_HIT,  // Remove the active field terrain if there is one.
<<<<<<< HEAD
        .battleAnimScript = Move_SPLINTERED_STORMSHARDS,
=======
        .battleAnimScript = gBattleAnimMove_SplinteredStormshards,
>>>>>>> upstream/master
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
        .name = COMPOUND_STRING("Let's Snuggle Forever"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 190,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_LETS_SNUGGLE_FOREVER,
=======
        .battleAnimScript = gBattleAnimMove_LetsSnuggleForever,
>>>>>>> upstream/master
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
        .name = COMPOUND_STRING("Clangorous Soulblaze"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 185,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .soundMove = TRUE,
        .ignoresSubstitute = B_UPDATED_MOVE_FLAGS >= GEN_6,
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_ALL_STATS_UP,
            .self = TRUE,
            .chance = 100,
        }),
<<<<<<< HEAD
        .battleAnimScript = Move_CLANGOROUS_SOULBLAZE,
=======
        .battleAnimScript = gBattleAnimMove_ClangorousSoulblaze,
>>>>>>> upstream/master
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
        .name = COMPOUND_STRING("Guardian of Alola"),
        .description = sNullDescription,
        .effect = EFFECT_GUARDIAN_OF_ALOLA,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
<<<<<<< HEAD
        .battleAnimScript = Move_GUARDIAN_OF_ALOLA,
=======
        .battleAnimScript = gBattleAnimMove_GuardianOfAlola,
>>>>>>> upstream/master
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
        .name = COMPOUND_STRING("Searing Sunraze Smash"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .ignoresTargetAbility = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_SEARING_SUNRAZE_SMASH,
=======
        .battleAnimScript = gBattleAnimMove_SearingSunrazeSmash,
>>>>>>> upstream/master
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
        .name = COMPOUND_STRING("Menacing Moonraze Maelstrom"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_MENACING_MOONRAZE_MAELSTROM,
=======
        .battleAnimScript = gBattleAnimMove_MenacingMoonrazeMaelstrom,
>>>>>>> upstream/master
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
        .name = COMPOUND_STRING("Light That Burns The Sky"),
        .description = sNullDescription,
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 200,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_SPECIAL,
        .ignoresTargetAbility = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_LIGHT_THAT_BURNS_THE_SKY,
=======
        .battleAnimScript = gBattleAnimMove_LightThatBurnsTheSky,
>>>>>>> upstream/master
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
        .name = COMPOUND_STRING("Soul Stealing 7 Star Strike"),
        .description = sNullDescription,
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
<<<<<<< HEAD
        .battleAnimScript = Move_SOUL_STEALING_7_STAR_STRIKE,
=======
        .battleAnimScript = gBattleAnimMove_SoulStealing7StarStrike,
>>>>>>> upstream/master
    },

    [MOVE_MAX_GUARD] =
    {
        .name = COMPOUND_STRING("Max Guard"),
        .description = sNullDescription,
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .category = DAMAGE_CATEGORY_STATUS,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_GUARD,
=======
        .battleAnimScript = gBattleAnimMove_MaxGuard,
>>>>>>> upstream/master
    },

    [MOVE_MAX_FLARE] =
    {
        .name = COMPOUND_STRING("Max Flare"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_SUN,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_FLARE,
=======
        .battleAnimScript = gBattleAnimMove_MaxFlare,
>>>>>>> upstream/master
    },

    [MOVE_MAX_FLUTTERBY] =
    {
        .name = COMPOUND_STRING("Max Flutterby"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_SP_ATK,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_FLUTTERBY,
=======
        .battleAnimScript = gBattleAnimMove_MaxFlutterby,
>>>>>>> upstream/master
    },

    [MOVE_MAX_LIGHTNING] =
    {
        .name = COMPOUND_STRING("Max Lightning"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_ELECTRIC_TERRAIN,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_LIGHTNING,
=======
        .battleAnimScript = gBattleAnimMove_MaxLightning,
>>>>>>> upstream/master
    },

    [MOVE_MAX_STRIKE] =
    {
        .name = COMPOUND_STRING("Max Strike"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_SPEED,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_STRIKE,
=======
        .battleAnimScript = gBattleAnimMove_MaxStrike,
>>>>>>> upstream/master
    },

    [MOVE_MAX_KNUCKLE] =
    {
        .name = COMPOUND_STRING("Max Knuckle"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RAISE_TEAM_ATTACK,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_KNUCKLE,
=======
        .battleAnimScript = gBattleAnimMove_MaxKnuckle,
>>>>>>> upstream/master
    },

    [MOVE_MAX_PHANTASM] =
    {
        .name = COMPOUND_STRING("Max Phantasm"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_DEFENSE,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_PHANTASM,
=======
        .battleAnimScript = gBattleAnimMove_MaxPhantasm,
>>>>>>> upstream/master
    },

    [MOVE_MAX_HAILSTORM] =
    {
        .name = COMPOUND_STRING("Max Hailstorm"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_HAIL,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_HAILSTORM,
=======
        .battleAnimScript = gBattleAnimMove_MaxHailstorm,
>>>>>>> upstream/master
    },

    [MOVE_MAX_OOZE] =
    {
        .name = COMPOUND_STRING("Max Ooze"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RAISE_TEAM_SP_ATK,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_OOZE,
=======
        .battleAnimScript = gBattleAnimMove_MaxOoze,
>>>>>>> upstream/master
    },

    [MOVE_MAX_GEYSER] =
    {
        .name = COMPOUND_STRING("Max Geyser"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RAIN,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_GEYSER,
=======
        .battleAnimScript = gBattleAnimMove_MaxGeyser,
>>>>>>> upstream/master
    },

    [MOVE_MAX_AIRSTREAM] =
    {
        .name = COMPOUND_STRING("Max Airstream"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RAISE_TEAM_SPEED,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_AIRSTREAM,
=======
        .battleAnimScript = gBattleAnimMove_MaxAirstream,
>>>>>>> upstream/master
    },

    [MOVE_MAX_STARFALL] =
    {
        .name = COMPOUND_STRING("Max Starfall"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_MISTY_TERRAIN,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_STARFALL,
=======
        .battleAnimScript = gBattleAnimMove_MaxStarfall,
>>>>>>> upstream/master
    },

    [MOVE_MAX_WYRMWIND] =
    {
        .name = COMPOUND_STRING("Max Wyrmwind"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_ATTACK,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_WYRMWIND,
=======
        .battleAnimScript = gBattleAnimMove_MaxWyrmwind,
>>>>>>> upstream/master
    },

    [MOVE_MAX_MINDSTORM] =
    {
        .name = COMPOUND_STRING("Max Mindstorm"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_PSYCHIC_TERRAIN,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_MINDSTORM,
=======
        .battleAnimScript = gBattleAnimMove_MaxMindstorm,
>>>>>>> upstream/master
    },

    [MOVE_MAX_ROCKFALL] =
    {
        .name = COMPOUND_STRING("Max Rockfall"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_SANDSTORM,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_ROCKFALL,
=======
        .battleAnimScript = gBattleAnimMove_MaxRockfall,
>>>>>>> upstream/master
    },

    [MOVE_MAX_QUAKE] =
    {
        .name = COMPOUND_STRING("Max Quake"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RAISE_TEAM_SP_DEF,
        .skyBattleBanned = B_EXTRAPOLATED_MOVE_FLAGS,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_QUAKE,
=======
        .battleAnimScript = gBattleAnimMove_MaxQuake,
>>>>>>> upstream/master
    },

    [MOVE_MAX_DARKNESS] =
    {
        .name = COMPOUND_STRING("Max Darkness"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_SP_DEF,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_DARKNESS,
=======
        .battleAnimScript = gBattleAnimMove_MaxDarkness,
>>>>>>> upstream/master
    },

    [MOVE_MAX_OVERGROWTH] =
    {
        .name = COMPOUND_STRING("Max Overgrowth"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_GRASSY_TERRAIN,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_OVERGROWTH,
=======
        .battleAnimScript = gBattleAnimMove_MaxOvergrowth,
>>>>>>> upstream/master
    },

    [MOVE_MAX_STEELSPIKE] =
    {
        .name = COMPOUND_STRING("Max Steelspike"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RAISE_TEAM_DEFENSE,
<<<<<<< HEAD
        .battleAnimScript = Move_MAX_STEELSPIKE,
=======
        .battleAnimScript = gBattleAnimMove_MaxSteelspike,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_VINE_LASH] =
    {
        .name = COMPOUND_STRING("G-Max Vine Lash"),
        .description = sNullDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_VINE_LASH,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_VINE_LASH,
=======
        .battleAnimScript = gBattleAnimMove_GMaxVineLash,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_WILDFIRE] =
    {
        .name = COMPOUND_STRING("G-Max Wildfire"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_WILDFIRE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_WILDFIRE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxWildfire,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_CANNONADE] =
    {
        .name = COMPOUND_STRING("G-Max Canonade"),
        .description = sNullDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_CANNONADE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_CANNONADE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxCannonade,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_BEFUDDLE] =
    {
        .name = COMPOUND_STRING("G-Max Befuddle"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_EFFECT_SPORE_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_BEFUDDLE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxBefuddle,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_VOLT_CRASH] =
    {
        .name = COMPOUND_STRING("G-Max Volt Crash"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_PARALYZE_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_VOLT_CRASH,
=======
        .battleAnimScript = gBattleAnimMove_GMaxVoltCrash,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_GOLD_RUSH] =
    {
        .name = COMPOUND_STRING("G-Max Gold Rush"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_CONFUSE_FOES_PAY_DAY,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_GOLD_RUSH,
=======
        .battleAnimScript = gBattleAnimMove_GMaxGoldRush,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_CHI_STRIKE] =
    {
        .name = COMPOUND_STRING("G-Max Chi Strike"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_CRIT_PLUS,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_CHI_STRIKE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxChiStrike,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_TERROR] =
    {
        .name = COMPOUND_STRING("G-Max Terror"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_MEAN_LOOK,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_TERROR,
=======
        .battleAnimScript = gBattleAnimMove_GMaxTerror,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_FOAM_BURST] =
    {
        .name = COMPOUND_STRING("G-Max Foam Burst"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_SPEED_2_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_FOAM_BURST,
=======
        .battleAnimScript = gBattleAnimMove_GMaxFoamBurst,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_RESONANCE] =
    {
        .name = COMPOUND_STRING("G-Max Resonance"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_AURORA_VEIL,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_RESONANCE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxResonance,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_CUDDLE] =
    {
        .name = COMPOUND_STRING("G-Max Cuddle"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_INFATUATE_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_CUDDLE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxCuddle,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_REPLENISH] =
    {
        .name = COMPOUND_STRING("G-Max Replenish"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_RECYCLE_BERRIES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_REPLENISH,
=======
        .battleAnimScript = gBattleAnimMove_GMaxReplenish,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_MALODOR] =
    {
        .name = COMPOUND_STRING("G-Max Malodor"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_POISON_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_MALODOR,
=======
        .battleAnimScript = gBattleAnimMove_GMaxMalodor,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_MELTDOWN] =
    {
        .name = COMPOUND_STRING("G-Max Meltdown"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_TORMENT_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_MELTDOWN,
=======
        .battleAnimScript = gBattleAnimMove_GMaxMeltdown,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_DRUM_SOLO] =
    {
        .name = COMPOUND_STRING("G-Max Drum Solo"),
        .description = sNullDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_FIXED_POWER,
        .ignoresTargetAbility = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_DRUM_SOLO,
=======
        .battleAnimScript = gBattleAnimMove_GMaxDrumSolo,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_FIREBALL] =
    {
        .name = COMPOUND_STRING("G-Max Fireball"),
        .description = sNullDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_FIXED_POWER,
        .ignoresTargetAbility = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_FIREBALL,
=======
        .battleAnimScript = gBattleAnimMove_GMaxFireball,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_HYDROSNIPE] =
    {
        .name = COMPOUND_STRING("G-Max Hydrosnipe"),
        .description = sNullDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_FIXED_POWER,
        .ignoresTargetAbility = TRUE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_HYDROSNIPE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxHydrosnipe,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_WIND_RAGE] =
    {
        .name = COMPOUND_STRING("G-Max Wind Rage"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_DEFOG,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_WIND_RAGE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxWindRage,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_GRAVITAS] =
    {
        .name = COMPOUND_STRING("G-Max Gravitas"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_GRAVITY,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_GRAVITAS,
=======
        .battleAnimScript = gBattleAnimMove_GMaxGravitas,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_STONESURGE] =
    {
        .name = COMPOUND_STRING("G-Max Stonesurge"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_STEALTH_ROCK,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_STONESURGE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxStonesurge,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_VOLCALITH] =
    {
        .name = COMPOUND_STRING("G-Max Volcalith"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_VOLCALITH,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_VOLCALITH,
=======
        .battleAnimScript = gBattleAnimMove_GMaxVolcalith,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_TARTNESS] =
    {
        .name = COMPOUND_STRING("G-Max Tartness"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_LOWER_EVASIVENESS_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_TARTNESS,
=======
        .battleAnimScript = gBattleAnimMove_GMaxTartness,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_SWEETNESS] =
    {
        .name = COMPOUND_STRING("G-Max Sweetness"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_AROMATHERAPY,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_SWEETNESS,
=======
        .battleAnimScript = gBattleAnimMove_GMaxSweetness,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_SANDBLAST] =
    {
        .name = COMPOUND_STRING("G-Max Sandblast"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_SANDBLAST_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_SANDBLAST,
=======
        .battleAnimScript = gBattleAnimMove_GMaxSandblast,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_STUN_SHOCK] =
    {
        .name = COMPOUND_STRING("G-Max Stun Shock"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_POISON_PARALYZE_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_STUN_SHOCK,
=======
        .battleAnimScript = gBattleAnimMove_GMaxStunShock,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_CENTIFERNO] =
    {
        .name = COMPOUND_STRING("G-Max Centiferno"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_FIRE_SPIN_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_CENTIFERNO,
=======
        .battleAnimScript = gBattleAnimMove_GMaxCentiferno,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_SMITE] =
    {
        .name = COMPOUND_STRING("G-Max Smite"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_CONFUSE_FOES,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_SMITE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxSmite,
>>>>>>> upstream/master
    },


    [MOVE_G_MAX_SNOOZE] =
    {
        .name = COMPOUND_STRING("G-Max Snooze"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_YAWN_FOE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_SNOOZE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxSnooze,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_FINALE] =
    {
        .name = COMPOUND_STRING("G-Max Finale"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_HEAL_TEAM,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_FINALE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxFinale,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_STEELSURGE] =
    {
        .name = COMPOUND_STRING("G-Max Steelsurge"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_STEELSURGE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_STEELSURGE,
=======
        .battleAnimScript = gBattleAnimMove_GMaxSteelsurge,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_DEPLETION] =
    {
        .name = COMPOUND_STRING("G-Max Depletion"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_SPITE,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_DEPLETION,
=======
        .battleAnimScript = gBattleAnimMove_GMaxDepletion,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_ONE_BLOW] =
    {
        .name = COMPOUND_STRING("G-Max One Blow"),
        .description = sNullDescription,
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_BYPASS_PROTECT,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_ONE_BLOW,
=======
        .battleAnimScript = gBattleAnimMove_GMaxOneBlow,
>>>>>>> upstream/master
    },

    [MOVE_G_MAX_RAPID_FLOW] =
    {
        .name = COMPOUND_STRING("G-Max Rapid Flow"),
        .description = sNullDescription,    //ANIM TODO
        .effect = EFFECT_MAX_MOVE,
        .power = 10,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .argument = MAX_EFFECT_BYPASS_PROTECT,
<<<<<<< HEAD
        .battleAnimScript = Move_G_MAX_RAPID_FLOW,
=======
        .battleAnimScript = gBattleAnimMove_GMaxRapidFlow,
>>>>>>> upstream/master
    },

};
