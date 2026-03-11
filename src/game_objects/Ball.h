#pragma once
#include "Point.h"
#include "raylib.h"


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

