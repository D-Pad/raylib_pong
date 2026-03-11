#pragma once 


struct Ball {

    double x_pos = 100;
    double y_pos = 100;
    double x_speed = 5.0;
    double y_speed = 5.0;
    double max_speed = 20.0;
    double acceleration;
    int radius = 15;

    int max_width, max_height;

    void initialize(int winW, int winH, int frameRate);
    int update_position();
    void draw();
    void move();
    void update();

};

