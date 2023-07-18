#include "../include/app.h"

namespace shapes{

screen app::m_screen = screen();

void app::run(){

    if(!m_screen.init()){
        return;
    }

    bool quit = false;
    SDL_Event event;

    square square;

    while (!quit) {
        square.draw(m_screen, 0, 255, 0);

        m_screen.update();
        if(!m_screen.processEvents(event)){
            quit = true;
        }   
    }

    m_screen.close();
}

} //namespace shapes