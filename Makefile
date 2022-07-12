MAKE                 = make -r
OUTPUT_DIRECTORY     = build
OUTPUT_ELF           = $(OUTPUT_DIRECTORY)/kernel.elf
KERNEL_ENTRY_POINT   = kernelStart

default :
	$(MAKE) kernel.elf

kernel.elf : Makefile \
kernel/kernel.c \
kernel/kernel.h \
kernel/Uefi.h \
memory/xmemory.c \
memory/xmemory.h \
shell/printer.c \
shell/printer.h \
shell/shell.c \
shell/shell.h \
utils/string_converter.c \
utils/string_converter.h \
utils/xmath.c \
utils/xmath.h \
video/video.c \
video/video.h \
$(OUTPUT_DIRECTORY)/asms/asmfuncs.o
	-mkdir $(OUTPUT_DIRECTORY)
	clang kernel/kernel.c \
          memory/xmemory.c \
          shell/printer.c \
          shell/shell.c \
          utils/string_converter.c \
          utils/xmath.c \
          video/video.c \
          $(OUTPUT_DIRECTORY)/asms/asmfuncs.o \
          -nostdlib -e $(KERNEL_ENTRY_POINT) -o $(OUTPUT_ELF)

$(OUTPUT_DIRECTORY)/asms/asmfuncs.o: asms/asmfuncs.asm Makefile
	$(MAKE) asm

asm: asms/asmfuncs.asm Makefile
	-mkdir $(OUTPUT_DIRECTORY)
	-mkdir $(OUTPUT_DIRECTORY)/asms
	nasm -f elf64 asms/asmfuncs.asm -o $(OUTPUT_DIRECTORY)/asms/asmfuncs.o

kernel :
	$(MAKE) kernel.elf