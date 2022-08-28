#include "shell.h"

BASE Base;

int initShell(VideoConfig videoConfig) {
    UINTN width = videoConfig.HorizontalResolution;
    UINTN height = videoConfig.VerticalResolution;
    Base.Setup.Height = height - 40;
    Base.Setup.Width = width - 40;
    Base.Setup.X = 20;
    Base.Setup.Y = 20;
    Base.Setup.OutLines = 1;

    // Draw  Background
    BLOCK BackGround;
    BackGround.Color = 0xFF000000;
    BackGround.Start.X = 20;
    BackGround.Start.Y = 20;
    BackGround.End.X = width - 20;
    BackGround.End.Y = height - 20;
    //drawBlock(BackGround);

    if (Base.Setup.OutLines) {
        // Draw OutLine Up
        BLOCK OutLine;
        OutLine.Color = 0xFFFFFFFF;
        OutLine.Start.X = 20;
        OutLine.Start.Y = 20;
        OutLine.End.X = width - 20;
        OutLine.End.Y = 22;/*33*/
        drawBlock(OutLine);

        // Draw OutLine Middle
        OutLine.Start.X = 22;
        OutLine.Start.Y = 68;/*38*/
        OutLine.End.X = width - 22;
        OutLine.End.Y = 70;/*40*/
        drawBlock(OutLine);

        // Draw OutLine Down
        OutLine.Start.X = 20;
        OutLine.Start.Y = height - 22;/*45*/
        OutLine.End.X = width - 20;
        OutLine.End.Y = height - 20;
        drawBlock(OutLine);

        // Draw OutLine Left
        OutLine.Start.X = 20;
        OutLine.Start.Y = 22;
        OutLine.End.X = 22; /*53*/
        OutLine.End.Y = height - 22;
        drawBlock(OutLine);

        // Draw OutLine right
        OutLine.Start.X = width - 22;/*58*/
        OutLine.Start.Y = 22;
        OutLine.End.X = width - 20;
        OutLine.End.Y = height - 22;
        drawBlock(OutLine);
    }

    drawTitle(width, height);

    return 0;
}

int drawTitle(UINT32 width, UINT32 height) {
    UINT32 titleLength = 7;
    UINT32 titleStringLength = titleLength/*+1*/;
    char title[titleStringLength];
    title[0] = 'S';
    title[1] = 'h';
    title[2] = 'i';
    title[3] = 'e';
    title[4] = 'h';
    title[5] = 'O';
    title[6] = 'S';
    //title[7]='\0';
    UINT32 titleHeight = LETTER_HEIGHT;
    UINT32 titleWidth = titleLength * LETTER_WIDTH;
    UINT32 x = (width - titleWidth) >> 1;


    int titleAreaHeight = 68/*38**/- 22/*33**/;
    int halfRest = (titleAreaHeight - titleHeight) >> 1;
    UINT32 y = 22/*33**/+ halfRest;

    for (int i = 0; i < titleLength; i++) {
        char c = title[i];
        POINT p;
        p.X = x + LETTER_WIDTH * i;
        p.Y = y;
        drawLetter(c, p,0xffffff,false,0);
    }
    return 0;
}