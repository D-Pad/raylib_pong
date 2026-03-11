#pragma once 


enum Direction {
    UP,
    DOWN
};

struct Paddle {

    bool is_player;
    int width = 20;
    double move_speed = 0;
    double max_speed = 10;
    double acceleration_rate;
    int height, x_pos, y_pos, max_y_pos;

    void draw();
    void initialize(bool isPlayer, int winW, int winH, int frameRate);
    void accelerate(Direction dir);
    void decelerate();
    void update();
};


