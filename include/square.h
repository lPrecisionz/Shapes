/* square.h */
#pragma once

#include "screen.h"

namespace shapes{

class square{
private:
    int m_side;
    double m_x;
    double m_y;

public:
    square();
    void draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue);
};

} //namespace shapes