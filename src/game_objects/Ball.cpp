#include "Ball.h"
#include "raylib.h"


void Ball::initialize(int winW, int winH, int frameRate) {
    max_width = winW;
    max_height = winH;
    x_pos = winW / 2.0;
    y_pos = winH / 2.0;
    acceleration = 0.1;
}


int Ball::update_position() {

    if (x_pos + radius >= max_width || x_pos - radius <= 0) {
        x_speed *= -1;
    }

    if (y_pos + radius >= max_height || y_pos - radius <= 0) {
        y_speed *= -1;
    }

    return 0;
};


void Ball::draw() {
    DrawCircle(x_pos, y_pos, radius, ORANGE);
}

void Ball::move() {
    x_pos += x_speed;
    y_pos += y_speed;
}

void Ball::update() {
    update_position();
    move();
}

