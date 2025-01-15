// #ifndef GUARD_BLIT_H
// #define GUARD_BLIT_H

void bitmapDrawInWindow(u32 windowID);
void bitmapDrawPixel(u32 windowID, u8 x, u8 y, u8 color);
void bitmapDrawLine(u32 windowID, u8 x1, u8 y1, u8 x2, u8 y2, u8 color);
void bitmapDrawRectangle(u32 windowID, u8 x, u8 y, u8 width, u8 height, u8 color);
void bitmapDrawCircle(u32 windowID, u8 xCenter, u8 yCenter, u8 radius, u8 color);
void bitmapDrawRegularHexagon(u32 windowID, u8 xCenter, u8 yCenter, u8 radius, u8 color);
void bitmapDrawIrregularHexagon(u32 windowID, u8 xCenter, u8 yCenter, u8 radius0, u8 radius1, u8 radius2, u8 radius3, u8 radius4, u8 radius5, u8 color);
void bitmapScanlineFill(u32 windowID, u8 xStart, u8 yStart, u8 fillColor);
u8 bitmapGetPixelColor(u32 windowID, u8 x, u8 y);

void bitmapDrawPixelColorBasedOnDistance(u32 windowID, u8 x, u8 y, u8 xCenter, u8 yCenter, u8 maxDistance);
void bitmapDrawGradientLine(u32 windowID, u8 x1, u8 y1, u8 x2, u8 y2, u8 xCenter, u8 yCenter, u8 maxDistance);
void bitmapScanlineGradientFill(u32 windowID, u8 xStart, u8 yStart, u8 xCenter, u8 yCenter, u8 maxDistance);

// #endif // GUARD_DIPLOMA_H