
#include <iostream>
#include "Game.hpp"

//define the static instance of Game
Game* Game::s_pInstance = 0;

//game window initialzation function
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    std::cout << "Initializing the window and renderer ..." << std::endl;
    
    //initialize window and report error if unseccessful
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        std::cout << "SDL did not initialize. Error code: " << SDL_GetError() << std::endl;
    }
    
    //create a window and report if unsuccessfull
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    
    if ( m_pWindow == nullptr )
    {
        std::cout << "SDL could not create a window. Error code: " << SDL_GetError() << std::endl;
    }
    
    //create a renderer and report if unsuccessful
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    
    if ( m_pRenderer == nullptr )
    {
        std::cout << "SDL could not create a renderer. Error code: " << SDL_GetError() << std::endl;
    }
    
    //set the color of the renderer
    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
    
    //use textermanager as a Singleton to load an image.
   if ( !theTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer) )
   {
       return false;
   }
    
    //declaring new objects
    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
    
    //set the while loop to true
    m_bRunning = true;
    
    
    return true;
};


void Game::render()
{
    // "clear" the renderer to the selected color
    SDL_RenderClear(m_pRenderer);
    
    //loop through the object and draw them
    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i] -> draw(m_pRenderer);
    }

    
    //draw to the screen
    SDL_RenderPresent(m_pRenderer);
    
};

void Game::clean()
{
    std::cout << "Quiting and cleaning up the game ... " << std::endl;
    //destory the window
    SDL_DestroyWindow(m_pWindow);
    
    //destory the renderer
    SDL_DestroyRenderer(m_pRenderer);
    
    //uninitialize SDL
    SDL_Quit();
    
};

void Game::handleEvents()
{
    SDL_Event windowEvent;
    
    if (SDL_PollEvent( &windowEvent ) )
    {
        switch (windowEvent.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
                
            default:
                break;
        }
    }
    
};

void Game::update()
{
    //loop through the game objects and update
    //TODO: what is size_type funciton in vectors?
    
    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i] -> update();
    }
}
