#include "kernel.h"

int say_hi(int a5);

_Noreturn UINT64 kernelStart(BootConfig *bootConfig) {
    //UINT64 PassBack = 0;
    initVideo(bootConfig);
    initShell(bootConfig->videoConfig);
    initPrinter(bootConfig);
    initMemory(bootConfig);

    int ao=10;
    printlnInt(ao);
    int* aa=&ao;
    printlnInt(say_hi(2222));

    int x=0;
    char c[61];
    c[x++]='A';
    c[x++]='r';
    c[x++]='i';
    c[x++]='n';
    c[x++]='t';
    c[x++]=' ';
    c[x++]='a';
    c[x++]=' ';
    c[x++]='S';
    c[x++]='t';
    c[x++]='r';
    c[x++]='i';
    c[x++]='n';
    c[x++]='g';
    c[x++]=':';
    c[x++]=' ';
    c[x++]='%';
    c[x++]='s';
    c[x++]='\n';
    c[x++]='P';
    c[x++]='r';
    c[x++]='i';
    c[x++]='n';
    c[x++]='t';
    c[x++]=' ';
    c[x++]='a';
    c[x++]=' ';
    c[x++]='f';
    c[x++]='r';
    c[x++]='a';
    c[x++]='c';
    c[x++]='t';
    c[x++]='i';
    c[x++]='o';
    c[x++]='n';
    c[x++]=':';
    c[x++]=' ';
    c[x++]='%';
    c[x++]='f';
    c[x++]='\n';
    c[x++]='P';
    c[x++]='r';
    c[x++]='i';
    c[x++]='n';
    c[x++]='t';
    c[x++]=' ';
    c[x++]='a';
    c[x++]='n';
    c[x++]=' ';
    c[x++]='i';
    c[x++]='n';
    c[x++]='t';
    c[x++]='e';
    c[x++]='g';
    c[x++]='e';
    c[x++]='r';
    c[x++]=':';
    c[x++]=' ';
    c[x++]='%';
    c[x++]='d';
    c[x++]='\0';

    //printFraction(str,6);
    char str[9];
    int y=0;
    str[y++]='M';
    str[y++]='r';
    str[y++]='S';
    str[y++]='h';
    str[y++]='i';
    str[y++]='e';
    str[y++]='h';
    str[y++]='X';
    str[y++]='\0';
    int integer=14;
    double fraction=11454;
    UINT64 f[3];
    f[0]= (UINT64) &str;
    f[1]= (UINT64) &fraction;
    f[2]= (UINT64) &integer;





    int p=printfln(c,f,3);
    int p2=printfln(c,f,3);
    printlnInt(p);
    printlnInt(p2);












    /*printFraction(1456.0,0);//1456.0
    newLine();
    printFraction(1456.0,1);//1456.0
    newLine();
    printFraction(1456.0,2);//1456.00
    newLine();
    printFraction(1456.1,0);//1456.0
    newLine();*/

    /*printFraction(1456.11,0);//1456.0
    newLine();
    printFraction(1456.11,1);//1456.1
    newLine();
    printFraction(1456.11,2);//1456.11
    newLine();

    newLine();
    printlnFraction(1456.0,0);//1456.0
    printlnFraction(1456.0,1);//1456.0
    printlnFraction(1456.12121212,9);//1456.00
    printlnFraction(1456.1,0);//1456.0
    printlnFraction(1456.1,1);//1456.1
    printlnFraction(1456.1,2);//1456.10
    printlnFraction(1456.11,0);//1456.0
    printlnFraction(1456.11,1);//1456.1
    printlnFraction(1456.111456,2);//1456.11
    printlnFraction(1456.111456,5);//1456.11145
    printlnFraction(1456.111456,6);//1456.111456
    printlnFraction(1456.111456,7);//1456.1114560*/



    /*
     * 4+16
     * 4+16
     * 17
     * 5+16
     * 5+16
     * 18
     * 23234
     * -23234
     * 23234
     * -23234
     * 0x23234-0x23234
     * 23234
     * -5AC2
     * 5AC2
     * -5AC2
     * -101101011000010
     * -23234
     *

    printlnInt(intToStrLength(456,10));
    printlnInt(intToStrLength(456,1));
    printlnInt(intToStrLength(456,26));
    printlnInt(intToStrLength(-456,10));
    printlnInt(intToStrLength(-456,1));
    printlnInt(intToStrLength(-456,26));

    printInt(23234);
    newLine();
    printInt(-23234);
    newLine();
    printlnInt(23234);
    printlnInt(-23234);
    printHex(0x23234);
    printlnHex(-0x23234);

    printIntRadix(0X23234,16);
    newLine();
    printIntRadix(-23234,16);
    newLine();
    printlnIntRadix(23234,16);
    printlnIntRadix(-23234,16);
    printlnIntRadix(-23234,2);
    printlnIntRadix(-23234,1);*/




    while(1){;}

    //return /*str[0]*/0;
}