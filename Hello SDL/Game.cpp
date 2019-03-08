
#include <iostream>
#include "Game.hpp"

//game window initialzation function
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
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
    
    //use SDL_Image IMG_Load rather than the bmp
    SDL_Surface *pTempSurface = IMG_Load("Assets/animate-alpha.png");
    
    //create a texture with the surface/image just loaded
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    
    //free the surface to release the memory
    SDL_FreeSurface(pTempSurface);
    
    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;
    
    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
    
    //set the while loop to true
    m_bRunning = true;
    
    
    return true;
};


void Game::render()
{
    // "clear" the renderer to the selected color
    SDL_RenderClear(m_pRenderer);
    
    //push texture to the renderer
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    
   // SDL_RenderCopyEx(m_pRenderer, m_pTexture,
   //                  &m_sourceRectangle, &m_destinationRectangle,
    //                 NULL, NULL, SDL_FLIP_HORIZONTAL);
    
    //draw to the screen
    SDL_RenderPresent(m_pRenderer);
    
};

void Game::clean()
{
    std::cout << "Cleaning the game" << std::endl;
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
    m_sourceRectangle.x = 128 * int ( ( (SDL_GetTicks() / 100 ) % 6 ) );
    
}
