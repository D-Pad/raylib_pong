#pragma once 
#include "raylib.h"


struct Ball {

    double x_pos = 100;
    double y_pos = 100;
    double dx = 1.0;
    double dy = 1.0;
    double speed = 5.0;
    double max_speed = 20.0;
    double acceleration;
    int radius = 15;

    int max_width, max_height;

    void draw();
    void initialize(int winW, int winH);
    void move();
    void update();

};

