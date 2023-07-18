#include <iostream>
#include <SDL.h>
#include "../include/screen.h"
#include "../include/square.h"
using namespace shapes;

int main(int, char**){
    screen screen;
    screen.init();
    bool quit = false;
    SDL_Event event;

    square square;

    while (!quit) {
        square.draw(screen, 0, 255, 0);

        screen.update();
        if(!screen.processEvents(event)){
            quit = true;
        }
    }

    screen.close();
    return 0;
}