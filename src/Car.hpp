/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.hpp
 * Author: johanpelkonen
 *
 * Created on 12 December 2017, 18:03
 */

#ifndef CAR_HPP
#define CAR_HPP

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

#include "GameObject.hpp"
#include "Box2DToSFML.hpp"
//#include "Ground.hpp"




class Player : public GameObject
{
public:
	Player(b2World* world);
        
        ~Player() {}
	
	void render(sf::RenderTarget &rt) const;
	
	void update();
	
	void setDrawingPosition();
	
	void createShape(b2PolygonShape polygonShape);
	
	const b2Vec2 getPosition() const;
	
	void forward();
	
	void backwards();
	
	void brake();
        
        void stop();
	
	void accelerate(float32 change); 
	
	void decreaseSpeed(float32 speedDecrease);
        
        void tiltback();
        
        void tiltforward();
        
	/* DESCRIPTION:
	 * Used for debugging player movement
	 * Parameter: output stream
	 */
        
        
	void debugLog(std::ostream& out);
	
        void increasePoints(int x);
        
        size_t getPoints(); 
        
        //void contactHead() {h_contacting = true;}
        //void endHead() {h_contacting = false;}   
        //bool getCollectedHead () {
        //    return h_collected;
        //}
        //uint16 getcol1(){
         //   return hd1.filter.categoryBits;
        //}
        
private:
	
	sf::ConvexShape shape;
	sf::CircleShape wheel1;
	sf::CircleShape wheel2;
        sf::CircleShape headshape;
	
	b2Body* body;
	b2Body* m_wheel1;
	b2Body* m_wheel2;
        b2Body* head;
        sf::Texture bodytexture;
        sf::Texture wheeltexture;
        sf::Texture headtexture;
	        
        b2RevoluteJoint* m_spring1;
        b2RevoluteJoint* m_spring2;
        b2RevoluteJoint* m_head;
        
	//b2WheelJoint* m_spring1;
	//b2WheelJoint* m_spring2;
	
	float32 m_hz;
	float32 m_zeta;
	float32 m_speed;
        size_t points;
        
        //b2FixtureDef hd1;
        
        //bool h_contacting;
        //bool h_collected;
        
        //sf::Time timeSinceLastUpdate = sf::Time::Zero;
};
/*
class HeadListener : public b2ContactListener {
    void BeginContact(b2Contact* contact) {
        
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyBUserData == )
            static_cast<Player*>( bodyUserData )->contactHead();
        
        //bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        //if ( bodyUserData )
          //  static_cast<Player*>( bodyUserData )->contactHead();
        
    }
    
    void EndContact(b2Contact* contact) {
        
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Player*>( bodyUserData )->endHead();
        
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Player*>( bodyUserData )->endHead();
        
    }
};
*/

#endif /* CAR_HPP */

