
#include "Player.hpp"
#include "SDLGameObject.hpp"


Player::Player(const LoaderParams* pParams) :
SDLGameObject(pParams)
{
    
    
}

void Player::draw()
{
    //use the draw function from SDLGameObject
    SDLGameObject::draw();
    
}

void Player::update()
{
    m_xCoord -= 1;
    m_currentFrame = int( ( (SDL_GetTicks() / 100) / 6)  );
}

void Player::clean()
{
    
    
}
