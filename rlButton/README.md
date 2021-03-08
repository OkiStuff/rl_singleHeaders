# rlButton.h
rlButton is a single-header library that manages button collison and some basic rendering of the buttons

How to install:

`wget https://raw.githubusercontent.com/OkiStuff/rl_singleHeaders/main/rlButton/rlButton.h`

or
`git clone https://github.com/OkiStuff/rl_singleHeaders.git`

an Example is also avaliable for install with

`wget https://raw.githubusercontent.com/OkiStuff/rl_singleHeaders/main/rlButton/example.c`

# Example

```c
#include "raylib.h"
#include "rlButton.h"

int main(void)
{
    InitWindow(800,800,"rlButton Demo");
    rlButton button = {
      (Rectangle){800/2-120,800/2,250,100},
      "Click Me :D"};
    rlMouseCollider mouse = NewMouseCollider(0,0);
    bool buttonPressed = false;
    bool buttonHovered = false;
    bool debugMode = false;
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        mouse = UpdateMouseCollider(mouse);
        if (IsButtonPressed(button, mouse)) buttonPressed = true;
        else if (IsButtonHovered(button, mouse)) buttonHovered = true;
        else 
        {
            buttonPressed = false;
            buttonHovered = false;
        }
        
        if (IsKeyPressed(KEY_ENTER)) debugMode = !debugMode;
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Press Enter to show/hide collision boxes", 10, 10, 20, GRAY);
            DrawButton(button, 50, BLACK);
            if (buttonPressed) DrawText("pressed", 800/2-50, 800/2-150, 32, RED);
            else if (!buttonPressed && buttonHovered) DrawText("hovered", 800/2-50, 800/2-150, 32, RED);
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
```
     
     
     
     
        
