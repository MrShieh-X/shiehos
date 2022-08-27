#ifndef __VIDEO_CURSOR_H__
#define __VIDEO_CURSOR_H__

#include "video.h"

boolean setCursor(POINT point);

void backup(POINT point);

void recover(POINT point);

#endif