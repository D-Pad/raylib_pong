#include "Ball.h"


int Ball::check_position(int winW, int winH) {

    if (x + radius >= winW || x - radius <= 0) {
        x_speed *= -1;
    }

    if (y + radius >= winH || y - radius <= 0) {
        y_speed *= -1;
    }

    return 0;
};

