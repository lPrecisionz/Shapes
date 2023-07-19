#pragma once

#include <SDL.h>

namespace shapes{

class shape{
protected:
    double m_x;
    double m_y;
    double m_xspeed;
    double m_yspeed;
    Uint32 m_color;

public:
    shape();
    double getRandomSpeed();
    Uint32 getRandomColor();
    int getScreenX();
    int getScreenY();
};
} //namespace shapes