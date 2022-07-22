 #include "raylib.h"

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
 
 int main(){
     int width {350};
     int height {200};
     Circle circle {25,25,25};
     const int speed {4};
     
     InitWindow(width, height, "Moving circle");
     
     while(!WindowShouldClose()) {
         BeginDrawing();
         CheckMovement(circle, speed);
         DrawCircle(circle.pos_x, circle.pos_y, circle.radius, circle.color);
         ClearBackground(RED);
         EndDrawing();
     }
     
     return 0;
 }
