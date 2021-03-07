# rlButton.h
rlButton is a single-header library that manages button collison and some basic rendering of the buttons

# Example

```c
#include "raylib.h"
#include "rlButton.h"

int main(void)
{
    InitWindow(800,800,"rlButton Demo");
    rlButton button = {
      (Rectangle){50,50,50,50},
      "Click Me :D"};
    rlMouseCollider mouse = NewMouseCollider(0,0);
    bool buttonPressed, buttonHovered, debugMode = false;
    
    SetTargetFPS(60);
    if (!WindowShouldClose())
    {
        UpdateMouseCollider(mouse);
        if (IsButtonPressed(button, mouse)) buttonPressed = true;
        else if (IsButtonHovered(button, mouse)) buttonHovered = true;
        else buttonPressed, buttonHovered = false;
        
        if (IsKeyDown(KEY_ENTER)) debugMode = !debugMode;
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawButton(button, 12, BLACK);
            if (buttonPressed && !buttonHovered) DrawText("pressed", 800/2, 800/2, 24, RED);
            if (!buttonPressed && buttonHovered) DrawText("hovered", 800/2, 800/2, 24, RED);
            if (debugMode) 
            {
              rlButtonDrawDebug(button);
              rlMouseColliderDrawDebug(mouse);
            }
        EndDrawing();
     }
     CloseWindow();
     return 0;
}
     
     
     
     
        
