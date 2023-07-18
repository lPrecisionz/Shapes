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
    square square4(5);
    square square5(40);
    square square6(23);

    while (!quit) {
        m_screen.clear();

        square1.update(m_screen);
        square2.update(m_screen);
        square3.update(m_screen);
        square4.update(m_screen);
        square5.update(m_screen);
        square6.update(m_screen);

        m_screen.update();
        if(!m_screen.processEvents(event)){
            quit = true;
        }   
    }

    m_screen.close();
}

} //namespace shapes