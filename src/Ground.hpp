#ifndef GROUND_HPP
#define GROUND_HPP

#include "Box2DToSFML.hpp"
#include "GameObject.hpp"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <ctime>




class Ground : public GameObject
{
public:
    
    Ground();

	void drawMap(b2World* world, std::list <std::pair <float, float>> mapPoints);


    void render(sf::RenderTarget &rt) const ;

	std::list<std::pair<float, float>> generateGroundPoints(float difficulty, int length);

private:
	std::vector<b2Vec2> vertices;
	b2Body* groundBody;
};
#endif


