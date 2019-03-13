
#include "Enemy.hpp"
#include "SDLGameObject.hpp"

Enemy::Enemy(const LoaderParams* pParams) :
SDLGameObject(pParams)
{
    
    
}

void Enemy::draw()
{
    SDLGameObject::draw();
    
}


void Enemy::update()
{
    m_yCoord += 1;
    m_xCoord += 1;
    m_currentFrame = int( ( (SDL_GetTicks() / 100) % 6) );
}

void Enemy::clean()
{
    
}
