#include "Ball.h"
#include "raylib.h"


int Ball::check_position(int winW, int winH) {

    if (x_pos + radius >= winW || x_pos - radius <= 0) {
        x_speed *= -1;
    }

    if (y_pos + radius >= winH || y_pos - radius <= 0) {
        y_speed *= -1;
    }

    return 0;
};


void Ball::draw() {
    
    DrawCircle(x_pos, y_pos, radius, ORANGE);

}

