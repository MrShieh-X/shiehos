#include "xmath.h"

/**
 * 获得绝对值（分数）
 **/
double xabsFra(double value){
    if(value<0){
        return -value;
    }
    return value;
}


/**
 * 获得绝对值
 **/
SUINT64 xabs(SUINT64 value){
    if(value<0){
        return -value;
    }
    return value;
}

/**
 * 获得整数幂
 **/
double xpowFra(double x, UINT64 y){
    if(y==0)return 1;
    double xs=x;
    for(int i=1;i<y;i++){
        x*=xs;
    }
    return x;
}

/**
 * 获得整数幂
 **/
SUINT64 xpow(SUINT64 x, UINT64 y){
    if(y==0)return 1;
    SUINT64 xs=x;
    for(int i=1;i<y;i++){
        x*=xs;
    }
    return x;
}