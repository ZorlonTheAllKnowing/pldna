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

static EWRAM_DATA struct ResearchPokedexState *sResearchPokedexState = NULL;
static EWRAM_DATA u8 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg3TilemapBuffer = NULL;

static const u8 sText_PokedexListItem[] = _("Pg {STR_VAR_1}-{STR_VAR_2}");

// This is the object that is keeping track of whatever state the pokedex is in.
// It tracks what pokemon is currently being looked at, as well as useful things like
// what callback to use in case of an error.
struct ResearchPokedexState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 mode;
    u8 monSpriteId;
    u16 selectedPokemon;
    u8 currentPage;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                  GENERAL FUNCTIONS                                         /////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

void Task_StartResearchPokedex_FromOverworldMenu(u8 taskId)
{
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);
    sBg0TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg3TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sResearchPokedexState = AllocZeroed(sizeof(struct ResearchPokedexState)); 
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                     GRAPHICS STUFF                                         /////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
        .tilemapTop = 11,
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

//List Page Window Template
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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                        LIST PAGE                                           /////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset+6,yOffset - 32);
            break;
        case 2:
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset - 22);
            break;
        case 3:
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROW, xOffset,yOffset - 12);
            break;
        case 4:
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_NARROW, xOffset,yOffset);
            break;
        case 5:
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROW, xOffset,yOffset + 12);
            break;
        case 6:
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset + 22);
            break;
        case 7:
            DisplayMagnifierLineItemText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset + 32);
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
    ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
    StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon));
    StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
    AddTextPrinterParameterized4(0, fontID, xPos, yPos, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);    
}

static void DisplayCurrentPokemonPicture(void)
{
    u8 xPos = 160;
    u8 yPos = 65;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    
    FreeAndDestroyMonPicSprite(sResearchPokedexState->monSpriteId);
    sResearchPokedexState->monSpriteId = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 2);
    gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
}

static void DisplayCurrentPokemonCategoryTypeText(void)
{
    u8 xOffset = 0;
    u8 yOffset = 2;
    u8 color[3] = {0, 10, 3};
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    StringCopy(gStringVar3, GetSpeciesCategory(currentMon));
    AddTextPrinterParameterized4(1, FONT_NORMAL, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

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
        DisplayMagnifierListText();
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
        DisplayMagnifierListText();
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
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
        DisplayMagnifierListText();
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
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
        DisplayMagnifierListText();
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                        INFO PAGE                                           /////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sResearchPokedexState->selectedPokemon < HIGHEST_MON_NUMBER){
            sResearchPokedexState->selectedPokemon++;
        }
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
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
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
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
        DisplayCurrentPokemonPicture();
        DisplayCurrentPokemonCategoryTypeText();
    }
}