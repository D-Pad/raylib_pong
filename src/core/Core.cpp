#include <iostream>
#include <raylib.h>
#include <cmath>
#include "Cleanup.h"
#include "Init.h"
#include "../game_objects/Ball.h"
#include "../game_objects/Paddle.h"
#include "../game_objects/Court.h"
#include "../game_settings/Screen.h"
using namespace std;


enum PaddleCollision {
    None,
    Top,
    Bottom,
    Front,
    Back, // Should never happen, unless ball glitches behind paddle
};


PaddleCollision ball_paddle_collision(Ball ball, Paddle paddle) {
    
    PaddleCollision collision = None;

    Point top_front = paddle.hit_box.top_right;
    Point btm_front = paddle.hit_box.bottom_right; 

    double x_dist_from_top = fabs(ball.x_pos - top_front.x);
    double y_dist_from_top = fabs(ball.y_pos - top_front.y);
    double x_dist_from_btm = fabs(ball.x_pos - btm_front.x);
    double y_dist_from_btm = fabs(ball.y_pos - btm_front.y);

    if (paddle.is_player) {
        cout << "Closest: ";
        if (y_dist_from_btm < y_dist_from_top) {
            cout << "btm "; 
        }
        else {
            cout << "top ";
        }
        cout << endl;
    }

    return collision;
}


int game_loop() {

    // Game screen initialization
    Screen screen;
    screen.initialize(1920, 1080, 60);

    InitWindow(screen.width, screen.height, "PONG!");
    SetTargetFPS(screen.frame_rate);

    // Game object initialization
    Ball ball;
    ball.initialize(screen.width, screen.height); 

    Paddle player;
    player.initialize(true, screen.width, screen.height, screen.frame_rate);

    Paddle opponent;
    opponent.initialize(false, screen.width, screen.height, screen.frame_rate);

    Court court;
    court.initialize(screen.center_width, screen.height);

    while (WindowShouldClose() == false) {

        // ---------------- Update objects here ------------------ //
        ball.update();
        player.update();      

        bool player_hit = ball_paddle_collision(ball, player);
        bool opponent_hit = ball_paddle_collision(ball, opponent);

        // if (player_hit || opponent_hit) {
        //     ball.x_speed *= -1;
        // }

        // ----------------- Draw objects here ------------------- //
        BeginDrawing();
        ClearBackground(BLACK);
        
        // Court
        court.draw(); 

        // Players
        player.draw();
        opponent.draw();

        // Ball 
        ball.draw();

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

