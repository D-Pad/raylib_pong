#include <iostream>
#include <algorithm>
#include <raylib.h>
#include "Core.h"
#include "../game_objects/GameObjects.h"
#include "../game_settings/Screen.h"
using namespace std;


enum PaddleCollision {
    None,
    Top,
    Bottom,
    Front,
    Back, // Should never happen, unless ball glitches behind paddle
};


bool ball_paddle_collision(Ball ball, Paddle paddle) {
    
    PaddleCollision collision = None;

    float closest_x = std::clamp(
        ball.x_pos, 
        paddle.hit_box.top_left.x,
        paddle.hit_box.bottom_right.x
    );    

    float closest_y = std::clamp(
        ball.y_pos, 
        paddle.hit_box.top_left.y,
        paddle.hit_box.bottom_right.y
    );

    float dx = ball.x_pos - closest_x;
    float dy = ball.y_pos - closest_y;

    return (dx * dx + dy * dy) <= (ball.radius * ball.radius);
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

        if (player_hit || opponent_hit) {
            
            ball.dx *= -1;
            
            bool below_top = ball.y_pos <= player.hit_box.top_right.y;
            bool above_btm = ball.y_pos >= player.hit_box.bottom_right.y;
           
            // Clip prevention
            if (player_hit) {
                double target = player.hit_box.top_right.x;
                if (ball.x_pos - ball.radius <= target) {
                    ball.x_pos = player.hit_box.top_right.x + ball.radius;
                }
            }
            else if (opponent_hit) {
                double target = opponent.hit_box.bottom_left.x;
                if (ball.x_pos + ball.radius >= target) {
                    ball.x_pos = opponent.hit_box.bottom_left.x - ball.radius;
                }           
            };
        
        }

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

