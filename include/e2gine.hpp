#pragma once
#include <SDL3/SDL.h>

// Define some common colors
#define RED ((SDL_Color){255,0,0,255})
#define GREEN ((SDL_Color){0,255,0,255})
#define BLUE ((SDL_Color){0,0,255,255})
#define BLACK ((SDL_Color){0,0,0,255})
#define WHITE ((SDL_Color){255,255,255,255})
#define GRAY ((SDL_Color){128,128,128,255})
#define YELLOW ((SDL_Color){255,255,0,255})

// Declare global SDL_Window and SDL_Renderer pointers
extern SDL_Window *window;
extern SDL_Renderer *renderer;

// Initializes the e2gine with a window and renderer
bool e2gine_init(const char *title, int width, int height);

// Returns false if the window should close
bool windowShouldClose();

// Clear the screen at the beginning of the frame
void Begin(SDL_Color color = {0,0,0,255});
// Present the rendered content at the end of the frame
void End();

void CloseE2gine();
