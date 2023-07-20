#include "../include/screen.h"
#include "../include/shape.h"
#include "../include/randomGenerator.h"

namespace shapes{

shape::shape() : m_x(0), m_y(0){
    static randomGenerator rng;
    m_xspeed = getRandomSpeed();
    m_yspeed = getRandomSpeed();
    m_color = getRandomColor();
}

double shape::getRandomSpeed(){
    static randomGenerator rng;
    return rng.getRandomValue(-1, 1);
}

Uint32 shape::getRandomColor(){
    static randomGenerator rng;

    Uint8 red = static_cast<Uint8>(rng.getRandomValue(0, 255));
    Uint8 green = static_cast<Uint8>(rng.getRandomValue(0, 255));
    Uint8 blue = static_cast<Uint8>(rng.getRandomValue(0, 255));

    Uint32 color{0};

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;

    return color;
}

int shape::getScreenX() const{
    return static_cast<int>((m_x + 1) * screen::SCREEN_WIDTH/2);
}

int shape::getScreenY() const{
    return static_cast<int>((m_y + 1) * screen::SCREEN_HEIGHT/2);
}


} //namespace shapes