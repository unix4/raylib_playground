#include "raylib.h"
#include <string>
 
 class Circle {
     public: 
        int pos_x;
        int pos_y;
        int radius;
        Color color {BLUE};
 };
 
 void CheckMovement(Circle &circle, int speed) {
      if(IsKeyPressed(KEY_D)) {
             circle.pos_x += speed;
      }else if(IsKeyPressed(KEY_A)) {
             circle.pos_x -= speed;
      }else if(IsKeyPressed(KEY_W)) {
             circle.pos_y -= speed;
      }else if(IsKeyPressed(KEY_S)) {
             circle.pos_y += speed;
      }
 }
 
 void DrawCoordinates(const Circle &circle) {
     DrawText(TextFormat("x : %i", circle.pos_x), 5,20 ,15,WHITE);
     DrawText(TextFormat("y : %i", circle.pos_y), 5,40, 15, WHITE);
 }    
 

 int main()
 {
     int width {350};
     int height {200};
     Circle circle {width / 2,height / 2,25};
     const int speed {4};
     
     InitWindow(width, height, "Moving circle");
     
     
     while(!WindowShouldClose()) {
         BeginDrawing();
         DrawCoordinates(circle);
         CheckMovement(circle, speed);
         DrawCircle(circle.pos_x, circle.pos_y, circle.radius, circle.color);
         ClearBackground(RED);
         EndDrawing();
     }
     
     CloseWindow();
     
     return 0;
     
 }
