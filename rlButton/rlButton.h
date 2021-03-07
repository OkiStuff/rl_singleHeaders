/*
MIT License

Copyright (c) 2021 OkiStuff

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Developed By Okistuff
Requires Raylib

This is a single-header library that handles button collison and some basic rendering

Example: https://github.com/OkiStuff/rl_singleHeaders/tree/main/rlButton
*/
#pragma once
#include "raylib.h" // Rendering Framework
#include <stdbool.h> // Required for bool,
//(??, sometimes its not needed but sometimes bools wont work without it. its weird, lets just include to be safe)
#define RL_BUTTON_MOUSE_COLLIDER_SIZE_DEFAULT 60


// Defining


// Mouse Collison
typedef Rectangle rlMouseCollider;

// Button Object
typedef struct rlButton
{
    Rectangle box;
    char *buttonText;
} rlButton;

/* Create a mouse collider
set width & height to 0 or RL_BUTTON_MOUSE_COLLIDER_SIZE_DEFAULT if you want to use the default collider size (60,60)
*/
rlMouseCollider NewMouseCollider(int width, int height);
// Updates the mouse collider
void UpdateMouseCollider(rlMouseCollider collider);
/* Returns true if the passed rlButton has been pressed by the passed rlMouseCollider
else, returns false
*/
bool IsButtonPressed(rlButton button, rlMouseCollider collider);
/* Returns true if the passed rlButton is being hovered over by the passed rlMouseCollider
else, returns false
*/
bool IsButtonHovered(rlButton button, rlMouseCollider collider);
/* Renders the passed rlButton with text,
only use this if you arent going to be using the button with a sprite or rendering it a different way*/
void DrawButton(rlButton button, int posX, int posY, int fontSize, Color tint);
// Render the collison boxes of passed rlButton
void rlButtonDrawDebug(rlButton button);
// Render the collison boxes of passed rlMouseCollider
void rlMouseColliderDrawDebug(rlMouseCollider collider);

// Implemention

rlMouseCollider NewMouseCollider(int width, int height)
{
    rlMouseCollider temp;
    // Initalize the box that is rendered if rlButtonDebugMode is enabled
    if (width == 0 && height == 0) temp = { 0, 0, 60, 60};
    else temp = {0, 0, width, height};;
    return temp;
}

void UpdateMouseCollider(rlMouseCollider collider)
{
    collider.x = GetMouseX() - collider.width/2;
    collider.y = GetMouseY() - collider.height/2;
}

bool IsButtonPressed(rlButton button, rlMouseCollider collider)
{
    if (CheckCollisionRecs(button.box, collider) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return true;
    return false;
}

bool IsButtonHovered(rlButton button, rlMouseCollider collider)
{
    // Check if mouse collider is colliding and the mouse is not being pressed
    if (CheckCollisionRecs(button.box, collider) && !IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return true;
    return false;
}

void DrawButton(rlButton button, int posX, int posY, int fontSize, Color tint)
{
    DrawText(button.buttonText, posX, posY, fontSize, tint);
}

void rlButtonDrawDebug(rlButton button)
{
    DrawRectangle(button.box.x, button.box.y, button.box.width, button.box.height, YELLOW);
}

void rlMouseColliderDrawDebug(rlMouseCollider collider)
{
    DrawRectangle(collider.x, collider.y, collider.width, collider.height, BLUE);
}


