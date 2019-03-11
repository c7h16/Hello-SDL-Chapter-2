
#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "GameObject.hpp"


//this class inherits from the GameObject class
class Player : public GameObject
{
    
public:
    
    void load(int x, int y,
              int width, int heigh,
              std::string textureID);
    
    void draw(SDL_Renderer *pRenderer);
    void update();
    void clean();
    
};

#endif /* Player_hpp */
