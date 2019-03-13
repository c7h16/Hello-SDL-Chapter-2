
#ifndef Enemy_hpp
#define Enemy_hpp

#include <iostream>
#include "GameObject.hpp"

class Enemy : public GameObject
{
public:
    
    void load(int x, int y,
              int width, int heigh,
              std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
    
};

#endif /* Enemy_hpp */
