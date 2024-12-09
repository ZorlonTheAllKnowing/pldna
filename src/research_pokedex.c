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
    u16 pokeBallRotationStep;
    u16 pokeBallRotationBackup;
    u8 pokeBallRotation;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u16 unkArr1[4]; // Cleared, never read
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

static const u16 sResearchPokedexBackgroundPalette[] = INCBIN_U16("graphics/pokedex/researchdex/list_background.gbapal");
static const u16 sResearchPokedexListPalette[] = INCBIN_U16("graphics/pokedex/researchdex/list_pages.gbapal");
static const u32 sResearchPokedexBackgroundTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.bin.lz");
static const u32 sResearchPokedexListTilemap[] = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.bin.lz");
static const u32 sResearchPokedexBackgroundTiles[] = INCBIN_U32("graphics/pokedex/researchdex/list_background_tiles.4bpp.lz");
static const u32 sResearchPokedexListTiles[] = INCBIN_U32("graphics/pokedex/researchdex/list_pages_tiles.4bpp.lz");

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

static void Task_ResearchPokedexFadeIn(u8);
static void InitResearchPokedexBg(void);
static void InitResearchPokedexWindow(void);
static void Task_ResearchPokedexMainInput(u8);
static void DisplayListText(void);
static void DisplayCurrentPokemonCategoryTypeText(void);
static void DisplayCurrentPokemonPicture(void);
static void Task_ResearchPokedexFadeOut(u8);

EWRAM_DATA static u8 *sResearchPokedexBackgroundTilemapPtr = NULL;
EWRAM_DATA static u8 *sResearchPokedexListTilemapPtr = NULL;

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_ShowResearchPokedex(void)
{
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
    // why doesn't this one use the dma manager either?
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();

    sPokedexView = AllocZeroed(sizeof(struct PokedexView)); // Allocate memory for Pokedex data
    sPokedexView->selectedPokemon = 0;
    
    LoadPalette(sResearchPokedexBackgroundPalette, BG_PLTT_ID(0), sizeof(sResearchPokedexBackgroundPalette));
    LoadPalette(sResearchPokedexListPalette, BG_PLTT_ID(1), sizeof(sResearchPokedexListPalette));
    sResearchPokedexBackgroundTilemapPtr = AllocZeroed(0x800);
    sResearchPokedexListTilemapPtr = AllocZeroed(0x800);
    InitResearchPokedexBg();
    InitResearchPokedexWindow();
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(BG_BOOK_PAGES, &sResearchPokedexListTiles, 0, 0, 0);
    DecompressAndCopyTileDataToVram(BG_BOOK_COVER, &sResearchPokedexBackgroundTiles, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressWram(sResearchPokedexBackgroundTilemap, sResearchPokedexBackgroundTilemapPtr);
    LZDecompressWram(sResearchPokedexListTilemap, sResearchPokedexListTilemapPtr);
    CopyBgTilemapBufferToVram(BG_BOOK_PAGES);
    CopyBgTilemapBufferToVram(BG_BOOK_COVER);
    DisplayListText();
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(MainCB2);
    CreateTask(Task_ResearchPokedexFadeIn, 0);
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_ResearchPokedexFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ResearchPokedexMainInput;
}

static void Task_ResearchPokedexMainInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ResearchPokedexFadeOut;
    }
    if (JOY_HELD(DPAD_UP))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sPokedexView->selectedPokemon > 0){
            sPokedexView->selectedPokemon--;
        }
    }
    if (JOY_HELD(DPAD_DOWN))
    {
        FillWindowPixelBuffer(0, TEXT_COLOR_TRANSPARENT);
        FillWindowPixelBuffer(1, TEXT_COLOR_TRANSPARENT);
        if(sPokedexView->selectedPokemon < HIGHEST_MON_NUMBER){
            sPokedexView->selectedPokemon++;
        }
    }
    if (JOY_HELD(DPAD_LEFT))
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
    if (JOY_HELD(DPAD_RIGHT))
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
    DisplayListText();
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

static void DisplayListText(void)
{
    u8 xOffset = 3;
    u8 yOffset = 39;
    u8 color[3] = {0, 10, 3};
    u16 currentMon = sPokedexView->selectedPokemon;
    u8 i;

    for(i = 1; i < 8; i++){
        switch (i)
        {
        case 1:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_SMALL_NARROWER, xOffset+6, yOffset - 32, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        case 2:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_SMALL_NARROWER, xOffset+6, yOffset - 22, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        case 3:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_SMALL_NARROW, xOffset, yOffset - 12, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        case 4:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_NARROW, xOffset, yOffset, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        case 5:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_SMALL_NARROW, xOffset, yOffset + 12, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        case 6:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_SMALL_NARROWER, xOffset+6, yOffset + 22, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        case 7:
            ConvertIntToDecimalStringN(gStringVar1, (currentMon-3+i), STR_CONV_MODE_LEADING_ZEROS, 4);
            StringExpandPlaceholders(gStringVar2, GetSpeciesName(currentMon-3+i));
            StringExpandPlaceholders(gStringVar4, sText_PokedexListItem);
            AddTextPrinterParameterized4(0, FONT_SMALL_NARROWER, xOffset+6, yOffset + 32, 0, 0, color, TEXT_SKIP_DRAW, gStringVar4);
            break;
        default:
            break;
        }
    }
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void DisplayCurrentPokemonPicture(void)
{
    u8 xPos = 160;
    u8 yPos = 65;
    u16 currentMon = sPokedexView->selectedPokemon + 1;
    
    FreeAndDestroyMonPicSprite(sPokedexView->monSpriteIds[0]);
    sPokedexView->monSpriteIds[0] = CreateMonSpriteFromNationalDexNumber(currentMon, xPos, yPos, 0);
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
        .mapBaseIndex = 30,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = BG_SCROLLING_LIST,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
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

static void InitResearchPokedexBg(void)
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

static void InitResearchPokedexWindow(void)
{
    InitWindows(sResearchPokedexWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
}
