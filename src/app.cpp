#include "../include/app.h"
#include <time.h>

namespace shapes{

screen app::m_screen = screen();

void app::run(){
    srand(time(NULL));

    if(!m_screen.init()){
        return;
    }

    bool quit = false;
    SDL_Event event;

    square square1(50);
    square square2(10);
    square square3(28);
    square square4(90);
    square square5(70);

    while (!quit) {
        m_screen.clear();

        square1.draw(m_screen, 15, 255, 27);
        square1.update();
        square2.draw(m_screen, 255, 255, 255);
        square2.update();
        square3.draw(m_screen, 19, 0, 154);
        square3.update();

        m_screen.update();
        if(!m_screen.processEvents(event)){
            quit = true;
        }   
    }

    m_screen.close();
}

} //namespace shapes