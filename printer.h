#include "video.h"

int initPrinter(BootConfig *bootConfig);
POINT nextPosition();

/**
 * 打印小数并换行
 *
 * @return 打印成功的字符数
 **/
int printlnFraction(double fra, int accuracy);
/**
 * 打印小数
 *
 * @return 打印成功的字符数
 **/
int printFraction(double fra, int accuracy);
/**
 * 打印十六进制整数（带有“0x”）并换行
 *
 * @return 打印成功的字符数
 **/
int printlnHex(UINT64 i);
/**
 * 打印十六进制整数（带有“0x”）
 *
 * @return 打印成功的字符数
 **/
int printHex(UINT64 i);

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
int printlnInt(UINT64 i);

/**
 * 打印整数（十进制）
 *
 * @return 打印成功的字符数
 **/
int printInt(UINT64 i);
/**
 * 打印整数并换行
 *
 * @return 打印成功的字符数
 **/
int printlnIntRadix(UINT64 i,int radix);

/**
 * 打印整数
 *
 * @return 打印成功的字符数
 **/
int printIntRadix(UINT64 i,int radix);

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