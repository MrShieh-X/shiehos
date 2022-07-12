#include "video.h"

VideoConfig *videoConfig;
UINT32 *videoStart;

BMPConfig*AsciiBmp;
UINT32 *AsciiStart;

int initVideo(BootConfig *bootConfig){
    videoConfig = &bootConfig->videoConfig;
    videoStart = (UINT32 *)bootConfig->videoConfig.FrameBufferBase;

    AsciiBmp = (bootConfig->AsciiBmp);
    AsciiStart = (UINT32 *)bootConfig->AsciiBmp->PixelStart;

    BLOCK BackGround;

    BackGround.Start.X = 0;
    BackGround.Start.Y = 0;
    BackGround.End.X = bootConfig->videoConfig.HorizontalResolution - 1;
    BackGround.End.Y = bootConfig->videoConfig.VerticalResolution - 1;
    BackGround.Color = 0xFF0078D7;
    drawBlock(BackGround);
    return 0;
}

int drawPixel(PIXEL Pixel)
{
    UINT32 *Position = videoStart + (Pixel.Y - 1) * videoConfig->PixelsPerScanLine + Pixel.X;
    *Position = Pixel.Color;
    return 0;
}

int drawBlock(BLOCK Block)
{
    PIXEL Pixel;
    Pixel.Color = Block.Color;
    for (int y = Block.Start.Y; y < Block.End.Y;y++){
        for (int x = Block.Start.X; x < Block.End.X;x++){
            Pixel.X = x;
            Pixel.Y = y;
            drawPixel(Pixel);
        }
    }
    return 0;
}

int drawLetter(character c, POINT dest)
{
    POINT inAscii = getPosition(c);
    //UINTN startAscii = asciiStart + (inAscii.Y - 1) * PIC_WIDTH + inAscii.X;
    //UINTN startVideo = videoStart + (dest.Y - 1) * videoConfig->HorizontalResolution + dest.X;
    for (int y = 0; y < LETTER_HEIGHT; y++)
    {
        for (int x = 0; x < LETTER_WIDTH; x++)
        {
            //找到当前ascii和video的point就好办了

            UINT32 *ascii = AsciiStart + y * PIC_WIDTH + inAscii.Y * PIC_WIDTH + inAscii.X + x;
            UINT32 *video = videoStart + dest.Y * videoConfig->HorizontalResolution + y * videoConfig->HorizontalResolution + dest.X + x;
            *video = *ascii;
        }
    }
    return 0;
}

/*int drawLetter(UINT8 Ascii, POINT Destination)
{
    UINT8 Index = Ascii - 32;
    if (Ascii < 32 || Ascii > 126) // 0x20~0x7E
    {
        Index = 127 - 32;
    }
    UINT32 *From = AsciiStart + (Index % 32) * LETTER_WIDTH+ (Index / 32) * LETTER_HEIGHT * 640;
    UINT32 *To = videoStart + Destination.X + Destination.Y * videoConfig->PixelsPerScanLine;
    for (int i = 0; i < LETTER_HEIGHT; i++)
    {
        for (int j = 0; j < LETTER_WIDTH; j++)
        {
            *To = *From;
            From++;
            To++;
        }
        From = From + 640 - LETTER_WIDTH;
        To = To + videoConfig->PixelsPerScanLine - LETTER_WIDTH;
    }
    return 0;
}*/

POINT getPosition(character c)
{
    if (c < 0x20 || c > 0x7e)
    {
        //不支持显示的字符，显示乱码
        POINT unknown;
        unknown.X = 31 * LETTER_WIDTH;
        unknown.Y = 2 * LETTER_HEIGHT;
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
