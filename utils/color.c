#include "color.h"

unsigned int rgb2hex(unsigned int r, unsigned int g, unsigned int b) {
    return rgb2hexWithTrans(0xff, r, g, b);
}

unsigned int rgb2hexWithTrans(unsigned int transparency, unsigned int r, unsigned int g, unsigned int b) {
    return transparency * 0x1000000 + r * 0x10000 + g * 0x100 + b;
}