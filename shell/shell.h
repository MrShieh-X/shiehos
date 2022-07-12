#ifndef __SHELL_SHELL_H__
#define __SHELL_SHELL_H__

#include "../kernel/Uefi.h"
#include "../video/video.h"

#pragma pack(1)

typedef struct
{
    UINT32 Width;
    UINT32 Height;
    UINT32 X;
    UINT32 Y;
    UINT32 OutLines;
} SETUP;

typedef struct
{
    SETUP Setup;
} BASE;
#pragma pack()

int initShell(VideoConfig videoConfig);

int drawTitle(UINT32 width, UINT32 height);

#endif