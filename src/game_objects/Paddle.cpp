#include "Paddle.h"
#include "raylib.h"
#include <cmath>


void Paddle::accelerate(Direction dir) {

    if (dir == UP) {

        if (y_pos > 0) {
            if (fabs(move_speed) < max_speed) {
                move_speed -= acceleration_rate;
                if (move_speed < -max_speed) move_speed = -max_speed;
            }
            y_pos += move_speed;
        }
        else {
            move_speed = 0.0;  // Has hit the wall
            y_pos = 0;
        };
    
    }
    else if (dir == DOWN) {

        if (y_pos < max_y_pos) {
            if (fabs(move_speed) < max_speed) {
                move_speed += acceleration_rate;
                if (move_speed > max_speed) move_speed = max_speed;
            }
            y_pos += move_speed;
        }
        else {
            move_speed = 0.0;
            y_pos = max_y_pos;
        }

    } 

}


void Paddle::decelerate() {
 
    if (fabs(move_speed) - 0.0 < 0.001 || y_pos >= max_y_pos || y_pos <= 0) {
        move_speed = 0.0;
    }
    else {
        if (move_speed < 0.0) move_speed += acceleration_rate;
        else if (move_speed > 0.0) move_speed -= acceleration_rate;
        y_pos += move_speed;
    }

}


void Paddle::initialize(bool isPlayer, int winW, int winH, int frameRate) {

    is_player = isPlayer;
    height = winH / 10;  
    y_pos = (winH / 2) - height / 2;
    max_y_pos = winH - (height);
    acceleration_rate = max_speed / frameRate; 

    int padding = winW / 100;

    if (isPlayer) x_pos = padding;
    else x_pos = winW - (width + padding);

}


void Paddle::draw() {
    DrawRectangle(x_pos, y_pos, width, height, WHITE); 
}

void Paddle::update() {
  
    // Player movement
    if (is_player) {
        if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
            accelerate(UP); 
        }
        else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)) {
            accelerate(DOWN); 
        }
        else {
            decelerate();
        }
    }

    // FIXME: AI movement here
}


