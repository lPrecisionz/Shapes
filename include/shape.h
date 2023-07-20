#pragma once

#include "screen.h"

namespace shapes{

struct point{
    double x;
    double y;
};

class shape{
protected:
    point m_point;
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