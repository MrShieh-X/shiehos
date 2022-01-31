#include "kernel.h"

UINT64 kernelStart(BootConfig *bootConfig)
{
    //UINT64 PassBack = 0;
    initVideo(bootConfig);
    initShell(bootConfig->videoConfig);
    initPrinter(bootConfig);

    int i=0;
    char c[5];
    c[i++]='a';
    c[i++]='b';
    c[i++]='c';
    c[i++]='d';
    c[i++]='e';
    c[i++]='g';

    printlnString(c);
    printString(c);

    //for(character i=0;i<2000;i++)print(i);
    /*print('M');
    print('r');
    print('S');
    print('h');
    print('i');
    print('e');
    print('h');
    print('X');
    print('o');
    print('s');
    print('\n');
    print('2');
    print('0');
    print('2');
    print('2');
    print('0');
    newLine();
    print('\r');
    print('\n');
    print('a');
    print('b');*/




    while(1){;}

    return /*str[0]*/0;
}