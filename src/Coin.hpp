/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coin.hpp
 * Author: johanpelkonen
 *
 * Created on 12 December 2017, 18:36
 */

#ifndef COIN_HPP
#define COIN_HPP

#include "GameObject.hpp"
#include "Car.hpp"
#include "Box2DToSFML.hpp"

class Coin : public GameObject
{
    //protected:
    //Player* player;
    public:
    Coin(b2World* world, Player* player, double x, double y) { //  Player* p, removed
        m_contacting = false;
        collected = false;
        //player = p;
        player1 = player;
        
        b2CircleShape circle;
        circle.m_radius = 1.0f;
        coin = B2toSFRenderer::CircleToSFCircle(circle);
        cointexture.loadFromFile("coin.png");
        cointexture.setSmooth(true);
        coin.setTexture(&cointexture, true);
        
        b2FixtureDef fd;
        fd.shape = &circle;
        fd.density = 1.1f;
        fd.isSensor = true;
        
        b2BodyDef bd;
        bd.position.Set(x,y);
        m_coin = world->CreateBody(&bd);
        m_coin->CreateFixture(&fd);
        m_coin->SetUserData(this);
    }
    
    void render(sf::RenderTarget &rt) const
    {
        if(!collected) {rt.draw(coin);}
        
    }
    
    
    void update()
    {
        if (m_contacting) {
            m_coin->GetWorld()->DestroyBody(m_coin);
            collected = true;
            player1->increasePoints();
            
        }
        
        coin.setOrigin(coin.getRadius(), coin.getRadius());
        coin.setPosition((m_coin->GetPosition().x )*Pix_Per_M,
                (m_coin->GetPosition().y)*Pix_Per_M*(-1));
        
    }
    
    
    void startContact() {m_contacting = true;}
    void endContact() {m_contacting = false;}
    
    private:
    
    b2Body* m_coin;
    sf::CircleShape coin;
    bool m_contacting;
    bool collected;
    sf::Texture cointexture;
    Player* player1;
    
};

class CoinListener : public b2ContactListener {
    void BeginContact(b2Contact* contact) {
        
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Coin*>( bodyUserData )->startContact();
        
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Coin*>( bodyUserData )->startContact();
        
    }
    
    void EndContact(b2Contact* contact) {
        
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Coin*>( bodyUserData )->endContact();
        
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Coin*>( bodyUserData )->endContact();
        
    }
};

/*class Goal : public GameObject
{
    public:
    Goal(b2World* world, Player* player, double x, double y) {
        
        g_contacting = false;
        g_collected = false;
        
        b2CircleShape circlegoal;
        circlegoal.m_radius = 1.0f;
        goal = B2toSFRenderer::CircleToSFCircle(circlegoal);
        goaltexture.loadFromFile("Goal.png");
        goaltexture.setSmooth(true);
        goal.setTexture(&goaltexture, true);
        
        
        b2FixtureDef fd_goal;
        fd_goal.shape = &circlegoal;
        fd_goal.density = 1.1f;
        fd_goal.isSensor = true;
        
        b2BodyDef bd_goal;
        bd_goal.position.Set(x,y);
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
        
        
        private:
        
        b2Body* m_goal;
        sf::CircleShape goal;
        bool g_contacting;
        bool g_collected;
        sf::Texture goaltexture;
        
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
};*/
    
    
#endif /* COIN_HPP */
    
