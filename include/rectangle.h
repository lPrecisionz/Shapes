/* rectangle.h */
#pragma once

#include "shape.h"

namespace shapes{

class rectangle : public shape{
private:
    int m_side1;
    int m_side2;

public:
    rectangle();
    rectangle(int side1, int side2);
    void updatePosition();
    void update(screen &screen);
    void draw(screen &screen, Uint8 red, Uint8 green, Uint8 blue) const override;
    void draw(screen &screen) const override;
};

} //namespace shapes