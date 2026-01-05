#pragma once
#include <SDL3/SDL.h>

// Declare global SDL_Window and SDL_Renderer pointers
extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Initializes the e2gine with a window and renderer
bool e2gine_init(const char *title, int width, int height);

// Returns false if the window should close
bool windowShouldClose();

// Clear the screen at the beginning of the frame
void Begin();
// Present the rendered content at the end of the frame
void End();

void CloseE2gine();
