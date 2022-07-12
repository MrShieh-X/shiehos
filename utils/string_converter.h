#ifndef __UTILS_STRING_CONVERTER_H__
#define __UTILS_STRING_CONVERTER_H__

#include "xmath.h"

int length(char *str);

SUINT64 getIntegerPart(double fra);

char *booleanToStr(boolean b, char *str);

void initStringConverter();

/**
 * @brief 整数转字符串时计算长度
 *
 * @author MrShiehX
 * @param num 整数
 * @param radix 进制数
 * @return 字符串长度（已包含负号（如果有）、该进制的最大数值的长度、“\0”）
 */
UINT32 intToStrLength(SUINT64 num, int radix);

/**
 * @brief 小数转字符串（十进制）有问题
 *
 * @author MrShiehX
 * @param fra 小数（double、float）
 * @param accuracy 精度，转换到小数点后几位
 * @param str 长度：1(-，如果能确保不是负数可以省略)
 *                 +19(maxOfLongLong(十进制))
 *                 +1(.)
 *                 +accuracy
 *                 +1(\0)
 *                 ==22（正数21）+accuracy
 * @problem 转换小数部分以及精度不为0的小数时有问题
 */
void fractionToStr(double fra, int accuracy, char *str);


/**
 * @brief 整数转字符串(十进制)
 *
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串 长度：UINT32 intToStrLength(SUINT64 num, int radix)
 * @return 长度（没有\0）
 */
UINT32 intToStr(SUINT64 num, char *str);

/**
 * @brief 整数转字符串
 *
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串 长度：UINT32 intToStrLength(SUINT64 num, int radix)
 * @param radix 进制数
 * @return 长度（没有\0）
 */
UINT32 intToStrRadix(SUINT64 num, char *str, int radix);

#endif