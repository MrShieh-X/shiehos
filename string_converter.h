#include "xmath.h"

int length(char *str);

/**
 * @brief 小数转字符串
 *
 * @author MrShiehX
 * @param fra 小数（double、float）
 * @param accuracy 精度，转换到小数点后几位
 * @return char*
 */
void fractionToStr(double fra, int accuracy, char*str);

char *booleanToStr(boolean b,char* str);

/**
 * @brief 整数转字符串(十进制)
 *
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串
 * @return 长度（没有\0）
 */
UINT32 intToStr(SUINT64 num, char *str);

/**
 * @brief 整数转字符串
 *
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串
 * @param radix 进制数
 * @return 长度（没有\0）
 */
UINT32 intToStrRadix(SUINT64 num, char *str, int radix);

void init();