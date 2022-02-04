#include "string_converter.h"

//#define UPPER//整数转字符串中的字母是否大写

boolean inited=false;
char indexx[36 + 1];
int baseCounts[15];

int length(char* str){
    int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

/**
 * @param str 长度：6。
 **/
char *booleanToStr(boolean b,char* str){
    if(b==0){
        str[0]='f';
        str[1]='a';
        str[2]='l';
        str[3]='s';
        str[4]='e';
        str[5]='\0';
        return str;
    }else {
        //char *c;
        str[0]='t';
        str[1]='r';
        str[2]='u';
        str[3]='e';
        str[4]='\0';
        return str;
    }
}

SUINT64 getIntegerPart(double fra){
    if(fra<0.0){
        UINT64 integer=0;
        while(1){
            if((fra+(integer+1))>0){
                break;
            }
            integer++;
        }
        return -integer;
    }else if(fra>0.0){
        UINT64 integer=0;
        while(1){
            if((fra-(integer+1))<0){
                break;
            }
            integer++;
        }
        return integer;
    }else{
        return 0;
    }
}

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
void fractionToStr(double fra, int accuracy, char*str)
{
    if(((SUINT64)fra)==fra){
        intToStr(((SUINT64)fra),str);
        int number=0;
        while(1){
            if(str[number++]=='\0'){
                str[number-1]='.';
                str[number]='0';
                int base;
                if(accuracy>1){
                    base=accuracy;
                    for(int i=1;i<accuracy;i++){
                        str[number+i]='0';
                    }
                }else{
                    base=1;
                }
                str[number+base]='\0';
                break;
            }
        }
        return;
        //return str;
    }


    int negative=fra<0;
    if(negative)fra=-fra;

    //获得整数的部分，i就是整数
    SUINT64 integer=/*0*/getIntegerPart(fra);
    /*while(1){
        if((fra-(integer+1))<0){
            break;
        }
        integer++;
    }*/

    if(accuracy<=0){
        //print('A');
        //如果精度<=0，就直接返回整数部分
        intToStr(negative?(-integer):integer,str);
        int number=0;
        while(1){
            if(str[number++]=='\0'){
                str[number-1]='.';
                str[number]='0';
                str[number+1]='\0';
                break;
            }
        }
        return;
        //return str;
    }


    //下面开始获得小数部分
    double multiplier=xpowFra(10.0,accuracy);
    /**Problem Start 可能是精度问题*/
    SUINT64 fractionPart=(getIntegerPart(/**problem 减法有问题*/(fra-(double)integer)*multiplier/**problem*/));
    /**Problem End*/


    char fractionPartString[accuracy+1];
    char integerString[20+1];

    int lengthInt=intToStr(negative?(-integer):integer,integerString);
    int lengthFra=intToStr(fractionPart,fractionPartString);



    //下面开始合成，将fractionPartString和.和fractionPartString串联
    //char final[lengthInt+1/*.*/+lengthFra+1/*\0*/];
    for(int i=0;i<lengthInt;i++){
        str[i]=integerString[i];
    }
    str[lengthInt]='.';
    for(int i=0;i<lengthFra;i++){
        str[lengthInt+1+i]=fractionPartString[i];
    }
    str[lengthInt+1+lengthFra]='\0';
    //printString(final);
    //*str=*final;
    //return final;
}


/**
 * @brief 整数转字符串时计算长度
 *
 * @author MrShiehX
 * @param num 整数
 * @param radix 进制数
 * @return 字符串长度（已包含负号（如果有）、该进制的最大数值的长度、“\0”）
 */
UINT32 intToStrLength(SUINT64 num, int radix){
    if(radix<2)radix=10;
    UINT32 length=0;
    boolean negative=num<0;
    if(negative)length++;

    if(!inited)init();

    int radixLessTwo=radix-2;
    if(radixLessTwo<=14){
        length+=baseCounts[radixLessTwo];
    }else{
        length+=16;
    }
    length++;//\0
    return length;
}


/**
 * @brief 整数转字符串(十进制)
 *
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串 长度：UINT32 intToStrLength(SUINT64 num, int radix)
 * @return 长度（没有\0）
 */
UINT32 intToStr(SUINT64 num, char *str){
    return intToStrRadix(num,str,10);
}

/**
 * @brief 整数转字符串
 * 
 * @from https://blog.csdn.net/nanfeibuyi/article/details/80811498
 * @param num 整数
 * @param str 目标字符串 长度：UINT32 intToStrLength(SUINT64 num, int radix)
 * @param radix 进制数
 * @return 长度（没有\0）
 */
UINT32 intToStrRadix(SUINT64 num, char *str, int radix) {
    //int x = 0;

    if(!inited)init();
    //"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //索引表

    if(radix<2)radix=10;

    boolean negative = num < 0;
    if (negative) {
        num = -num;
    }

    unsigned unum;                                         //存放要转换的整数的绝对值,转换的整数可能是负数
    int i = 0, j, k;                                       //i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。

    //获取要转换的整数的绝对值
    /*if (radix == 10 && num < 0) //要转换成十进制数并且是负数
    {
        unum = (unsigned) -num; //将num的绝对值赋给unum
        str[i++] = '-';        //在字符串最前面设置为'-'号，并且索引加1
    } else*/
        unum = (unsigned) num; //若是num为正，直接赋值给unum

    //转换部分，注意转换后是逆序的
    do {
        str[i++] = indexx[unum % (unsigned) radix]; //取unum的最后一位，并设置为str对应位，指示索引加1
        unum /= radix;                            //unum去掉最后一位

    } while (unum); //直至unum为0退出循环

    str[i] = '\0'; //在字符串最后添加'\0'字符，c语言字符串以'\0'结束。

    //将顺序调整过来
    //if (str[0] == '-')
    //    k = 1; //如果是负数，符号不用调整，从符号后面开始调整
    //else
    k = 0; //不是负数，全部都要调整

    char temp;//临时变量，交换两个值时用到
    for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp=str[j];//头部赋值给临时变量
        str[j]=str[i-1+k-j];//尾部赋值给头部
        str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
    }


    if (!negative) {
        //return str; //返回转换后的字符串
        return i;

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

        //return str; //返回转换后的字符串
        return i+1;
    }
}


void init(){
    for(int p=0;p<10;p++){
        indexx[p]=p+0x30;
    }

    int base;
#ifdef UPPER
    base=0x41;
#else
    base=0x61;
#endif
    for(int p=10;p<26+10;p++){
        indexx[p]=p+base/*小写*/-10;
    }
    indexx[36] = '\0';

/*
 * SUINT64
 * 2 111111111111111111111111111111111111111111111111111111111111111 63
 * 3 2021110011022210012102010021220101220221 40
 * 4 13333333333333333333333333333333 32
 * 5 1104332401304422434310311212 28
 * 6 1540241003031030222122211 25
 * 7 22341010611245052052300 23
 * 8 777777777777777777777 21
 * 9 67404283172107811827 20
 * 10 9223372036854775807 19
 * 11 1728002635214590697 19
 * 12 41A792678515120367 18
 * 13 10B269549075433C37 18
 * 14 4340724C6C71DC7A7 17
 * 15 160E2AD3246366807 17
 * 16 7FFFFFFFFFFFFFFF 16
 * 17 33D3D8307B214008 16
 * 18 16AGH595DF825FA7 16
 * 19 BA643DCI0FFEEHH 15
 * 20 5CBFJIA3FH26JA7 15
 * 21 2HEICIIIE82DH97 15
 * 22 1ADAIBB21DCKFA7 15
 *
 *
 *
 * 36 1Y2P0IJ32E8E7
 * */


    baseCounts[0]=63;
    baseCounts[1]=40;
    baseCounts[2]=32;
    baseCounts[3]=28;
    baseCounts[4]=25;
    baseCounts[5]=23;
    baseCounts[6]=21;
    baseCounts[7]=20;
    baseCounts[8]=19;
    baseCounts[9]=19;
    baseCounts[10]=18;
    baseCounts[11]=18;
    baseCounts[12]=17;
    baseCounts[13]=17;
    baseCounts[14]=16;


    inited=true;
}