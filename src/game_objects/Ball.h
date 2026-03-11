#pragma once 


struct Ball {

    int x = 100;
    int y = 100;
    int x_speed = 5;
    int y_speed = 5;
    int radius = 15;

    int check_position(int winW, int winH);

};

