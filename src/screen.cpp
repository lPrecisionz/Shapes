#include "../include/screen.h"

namespace shapes{

screen::screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL){
}

bool screen::init(){
    m_window = SDL_CreateWindow("Shapes", 
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if(m_window == NULL){
        SDL_Log("Couln't create window: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window,
        -1,
        SDL_RENDERER_PRESENTVSYNC);

    if(m_renderer == NULL){
        SDL_Log("Couldn't create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_texture = SDL_CreateTexture(m_renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_STATIC,
    SCREEN_WIDTH,
    SCREEN_HEIGHT);

    if(m_texture == NULL){
        SDL_Log("Couldn't create texture: %s", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
        SDL_Quit();
    }

    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    return true;
}


void screen::update(){
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void screen::drawPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    bool outOfBounds = x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT;
    if(outOfBounds){
        return;
    }

    Uint32 color{0};

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF; //alpha (opaque)

    m_buffer[y * SCREEN_WIDTH + x] = color;
}

void screen::drawPixel(int x, int y, Uint32 color){
    bool outOfBounds = x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT;
    if(outOfBounds){
        return;
    }

    m_buffer[y * SCREEN_WIDTH + x] = color;
}


bool screen::processEvents(SDL_Event &event){
    while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
    }
    return true;
}

void screen::clear(){
    SDL_memset(m_buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
}

void screen::close(){
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}


} //namespace shapes