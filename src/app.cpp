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

    rectangle rectangle1(100, 50);
    square square1(50);
    while (!quit) {
        m_screen.clear();

        rectangle1.update(m_screen);
        square1.update(m_screen);

        m_screen.update();
        if(!m_screen.processEvents(event)){
            quit = true;
        }   
    }

    m_screen.close();
}

} //namespace shapes