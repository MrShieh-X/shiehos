typedef void VOID;
typedef unsigned char UINT8;
typedef UINT8 CHAR8;
typedef unsigned int  UINT32;
typedef unsigned long long  UINT64;
typedef UINT64 UINTN;
typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef int boolean;
#define true 1
#define false 2

typedef char *String;

#pragma pack(1)
typedef struct
{
  UINTN Size;
  UINTN PageSize;
  UINTN Width;
  UINTN Height;
  UINTN Offset;
  UINT64 PixelStart;
} BMPConfig;

typedef struct
{
  EFI_PHYSICAL_ADDRESS FrameBufferBase;
  UINT64 FrameBufferSize;
  UINT32 HorizontalResolution;
  UINT32 VerticalResolution;
  UINT32 PixelsPerScanLine;
} VideoConfig;

typedef struct
{
  UINT64 AsciiPixelStart;
  VideoConfig videoConfig;
  BMPConfig *AsciiBmp;
} BootConfig;

#pragma pack()