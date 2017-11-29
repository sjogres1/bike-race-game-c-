#ifndef FOOTEST_H
  #define FOOTEST_H
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
    
  class FooTest : public Test
    {
        public:
        FooTest() {  //do nothing, no scene yet
	//myWorld->SetGravity( b2Vec2(0,0) );
 // dynamic body  
	// First circle  
	b2BodyDef myBodyDef;
  	myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
  	myBodyDef.position.Set(0, 20); //set the starting position
	myBodyDef.angle = 0; //set the starting angle
	//b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);
	dynamicBody = m_world->CreateBody(&myBodyDef);
	
	// Other circle
	b2BodyDef myBodyDef2;
  	myBodyDef2.type = b2_dynamicBody; //this will be a dynamic body
  	myBodyDef2.position.Set(3, 20); //set the starting position
	myBodyDef2.angle = 0; //set the starting angle
	//b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);
	dynamicBody2 = m_world->CreateBody(&myBodyDef2);

	// First circle
	b2CircleShape circleShape;
  	circleShape.m_p.Set(0, 0); //position, relative to body position
  	circleShape.m_radius = 1; //radius
	b2FixtureDef myFixtureDef;
	myFixtureDef.density = 1;
  	myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
  	dynamicBody->CreateFixture(&myFixtureDef); //add a fixture to the body
	
	// Other circle
	b2CircleShape circleShape2;
  	circleShape2.m_p.Set(0, 0); //position, relative to body position
  	circleShape2.m_radius = 1; //radius
	b2FixtureDef myFixtureDef2;
	myFixtureDef2.density = 1;
  	myFixtureDef2.shape = &circleShape2; //this is a pointer to the shape above
  	dynamicBody2->CreateFixture(&myFixtureDef2); //add a fixture to the body

  	b2PolygonShape polygonShape;

	//set each vertex of polygon in an array
  	b2Vec2 vertices[5];
  	vertices[0].Set(0,  0);
  	vertices[1].Set(4,  0);
  	vertices[2].Set( 4, 0.5);
  	vertices[3].Set( 4,  1);
  	vertices[4].Set( 4,  2);
  	//b2PolygonShape polygonShape;
  	polygonShape.Set(vertices, 5); //pass array to the shape
  	myFixtureDef.shape = &polygonShape; //change the shape of the fixture
  	myBodyDef.position.Set(0, 20); //in the middle
  	b2Body* dynamicBody3 = m_world->CreateBody(&myBodyDef);
  	dynamicBody3->CreateFixture(&myFixtureDef); //add a fixture to the body

	//set up the definition for a xxx joint
  	b2RevoluteJointDef revoluteJointDef;
  	revoluteJointDef.bodyA = dynamicBody3;
  	revoluteJointDef.bodyB = dynamicBody;
  	revoluteJointDef.collideConnected = false;
	revoluteJointDef.localAnchorA.Set(0,0);//the top right corner of the box
  	revoluteJointDef.localAnchorB.Set(0,0);//center of the circle
  	b2RevoluteJoint* joint = (b2RevoluteJoint*)m_world->CreateJoint( &revoluteJointDef );

	//set up the definition for a second xxx joint
  	b2RevoluteJointDef revoluteJointDef2;
  	revoluteJointDef2.bodyA = dynamicBody3;
  	revoluteJointDef2.bodyB = dynamicBody2;
  	revoluteJointDef2.collideConnected = false;
	revoluteJointDef2.localAnchorA.Set(4,0);//the top right corner of the box
  	revoluteJointDef2.localAnchorB.Set(0,0);//center of the circle
  	b2RevoluteJoint* joint2 = (b2RevoluteJoint*)m_world->CreateJoint( &revoluteJointDef2 );


	// Easy way to build a box
	//polygonShape.SetAsBox(2, 1); //a 4x2 rectangle
  	//myBodyDef.position.Set(10,20); //a bit to the right
  	//b2Body* dynamicBody3 = m_world->CreateBody(&myBodyDef);
  	//dynamicBody3->CreateFixture(&myFixtureDef); //add a fixture to the body

	// Ground line
	myBodyDef.type = b2_staticBody; //change body type
  	myBodyDef.position.Set(0,0); //middle, bottom
  	polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) ); //ends of the line
  	b2Body* staticBody = m_world->CreateBody(&myBodyDef);
  	staticBody->CreateFixture(&myFixtureDef); //add a fixture to the body
	
	//b2PolygonShape boxShape;
  	//boxShape.SetAsBox(1,1);
 	//b2FixtureDef boxFixtureDef;
  	//boxFixtureDef.shape = &boxShape;
  	//boxFixtureDef.density = 1;
  	//dynamicBody->CreateFixture(&boxFixtureDef);
	//dynamicBody->SetTransform( b2Vec2( 10, 20 ), 1 );
	//dynamicBody->SetLinearVelocity( b2Vec2( -5, 5 ) ); //moving up and left 5 units per second
  	//dynamicBody->SetAngularVelocity( -90 * DEGTORAD ); //90 degrees per second clockwise

// static body creation
	//myBodyDef.type = b2_staticBody; //this will be a static body
  	//myBodyDef.position.Set(0, 10); //slightly lower position
  	//b2Body* staticBody = m_world->CreateBody(&myBodyDef); //add body to world
  	//staticBody->CreateFixture(&boxFixtureDef); //add fixture to body

// kinematic body
	//myBodyDef.type = b2_kinematicBody; //this will be a kinematic body
  	//myBodyDef.position.Set(-18, 11); // start from left side, slightly above the static body
  	//b2Body* kinematicBody = m_world->CreateBody(&myBodyDef); //add body to world
  	//kinematicBody->CreateFixture(&boxFixtureDef); //add fixture to body
  
  	//kinematicBody->SetLinearVelocity( b2Vec2( 1, 0 ) ); //move right 1 unit per second
  	//kinematicBody->SetAngularVelocity( 360 * DEGTORAD ); //1 turn per second counter-clockwise

// ground
	//ground
      	//EdgeShapes edgeShape;
      	//edgeShape.Set( b2Vec2(-20,0), b2Vec2(20,0) );
  
      	//b2BodyDef bodyDef;
      	//m_world->CreateBody(&bodyDef)->CreateFixture(&edgeShape, 0);
  

	forceOn = false;
	//torqueOn = false;
	
//hovercar
      b2BodyDef bodyDef;
      bodyDef.type = b2_staticBody;
      bodyDef.fixedRotation = true;
      bodyDef.position.Set(0,0);
      m_hovercarBody = m_world->CreateBody(&bodyDef);
  
      //b2PolygonShape polygonShape;
      polygonShape.SetAsBox(2,0.5f);//4x1 box
      b2FixtureDef fixtureDef;
      fixtureDef.shape = &polygonShape;
      fixtureDef.density = 1;
  
      m_hovercarBody->CreateFixture(&fixtureDef);
}
  



void Keyboard(unsigned char key)
  {
    switch (key)
    {
      case 'q':
        //apply gradual force upwards
	forceOn = !forceOn;//toggle bool value
        //dynamicBody->ApplyForce( b2Vec2(0,50), dynamicBody->GetWorldCenter() );
        break;
      case 'w':
        //rotate right
        dynamicBody->ApplyTorque( -200 );
	//torqueOn = !torqueOn;
        break;
      case 'e':
        //rotate left
        dynamicBody->ApplyTorque( 200 );
        break;
      default:
        //run default behaviour
        Test::Keyboard(key);
    }
  }


	// If want to look at all bodies in the world
	//for ( b2Body* b = m_world->GetBodyList(); b; b = b->GetNext())
  	//{
      		//do something with the body 'b'
  	//}

        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings); 
    
            //show some text in the main screen
            m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
            m_textLine += 15;
	    
	    if(forceOn){
	    dynamicBody->ApplyForce( b2Vec2(0,30), dynamicBody->GetWorldCenter() );}

	    //if(torqueOn){
		//dynamicBody->ApplyAngularImpulse( 20 );}
		
	    // Suspension ??
	    /*float targetHeight = 3;
  	    float springConstant = 100;
  	    //make the ray at least as long as the target distance
  	    b2Vec2 startOfRay = m_hovercarBody->GetPosition();
  	    b2Vec2 endOfRay = m_hovercarBody->GetWorldPoint( b2Vec2(0,-5) );
  	    //HovercarRayCastClosestCallback callback;
	    b2RayCastOutput callback;
  	    m_world->RayCast(&callback, startOfRay, endOfRay);
  	    if ( callback.m_hit ) {
      	 	float distanceAboveGround = (startOfRay - callback.m_point).Length();
      		//dont do anything if too far above ground
      		if ( distanceAboveGround < targetHeight ) {
        	     float distanceAwayFromTargetHeight = targetHeight - distanceAboveGround;
          	     m_hovercarBody->ApplyForce( b2Vec2(0,springConstant*distanceAwayFromTargetHeight),m_hovercarBody->GetWorldCenter() );
      		}
  	    }*/
		
	    //b2Vec2 pos = dynamicBody->GetPosition();
       	    //float angle = dynamicBody->GetAngle();
            //b2Vec2 vel = dynamicBody->GetLinearVelocity();
            //float angularVel = dynamicBody->GetAngularVelocity();
            //m_debugDraw.DrawString(5, m_textLine, "Position:%.3f,%.3f Angle:%.3f", pos.x, pos.y, angle * RADTODEG);
            //m_textLine += 15;
            //m_debugDraw.DrawString(5, m_textLine, "Velocity:%.3f,%.3f Angular velocity:%.3f", vel.x, vel.y, angularVel * RADTODEG);
            //m_textLine += 15;
        }
    
        static Test* Create()
        {
            return new FooTest;
        }

	//m_world->DestroyBody(dynamicBody);

private:
	//in the class itself, not inside the constructor!
  	b2Body* dynamicBody;
	b2Body* dynamicBody2;
	b2Body* m_hovercarBody;
	bool forceOn;
	//bool torqueOn;
    };
  
  #endif