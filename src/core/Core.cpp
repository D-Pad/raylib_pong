#include <iostream>
#include <algorithm>
#include <raylib.h>
#include "Core.h"
#include "../game_objects/GameObjects.h"
#include "../game_settings/Screen.h"
using namespace std;


enum GameModes {
    SINGLEPLAYER,
    MULTIPLAYER,
    MENU,
};


enum PaddleCollision {
    None,
    Top,
    Bottom,
    Front,
    Back, // Should never happen, unless ball glitches behind paddle
};


bool BallPaddleCollision(const Ball& ball, const Paddle& paddle) {
    
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


int GameLoop() {

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

    GameModes menu = SINGLEPLAYER;
    
    while (WindowShouldClose() == false) {

        // ---------------- Update objects here ------------------ //
        bool below_top;
        bool above_btm;
        bool player_hit; 
        bool opponent_hit;

        switch(menu) {

            case MENU:

                break;

            case SINGLEPLAYER:
            case MULTIPLAYER:
                
                ball.update();
                player.update();      

                player_hit = BallPaddleCollision(ball, player);
                opponent_hit = BallPaddleCollision(ball, opponent);

                if (player_hit || opponent_hit) {
                    
                    ball.dx *= -1;
                    
                    below_top = ball.y_pos <= player.hit_box.top_right.y;
                    above_btm = ball.y_pos >= player.hit_box.bottom_right.y;
                   
                    // Clip prevention
                    if (player_hit) {
                        double target = player.hit_box.top_right.x;
                        if (ball.x_pos - ball.radius <= target) {
                            double player_tr = player.hit_box.top_right.x;
                            ball.x_pos = player_tr + ball.radius;
                        }
                    }
                    else if (opponent_hit) {
                        double target = opponent.hit_box.bottom_left.x;
                        if (ball.x_pos + ball.radius >= target) {
                            double opp_tl = opponent.hit_box.bottom_left.x;
                            ball.x_pos = opp_tl - ball.radius;
                        }           
                    };
                
                }

                break;

        };

        // ----------------- Draw objects here ------------------- //
        BeginDrawing();
        ClearBackground(BLACK);

        switch(menu) {

            case MENU:

                break;

            case SINGLEPLAYER:
            case MULTIPLAYER:

                // Court
                court.draw(); 

                // Players
                player.draw();
                opponent.draw();

                // Ball 
                ball.draw();

                break;

        };

        EndDrawing();

    }

    CloseWindow();
    return 0;

}


int RunGameLoop() {

    int exit_code;

    int init_code = Initialize();
    if (init_code != 0) {
        cout << "Initialization failed" << endl;
        return init_code; 
    }

    cout << "Running main game loop" << endl;
    int game_code = GameLoop();
    if (game_code != 0) {
        cout << "ERROR: " << game_code << endl;
        return game_code; 
    }

    int cleanup_code;
    cleanup_code = Cleanup();
    if (cleanup_code != 0) {
        cout << "Cleanup failed" << endl;
        return cleanup_code;
    }

    return 0;

}

