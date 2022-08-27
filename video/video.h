#ifndef __VIDEO_VIDEO_H__
#define __VIDEO_VIDEO_H__

#include "../kernel/Uefi.h"
//#include "../shell/printer.h"
//#include "cursor.h"

#pragma pack(1)

typedef struct {
    UINT32 X;
    UINT32 Y;
} POINT;

typedef struct {
    UINT32 X;
    UINT32 Y;
    UINT32 Color;
} PIXEL;

typedef struct {
    POINT Start;
    POINT End;
    UINT32 Color;
} BLOCK;

#pragma pack()

#define LETTER_HEIGHT 36
#define LETTER_WIDTH 20
#define PIC_HEIGHT 108
#define PIC_WIDTH 640

#define CURSOR_WIDTH 12
#define CURSOR_HEIGHT 19
typedef UINT32 character;


extern POINT cursorNow;
extern long backups/*[125]*/[CURSOR_HEIGHT][CURSOR_WIDTH];
extern boolean cursorSet;

/*typedef struct
{
    UINTN x;
    UINTN y;
}Position;
*/
POINT getPosition(character c);

int initVideo(BootConfig *BootConfig);

int drawPixel(PIXEL Pixel);

UINT32 getPixelByXY(UINT32 x, UINT32 y);

UINT32 getPixel(POINT Pixel);

int drawBlock(BLOCK Block);

//int drawLetter(UINT8 c, POINT dest);
int drawLetter(character c, POINT dest);

boolean drawMousePointer(POINT point);

UINT32 *getAsciiStart();

#endif