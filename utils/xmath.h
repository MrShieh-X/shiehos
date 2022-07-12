#ifndef __UTILS_XMATH_H__
#define __UTILS_XMATH_H__

#include "../kernel/Uefi.h"

/**
 * 获得绝对值（分数）
 **/
double xabsFra(double value);


/**
 * 获得绝对值
 **/
SUINT64 xabs(SUINT64 value);

/**
 * 获得整数幂
 **/
double xpowFra(double x, UINT64 y);

/**
 * 获得整数幂
 **/
SUINT64 xpow(SUINT64 x, UINT64 y);

#endif