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

    square square1(50);
    square square2(10);
    square square3(28);

    while (!quit) {
        m_screen.clear();

        square1.draw(m_screen);
        square1.update();
        square2.draw(m_screen, 255, 0, 255);
        square2.update();
        square3.draw(m_screen);
        square3.update();

        m_screen.update();
        if(!m_screen.processEvents(event)){
            quit = true;
        }   
    }

    m_screen.close();
}

} //namespace shapes