#ifndef GOAL_HPP
#define GOAL_HPP
#include "Box2DToSFML.hpp"
#include "GameObject.hpp"
#include "Car.hpp"



class Goal : public GameObject
{
    public:
    Goal(b2World* world, Player* player, double x, double y) {
        
        g_contacting = false;
        g_collected = false;
        player2 = player;
        
        b2CircleShape circlegoal;
        circlegoal.m_radius = 6.0f;
        goal = B2toSFRenderer::CircleToSFCircle(circlegoal);
        goaltexture.loadFromFile("Goal.png");
        goaltexture.setSmooth(true);
        goal.setTexture(&goaltexture, true);
        
        
        b2FixtureDef fd_goal;
        fd_goal.shape = &circlegoal;
        fd_goal.density = 1.1f;
        fd_goal.isSensor = true;
        
        b2BodyDef bd_goal;
        bd_goal.position.Set(x+8,y);
        m_goal = world->CreateBody(&bd_goal);
        m_goal->CreateFixture(&fd_goal);
        m_goal->SetUserData(this);
        
    }
        
        void render(sf::RenderTarget &rt) const
        {
            if(!g_collected) {rt.draw(goal);}
            
            //if(!g_collected) {rt.draw(goal);}
        }
        
        void update()
        {
            if (g_contacting) {
                m_goal->GetWorld()->DestroyBody(m_goal);
                g_collected = true;
                
                
                
            }
            
            goal.setOrigin(goal.getRadius(), goal.getRadius());
            goal.setPosition((m_goal->GetPosition().x )*Pix_Per_M,
                    (m_goal->GetPosition().y)*Pix_Per_M*(-1));
            
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