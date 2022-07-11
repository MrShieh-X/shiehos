MAKE                 = make -r
OUTPUT_ELF_DIRECTORY = build
OUTPUT_ELF           = build/kernel.elf
KERNEL_ENTRY_POINT   = kernelStart

default :
	$(MAKE) kernel.elf

kernel.elf : kernel/kernel.c \
kernel/kernel.h \
kernel/Uefi.h \
memory/xmemory.c \
memory/xmemory.h \
shell/letter.c \
shell/letter.h \
shell/printer.c \
shell/printer.h \
shell/shell.c \
shell/shell.h \
utils/string_converter.c \
utils/string_converter.h \
utils/xmath.c \
utils/xmath.h \
video/video.c \
video/video.h
	-mkdir $(OUTPUT_ELF_DIRECTORY)
	clang kernel/kernel.c \
          memory/xmemory.c \
          shell/letter.c \
          shell/printer.c \
          shell/shell.c \
          utils/string_converter.c \
          utils/xmath.c \
          video/video.c \
          -nostdlib -e $(KERNEL_ENTRY_POINT) -o $(OUTPUT_ELF)

kernel :
	$(MAKE) kernel.elf