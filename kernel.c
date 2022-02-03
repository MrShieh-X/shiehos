#include "kernel.h"



UINT64 kernelStart(BootConfig *bootConfig) {
    //UINT64 PassBack = 0;
    initVideo(bootConfig);
    initShell(bootConfig->videoConfig);
    initPrinter(bootConfig);

    int i;
    char c[3];
    c[i++] = '4';
    c[i++] = ':';
    c[i++] = '\0';

    printFraction(1456.0,0);//1.0
    newLine();
    printFraction(1456.0,1);//1.0
    newLine();
    printFraction(1456.0,2);//1.00
    newLine();
    printFraction(1456.1,0);//1.0
    newLine();
    printFraction(1456.1,1);//1.1
    newLine();
    printFraction(1456.1,2);//1.10
    newLine();
    printFraction(1456.11,0);//1.0
    newLine();
    printFraction(1456.11,1);//1.1
    newLine();
    printFraction(1456.11,2);//1.11
    newLine();

    newLine();
    printlnFraction(1456.0,0);//1.0
    printlnFraction(1456.0,1);//1.0
    printlnFraction(1456.12121212,9);//1.00
    printlnFraction(1456.1,0);//1.0
    printlnFraction(1456.1,1);//1.1
    printlnFraction(1456.1,2);//1.10
    printlnFraction(1456.11,0);//1.0
    printlnFraction(1456.11,1);//1.1
    printlnFraction(1456.111456,2);//1.11
    printlnFraction(1456.111456,5);//1456.11145
    printlnFraction(1456.111456,6);//1456.111456
    printlnFraction(1456.111456,7);//1456.1114560



    /*
     * 23234
     * -23234
     * 23234
     * -23234
     * 0x23234-0x23234
     * 23234
     * -5AC2
     * 5AC2
     * -5AC2
     *

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
    printlnIntRadix(-23234,16);*/




    while(1){;}

    return /*str[0]*/0;
}