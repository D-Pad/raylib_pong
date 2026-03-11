#pragma once 


struct Ball {

    float x_pos = 100;
    float y_pos = 100;
    int x_speed = 5;
    int y_speed = 5;
    int radius = 15;

    int check_position(int winW, int winH);
    void draw();

};

