#include "video.h"

VideoConfig *videoConfig;
UINT32 *videoStart;

BMPConfig *asciiConfig;
UINT32 *asciiStart;

int initVideo(BootConfig *bootConfig){
    videoConfig = &bootConfig->videoConfig;
    videoStart = (UINT32 *)bootConfig->videoConfig.FrameBufferBase;

    asciiConfig = &bootConfig->ascii;
    asciiStart = (UINT32*)bootConfig->ascii.PixelStart;

    BLOCK BackGround;

    BackGround.Start.X = 0;
    BackGround.Start.Y = 0;
    BackGround.End.X = bootConfig->videoConfig.HorizontalResolution - 1;
    BackGround.End.Y = bootConfig->videoConfig.VerticalResolution - 1;
    BackGround.Color = 0xFF0078D7;
    DrawBlock(BackGround);
    return 0;
}

int DrawPixel(PIXEL Pixel)
{
    UINT32 *Position = videoStart + (Pixel.Y - 1) * videoConfig->PixelsPerScanLine + Pixel.X;
    *Position = Pixel.Color;
    return 0;
}

int DrawBlock(BLOCK Block)
{
    PIXEL Pixel;
    Pixel.Color = Block.Color;
    for (int y = Block.Start.Y; y < Block.End.Y;y++){
        for (int x = Block.Start.X; x < Block.End.X;x++){
            Pixel.X = x;
            Pixel.Y = y;
            DrawPixel(Pixel);
        }
    }
    return 0;
}

int subtractOneIfBiggerThanZero(int value)
{
    return value > 0 ? value - 1 : value;
}

int DrawLetter(char c, POINT dest)
{
    POINT inAscii = getPosition(c);
    //UINTN startAscii = asciiStart + (inAscii.Y - 1) * PIC_WIDTH + inAscii.X;
    //UINTN startVideo = videoStart + (dest.Y - 1) * videoConfig->HorizontalResolution + dest.X;
    for (int y = 0; y < LETTER_HEIGHT; y++)
    {
        for (int x = 0; x < LETTER_WIDTH; x++)
        {
            //找到当前ascii和video的point就好办了

            UINT32 *ascii = asciiStart + inAscii.X + y * PIC_WIDTH + (subtractOneIfBiggerThanZero(inAscii.Y)) * PIC_WIDTH + x;
            UINT32 *video = videoStart + dest.X + y * videoConfig->HorizontalResolution + (subtractOneIfBiggerThanZero(dest.Y)) * videoConfig->HorizontalResolution + x;
            *video = *ascii;
        }
    }
    return 0;
}
POINT getPosition(char c)
{
    if (c < 0x20 || c > 0x7e)
    {
        //不支持显示的字符，显示乱码
        POINT unknown = {
            .X = 31 * LETTER_WIDTH,
            .Y = 2 * LETTER_HEIGHT};
        return unknown;
    }
    int line = (c - 0x20) / 0x20;
    /*if (c >= 0x60)
        line = 2;
    else if (c >= 0x40)
        line = 1;
    else
    {
        line = 0;
    }*/

    //int subtraction = line * (PIC_WIDTH / LETTER_WIDTH);
    //int x = (c - subtraction - 0x20) * LETTER_WIDTH;

    int y = line * LETTER_HEIGHT;
    int x = ((c - 0x20) % 0x20) * LETTER_WIDTH;

    POINT p = {
        .X = x,
        .Y = y};
    return p;
}
