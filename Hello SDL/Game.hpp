#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
    
    SDL_Texture * m_pTexture = nullptr;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
    
    bool m_bRunning = true;
    
};

#endif /* Game_hpp */
