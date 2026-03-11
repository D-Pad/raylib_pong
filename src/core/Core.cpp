#include <iostream>
#include "Cleanup.h"
#include "Init.h"
#include "../game_objects/Ball.h"
#include "../game_settings/Screen.h"
using namespace std;


int game_loop() {

    Screen screen { 800, 600 };
    Ball ball; 

    cout << "BALL!" << endl;
    cout << ball.ball_x << endl;
    return 0;

}


int run_game_loop() {

    int exit_code;

    int init_code = initialize();
    if (init_code != 0) {
        cout << "Initialization failed" << endl;
        return init_code; 
    }

    cout << "Running main game loop" << endl;
    int game_code = game_loop();
    if (game_code != 0) {
        cout << "ERROR: " << game_code << endl;
        return game_code; 
    }

    int cleanup_code;
    cleanup_code = cleanup();
    if (cleanup_code != 0) {
        cout << "Cleanup failed" << endl;
        return cleanup_code;
    }

    return 0;

}

