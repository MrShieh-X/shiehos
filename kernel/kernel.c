#include "kernel.h"

int say_hi(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13);

_Noreturn UINT64 kernelStart(BootConfig *bootConfig) {
    //UINT64 PassBack = 0;
    initVideo(bootConfig);
    initShell(bootConfig->videoConfig);
    initPrinter(bootConfig);
    //initMemory(bootConfig);
    initStringConverter();

    for (int i = 32; i < 130; i++) {
        print(i);
    }


    {
        BLOCK block;
        block.Color = argbToRgb(0x7f, 0xff0000, 0x0078d7);
        block.Start.X = 180;
        block.Start.Y = 180;
        block.End.X = 280;
        block.End.Y = 280;
        drawBlock(block);
    }


    POINT p233;
    p233.X = 200;
    p233.Y = 200;

    for (int i = 0; i < 77; i++) {
        print('a');
    }


    setCursor(p233);

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }

    p233.X = 201;
    setCursor(p233);

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }

    p233.X = 202;
    p233.Y = 201;
    setCursor(p233);

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }

    p233.X = 200;
    p233.Y = 200;
    setCursor(p233);
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }

    BLOCK block;
    block.Color = 0xaaff0000;
    block.Start.X = 180;
    block.Start.Y = 180;
    block.End.X = 280;
    block.End.Y = 280;
    drawBlock(block);

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }

    p233.X = 300;
    p233.Y = 300;
    setCursor(p233);

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            for (int x = 0; x < 3; x++) {
                p233.X = 0;
            }
        }
    }
    p233.X = 400;
    p233.Y = 390;
    setCursor(p233);


    for (int a = 0; a < 690; a++) {
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 300; j++) {
                for (int x = 0; x < 3; x++) {
                    p233.X = 0;
                }
            }
        }
        print('a');
    }

    p233.X = 200;
    p233.Y = 200;
    setCursor(p233);


    char a[5];
    a[0] = 'b';
    a[1] = '%';
    a[2] = 'd';
    a[3] = 'e';
    a[4] = '\0';
    UINT64 address[1];
    int A = 24;
    address[0] = (UINT64) (&(A));
    printfln(a, address, 1);

    /*p233.X=600;
    setCursor(p233);*/

    /*POINT p;
    p.X =200;
    p.Y =200;*/

/*

    for(int i=0;i<19;i++){
        for(int j=0;j<12;j++){
            printInt(backups[i][j]);
            print(' ');
        }
        newLine();
    }
*/



    while (1) { ; }

    //return /*str[0]*/0;



}