#include "Screen.h"


void Screen::initialize(int winW, int winH, int frameRate) {

    width = winW;
    height = winH;
    center_width = winW / 2;
    center_height = winH / 2;
    frame_rate = frameRate;

}

