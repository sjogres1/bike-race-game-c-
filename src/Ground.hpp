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
		shape.setTextureRect(sf::IntRect(10, 10, 10, 70));
                shape.setPointCount(4);
                shape.setPoint(0, sf::Vector2f(curr->x*Pix_Per_M, curr->y*Pix_Per_M*(-1)+thickness));
 		shape.setPoint(1, sf::Vector2f(v->x*Pix_Per_M, v->y*Pix_Per_M*(-1)+thickness));
 		shape.setPoint(2, sf::Vector2f(v->x*Pix_Per_M, v->y*Pix_Per_M*(-1)));
 		shape.setPoint(3, sf::Vector2f(curr->x*Pix_Per_M, curr->y*Pix_Per_M*(-1)));
 		rt.draw(shape);
            }
	}


	std::list<std::pair<float, float>> generateGroundPoints(float difficulty, int length){
		std::list<std::pair<float, float>> groundPoints;
		std::pair<float, float> lastPoint;
		std::pair<float, float> thisPoint;
		std::pair<float, float> updatedPoint;
		std::pair<float, float> creationVector;
		creationVector.first = 0;
		creationVector.second = 0;
		double randomNumberY;
		float k = 0.001;
		float friction = 0.2;
		float frictionForce;
		srand(time(NULL));
		std::default_random_engine generator;
		generator.seed(time(NULL));
		std::normal_distribution<double> distribution(difficulty, 1.0);
		
		for (int count = -10; count <= 5; ++count){
			thisPoint.first = count;
			thisPoint.second = 0;
			groundPoints.push_back(thisPoint);
		}


		for(int count = 6; count <= length; ++count)
		{	
		    randomNumberY = distribution(generator);
		    lastPoint = groundPoints.back();
		    creationVector.second = creationVector.second + randomNumberY*difficulty;
		    frictionForce = -creationVector.second*friction;
		    creationVector.second = (creationVector.second) - k*(lastPoint.second+20) + frictionForce;
		    updatedPoint.first = count;
		    updatedPoint.second = lastPoint.second + creationVector.second;
		    groundPoints.push_back(updatedPoint);
		}

		return groundPoints;
	}


private:
	std::vector<b2Vec2> vertices;
	b2Body* groundBody;
};
#endif


