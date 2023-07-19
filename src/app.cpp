#include "../include/app.h"

namespace shapes{

screen app::m_screen = screen();

void app::run(){
    static randomGenerator rng;

    if(!m_screen.init()){
        return;
    }

    bool quit = false;
    SDL_Event event;

    rectangle rectangle1(50, 100);
    square square1(50);

    Uint32 previousFrameTime = SDL_GetTicks();
    const int targetFrameTime = 1000 / 45;

    while (!quit) {
        m_screen.clear();
        Uint32 currentFrameTime = SDL_GetTicks();
        Uint32 deltaTime = currentFrameTime - previousFrameTime;

        rectangle1.update(m_screen, deltaTime);
        square1.update(m_screen, deltaTime);

        m_screen.update();

        Uint32 frameTime = SDL_GetTicks() - currentFrameTime;

        if(frameTime < targetFrameTime){
            SDL_Delay(targetFrameTime - frameTime);
        }

        if(!m_screen.processEvents(event)){
            quit = true;
        } 

        previousFrameTime = currentFrameTime;
    }

    m_screen.close();
}

} //namespace shapes