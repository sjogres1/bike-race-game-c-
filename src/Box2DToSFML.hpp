#ifndef RENDER_HPP
#define RENDER_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

// Renders polygonshapes and circleshapes to sfml graphics form

namespace {
	const float32 Pix_Per_M = 20.0f;
}
 namespace B2toSFRenderer {
    sf::ConvexShape PolygonToSFConvex(b2PolygonShape& polygonShape);
   
   
    sf::CircleShape CircleToSFCircle(b2CircleShape& circleShape);
   
 }
 
#endif