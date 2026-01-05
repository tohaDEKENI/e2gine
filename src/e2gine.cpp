#include "e2gine.hpp"  

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

// Initializes the e2gine with a window and renderer
bool e2gine_init(const char *title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(title, width, height, 0);

    renderer = SDL_CreateRenderer(window,"");
    
    return true;
}

// Returns false if the window should close
bool windowShouldClose(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
    }
    return true;
}

// Clear the screen at the beginning of the frame
void Begin(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}
// Present the rendered content at the end of the frame
void End(){
    SDL_RenderPresent(renderer);
}

// Cleans up and closes the e2gine
void CloseE2gine(){
    if(renderer){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if(window){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}