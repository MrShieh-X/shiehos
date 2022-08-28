#ifndef __UTILS_MEMORY_UTILS_H__
#define __UTILS_MEMORY_UTILS_H__

#include "../kernel/Uefi.h"

UINTN getValue(
        EFI_PHYSICAL_ADDRESS StartAddress,
        UINTN Offset,
        UINTN Size);

#endif