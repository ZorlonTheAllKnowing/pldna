#include "global.h"
#include "bitmap_drawer.h"
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
#include "graphics.h"
#include "blit.h"

void drawInWindow(u32 windowID)
{
    u8 bg = gWindows[windowID].window.bg;
    u8 tilemapLeft = gWindows[windowID].window.tilemapLeft;
    u8 tilemapTop = gWindows[windowID].window.tilemapTop;
    u8 width = gWindows[windowID].window.width * 8;
    u8 height = gWindows[windowID].window.height;
    u8 paletteNum = gWindows[windowID].window.paletteNum;
    u16 baseBlock = gWindows[windowID].window.baseBlock;

    struct Bitmap pixelRect;
    pixelRect.pixels = gWindows[windowID].tileData;

    u8 *firstPixel = pixelRect.pixels;
    u8 fillValue = 4;

    u8 toOrr1 = fillValue << 4;
    u8 toOrr2 = fillValue & 0xF;

    firstPixel[0] = toOrr1 | (*firstPixel & 0xF);
    firstPixel[0] = toOrr2 | (*firstPixel & 0xF0);

    firstPixel[1] = toOrr1 | (*firstPixel & 0xF);
    firstPixel[1] = toOrr2 | (*firstPixel & 0xF0);

    firstPixel[2] = toOrr1 | (*firstPixel & 0xF);
    firstPixel[2] = toOrr2 | (*firstPixel & 0xF0);

    firstPixel[3] = toOrr1 | (*firstPixel & 0xF);
    firstPixel[3] = toOrr2 | (*firstPixel & 0xF0);

    firstPixel[32] = toOrr1 | (*firstPixel & 0xF);
    firstPixel[32] = toOrr2 | (*firstPixel & 0xF0);
    CopyWindowToVram(windowID, COPYWIN_FULL);
}

void drawPixel(u32 windowID, u8 x, u8 y)
{

}