#include "Goal.hpp"

Goal::Goal(b2World* world, Player* player, double x, double y) {
        
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

     void Goal::update()
    {
        if (g_contacting) 
            g_collected = true;
            
        
        
        goal.setOrigin(goal.getRadius(), goal.getRadius());
        goal.setPosition((m_goal->GetPosition().x )*Pix_Per_M,
                (m_goal->GetPosition().y)*Pix_Per_M*(-1));
        
    }