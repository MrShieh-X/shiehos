#include "string_converter.h"

int length(char* str){
    int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

char *booleanToStr(boolean b,char* str){
    if(b==true){
        //char *c;
        str[0]='t';
        str[1]='r';
        str[2]='u';
        str[3]='e';
        str[4]='\0';
        return str;
    }else {
        str[0]='f';
        str[1]='a';
        str[2]='l';
        str[3]='s';
        str[4]='e';
        str[5]='\0';
        return str;
    }
}

/**
 * @brief 小数转字符串
 *
 * @author MrShiehX
 * @param fra 小数（double、float）
 * @param accuracy 精度，转换到小数点后几位
 * @return char*
 */
char *fractionToStr(double fra, int accuracy)
{
    char*str;
    if(((UINT64)fra)==fra)return intToStr(fra,str);


    int negative=fra<0;
    if(negative)fra=-fra;

    //获得整数的部分，i就是整数
    UINT64 integer=0;
    while(1){
        if((fra-(integer+1))<0){
            break;
        }
        integer++;
    }

    if(accuracy<=0){
        //如果精度<=0，就直接返回整数部分
        return intToStr(negative?(-integer):integer,str);
    }


    //下面开始获得小数部分
    UINT64 multiplier=10;

    for(int i=1;i<accuracy;i++){
        multiplier*=10;
    }
    UINT64 fractionPart=(fra-integer)*multiplier;
    char* fractionPartString;
    intToStr(fractionPart,fractionPartString);


    char*integerString;
    intToStr(negative?(-integer):integer,integerString);

    int lengthInt=length(integerString);
    int lengthFra=length(fractionPartString);

    //下面开始合成，将fractionPartString和.和fractionPartString串联
    char final[lengthInt+1/*.*/+lengthFra+1/*\0*/];
    for(int i=0;i<lengthInt;i++){
        final[i]=integerString[i];
    }
    final[lengthInt]='.';
    for(int i=0;i<lengthFra;i++){
        final[lengthInt+1+i]=fractionPartString[i];
    }
    final[lengthInt+1+lengthFra]='\0';
    return final;
}


/**
 * @brief 整数转字符串(十进制)
 *
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串
 * @return char*
 */
char *intToStr(UINT64 num, char *str){
    intToStrRadix(num,str,10);
    return str;
}

/**
 * @brief 整数转字符串
 * 
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串
 * @param radix 进制数
 * @return char* 
 */
char *intToStrRadix(UINT64 num, char *str, int radix) {
    int x = 0;
    char index[36 + 1];
    index[x++] = '0';
    index[x++] = '1';
    index[x++] = '2';
    index[x++] = '3';
    index[x++] = '4';
    index[x++] = '5';
    index[x++] = '6';
    index[x++] = '7';
    index[x++] = '8';
    index[x++] = '9';
    index[x++] = 'a';
    index[x++] = 'b';
    index[x++] = 'c';
    index[x++] = 'd';
    index[x++] = 'e';
    index[x++] = 'f';
    index[x++] = 'g';
    index[x++] = 'h';
    index[x++] = 'i';
    index[x++] = 'j';
    index[x++] = 'k';
    index[x++] = 'l';
    index[x++] = 'm';
    index[x++] = 'n';
    index[x++] = 'o';
    index[x++] = 'p';
    index[x++] = 'q';
    index[x++] = 'r';
    index[x++] = 's';
    index[x++] = 't';
    index[x++] = 'u';
    index[x++] = 'v';
    index[x++] = 'w';
    index[x++] = 'x';
    index[x++] = 'y';
    index[x++] = 'z';
    index[x] = '\0';
    //"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //索引表

    boolean negative = num < 0;
    if (negative) {
        num = -num;
    }

    unsigned unum;                                         //存放要转换的整数的绝对值,转换的整数可能是负数
    int i = 0, j, k;                                       //i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。

    //获取要转换的整数的绝对值
    if (radix == 10 && num < 0) //要转换成十进制数并且是负数
    {
        unum = (unsigned) -num; //将num的绝对值赋给unum
        str[i++] = '-';        //在字符串最前面设置为'-'号，并且索引加1
    } else
        unum = (unsigned) num; //若是num为正，直接赋值给unum

    //转换部分，注意转换后是逆序的
    do {
        str[i++] = index[unum % (unsigned) radix]; //取unum的最后一位，并设置为str对应位，指示索引加1
        unum /= radix;                            //unum去掉最后一位

    } while (unum); //直至unum为0退出循环

    str[i] = '\0'; //在字符串最后添加'\0'字符，c语言字符串以'\0'结束。

    //将顺序调整过来
    //if (str[0] == '-')
    //    k = 1; //如果是负数，符号不用调整，从符号后面开始调整
    //else
    k = 0; //不是负数，全部都要调整

    char temp;                         //临时变量，交换两个值时用到
    for (j = k; j <= (i - 1) / 2; j++) //头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp = str[j];               //头部赋值给临时变量
        str[j] = str[i - 1 + k - j]; //尾部赋值给头部
        str[i - 1 + k - j] = temp;   //将临时变量的值(其实就是之前的头部值)赋给尾部
    }

    if (!negative) {
        return str; //返回转换后的字符串

    } else {

/*
        char *newa;
        int i2=0;
        newa[0]='-';
        while (1) {
            newa[i2+1]=str[i2];
            if(str[i2]=='\0')break;
            i2++;
        }
        *str = *newa;*/


        char next;
        next=str[0];
        str[0]='-';
        int p=1;
        while(true){
            char temp2=str[p];
            str[p]=next;
            next=temp2;
            if(str[p]=='\0')break;
            p++;
        }

        return str; //返回转换后的字符串
    }
}