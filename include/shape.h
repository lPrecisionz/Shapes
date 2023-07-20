#pragma once

#include "screen.h"

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
    int getScreenX() const;
    int getScreenY() const;
    virtual void draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue) const = 0;
    virtual void draw(screen &screen) const = 0;
};
} //namespace shapes