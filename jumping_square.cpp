 #include "raylib.h"

int main()
{
    const int windowWidth = 512;
    const int windowHeight = 380;
    const int max_fps = 60;

    InitWindow(windowWidth,windowHeight, "Dasher");

    // rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{windowHeight - height};
    int velocity {0};
    int back {0};
    bool is_jumping = false;

    SetTargetFPS(max_fps);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(IsKeyPressed(KEY_SPACE)) {
            back = posY;
            velocity -= 10;
            is_jumping = true;
        }
          
        posY += velocity;
        
        if(is_jumping && back - posY == 220) {
            velocity = 10;
        }

        if(is_jumping && back == posY ) {
            velocity = 0;
            is_jumping = false;
        }
      
        
        DrawRectangle(windowWidth/2, posY, width, height, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
