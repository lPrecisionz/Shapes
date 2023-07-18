#include "../include/square.h"
#include "../include/randomGenerator.h"

namespace shapes{

square::square() : m_x(0), m_y(0), m_side(100){
    m_xspeed = getRandomSpeed();
    m_yspeed = getRandomSpeed();
    m_color = getRandomColor();
}

square::square(int side) : m_x(0), m_y(0), m_side(side){
    m_xspeed = getRandomSpeed();
    m_yspeed = getRandomSpeed();
    m_color = getRandomColor();
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

void square::draw(screen &screen){
    int screen_x = getScreenX();
    int screen_y = getScreenY();

    for(int row = -m_side; row < m_side; row++){
        for(int col = -m_side; col < m_side; col++){
            int current_x = screen_x + row;
            int current_y = screen_y + col;
            screen.drawPixel(current_x, current_y, m_color);
        }
    }
}

double square::getRandomSpeed(){
    static randomGenerator rng;
    return rng.getRandomValue(-0.05, 0.05) * 0.5;
}

Uint32 square::getRandomColor(){
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

int square::getScreenX(){
    return static_cast<int>((m_x + 1) * screen::SCREEN_WIDTH/2);
}

int square::getScreenY(){
    return static_cast<int>((m_y + 1) * screen::SCREEN_HEIGHT/2);
}

} //namespace shapes