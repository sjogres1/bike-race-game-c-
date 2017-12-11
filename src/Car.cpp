#include "Car.h"

//Car::Car(){
    

    //b2BodyDef Car;
    //bd.type = b2_dynamicBody;
    
    // Chassis
//    b2PolygonShape polygonShape;
    //polygonShape.Set(chassisVertices, 4);
    //ChassisFixture.shape = &polygonShape;
    //sf::ConvexShape shape;
    //int32 vcount = polygonShape.GetVertexCount();
    //shape.setPointCount(vcount);
    //for (int32 i = 0; i < vcount; i++) {
    //    const b2Vec2 v = polygonShape.GetVertex(i);
    //    shape.setPoint(i, sf::Vector2f(v.x*10,
    //                                 v.y*10*(-1)));
    //}
    
/*    polygonShape.SetAsBox(4,2.0f);//4x1 box
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &polygonShape;
    fixtureDef.density = 1.0f;
  
    Chassis->CreateFixture(&fixtureDef);
*/
    /*Car.position.Set(0.0f, Distance);
    //Chassis = world->CreateBody(&Car);  // Where to define the world??????
    Chassis->CreateFixture(&ChassisFixture);
    Chassis->SetUserData(this);
    
    ChassisTexture.loadFromFile("chassis.png");
    ChassisTexture.setSmooth(true);
    sfChassis.setTexture(&ChassisTexture, true);*/
    // Wheels
    
    
    // Joints
//}
/*
b2Body* Car::getChassis(){
    return Chassis;
}

b2BodyDef Car::getb2BodyDef(){
    return bd;
}*/

b2Body* Car::CreateChassis(b2World* world){
        bd.type = b2_dynamicBody;
        bd.fixedRotation = false;
        bd.position.Set(0.0f,15.0f);
        Chassis = world->CreateBody(&bd);
        
        polygonShape.SetAsBox(70,2.0f);//4x1 box
        //b2FixtureDef fixtureDef;
        ChassisFixture.shape = &polygonShape;
        ChassisFixture.density = 1.0f;
        Chassis->CreateFixture(&ChassisFixture);
        return Chassis;
}

b2Body* Car::CreatewheelBack(b2World* world){ // & to *
    
        //b2BodyDef BodyDef;
        WheelBackDef.type = b2_dynamicBody;
        WheelBackDef.position.Set(-20.0f, 8.0f);
        WheelBack = world->CreateBody(&WheelBackDef);

        b2CircleShape circle;
        circle.m_radius = 15.0f/10;

        b2FixtureDef FixtureDef;
        FixtureDef.density = 3.0f;
        FixtureDef.friction = 50.0f;
        FixtureDef.restitution = 0.01f;
        FixtureDef.shape = &circle;

        WheelBack->CreateFixture(&FixtureDef);
        
          //set up the definition for a xxx joint
        //b2RevoluteJointDef revoluteJointDef;
        WheelJointBack.bodyA = Chassis;
        WheelJointBack.bodyB = WheelBack;
        WheelJointBack.collideConnected = false;
        WheelJointBack.localAnchorA.Set(-30,-20); //the down left corner of the box
        WheelJointBack.localAnchorB.Set(0,0);//center of the circle
        JointBack = (b2RevoluteJoint*)world->CreateJoint( &WheelJointBack );
        //JointBack = (JointBack*)world->CreateJoint( &WheelJointBack );
        
        return WheelBack;
}

b2Body* Car::CreatewheelFront(b2World* world){ // b2World& world to b2World* world
    
        //b2BodyDef BodyDef;
        WheelFrontDef.type = b2_dynamicBody;
        WheelFrontDef.position.Set(20.0f, 8.0f);
        WheelFront = world->CreateBody(&WheelFrontDef);

        b2CircleShape circle;
        circle.m_radius = 15.0f/10;

        b2FixtureDef FixtureDef;
        FixtureDef.density = 3.0f;
        FixtureDef.friction = 50.0f;
        FixtureDef.restitution = 0.01f;
        FixtureDef.shape = &circle;

        WheelFront->CreateFixture(&FixtureDef);
        
        //set up the definition for a second xxx joint
        //b2RevoluteJointDef revoluteJointDef2;
        WheelJointFront.bodyA = Chassis;
        WheelJointFront.bodyB = WheelFront;
        WheelJointFront.collideConnected = false;
        WheelJointFront.localAnchorA.Set(25,-20);//the down right corner of the box
        WheelJointFront.localAnchorB.Set(0,0);//center of the circle
        JointFront = (b2RevoluteJoint*)world->CreateJoint( &WheelJointFront );
        //JointFront = (JointFront*)world->CreateJoint( &WheelJointFront );
        
        return WheelFront;
}
                                                 
                                       