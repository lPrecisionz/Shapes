/* screen.h */

#pragma once

#include <SDL.h>

namespace shapes{

class screen{
public:
    static const int SCREEN_WIDTH{800};
    static const int SCREEN_HEIGHT{600};

public:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32* m_buffer;

public:
    screen();
    bool init();
    void update();
    void drawPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void drawPixel(int x, int y, Uint32 color);
    bool processEvents(SDL_Event &event);
    void clear();
    void close();
};

} //namespace shapes