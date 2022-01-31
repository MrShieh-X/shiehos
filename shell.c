#include "shell.h"

BASE Base;
char *Hello;

int initShell(VideoConfig videoConfig)
{
    UINTN width = videoConfig.HorizontalResolution;
    UINTN height = videoConfig.VerticalResolution;
    Base.Setup.Height = height-40;
    Base.Setup.Width = width-40;
    Base.Setup.X = 20;
    Base.Setup.Y = 20;
    Base.Setup.OutLines = 1;

    // Draw  Background
    BLOCK BackGround;
    BackGround.Color = 0xFF000000;
    BackGround.Start.X = 20;
    BackGround.Start.Y = 20;
    BackGround.End.X = width-20;
    BackGround.End.Y = height-20;
    DrawBlock(BackGround);

    if (Base.Setup.OutLines)
    {
        // Draw OutLine Up
        BLOCK OutLine;
        OutLine.Color = 0xFFFFFFFF;
        OutLine.Start.X = 20;
        OutLine.Start.Y = 20;
        OutLine.End.X = width - 20;
        OutLine.End.Y = 22;
        DrawBlock(OutLine);

        // Draw OutLine Middle
        OutLine.Start.X = 22;
        OutLine.Start.Y = 68;
        OutLine.End.X = width-22;
        OutLine.End.Y = 70;/*40*/
        DrawBlock(OutLine);

        // Draw OutLine Down
        OutLine.Start.X = 20;
        OutLine.Start.Y = height - 22;/*45*/
        OutLine.End.X = width - 20;
        OutLine.End.Y = height - 20;
        DrawBlock(OutLine);

        // Draw OutLine Left
        OutLine.Start.X = 20;
        OutLine.Start.Y = 22;
        OutLine.End.X = 22; /*53*/
        OutLine.End.Y = height - 22;
        DrawBlock(OutLine);

        // Draw OutLine right
        OutLine.Start.X = width-22;/*58*/
        OutLine.Start.Y = 22;
        OutLine.End.X = width-20;
        OutLine.End.Y = height-22;
        DrawBlock(OutLine);
    }

    return 0;
}