
#ifndef Enemy_hpp
#define Enemy_hpp

#include "GameObject.hpp"
#include "SDLGameObject.hpp"


class Enemy : public SDLGameObject
{

public:
    
    Enemy(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
};

#endif /* Enemy_hpp */
