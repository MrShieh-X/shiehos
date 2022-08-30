MAKE                 = make -r
OUTPUT_DIRECTORY     = build
OUTPUT_ELF           = $(OUTPUT_DIRECTORY)/kernel.elf
KERNEL_ENTRY_POINT   = kernelStart
OS_VERSION           = 1

default :
	$(MAKE) kernel.elf

kernel.elf : Makefile \
kernel/kernel.c \
memory/xmemory.c \
shell/printer.c \
shell/shell.c \
utils/string_converter.c \
utils/xmath.c \
utils/color.c \
utils/memory_utils.c \
video/video.c \
video/cursor.c \
kernel/Uefi.h \
kernel/kernel.h \
memory/xmemory.h \
shell/printer.h \
shell/shell.h \
utils/string_converter.h \
utils/xmath.h \
utils/color.h \
utils/memory_utils.h \
video/video.h \
video/cursor.h \
$(OUTPUT_DIRECTORY)/asms/asmfuncs.o
	-mkdir $(OUTPUT_DIRECTORY)
	clang kernel/kernel.c \
          memory/xmemory.c \
          shell/printer.c \
          shell/shell.c \
          utils/string_converter.c \
          utils/color.c \
          utils/xmath.c \
          utils/memory_utils.c \
          video/video.c \
          video/cursor.c \
          $(OUTPUT_DIRECTORY)/asms/asmfuncs.o \
          -nostdlib -e $(KERNEL_ENTRY_POINT) -o $(OUTPUT_ELF)
	java project_tools.SignWriter $(OUTPUT_ELF) $(OS_VERSION)

$(OUTPUT_DIRECTORY)/asms/asmfuncs.o: asms/asmfuncs.asm Makefile
	-mkdir $(OUTPUT_DIRECTORY)
	-mkdir $(OUTPUT_DIRECTORY)/asms
	nasm -f elf64 asms/asmfuncs.asm -o $(OUTPUT_DIRECTORY)/asms/asmfuncs.o

asm: asms/asmfuncs.asm Makefile
	$(MAKE) $(OUTPUT_DIRECTORY)/asms/asmfuncs.o

kernel :
	$(MAKE) kernel.elf

clean:
	-rm -rf $(OUTPUT_DIRECTORY)