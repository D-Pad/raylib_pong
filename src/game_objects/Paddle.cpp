#include "Paddle.h"


void Paddle::move(Direction dir) {

    if (dir == UP) {

        if (y_pos > 0) {
            y_pos += move_speed;
        };
    
    }
    else if (dir == DOWN) {

        if (y_pos < max_y_pos) {
            y_pos -= move_speed;
        } 

    } 

}


void Paddle::initialize(bool isPlayer, int winW, int winH) {

    is_player = isPlayer;
    height = winH / 10;  
    y_pos = (winH / 2) - height / 2;
    max_y_pos = winH - (height);

    int padding = winW / 100;

    if (isPlayer) x_pos = padding;
    else x_pos = winW - (width + padding);


}


