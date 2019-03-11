//
//  Player.cpp
//  Hello SDL
//
//  Created by Mark's Test Computer on 3/10/19.
//  Copyright © 2019 Mark's Computer. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

void Player::load(int x, int y, int width, int heigh, std::string textureID)
{
    GameObject::load(x, y, width, heigh, textureID);
}

void Player::draw(SDL_Renderer *pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
    m_xCoord -= 1;
}

void Player::clean()
{
    
}
