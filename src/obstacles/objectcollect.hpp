#ifndef OBJECT_COLLECT_HPP
#define OBJECT_COLLECT_HPP

#include <sstream>
#include <Box2D/Box2D.h>
#include "terrainobject.hpp"
/*Needs MapobjectVehicle.hpp included



/* This script handles the coin collecting with the bike/car */


class ObjectCollect : public TerrainObject
{

public:
	ObjectCollect(b2World* world, std::istringstream& s, int type);
	ObjectCollect(b2World* world, float x_, float y_, int type);
	void destroyCoin();
	void takeCoin();
	bool coinDestroyed();
	void setCoinPos(float x_n, float y_n);
	virtual std::string getName() const = 0;
	std::string getCoinText() const;
	bool coinToTerrain();


protected:
	bool coin_taken;
	float x, y;
	b2World* world;
	b2Body* body;

};

class CoinListener : public b2ContactListener
{
	void StartContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};