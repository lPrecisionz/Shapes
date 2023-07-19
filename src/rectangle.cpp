#include "../include/rectangle.h"

namespace shapes{

rectangle::rectangle(): shape(), m_side1(20), m_side2(50){
}

rectangle::rectangle(int side1, int side2): m_side1(side1), m_side2(side2){
}

void rectangle::updatePosition(Uint32 &deltaTime){
    double deltaSeconds = deltaTime / 1000.0;
    m_x += m_xspeed * deltaSeconds;
    m_y += m_yspeed * deltaSeconds;
    
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    double radius1 = static_cast<double>(m_side1)/ 2.0;
    double radius2 = static_cast<double>(m_side2)/ 2.0;

    bool x_outOfBounds = (screen_x - radius1) < 0 || (screen_x + radius1) >= screen::SCREEN_WIDTH;
    bool y_outOfBounds = (screen_y - radius2) < 0 || (screen_y + radius2) >= screen::SCREEN_HEIGHT;

    if(x_outOfBounds){
        m_xspeed = -m_xspeed;
    }

    if(y_outOfBounds){
        m_yspeed = -m_yspeed;
    }
 }

void rectangle::draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue) const{
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    for(int row = -m_side1; row < m_side1; row++){
        for(int col = -m_side2; col < m_side2; col++){
            int current_x = screen_x + row;
            int current_y = screen_y + col;
            screen.drawPixel(current_x, current_y, red, green, blue);
        }
    }
}

void rectangle::draw(screen &screen) const{
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    for(int row = -m_side1; row < m_side1; row++){
        for(int col = -m_side2; col < m_side2; col++){
            int current_x = screen_x + row;
            int current_y = screen_y + col;
            screen.drawPixel(current_x, current_y, m_color);
        }
    }
}

void rectangle::update(screen &screen, Uint32 &deltaTime){
    this->draw(screen);
    this->updatePosition(deltaTime);
}

} //namespace shapes