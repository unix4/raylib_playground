#include "raylib.h"
 
 class Screen {
     public:
        int width;
        int height;
        int fps;
        Color background {WHITE};
 };
 
 class Circle {
     public: 
        float pos_x;
        float pos_y;
        float radius;
        int speed;
        Color color {BLUE};
        
        void draw() {
            DrawCircle(pos_x, pos_y, radius, color);
        }
 };
 
 class Axe {
     public:
        float pos_x;
        float pos_y;
        float width;
        float height;
        float speed;
        Color color {RED};
        
        void draw() {
            DrawRectangle(pos_x, pos_y, width, height, color);
        }
        
        void animate(int screen_height) {
            pos_y += speed;
            if(pos_y <= 0) {
                speed = speed * -1;
            }
                
            if(pos_y >= screen_height) {
                speed = -speed;
            }
                
        }
 };
 
 void CheckMovement(Circle &circle, Screen &screen) {
      if(IsKeyDown(KEY_D)) {
             circle.pos_x += circle.pos_x >= screen.width ? 0 : circle.speed;
      }else if(IsKeyDown(KEY_A)) {
             circle.pos_x -= circle.pos_x <= 0? 0: circle.speed;
      }else if(IsKeyDown(KEY_W)) {
             circle.pos_y -= circle.pos_y <= 0 ? 0 : circle.speed;
      }else if(IsKeyDown(KEY_S)) {
             circle.pos_y += circle.pos_y >= screen.height ? 0 : circle.speed;
      }
 }
 
 int main()
 {
     int screen_width {350};
     int screen_height {200};
     
     Screen screen {screen_width, screen_height, 60, WHITE};
     Circle circle {30, screen.height/2, 25, 4, BLUE};
     Axe axe {screen_width-100, screen.height/2, 30, 30, 8, RED};
     
     InitWindow(screen.width, screen.height, "Moving circle");
     SetTargetFPS(screen.fps);
     
     while(!WindowShouldClose()) {
         BeginDrawing();
         CheckMovement(circle, screen);
         circle.draw();
         axe.draw();
         axe.animate(screen.height);
         Vector2 vec = {circle.pos_x, circle.pos_y};
         Rectangle rec = {axe.pos_x, axe.pos_y, axe.width, axe.height};
         if(CheckCollisionCircleRec(vec, circle.radius, rec )) {
             DrawText("Game Over!!!!!", 40,40,30, BLUE);
         }
         ClearBackground(screen.background);
         EndDrawing();
     }
     
     CloseWindow();
     
     return 0;
     
 }
