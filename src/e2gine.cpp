#include "e2gine.hpp"  
#include <cmath>

// Define global SDL_Window and SDL_Renderer pointers
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
void Begin(SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
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

// Draws a filled rectangle on the screen
void DrawRectangleRec(Rectangle rect, SDL_Color color){
    SDL_FRect sdlRect = {rect.x, rect.y, rect.width, rect.height};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &sdlRect);
}

void DrawRectangleVec(Vec2 position, Vec2 size, SDL_Color color){
    SDL_FRect sdlRect = {position.x, position.y, size.x, size.y};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &sdlRect);
}

void DrawRectangle(float x, float y, float width, float height, SDL_Color color){
    SDL_FRect sdlRect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &sdlRect);
}


// Draw line on the screen
void DrawLine(float x1, float y1, float x2, float y2,SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderLine(renderer, x1, y1, x2, y2);
}

void DrawLineVec(Vec2 start,Vec2 end,SDL_Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderLine(renderer, start.x,start.y,end.x,end.y);
}

// Draw points
void DrawPoint(float x ,float y,SDL_Color color){
    SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
    SDL_RenderPoint(renderer,x,y);
}

void DrawPointVec(Vec2 point,SDL_Color color){
    SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
    SDL_RenderPoint(renderer,point.x,point.y);
}

// Draw circle
void DrawCircle(int cx, int cy, int radius,SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
    for (int dy = -radius; dy <= radius; dy++) {
        int dx = (int)sqrt(radius * radius - dy * dy);
        SDL_RenderLine(renderer,
                       cx - dx, cy + dy,
                       cx + dx, cy + dy);
    }
}

void DrawCircleVec(Vec2 pos, int radius,SDL_Color color){
    SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
    for (int dy = -radius; dy <= radius; dy++) {
        int dx = (int)sqrt(radius * radius - dy * dy);
        SDL_RenderLine(renderer,
                       pos.x - dx, pos.y + dy,
                       pos.x + dx, pos.y + dy);
    }
}

void DrawCircleVec3(Vec3 props ,SDL_Color color){
    SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
    for (int dy = -props.z; dy <= props.z; dy++) {
        int dx = (int)sqrt(props.z * props.z - dy * dy);
        SDL_RenderLine(renderer,
                       props.x - dx, props.y + dy,
                       props.x + dx, props.y + dy);
    }
}

