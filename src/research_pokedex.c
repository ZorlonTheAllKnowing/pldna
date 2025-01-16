#include "global.h"
#include "research_pokedex.h"
#include "palette.h"
#include "main.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "task.h"
#include "malloc.h"
#include "decompress.h"
#include "bg.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "overworld.h"
#include "menu.h"
#include "pokedex.h"
#include "constants/rgb.h"

#include "trainer_pokemon_sprites.h"
#include "international_string_util.h"
#include "image_processing_effects.h"
#include "menu_helpers.h"
#include "graphics.h"
#include "pokemon_summary_screen.h"
#include "pokemon.h"
#include "bitmap_drawer.h"
#include "pokemon_icon.h"

// General functions
void Task_StartResearchPokedex_FromOverworldMenu(u8);
static void MainCB2(void);
static void VBlankCB(void);
static void FadeAndBail(void);
static void Task_ResearchPokedexFadeAndBail(u8);
static void FreeResources(void);
static void Task_ResearchPokedexFadeOut(u8);

// Scrolling List Page
void Task_StartListPage(u8);
void ResearchPokedex_ListPage_Init(MainCallback);
void CB2_ListPageSetUp(void);
static bool8 ListPage_InitBgs(void);
static bool8 ListPage_LoadGraphics(void);
static void ListPage_InitWindows(void);
static void Task_ListPageWaitFadeIn(u8);
static void DisplayMagnifierListText(void);
static void DisplayMagnifierLineItemText(u16, u8, u8, u8);
static void ListPage_DisplayCurrentPokemonPicture(void);
static void GetCurrentPokemonBackground(void);
static void DisplayCurrentPokemonCategoryTypeText(void);
static void DisplayCaughtMasteredPokemonCount(void);
static void DisplayListPageResearchLevel(void);
static void DisplayCurrentPokemonType(void);
u16 getTypePalette(u8 type);
static void UpdateListDisplay(void);
static void Task_ListPageInput(u8);
static void CleanUpListPage(void);

// Info Pages
void Task_StartInfoPage(u8);
void ResearchPokedex_InfoPage_Init(MainCallback);
void CB2_InfoPageSetUp(void);
static bool8 InfoPage_InitBgs(void);
static bool8 InfoPage_LoadGraphics(void);
static void InfoPage_InitWindows(void);
static void Task_InfoPageWaitFadeIn(u8);
static void InfoPage_UpdateDisplay(void);
static void InfoPage_DisplayNameAndNumber(void);
static void InfoPage_DisplayPokedexEntry(void);
static void InfoPage_DisplayPokemonWeight(void);
static void InfoPage_DisplayPokemonPicture(void);
static void InfoPage_DisplayEggGroup(void);
static void Task_InfoPageInput(u8);
static void InfoPage_CleanUp(void);

// Stat Pages
void Task_StartStatPage(u8);
void ResearchPokedex_StatPage_Init(MainCallback);
void CB2_StatPageSetUp(void);
static bool8 StatPage_InitBgs(void);
static bool8 StatPage_LoadGraphics(void);
static void StatPage_InitWindows(void);
static void Task_StatPageWaitFadeIn(u8);
static void StatPage_UpdateDisplay(void);
static void StatPage_DisplayNameAndNumber(void);
static void StatPage_DisplayCurrentPokemonIcon(void);
static void InfoPage_DisplayStatRadar(void);
static void Task_StatPageInput(u8);
static void StatPage_CleanUp(void);

// Area Pages
void Task_StartAreaPage(u8);
void ResearchPokedex_AreaPage_Init(MainCallback);
void CB2_AreaPageSetUp(void);
static bool8 AreaPage_InitBgs(void);
static bool8 AreaPage_LoadGraphics(void);
static void AreaPage_InitWindows(void);
static void Task_AreaPageWaitFadeIn(u8);
static void Task_AreaPageInput(u8);

// Task Pages
void Task_StartTaskPage(u8);
void ResearchPokedex_TaskPage_Init(MainCallback);
void CB2_TaskPageSetUp(void);
static bool8 TaskPage_InitBgs(void);
static bool8 TaskPage_LoadGraphics(void);
static void TaskPage_InitWindows(void);
static void Task_TaskPageWaitFadeIn(u8);
static void Task_TaskPageInput(u8);

// Form Pages
void Task_StartFormPage(u8);
void ResearchPokedex_FormPage_Init(MainCallback);
void CB2_FormPageSetUp(void);
static bool8 FormPage_InitBgs(void);
static bool8 FormPage_LoadGraphics(void);
static void FormPage_InitWindows(void);
static void Task_FormPageWaitFadeIn(u8);
static void Task_FormPageInput(u8);

// Move Pages
void Task_StartMovePage(u8);
void ResearchPokedex_MovePage_Init(MainCallback);
void CB2_MovePageSetUp(void);
static bool8 MovePage_InitBgs(void);
static bool8 MovePage_LoadGraphics(void);
static void MovePage_InitWindows(void);
static void Task_MovePageWaitFadeIn(u8);
static void Task_MovePageInput(u8);

// Getters and Setters
u16 GetResearchDexSeenCount(void);
u16 GetResearchDexMasteredCount(void);

static EWRAM_DATA struct ResearchPokedexState *sResearchPokedexState = NULL;
static EWRAM_DATA u8 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg3TilemapBuffer = NULL;

static const u8 sText_PokedexListItem[] = _("Pg {STR_VAR_1}-{STR_VAR_2}");
static const u8 sText_SingleSpace[] = _(" ");
static const u8 sText_TenDashes[] = _("----------");
static const u8 sText_ResearchLevelText[] = _("Research Level");
static const u8 sText_Stats_eggGroup_Groups[] = _("{STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_Stats_eggGroup_MONSTER[] = _("Monster");
static const u8 sText_Stats_eggGroup_WATER_1[] = _("Water {CIRCLE_1}");
static const u8 sText_Stats_eggGroup_BUG[] = _("Bug");
static const u8 sText_Stats_eggGroup_FLYING[] = _("Flying");
static const u8 sText_Stats_eggGroup_FIELD[] = _("Field");
static const u8 sText_Stats_eggGroup_FAIRY[] = _("Fairy");
static const u8 sText_Stats_eggGroup_GRASS[] = _("Grass");
static const u8 sText_Stats_eggGroup_HUMAN_LIKE[] = _("Human-like");
static const u8 sText_Stats_eggGroup_WATER_3[] = _("Water {CIRCLE_3}");
static const u8 sText_Stats_eggGroup_MINERAL[] = _("Mineral");
static const u8 sText_Stats_eggGroup_AMORPHOUS[] = _("Amorphous");
static const u8 sText_Stats_eggGroup_WATER_2[] = _("Water {CIRCLE_2}");
static const u8 sText_Stats_eggGroup_DITTO[] = _("Ditto");
static const u8 sText_Stats_eggGroup_DRAGON[] = _("Dragon");
static const u8 sText_Stats_eggGroup_NO_EGGS_DISCOVERED[] = _("---");
static const u8 sText_Stats_eggGroup_UNKNOWN[] = _("???");

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u8 researchLevel;
};

// This is the object that is keeping track of whatever state the pokedex is in.
// It tracks what pokemon is currently being looked at, as well as useful things like
// what callback to use in case of an error.
struct ResearchPokedexState
{
    struct PokedexListItem pokedexList[HIGHEST_MON_NUMBER];
    MainCallback savedCallback;
    u8 loadState;
    u8 mode;
    u8 monSpriteId;
    u16 selectedPokemon;
    u16 caughtCount;
    u8 currentPage;
    u8 typeIcon1;
    u8 typeIcon2;
};

//MARK:GENERAL FUNCTIONS

void Task_StartResearchPokedex_FromOverworldMenu(u8 taskId)
{
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);
    sBg0TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg3TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sResearchPokedexState = AllocZeroed(sizeof(struct ResearchPokedexState)); 
    //Grant some pokemon, for development purposes
    sResearchPokedexState->pokedexList[1].seen = TRUE;
    sResearchPokedexState->pokedexList[2].seen = TRUE;
    sResearchPokedexState->pokedexList[3].seen = TRUE;
    sResearchPokedexState->pokedexList[4].seen = TRUE;
    sResearchPokedexState->pokedexList[5].seen = TRUE;
    sResearchPokedexState->pokedexList[6].seen = TRUE;
    sResearchPokedexState->pokedexList[7].seen = TRUE;
    sResearchPokedexState->pokedexList[8].seen = TRUE;
    sResearchPokedexState->pokedexList[9].seen = TRUE;
    sResearchPokedexState->pokedexList[10].seen = TRUE;
    sResearchPokedexState->pokedexList[11].seen = TRUE;
    sResearchPokedexState->pokedexList[12].seen = TRUE;

    sResearchPokedexState->pokedexList[1].researchLevel = 1;
    sResearchPokedexState->pokedexList[2].researchLevel = 2;
    sResearchPokedexState->pokedexList[3].researchLevel = 3;
    sResearchPokedexState->pokedexList[4].researchLevel = 4;
    sResearchPokedexState->pokedexList[5].researchLevel = 5;
    sResearchPokedexState->pokedexList[6].researchLevel = 6;
    sResearchPokedexState->pokedexList[7].researchLevel = 7;
    sResearchPokedexState->pokedexList[8].researchLevel = 8;
    sResearchPokedexState->pokedexList[9].researchLevel = 9;
    sResearchPokedexState->pokedexList[10].researchLevel = 10;
    sResearchPokedexState->pokedexList[11].researchLevel = 10;
    sResearchPokedexState->pokedexList[12].researchLevel = 10;
    //End debugging
    sResearchPokedexState->selectedPokemon = 0;
    sResearchPokedexState->typeIcon1 = 0xFF;
    sResearchPokedexState->typeIcon2 = 0xFF;
    gTasks[taskId].func = Task_StartListPage;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ResearchPokedexFadeAndBail, 0);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(MainCB2);
}

static void Task_ResearchPokedexFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sResearchPokedexState->savedCallback);
        FreeResources();
        DestroyTask(taskId);
    }
}

static void FreeResources(void)
{
    if (sResearchPokedexState != NULL)
    {
        Free(sResearchPokedexState);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}

static void Task_ResearchPokedexFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(sBg0TilemapBuffer);
        Free(sBg1TilemapBuffer);
        Free(sBg2TilemapBuffer);
        Free(sBg3TilemapBuffer);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

//MARK:General Use Graphics

// Palette Slots
// 0-2: Type Icons
// 14: Pokemon Sprites
// 15: General Text
//
//
//
//
//
//
//

//MARK:Type Icons

static const u32 gNormalTypeIcon0[]     = INCBIN_U32("graphics/types/type_icons/normal_research_icon_full.4bpp");
static const u32 gNormalTypeIcon1[]     = INCBIN_U32("graphics/types/type_icons/normal_research_icon1.4bpp");
static const u32 gNormalTypeIcon2[]     = INCBIN_U32("graphics/types/type_icons/normal_research_icon2.4bpp");

static const u32 gFightTypeIcon0[]      = INCBIN_U32("graphics/types/type_icons/fight_research_icon_full.4bpp");
static const u32 gFightTypeIcon1[]      = INCBIN_U32("graphics/types/type_icons/fight_research_icon1.4bpp");
static const u32 gFightTypeIcon2[]      = INCBIN_U32("graphics/types/type_icons/fight_research_icon2.4bpp");

static const u32 gFlyingTypeIcon0[]     = INCBIN_U32("graphics/types/type_icons/flying_research_icon_full.4bpp");
static const u32 gFlyingTypeIcon1[]     = INCBIN_U32("graphics/types/type_icons/flying_research_icon1.4bpp");
static const u32 gFlyingTypeIcon2[]     = INCBIN_U32("graphics/types/type_icons/flying_research_icon2.4bpp");

static const u32 gPoisonTypeIcon0[]     = INCBIN_U32("graphics/types/type_icons/poison_research_icon_full.4bpp");
static const u32 gPoisonTypeIcon1[]     = INCBIN_U32("graphics/types/type_icons/poison_research_icon1.4bpp");
static const u32 gPoisonTypeIcon2[]     = INCBIN_U32("graphics/types/type_icons/poison_research_icon2.4bpp");

static const u32 gGroundTypeIcon0[]     = INCBIN_U32("graphics/types/type_icons/ground_research_icon_full.4bpp");
static const u32 gGroundTypeIcon1[]     = INCBIN_U32("graphics/types/type_icons/ground_research_icon1.4bpp");
static const u32 gGroundTypeIcon2[]     = INCBIN_U32("graphics/types/type_icons/ground_research_icon2.4bpp");

static const u32 gRockTypeIcon0[]       = INCBIN_U32("graphics/types/type_icons/rock_research_icon_full.4bpp");
static const u32 gRockTypeIcon1[]       = INCBIN_U32("graphics/types/type_icons/rock_research_icon1.4bpp");
static const u32 gRockTypeIcon2[]       = INCBIN_U32("graphics/types/type_icons/rock_research_icon2.4bpp");

static const u32 gBugTypeIcon0[]   = INCBIN_U32("graphics/types/type_icons/bug_research_icon_full.4bpp");
static const u32 gBugTypeIcon1[]   = INCBIN_U32("graphics/types/type_icons/bug_research_icon1.4bpp");
static const u32 gBugTypeIcon2[]   = INCBIN_U32("graphics/types/type_icons/bug_research_icon2.4bpp");

static const u32 gGhostTypeIcon0[]      = INCBIN_U32("graphics/types/type_icons/ghost_research_icon_full.4bpp");
static const u32 gGhostTypeIcon1[]      = INCBIN_U32("graphics/types/type_icons/ghost_research_icon1.4bpp");
static const u32 gGhostTypeIcon2[]      = INCBIN_U32("graphics/types/type_icons/ghost_research_icon2.4bpp");

static const u32 gSteelTypeIcon0[]      = INCBIN_U32("graphics/types/type_icons/steel_research_icon_full.4bpp");
static const u32 gSteelTypeIcon1[]      = INCBIN_U32("graphics/types/type_icons/steel_research_icon1.4bpp");
static const u32 gSteelTypeIcon2[]      = INCBIN_U32("graphics/types/type_icons/steel_research_icon2.4bpp");

static const u32 gUnknownTypeIcon0[]     = INCBIN_U32("graphics/types/type_icons/unknown_research_icon_full.4bpp");

static const u32 gFireTypeIcon0[]       = INCBIN_U32("graphics/types/type_icons/fire_research_icon_full.4bpp");
static const u32 gFireTypeIcon1[]       = INCBIN_U32("graphics/types/type_icons/fire_research_icon1.4bpp");
static const u32 gFireTypeIcon2[]       = INCBIN_U32("graphics/types/type_icons/fire_research_icon2.4bpp");

static const u32 gWaterTypeIcon0[]      = INCBIN_U32("graphics/types/type_icons/water_research_icon_full.4bpp");
static const u32 gWaterTypeIcon1[]      = INCBIN_U32("graphics/types/type_icons/water_research_icon1.4bpp");
static const u32 gWaterTypeIcon2[]      = INCBIN_U32("graphics/types/type_icons/water_research_icon2.4bpp");

static const u32 gGrassTypeIcon0[]      = INCBIN_U32("graphics/types/type_icons/grass_research_icon_full.4bpp");
static const u32 gGrassTypeIcon1[]      = INCBIN_U32("graphics/types/type_icons/grass_research_icon1.4bpp");
static const u32 gGrassTypeIcon2[]      = INCBIN_U32("graphics/types/type_icons/grass_research_icon2.4bpp");

static const u32 gElectricTypeIcon0[]   = INCBIN_U32("graphics/types/type_icons/electric_research_icon_full.4bpp");
static const u32 gElectricTypeIcon1[]   = INCBIN_U32("graphics/types/type_icons/electric_research_icon1.4bpp");
static const u32 gElectricTypeIcon2[]   = INCBIN_U32("graphics/types/type_icons/electric_research_icon2.4bpp");

static const u32 gPsychicTypeIcon0[]    = INCBIN_U32("graphics/types/type_icons/psychic_research_icon_full.4bpp");
static const u32 gPsychicTypeIcon1[]    = INCBIN_U32("graphics/types/type_icons/psychic_research_icon1.4bpp");
static const u32 gPsychicTypeIcon2[]    = INCBIN_U32("graphics/types/type_icons/psychic_research_icon2.4bpp");

static const u32 gIceTypeIcon0[]        = INCBIN_U32("graphics/types/type_icons/ice_research_icon_full.4bpp");
static const u32 gIceTypeIcon1[]        = INCBIN_U32("graphics/types/type_icons/ice_research_icon1.4bpp");
static const u32 gIceTypeIcon2[]        = INCBIN_U32("graphics/types/type_icons/ice_research_icon2.4bpp");

static const u32 gDragonTypeIcon0[]     = INCBIN_U32("graphics/types/type_icons/dragon_research_icon_full.4bpp");
static const u32 gDragonTypeIcon1[]     = INCBIN_U32("graphics/types/type_icons/dragon_research_icon1.4bpp");
static const u32 gDragonTypeIcon2[]     = INCBIN_U32("graphics/types/type_icons/dragon_research_icon2.4bpp");

static const u32 gDarkTypeIcon0[]       = INCBIN_U32("graphics/types/type_icons/dark_research_icon_full.4bpp");
static const u32 gDarkTypeIcon1[]       = INCBIN_U32("graphics/types/type_icons/dark_research_icon1.4bpp");
static const u32 gDarkTypeIcon2[]       = INCBIN_U32("graphics/types/type_icons/dark_research_icon2.4bpp");

static const u32 gFairyTypeIcon0[]      = INCBIN_U32("graphics/types/type_icons/fairy_research_icon_full.4bpp");
static const u32 gFairyTypeIcon1[]      = INCBIN_U32("graphics/types/type_icons/fairy_research_icon1.4bpp");
static const u32 gFairyTypeIcon2[]      = INCBIN_U32("graphics/types/type_icons/fairy_research_icon2.4bpp");

//Palettes
#define PALETTE_TAG_TYPES0 0x1000   // This should make it so the palettes used for the type icons
#define PALETTE_TAG_TYPES1 0x1001   // Are in palette slots 0, 1, and 2
#define PALETTE_TAG_TYPES2 0x1002   

static const u16 gTypePalette0[]        = INCBIN_U16("graphics/types/type_icons/typesPalette0.gbapal");
static const u16 gTypePalette1[]        = INCBIN_U16("graphics/types/type_icons/typesPalette1.gbapal");
static const u16 gTypePalette2[]        = INCBIN_U16("graphics/types/type_icons/typesPalette2.gbapal");

//Palette for these types: Normal, Fighting, Ground, Rock, Steel, Fire, Electric, Dark,   
static const struct SpritePalette gTypes0SpritePalette =
{
    .data = gTypePalette0,
    .tag = PALETTE_TAG_TYPES0
};
//Palette for these types: Flying, Poison, Ghost, Water, Psychic, Ice, Fairy,
static const struct SpritePalette gTypes1SpritePalette =
{
    .data = gTypePalette1,
    .tag = PALETTE_TAG_TYPES1
};
//Palette for these types: Unknown, Bug, Mystery, Grass, Dragon, 
static const struct SpritePalette gTypes2SpritePalette =
{
    .data = gTypePalette2,
    .tag = PALETTE_TAG_TYPES2
};

//Anims
#define DEFAULT_ANIM  0
#define SELECTED_ANIM 0

static const union AnimCmd gTypeIconDefaultAnim[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};
static const union AnimCmd *const gTypeIconAnims[] =
{
    [DEFAULT_ANIM] = gTypeIconDefaultAnim
};

//Sprite templates
//Unknown
static const struct OamData gTypeIcon0Oam =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const struct SpriteFrameImage gUnknownTypeIcon0Table[] =
{
    obj_frame_tiles(gUnknownTypeIcon0)
};
static const struct SpriteTemplate gUnknownTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gUnknownTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Normal
static const struct SpriteFrameImage gNormalTypeIcon0Table[] =
{
    obj_frame_tiles(gNormalTypeIcon0)
};
static const struct SpriteTemplate gNormalTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gNormalTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gNormalTypeIcon1Table[] =
{
    obj_frame_tiles(gNormalTypeIcon1)
};
static const struct SpriteTemplate gNormalTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gNormalTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gNormalTypeIcon2Table[] =
{
    obj_frame_tiles(gNormalTypeIcon2)
};
static const struct SpriteTemplate gNormalTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gNormalTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Fighting
static const struct SpriteFrameImage gFightTypeIcon0Table[] =
{
    obj_frame_tiles(gFightTypeIcon0)
};
static const struct SpriteTemplate gFightTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFightTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFightTypeIcon1Table[] =
{
    obj_frame_tiles(gFightTypeIcon1)
};
static const struct SpriteTemplate gFightTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFightTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFightTypeIcon2Table[] =
{
    obj_frame_tiles(gFightTypeIcon2)
};
static const struct SpriteTemplate gFightTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFightTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Flying
static const struct SpriteFrameImage gFlyingTypeIcon0Table[] =
{
    obj_frame_tiles(gFlyingTypeIcon0)
};
static const struct SpriteTemplate gFlyingTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFlyingTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFlyingTypeIcon1Table[] =
{
    obj_frame_tiles(gFlyingTypeIcon1)
};
static const struct SpriteTemplate gFlyingTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFlyingTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFlyingTypeIcon2Table[] =
{
    obj_frame_tiles(gFlyingTypeIcon2)
};
static const struct SpriteTemplate gFlyingTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFlyingTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Poison
static const struct SpriteFrameImage gPoisonTypeIcon0Table[] =
{
    obj_frame_tiles(gPoisonTypeIcon0)
};
static const struct SpriteTemplate gPoisonTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gPoisonTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gPoisonTypeIcon1Table[] =
{
    obj_frame_tiles(gPoisonTypeIcon1)
};
static const struct SpriteTemplate gPoisonTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gPoisonTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gPoisonTypeIcon2Table[] =
{
    obj_frame_tiles(gPoisonTypeIcon2)
};
static const struct SpriteTemplate gPoisonTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gPoisonTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Ground
static const struct SpriteFrameImage gGroundTypeIcon0Table[] =
{
    obj_frame_tiles(gGroundTypeIcon0)
};
static const struct SpriteTemplate gGroundTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGroundTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gGroundTypeIcon1Table[] =
{
    obj_frame_tiles(gGroundTypeIcon1)
};
static const struct SpriteTemplate gGroundTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGroundTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gGroundTypeIcon2Table[] =
{
    obj_frame_tiles(gGroundTypeIcon2)
};
static const struct SpriteTemplate gGroundTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGroundTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Rock
static const struct SpriteFrameImage gRockTypeIcon0Table[] =
{
    obj_frame_tiles(gRockTypeIcon0)
};
static const struct SpriteTemplate gRockTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gRockTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gRockTypeIcon1Table[] =
{
    obj_frame_tiles(gRockTypeIcon1)
};
static const struct SpriteTemplate gRockTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gRockTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gRockTypeIcon2Table[] =
{
    obj_frame_tiles(gRockTypeIcon2)
};
static const struct SpriteTemplate gRockTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gRockTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Bug
static const struct SpriteFrameImage gBugTypeIcon0Table[] =
{
    obj_frame_tiles(gBugTypeIcon0)
};
static const struct SpriteTemplate gBugTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gBugTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gBugTypeIcon1Table[] =
{
    obj_frame_tiles(gBugTypeIcon1)
};
static const struct SpriteTemplate gBugTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gBugTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gBugTypeIcon2Table[] =
{
    obj_frame_tiles(gBugTypeIcon2)
};
static const struct SpriteTemplate gBugTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gBugTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//
static const struct SpriteFrameImage gGhostTypeIcon0Table[] =
{
    obj_frame_tiles(gGhostTypeIcon0)
};
static const struct SpriteTemplate gGhostTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGhostTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gGhostTypeIcon1Table[] =
{
    obj_frame_tiles(gGhostTypeIcon1)
};
static const struct SpriteTemplate gGhostTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGhostTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gGhostTypeIcon2Table[] =
{
    obj_frame_tiles(gGhostTypeIcon2)
};
static const struct SpriteTemplate gGhostTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGhostTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Steel
static const struct SpriteFrameImage gSteelTypeIcon0Table[] =
{
    obj_frame_tiles(gSteelTypeIcon0)
};
static const struct SpriteTemplate gSteelTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gSteelTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gSteelTypeIcon1Table[] =
{
    obj_frame_tiles(gSteelTypeIcon1)
};
static const struct SpriteTemplate gSteelTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gSteelTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gSteelTypeIcon2Table[] =
{
    obj_frame_tiles(gSteelTypeIcon2)
};
static const struct SpriteTemplate gSteelTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gSteelTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Fire
static const struct SpriteFrameImage gFireTypeIcon0Table[] =
{
    obj_frame_tiles(gFireTypeIcon0)
};
static const struct SpriteTemplate gFireTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFireTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFireTypeIcon1Table[] =
{
    obj_frame_tiles(gFireTypeIcon1)
};
static const struct SpriteTemplate gFireTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFireTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFireTypeIcon2Table[] =
{
    obj_frame_tiles(gFireTypeIcon2)
};
static const struct SpriteTemplate gFireTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFireTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Water
static const struct SpriteFrameImage gWaterTypeIcon0Table[] =
{
    obj_frame_tiles(gWaterTypeIcon0)
};
static const struct SpriteTemplate gWaterTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gWaterTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gWaterTypeIcon1Table[] =
{
    obj_frame_tiles(gWaterTypeIcon1)
};
static const struct SpriteTemplate gWaterTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gWaterTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gWaterTypeIcon2Table[] =
{
    obj_frame_tiles(gWaterTypeIcon2)
};
static const struct SpriteTemplate gWaterTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gWaterTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Grass
static const struct SpriteFrameImage gGrassTypeIcon0Table[] =
{
    obj_frame_tiles(gGrassTypeIcon0)
};
static const struct SpriteTemplate gGrassTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGrassTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gGrassTypeIcon1Table[] =
{
    obj_frame_tiles(gGrassTypeIcon1)
};
static const struct SpriteTemplate gGrassTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGrassTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gGrassTypeIcon2Table[] =
{
    obj_frame_tiles(gGrassTypeIcon2)
};
static const struct SpriteTemplate gGrassTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gGrassTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Electric
static const struct SpriteFrameImage gElectricTypeIcon0Table[] =
{
    obj_frame_tiles(gElectricTypeIcon0)
};
static const struct SpriteTemplate gElectricTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gElectricTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gElectricTypeIcon1Table[] =
{
    obj_frame_tiles(gElectricTypeIcon1)
};
static const struct SpriteTemplate gElectricTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gElectricTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gElectricTypeIcon2Table[] =
{
    obj_frame_tiles(gElectricTypeIcon2)
};
static const struct SpriteTemplate gElectricTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gElectricTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Psychic
static const struct SpriteFrameImage gPsychicTypeIcon0Table[] =
{
    obj_frame_tiles(gPsychicTypeIcon0)
};
static const struct SpriteTemplate gPsychicTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gPsychicTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gPsychicTypeIcon1Table[] =
{
    obj_frame_tiles(gPsychicTypeIcon1)
};
static const struct SpriteTemplate gPsychicTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gPsychicTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gPsychicTypeIcon2Table[] =
{
    obj_frame_tiles(gPsychicTypeIcon2)
};
static const struct SpriteTemplate gPsychicTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gPsychicTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Ice
static const struct SpriteFrameImage gIceTypeIcon0Table[] =
{
    obj_frame_tiles(gIceTypeIcon0)
};
static const struct SpriteTemplate gIceTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gIceTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gIceTypeIcon1Table[] =
{
    obj_frame_tiles(gIceTypeIcon1)
};
static const struct SpriteTemplate gIceTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gIceTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gIceTypeIcon2Table[] =
{
    obj_frame_tiles(gIceTypeIcon2)
};
static const struct SpriteTemplate gIceTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gIceTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Dragon
static const struct SpriteFrameImage gDragonTypeIcon0Table[] =
{
    obj_frame_tiles(gDragonTypeIcon0)
};
static const struct SpriteTemplate gDragonTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gDragonTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gDragonTypeIcon1Table[] =
{
    obj_frame_tiles(gDragonTypeIcon1)
};
static const struct SpriteTemplate gDragonTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gDragonTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gDragonTypeIcon2Table[] =
{
    obj_frame_tiles(gDragonTypeIcon2)
};
static const struct SpriteTemplate gDragonTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES2,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gDragonTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Dark
static const struct SpriteFrameImage gDarkTypeIcon0Table[] =
{
    obj_frame_tiles(gDarkTypeIcon0)
};
static const struct SpriteTemplate gDarkTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gDarkTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gDarkTypeIcon1Table[] =
{
    obj_frame_tiles(gDarkTypeIcon1)
};
static const struct SpriteTemplate gDarkTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gDarkTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gDarkTypeIcon2Table[] =
{
    obj_frame_tiles(gDarkTypeIcon2)
};
static const struct SpriteTemplate gDarkTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES0,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gDarkTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
//Fairy
static const struct SpriteFrameImage gFairyTypeIcon0Table[] =
{
    obj_frame_tiles(gFairyTypeIcon0)
};
static const struct SpriteTemplate gFairyTypeIcon0SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFairyTypeIcon0Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFairyTypeIcon1Table[] =
{
    obj_frame_tiles(gFairyTypeIcon1)
};
static const struct SpriteTemplate gFairyTypeIcon1SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFairyTypeIcon1Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteFrameImage gFairyTypeIcon2Table[] =
{
    obj_frame_tiles(gFairyTypeIcon2)
};
static const struct SpriteTemplate gFairyTypeIcon2SpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALETTE_TAG_TYPES1,
    .oam = &gTypeIcon0Oam,
    .anims = gTypeIconAnims,
    .images = gFairyTypeIcon2Table,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// Declare the array of pointers to arrays, with 20 types and 3 icons per type
static const struct SpriteTemplate gTypeIconSpriteTemplates[][3] = {
    { gUnknownTypeIcon0SpriteTemplate, gUnknownTypeIcon0SpriteTemplate, gUnknownTypeIcon0SpriteTemplate }, //None
    { gNormalTypeIcon0SpriteTemplate, gNormalTypeIcon1SpriteTemplate, gNormalTypeIcon2SpriteTemplate },
    { gFightTypeIcon0SpriteTemplate, gFightTypeIcon1SpriteTemplate, gFightTypeIcon2SpriteTemplate },
    { gFlyingTypeIcon0SpriteTemplate, gFlyingTypeIcon1SpriteTemplate, gFlyingTypeIcon2SpriteTemplate },
    { gPoisonTypeIcon0SpriteTemplate, gPoisonTypeIcon1SpriteTemplate, gPoisonTypeIcon2SpriteTemplate },
    { gGroundTypeIcon0SpriteTemplate, gGroundTypeIcon1SpriteTemplate, gGroundTypeIcon2SpriteTemplate },
    { gRockTypeIcon0SpriteTemplate, gRockTypeIcon1SpriteTemplate, gRockTypeIcon2SpriteTemplate },
    { gBugTypeIcon0SpriteTemplate, gBugTypeIcon1SpriteTemplate, gBugTypeIcon2SpriteTemplate },
    { gGhostTypeIcon0SpriteTemplate, gGhostTypeIcon1SpriteTemplate, gGhostTypeIcon2SpriteTemplate },
    { gSteelTypeIcon0SpriteTemplate, gSteelTypeIcon1SpriteTemplate, gSteelTypeIcon2SpriteTemplate },
    { gUnknownTypeIcon0SpriteTemplate, gUnknownTypeIcon0SpriteTemplate, gUnknownTypeIcon0SpriteTemplate }, //Mystery
    { gFireTypeIcon0SpriteTemplate, gFireTypeIcon1SpriteTemplate, gFireTypeIcon2SpriteTemplate },
    { gWaterTypeIcon0SpriteTemplate, gWaterTypeIcon1SpriteTemplate, gWaterTypeIcon2SpriteTemplate },
    { gGrassTypeIcon0SpriteTemplate, gGrassTypeIcon1SpriteTemplate, gGrassTypeIcon2SpriteTemplate },
    { gElectricTypeIcon0SpriteTemplate, gElectricTypeIcon1SpriteTemplate, gElectricTypeIcon2SpriteTemplate },
    { gPsychicTypeIcon0SpriteTemplate, gPsychicTypeIcon1SpriteTemplate, gPsychicTypeIcon2SpriteTemplate },
    { gIceTypeIcon0SpriteTemplate, gIceTypeIcon1SpriteTemplate, gIceTypeIcon2SpriteTemplate },
    { gDragonTypeIcon0SpriteTemplate, gDragonTypeIcon1SpriteTemplate, gDragonTypeIcon2SpriteTemplate },
    { gDarkTypeIcon0SpriteTemplate, gDarkTypeIcon1SpriteTemplate, gDarkTypeIcon2SpriteTemplate },
    { gFairyTypeIcon0SpriteTemplate, gFairyTypeIcon1SpriteTemplate, gFairyTypeIcon2SpriteTemplate },
    { gFlyingTypeIcon0SpriteTemplate, gFlyingTypeIcon1SpriteTemplate, gFlyingTypeIcon2SpriteTemplate },
    { gUnknownTypeIcon0SpriteTemplate, gUnknownTypeIcon0SpriteTemplate, gUnknownTypeIcon0SpriteTemplate } //Stellar
};

//MARK:List Page Graphics
static const u16 sListBackgroundPalette[]   = INCBIN_U16("graphics/pokedex/researchdex/list_background.gbapal");
static const u16 sListPagesPalette[]        = INCBIN_U16("graphics/pokedex/researchdex/list_pages.gbapal");
static const u32 sListBackgroundTilemap[]   = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.bin.lz");
static const u32 sListPagesTilemap[]        = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.bin.lz");
static const u32 sListBackgroundTiles[]     = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.4bpp.lz");
static const u32 sListPagesTiles[]          = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.4bpp.lz");

//MARK:List Page Backgrounds
static const struct BgTemplate sListPageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

//MARK:List Page Windows
#define LISTPAGE_SCROLLING_TEXT 0
#define LISTPAGE_CATEGORY_TYPE  1
#define LISTPAGE_CAUGHT_COUNT  2
#define LISTPAGE_RESEARCH_LEVEL 3

static const struct WindowTemplate sListPageWinTemplates[] =
{
    [LISTPAGE_SCROLLING_TEXT] =
    {
        .bg = BG_SCROLLING_LIST,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [LISTPAGE_CATEGORY_TYPE] =
    {
        .bg = BG_PAGE_CONTENT,
        .tilemapLeft = 18,
        .tilemapTop = 3,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,  // 1 + (14*18)
    },
    [LISTPAGE_CAUGHT_COUNT] =
    {
        .bg = BG_PAGE_CONTENT,
        .tilemapLeft = 9,
        .tilemapTop = 3,
        .width = 4,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 290,  // 1 + (14*18) + (12*3)
    },
    [LISTPAGE_RESEARCH_LEVEL] =
    {
        .bg = BG_PAGE_CONTENT,
        .tilemapLeft = 16,
        .tilemapTop = 15,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 306,  // 1 + (14*18) + (12*3) + (4*4)
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:Info Page Graphics
static const u16 sInfoBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/info_background.gbapal");
static const u16 sInfoPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/info_pages.gbapal");
static const u32 sInfoBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/info_background_tiles.bin.lz");
static const u32 sInfoPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/info_pages_tiles.bin.lz");
static const u32 sInfoBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/info_background_tiles.4bpp.lz");
static const u32 sInfoPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/info_pages_tiles.4bpp.lz");

//MARK:Info Page Backgrounds
static const struct BgTemplate sInfoPageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

#define INFOPAGE_NAME_AND_NUMBER    0
#define INFOPAGE_HEIGHT_AND_WEIGHT  1
#define INFOPAGE_POKEDEX_ENTRY      2
#define INFOPAGE_EGG_GROUPS         3

//MARK:Info Page Windows
static const struct WindowTemplate sInfoPageWinTemplates[] =
{
    [INFOPAGE_NAME_AND_NUMBER] =
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 2,
        .width = 8,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [INFOPAGE_HEIGHT_AND_WEIGHT] =
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 7,
        .width = 7,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 25,  //1 + (8*3)
    },
    [INFOPAGE_POKEDEX_ENTRY] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 11,
        .width = 29,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 53,  //1 + (8*3) + (7*4)
    },
    [INFOPAGE_EGG_GROUPS] =
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 6,
        .width = 9,
        .height = 5,
        .paletteNum = 15,
        .baseBlock = 285,  //1 + (8*3) + (7*4) + (29*8)
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:Stat Page Graphics
static const u16 sStatBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/stat_background.gbapal");
static const u16 sStatPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/stat_pages.gbapal");
static const u32 sStatBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/stat_background_tiles.bin.lz");
static const u32 sStatPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/stat_pages_tiles.bin.lz");
static const u32 sStatBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/stat_background_tiles.4bpp.lz");
static const u32 sStatPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/stat_pages_tiles.4bpp.lz");

static const u16 sRadarChartPalette[] = INCBIN_U16("graphics/pokedex/researchdex/zRadar_chart_fade.gbapal");

//MARK:Stat Page Backgrounds
static const struct BgTemplate sStatPageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

#define STATPAGE_RADAR_CHART    0
#define STATPAGE_NAME_AND_NUMBER    1

//MARK:Stat Page Windows
static const struct WindowTemplate sStatPageWinTemplates[3] =
{
    [STATPAGE_RADAR_CHART] =
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 10,
        .height = 10,
        .paletteNum = 2,
        .baseBlock = 1,
    },
    [STATPAGE_NAME_AND_NUMBER] =
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 2,
        .width = 8,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 101,
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:Area Page Graphics
static const u16 sAreaBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/area_background.gbapal");
static const u16 sAreaPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/area_pages.gbapal");
static const u32 sAreaBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/area_background_tiles.bin.lz");
static const u32 sAreaPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/area_pages_tiles.bin.lz");
static const u32 sAreaBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/area_background_tiles.4bpp.lz");
static const u32 sAreaPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/area_pages_tiles.4bpp.lz");

//MARK:Area Page Backgrounds
static const struct BgTemplate sAreaPageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

//MARK:Area Page Windows
static const struct WindowTemplate sAreaPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 8,
        .tilemapTop = 8,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 8,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:Task Page Graphics
static const u16 sTaskBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/task_background.gbapal");
static const u16 sTaskPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/task_pages.gbapal");
static const u32 sTaskBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/task_background_tiles.bin.lz");
static const u32 sTaskPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/task_pages_tiles.bin.lz");
static const u32 sTaskBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/task_background_tiles.4bpp.lz");
static const u32 sTaskPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/task_pages_tiles.4bpp.lz");

//MARK:Task Page Backgrounds
static const struct BgTemplate sTaskPageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

//MARK:Task Page Windows
static const struct WindowTemplate sTaskPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 10,
        .tilemapTop = 10,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 10,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:Form Page Graphics
static const u16 sFormBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/form_background.gbapal");
static const u16 sFormPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/form_pages.gbapal");
static const u32 sFormBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/form_background_tiles.bin.lz");
static const u32 sFormPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/form_pages_tiles.bin.lz");
static const u32 sFormBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/form_background_tiles.4bpp.lz");
static const u32 sFormPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/form_pages_tiles.4bpp.lz");

//MARK:Form Page Backgrounds
static const struct BgTemplate sFormPageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

//MARK:Form Page Windows
static const struct WindowTemplate sFormPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 12,
        .tilemapTop = 12,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 12,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:Moves Page Graphics
static const u16 sMoveBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/move_background.gbapal");
static const u16 sMovePagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/move_pages.gbapal");
static const u32 sMoveBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/move_background_tiles.bin.lz");
static const u32 sMovePagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/move_pages_tiles.bin.lz");
static const u32 sMoveBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/move_background_tiles.4bpp.lz");
static const u32 sMovePagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/move_pages_tiles.4bpp.lz");

//MARK:Moves Page Backgrounds
static const struct BgTemplate sMovePageBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

//MARK:Moves Page Windows
static const struct WindowTemplate sMovePageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 14,
        .tilemapTop = 14,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 14,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:LIST PAGE
void Task_StartListPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_ListPage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_ListPage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = LIST_PAGE;
    SetMainCallback2(CB2_ListPageSetUp);
}

void CB2_ListPageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (ListPage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (ListPage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        ListPage_InitWindows();
        gMain.state++;
        break;
    case 5:
        UpdateListDisplay();
        CreateTask(Task_ListPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 ListPage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sListPageBgTemplates, ARRAY_COUNT(sListPageBgTemplates));

    SetBgTilemapBuffer(BG_PAGE_CONTENT, sBg0TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_PAGES, sBg1TilemapBuffer);
    SetBgTilemapBuffer(BG_SCROLLING_LIST, sBg2TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_COVER, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(BG_PAGE_CONTENT);
    ScheduleBgCopyTilemapToVram(BG_BOOK_PAGES);
    ScheduleBgCopyTilemapToVram(BG_SCROLLING_LIST);
    ScheduleBgCopyTilemapToVram(BG_BOOK_COVER);

    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = LIST_PAGE;
    return TRUE;
}

static bool8 ListPage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sListPagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sListBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sListPagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sListBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sListBackgroundPalette, BG_PLTT_ID(0), sizeof(sListBackgroundPalette));
        LoadPalette(sListPagesPalette, BG_PLTT_ID(1), sizeof(sListPagesPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void ListPage_InitWindows(void)
{
    InitWindows(sListPageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    PutWindowTilemap(LISTPAGE_SCROLLING_TEXT);
    PutWindowTilemap(LISTPAGE_CATEGORY_TYPE);
    PutWindowTilemap(LISTPAGE_CAUGHT_COUNT);
    PutWindowTilemap(LISTPAGE_RESEARCH_LEVEL);
    CopyWindowToVram(LISTPAGE_SCROLLING_TEXT, COPYWIN_FULL);
    CopyWindowToVram(LISTPAGE_CATEGORY_TYPE, COPYWIN_FULL);
    CopyWindowToVram(LISTPAGE_CAUGHT_COUNT, COPYWIN_FULL);
    CopyWindowToVram(LISTPAGE_RESEARCH_LEVEL, COPYWIN_FULL);

    DisplayListPageResearchLevel();
    DisplayCaughtMasteredPokemonCount();
    UpdateListDisplay();
}

static void Task_ListPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_ListPageInput;
    }
}

//MARK:List Input Task
static void Task_ListPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        CleanUpListPage();
        gTasks[taskId].func = Task_StartInfoPage;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        CleanUpListPage();
        gTasks[taskId].func = Task_ResearchPokedexFadeOut;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
        UpdateListDisplay();
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
        UpdateListDisplay();
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        if(sResearchPokedexState->selectedPokemon > 5){
            sResearchPokedexState->selectedPokemon -= 5;
        }
        else{
            sResearchPokedexState->selectedPokemon = 0;
        }
        UpdateListDisplay();
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER - 5){
            sResearchPokedexState->selectedPokemon += 5;
        }
        else{
            sResearchPokedexState->selectedPokemon = HIGHEST_MON_NUMBER;
        }
        UpdateListDisplay();
    }
}

//MARK:Update List
static void UpdateListDisplay(void)
{
    FillWindowPixelBuffer(LISTPAGE_SCROLLING_TEXT, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(LISTPAGE_CATEGORY_TYPE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    DisplayMagnifierListText();
    ListPage_DisplayCurrentPokemonPicture();
    DisplayCurrentPokemonCategoryTypeText();
    DisplayCurrentPokemonType();
}

//MARK:Scroll List
static void DisplayMagnifierListText(void)
{
    u8 xOffset = 3;
    u8 yOffset = 39;
    u16 currentMon = sResearchPokedexState->selectedPokemon;
    u8 i;

    for(i = 1; i < 8; i++){
        switch (i)
        {
        case 1:
            if(currentMon >= 3 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset - 32);
            }
            break;
        case 2:
            if(currentMon >= 2 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset - 22);
            }
            break;
        case 3:
            if(currentMon >= 1 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROW, xOffset, yOffset - 12);
            }
            break;
        case 4:
            if(currentMon >= 0 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_NARROW, xOffset,yOffset);
            }
            break;
        case 5:
            if(currentMon >= -1 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROW, xOffset, yOffset + 12);
            }
            break;
        case 6:
            if(currentMon >= -2 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset + 22);
            }
            break;
        case 7:
            if(currentMon >= -3 ){
                DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset + 32);
            }
            break;
        default:
            break;
        }
    }
    CopyWindowToVram(LISTPAGE_SCROLLING_TEXT, COPYWIN_FULL);
}

//MARK:Line Item
static void DisplayMagnifierLineItemText(u16 currentMon, u8 fontID, u8 xPos, u8 yPos)
{
    u8 color[3] = {0, 10, 3};
    
    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
        StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon));
        StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
        AddTextPrinterParameterized4(LISTPAGE_SCROLLING_TEXT, fontID, xPos, yPos, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);  
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
        StringExpandPlaceholders(gStringVar2, sText_SingleSpace);
        StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
        AddTextPrinterParameterized4(LISTPAGE_SCROLLING_TEXT, fontID, xPos, yPos, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
    }
}

//MARK:PKMN Pic
static void ListPage_DisplayCurrentPokemonPicture(void)
{
    u8 xPos = 159;
    u8 yPos = 88;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    FreeAndDestroyMonPicSprite(sResearchPokedexState->monSpriteId);
    sResearchPokedexState->monSpriteId = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 14);
    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        gSprites[sResearchPokedexState->monSpriteId].invisible = FALSE;
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
    }
    else
    {
        gSprites[sResearchPokedexState->monSpriteId].invisible = TRUE;
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
    }
}

//MARK:PKMN Bg
// static void GetCurrentPokemonBackground(void)
// {
//     LZDecompressVram(gBattleTerrainTiles_TallGrass, (void *)(BG_CHAR_ADDR(2)));
//     LZDecompressVram(gBattleTerrainTilemap_TallGrass, (void *)(BG_SCREEN_ADDR(26)));
//     LoadCompressedPalette(gBattleTerrainPalette_TallGrass, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
// }

//MARK:Category Type
static void DisplayCurrentPokemonCategoryTypeText(void)
{
    u8 xOffset = 0;
    u8 yOffset = 6;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_NORMAL;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        StringCopy(gStringVar3, GetSpeciesCategory(currentMon));
        if (StringLength(gStringVar3) > 11)
        {
            fontsize = FONT_NARROW;
        }
        AddTextPrinterParameterized4(LISTPAGE_CATEGORY_TYPE, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
        CopyWindowToVram(LISTPAGE_CATEGORY_TYPE, COPYWIN_FULL);
    }
    else
    {
        AddTextPrinterParameterized4(LISTPAGE_CATEGORY_TYPE, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, sText_SingleSpace);
        CopyWindowToVram(LISTPAGE_CATEGORY_TYPE, COPYWIN_FULL);
    }
}

//MARK:Caught Cnts
static void DisplayCaughtMasteredPokemonCount(void)
{
    u8 xOffset = 10;
    u8 yOffset = 3;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_SMALL_NARROW;
    u16 seenCount = GetResearchDexSeenCount();
    u16 caughtCount = GetResearchDexMasteredCount();

    ConvertIntToDecimalStringN(gStringVar2, seenCount, STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized4(LISTPAGE_CAUGHT_COUNT, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
    CopyWindowToVram(LISTPAGE_CAUGHT_COUNT, COPYWIN_FULL);

    ConvertIntToDecimalStringN(gStringVar3, caughtCount, STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized4(LISTPAGE_CAUGHT_COUNT, fontsize, xOffset, yOffset + 11, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
    CopyWindowToVram(LISTPAGE_CAUGHT_COUNT, COPYWIN_FULL);
}

//MARK:Rsrch Level
static void DisplayListPageResearchLevel(void)
{
    u8 xOffset = 5;
    u8 yOffset = 1;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_NARROW;
    u8 researchLevel = sResearchPokedexState->pokedexList[sResearchPokedexState->selectedPokemon + 1].researchLevel;

    StringExpandPlaceholders(gStringVar4, sText_ResearchLevelText);
    AddTextPrinterParameterized4(LISTPAGE_RESEARCH_LEVEL, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(LISTPAGE_RESEARCH_LEVEL, COPYWIN_FULL);
}

//MARK:Type Icons
static void DisplayCurrentPokemonType(void)
{
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    u8 type1 = gSpeciesInfo[currentMon].types[0];
    u8 type2 = gSpeciesInfo[currentMon].types[1];
    u8 xPos = 208;
    u8 yPos = 76;

    DestroySpriteAndFreeResources(&gSprites[sResearchPokedexState->typeIcon1]);
    DestroySpriteAndFreeResources(&gSprites[sResearchPokedexState->typeIcon2]);
    LoadSpritePalette(&gTypes0SpritePalette);
    LoadSpritePalette(&gTypes1SpritePalette);
    LoadSpritePalette(&gTypes2SpritePalette);

    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        if (type1 == type2)
        {
            sResearchPokedexState->typeIcon1 = CreateSprite(&gTypeIconSpriteTemplates[type1][0],xPos,yPos,0);
        }
        else
        {
            sResearchPokedexState->typeIcon1 = CreateSprite(&gTypeIconSpriteTemplates[type1][1],xPos,yPos,0);
            sResearchPokedexState->typeIcon2 = CreateSprite(&gTypeIconSpriteTemplates[type2][2],xPos,yPos,0);
        }
    }
    else{
        //sResearchPokedexState->typeIcon1 = CreateSprite(&gTypeIconSpriteTemplates[0][0],xPos,yPos,0);
    }
    
}

//MARK:Cleanup List
static void CleanUpListPage(void)
{
    ClearWindowTilemap(LISTPAGE_SCROLLING_TEXT);
    ClearWindowTilemap(LISTPAGE_CATEGORY_TYPE);
    ClearWindowTilemap(LISTPAGE_CAUGHT_COUNT);
    ClearWindowTilemap(LISTPAGE_RESEARCH_LEVEL);
    RemoveWindow(LISTPAGE_SCROLLING_TEXT);
    RemoveWindow(LISTPAGE_CATEGORY_TYPE);
    RemoveWindow(LISTPAGE_CAUGHT_COUNT);
    RemoveWindow(LISTPAGE_RESEARCH_LEVEL);
}

//MARK:INFO PAGE

///////////////////////General Loading Activities///////////////////////

void Task_StartInfoPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_InfoPage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_InfoPage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = INFO_PAGE;
    SetMainCallback2(CB2_InfoPageSetUp);
}

void CB2_InfoPageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (InfoPage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (InfoPage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        InfoPage_InitWindows();
        gMain.state++;
        break;
    case 5:
        InfoPage_UpdateDisplay();
        CreateTask(Task_InfoPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 InfoPage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sInfoPageBgTemplates, ARRAY_COUNT(sInfoPageBgTemplates));

    SetBgTilemapBuffer(BG_PAGE_CONTENT, sBg0TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_PAGES, sBg1TilemapBuffer);
    SetBgTilemapBuffer(BG_SCROLLING_LIST, sBg2TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_COVER, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(BG_PAGE_CONTENT);
    ScheduleBgCopyTilemapToVram(BG_BOOK_PAGES);
    ScheduleBgCopyTilemapToVram(BG_SCROLLING_LIST);
    ScheduleBgCopyTilemapToVram(BG_BOOK_COVER);

    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = INFO_PAGE;
    return TRUE;
}

static bool8 InfoPage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sInfoPagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sInfoBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sInfoPagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sInfoBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sInfoBackgroundPalette, BG_PLTT_ID(0), sizeof(sInfoBackgroundPalette));
        LoadPalette(sInfoPagesPalette, BG_PLTT_ID(1), sizeof(sInfoPagesPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void InfoPage_InitWindows(void)
{
    InitWindows(sInfoPageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(INFOPAGE_EGG_GROUPS, PIXEL_FILL(0));
    FillWindowPixelBuffer(INFOPAGE_NAME_AND_NUMBER, PIXEL_FILL(0));
    FillWindowPixelBuffer(INFOPAGE_HEIGHT_AND_WEIGHT, PIXEL_FILL(0));
    FillWindowPixelBuffer(INFOPAGE_POKEDEX_ENTRY, PIXEL_FILL(0));
    
    PutWindowTilemap(INFOPAGE_EGG_GROUPS);
    PutWindowTilemap(INFOPAGE_NAME_AND_NUMBER);
    PutWindowTilemap(INFOPAGE_HEIGHT_AND_WEIGHT);
    PutWindowTilemap(INFOPAGE_POKEDEX_ENTRY);
    
    CopyWindowToVram(INFOPAGE_EGG_GROUPS, COPYWIN_FULL);
    CopyWindowToVram(INFOPAGE_NAME_AND_NUMBER, COPYWIN_FULL);
    CopyWindowToVram(INFOPAGE_HEIGHT_AND_WEIGHT, COPYWIN_FULL);
    CopyWindowToVram(INFOPAGE_POKEDEX_ENTRY, COPYWIN_FULL);
}

static void Task_InfoPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_InfoPageInput;
    }
}

//MARK:Info Inpt Task

static void Task_InfoPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {

    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        InfoPage_CleanUp();
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
        InfoPage_UpdateDisplay();
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
        InfoPage_UpdateDisplay();
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        InfoPage_CleanUp();
        gTasks[taskId].func = Task_StartStatPage;
    }
}

//MARK:Update Info
static void InfoPage_UpdateDisplay(void)
{
    FillWindowPixelBuffer(INFOPAGE_NAME_AND_NUMBER, PIXEL_FILL(0));
    FillWindowPixelBuffer(INFOPAGE_HEIGHT_AND_WEIGHT, PIXEL_FILL(0));
    FillWindowPixelBuffer(INFOPAGE_POKEDEX_ENTRY, PIXEL_FILL(0));
    FillWindowPixelBuffer(INFOPAGE_EGG_GROUPS, PIXEL_FILL(0));
    InfoPage_DisplayPokemonWeight();
    InfoPage_DisplayPokedexEntry();
    InfoPage_DisplayPokemonPicture();
    InfoPage_DisplayNameAndNumber();
    InfoPage_DisplayEggGroup();
}

//MARK:Name/No.
static void InfoPage_DisplayNameAndNumber(void)
{
    u8 xOffset = 1;
    u8 yOffset = 2;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_CURSIVE;

    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
    StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon));
    AddTextPrinterParameterized4(INFOPAGE_NAME_AND_NUMBER, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2); 
    AddTextPrinterParameterized4(INFOPAGE_NAME_AND_NUMBER, fontsize, xOffset, yOffset + 12, 0, 0, color, TEXT_SKIP_DRAW, gStringVar1); 
    CopyWindowToVram(INFOPAGE_NAME_AND_NUMBER, COPYWIN_GFX);
}

//MARK:Pokedex Entry
static void InfoPage_DisplayPokedexEntry(void)
{
    u8 xOffset = 8;
    u8 yOffset = 0;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_CURSIVE;

    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    const u8* description;
    description = GetSpeciesPokedexDescription(currentMon);

    FillWindowPixelBuffer(INFOPAGE_POKEDEX_ENTRY, PIXEL_FILL(0));
    AddTextPrinterParameterized4(INFOPAGE_POKEDEX_ENTRY, fontsize, xOffset, yOffset, 0, 1, color, TEXT_SKIP_DRAW, description);
    CopyWindowToVram(INFOPAGE_POKEDEX_ENTRY, COPYWIN_GFX);
}

//MARK:H/Weight
static void InfoPage_DisplayPokemonWeight(void)
{
    u8 xOffset = 0;
    u8 yOffset = 3;
    u8 color[3] = {0, 10, 3};
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    u8 fontsize = FONT_CURSIVE;
    u32 weight = 0;
    u8* weightString;
    u32 height = 0;
    u8* heightString;
    FillWindowPixelBuffer(INFOPAGE_HEIGHT_AND_WEIGHT, PIXEL_FILL(0));

    weight = GetSpeciesWeight(currentMon);
    weightString = ConvertMonWeightToString(weight);

    height = GetSpeciesHeight(currentMon);
    heightString = ConvertMonHeightToString(height);

    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        AddTextPrinterParameterized4(INFOPAGE_HEIGHT_AND_WEIGHT, fontsize, xOffset+11, yOffset, 0, 0, color, TEXT_SKIP_DRAW, heightString);
        AddTextPrinterParameterized4(INFOPAGE_HEIGHT_AND_WEIGHT, fontsize, xOffset, yOffset + 12, 0, 0, color, TEXT_SKIP_DRAW, weightString);
        CopyWindowToVram(INFOPAGE_HEIGHT_AND_WEIGHT, COPYWIN_GFX);
    }
    else
    {

    }
    Free(weightString);
}

//MARK: PKMN Pic
static void InfoPage_DisplayPokemonPicture(void)
{
    u8 xPos = 43;
    u8 yPos = 52;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    FreeAndDestroyMonPicSprite(sResearchPokedexState->monSpriteId);
    sResearchPokedexState->monSpriteId = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 14);
    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        gSprites[sResearchPokedexState->monSpriteId].invisible = FALSE;
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
    }
    else
    {
        gSprites[sResearchPokedexState->monSpriteId].invisible = TRUE;
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
    }
}

//MARK: Egg Group
static void InfoPage_DisplayEggGroup(void)
{
    u8 xOffset = 0;
    u8 yOffset = 0;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_CURSIVE;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    u8 eggGroup1;
    u8 eggGroup2;

    eggGroup1 = gSpeciesInfo[currentMon].eggGroups[0];
    eggGroup2 = gSpeciesInfo[currentMon].eggGroups[1];

    switch (eggGroup1)
    {
    case EGG_GROUP_MONSTER:
        StringCopy(gStringVar1, sText_Stats_eggGroup_MONSTER);
        break;
    case EGG_GROUP_WATER_1:
        StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_1);
        break;
    case EGG_GROUP_BUG:
        StringCopy(gStringVar1, sText_Stats_eggGroup_BUG);
        break;
    case EGG_GROUP_FLYING:
        StringCopy(gStringVar1, sText_Stats_eggGroup_FLYING);
        break;
    case EGG_GROUP_FIELD:
        StringCopy(gStringVar1, sText_Stats_eggGroup_FIELD);
        break;
    case EGG_GROUP_FAIRY:
        StringCopy(gStringVar1, sText_Stats_eggGroup_FAIRY);
        break;
    case EGG_GROUP_GRASS:
        StringCopy(gStringVar1, sText_Stats_eggGroup_GRASS);
        break;
    case EGG_GROUP_HUMAN_LIKE:
        StringCopy(gStringVar1, sText_Stats_eggGroup_HUMAN_LIKE);
        break;
    case EGG_GROUP_WATER_3:
        StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_3);
        break;
    case EGG_GROUP_MINERAL:
        StringCopy(gStringVar1, sText_Stats_eggGroup_MINERAL);
        break;
    case EGG_GROUP_AMORPHOUS:
        StringCopy(gStringVar1, sText_Stats_eggGroup_AMORPHOUS);
        break;
    case EGG_GROUP_WATER_2:
        StringCopy(gStringVar1, sText_Stats_eggGroup_WATER_2);
        break;
    case EGG_GROUP_DITTO:
        StringCopy(gStringVar1, sText_Stats_eggGroup_DITTO);
        break;
    case EGG_GROUP_DRAGON:
        StringCopy(gStringVar1, sText_Stats_eggGroup_DRAGON);
        break;
    case EGG_GROUP_NO_EGGS_DISCOVERED:
        StringCopy(gStringVar1, sText_Stats_eggGroup_NO_EGGS_DISCOVERED);
        break;
    default:
        StringCopy(gStringVar1, sText_Stats_eggGroup_UNKNOWN);
        break;
    }

    AddTextPrinterParameterized4(INFOPAGE_EGG_GROUPS, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar1);
    CopyWindowToVram(INFOPAGE_EGG_GROUPS, COPYWIN_GFX);
}

//MARK:Cleanup Info
static void InfoPage_CleanUp(void)
{
    ClearWindowTilemap(INFOPAGE_NAME_AND_NUMBER);
    ClearWindowTilemap(INFOPAGE_HEIGHT_AND_WEIGHT);
    ClearWindowTilemap(INFOPAGE_POKEDEX_ENTRY);
    ClearWindowTilemap(INFOPAGE_EGG_GROUPS);
    
    RemoveWindow(INFOPAGE_NAME_AND_NUMBER);
    RemoveWindow(INFOPAGE_HEIGHT_AND_WEIGHT);
    RemoveWindow(INFOPAGE_POKEDEX_ENTRY);
    RemoveWindow(INFOPAGE_EGG_GROUPS);
}

//MARK:STAT PAGE

///////////////////////General Loading Activities///////////////////////

void Task_StartStatPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_StatPage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_StatPage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = STAT_PAGE;
    SetMainCallback2(CB2_StatPageSetUp);
}

void CB2_StatPageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (StatPage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (StatPage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        StatPage_InitWindows();
        gMain.state++;
        break;
    case 5:
        StatPage_UpdateDisplay();
        CreateTask(Task_StatPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 StatPage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sStatPageBgTemplates, ARRAY_COUNT(sStatPageBgTemplates));

    SetBgTilemapBuffer(0, sBg0TilemapBuffer);
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    SetBgTilemapBuffer(3, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);

    //Set the Stat Radar Chart to have some transparency
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG2 | BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(2, 18));
    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);

    sResearchPokedexState->currentPage = STAT_PAGE;
    return TRUE;
}

static bool8 StatPage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sStatPagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sStatBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sStatPagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sStatBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sStatBackgroundPalette, BG_PLTT_ID(0), sizeof(sStatBackgroundPalette));
        LoadPalette(sStatPagesPalette, BG_PLTT_ID(1), sizeof(sStatPagesPalette));
        LoadPalette(sRadarChartPalette, BG_PLTT_ID(2), sizeof(sRadarChartPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void StatPage_InitWindows(void)
{
    InitWindows(sStatPageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(STATPAGE_RADAR_CHART, PIXEL_FILL(0));
    FillWindowPixelBuffer(STATPAGE_NAME_AND_NUMBER, PIXEL_FILL(0));
    PutWindowTilemap(STATPAGE_RADAR_CHART);
    PutWindowTilemap(STATPAGE_NAME_AND_NUMBER);
    CopyWindowToVram(STATPAGE_RADAR_CHART, COPYWIN_FULL);
    CopyWindowToVram(STATPAGE_NAME_AND_NUMBER, COPYWIN_FULL);
}

static void Task_StatPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_StatPageInput;
    }
}

//MARK:STAT PAGE INPUT TASK

static void Task_StatPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {

    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        StatPage_CleanUp();
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
        StatPage_UpdateDisplay();
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
        StatPage_UpdateDisplay();
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        StatPage_CleanUp();
        gTasks[taskId].func = Task_StartInfoPage;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        StatPage_CleanUp();
        gTasks[taskId].func = Task_StartAreaPage;
    }
}

//MARK:Update Info
static void StatPage_UpdateDisplay(void)
{
    FillWindowPixelBuffer(STATPAGE_RADAR_CHART, PIXEL_FILL(0));
    FillWindowPixelBuffer(STATPAGE_NAME_AND_NUMBER, PIXEL_FILL(0));
    InfoPage_DisplayStatRadar();
    StatPage_DisplayNameAndNumber();
    //StatPage_DisplayCurrentPokemonIcon();
}

//MARK:Cleanup Stat
static void StatPage_CleanUp(void)
{
    ClearWindowTilemap(STATPAGE_RADAR_CHART);
    ClearWindowTilemap(STATPAGE_NAME_AND_NUMBER);
    RemoveWindow(STATPAGE_RADAR_CHART);
    RemoveWindow(STATPAGE_NAME_AND_NUMBER);
}

//MARK:Name/No.
static void StatPage_DisplayNameAndNumber(void)
{
    u8 xOffset = 1;
    u8 yOffset = 2;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_CURSIVE;

    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
    StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon));
    AddTextPrinterParameterized4(STATPAGE_NAME_AND_NUMBER, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2); 
    AddTextPrinterParameterized4(STATPAGE_NAME_AND_NUMBER, fontsize, xOffset, yOffset + 12, 0, 0, color, TEXT_SKIP_DRAW, gStringVar1); 
    CopyWindowToVram(STATPAGE_NAME_AND_NUMBER, COPYWIN_GFX);
}

//MARK:PKMN Icon
static void StatPage_DisplayCurrentPokemonIcon(void)
{
    u8 xPos = 170;
    u8 yPos = 28;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    FreeAndDestroyMonPicSprite(sResearchPokedexState->monSpriteId);
    FreeMonIconPalettes();
    LoadMonIconPalettePersonality(currentMon, 0);
    sResearchPokedexState->monSpriteId = CreateMonIcon(currentMon, SpriteCB_MonIcon, xPos, yPos, 1, 0);
    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        gSprites[sResearchPokedexState->monSpriteId].invisible = FALSE;
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 0;
    }
    else
    {
        gSprites[sResearchPokedexState->monSpriteId].invisible = FALSE;
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 0;
    }
}

//MARK:Radar Chart
static void InfoPage_DisplayStatRadar(void)
{
    u8 xOffset = 37;
    u8 yOffset = 37;
    u8 color[3] = {0, 10, 3};
    u8 fontsize = FONT_CURSIVE;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    u8 baseAttack = 2 + (gSpeciesInfo[currentMon].baseAttack / 8);
    u8 baseHP = 2 + (gSpeciesInfo[currentMon].baseHP / 8);
    u8 baseSpAttack = 2 + (gSpeciesInfo[currentMon].baseSpAttack / 8);
    u8 baseSpDefense = 2 + (gSpeciesInfo[currentMon].baseSpDefense / 8);
    u8 baseSpeed = 2 + (gSpeciesInfo[currentMon].baseSpeed / 8);
    u8 baseDefense = 2 + (gSpeciesInfo[currentMon].baseDefense / 8);
    u8 maxStat = max(max(max(baseAttack,baseHP),baseSpAttack),max(max(baseSpDefense,baseSpeed),baseDefense));

    bitmapDrawIrregularHexagon(STATPAGE_RADAR_CHART, 0 + xOffset, 0 + yOffset, baseAttack, baseHP, baseSpAttack, baseSpDefense, baseSpeed, baseDefense, 1);
    bitmapScanlineGradientFill(STATPAGE_RADAR_CHART, 0 + xOffset, 0 + yOffset, 37, 37, maxStat);
    CopyWindowToVram(STATPAGE_RADAR_CHART, COPYWIN_FULL);
}

//MARK:AREA PAGE

///////////////////////General Loading Activities///////////////////////

void Task_StartAreaPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_AreaPage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_AreaPage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = AREA_PAGE;
    SetMainCallback2(CB2_AreaPageSetUp);
}

void CB2_AreaPageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (AreaPage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (AreaPage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        AreaPage_InitWindows();
        gMain.state++;
        break;
    case 5:
        CreateTask(Task_AreaPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 AreaPage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sAreaPageBgTemplates, ARRAY_COUNT(sAreaPageBgTemplates));

    SetBgTilemapBuffer(BG_PAGE_CONTENT, sBg0TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_PAGES, sBg1TilemapBuffer);
    SetBgTilemapBuffer(BG_SCROLLING_LIST, sBg2TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_COVER, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(BG_PAGE_CONTENT);
    ScheduleBgCopyTilemapToVram(BG_BOOK_PAGES);
    ScheduleBgCopyTilemapToVram(BG_SCROLLING_LIST);
    ScheduleBgCopyTilemapToVram(BG_BOOK_COVER);

    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = AREA_PAGE;
    return TRUE;
}

static bool8 AreaPage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sAreaPagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sAreaBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sAreaPagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sAreaBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sAreaBackgroundPalette, BG_PLTT_ID(0), sizeof(sAreaBackgroundPalette));
        LoadPalette(sAreaPagesPalette, BG_PLTT_ID(1), sizeof(sAreaPagesPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void AreaPage_InitWindows(void)
{
    InitWindows(sAreaPageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_AreaPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_AreaPageInput;
    }
}

//MARK:AREA PAGE INPUT TASK

static void Task_AreaPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartStatPage;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartTaskPage;
    }
}

//MARK:TASK PAGE

///////////////////////General Loading Activities///////////////////////

void Task_StartTaskPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_TaskPage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_TaskPage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = TASK_PAGE;
    SetMainCallback2(CB2_TaskPageSetUp);
}

void CB2_TaskPageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (TaskPage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (TaskPage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        TaskPage_InitWindows();
        gMain.state++;
        break;
    case 5:
        CreateTask(Task_TaskPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 TaskPage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sTaskPageBgTemplates, ARRAY_COUNT(sTaskPageBgTemplates));

    SetBgTilemapBuffer(BG_PAGE_CONTENT, sBg0TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_PAGES, sBg1TilemapBuffer);
    SetBgTilemapBuffer(BG_SCROLLING_LIST, sBg2TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_COVER, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(BG_PAGE_CONTENT);
    ScheduleBgCopyTilemapToVram(BG_BOOK_PAGES);
    ScheduleBgCopyTilemapToVram(BG_SCROLLING_LIST);
    ScheduleBgCopyTilemapToVram(BG_BOOK_COVER);

    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = TASK_PAGE;
    return TRUE;
}

static bool8 TaskPage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sTaskPagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sTaskBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sTaskPagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sTaskBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sTaskBackgroundPalette, BG_PLTT_ID(0), sizeof(sTaskBackgroundPalette));
        LoadPalette(sTaskPagesPalette, BG_PLTT_ID(1), sizeof(sTaskPagesPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void TaskPage_InitWindows(void)
{
    InitWindows(sTaskPageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_TaskPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_TaskPageInput;
    }
}

//MARK:TASK PAGE INPUT TASK

static void Task_TaskPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartAreaPage;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartFormPage;
    }
}

//MARK:FORM PAGE

///////////////////////General Loading Activities///////////////////////

void Task_StartFormPage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_FormPage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_FormPage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = FORM_PAGE;
    SetMainCallback2(CB2_FormPageSetUp);
}

void CB2_FormPageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (FormPage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (FormPage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        FormPage_InitWindows();
        gMain.state++;
        break;
    case 5:
        CreateTask(Task_FormPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 FormPage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sFormPageBgTemplates, ARRAY_COUNT(sFormPageBgTemplates));

    SetBgTilemapBuffer(BG_PAGE_CONTENT, sBg0TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_PAGES, sBg1TilemapBuffer);
    SetBgTilemapBuffer(BG_SCROLLING_LIST, sBg2TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_COVER, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(BG_PAGE_CONTENT);
    ScheduleBgCopyTilemapToVram(BG_BOOK_PAGES);
    ScheduleBgCopyTilemapToVram(BG_SCROLLING_LIST);
    ScheduleBgCopyTilemapToVram(BG_BOOK_COVER);

    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = FORM_PAGE;
    return TRUE;
}

static bool8 FormPage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sFormPagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sFormBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sFormPagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sFormBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sFormBackgroundPalette, BG_PLTT_ID(0), sizeof(sFormBackgroundPalette));
        LoadPalette(sFormPagesPalette, BG_PLTT_ID(1), sizeof(sFormPagesPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void FormPage_InitWindows(void)
{
    InitWindows(sFormPageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_FormPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_FormPageInput;
    }
}

//MARK:FORM PAGE INPUT TASK

static void Task_FormPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartTaskPage;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartMovePage;
    }
}

//MARK:MOVE PAGE

///////////////////////General Loading Activities///////////////////////

void Task_StartMovePage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_MovePage_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

void ResearchPokedex_MovePage_Init(MainCallback callback)
{
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = MOVE_PAGE;
    SetMainCallback2(CB2_MovePageSetUp);
}

void CB2_MovePageSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (MovePage_InitBgs()) 
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            FadeAndBail();
            return;
        }
        break;
    case 3:
        if (MovePage_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        MovePage_InitWindows();
        gMain.state++;
        break;
    case 5:
        CreateTask(Task_MovePageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static bool8 MovePage_InitBgs(void)
{
    ResetAllBgsCoordinates();
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sMovePageBgTemplates, ARRAY_COUNT(sMovePageBgTemplates));

    SetBgTilemapBuffer(BG_PAGE_CONTENT, sBg0TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_PAGES, sBg1TilemapBuffer);
    SetBgTilemapBuffer(BG_SCROLLING_LIST, sBg2TilemapBuffer);
    SetBgTilemapBuffer(BG_BOOK_COVER, sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(BG_PAGE_CONTENT);
    ScheduleBgCopyTilemapToVram(BG_BOOK_PAGES);
    ScheduleBgCopyTilemapToVram(BG_SCROLLING_LIST);
    ScheduleBgCopyTilemapToVram(BG_BOOK_COVER);

    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = MOVE_PAGE;
    return TRUE;
}

static bool8 MovePage_LoadGraphics(void)
{
    switch (sResearchPokedexState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sMovePagesTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sMoveBackgroundTiles, 0, 0, 0);
        sResearchPokedexState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sMovePagesTilemap, sBg1TilemapBuffer);
            LZDecompressWram(sMoveBackgroundTilemap, sBg3TilemapBuffer);
            sResearchPokedexState->loadState++;
        }
        break;
    case 2:
        LoadPalette(sMoveBackgroundPalette, BG_PLTT_ID(0), sizeof(sMoveBackgroundPalette));
        LoadPalette(sMovePagesPalette, BG_PLTT_ID(1), sizeof(sMovePagesPalette));
        sResearchPokedexState->loadState++;
    default:
        sResearchPokedexState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void MovePage_InitWindows(void)
{
    InitWindows(sMovePageWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_MovePageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_MovePageInput;
    }
}

//MARK:MOVE PAGE INPUT TASK

static void Task_MovePageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartListPage;
    }
    if (JOY_REPEAT(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 0){
            sResearchPokedexState->selectedPokemon--;
        }
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartFormPage;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {

    }
}

//MARK:GETTERS/SETTERS

u16 GetResearchDexSeenCount(void)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < HIGHEST_MON_NUMBER; i++)
    {
        if (sResearchPokedexState->pokedexList[i].seen)
            count++;
    }
    return count;
}

u16 GetResearchDexMasteredCount(void)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < HIGHEST_MON_NUMBER; i++)
    {
        if (sResearchPokedexState->pokedexList[i].researchLevel == 10)
            count++;
    }
    return count;
}