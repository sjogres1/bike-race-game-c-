#ifndef OBSTACLE_COIN_HPP
#define OBSTACLE_COIN_HPP

#include "objectcollect.cpp"

/* Obstacle coin class. Tells all the information about coins that are on the map */


class ObstacleCoin : public ObjectCollect
{

public:
	ObstacleCoin(b2World* world, std::istringstream& s);
	ObstacleCoin(b2World* world, float x, float y);

	std::string getName() const;

	void init();

	void draw(sf::RenderTarget &rt, sf::RenderStates states) const;

	b2Shape& getShape();

private:
	b2CircleShape myShape;
	sf::CircleShape coin;
	sf::Texture CoinTexture;
	float radius;
	
};

#endif