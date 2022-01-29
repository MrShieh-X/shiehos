#include "kernel.h"

UINT64 _start(BootConfig *bootConfig){
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
	
	POINT p1={.X=100,.Y=100};
	POINT p2={.X=130,.Y=100};
	POINT p3={.X=160,.Y=100};
	POINT p4={.X=190,.Y=100};
	POINT p5={.X=220,.Y=100};
	POINT p6={.X=250,.Y=100};
	POINT p7={.X=280,.Y=100};
	POINT p8={.X=310,.Y=100};
	POINT p9={.X=340,.Y=100};
	POINT p10={.X=370,.Y=100};
	POINT p11={.X=400,.Y=100};
	POINT p12={.X=430,.Y=100};
	DrawLetter('X',p1);
	DrawLetter('4',p2);
	DrawLetter('8',p3);
	DrawLetter('A',p4);
	DrawLetter(0xFF,p5);
	DrawLetter('v',p6);
	DrawLetter(0x00,p7);
	DrawLetter('a',p8);
	DrawLetter('{',p9);
	DrawLetter('}',p10);
	DrawLetter('<',p11);
	DrawLetter('>',p12);

    while (1)
    {
        ;
    }

    return PassBack;
}

/*int DrawPixel(UINT32 *VideoHandle, UINT32 Color, int X, int Y, UINT64 horizontal)
{
    UINT32 *Pixel = VideoHandle;
    Pixel += Y * horizontal + X;
    *Pixel = Color;
    return 0;
}*/