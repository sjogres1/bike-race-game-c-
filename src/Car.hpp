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

class Player : public GameObject
{
public:
    // Creates the Box2D bodies and the SFML textures of the vehicle
    Player(b2World* world);
        
    ~Player() {}
	
    void render(sf::RenderTarget &rt) const;
	
    // Updates the position and the angle of the vehicle
    void update();
	
    // Draws the vehicle to the screen
    void setDrawingPosition();
	
    // Creates the chassis from the polygon
    // Parameter: Box2D polygon of the chassis
    void createShape(b2PolygonShape polygonShape);
	
    // Returns the position of the chassis
    const b2Vec2 getPosition() const;
	
    // Accelerates the vehicle
    void forward();
	
    // Reverse acceleration
    void backwards();
	
    // Brakes the car by stopping the wheels
    void brake();
        
    // Disables the motors
    void stop();
	
    // Adjust the motor acceleration for both directions
    // Parameter: The velocity change
    void accelerate(float32 change); 
	
    // Decreased the speed slowly
    // Parameter: The velocity change
    void decreaseSpeed(float32 speedDecrease);
        
    // Tilt the vehicle counterclockwise
    void tiltback();
        
    // Tilt the vehicle clockwise
    void tiltforward();
        
    // Used for debugging the chassis position and angle  
    // Prints these variables to the screen
    // Parameter: The output stream
    void debugLog(std::ostream& out);
	
    // Increase the points 
    // Parameter: the amount of points collected
    void increasePoints(int x);
        
    // Returns the collected points
    int getPoints(); 
        
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
        
    int points;
};

#endif /* CAR_HPP */

