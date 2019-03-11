//
//  Player.hpp
//  Hello SDL
//
//  Created by Mark's Test Computer on 3/10/19.
//  Copyright © 2019 Mark's Computer. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "GameObject.hpp"


//this class inherits from the GameObject class
class Player : public GameObject
{
    
public:
    
    void draw()
    {
        GameObject::draw();
        std::cout << "draw player" << std::endl;
    }
    
    void update()
    {
        GameObject::update();
        std::cout << "update player" << std::endl;
        m_xCoord = 10;
        m_yCoord = 20;
    }
    
    void clean()
    {
        GameObject::clean();
        std::cout << "cleanup player" << std::endl;
    }
    
    
};

#endif /* Player_hpp */
