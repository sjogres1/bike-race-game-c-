#ifndef GROUND_HPP
#define GROUND_HPP

#include "Box2DToSFML.hpp"
#include "GameObject.hpp"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>




class Ground : public GameObject
{
public:
    
        Ground() { }

	void drawMap(b2World* world, std::list <std::pair <float, float>> mapPoints){
		b2BodyDef ground;
		ground.type = b2_staticBody;
		groundBody = world->CreateBody(&ground);

		
		for (auto const& pair : mapPoints) {
			vertices.push_back(b2Vec2(pair.first, pair.second));
		}


		b2FixtureDef fd;
		fd.density = 1.0f;
		fd.friction = 0.6f;
		
		for (auto v = vertices.begin(); v != vertices.end();)
		{
			auto curr = v;
			if (++v == vertices.end()) break;
			b2PolygonShape edgeShape;
			edgeShape.SetAsEdge(*curr, *v);
			fd.shape = &edgeShape;
			groundBody->CreateFixture(&fd);
		}
	}
        
        void render(sf::RenderTarget &rt) const {
	    float thickness = 2.0f * Pix_Per_M;
	    sf::Texture texture;
	    texture.loadFromFile("grass.png");
            for (auto v = vertices.begin(); v!= vertices.end();)
            {
                auto curr = v;
                if(++v == vertices.end()) break;
		sf::ConvexShape shape;

		shape.setTexture(&texture);
		shape.setTextureRect(sf::IntRect(10, 10, 100, 100));
                shape.setPointCount(4);
                shape.setPoint(0, sf::Vector2f(curr->x*Pix_Per_M, curr->y*Pix_Per_M*(-1)+thickness));
 		shape.setPoint(1, sf::Vector2f(v->x*Pix_Per_M, v->y*Pix_Per_M*(-1)+thickness));
 		shape.setPoint(2, sf::Vector2f(v->x*Pix_Per_M, v->y*Pix_Per_M*(-1)));
 		shape.setPoint(3, sf::Vector2f(curr->x*Pix_Per_M, curr->y*Pix_Per_M*(-1)));
 		rt.draw(shape);
            }
        }

	std::list<std::pair<float, float>> generateGroundPoints(int difficulty, int length){
		std::list<std::pair<float, float>> groundPoints;
		std::pair<float, float> firstPoint;
		std::pair<float, float> lastPoint;
		firstPoint.first = -20;
		firstPoint.second = -20;
		groundPoints.push_back(firstPoint);
		firstPoint.first = 0;
		firstPoint.second = -20;
		groundPoints.push_back(firstPoint);
		float r;
		std::pair<float, float> updatedPoint;
		std::pair<float, float> creationVector;
		creationVector.first = 0;
		creationVector.second = 0;
		float randomNumberX;
		float randomNumberY;
		int min = -1;
		int max = 1;
		difficulty = 1;

		for(int count = 0; count <= length; ++count)
		{
		    r = (1- (float)rand() / RAND_MAX) * 2;		
		    randomNumberX = 1 - 2*((float) (rand()) / (RAND_MAX));//2 - rand () % 5;
		    randomNumberY = 1 - 2*((float) (rand()) / (RAND_MAX));//2 - rand () % 5;
		    lastPoint = groundPoints.back();
		    creationVector.first = creationVector.first + randomNumberX*difficulty;
		    creationVector.second = creationVector.second + randomNumberY*difficulty;
		    updatedPoint.first = lastPoint.first + creationVector.first;
		    updatedPoint.second = lastPoint.second + creationVector.second;
		    if (updatedPoint.first < lastPoint.first){
			updatedPoint.first = lastPoint.first + 1;
			}
		    groundPoints.push_back(updatedPoint);
		}
		return groundPoints;
	}


private:
	std::vector<b2Vec2> vertices;
	b2Body* groundBody;
};
#endif