#include "raylib.h"

typedef enum GameScreen { LOGO = 0, TITLE, NEW_GAME, CONTINUE,HIGH_SCORES ,QUIT } GameScreen;


void game()
{
        const int screenWidth = 800;
    const int screenHeight = 450;
    Font fonte = LoadFont("resources/fonts/mecha.png");

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();


            ClearBackground(RAYWHITE);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        if(IsKeyPressed(KEY_ENTER))
            break;
        //----------------------------------------------------------------------------------
    }
}

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 900;
    int tchauzinho = 0;
    int menu_choice = 0;    
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    Font fonte = LoadFont("resources/fonts/mecha.png");

    InitWindow(screenWidth, screenHeight, "BattleINF by Caetano Müller");

    GameScreen currentScreen = LOGO;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    
    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)){
                    switch(menu_choice)
                    {
                        case 1:currentScreen = NEW_GAME; break;
                        case 0:currentScreen = CONTINUE; break;
                        case 2:currentScreen = HIGH_SCORES; break;
                        case 3:currentScreen = QUIT; break;
                    }   
                }
                if(IsKeyPressed(KEY_DOWN) && menu_choice<3) //a wittle heart how cute <3
                    menu_choice++;
                if(IsKeyPressed(KEY_UP) && menu_choice>0) //a wittle heart how cute
                    menu_choice--;

            } break;
            case NEW_GAME:
            {
                while (!(IsKeyDown(KEY_Q)))    // Detect window close button or ESC key
                {
                    // Update
                    //----------------------------------------------------------------------------------
                    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 4.0f;
                    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 4.0f;
                    if (IsKeyDown(KEY_UP)) ballPosition.y -= 4.0f;
                    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 4.0f;
                }

            } break;
            case HIGH_SCORES:
            {
                //implement here...
            }break;
            case QUIT:
            {
                if(tchauzinho == 60)
                    return 0;
                tchauzinho++;
            } break;
            default: break;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case LOGO:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    // TODO: Draw LOGO screen here!
                    DrawText("BattleINF", (screenWidth - MeasureText("BattleINF", 80)) / 2, 20, 80, RED);
                    DrawText("Loading...", (screenWidth - MeasureText("BattleINF", 80)) / 2, 550, 40, RED);
                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawText("BattleINF", (screenWidth - MeasureText("BattleINF", 150))/2, 20, 150, WHITE);
                    if(menu_choice==0)
                        DrawText("CONTINUE", (screenWidth - MeasureText("CONTINUE", 40))/2, 320, 40, YELLOW);
                    else
                        DrawText("CONTINUE", (screenWidth - MeasureText("CONTINUE", 40))/2, 320, 40, WHITE);
                    if(menu_choice==1)
                        DrawText("NEW GAME", (screenWidth - MeasureText("NEW GAME", 40))/2, 420, 40, YELLOW);
                    else
                        DrawText("NEW GAME", (screenWidth - MeasureText("NEW GAME", 40))/2, 420, 40, WHITE);
                    if(menu_choice==2)
                        DrawText("HIGH SCORES", (screenWidth - MeasureText("HIGH SCORES", 40))/2, 520, 40, YELLOW);
                    else
                        DrawText("HIGH SCORES", (screenWidth - MeasureText("HIGH SCORES", 40))/2, 520, 40, WHITE);
                    if(menu_choice==3)
                        DrawText("QUIT", (screenWidth - MeasureText("QUIT", 40))/2, 620, 40, YELLOW);
                    else
                        DrawText("QUIT", (screenWidth - MeasureText("QUIT", 40))/2, 620, 40, WHITE);

                } break;
                //TRAZER IMPLEMENTAÇÃO DE NOVO JOGO
                case NEW_GAME:
                {
                    BeginDrawing();


                        ClearBackground(RAYWHITE);

                        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

                        DrawCircleV(ballPosition, 50, MAROON);

                    EndDrawing();

                } break;

                case CONTINUE:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                case QUIT:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawText("Obrigado por jogar :)", 20, 20, 40, RED);
                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();
    

    return 0;
}



