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
static void DisplayCurrentPokemonPicture(void);
static void DisplayCurrentPokemonCategoryTypeText(void);
static void Task_ListPageInput(u8);

// Info Pages
void Task_StartInfoPage(u8);
void ResearchPokedex_InfoPage_Init(MainCallback);
void CB2_InfoPageSetUp(void);
static bool8 InfoPage_InitBgs(void);
static bool8 InfoPage_LoadGraphics(void);
static void InfoPage_InitWindows(void);
static void Task_InfoPageWaitFadeIn(u8);
static void Task_InfoPageInput(u8);

// Stat Pages
void Task_StartStatPage(u8);
void ResearchPokedex_StatPage_Init(MainCallback);
void CB2_StatPageSetUp(void);
static bool8 StatPage_InitBgs(void);
static bool8 StatPage_LoadGraphics(void);
static void StatPage_InitWindows(void);
static void Task_StatPageWaitFadeIn(u8);
static void Task_StatPageInput(u8);

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

static EWRAM_DATA struct ResearchPokedexState *sResearchPokedexState = NULL;
static EWRAM_DATA u8 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg3TilemapBuffer = NULL;

static const u8 sText_PokedexListItem[] = _("Pg {STR_VAR_1}-{STR_VAR_2}");
static const u8 sText_TenDashes[] = _("----------");

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u8 reserchLevel;
};

// This is the object that is keeping track of whatever state the pokedex is in.
// It tracks what pokemon is currently being looked at, as well as useful things like
// what callback to use in case of an error.
struct ResearchPokedexState
{
    struct PokedexListItem pokedexList[1000];
    MainCallback savedCallback;
    u8 loadState;
    u8 mode;
    u8 monSpriteId;
    u16 selectedPokemon;
    u8 currentPage;
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
    sResearchPokedexState->pokedexList[7].seen = TRUE;
    //End debugging
    sResearchPokedexState->selectedPokemon = 0;
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

//MARK:GRAPHICS STUFF


// Graphics data for List Pages
static const u16 sListBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/list_background.gbapal");
static const u16 sListPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/list_pages.gbapal");
static const u32 sListBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.bin.lz");
static const u32 sListPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.bin.lz");
static const u32 sListBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.4bpp.lz");
static const u32 sListPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.4bpp.lz");

// List Page Background Template
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

//List Page Window Template
static const struct WindowTemplate sListPageWinTemplates[3] =
{
    {
        .bg = BG_SCROLLING_LIST,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = BG_PAGE_CONTENT,
        .tilemapLeft = 18,
        .tilemapTop = 3,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

// Graphics data for Info Pages
static const u16 sInfoBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/info_background.gbapal");
static const u16 sInfoPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/info_pages.gbapal");
static const u32 sInfoBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/info_background_tiles.bin.lz");
static const u32 sInfoPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/info_pages_tiles.bin.lz");
static const u32 sInfoBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/info_background_tiles.4bpp.lz");
static const u32 sInfoPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/info_pages_tiles.4bpp.lz");

// Info Page Background Template
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

//Info Page Window Template
static const struct WindowTemplate sInfoPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

// Graphics data for Stat Pages
static const u16 sStatBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/stat_background.gbapal");
static const u16 sStatPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/stat_pages.gbapal");
static const u32 sStatBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/stat_background_tiles.bin.lz");
static const u32 sStatPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/stat_pages_tiles.bin.lz");
static const u32 sStatBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/stat_background_tiles.4bpp.lz");
static const u32 sStatPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/stat_pages_tiles.4bpp.lz");

// Stat Page Background Template
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

//Stat Page Window Template
static const struct WindowTemplate sStatPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 11,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

// Graphics data for Area Pages
static const u16 sAreaBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/area_background.gbapal");
static const u16 sAreaPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/area_pages.gbapal");
static const u32 sAreaBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/area_background_tiles.bin.lz");
static const u32 sAreaPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/area_pages_tiles.bin.lz");
static const u32 sAreaBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/area_background_tiles.4bpp.lz");
static const u32 sAreaPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/area_pages_tiles.4bpp.lz");

// Area Page Background Template
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

//Area Page Window Template
static const struct WindowTemplate sAreaPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 3,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

// Graphics data for Task Pages
static const u16 sTaskBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/task_background.gbapal");
static const u16 sTaskPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/task_pages.gbapal");
static const u32 sTaskBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/task_background_tiles.bin.lz");
static const u32 sTaskPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/task_pages_tiles.bin.lz");
static const u32 sTaskBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/task_background_tiles.4bpp.lz");
static const u32 sTaskPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/task_pages_tiles.4bpp.lz");

// Task Page Background Template
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

//Task Page Window Template
static const struct WindowTemplate sTaskPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 3,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

// Graphics data for Form Pages
static const u16 sFormBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/form_background.gbapal");
static const u16 sFormPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/form_pages.gbapal");
static const u32 sFormBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/form_background_tiles.bin.lz");
static const u32 sFormPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/form_pages_tiles.bin.lz");
static const u32 sFormBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/form_background_tiles.4bpp.lz");
static const u32 sFormPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/form_pages_tiles.4bpp.lz");

// Form Page Background Template
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

//Form Page Window Template
static const struct WindowTemplate sFormPageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

// Graphics data for Move Pages
static const u16 sMoveBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/move_background.gbapal");
static const u16 sMovePagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/move_pages.gbapal");
static const u32 sMoveBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/move_background_tiles.bin.lz");
static const u32 sMovePagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/move_pages_tiles.bin.lz");
static const u32 sMoveBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/move_background_tiles.4bpp.lz");
static const u32 sMovePagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/move_pages_tiles.4bpp.lz");

// Move Page Background Template
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

//Move Page Window Template
static const struct WindowTemplate sMovePageWinTemplates[3] =
{
    {
        .bg = 2,
        .tilemapLeft = 2,
        .tilemapTop = 6,
        .width = 14,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 12,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 253,
    },
    DUMMY_WIN_TEMPLATE,
};

//MARK:LIST PAGE

///////////////////////General Loading Activities///////////////////////

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
        DisplayMagnifierListText();
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
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
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_ListPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_ListPageInput;
    }
}

//MARK:LIST PAGE INPUT TASK

static void Task_ListPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartInfoPage;
    }
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ResearchPokedexFadeOut;
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
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon > 5){
            sResearchPokedexState->selectedPokemon -= 5;
        }
        else{
            sResearchPokedexState->selectedPokemon = 0;
        }
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER - 5){
            sResearchPokedexState->selectedPokemon += 5;
        }
        else{
            sResearchPokedexState->selectedPokemon = HIGHEST_MON_NUMBER;
        }
    }
    DisplayMagnifierListText();
    DisplayCurrentPokemonPicture();
    DisplayCurrentPokemonCategoryTypeText();
}

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
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void DisplayMagnifierLineItemText(u16 currentMon, u8 fontID, u8 xPos, u8 yPos)
{
    u8 color[3] = {0, 10, 3};
    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
        StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon));
        StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
        AddTextPrinterParameterized4(0, fontID, xPos, yPos, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);  
    }
    else
    {

    }
}

static void DisplayCurrentPokemonPicture(void)
{
    u8 xPos = 160;
    u8 yPos = 95;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        FreeAndDestroyMonPicSprite(sResearchPokedexState->monSpriteId);
        sResearchPokedexState->monSpriteId = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 2);
        gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
    }
    else
    {

    }
}

static void DisplayCurrentPokemonCategoryTypeText(void)
{
    u8 xOffset = 0;
    u8 yOffset = 6;
    u8 color[3] = {0, 10, 3};
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    u8 fontsize = FONT_NORMAL;

    if(sResearchPokedexState->pokedexList[currentMon].seen)
    {
        StringCopy(gStringVar3, GetSpeciesCategory(currentMon));
        if (StringLength(gStringVar3) > 11)
        {
            fontsize = FONT_NARROW;
        }
        AddTextPrinterParameterized4(1, fontsize, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
        PutWindowTilemap(1);
        CopyWindowToVram(1, COPYWIN_FULL);
    }
    else
    {

    }
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
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_InfoPageWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_InfoPageInput;
    }
}

//MARK:INFO PAGE INPUT TASK

static void Task_InfoPageInput(u8 taskId)
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

    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartStatPage;
    }
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
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
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
        gTasks[taskId].func = Task_StartInfoPage;
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartAreaPage;
    }
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