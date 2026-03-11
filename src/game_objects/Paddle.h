#pragma once 


enum Direction {
    UP,
    DOWN
};

struct Paddle {

    bool is_player;
    int width = 20;
    int move_speed = 10;
    int height, x_pos, y_pos, max_y_pos;

    void initialize(bool isPlayer, int winW, int winH);
    void move(Direction dir);
};


