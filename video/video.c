#include "video.h"

VideoConfig *videoConfig;
UINT32 *videoStart;

BMPConfig *AsciiBmp;
UINT32 *AsciiStart;

POINT cursorNow;
long backups/*[125]*/[CURSOR_HEIGHT][CURSOR_WIDTH];

int initVideo(BootConfig *bootConfig) {
    videoConfig = &bootConfig->videoConfig;
    videoStart = (UINT32 *) bootConfig->videoConfig.FrameBufferBase;

    AsciiBmp = (bootConfig->AsciiBmp);
    AsciiStart = (UINT32 *) bootConfig->AsciiBmp->PixelStart;

    BLOCK BackGround;

    BackGround.Start.X = 0;
    BackGround.Start.Y = 0;
    BackGround.End.X = bootConfig->videoConfig.HorizontalResolution - 1;
    BackGround.End.Y = bootConfig->videoConfig.VerticalResolution - 1;
    BackGround.Color = 0xFF0078D7;
    drawBlock(BackGround);
    return 0;
}

int drawPixel(PIXEL Pixel) {
    UINT32 x = Pixel.X;
    UINT32 y = Pixel.Y;
    if (cursorSet && x >= cursorNow.X && x < (cursorNow.X + CURSOR_WIDTH) && y >= cursorNow.Y &&
        y < (cursorNow.Y + CURSOR_HEIGHT)) {
        int offsetX = x - cursorNow.X;
        int offsetY = y - cursorNow.Y;
        if (backups[offsetY][offsetX] == -1) {
            UINT32 *Position = videoStart + (y - 1) * videoConfig->PixelsPerScanLine + x;
            *Position = Pixel.Color;
        } else {
            backups[offsetY][offsetX] = Pixel.Color;
        }


    } else {
        UINT32 *Position = videoStart + (y - 1) * videoConfig->PixelsPerScanLine + x;
        *Position = Pixel.Color;
    }
    return 0;
}

UINT32 getPixelByXY(UINT32 x, UINT32 y) {
    POINT p;
    p.X = x;
    p.Y = y;
    return getPixel(p);
}

UINT32 getPixel(POINT Pixel) {
    UINT32 *Position = videoStart + (Pixel.Y - 1) * videoConfig->PixelsPerScanLine + Pixel.X;
    return *Position;
}

/**
 * x和y貌似要加一
 **/
int drawBlock(BLOCK Block) {
    PIXEL Pixel;
    Pixel.Color = Block.Color;
    for (int y = Block.Start.Y; y < Block.End.Y; y++) {
        for (int x = Block.Start.X; x < Block.End.X; x++) {
            Pixel.X = x;
            Pixel.Y = y;
            drawPixel(Pixel);
        }
    }
    return 0;
}

int drawLetter(character c, POINT dest) {
    POINT inAscii = getPosition(c);
    //UINTN startAscii = asciiStart + (inAscii.Y - 1) * PIC_WIDTH + inAscii.X;
    //UINTN startVideo = videoStart + (dest.Y - 1) * videoConfig->HorizontalResolution + dest.X;
    for (int y = 0; y < LETTER_HEIGHT; y++) {
        for (int x = 0; x < LETTER_WIDTH; x++) {
            //找到当前ascii和video的point就好办了

            UINT32 *ascii = AsciiStart + y * PIC_WIDTH + inAscii.Y * PIC_WIDTH + inAscii.X + x;


            UINT32 x2 = dest.X + x;
            UINT32 y2 = dest.Y + y + 1;
            if (cursorSet && x2 >= cursorNow.X && x2 < (cursorNow.X + CURSOR_WIDTH) && y2 >= cursorNow.Y &&
                y2 < (cursorNow.Y + CURSOR_HEIGHT)) {
                int offsetX = x2 - cursorNow.X;
                int offsetY = y2 - cursorNow.Y;
                if (backups[offsetY][offsetX] == -1) {
                    UINT32 *video =
                            videoStart + dest.Y * videoConfig->HorizontalResolution +
                            y * videoConfig->HorizontalResolution +
                            dest.X + x;
                    *video = *ascii;
                } else {
                    backups[offsetY][offsetX] = *ascii;
                }
            } else {
                UINT32 *video =
                        videoStart + dest.Y * videoConfig->HorizontalResolution +
                        y * videoConfig->HorizontalResolution +
                        dest.X + x;
                *video = *ascii;
            }
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

POINT getPosition(character c) {
    if (c < 0x20 || c > 0x7e) {
        //不支持显示的字符，显示乱码
        POINT unknown;
        unknown.X = 31 * LETTER_WIDTH;
        unknown.Y = 2 * LETTER_HEIGHT;
        return unknown;
    }
    UINT32 line = (c - 0x20) / 0x20;
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

    UINT32 y = line * LETTER_HEIGHT;
    UINT32 x = ((c - 0x20) % 0x20) * LETTER_WIDTH;

    POINT p = {
            .X = x,
            .Y = y};
    return p;
}


boolean drawMousePointer(POINT point) {
    UINT32 startX = point.X;
    UINT32 startY = point.Y;
    for (int i = 0; i < 16; i++) {
        PIXEL pixel = {
                .X=startX,
                .Y=startY + i,
                .Color=0x000000
        };
        drawPixel(pixel);
    }

    PIXEL pixel1 = {
            .X=startX,
            .Y=startY + 16,
            .Color=0x000000
    };
    drawPixel(pixel1);

    for (int i = 1; i < 12; i++) {
        PIXEL pixel = {
                .X=startX + i,
                .Y=startY + i,
                .Color=0x000000
        };
        drawPixel(pixel);
    }
    for (int i = 0; i < 5; i++) {
        PIXEL pixel = {
                .X=startX + 7 + i,
                .Y=startY + 12,
                .Color=0x000000
        };
        drawPixel(pixel);
    }
    for (int i = 0; i < 4; i++) {
        PIXEL pixel = {
                .X=startX + 4 - i,
                .Y=startY + 13 + i,
                .Color=0x000000
        };
        drawPixel(pixel);
    }
    {
        PIXEL pixel2 = {
                .X=startX + 5,
                .Y=startY + 14,
                .Color=0x000000
        };
        drawPixel(pixel2);
        PIXEL pixel3 = {
                .X=startX + 5,
                .Y=startY + 15,
                .Color=0x000000
        };
        drawPixel(pixel3);


        PIXEL pixel4 = {
                .X=startX + 8,
                .Y=startY + 14,
                .Color=0x000000
        };
        drawPixel(pixel4);
        PIXEL pixel5 = {
                .X=startX + 8,
                .Y=startY + 15,
                .Color=0x000000
        };
        drawPixel(pixel5);
    }

    {
        PIXEL pixel2 = {
                .X=startX + 6,
                .Y=startY + 16,
                .Color=0x000000
        };
        drawPixel(pixel2);
        PIXEL pixel3 = {
                .X=startX + 6,
                .Y=startY + 17,
                .Color=0x000000
        };
        drawPixel(pixel3);


        PIXEL pixel4 = {
                .X=startX + 9,
                .Y=startY + 16,
                .Color=0x000000
        };
        drawPixel(pixel4);
        PIXEL pixel5 = {
                .X=startX + 9,
                .Y=startY + 17,
                .Color=0x000000
        };
        drawPixel(pixel5);
    }
    PIXEL pixel2 = {
            .X=startX + 7,
            .Y=startY + 18,
            .Color=0x000000
    };
    drawPixel(pixel2);
    PIXEL pixel3 = {
            .X=startX + 8,
            .Y=startY + 18,
            .Color=0x000000
    };
    drawPixel(pixel3);


    PIXEL pixel4 = {
            .X=startX + 7,
            .Y=startY + 13,
            .Color=0x000000
    };
    drawPixel(pixel4);

    //white inside
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i + 1; j++) {
            PIXEL pixel = {
                    .X=startX + 1 + j,
                    .Y=startY + 2 + i,
                    .Color=0xFFFFFF
            };
            drawPixel(pixel);
        }
    }
    BLOCK block1;
    block1.Color = 0xffffff;
    block1.Start.X = startX + 1;
    block1.Start.Y = startY + 12;
    block1.End.X = startX + 6 + 1;
    block1.End.Y = startY + 12 + 1;
    drawBlock(block1);

    BLOCK block2;
    block2.Color = 0xffffff;
    block2.Start.X = startX + 1;
    block2.Start.Y = startY + 13;
    block2.End.X = startX + 3 + 1;
    block2.End.Y = startY + 13 + 1;
    drawBlock(block2);

    BLOCK block3;
    block3.Color = 0xffffff;
    block3.Start.X = startX + 1;
    block3.Start.Y = startY + 14;
    block3.End.X = startX + 2 + 1;
    block3.End.Y = startY + 14 + 1;
    drawBlock(block3);

    PIXEL pixel5 = {
            .X=startX + 1,
            .Y=startY + 15,
            .Color=0xffffff
    };
    drawPixel(pixel5);

    PIXEL pixel6 = {
            .X=startX + 5,
            .Y=startY + 13,
            .Color=0xffffff
    };
    drawPixel(pixel6);
    PIXEL pixel7 = {
            .X=startX + 6,
            .Y=startY + 13,
            .Color=0xffffff
    };
    drawPixel(pixel7);

    BLOCK block4;
    block4.Color = 0xffffff;
    block4.Start.X = startX + 6;
    block4.Start.Y = startY + 14;
    block4.End.X = startX + 7 + 1;
    block4.End.Y = startY + 15 + 1;
    drawBlock(block4);

    BLOCK block5;
    block5.Color = 0xffffff;
    block5.Start.X = startX + 7;
    block5.Start.Y = startY + 16;
    block5.End.X = startX + 8 + 1;
    block5.End.Y = startY + 17 + 1;
    drawBlock(block5);


    return true;
}

UINT32 *getAsciiStart(){
    return AsciiStart;
}