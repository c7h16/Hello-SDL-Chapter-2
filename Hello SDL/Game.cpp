
#include <iostream>
#include "Game.hpp"

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
    
    
    //use the texture manager to load an image
    m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
    
    
    //set the while loop to true
    m_bRunning = true;
    
    
    return true;
};


void Game::render()
{
    // "clear" the renderer to the selected color
    SDL_RenderClear(m_pRenderer);
    
    //use the texture manger to draw an individual image
    m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
    
    //use the texture manager drawframe funciton to draw an animated frame
    m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    
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
    //new update function based on the new texture manager the source retangle is calculated inside the draw function
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 6 ) );
}
