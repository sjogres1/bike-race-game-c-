#include "obstaclecoin.hpp"

ObstacleCoin::ObstacleCoin(b2World* world, std::istringstream& s) : Object_collect(world, s) {
	init();
}

ObstacleCoin::ObstacleCoin(b2World* world, float x, float y) : Object_collect(world, x, y) {
	init();
}

void ObstacleCoin::init() {
	myShape.radius = 1.0f;
	coin = B2toSFRenderer::CircletoSFCircle(myshape);
	CoinTexture.loadFromFile("coin.png");
	coin.setTexture(&CoinTexture, true);
	coin.setOrigin(coin.getRadius(), coin.getRadius());
	coin.setCoinPos(x*20'2,-y*20*2);
	coinToTerrain();
}

void ObstacleCoin::draw(sf::RenderTarget &rt, sf::RenderStates states) const {
	if(!takeCoin){
		rt.draw(coin);
	}
}

std::string ObstacleCoin::getName() const {

	return "coin";

}

b2Shape& ObstacleCoin::getShape(){
	return myShape;
}