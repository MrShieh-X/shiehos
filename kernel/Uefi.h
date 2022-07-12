#ifndef __KERNEL_UEFI_H__
#define __KERNEL_UEFI_H__

typedef void VOID;
typedef unsigned char UINT8;
typedef UINT8 CHAR8;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;//MAX: 18,446,744,073,709,551,615;18446744073709551615
typedef long long SUINT64;//MAX: 9,223,372,036,854,775,807;9223372036854775807

typedef UINT64 UINTN;
typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

#define NULL ((VOID *) 0)

typedef int boolean;
#define true 1
#define false 0

typedef char *String;

typedef enum {
    /// Not used.
    EfiReservedMemoryType,
    /// The code portions of a loaded application.
    /// (Note that UEFI OS loaders are UEFI applications.)
    EfiLoaderCode,
    /// The data portions of a loaded application and the default data allocation
    /// type used by an application to allocate pool memory.
    EfiLoaderData,
    /// The code portions of a loaded Boot Services Driver.
    EfiBootServicesCode,
    /// The data portions of a loaded Boot Serves Driver, and the default data
    /// allocation type used by a Boot Services Driver to allocate pool memory.
    EfiBootServicesData,
    /// The code portions of a loaded Runtime Services Driver.
    EfiRuntimeServicesCode,
    /// The data portions of a loaded Runtime Services Driver and the default
    /// data allocation type used by a Runtime Services Driver to allocate pool memory.
    EfiRuntimeServicesData,
    /// Free (unallocated) memory.
    EfiConventionalMemory,
    /// Memory in which errors have been detected.
    EfiUnusableMemory,
    /// Memory that holds the ACPI tables.
    EfiACPIReclaimMemory,
    /// Address space reserved for use by the firmware.
    EfiACPIMemoryNVS,
    /// Used by system firmware to request that a memory-mapped IO region
    /// be mapped by the OS to a virtual address so it can be accessed by EFI runtime services.
    EfiMemoryMappedIO,
    /// System memory-mapped IO region that is used to translate memory
    /// cycles to IO cycles by the processor.
    EfiMemoryMappedIOPortSpace,
    /// Address space reserved by the firmware for code that is part of the processor.
    EfiPalCode,
    /// A memory region that operates as EfiConventionalMemory,
    /// however it happens to also support byte-addressable non-volatility.
    EfiPersistentMemory,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

#pragma pack(1)
typedef struct {
    UINT64 BufferSize;
    VOID *Buffer;
    UINT64 MapSize;
    UINT64 MapKey;
    UINT64 DescriptorSize;
    UINT32 DescriptorVersion;
} MEMORY_MAP;


typedef struct {
    UINT32 Type;
    UINT32 ReservedA;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
    UINT64 ReservedB;
} EFI_MEMORY_DESCRIPTOR;

typedef struct {
    UINTN Size;
    UINTN PageSize;
    UINTN Width;
    UINTN Height;
    UINTN Offset;
    UINT64 PixelStart;
} BMPConfig;

typedef struct {
    EFI_PHYSICAL_ADDRESS FrameBufferBase;
    UINT64 FrameBufferSize;
    UINT32 HorizontalResolution;
    UINT32 VerticalResolution;
    UINT32 PixelsPerScanLine;
} VideoConfig;

typedef struct {
    VideoConfig videoConfig;
    BMPConfig *AsciiBmp;
    MEMORY_MAP memoryMap;
} BootConfig;

#pragma pack()


#endif