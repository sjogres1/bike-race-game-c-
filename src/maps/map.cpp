#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

static const float SCALE = 3.0; //10px = 1 meter
static const float WWIDTH= 1600.0; //screen width
static const float WHEIGHT= 600.0; //screen width

b2Vec2 convertWorldToScreen( const b2Vec2& v) {
  return b2Vec2( (v.x * SCALE + WWIDTH/2) , -v.y * SCALE + WHEIGHT/4);
}

int main(int argc, char** argv)
{
  //Setup SFML
  sf::RenderWindow window( sf::VideoMode( WWIDTH,WHEIGHT), "map test");

  B2_NOT_USED(argc);
  B2_NOT_USED(argv);

  // Textures
  sf::Texture GroundTexture;
  GroundTexture.loadFromFile("grass.png");
  // Sprites
  sf::Sprite GroundSprite;

  GroundSprite.setTexture(GroundTexture);
  GroundSprite.setTextureRect(sf::IntRect(0, 0, 78 * SCALE, 2 * SCALE));
  GroundSprite.setOrigin(39 * SCALE, 1 * SCALE); // origin in middle

  // Define the gravity vector.
  b2Vec2 gravity(0.0f, -1.0f);

  // Construct a world object, which will hold and simulate the rigid bodies.
  b2World world(gravity, true);

  // Define the ground body.
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -40.0f);

  b2BodyDef groundBodyDef2;
  groundBodyDef2.position.Set(80.0f, -40.0f);

  // Call the body factory which allocates memory for the ground body
  // from a pool and creates the ground box shape (also from a pool).
  // The body is also added to the world.
  b2Body* groundBody = world.CreateBody(&groundBodyDef);
  b2Body* groundBody2 = world.CreateBody(&groundBodyDef2);

  // Define the ground box shape.
  b2PolygonShape groundBox;

  // The extents are the half-widths of the box.
  groundBox.SetAsBox(5.0f, 1.0f);

  // Add the ground fixture to the ground body.
  groundBody->CreateFixture(&groundBox, 0.0f);
  groundBody2->CreateFixture(&groundBox, 0.0f);
  
  // Define the dynamic body. We set its position and call the body factory.
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(3.0f, 8.0f);
  b2Body* body = world.CreateBody(&bodyDef);
  body->SetTransform( body->GetPosition(), 1.2); //rotate


  // Prepare for simulation. Typically we use a time step of 1/60 of a
  // second (60Hz) and 10 iterations. This provides a high quality simulation
  // in most game scenarios.
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  // This is our little game loop.
  while (window.isOpen())
  {
    // Check if it's time to go
    sf::Event event;
    while (window.pollEvent( event))
    {
      if( event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    world.Step(timeStep, velocityIterations, positionIterations);

    // Draw it
    // get the position and angle of the body
    b2Vec2 pos = body->GetPosition();
    float32 angle = body->GetAngle();
    pos = convertWorldToScreen( pos);

    // get the position and angle of the ground
    pos = groundBody->GetPosition();
    angle = groundBody->GetAngle();
    pos = convertWorldToScreen( pos);

    GroundSprite.setPosition(pos.x, pos.y);
    GroundSprite.setRotation(180/b2_pi * angle);
    window.draw(GroundSprite);

    pos = groundBody2->GetPosition();
    angle = groundBody2->GetAngle();
    pos = convertWorldToScreen( pos);

    GroundSprite.setPosition(pos.x, pos.y);
    GroundSprite.setRotation(180/b2_pi * angle);
    window.draw(GroundSprite);


    window.display();
  }

  return 0;
}

