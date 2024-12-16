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

#define MAX_MONS_ON_SCREEN 4
#define HIGHEST_MON_NUMBER 2000

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT + 1];
    u16 pokemonListCount;
    u16 selectedPokemon;
    u16 selectedPokemonBackup;
    u16 dexMode;
    u16 dexModeBackup;
    u16 dexOrder;
    u16 dexOrderBackup;
    u16 seenCount;
    u16 ownCount;
    u16 monSpriteIds[MAX_MONS_ON_SCREEN];
    u16 selectedMonSpriteId;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u8 filler[8];
    u8 currentPage;
    u8 currentPageBackup;
    bool8 isSearchResults:1;
    u8 selectedScreen;
    u8 screenSwitchState;
    u8 menuIsOpen;
    u16 menuCursorPos;
    s16 menuY;     //Menu Y position (inverted because we use REG_BG0VOFS for this)
    u8 unkArr2[8]; // Cleared, never read
    u8 unkArr3[8]; // Cleared, never read
};

// Graphics data for List Pages
static const u16 sListBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/list_background.gbapal");
static const u16 sListPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/list_pages.gbapal");
static const u32 sListBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.bin.lz");
static const u32 sListPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.bin.lz");
static const u32 sListBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.4bpp.lz");
static const u32 sListPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.4bpp.lz");

// Graphics data for Info Pages
static const u16 sInfoBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/info_background.gbapal");
static const u16 sInfoPagesPalette[] = INCBIN_U16("graphics/pokedex/researchdex/info_pages.gbapal");
static const u32 sInfoBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/info_background_tiles.bin.lz");
static const u32 sInfoPagesTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/info_pages_tiles.bin.lz");
static const u32 sInfoBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/info_background_tiles.4bpp.lz");
static const u32 sInfoPagesTiles[] = INCBIN_U32("graphics/pokedex/researchdex/info_pages_tiles.4bpp.lz");

extern const u8 gText_DexNational[];
extern const u8 gText_DexHoenn[];
extern const u8 gText_Peekaboo[];
static const u8 sText_PokedexListItem[] = _("Pg {STR_VAR_1}-{STR_VAR_2}");

enum{
    BG_PAGE_CONTENT,
    BG_BOOK_PAGES,
    BG_SCROLLING_LIST,
    BG_BOOK_COVER,
};

static EWRAM_DATA struct PokedexView *sPokedexView = NULL;

static void MainCB2(void);

// Scrolling List Page
static void Task_LoadListPage(u8);
static void InitListPageBgs(void);
static void InitListPageWindows(void);
static void DisplayListPageText(void);
static void DisplaySingleListEntryText(u16, u8, u8, u8);
static void DisplayCurrentPokemonCategoryTypeText(void);
static void DisplayCurrentPokemonPicture(void);
static void Task_ResearchPokedexMainInput(u8);
static void Task_ResearchPokedexFadeOut(u8);

// Info Pages
static void Task_LoadInfoPage(u8);
static void Task_InfoPageInput(u8);
static void Task_CloseInfoPage(u8);

EWRAM_DATA static u8 *sResearchPokedexBackgroundTilemapPtr = NULL;
EWRAM_DATA static u8 *sResearchPokedexListTilemapPtr = NULL;

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

/////////////////////////////////////////////
//               LIST PAGE                 //
/////////////////////////////////////////////

// List Page Background Template
static const struct BgTemplate sResearchPokedexBgTemplates[4] =
{
    {
        .bg = BG_PAGE_CONTENT,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 1,
    },
    {
        .bg = BG_BOOK_PAGES,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = BG_SCROLLING_LIST,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 1,
    },
    {
        .bg = BG_BOOK_COVER,
        .charBaseIndex = 0,
        .mapBaseIndex = 25,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

//List Page Window Template
static const struct WindowTemplate sResearchPokedexWinTemplates[3] =
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

// Call back to start the Pokedex. This is called from start_menu.c and is the entry
// point for all pokedex things. 
// This clears out all the overworld graphics data, loads the palettes/windows/backgrounds etc.
// for the Pokedex, and fades to black for the transition.
void CB2_ShowResearchPokedex(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        // First step of the state machine
        // Zeroes out and clears all necessary graphical doohickies
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, 0, PLTT, PLTT_SIZE);
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        FreeAllWindowBuffers();
        LoadPalette(sListBackgroundPalette, BG_PLTT_ID(0), sizeof(sListBackgroundPalette));  // Load the palettes for the background layers
        LoadPalette(sListPagesPalette, BG_PLTT_ID(1), sizeof(sListPagesPalette));
        sResearchPokedexBackgroundTilemapPtr = AllocZeroed(0x800);                           // Allocate memory for the Tilemaps
        sResearchPokedexListTilemapPtr = AllocZeroed(0x800);
        InitListPageBgs();                                                                   // Initiate the Backgrounds
        InitListPageWindows();                                                               // Initiate the Windows
        ResetTempTileDataBuffers();                                                          // Not sure
        DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sListPagesTiles, 0, 0, 0);           // Puts the two backgrounds into VRAM
        DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sListBackgroundTiles, 0, 0, 0);
        gMain.state = 1;
        break;
    case 1:
        sPokedexView = AllocZeroed(sizeof(struct PokedexView));                              // Allocate memory for Pokedex data
        sPokedexView->selectedPokemon = 0;                                                   // Set current Pokemon to the first one

        LZDecompressWram(sListBackgroundTilemap, sResearchPokedexBackgroundTilemapPtr);
        LZDecompressWram(sListPagesTilemap, sResearchPokedexListTilemapPtr);
        CopyBgTilemapBufferToVram(BG_BOOK_PAGES);                                            // Copies the tilemaps to VRAM?
        CopyBgTilemapBufferToVram(BG_BOOK_COVER);
        DisplayListPageText();                                                               // Displays the List window
        DisplayCurrentPokemonPicture();                                                      // Displays the sprite image of the current pokemon
        DisplayCurrentPokemonCategoryTypeText();                                             // Displays the current pokemon's category name

        gMain.state++;
        break;
    case 2:
        while (FreeTempTileDataBuffersIfPossible())
            ;
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);                           // Fades FROM black
        EnableInterrupts(1);
        gMain.state++;
        break;
    case 3:
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        CreateTask(Task_LoadListPage, 0);
        break;
    }
}

// Waits for the fade from CB2_ShowResearchPokedex to end,
// then puts Task_ResearchPokedexMainInput in the tasks to handle inputs
static void Task_LoadListPage(u8 taskId)
{
    if (!gPaletteFade.active) 
        gTasks[taskId].func = Task_ResearchPokedexMainInput;         
}

// This is called by CB2_ShowResearchPokedex
static void InitListPageWindows(void)
{
    InitWindows(sResearchPokedexWinTemplates);                          // Create windows defined in the template
    DeactivateAllTextPrinters();                                        // Deactivate whatever text printers are left from before
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);  // Load the font palette in Background Palette 15
    FillWindowPixelBuffer(0, PIXEL_FILL(0));                            // Fills Window 0 with transparent pixels to zero it out.
    FillWindowPixelBuffer(1, PIXEL_FILL(0));                            // Fills Window 1 with transparent pixels to zero it out.
    PutWindowTilemap(0);                                                // Puts Window 0 on the tile map
    PutWindowTilemap(1);                                                // Puts Window 1 on the tile map
}

static void InitListPageBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sResearchPokedexBgTemplates, ARRAY_COUNT(sResearchPokedexBgTemplates));
    SetBgTilemapBuffer(BG_BOOK_PAGES, sResearchPokedexListTilemapPtr);
    SetBgTilemapBuffer(BG_BOOK_COVER, sResearchPokedexBackgroundTilemapPtr);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void DisplayListPageText(void)
{
    u8 xOffset = 3;
    u8 yOffset = 39;
    u16 currentMon = sPokedexView->selectedPokemon;
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

static void DisplaySingleListEntryText(u16 currentMon, u8 fontID, u8 xPos, u8 yPos){
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
    u16 currentMon = sPokedexView->selectedPokemon + 1;
    
    FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[0]);
    sPokedexView->monSpriteIds[0] = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 2);
    gSprites[sPokedexView->monSpriteIds[0]].oam.priority = 3;
}

static void DisplayCurrentPokemonCategoryTypeText(void){
    u8 xOffset = 0;
    u8 yOffset = 2;
    u8 color[3] = {0, 10, 3};
    u16 currentMon = sPokedexView->selectedPokemon + 1;

    StringCopy(gStringVar3, GetSpeciesCategory(currentMon));
    AddTextPrinterParameterized4(1, FONT_NORMAL, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void Task_ResearchPokedexMainInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_LoadInfoPage;
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
        if(sPokedexView->selectedPokemon > 0){
            sPokedexView->selectedPokemon--;
        }
    }
    if (JOY_REPEAT(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sPokedexView->selectedPokemon < HIGHEST_MON_NUMBER){
            sPokedexView->selectedPokemon++;
        }
    }
    if (JOY_REPEAT(DPAD_LEFT))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sPokedexView->selectedPokemon > 5){
            sPokedexView->selectedPokemon -= 5;
        }
        else{
            sPokedexView->selectedPokemon = 0;
        }
    }
    if (JOY_REPEAT(DPAD_RIGHT))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sPokedexView->selectedPokemon < HIGHEST_MON_NUMBER - 5){
            sPokedexView->selectedPokemon += 5;
        }
        else{
            sPokedexView->selectedPokemon = HIGHEST_MON_NUMBER;
        }
    }
    ShowBg(BG_PAGE_CONTENT);
    ShowBg(BG_BOOK_PAGES);
    ShowBg(BG_SCROLLING_LIST);
    ShowBg(BG_BOOK_COVER);
    DisplayListPageText();
    DisplayCurrentPokemonPicture();
    DisplayCurrentPokemonCategoryTypeText();
}

static void Task_ResearchPokedexFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(sResearchPokedexBackgroundTilemapPtr);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

//////////////////////////////////////////
//          INFO PAGE                   //
//////////////////////////////////////////

static void Task_LoadInfoPage(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_InfoPageInput;
}

static void Task_InfoPageInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_LoadListPage;
    }
    //DisplayListPageText();
    //DisplayCurrentPokemonPicture();
    //DisplayCurrentPokemonCategoryTypeText();
}

static u8 LoadInfoScreen(struct PokedexListItem *item, u8 monSpriteId)
{
    return 0;
}