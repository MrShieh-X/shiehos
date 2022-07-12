#include "cursor.h"

boolean cursorSet = false;

boolean setCursor(POINT point) {
    if (!cursorSet) {
        backup(point);
        return cursorSet = drawMousePointer(cursorNow = point);
    }
    cursorSet = false;
    recover(cursorNow);
    backup(point);
    return cursorSet = drawMousePointer(cursorNow = point);
}

void recover(POINT point) {
    for (int y = 0; y < CURSOR_HEIGHT; y++) {
        for (int x = 0; x < CURSOR_WIDTH; x++) {
            long target = backups[y][x];
            if (target != -1) {
                PIXEL pixel;
                pixel.Color = target;
                pixel.X = point.X + x;
                pixel.Y = point.Y + y;
                drawPixel(pixel);
            }
        }
    }

}

void backup(POINT point) {
    UINT32 startX = point.X;
    UINT32 startY = point.Y;


    for (int i = 0; i < CURSOR_HEIGHT; i++) {
        for (int j = 0; j < CURSOR_WIDTH; j++) {
            backups[i][j] = -1;
        }
    }


    backups[0][0] = getPixelByXY(startX, startY);
    backups[1][0] = getPixelByXY(startX, startY + 1);
    backups[1][1] = getPixelByXY(startX + 1, startY + 1);
    backups[2][0] = getPixelByXY(startX, startY + 2);
    backups[2][1] = getPixelByXY(startX + 1, startY + 2);
    backups[2][2] = getPixelByXY(startX + 2, startY + 2);
    backups[3][0] = getPixelByXY(startX, startY + 3);
    backups[3][1] = getPixelByXY(startX + 1, startY + 3);
    backups[3][2] = getPixelByXY(startX + 2, startY + 3);
    backups[3][3] = getPixelByXY(startX + 3, startY + 3);
    backups[4][0] = getPixelByXY(startX, startY + 4);
    backups[4][1] = getPixelByXY(startX + 1, startY + 4);
    backups[4][2] = getPixelByXY(startX + 2, startY + 4);
    backups[4][3] = getPixelByXY(startX + 3, startY + 4);
    backups[4][4] = getPixelByXY(startX + 4, startY + 4);
    backups[5][0] = getPixelByXY(startX, startY + 5);
    backups[5][1] = getPixelByXY(startX + 1, startY + 5);
    backups[5][2] = getPixelByXY(startX + 2, startY + 5);
    backups[5][3] = getPixelByXY(startX + 3, startY + 5);
    backups[5][4] = getPixelByXY(startX + 4, startY + 5);
    backups[5][5] = getPixelByXY(startX + 5, startY + 5);
    backups[6][0] = getPixelByXY(startX, startY + 6);
    backups[6][1] = getPixelByXY(startX + 1, startY + 6);
    backups[6][2] = getPixelByXY(startX + 2, startY + 6);
    backups[6][3] = getPixelByXY(startX + 3, startY + 6);
    backups[6][4] = getPixelByXY(startX + 4, startY + 6);
    backups[6][5] = getPixelByXY(startX + 5, startY + 6);
    backups[6][6] = getPixelByXY(startX + 6, startY + 6);
    backups[7][0] = getPixelByXY(startX, startY + 7);
    backups[7][1] = getPixelByXY(startX + 1, startY + 7);
    backups[7][2] = getPixelByXY(startX + 2, startY + 7);
    backups[7][3] = getPixelByXY(startX + 3, startY + 7);
    backups[7][4] = getPixelByXY(startX + 4, startY + 7);
    backups[7][5] = getPixelByXY(startX + 5, startY + 7);
    backups[7][6] = getPixelByXY(startX + 6, startY + 7);
    backups[7][7] = getPixelByXY(startX + 7, startY + 7);
    backups[8][0] = getPixelByXY(startX, startY + 8);
    backups[8][1] = getPixelByXY(startX + 1, startY + 8);
    backups[8][2] = getPixelByXY(startX + 2, startY + 8);
    backups[8][3] = getPixelByXY(startX + 3, startY + 8);
    backups[8][4] = getPixelByXY(startX + 4, startY + 8);
    backups[8][5] = getPixelByXY(startX + 5, startY + 8);
    backups[8][6] = getPixelByXY(startX + 6, startY + 8);
    backups[8][7] = getPixelByXY(startX + 7, startY + 8);
    backups[8][8] = getPixelByXY(startX + 8, startY + 8);
    backups[9][0] = getPixelByXY(startX, startY + 9);
    backups[9][1] = getPixelByXY(startX + 1, startY + 9);
    backups[9][2] = getPixelByXY(startX + 2, startY + 9);
    backups[9][3] = getPixelByXY(startX + 3, startY + 9);
    backups[9][4] = getPixelByXY(startX + 4, startY + 9);
    backups[9][5] = getPixelByXY(startX + 5, startY + 9);
    backups[9][6] = getPixelByXY(startX + 6, startY + 9);
    backups[9][7] = getPixelByXY(startX + 7, startY + 9);
    backups[9][8] = getPixelByXY(startX + 8, startY + 9);
    backups[9][9] = getPixelByXY(startX + 9, startY + 9);
    backups[10][0] = getPixelByXY(startX, startY + 10);
    backups[10][1] = getPixelByXY(startX + 1, startY + 10);
    backups[10][2] = getPixelByXY(startX + 2, startY + 10);
    backups[10][3] = getPixelByXY(startX + 3, startY + 10);
    backups[10][4] = getPixelByXY(startX + 4, startY + 10);
    backups[10][5] = getPixelByXY(startX + 5, startY + 10);
    backups[10][6] = getPixelByXY(startX + 6, startY + 10);
    backups[10][7] = getPixelByXY(startX + 7, startY + 10);
    backups[10][8] = getPixelByXY(startX + 8, startY + 10);
    backups[10][9] = getPixelByXY(startX + 9, startY + 10);
    backups[10][10] = getPixelByXY(startX + 10, startY + 10);
    backups[11][0] = getPixelByXY(startX, startY + 11);
    backups[11][1] = getPixelByXY(startX + 1, startY + 11);
    backups[11][2] = getPixelByXY(startX + 2, startY + 11);
    backups[11][3] = getPixelByXY(startX + 3, startY + 11);
    backups[11][4] = getPixelByXY(startX + 4, startY + 11);
    backups[11][5] = getPixelByXY(startX + 5, startY + 11);
    backups[11][6] = getPixelByXY(startX + 6, startY + 11);
    backups[11][7] = getPixelByXY(startX + 7, startY + 11);
    backups[11][8] = getPixelByXY(startX + 8, startY + 11);
    backups[11][9] = getPixelByXY(startX + 9, startY + 11);
    backups[11][10] = getPixelByXY(startX + 10, startY + 11);
    backups[11][11] = getPixelByXY(startX + 11, startY + 11);
    backups[12][0] = getPixelByXY(startX, startY + 12);
    backups[12][1] = getPixelByXY(startX + 1, startY + 12);
    backups[12][2] = getPixelByXY(startX + 2, startY + 12);
    backups[12][3] = getPixelByXY(startX + 3, startY + 12);
    backups[12][4] = getPixelByXY(startX + 4, startY + 12);
    backups[12][5] = getPixelByXY(startX + 5, startY + 12);
    backups[12][6] = getPixelByXY(startX + 6, startY + 12);
    backups[12][7] = getPixelByXY(startX + 7, startY + 12);
    backups[12][8] = getPixelByXY(startX + 8, startY + 12);
    backups[12][9] = getPixelByXY(startX + 9, startY + 12);
    backups[12][10] = getPixelByXY(startX + 10, startY + 12);
    backups[12][11] = getPixelByXY(startX + 11, startY + 12);
    backups[13][0] = getPixelByXY(startX, startY + 13);
    backups[13][1] = getPixelByXY(startX + 1, startY + 13);
    backups[13][2] = getPixelByXY(startX + 2, startY + 13);
    backups[13][3] = getPixelByXY(startX + 3, startY + 13);
    backups[13][4] = getPixelByXY(startX + 4, startY + 13);
    backups[13][5] = getPixelByXY(startX + 5, startY + 13);
    backups[13][6] = getPixelByXY(startX + 6, startY + 13);
    backups[13][7] = getPixelByXY(startX + 7, startY + 13);
    backups[14][0] = getPixelByXY(startX, startY + 14);
    backups[14][1] = getPixelByXY(startX + 1, startY + 14);
    backups[14][2] = getPixelByXY(startX + 2, startY + 14);
    backups[14][3] = getPixelByXY(startX + 3, startY + 14);
    backups[14][5] = getPixelByXY(startX + 5, startY + 14);
    backups[14][6] = getPixelByXY(startX + 6, startY + 14);
    backups[14][7] = getPixelByXY(startX + 7, startY + 14);
    backups[14][8] = getPixelByXY(startX + 8, startY + 14);
    backups[15][0] = getPixelByXY(startX, startY + 15);
    backups[15][1] = getPixelByXY(startX + 1, startY + 15);
    backups[15][2] = getPixelByXY(startX + 2, startY + 15);
    backups[15][5] = getPixelByXY(startX + 5, startY + 15);
    backups[15][6] = getPixelByXY(startX + 6, startY + 15);
    backups[15][7] = getPixelByXY(startX + 7, startY + 15);
    backups[15][8] = getPixelByXY(startX + 8, startY + 15);
    backups[16][0] = getPixelByXY(startX, startY + 16);
    backups[16][1] = getPixelByXY(startX + 1, startY + 16);
    backups[16][6] = getPixelByXY(startX + 6, startY + 16);
    backups[16][7] = getPixelByXY(startX + 7, startY + 16);
    backups[16][8] = getPixelByXY(startX + 8, startY + 16);
    backups[16][9] = getPixelByXY(startX + 9, startY + 16);
    backups[17][6] = getPixelByXY(startX + 6, startY + 17);
    backups[17][7] = getPixelByXY(startX + 7, startY + 17);
    backups[17][8] = getPixelByXY(startX + 8, startY + 17);
    backups[17][9] = getPixelByXY(startX + 9, startY + 17);
    backups[18][7] = getPixelByXY(startX + 7, startY + 18);
    backups[18][8] = getPixelByXY(startX + 8, startY + 18);
}