#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"



class Game
{
    
public:
    
    //static instance for creating the singleton, checks if we already have an instance; if it does returns exisitng if not creates a new one and returns it.
    static Game* Instance()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    
    //set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    
    void render();
    void update();
    void handleEvents();
    void clean();
    
    //to access the private running variable
    bool running() { return m_bRunning; }
    
    //getter to return the renderer
    SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
    //constructors
    Game() {}
    ~Game() {}
    
    static Game* s_pInstance;
    
    SDL_Window *m_pWindow = nullptr;
    SDL_Renderer *m_pRenderer = nullptr;
    
    GameObject *m_go = nullptr;
    GameObject *m_player = nullptr;
    GameObject *m_enemy = nullptr;
    
    std::vector<GameObject*> m_gameObjects;
    
    int m_currentFrame;
    
    bool m_bRunning = true;
    
};

//create a typedef for Game
typedef Game TheGame;

#endif /* Game_hpp */
