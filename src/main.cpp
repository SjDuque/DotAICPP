#include "raylib.h"
// #include "dot.hpp"
#include "vpoint.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Dots");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    //---------------------------------------------------------------------------------------
    VPoint v(400, 225);
    SetTargetFPS(120);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawCircle(v.x, v.y, 5, RED);
            v += VPoint::random()*5;
            // d.draw();
            // d.update();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}