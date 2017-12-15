#include "Goal.hpp"

Goal::Goal(b2World* world, Player* player, double x, double y) {
        
        g_contacting = false;
        g_collected = false;
        player2 = player;
        // physics and texture for goal
        b2CircleShape circlegoal;
        circlegoal.m_radius = 6.0f;
        goal = B2toSFRenderer::CircleToSFCircle(circlegoal);
        goaltexture.loadFromFile("Goal.png");
        goaltexture.setSmooth(true);
        goal.setTexture(&goaltexture, true);
        
        // goal texture fixing
        b2FixtureDef fd_goal;
        fd_goal.shape = &circlegoal;
        fd_goal.density = 1.1f;
        fd_goal.isSensor = true;

        // goal physics and texture implementation
        b2BodyDef bd_goal;
        bd_goal.position.Set(x+8,y);
        m_goal = world->CreateBody(&bd_goal);
        m_goal->CreateFixture(&fd_goal);
        m_goal->SetUserData(this);
        
    }

     void Goal::update()
    {
        if (g_contacting) 
            // checks if player touches the goal
            g_collected = true;
            
        
        // sets the location of the goal and handles that goal does not move from the final point
        goal.setOrigin(goal.getRadius(), goal.getRadius());
        goal.setPosition((m_goal->GetPosition().x )*Pix_Per_M,
                (m_goal->GetPosition().y)*Pix_Per_M*(-1));
        
    }