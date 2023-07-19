/* square.h */
#pragma once

#include "screen.h"
#include "shape.h"

namespace shapes{

class square : public shape{
private:
    int m_side;

public:
    square();
    square(int side);
    void draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue);
    void draw(screen &screen);
    void updatePosition();
    void update(screen &screen);
};

} //namespace shapes