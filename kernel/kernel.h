#ifndef __KERNEL_KERNEL_H__
#define __KERNEL_KERNEL_H__

#include "../video/video.h"
#include "../shell/printer.h"
#include "../shell/shell.h"
#include "../memory/xmemory.h"

//int drawPixel(UINT32 *VideoHandle, UINT32 Color, int X, int Y, UINT64 horizontal);

_Noreturn UINT64 kernelStart(BootConfig *bootConfig);

#endif