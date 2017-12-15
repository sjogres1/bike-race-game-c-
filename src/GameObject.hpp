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


// Gameobject class that is used with other classes
class GameObject
{
public:
	// virtual functions that are used in many other classes
    virtual void update() {};
    virtual ~GameObject() {};
    virtual void render(sf::RenderTarget & rt) const = 0;
    
};
	
#endif