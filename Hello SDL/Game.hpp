#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "TextureManager.hpp"

class Game
{
    
public:
    
    //constructors
    Game() {}
    ~Game() {}
    
    //set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    
    void render();
    void update();
    void handleEvents();
    void clean();
    
    //to access the private running variable
    bool running() { return m_bRunning; }

private:
    
    SDL_Window *m_pWindow = nullptr;
    SDL_Renderer *m_pRenderer = nullptr;
    
    int m_currentFrame;
    TextureManager m_textureManager;
    
    bool m_bRunning = true;
    
};

#endif /* Game_hpp */
