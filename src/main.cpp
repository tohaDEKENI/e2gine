#include <iostream>
#include "e2gine.hpp"

int main(){
    e2gine_init("E2gine Exemple", 800, 600);

    Rectangle rect = {50, 50, 300, 200};
    Vec2 position = {400, 300};
    Vec2 size = {100, 150};

    int x = 500;

    while(windowShouldClose()) {
        
        //x += 1;

        Begin(BLACK);
        DrawRectangleRec(rect, RED);
        DrawRectangleVec(position, size, BLUE);

        DrawLine(10,10 ,500,500,BLUE);
        DrawPoint(500,40,RED);

        DrawCircle(x,50,30,GREEN);
        DrawCircle(x,50,10,RED);
        End();
    }

    CloseE2gine(); 
    return 0;
}

/*
g++ -std=c++17 -Iinclude -o prog src/main.cpp src/e2gine.cpp -lSDL3
*/