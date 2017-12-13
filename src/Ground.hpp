#ifndef GROUND_HPP
#define GROUND_HPP

#include "Box2DToSFML.hpp"
#include "GameObject.hpp"



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
            float thickness = 1.0f * Pix_Per_M;
            for (auto v = vertices.begin(); v!= vertices.end();)
            {
                auto curr = v;
                if(++v == vertices.end()) break;
                sf::ConvexShape shape;
                shape.setFillColor(sf::Color::Yellow);
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
		std::pair<float, float> coordinatesAtSection;
		std::pair<float, float> firstPair;
		std::pair<float, float> lastPair;
		int dice;
		firstPair.first = -20;
		firstPair.second = -10;
		groundPoints.push_back(firstPair);
		float r;

		for(int section = 0; section <= length; section = section + 5)
		{
			lastPair = groundPoints.back();
			coordinatesAtSection.first = section;
			r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			dice = rand() % 5;
			if (dice == 1){
				coordinatesAtSection.second = lastPair.second + r*difficulty;
			}
			if (dice == 0){
				coordinatesAtSection.second = lastPair.second - r*difficulty;
			}
			groundPoints.push_back(coordinatesAtSection);
		}
		return groundPoints;
	}
	
	
	
private:
	std::vector<b2Vec2> vertices;
	b2Body* groundBody;
};
#endif