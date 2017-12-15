#ifndef GOAL_HPP
#define GOAL_HPP
#include "Box2DToSFML.hpp"
#include "GameObject.hpp"
#include "Car.hpp"




class Goal : public GameObject
{
    public:
    ~Goal() {

    }

    Goal(b2World* world, Player* player, double x, double y);
        
    void update();
    
    void render(sf::RenderTarget &rt) const
    {
        if(!g_collected) {rt.draw(goal);}
    }
    
    
    void contactGoal() {g_contacting = true;}
    void endGoal() {g_contacting = false;}   
    bool getCollected () {
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