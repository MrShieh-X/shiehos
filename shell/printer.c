#include "printer.h"

UINT32 curLine;
UINT32 curColumn;
UINT32 charCount;

//以下需初始化
UINT32 maxLines;
UINT32 maxColumns;
UINT32 maxCount;
UINT32 startX;
UINT32 startY;
UINT32 xDistance;
UINT32 yDistance;

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
int printfx(char *str, UINT64 formatObjectsAddresses[], UINT32 addressesSize) {
    int number = 0;
    int success = 0;
    int formatNumber = 0;
    while (str[number] != '\0' && addressesSize >= 0) {
        char c = str[number++];
        if (c == '%' && formatNumber < addressesSize) {
            int *address = (int *) (formatObjectsAddresses[formatNumber]);
            char next = str[number];
            if (next == 'd') {
                SUINT64 value = ((SUINT64) (*address));
                char integer[intToStrLength(value, 10)];
                intToStr(value, integer);
                printString(integer);

                success++;
                formatNumber++;
                number++;
            } else if (next == 's') {
                char *value = ((char *) (address));
                printString(value);
                success++;
                formatNumber++;
                number++;
            } else if (next == 'f') {
                int accuracy = 6;
                double value = *((double *) (address));
                printFraction(value, accuracy);
                success++;
                formatNumber++;
                number++;
            }/*else if (next=='0'
                      ||next=='1'
                        ||next=='2'
                          ||next=='3'
                            ||next=='4'
                              ||next=='5'
                                ||next=='6'
                                  ||next=='7'
                                    ||next=='8'
                                      ||next=='9') {
                if(str[number+1]=='f'){

                }

            }*/else {
                print(c);
            }
        } else {
            print(c);
        }
    }
    return success;
}

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
int printfln(char *str, UINT64 formatObjectsAddresses[], UINT32 addressesSize) {
    int p = printfx(str, formatObjectsAddresses, addressesSize);
    newLine();
    return p;
}


/**
 * 打印小数（十进制）并换行
 *
 * @return 打印成功的字符数
 **/
int printlnFraction(double fra, int accuracy) {
    char c[(fra < 0 ? 22 : 21) + accuracy];
    fractionToStr(fra, accuracy, c);
    return printlnString(c);
}

/**
 * 打印小数（十进制）
 *
 * @return 打印成功的字符数
 **/
int printFraction(double fra, int accuracy) {
    char c[(fra < 0 ? 22 : 21) + accuracy];
    fractionToStr(fra, accuracy, c);
    return printString(c);
}


/**
 * 打印十六进制整数（带有“0x”）并换行
 *
 * @return 打印成功的字符数
 **/
int printlnHex(SUINT64 i) {
    int success = 0;
    if (i < 0) {
        if (print('-'))success++;
    }
    if (print('0')) {
        success++;
    }
    if (print('x')) {
        success++;
    }
    char c[2/*0x*/+ intToStrLength(i, 16)];
    intToStrRadix((i < 0) ? (-i) : (i), c, 16);
    success += printlnString(c);
    return success;
}

/**
 * 打印十六进制整数（带有“0x”）
 *
 * @return 打印成功的字符数
 **/
int printHex(SUINT64 i) {
    int success = 0;
    if (i < 0) {
        if (print('-'))success++;
    }
    if (print('0')) {
        success++;
    }
    if (print('x')) {
        success++;
    }
    char c[2/*0x*/+ intToStrLength(i, 16)];
    intToStrRadix((i < 0) ? (-i) : (i), c, 16);
    success += printString(c);
    return success;
}

/**
 * 打印 boolean
 *
 * @return 打印成功的字符数
 **/
int printBoolean(boolean i) {
    char c[6];
    booleanToStr(i, c);
    return printString(c);
}

/**
 * 打印 boolean 并换行
 *
 * @return 打印成功的字符数
 **/
int printlnBoolean(boolean i) {
    char c[6];
    booleanToStr(i, c);
    return printlnString(c);
}


/**
 * 打印整数并换行（十进制）
 *
 * @return 打印成功的字符数
 **/
int printlnInt(SUINT64 i) {
    char c[intToStrLength(i, 10)];
    intToStr(i, c);
    return printlnString(c);
}

/**
 * 打印整数（十进制）
 *
 * @return 打印成功的字符数
 **/
int printInt(SUINT64 i) {
    char c[intToStrLength(i, 10)];
    intToStr(i, c);
    return printString(c);
}

/**
 * 打印整数并换行
 *
 * @return 打印成功的字符数
 **/
int printlnIntRadix(SUINT64 i, int radix) {
    char c[intToStrLength(i, radix)];
    intToStrRadix(i, c, radix);
    return printlnString(c);
}

/**
 * 打印整数
 *
 * @return 打印成功的字符数
 **/
int printIntRadix(SUINT64 i, int radix) {
    char c[intToStrLength(i, radix)];
    intToStrRadix(i, c, radix);
    return printString(c);
}

/**
 * @return 打印成功的字符数
 **/
int printlnString(char *str) {
    int successed = printString(str);
    if (newLine()) {
        successed++;
    }
    return successed;
}

/**
 * @return 打印成功的字符数
 **/
int printString(char *str) {
    char *b = str;
    //UINT32 len = length(b);
    UINT32 successed = 0;
    for (UINT32 i = 0;/*i<len*/b[i] != '\0'; i++) {
        if (print(b[i])) {
            successed++;
        }
    }
    return successed;
}

POINT nextPosition() {
    //1.如果curColumn+1>=maxColumns，就换行，且curColumn+1；
    //2.如果curLine+1>=maxLines，返回一个X和Y皆为-1的POINT
    // 最后charCount+1
    POINT point;
    if (curColumn + 1 >= maxColumns) {
        if (curLine + 1 >= maxLines) {
            point.X = -1;
            point.Y = -1;
        } else {
            //换行
            curColumn = 0;
            curLine++;
            point.X = startX;
            point.Y = startY + curLine * LETTER_HEIGHT;
            charCount++;
        }
    } else {
        curColumn++;
        charCount++;
        point.X = startX + curColumn * LETTER_WIDTH;
        point.Y = startY + curLine * LETTER_HEIGHT;
    }
    return point;
}

boolean newLine() {
    return print('\n');
}

boolean print(character c) {
    if (c == '\n' || c == '\r') {
        if (curLine + 1 < maxLines) {
            curLine++;
            curColumn = -1;
            return true;
        } else return false;
    } else {
        POINT point;
        point = nextPosition();
        if (point.X == -1 || point.Y == -1) {
            return false;
        }
        drawLetter(c, point);
        return true;
    }
}

int initPrinter(BootConfig *bootConfig) {
    //以下需初始化
    //UINT32 maxLines;
    //UINT32 maxColumns;
    //UINT32 startX;
    //UINT32 startY;
    //UINT32 xDistance;
    //UINT32 yDistance;


    UINT32 width = bootConfig->videoConfig.HorizontalResolution;
    UINT32 height = bootConfig->videoConfig.VerticalResolution;

    {
        //StartY,maxLines,yDistance
        /*04=middle之后在70（code:40 in shell.c) 化简：70

        down之前在height - 22(code:45 in shell.c)-1 化简：height-23

        2减1=height-22-      04 =height-92    ==808

        01=2减1/36(letter height)==22.XXXX（maxLines）

        02=2减1%36(letter height)==16

        03=02/2=8（与middle、down的距离）

        StartY=04+03=70+(03)==78;*/

        int a04 = 70/*40**/;
        int b = height - 22 /*45**/;
        int bSa04 = b - a04;
        maxLines = bSa04 / LETTER_HEIGHT;
        yDistance = (bSa04 % LETTER_HEIGHT) / 2; //（与middle、down的距离）
        startY = a04 + yDistance;
    }

    {
        //StartX,maxColumns,xDistance
        /*01=C58-C53==1396

            02=(01)/20==69.8(maxColumns)

            03=(01)%20==16（与left、right的距离和）

            04=（03）/2==8（与left、right的距离）*/
        int a01 = (width - 22) /*C58**/ - 22 /*C58**/;
        maxColumns = a01 / LETTER_WIDTH;
        xDistance = (a01 % 20) / 2;
        startX = 22 /*C58**/ + xDistance;
    }

    maxCount = maxLines * maxColumns;
    curLine = 0;
    curColumn = -1;
    charCount = 0;
    return 0;
}
