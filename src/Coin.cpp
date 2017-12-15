#include "Coin.hpp"

Coin::Coin(b2World* world, Player* player, double x, double y) { //  Player* p, removed
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

    void Coin::update()
    {
        if (m_contacting) {
            m_coin->GetWorld()->DestroyBody(m_coin);
            collected = true;
            player1->increasePoints(2);
            
        }
        
        coin.setOrigin(coin.getRadius(), coin.getRadius());
        coin.setPosition((m_coin->GetPosition().x )*Pix_Per_M,
                (m_coin->GetPosition().y)*Pix_Per_M*(-1));
        
    }