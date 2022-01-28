#include "kernel.h"

UINT64 _start(BootConfig *bootConfig){
    UINT64 vertical = bootConfig->VerticalResolution;
    UINT64 horizontal = bootConfig->HorizontalResolution;
    UINT64 PassBack = 0;
    UINT32 DarkBlue = 0xFF18679A;
    UINT32 *VideoHandle=(UINT32*)(bootConfig->FrameBufferBase);
    for (int i = 0; i < vertical;i++){
        for (int j = 0; j < horizontal;j++){
            DrawPixel(VideoHandle, DarkBlue, j, i, horizontal);
        }
    }
    PassBack = bootConfig->FrameBufferSize;
    return PassBack;
}

int DrawPixel(UINT32 *VideoHandle, UINT32 Color, int X, int Y, UINT64 horizontal)
{
    UINT32 *Pixel = VideoHandle;
    Pixel += Y * horizontal + X;
    *Pixel = Color;
    return 0;
}