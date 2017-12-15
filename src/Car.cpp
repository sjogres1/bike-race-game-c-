
#include "Car.hpp"

Player::Player(b2World* world)
        {    
                points = 0;
		
                // Creating the chassis
		b2PolygonShape polygonShape;
		b2Vec2 vertices[6];
		vertices[0].Set(-3.8f, -2.0f);
		vertices[1].Set(3.0f, -2.0f);
		vertices[2].Set(2.9f, 0.0f);
		vertices[3].Set(1.0f, 1.0f);
		vertices[4].Set(-2.0f, 1.0f);
		vertices[5].Set(-3.8f, 0.0f);
		polygonShape.Set(vertices, 6);
		
                shape = B2toSFRenderer::PolygonToSFConvex(polygonShape);
		bodytexture.loadFromFile("moto2.png");
        	bodytexture.setSmooth(true);
       		shape.setTexture(&bodytexture, true);
                
		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(-16.0f, 4.8f);
		body = world->CreateBody(&bd);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &polygonShape;
		fixtureDef.density = 3.0f;
		body->CreateFixture(&fixtureDef);
                
                // Creating the wheels
                b2CircleShape circle;
		circle.m_radius = 1.3f;
                
                wheel1 = B2toSFRenderer::CircleToSFCircle(circle);
                wheel2 = B2toSFRenderer::CircleToSFCircle(circle);
		wheeltexture.loadFromFile("wheel.png");
        	wheeltexture.setSmooth(true);
       		wheel1.setTexture(&wheeltexture, true);
                wheel2.setTexture(&wheeltexture, true);
                
		b2FixtureDef fd1;
		fd1.shape = &circle;
		fd1.density = 3.0f;
		fd1.friction = 3.0f;
		
		bd.position.Set(-2.4f, 0.4f);
                bd.linearDamping = 0.2f;
		m_wheel1 = world->CreateBody(&bd);
		m_wheel1->CreateFixture(&fd1);
                
		bd.position.Set(2.4f, 0.4f);
		m_wheel2 = world->CreateBody(&bd);
		m_wheel2->CreateFixture(&fd1);
		
                // Creating the head
                b2CircleShape circlehead;
		circlehead.m_radius = 0.7f;
                headshape = B2toSFRenderer::CircleToSFCircle(circlehead);
		headtexture.loadFromFile("head.png");
        	headtexture.setSmooth(true);
       		headshape.setTexture(&headtexture, true);
                
                b2FixtureDef hd1;
                hd1.shape = &circlehead;
                hd1.density = 1.0f;
                b2BodyDef hed;
                hed.type = b2_dynamicBody;
                hed.position.Set(0.9f, 0.2f);
                hed.angle = 2;
                head = world->CreateBody(&hed);
                head->CreateFixture(&hd1);
                
		// Attaching the head to the body
                b2RevoluteJointDef HeadJoint;
                HeadJoint.bodyA = body;
                HeadJoint.bodyB = head;
                HeadJoint.collideConnected = false;
                HeadJoint.localAnchorA.Set(0.8f, 0.9f);
                HeadJoint.localAnchorB.Set(0,0); // Center of the circle
		HeadJoint.enableMotor = false;
                HeadJoint.enableLimit = true;
                
                m_head = (b2RevoluteJoint*)world->CreateJoint( &HeadJoint );
                
                // Attaching the back wheel to the chassis
                b2RevoluteJointDef WheelJointBack;
                WheelJointBack.bodyA = body;
                WheelJointBack.bodyB = m_wheel1;
                WheelJointBack.collideConnected = false;
                WheelJointBack.localAnchorA.Set(-2.7f,-2.5f); //the down left corner of the box
                WheelJointBack.localAnchorB.Set(0,0);//center of the circle
                
                WheelJointBack.motorSpeed = -1.0f;
		WheelJointBack.maxMotorTorque = 95000.0f;
		WheelJointBack.enableMotor = false;
                
                m_spring1 = (b2RevoluteJoint*)world->CreateJoint( &WheelJointBack );
                
                // Attaching the front wheel to the chassis
                b2RevoluteJointDef WheelJointFront;
                WheelJointFront.bodyA = body;
                WheelJointFront.bodyB = m_wheel2;
                WheelJointFront.collideConnected = false;
                WheelJointFront.localAnchorA.Set(2.7f,-2.5f); 
                WheelJointFront.localAnchorB.Set(0,0); // Center of the circle
                
                WheelJointFront.motorSpeed = -1.0f;
		WheelJointFront.maxMotorTorque = 90000.0f;
		WheelJointFront.enableMotor = false;
		
                m_spring2 = (b2RevoluteJoint*)world->CreateJoint( &WheelJointFront );
		
                // Converting the Box2D to the screen pixels
		wheel1.setRadius(1.3f * Pix_Per_M);
		wheel1.setPointCount(12000);
		wheel2.setRadius(1.3f * Pix_Per_M);
		wheel2.setPointCount(12000);
                
                headshape.setRadius(0.7f * Pix_Per_M);
		headshape.setPointCount(12000);
		
		createShape(polygonShape);
}

void Player::render(sf::RenderTarget &rt) const
	{
		rt.draw(shape);
		rt.draw(wheel1);
		rt.draw(wheel2);
                rt.draw(headshape);
	}

void Player::update()
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
                
                headshape.setOrigin(0.7f * Pix_Per_M, 0.7f * Pix_Per_M);
		headshape.setPosition((head->GetPosition().x)*Pix_Per_M,
						   (head->GetPosition().y)*Pix_Per_M*(-1));
		headshape.setRotation(head->GetAngle() * (-180.0f / b2_pi));
	}
       
	
	void Player::setDrawingPosition()
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
                
                headshape.setOrigin(0.7f * Pix_Per_M, 0.7f * Pix_Per_M);
		headshape.setPosition((head->GetPosition().x)*Pix_Per_M,
						   (head->GetPosition().y)*Pix_Per_M*(-1));
		headshape.setRotation(head->GetAngle() * (-180.0f / b2_pi));
	}
	
	void Player::createShape(b2PolygonShape polygonShape)
	{
		int32 vcount = polygonShape.GetVertexCount();
		shape.setPointCount(vcount);
		for (int32 i = 0; i < vcount; i++) {
			const b2Vec2 v = polygonShape.GetVertex(i);
			shape.setPoint(i, sf::Vector2f(v.x*Pix_Per_M, v.y*Pix_Per_M*(-1)));
		}
		update();
	}
	
	const b2Vec2 Player::getPosition() const
	{
		return body->GetPosition();
	}
	
	void Player::forward()
	{
		accelerate(1.0f);
	}
	
	void Player::backwards()
	{
		accelerate(-2.0f);
	}
        
	void Player::brake(){
            m_spring2->EnableMotor(true);
            m_spring1->EnableMotor(true);
            m_spring1->SetMotorSpeed(0.0f);
            m_spring2->SetMotorSpeed(0.0f);
        }
        
        void Player::stop()
	{
		m_spring1->SetMotorSpeed(0.0f);
                m_spring2->SetMotorSpeed(0.0f);
                m_spring2->EnableMotor(false);
                m_spring1->EnableMotor(false);
	}
	
	void Player::accelerate(float32 change)
	{
                float a;
                m_spring1->EnableMotor(true);
                auto mspeed = m_spring1->GetMotorSpeed();
                
                if ((change > 0 && mspeed < 30.0f) || (change < 0 && mspeed > -30.0f))
                {
			m_spring1->SetMotorSpeed(mspeed-change);
                }
                
                mspeed = m_spring1->GetMotorSpeed();
                if (mspeed>=30.0f || mspeed<= -30.0f)
                {    
                    if (mspeed>=0.0f)
                    {
                        a = -1;
                    }
                    else
                        a = 1;
                    
                    m_spring1->SetMotorSpeed(-30.0f*a);
                }           	
	}
	
	void Player::decreaseSpeed(float32 speedDecrease)
	{
                auto mspeed = m_spring1->GetMotorSpeed();
                
                if (mspeed < 2*speedDecrease && mspeed > 2*speedDecrease)
			stop();
		if (mspeed > 0)
			m_spring1->SetMotorSpeed(mspeed-speedDecrease);
		else if (mspeed < 0)
			m_spring1->SetMotorSpeed(mspeed+speedDecrease);
                
	}
        
        void Player::tiltback()
        {
            if (abs(body->GetAngularVelocity()) > 2)
                return;
            
            body->ApplyAngularImpulse(300);
        }
        
        void Player::tiltforward()
        {
            if (abs(body->GetAngularVelocity()) > 2)
                return;
            
            body->ApplyAngularImpulse(-300);
        }
        
	
	/* DESCRIPTION:
	 * Used for debugging player movement
	 * Parameter: output stream
	 */
        
        
	void Player::debugLog(std::ostream& out)
	{
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();
		out << std::setprecision(2) << std::fixed << position.x << " " << position.y << " " << angle << std::endl;
	}
        
        void Player::increasePoints(int x) 
        {
            points = points + x;
        }
        
        int Player::getPoints() 
        {
            return points;
        }
        