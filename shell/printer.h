#ifndef __SHELL_PRINTER_H__
#define __SHELL_PRINTER_H__

#include "../video/video.h"
#include "../utils/string_converter.h"

int initPrinter(BootConfig *bootConfig);

POINT nextPosition();



/*int PrintHex(UINT64 Number);
int PrintDec(UINT64 Number);*/

/**
 * 格式化打印
 * %d 整数
 * %s 字符串
 * %f 小数（默认精度6位）
 * //%<x>f(<x>：精度) 打印指定精度的小数
 *
 * @author MrShiehX
 * @return 格式化成功的次数
 **/
int printfx(char *str, UINT64 formatObjectsAddresses[], UINT32 addressesSize);

/**
 * 格式化打印并换行
 * %d 整数
 * %s 字符串
 * %f 小数（默认精度6位）
 * //%<x>f(<x>：精度) 打印指定精度的小数
 *
 * @author MrShiehX
 * @return 格式化成功的次数
 **/
int printfln(char *str, UINT64 formatObjectsAddresses[], UINT32 addressesSize);

/**
 * 打印小数（十进制）并换行
 *
 * @return 打印成功的字符数
 **/
int printlnFraction(double fra, int accuracy);

/**
 * 打印小数（十进制）
 *
 * @return 打印成功的字符数
 **/
int printFraction(double fra, int accuracy);

/**
 * 打印十六进制整数（带有“0x”）并换行
 *
 * @return 打印成功的字符数
 **/
int printlnHex(SUINT64 i);

/**
 * 打印十六进制整数（带有“0x”）
 *
 * @return 打印成功的字符数
 **/
int printHex(SUINT64 i);

/**
 * 打印 boolean
 *
 * @return 打印成功的字符数
 **/
int printBoolean(boolean i);

/**
 * 打印 boolean 并换行
 *
 * @return 打印成功的字符数
 **/
int printlnBoolean(boolean i);

/**
 * 打印整数并换行（十进制）
 *
 * @return 打印成功的字符数
 **/
int printlnInt(SUINT64 i);

/**
 * 打印整数（十进制）
 *
 * @return 打印成功的字符数
 **/
int printInt(SUINT64 i);

/**
 * 打印整数并换行
 *
 * @return 打印成功的字符数
 **/
int printlnIntRadix(SUINT64 i, int radix);

/**
 * 打印整数
 *
 * @return 打印成功的字符数
 **/
int printIntRadix(SUINT64 i, int radix);

/**
 * @return 是否换行成功
 **/
boolean newLine();

/**
 * @return 是否打印成功
 **/
boolean print(character c);

/**
 * @return 打印成功的字符数
 **/
int printString(char *c);

/**
 * @return 打印成功的字符数
 **/
int printlnString(char *c);

#endif