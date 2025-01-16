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
#include "trig.h"

#include "test/test.h"
#include "test_runner.h"

#define MAX_FILL_QUEUE_SIZE 4096

typedef struct {u8 x, y;} Point;

void bitmapDrawInWindow(u32 windowID)
{

}

void bitmapDrawPixel(u32 windowID, u8 x, u8 y, u8 color)
{
    struct Bitmap pixelRect;
    pixelRect.pixels = gWindows[windowID].tileData;
    u16 width = 32 * (gWindows[windowID].window.width - 1);
    u8 *firstPixel = pixelRect.pixels;
    u8 toOrr1 = color << 4;
    u8 toOrr2 = color & 0xF;
    u8 nibbleIndex = x % 2;
    u16 pixel = (x / 8) * 32 + (x % 8) / 2 + (y * 4) + (y / 8) * width;

    if (nibbleIndex == 0) {
        firstPixel[pixel] = toOrr2 | (firstPixel[pixel] & 0xF0);
    } else {
        firstPixel[pixel] = toOrr1 | (firstPixel[pixel] & 0xF);
    }
}

// Colors a pixel based on how far it is from another pixel. 
// The further it is, the higher the index is for the palette color chosen
void bitmapDrawPixelColorBasedOnDistance(u32 windowID, u8 x, u8 y, u8 xCenter, u8 yCenter, u8 maxDistance)
{
    struct Bitmap pixelRect;
    pixelRect.pixels = gWindows[windowID].tileData;
    u16 width = 32 * (gWindows[windowID].window.width - 1);
    u8 *firstPixel = pixelRect.pixels;
    u8 color = 0;

    u8 dx = (x >= xCenter) ? (x - xCenter) : (xCenter - x);
    u8 dy = (y >= yCenter) ? (y - yCenter) : (yCenter - y);
    u8 distance = Sqrt((dx * dx) + (dy * dy));
    if (distance < 2)
    {
        color = 2;
    }
    else{
        color = 2 + (13 * (distance - 2) / maxDistance);
    }

    u8 toOrr1 = color << 4;
    u8 toOrr2 = color & 0xF;
    u8 nibbleIndex = x % 2;
    u16 pixel = (x / 8) * 32 + (x % 8) / 2 + (y * 4) + (y / 8) * width;

    if (nibbleIndex == 0) {
        firstPixel[pixel] = toOrr2 | (firstPixel[pixel] & 0xF0);
    } else {
        firstPixel[pixel] = toOrr1 | (firstPixel[pixel] & 0xF);
    }
}

u8 bitmapGetPixelColor(u32 windowID, u8 x, u8 y)
{
    struct Bitmap pixelRect;
    pixelRect.pixels = gWindows[windowID].tileData;
    u16 width = 32 * (gWindows[windowID].window.width - 1);
    u8 *firstPixel = pixelRect.pixels;
    u8 nibbleIndex = x % 2;
    u16 pixel = (x / 8) * 32 + (x % 8) / 2 + (y * 4) + (y / 8) * width;
    u8 pixelByte = firstPixel[pixel];

    if (nibbleIndex == 0) {
        return pixelByte & 0xF;
    } else {
        return (pixelByte >> 4) & 0xF;
    }
}

void bitmapDrawLine(u32 windowID, u8 x1, u8 y1, u8 x2, u8 y2, u8 color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (!(x1 == x2 && y1 == y2))
    {
        bitmapDrawPixel(windowID, x1, y1, color);

        int e2 = err * 2;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void bitmapDrawGradientLine(u32 windowID, u8 x1, u8 y1, u8 x2, u8 y2, u8 xCenter, u8 yCenter, u8 maxDistance)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (!(x1 == x2 && y1 == y2))
    {
        bitmapDrawPixelColorBasedOnDistance(windowID, x1, y1, xCenter, yCenter, maxDistance);

        int e2 = err * 2;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void bitmapDrawRectangle(u32 windowID, u8 x, u8 y, u8 width, u8 height, u8 color)
{
    bitmapDrawLine(windowID, x, y, x + width, y, 4);
    bitmapDrawLine(windowID, x + width, y, x + width, y + height, 4);
    bitmapDrawLine(windowID, x + width, y + height, x, y + height, 4);
    bitmapDrawLine(windowID, x, y + height, x, y, 4);
}

void bitmapDrawCircle(u32 windowID, u8 xCenter, u8 yCenter, u8 radius, u8 color)
{
    int x = radius;
    int y = 0;
    int p = 1 - radius;

    while (x >= y) {
        bitmapDrawPixel(windowID, xCenter + x, yCenter + y, 4);
        bitmapDrawPixel(windowID, xCenter - x, yCenter + y, 4);
        bitmapDrawPixel(windowID, xCenter + x, yCenter - y, 4);
        bitmapDrawPixel(windowID, xCenter - x, yCenter - y, 4);
        bitmapDrawPixel(windowID, xCenter + y, yCenter + x, 4);
        bitmapDrawPixel(windowID, xCenter - y, yCenter + x, 4);
        bitmapDrawPixel(windowID, xCenter + y, yCenter - x, 4);
        bitmapDrawPixel(windowID, xCenter - y, yCenter - x, 4);

        if (p < 0) {
            p += 2 * y + 3;
        } else {
            p += 2 * (y - x) + 5;
            x--;
        }
        y++;
    }
}

void bitmapDrawRegularHexagon(u32 windowID, u8 xCenter, u8 yCenter, u8 radius, u8 color)
{
    u8 x = 0;
    u8 y = 0;

    x = (radius * .88);  //length * cos(30)
    y = (radius * .5);   //length * sin(30)

    bitmapDrawLine(windowID, xCenter + x, yCenter + y,      xCenter, yCenter + radius, color);
    bitmapDrawLine(windowID, xCenter, yCenter + radius,     xCenter - x, yCenter + y, color);
    bitmapDrawLine(windowID, xCenter - x, yCenter + y,      xCenter - x, yCenter - y, color);
    bitmapDrawLine(windowID, xCenter - x, yCenter - y,      xCenter, yCenter - radius, color);
    bitmapDrawLine(windowID, xCenter, yCenter - radius,     xCenter + x, yCenter - y, color);
    bitmapDrawLine(windowID, xCenter + x, yCenter - y,      xCenter + x, yCenter + y, color);
}

void bitmapDrawIrregularHexagon(u32 windowID, u8 xCenter, u8 yCenter, u8 radius0, u8 radius1, u8 radius2, u8 radius3, u8 radius4, u8 radius5, u8 color)
{
    u8 x0 = (radius0 * .88);    //length * cos(30)  //Coords for Atk
    u8 y0 = (radius0 * .5);     //length * sin(30)
    u8 x1 = (radius1 * 0);      //length * cos(90)  //Coords for HP
    u8 y1 = (radius1 * 1);      //length * sin(90)
    u8 x2 = (radius2 * .88);    //length * cos(150) //Coords for Sp. Atk
    u8 y2 = (radius2 * .5);     //length * sin(150)
    u8 x3 = (radius3 * .88);    //length * cos(210) //Coords for Sp. Def
    u8 y3 = (radius3 * .5);     //length * sin(210)
    u8 x4 = (radius4 * 0);      //length * cos(270) //Coords for Spd
    u8 y4 = (radius4 * 1);      //length * sin(270)
    u8 x5 = (radius5 * .88);    //length * cos(330) //Coords for Def
    u8 y5 = (radius5 * .5);     //length * cos(330)

    bitmapDrawLine(windowID, xCenter + x0, yCenter - y0,      xCenter + x1, yCenter - y1, color);
    bitmapDrawLine(windowID, xCenter + x1, yCenter - y1,      xCenter - x2, yCenter - y2, color);  
    bitmapDrawLine(windowID, xCenter - x2, yCenter - y2,      xCenter - x3, yCenter + y3, color);
    bitmapDrawLine(windowID, xCenter - x3, yCenter + y3,      xCenter - x4, yCenter + y4, color);
    bitmapDrawLine(windowID, xCenter - x4, yCenter + y4,      xCenter + x5, yCenter + y5, color);
    bitmapDrawLine(windowID, xCenter + x5, yCenter + y5,      xCenter + x0, yCenter - y0, color);
}

void bitmapScanlineFill(u32 windowID, u8 xStart, u8 yStart, u8 fillColor)
{
    u8 targetColor = bitmapGetPixelColor(windowID, xStart, yStart);
    // Check if targetColor is the same as fillColor
    if (targetColor == fillColor) return;

    // Get the dimensions of the window (bitmap)
    u8 pixelWidth = gWindows[windowID].window.width * 8;
    u8 pixelHeight = gWindows[windowID].window.height * 8;
    u8 xShapeLeft = xStart;

    // Find the leftmost side of the shape (first pixel on the boundary from the starting x)
    while (bitmapGetPixelColor(windowID, xShapeLeft, yStart) != targetColor && xShapeLeft > 0)
    {
        xShapeLeft--;
    }

    u8 lineStartX = 0;
    u8 lineStartY = 0;
    u8 lineEndX = 0;
    u8 lineEndY = 0;
    bool8 lineStarted = FALSE;

    // Start vertical scanline filling from the starting position (moving vertically)
    for (u8 x = 0; x < pixelWidth; x++) 
    {
        // Scan each pixel in this column (y-coordinate)
        for (u8 y = 0; y < pixelHeight; y++) 
        {
            // Get fill line start
            if (!lineStarted && bitmapGetPixelColor(windowID, x, y) != targetColor && bitmapGetPixelColor(windowID, x, y + 1) == targetColor)
            {
                lineStartX = x;
                lineStartY = y + 1;
                lineStarted = TRUE;
            }
            // Get fill line end
            else if(lineStarted && bitmapGetPixelColor(windowID, x, y) != targetColor && bitmapGetPixelColor(windowID, x, y - 1) == targetColor)
            {
                lineEndX = x;
                lineEndY = y;
                lineStarted = FALSE;
            }

            // Draw the fill line
            if (lineEndX > 0)
            {
                bitmapDrawLine(windowID, lineStartX, lineStartY, lineEndX, lineEndY, fillColor);
                lineStartX = 0;
                lineStartY = 0;
                lineEndX = 0;
                lineEndY = 0;
                lineStarted = FALSE;
            }
        }
        lineStartX = 0;
        lineStartY = 0;
        lineEndX = 0;
        lineEndY = 0;
        lineStarted = FALSE;
    }
}


void bitmapScanlineGradientFill(u32 windowID, u8 xStart, u8 yStart, u8 xCenter, u8 yCenter, u8 maxDistance)
{
    u8 targetColor = bitmapGetPixelColor(windowID, xStart, yStart);

    // Get the dimensions of the window (bitmap)
    u8 pixelWidth = gWindows[windowID].window.width * 8;
    u8 pixelHeight = gWindows[windowID].window.height * 8;
    u8 xShapeLeft = xStart;

    // Find the leftmost side of the shape (first pixel on the boundary from the starting x)
    while (bitmapGetPixelColor(windowID, xShapeLeft, yStart) != targetColor && xShapeLeft > 0)
    {
        xShapeLeft--;
    }

    u8 lineStartX = 0;
    u8 lineStartY = 0;
    u8 lineEndX = 0;
    u8 lineEndY = 0;
    bool8 lineStarted = FALSE;

    // Start vertical scanline filling from the starting position (moving vertically)
    for (u8 x = 0; x < pixelWidth; x++) 
    {
        // Scan each pixel in this column (y-coordinate)
        for (u8 y = 0; y < pixelHeight; y++) 
        {
            // Get fill line start
            if (!lineStarted && bitmapGetPixelColor(windowID, x, y) != targetColor && bitmapGetPixelColor(windowID, x, y + 1) == targetColor)
            {
                lineStartX = x;
                lineStartY = y + 1;
                lineStarted = TRUE;
            }
            // Get fill line end
            else if(lineStarted && bitmapGetPixelColor(windowID, x, y) != targetColor && bitmapGetPixelColor(windowID, x, y - 1) == targetColor)
            {
                lineEndX = x;
                lineEndY = y;
                lineStarted = FALSE;
            }

            // Draw the fill line
            if (lineEndX > 0)
            {
                bitmapDrawGradientLine(windowID, lineStartX, lineStartY, lineEndX, lineEndY, xCenter, yCenter, maxDistance);
                lineStartX = 0;
                lineStartY = 0;
                lineEndX = 0;
                lineEndY = 0;
                lineStarted = FALSE;
            }
        }
        lineStartX = 0;
        lineStartY = 0;
        lineEndX = 0;
        lineEndY = 0;
        lineStarted = FALSE;
    }
}