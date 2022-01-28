#include "UefiBaseType.h"
#include "video.h"

typedef struct
{
    EFI_PHYSICAL_ADDRESS FrameBufferBase;
    UINTN FrameBufferSize;
    UINT32 HorizontalResolution;
    UINT32 VerticalResolution;
    UINT32 PixelsPerScanLine;
} VideoConfig;

typedef struct
{
    EFI_PHYSICAL_ADDRESS FrameBufferBase;
    UINT64 FrameBufferSize;
    UINT64 HorizontalResolution;
    UINT64 VerticalResolution;
    VideoConfig *videoConfig;
} BootConfig;

int DrawPixel(UINT32 *VideoHandle, UINT32 Color, int X, int Y, UINT64 horizontal);

UINT64 _start(BootConfig *bootConfig);