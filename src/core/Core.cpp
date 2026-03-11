#include <iostream>
#include <raylib.h>
#include "Cleanup.h"
#include "Init.h"
#include "../game_objects/Ball.h"
#include "../game_objects/Paddle.h"
#include "../game_objects/Court.h"
#include "../game_settings/Screen.h"
using namespace std;


int game_loop() {

    // Game screen initialization
    Screen screen;
    screen.initialize(1920, 1080);

    InitWindow(screen.width, screen.height, "PONG!");
    SetTargetFPS(60);

    // Game object initialization
    Ball ball;
    ball.x_pos = screen.center_width;
    ball.y_pos = screen.center_height;

    Paddle player;
    player.initialize(true, screen.width, screen.height);

    Paddle opponent;
    opponent.initialize(false, screen.width, screen.height);

    Court court;
    court.initialize(screen.center_width, screen.height);

    cout << "SCREEN " << screen.center_width << " " << screen.height << endl;
    while (WindowShouldClose() == false) {

        BeginDrawing();
        ClearBackground(BLACK);
        
        ball.x_pos += ball.x_speed;
        ball.y_pos += ball.y_speed;
        ball.check_position(screen.width, screen.height);
       
        // --------------- Draw objects here ------------------- //
        // Court
        court.draw(); 

        // Ball 
        ball.draw();       

        // Players
        player.draw();
        opponent.draw();

        EndDrawing();

    }

    CloseWindow();
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

