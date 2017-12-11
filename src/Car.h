#ifndef CAR_H
#define CAR_H
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

//static const float SCALE = 10.f; //10px = 1 meter
    
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Car
{
protected:
    //b2FixtureDef WheelBackFixture;
    //b2FixtureDef WheelFrontFixture;
    b2FixtureDef ChassisFixture;
    //sf::Texture ChassisTexture;
    //sf::Sprite ChassisSprite;
    b2RevoluteJointDef WheelJointBack;
    b2RevoluteJointDef WheelJointFront;
    
    b2PolygonShape polygonShape;
    b2Body* Chassis;
    b2Body* WheelBack;
    b2Body* WheelFront;
    b2RevoluteJoint* JointBack;
    b2RevoluteJoint* JointFront;
    
    b2BodyDef bd;
    b2BodyDef WheelBackDef;
    b2BodyDef WheelFrontDef;
    //bd.type = b2_dynamicBody;
    
    //sf::ConvexShape sfChassis;
    //sf::CircleShape sfWheelBack;
    //sf::CircleShape sfWheelFront;
    
    //sf::Texture ChassisTexture;
    //sf::Texture WheelTexture;
    
    //float Distance; // distance from the ground
    //b2Vec2 chassisVertices[4];
    
    //float acceleration;
    //float WheelBackRadius;
    //float WheelFrontRadius;
    //b2Vec2 WheelBack_position;
    //b2Vec2 WheelFront_position;
    
    //void CreateCar();
    
    //float maxMotorSpeed;

    //virtual void setSpeed(float);
    
    
    
public:
    Car(){}
    
    b2Body* CreateChassis(b2World* world);
    
    // Creates also the Joints
    b2Body* CreatewheelBack(b2World* world);
    
    // Creates also the Joints
    b2Body* CreatewheelFront(b2World* world);

    
 //   b2FixtureDef CreateFix(){
    //    Chassis->CreateFixture(&ChassisFixture);

 //       return ChassisFixture;
 //   }
    
    //sf::Sprite Spriteret(sf::Texture ChassisTexture){
        //ChassisTexture.loadFromFile("chassis.png");    
        
      //  ChassisSprite.setTexture(ChassisTexture);
      //  ChassisSprite.setTextureRect(sf::IntRect(6, 6, 8 * 10.f, 10 * 10.f));
      //  ChassisSprite.setOrigin( ChassisSprite.getGlobalBounds().width / 2 ,ChassisSprite.getGlobalBounds().height / 2);
  
      //  return ChassisSprite;
    //}
    /*Car(b2World*);

    void setPosition(float x, float y);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    void update();

    void forward(float deltaTime);
    void backward(float deltaTime);
    void stop();
    void accelerate(float32 change);
    void idle();
    void tilt(bool clockwise);
    void boost();

    void limitSpeed();

    b2Vec2 getPosition() const {
        return Chassis->GetPosition();
    }

    b2Vec2 getVelocity() const {
        return Chassis->GetLinearVelocity();
    }

    float32 getMotorSpeed() const {
        return -JointBack->GetMotorSpeed();
    }
*/
  /* Custom Methods */

  /**
   * @brief Disables motors
   */
//    void disableMotor();

  /**
   * @brief Enables motors based on driveType (enum)
   */
//    void enableMotor();
};    
  
#endif