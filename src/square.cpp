#include "../include/square.h"
#include <stdlib.h>

namespace shapes{

square::square() : m_x(0), m_y(0), m_side(100){
    m_xspeed = (rand()*0.05)/RAND_MAX;
    m_yspeed = (rand()*0.01)/RAND_MAX;
}

square::square(int side) : m_x(0), m_y(0), m_side(side){
    m_xspeed = (rand()*0.05)/RAND_MAX;
    m_yspeed = (rand()*0.01)/RAND_MAX;
}

void square::update(){
    m_x += m_xspeed;
    m_y += m_yspeed;
    
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

void square::draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue){
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

int square::getScreenX(){
    return static_cast<int>((m_x + 1) * screen::SCREEN_WIDTH/2);
}

int square::getScreenY(){
    return static_cast<int>((m_y + 1) * screen::SCREEN_HEIGHT/2);
}

} //namespace shapes