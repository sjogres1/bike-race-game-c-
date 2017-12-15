//
//  GameObject.hpp
//  Hillside1
//

#ifndef Hillside1_GameObject_hpp
#define Hillside1_GameObject_hpp

#include <iostream>
#include <iomanip>
#include <list>
#include "Box2DToSFML.hpp"



class GameObject
{
public:
    virtual void update() {};
    virtual ~GameObject() {};
    virtual void render(sf::RenderTarget & rt) const = 0;
    
};
	
#endif