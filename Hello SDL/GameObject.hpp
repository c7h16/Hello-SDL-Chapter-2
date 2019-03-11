//
//  GameObject.hpp
//  Hello SDL
//
//  Created by Mark's Test Computer on 3/10/19.
//  Copyright © 2019 Mark's Computer. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>

class GameObject
{
public:

    void draw() { std::cout << "draw game object" << std::endl; }
    void update() { std::cout << "update game object" << std::endl; }
    void clean() { std::cout << "clean up game object" << std::endl; }

protected:

    int m_xCoord;
    int m_yCoord;

};

#endif /* GameObject_hpp */
