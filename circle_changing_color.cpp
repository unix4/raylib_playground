 #include <raylib.h>

 int main()
 {
     const int width = 400;
     const int height = 400;
     
     InitWindow(width, height, "Changing color");
     const int color_items = 4;
     Color colors[] = {Color{RED}, Color{BLUE}, Color{GREEN}, Color{YELLOW}};
     
     unsigned int color_counter = 0;
     
     while(!WindowShouldClose()) 
     {
        // color_counter ++;
         BeginDrawing();
         if(IsKeyPressed(KEY_A)) {
             if(color_counter == color_items-1) color_counter = 0;
         else
             color_counter ++;
         }
         
         DrawCircle(200,200,25, colors[color_counter]);
         ClearBackground(WHITE);
         EndDrawing();
     }
     return 0; 
 }
