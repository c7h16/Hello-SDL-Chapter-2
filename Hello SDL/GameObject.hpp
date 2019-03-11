
#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>
#include <SDL2/SDL.h>

class GameObject
{
public:

    void load(int x, int y,
              int width, int height,
              std::string textureID);
    
    void draw( SDL_Renderer *pRenderer );
    void update();
    void clean();

protected:
    
    std::string m_textureID;
    
    int m_currentFrame;
    int m_currentRow;
    
    int m_xCoord;
    int m_yCoord;
    
    int m_width;
    int m_height;

};

#endif /* GameObject_hpp */
