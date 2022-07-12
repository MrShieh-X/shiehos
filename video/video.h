#ifndef __VIDEO_VIDEO_H__
#define __VIDEO_VIDEO_H__

#include "../kernel/Uefi.h"

#pragma pack(1)

typedef struct
{
    UINT32 X;
    UINT32 Y;
} POINT;

typedef struct
{
    UINT32 X;
    UINT32 Y;
    UINT32 Color;
} PIXEL;

typedef struct
{
    POINT Start;
    POINT End;
    UINT32 Color;
} BLOCK;

#pragma pack()

#define LETTER_HEIGHT 36
#define LETTER_WIDTH 20
#define PIC_HEIGHT 108
#define PIC_WIDTH 640
typedef UINT32 character;

/*typedef struct
{
    UINTN x;
    UINTN y;
}Position;
*/
POINT getPosition(character c);

int initVideo(BootConfig *BootConfig);
int drawPixel(PIXEL Pixel);
int drawBlock(BLOCK Block);
//int drawLetter(UINT8 c, POINT dest);
int drawLetter(character c, POINT dest);

#endif