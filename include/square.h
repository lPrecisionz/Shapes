/* square.h */
#pragma once

#include "shape.h"

namespace shapes{

class square : public shape{
private:
    int m_side;

public:
    square();
    square(int side);
    void draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue) const override;
    void draw(screen &screen) const override;
    void updatePosition(Uint32 &deltaTime);
    void update(screen &screen, Uint32 &deltaTime);
};

} //namespace shapes