#include "../include/square.h"

namespace shapes{

square::square() : m_x(0), m_y(0), m_side(100){
}

void square::draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue){
    int screen_x = static_cast<int>((m_x + 1) * screen::SCREEN_WIDTH/2);
    int screen_y = static_cast<int>((m_y + 1) * screen::SCREEN_HEIGHT/2);

    for(int row = -m_side; row < m_side; row++){
        for(int col = -m_side; col < m_side; col++){
            int current_x = screen_x + row;
            int current_y = screen_y + col;
            screen.drawPixel(current_x, current_y, red, green, blue);
        }
    }
}

} //namespace shapes