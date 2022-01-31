#include "video.h"

int initPrinter(BootConfig *bootConfig);
POINT nextPosition();

/**
 * @return 是否换行成功
 **/
boolean newLine();

/**
 * @return 是否打印成功
 **/
boolean print(character c);

/**
 * @return 打印成功的次数
 **/
int printString(char *c);

/**
 * @return 打印成功的次数
 **/
int printlnString(char *c);