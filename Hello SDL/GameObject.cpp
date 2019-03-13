
#include "GameObject.hpp"
#include "TextureManager.hpp"

void GameObject::load(int x, int y,
          int width, int height,
          std::string textureID)
{
    //setting all the memeber functions with the parameters of the function call
    m_xCoord = x;
    m_yCoord = y;
    
    m_width = width;
    m_height = height;
    m_textureID = textureID;
    
    //just using 1 for these two for now will update later (I DONT KNOW HOW THOUGH!!)
    m_currentRow = 1;
    m_currentFrame = 1;
}

//use member variable items in the Texture Manager draw frame instance
void GameObject::draw( SDL_Renderer *pRenderer )
{
    TextureManager::Instance() -> drawFrame(m_textureID,
                                            m_xCoord, m_yCoord,
                                            m_width, m_height,
                                            m_currentRow,
                                            m_currentFrame,
                                            pRenderer);
}

void GameObject::update()
{
    m_xCoord += 1;
}

void GameObject::clean()
{
    
}
