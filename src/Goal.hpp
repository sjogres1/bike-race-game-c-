#ifndef GOAL_HPP
#define GOAL_HPP
#include "Box2DToSFML.hpp"
#include "GameObject.hpp"
#include "Car.hpp"




class Goal : public GameObject
{
    public:
    //Destructor
    ~Goal() {

    }
    //Constructor
    Goal(b2World* world, Player* player, double x, double y);
      
     //checks if goal is collected is collected
    void update();
    
    void render(sf::RenderTarget &rt) const
    {//draws goal if it is not reached
        if(!g_collected) {rt.draw(goal);}
    }
    
    //checks if goal is contacted
    void contactGoal() {g_contacting = true;}
    //end coin contact
    void endGoal() {g_contacting = false;}   
    bool getCollected () {
        // flag for goal collection
        return g_collected;
    }
    
    
    private:
    
    b2Body* m_goal;
    sf::CircleShape goal;
    bool g_contacting;
    bool g_collected;
    sf::Texture goaltexture;
    Player* player2;
    
};
// this class handles goal contacting with Box2d b2ContactListener library
class GoalListener : public b2ContactListener {
    void BeginContact(b2Contact* contact) {
        
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Goal*>( bodyUserData )->contactGoal();
        
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Goal*>( bodyUserData )->contactGoal();
        
    }
    
    void EndContact(b2Contact* contact) {
        
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Goal*>( bodyUserData )->endGoal();
        
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Goal*>( bodyUserData )->endGoal();
        
    }
};

#endif