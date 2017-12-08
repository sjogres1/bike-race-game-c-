#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "terrainobject.hpp"
//#include "MapObjectVehicle.hpp"
#include "objectcollect.hpp"
#include "obstaclecoin.hpp"
//#include "MapObjectGoal.hpp"
//#include "MapObjectBackground.hpp"

class Terrain
{

protected:
	//sf::Vector2f playerStartPoint;

	std::vector<TerrainObject*> objects*
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, std::string> texturesfname;

public:

	Terrain();

	const std::vector<TerrainObject*>* getObjects() const;

	std::map<std::string, sf::Texture*>& getTextures();

	const std::map<std::string, std::string>* getTextureFilenames() const;

	~Terrain();

	sf::Texture* loadTexture(std::string id, std::string fname = "");

	Terrain(std::string terrainfname);

	b2World* getWorld();

	std::string getTerrainFname();

	void saveTerrain(std::string filename);

	/* sf::Vector2f getPlayerStartPoint() const {
    return playerStartPoint; */

    void addObject(TerrainObject* t);

    void destroyCoin();

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states, int typemask) const;
  


};

std::ostream& operator<<(std::ostream& os, const Terrain& t);

#endif