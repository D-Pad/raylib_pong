#include "Ball.h"
#include "raylib.h"
#include <cmath>


void Ball::initialize(int winW, int winH) {
    max_width = winW;
    max_height = winH;
    x_pos = winW / 2.0;
    y_pos = winH / 2.0;
    acceleration = 0.1;
}


void Ball::draw() {
    DrawCircle(x_pos, y_pos, radius, ORANGE);
}


void Ball::move() {

    double length = sqrt(dx * dx + dy * dy);

    if (length != 0) {
        
        double vx = dx / length * speed;
        double vy = dy / length * speed;

        x_pos += vx;
        y_pos += vy; 
    }
}


void Ball::update() {
    
    // Reverse ball direction on bounce
    if (x_pos + radius >= max_width || x_pos - radius <= 0) {
        dx *= -1;
    }

    if (y_pos + radius >= max_height || y_pos - radius <= 0) {
        dy *= -1;
    }

    move();
}


