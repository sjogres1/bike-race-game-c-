#include "Box2DToSFML.hpp"

namespace B2toSFRenderer {
    sf::ConvexShape PolygonToSFConvex(b2PolygonShape& polygonShape)
    {
        sf::ConvexShape shape;
        int32 vcount = polygonShape.GetVertexCount();
        shape.setPointCount(vcount);
        for (int32 i = 0; i < vcount; i++) {
            const b2Vec2 v = polygonShape.GetVertex(i);
            shape.setPoint(i, sf::Vector2f(v.x*Pix_Per_M,
                                           v.y*Pix_Per_M*(-1)));
        }
        return shape;
    }
   
    sf::CircleShape CircleToSFCircle(b2CircleShape& circleShape)
    {
        sf::CircleShape shape;
        float32 radius = circleShape.m_radius;
        shape.setPointCount(16);
        shape.setRadius(radius * Pix_Per_M);
        shape.setOrigin(radius * Pix_Per_M, radius * Pix_Per_M);
        return shape;
    }
 }