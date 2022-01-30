#include "Uefi.h"

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

/*typedef struct
{
    UINTN x;
    UINTN y;
}Position;
*/
POINT getPosition(char c);

int initVideo(BootConfig *BootConfig);
int DrawPixel(PIXEL Pixel);
int DrawBlock(BLOCK Block);
//int DrawLetter(UINT8 c, POINT dest);
int DrawLetter(char c, POINT dest);