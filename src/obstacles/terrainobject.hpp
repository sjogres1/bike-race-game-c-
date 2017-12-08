#ifndef TERRAIN_OBJECT_HPP
#define TERRAIN_OBJECT_HPP

#define TEROBJ_IDENT_NONE     0
#define TEROBJ_IDENT_VEHICLE  1
#define TEROBJ_IDENT_COIN     2

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>


class TerrainObject : public sf::Drawable
{
public:
	TerrainObject(int identifier=TEROBJ_IDENT_NONE) : identifier(identifier) { }
	virtual void update() {};

	int getIdentifier() {
		return identifier;
	};

	virtual void setPosition(float x, float y) {
		std::cout <<"Whats out! setting positions to an object that does not support it!" <<std::endl;

	}

	bool canCollect() {
		if(identifier = TEROBJ_IDENT_COIN){
			return true;
		}
	else{
		return false;
	}
}

	virtual void updateTextures(std::map<std::string sf::Texture*>& textures) {
	/* This loads the actual textures which matches the names. This way the
     * objects does not have to refer to any map */	
	}

	virtual bool coinDestroyed() {
		return false;
	}

	 virtual std::string getAsText() const {
    return "comment string representation of map object which does not have one\n";
  }





protected:
	int identifier;

};

std::ostream& operator<<(std::ostream& os, const TerrainObject& m);