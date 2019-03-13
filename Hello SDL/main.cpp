#include "Game.hpp"
// #include <iostream>

//create a Game object
//Game *g_game = nullptr;


int main(int argc, const char * argv[])
{

    //g_game = new Game();
    //g_game -> init("Chapter 2", 100, 100, 640, 480, 0);
    
    std::cout << "Game attempting to initialize" << std::endl;
    if (TheGame::Instance() -> init("Chapter 4", 100, 100, 640, 480, false))
    {
        std::cout << "The Game initialized successfully!" << std::endl;
    
        while (TheGame::Instance() -> running())
        {
        
            TheGame::Instance() -> handleEvents();
            TheGame::Instance() -> update();
            TheGame::Instance() -> render();
        
        //temporary funtion to delay the animations
        SDL_Delay(10);
        }
    } else
    {
        std::cout << "The game Failed to initialize with Error: " << SDL_GetError() << std::endl;
        return -1;
        
    }
    
    std::cout << "The Game is closing." << std::endl;
    TheGame::Instance() -> clean();
    
    return 0;
}
