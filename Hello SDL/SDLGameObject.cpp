
#include "SDLGameObject.hpp"

void SDLGameObject::draw()
{
    TextureManager::Instance() -> drawFrame(m_textureID, m_xCoord, m_yCoord, m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance() -> getRenderer());
    
}
