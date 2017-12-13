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
	Player(b2World* world)
        {
            //timeSinceLastUpdate > sf::seconds(timeStep))
            //timeSinceLastUpdate -= sf::seconds(timeStep);
                //sf::Time timeSinceLastUpdate = sf::Time::Zero;
                //timeSinceLastUpdate.asSeconds();
                        
                points = 0;
		m_hz = 3.0f;
		m_zeta = 0.1f;
		m_speed = 30.0f;
		
		b2PolygonShape polygonShape;
		b2Vec2 vertices[6];
		vertices[0].Set(-3.3f, -0.7f);
		vertices[1].Set(3.3f, -0.7f);
		vertices[2].Set(3.3f, 0.0f);
		vertices[3].Set(1.5f, 1.0f);
		vertices[4].Set(-1.5f, 1.0f);
		vertices[5].Set(-3.3f, 0.0f);
		polygonShape.Set(vertices, 6);
		
		b2CircleShape circle;
		circle.m_radius = 1.3f;
                
                wheel1 = B2toSFRenderer::CircleToSFCircle(circle);
                wheel2 = B2toSFRenderer::CircleToSFCircle(circle);
		wheeltexture.loadFromFile("wheel1.png");
        	wheeltexture.setSmooth(true);
       		wheel1.setTexture(&wheeltexture, true);
                wheel2.setTexture(&wheeltexture, true);
		
		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(0.0f, 2.8f);
		body = world->CreateBody(&bd);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &polygonShape;
		fixtureDef.density = 5.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 0.1;
		body->CreateFixture(&fixtureDef);

		b2FixtureDef fd;
		fd.shape = &circle;
		fd.density = 5.0f;
		fd.friction = 1.0f;
		fd.restitution = 0.1;
		
		bd.position.Set(-2.4f, 0.4f);
		m_wheel1 = world->CreateBody(&bd);
		m_wheel1->CreateFixture(&fd);
		
		bd.position.Set(2.4f, 0.4f);
		m_wheel2 = world->CreateBody(&bd);
		m_wheel2->CreateFixture(&fd);
		
		//b2RevoluteJoint *jd;
		//b2Vec2 axis(0.0f, 1.0f);
                
                // FIRST WHEEL AXIS
                b2RevoluteJointDef WheelJointBack;
                WheelJointBack.bodyA = body;
                WheelJointBack.bodyB = m_wheel1;
                WheelJointBack.collideConnected = false;
                WheelJointBack.localAnchorA.Set(-2.7f,-2.5f); //the down left corner of the box
                WheelJointBack.localAnchorB.Set(0,0);//center of the circle
                
                WheelJointBack.motorSpeed = -1.0f;
		WheelJointBack.maxMotorTorque = 500.0f;
		WheelJointBack.enableMotor = true;
		//WheelJointBack.frequencyHz = 4;
		//WheelJointBack.dampingRatio = 0.1;
                
                m_spring1 = (b2RevoluteJoint*)world->CreateJoint( &WheelJointBack );
                
                // SECOND WHEEL AXIS
                b2RevoluteJointDef WheelJointFront;
                WheelJointFront.bodyA = body;
                WheelJointFront.bodyB = m_wheel2;
                WheelJointFront.collideConnected = false;
                WheelJointFront.localAnchorA.Set(2.7f,-2.5f); //the down left corner of the box
                WheelJointFront.localAnchorB.Set(0,0);//center of the circle
                
                WheelJointFront.motorSpeed = -1.0f;
		WheelJointFront.maxMotorTorque = 500.0f;
		WheelJointFront.enableMotor = true;
		//WheelJointBack.frequencyHz = 4;
		//WheelJointBack.dampingRatio = 0.1;
                //b2PrismaticJoint aa;
                
                
                m_spring2 = (b2RevoluteJoint*)world->CreateJoint( &WheelJointFront );
		
		/*jd.Initialize(body, m_wheel1, m_wheel1->GetPosition(), axis);
		jd.motorSpeed = -1.0f;
		jd.maxMotorTorque = 500.0f;
		jd.enableMotor = true;
		jd.frequencyHz = 4;
		jd.dampingRatio = 0.1;
		m_spring1 = (b2WheelJoint*)world->CreateJoint(&jd);
		
		jd.Initialize(body, m_wheel2, m_wheel2->GetPosition(), axis);
		jd.motorSpeed = 0.0f;
		jd.maxMotorTorque = 0.0f;
		jd.enableMotor = false;
		jd.frequencyHz = 4;
		jd.dampingRatio = 0.1;
		m_spring2 = (b2WheelJoint*)world->CreateJoint(&jd);
                 */ 
	
		wheel1.setRadius(1.3f * Pix_Per_M);
		wheel1.setPointCount(12);
		wheel2.setRadius(1.3f * Pix_Per_M);
		wheel2.setPointCount(12);
		
		createShape(polygonShape);
		
	}
        
        ~Player() {
            
        }
	
	void render(sf::RenderTarget &rt) const
	{
		rt.draw(shape);
		rt.draw(wheel1);
		rt.draw(wheel2);
	}
	
	void update()
	{
		shape.setPosition(body->GetPosition().x*Pix_Per_M,
						  body->GetPosition().y*Pix_Per_M*(-1));
		shape.setRotation(body->GetAngle() * (-180.0f / b2_pi));
		
		wheel1.setOrigin(1.3f * Pix_Per_M, 1.3f * Pix_Per_M);
		wheel1.setPosition((m_wheel1->GetPosition().x )*Pix_Per_M,
						   (m_wheel1->GetPosition().y)*Pix_Per_M*(-1));
		wheel1.setRotation(m_wheel1->GetAngle() * (-180.0f / b2_pi));
		
		wheel2.setOrigin(1.3f * Pix_Per_M, 1.3f * Pix_Per_M);
		wheel2.setPosition((m_wheel2->GetPosition().x)*Pix_Per_M,
						   (m_wheel2->GetPosition().y)*Pix_Per_M*(-1));
		wheel2.setRotation(m_wheel2->GetAngle() * (-180.0f / b2_pi));
	}
       
	
	void setDrawingPosition()
	{
		shape.setPosition(body->GetPosition().x*Pix_Per_M,
						  body->GetPosition().y*Pix_Per_M*(-1));
		shape.setRotation(body->GetAngle() * (-180.0f / b2_pi));
		
		wheel1.setOrigin(1.3f * Pix_Per_M, 1.3f * Pix_Per_M);
		wheel1.setPosition((m_wheel1->GetPosition().x )*Pix_Per_M,
						   (m_wheel1->GetPosition().y)*Pix_Per_M*(-1));
		wheel1.setRotation(m_wheel1->GetAngle() * (-180.0f / b2_pi));
		
		wheel2.setOrigin(1.3f * Pix_Per_M, 1.3f * Pix_Per_M);
		wheel2.setPosition((m_wheel2->GetPosition().x)*Pix_Per_M,
						   (m_wheel2->GetPosition().y)*Pix_Per_M*(-1));
		wheel2.setRotation(m_wheel2->GetAngle() * (-180.0f / b2_pi));
	}
	
	void createShape(b2PolygonShape polygonShape)
	{
		int32 vcount = polygonShape.GetVertexCount();
		shape.setPointCount(vcount);
		for (int32 i = 0; i < vcount; i++) {
			const b2Vec2 v = polygonShape.GetVertex(i);
			shape.setPoint(i, sf::Vector2f(v.x*Pix_Per_M,
										   v.y*Pix_Per_M*(-1)));
		}
		
		//auto fixt = m_wheel1->GetFixtureList();
		//fixt->GetBody()->GetPosition()
	
		update();
	}
	
	const b2Vec2 getPosition() const
	{
		return body->GetPosition();
	}
	
	void forward()
	{
		accelerate(2.0f); //4.0f
	}
	
	void backwards()
	{
		accelerate(-2.0f);
	}
	
        void stop()
	{
		m_spring1->SetMotorSpeed(0.0f);
                m_spring2->SetMotorSpeed(0.0f);
	}
	
	void accelerate(float32 change) // 1.0f
	{
                auto mspeed = m_spring1->GetMotorSpeed();
                auto mspeed2 = m_spring2->GetMotorSpeed();
		if ((change > 0 && mspeed < 30.0f && mspeed2 < 30.0f) || (change < 0 && mspeed > -30.0f && mspeed2 > -30.0f)){
			m_spring1->SetMotorSpeed(mspeed-change);
                        m_spring2->SetMotorSpeed(mspeed2-change);
                }
                if ((m_spring1->GetMotorSpeed()>20.0f && m_spring2->GetMotorSpeed()>20.0f) || (m_spring1->GetMotorSpeed()< -20.0f && m_spring2->GetMotorSpeed()< -20.0f)){
                    //(change*5);
                    stop();
                }
            //float deltaTime = timeSinceLastUpdate.asSeconds();
            //if (m_wheel1->GetLinearVelocity().x > 500.0f)
            //    stop();
            //else{
                //accelerate(deltaTime*100*(-acceleration));
                //m_spring1->SetMotorSpeed(mspeed-deltaTime*100000000000000*(-change));
            //}
            //timeSinceLastUpdate.asSeconds();
			
	}
	
	void decreaseSpeed(float32 speedDecrease=2.0f)
	{
                auto mspeed = m_spring1->GetMotorSpeed();
		auto mspeed2 = m_spring2->GetMotorSpeed();
		if (mspeed < 2*speedDecrease && mspeed > 2*speedDecrease && mspeed2 < 2*speedDecrease && mspeed2 > 2*speedDecrease)
			stop();
		if (mspeed > 0 || mspeed2 > 0){
			m_spring1->SetMotorSpeed(mspeed-speedDecrease);
                        m_spring2->SetMotorSpeed(mspeed2-speedDecrease);
                }
		else if (mspeed < 0 || mspeed2 < 0){
			m_spring1->SetMotorSpeed(mspeed+speedDecrease);
			m_spring2->SetMotorSpeed(mspeed2+speedDecrease);
                }
	}
        
        void tiltback(){
            //auto body_angle = body->GetAngle();
            float desiredAngle = 0;
            body->ApplyTorque(4000);
            /*float bodyAngle = body->GetAngle();
            float nextAngle = bodyAngle + body->GetAngularVelocity() / 60.0;
  float totalRotation = desiredAngle - nextAngle;
  while ( totalRotation < -180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
  while ( totalRotation >  180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
  float desiredAngularVelocity = totalRotation * 60;
  float change = 1 * DEGTORAD; //allow 1 degree rotation per time step
  desiredAngularVelocity = fmin( change, fmax(-change, desiredAngularVelocity));
  float impulse = body->GetInertia() * desiredAngularVelocity;
  body->ApplyAngularImpulse( impulse );*/
        }
        void tiltforward(){
            //auto body_angle = body->GetAngle();
            //body->ApplyTorque(-4000);
            if (abs(body->GetAngularVelocity()) > 2)
    return;

  //if (clockwise)
    body->ApplyAngularImpulse(-150);
  //else
    //body->ApplyAngularImpulse(2000);
        }
        
	
	/* DESCRIPTION:
	 * Used for debugging player movement
	 * Parameter: output stream
	 */
        
        
	void debugLog(std::ostream& out)
	{
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();
		out << std::setprecision(2) << std::fixed << position.x << " " << position.y << " " << angle << std::endl;
	}
        void increasePoints() {points++;}
        size_t getPoints() {return points;}
        
private:
	
	sf::ConvexShape shape;
	
	sf::CircleShape wheel1;
	sf::CircleShape wheel2;
	
	b2Body* body;
	b2Body* m_wheel1;
	b2Body* m_wheel2;
        sf::Texture bodytexture;
        sf::Texture wheeltexture;
	        
        b2RevoluteJoint* m_spring1;
        b2RevoluteJoint* m_spring2;
	//b2WheelJoint* m_spring1;
	//b2WheelJoint* m_spring2;
	
	float32 m_hz;
	float32 m_zeta;
	float32 m_speed;
        size_t points;
        
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
};


#endif /* CAR_HPP */

