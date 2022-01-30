#include "kernel.h"

UINT64 kernelStart(BootConfig *bootConfig)
{
    /**UINT64 vertical = bootConfig->VerticalResolution;
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
    return PassBack;*/

    UINT64 PassBack = 0;
    initVideo(bootConfig);
    initShell(bootConfig->videoConfig);
    

    int *time;
    POINT p1;
    p1.X = 100;
    p1.Y = 100;
    DrawLetter('X', p1);

    POINT p2;
    p2.X = 120;
    p2.Y = 100;
    POINT p3;
    p3.X = 140;
    p3.Y = 100;
    POINT p4;
    p4.X = 160;
    p4.Y = 100;
    POINT p5;
    p5.X = 180;
    p5.Y = 100;
    POINT p6;
    p6.X = 200;
    p6.Y = 100;
    POINT p7;
    p7.X = 220;
    p7.Y = 100;
    POINT p8;
    p8.X = 240;
    p8.Y = 100;
    POINT p9;
    p9.X = 260;
    p9.Y = 100;
    POINT p10;
    p10.X = 280;
    p10.Y = 100;
    POINT p11;
    p11.X = 300;
    p11.Y = 100;
    POINT p12;
    p12.X = 320;
    p12.Y = 100;
    DrawLetter('M', p2);
    DrawLetter('r', p3);
    DrawLetter('S', p4);
    DrawLetter('h', p5);
    DrawLetter('i', p6);
    DrawLetter('e', p7);
    DrawLetter('h', p8);
    DrawLetter('X', p9);
    DrawLetter('6', p10);
    DrawLetter('-', p11);
    DrawLetter('_', p12);

    while (1)
    {
        ;
    }

    return 0;
}

/*int DrawPixel(UINT32 *VideoHandle, UINT32 Color, int X, int Y, UINT64 horizontal)
{
    UINT32 *Pixel = VideoHandle;
    Pixel += Y * horizontal + X;
    *Pixel = Color;
    return 0;
}*/