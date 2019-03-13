
#ifndef SDLGameObject_hpp
#define SDLGameObject_hpp

#include <string>

#include "GameObject.hpp"
#include "LoaderParams.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"


class SDLGameObject : public GameObject
{

public:
    
    SDLGameObject(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
protected:
    
    int m_xCoord;
    int m_yCoord;
    
    int m_width;
    int m_height;
    
    int m_currentRow;
    int m_currentFrame;
    
    std::string m_textureID;
    
};

#endif /* SDLGameObject_hpp */
