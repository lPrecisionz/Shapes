#include "../include/square.h"
#include "../include/randomGenerator.h"

namespace shapes{

square::square() : shape(), m_side(100){
}

square::square(int side) : shape(), m_side(side){
}

void square::updatePosition(Uint32 &deltaTime){
    double deltaSeconds = deltaTime / 1000.0;
    m_x += m_xspeed * deltaSeconds;
    m_y += m_yspeed * deltaSeconds;
    
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    double radius = static_cast<double>(m_side)/ 2.0;

    bool x_outOfBounds = (screen_x - radius) < 0 || (screen_x + radius) >= screen::SCREEN_WIDTH;
    bool y_outOfBounds = (screen_y - radius) < 0 || (screen_y + radius) >= screen::SCREEN_HEIGHT;

    if(x_outOfBounds){
        m_xspeed = -m_xspeed;
    }

    if(y_outOfBounds){
        m_yspeed = -m_yspeed;
    }
 }

void square::draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue) const{
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    for(int row = -m_side; row < m_side; row++){
        for(int col = -m_side; col < m_side; col++){
            int current_x = screen_x + row;
            int current_y = screen_y + col;
            screen.drawPixel(current_x, current_y, red, green, blue);
        }
    }
}

void square::draw(screen &screen) const{
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    for(int row = -m_side; row < m_side; row++){
        for(int col = -m_side; col < m_side; col++){
            int current_x = screen_x + row;
            int current_y = screen_y + col;
            screen.drawPixel(current_x, current_y, m_color);
        }
    }
}

void square::update(screen &screen, Uint32 &deltaTime){
    this->updatePosition(deltaTime);
    this->draw(screen);
}

} //namespace shapes