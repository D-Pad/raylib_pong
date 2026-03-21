#pragma once 
#include "raylib.h"


struct Point {
    double x, y;
};


struct Ball {

    double x_pos = 100;
    double y_pos = 100;
    double dx = 1.0;
    double dy = 0.5;
    double speed = 5.0;
    double angle;
    double max_speed = 20.0;
    double acceleration;
    double radius = 20.0;

    int max_width, max_height;

    void draw();
    double get_angle();
    void initialize(int winW, int winH);
    Point get_center_line(bool longLength);
    void move();
    void update();

};


struct Court {

    // Half court line
    int line_x;
    int line_y;

    void initialize(int lineX, int lineY);
    void draw();

};


enum Direction {
    UP,
    DOWN
};

struct PaddleHitBox {
    Point top_left, top_right, bottom_left, bottom_right;
};

struct Paddle {

    bool is_player;
    int width = 20;
    double move_speed = 0;
    double max_speed = 10;
    double acceleration_rate;
    int height, x_pos, y_pos, max_y_pos;
    PaddleHitBox hit_box;

    void draw();
    void initialize(bool isPlayer, int winW, int winH, int frameRate);
    void accelerate(Direction dir);
    void decelerate();
    void update();
};




