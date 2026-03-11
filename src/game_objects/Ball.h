#pragma once 


struct Ball {

    float x_pos = 100;
    float y_pos = 100;
    int x_speed = 5;
    int y_speed = 5;
    int radius = 15;

    int max_width, max_height;

    void initialize(int winW, int winH);
    int check_position();
    void draw();
    void move();
    void update();

};

