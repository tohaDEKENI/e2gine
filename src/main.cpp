#include <iostream>
#include "e2gine.hpp"

int main(){
    e2gine_init("E2gine Window", 800, 600);

    while(windowShouldClose()) {

        Begin(YELLOW);

        End();
    }

    CloseE2gine(); 
    return 0;
}

/*
g++ -std=c++17 -Iinclude -o prog src/main.cpp src/e2gine.cpp -lSDL3
*/