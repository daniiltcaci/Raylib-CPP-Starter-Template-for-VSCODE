#include <iostream>
#include <raylib.h>

using namespace std;

typedef enum{ TITLE, MENU_CHOIX_PERSO, GAMEPLAY, GAME_END } Gamescreen; 

int main () {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first RAYLIB program!");
    Gamescreen currentscreen = TITLE;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (currentscreen)
        {
            case TITLE:
            if (IsKeyPressed(KEY_ENTER))
            {
                currentscreen = MENU_CHOIX_PERSO;
            }
            break;

            case MENU_CHOIX_PERSO:
            if (IsKeyPressed(KEY_ENTER))
            {
                currentscreen = GAMEPLAY;
            }
            break;

            case GAMEPLAY:
            if (IsKeyPressed(KEY_ENTER))
            {
                currentscreen = GAME_END;
            }
            break;

            case GAME_END:
            if (IsKeyPressed(KEY_ENTER))
            {
                currentscreen = TITLE;
            }
            break;

        default:break;
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (currentscreen)
        {

        case TITLE:
            {
            DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GREEN);
            DrawText("TITLE SCREEN", 20, 20, 40, WHITE);
            }
        break;

        case MENU_CHOIX_PERSO:
           { DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RED);
            DrawText("MENU_CHOIX_PERSO", 20, 20, 40, WHITE);}
        break;

        case GAMEPLAY:
            {DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
            DrawText("GAMEPLAY", 20, 20, 40, WHITE);}
        break;

        case GAME_END:
           { DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
            DrawText("YANISSE JE TE SUCE", 20, 20, 40, WHITE);}
        break;

        
        default:break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}