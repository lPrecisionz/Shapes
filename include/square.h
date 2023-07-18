/* square.h */
#pragma once

#include "screen.h"

namespace shapes{

class square{
private:
    int m_side;
    double m_x;
    double m_y;
    double m_xspeed;
    double m_yspeed;
    Uint32 m_color;

public:
    square();
    square(int side);
    void draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue);
    void draw(screen &screen);
    void updatePosition();
    void update(screen &screen);
    double getRandomSpeed();
    Uint32 getRandomColor();
    int getScreenX(); 
    int getScreenY();
};

} //namespace shapes