
#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>
#include <SDL2/SDL.h>

#include "LoaderParams.hpp"

class GameObject
{
public:

    void virtual draw() = 0;
    void virtual update() = 0;
    void virtual clean() = 0;

protected:
    
    GameObject(const LoaderParams* pParams) { }
    virtual ~GameObject() {}
    
};

#endif /* GameObject_hpp */
