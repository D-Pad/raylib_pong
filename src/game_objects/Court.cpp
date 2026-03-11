#include "Court.h"
#include "raylib.h"


void Court::draw() {
    DrawLine(
        line_x, 0, line_x, line_y, WHITE 
    );
}


void Court::initialize(int lineX, int lineY) {

    line_x = lineX;
    line_y = lineY;

}

