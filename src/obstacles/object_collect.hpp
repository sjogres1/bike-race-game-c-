#ifndef OBJECT_COLLECT_HPP
#define OBJECT_COLLECT_HPP

#include <sstream>
#include <Box2D/Box2D.h>
#include "obstacle_coin"



/* This script handles the coin collecting with the bike/car */


class obstacle_coin : public Terrain
{

public:
	obstacle_coin(b2World* world, std::istringstream& s, int type);
	obstacle_coin(b2World* world, float x_, float y_, int type);
	void destroy_coin();
	void take_coin();
	bool coin_destroy();
	void setcoinpos(float x_n, float y_n);
	virtual std::string getName() const = 0;
	std::string getCoinText() const;
	bool coinToTerrain();


protected:
	bool coin_taken;
	float x, y;
	b2World* world;
	b2Body* body;

};

class Coin