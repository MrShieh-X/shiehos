#ifndef __ASMS_ASMFUNCS_H__
#define __ASMS_ASMFUNCS_H__

void hlt(void);

void cli(void);//关中断

void sti(void);//开中断

void nop(void);

/*int io_load_eflags(void);

void io_store_eflags(int eflags);

void load_gdtr(int limit, int addr);

void load_idtr(int limit, int addr);

int io_in8(int port);

int io_in16(int port);

int io_in32(int port);

void io_out8(int port, int data);

void io_out16(int port, int data);

void io_out32(int port, int data);*/


#endif