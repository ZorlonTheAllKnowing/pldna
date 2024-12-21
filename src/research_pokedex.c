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

#define MAX_MONS_ON_SCREEN 4
#define HIGHEST_MON_NUMBER 2000

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

extern const u8 gText_DexNational[];
extern const u8 gText_DexHoenn[];
static const u8 sText_PokedexListItem[] = _("Pg {STR_VAR_1}-{STR_VAR_2}");

enum{
    BG_PAGE_CONTENT,
    BG_BOOK_PAGES,
    BG_SCROLLING_LIST,
    BG_BOOK_COVER,
};

static EWRAM_DATA struct ResearchPokedexState *sResearchPokedexState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

// General functions
static void MainCB2(void);
static void ResearchPokedex_Init(MainCallback);
static void CB2_ResearchPokedexLoadSwitch(void);
static void FadeAndBail(void);
static void Task_ResearchPokedexFadeAndBail(u8);
static void FreeResources(void);

// Scrolling List Page
static bool8 LoadListPage(void);
static void Task_ListPageWaitFadeIn(u8);
static void DisplayPokedexListText(void);
static void DisplaySingleListEntryText(u16, u8, u8, u8);
static void DisplayCurrentPokemonCategoryTypeText(void);
static void DisplayCurrentPokemonPicture(void);
static void Task_ListPageInput(u8);
static void Task_ResearchPokedexFadeOut(u8);

// Info Pages
static bool8 LoadInfoPage(void);
static void Task_InfoPageWaitFadeIn(u8);
static void Task_InfoPageInput(u8);
static void Task_CloseInfoPage(u8);

EWRAM_DATA static u8 *sResearchPokedexBackground0TilemapPtr = NULL;
EWRAM_DATA static u8 *sResearchPokedexBackground1TilemapPtr = NULL;
EWRAM_DATA static u8 *sResearchPokedexBackground2TilemapPtr = NULL;
EWRAM_DATA static u8 *sResearchPokedexBackground3TilemapPtr = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                       MAIN STUFF                                           /////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

// The main Callback used in the Pokedex
// Used for controlling all tasks, graphics, and animation every frame
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

// The main vBlank Callback used in the Pokedex
static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Call this task to start the research Pokedex. Do a palette fade just before it.
// This will call the init function and set it up with a Return to Field With Open Menu Callback
// in case any errors occur during set up. The task is then destroyed.
void Task_StartResearchPokedexFromOverworld(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResearchPokedex_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This allocates the memory for the Pokedex State and initializes the List Page state.
// It saves the Return Callback to be used in case of errors,
// Then it sets the Callback for Loading the research Pokedex
// So, basically everything up to this so far is just setting up a fallback in case of erros.
void ResearchPokedex_Init(MainCallback callback)
{
    sResearchPokedexState = AllocZeroed(sizeof(struct ResearchPokedexState)); 
    if (sResearchPokedexState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sResearchPokedexState->selectedPokemon = 0;
    sResearchPokedexState->savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sResearchPokedexState->currentPage = LIST_PAGE;
    SetMainCallback2(CB2_ResearchPokedexLoadSwitch);
}

// The Callback that loads and sets up all graphics data for the Research Pokedex
// Case 0: Clear out graphics stuff being done in the overworld
// Case 1: Clears and resets overworld Sprite data and Tasks. Allocates memory for Background Tilemaps
// Case 2: Loads the list page, sets the load state to 0
// Case 3: Creates the Task that waits for Palette Fade In to end
// Case 4: Starts the Palette Fade In
// Case 5: Sets the main callbacks to their normal callback
// This clears out all the overworld graphics data, then sets the task to the List Page
void CB2_ResearchPokedexLoadSwitch(void)
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
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        sResearchPokedexBackground0TilemapPtr = AllocZeroed(0x800);                           // Allocate memory for the Tilemaps
        sResearchPokedexBackground1TilemapPtr = AllocZeroed(0x800);
        sResearchPokedexBackground2TilemapPtr = AllocZeroed(0x800);
        sResearchPokedexBackground3TilemapPtr = AllocZeroed(0x800);
        gMain.state++;
        break;
    case 2:
        if (LoadListPage())
        {
            sResearchPokedexState->loadState = 0;
            gMain.state++;
        }
        else
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            FadeAndBail();
            SetVBlankCallback(VBlankCB);
            SetMainCallback2(MainCB2);
            return;
        }
        break;
    case 3:
        CreateTask(Task_ListPageWaitFadeIn, 0);
        gMain.state++;
        break;
    case 4:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 5:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
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
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                        LIST PAGE                                           /////
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

// This is the task that loads all graphics for List Page.
// This is called whenever the List Page is navigated to from any other page (overworld, info pages, search)
// This loads and displays the List Page, then hands off to Task_ListPageInput to handle input
static bool8 LoadListPage(void)
{
    //Reset GPU Registers
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);  
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);

    // Init Backgrounds
    InitBgsFromTemplates(0, sListPageBgTemplates, ARRAY_COUNT(sListPageBgTemplates));
    SetBgTilemapBuffer(BG_BOOK_PAGES, sResearchPokedexBackground1TilemapPtr);
    SetBgTilemapBuffer(BG_BOOK_COVER, sResearchPokedexBackground3TilemapPtr);

    // Load Backgrounds
    DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sListPagesTiles, 0, 0, 0);
    DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sListBackgroundTiles, 0, 0, 0);
    LZDecompressWram(sListPagesTilemap, sResearchPokedexBackground1TilemapPtr);
    LZDecompressWram(sListBackgroundTilemap, sResearchPokedexBackground3TilemapPtr);
    CopyBgTilemapBufferToVram(BG_BOOK_PAGES);                                            // Copies the tilemaps to VRAM?
    CopyBgTilemapBufferToVram(BG_BOOK_COVER);
    LoadPalette(sListBackgroundPalette, BG_PLTT_ID(0), sizeof(sListBackgroundPalette));  // Load the palettes for the background layers
    LoadPalette(sListPagesPalette, BG_PLTT_ID(1), sizeof(sListPagesPalette));

    // Load Windows
    InitWindows(sListPageWinTemplates);                                 // Create windows defined in the template
    DeactivateAllTextPrinters();                                        // Deactivate whatever text printers are left from before
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);  // Load the font palette in Background Palette 15
    FillWindowPixelBuffer(0, PIXEL_FILL(0));                            // Fills Window 0 with transparent pixels to zero it out.
    FillWindowPixelBuffer(1, PIXEL_FILL(0));                            // Fills Window 1 with transparent pixels to zero it out.

    // Display Everything
    DisplayPokedexListText();
    DisplayCurrentPokemonPicture();
    DisplayCurrentPokemonCategoryTypeText();
    PutWindowTilemap(0);                                                // Puts Window 0 on the tile map
    PutWindowTilemap(1);                                                // Puts Window 1 on the tile map 
    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = LIST_PAGE;
    return TRUE;
}

static void Task_ListPageWaitFadeIn(u8 taskId)
{
    // Do nothing until the palette fade finishes, then replace ourself with the main menu task.
    if (!gPaletteFade.active)
    {
        if(LoadListPage()){
            gTasks[taskId].func = Task_ListPageInput;
        }
    }
}

// This displays the scrolling list of Pokemon names for the Pokedex
// It calls DisplaySingleListEntry multiple times for this
static void DisplayPokedexListText(void)
{
    u8 xOffset = 3;
    u8 yOffset = 39;
    u16 currentMon = sResearchPokedexState->selectedPokemon;
    u8 i;

    for(i = 1; i < 8; i++){
        switch (i)
        {
        case 1:
            DisplaySingleListEntryText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset+6,yOffset - 32);
            break;
        case 2:
            DisplaySingleListEntryText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset - 22);
            break;
        case 3:
            DisplaySingleListEntryText(currentMon-3+i, FONT_SMALL_NARROW, xOffset,yOffset - 12);
            break;
        case 4:
            DisplaySingleListEntryText(currentMon-3+i, FONT_NARROW, xOffset,yOffset);
            break;
        case 5:
            DisplaySingleListEntryText(currentMon-3+i, FONT_SMALL_NARROW, xOffset,yOffset + 12);
            break;
        case 6:
            DisplaySingleListEntryText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset + 22);
            break;
        case 7:
            DisplaySingleListEntryText(currentMon-3+i, FONT_SMALL_NARROWER, xOffset + 6,yOffset + 32);
            break;
        default:
            break;
        }
    }
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

// This handle the logic of displaying each list item in the Pokedex
// The font, size, and position are different for each entry
static void DisplaySingleListEntryText(u16 currentMon, u8 fontID, u8 xPos, u8 yPos)
{
    u8 color[3] = {0, 10, 3};
    ConvertIntToDecimalStringN(gStringVar1, currentMon, STR_CONV_MODE_LEADING_ZEROS, 4);
    StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon));
    StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
    AddTextPrinterParameterized4(0, fontID, xPos, yPos, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);    
}

// This displays the image of the current pokemon
static void DisplayCurrentPokemonPicture(void)
{
    u8 xPos = 160;
    u8 yPos = 65;
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;
    
    FreeAndDestroyMonPicSprite(sResearchPokedexState->monSpriteId);
    sResearchPokedexState->monSpriteId = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 2);
    gSprites[sResearchPokedexState->monSpriteId].oam.priority = 3;
}

// This displays the category name of the current pokemon
static void DisplayCurrentPokemonCategoryTypeText(void){
    u8 xOffset = 0;
    u8 yOffset = 2;
    u8 color[3] = {0, 10, 3};
    u16 currentMon = sResearchPokedexState->selectedPokemon + 1;

    StringCopy(gStringVar3, GetSpeciesCategory(currentMon));
    AddTextPrinterParameterized4(1, FONT_NORMAL, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

// This is the task that handle List Page input
// For almost all the time that the List Page is on screen, this is the task being run.
// It should be preceeded by Task_LoadListPage, and followed by the task that loads whatever page is coming next.
static void Task_ListPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_InfoPageWaitFadeIn;
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
    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);
    DisplayPokedexListText();
    DisplayCurrentPokemonPicture();
    DisplayCurrentPokemonCategoryTypeText();
}

// This task handles quitting the Pokedex from the List Page.
// The list page is the only page that can quit the pokedex, so that should be the only place this is called from
static void Task_ResearchPokedexFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(sResearchPokedexBackground0TilemapPtr);
        Free(sResearchPokedexBackground1TilemapPtr);
        Free(sResearchPokedexBackground2TilemapPtr);
        Free(sResearchPokedexBackground3TilemapPtr);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////                                        INFO PAGE                                           /////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

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

// This is the task that loads all graphics for Info Page.
// This is called whenever the Info Page is navigated to from any other page (List Page, other info pages)
// This loads and displays the Info Page, then hands off to Task_InfoPageInput to handle input
static bool8 LoadInfoPage(void)
{
    //Reset GPU Registers
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);  
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);

    // Init Backgrounds
    InitBgsFromTemplates(0, sInfoPageBgTemplates, ARRAY_COUNT(sInfoPageBgTemplates));
    SetBgTilemapBuffer(BG_BOOK_PAGES, sResearchPokedexBackground1TilemapPtr);
    SetBgTilemapBuffer(BG_BOOK_COVER, sResearchPokedexBackground3TilemapPtr);

    // Load Backgrounds
    DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sInfoPagesTiles, 0, 0, 0);
    DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sInfoBackgroundTiles, 0, 0, 0);
    LZDecompressWram(sInfoPagesTilemap, sResearchPokedexBackground1TilemapPtr);
    LZDecompressWram(sInfoBackgroundTilemap, sResearchPokedexBackground3TilemapPtr);
    CopyBgTilemapBufferToVram(BG_BOOK_PAGES);                                            // Copies the tilemaps to VRAM?
    CopyBgTilemapBufferToVram(BG_BOOK_COVER);
    LoadPalette(sInfoBackgroundPalette, BG_PLTT_ID(0), sizeof(sInfoBackgroundPalette));  // Load the palettes for the background layers
    LoadPalette(sInfoPagesPalette, BG_PLTT_ID(1), sizeof(sInfoPagesPalette));

    // Load Windows
    InitWindows(sInfoPageWinTemplates);                                 // Create windows defined in the template
    DeactivateAllTextPrinters();                                        // Deactivate whatever text printers are left from before
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);  // Load the font palette in Background Palette 15
    FillWindowPixelBuffer(0, PIXEL_FILL(0));                            // Fills Window 0 with transparent pixels to zero it out.
    FillWindowPixelBuffer(1, PIXEL_FILL(0));                            // Fills Window 1 with transparent pixels to zero it out.

    // Display Everything
    PutWindowTilemap(0);                                                // Puts Window 0 on the tile map
    PutWindowTilemap(1);                                                // Puts Window 1 on the tile map 
    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);

    sResearchPokedexState->currentPage = INFO_PAGE;
    return TRUE;
}

// This is the task that handles Info Page input
// For almost all the time that the Info Page is on screen, this is the task being run.
// It should be preceeded by Task_InfoListPage, and followed by the task that loads whatever page is coming next.
static void Task_InfoPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ListPageWaitFadeIn;
    }
}

static void Task_InfoPageWaitFadeIn(u8 taskId)
{
    // Do nothing until the palette fade finishes, then replace ourself with the main menu task.
    if (!gPaletteFade.active)
    {
        if(LoadInfoPage()){
            gTasks[taskId].func = Task_InfoPageInput;
        }
    }
}