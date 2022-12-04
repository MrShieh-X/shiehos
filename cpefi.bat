mkdir G:\system\kernel
mkdir G:\EFI\BOOT
copy "D:\AdministratorDocuments\Virtual Machines\Ubuntu21.04\share\edk2\ShiehOS\build\kernel.elf" G:\system\kernel /Y
copy "D:\AdministratorDocuments\Virtual Machines\Ubuntu21.04\share\edk2\XBLPkg\Build\DEBUG_GCC5\X64\XBL.efi" G:\EFI\BOOT /Y
del G:\EFI\BOOT\bootx64.efi
rename G:\EFI\BOOT\XBL.efi bootx64.efi
copy "D:\AdministratorDocuments\Virtual Machines\Ubuntu21.04\share\edk2\XBLPkg\Build\DEBUG_GCC5\X64\XBL.efi" G:\EFI\BOOT /Y
del G:\EFI\BOOT\shieh.efi
rename G:\EFI\BOOT\XBL.efi shieh.efi