
#ifndef COIN_HPP
#define COIN_HPP

#include "GameObject.hpp"
#include "Car.hpp"
#include "Box2DToSFML.hpp"

class Coin : public GameObject
{
    
    public:
        // implements coin texture, physics and position
    Coin(b2World* world, Player* player, double x, double y);
    
    
    
    // checks if coin is collected and add points if coin is collected
    void update(); 
        // draws coin, if coin is not collected
        void render(sf::RenderTarget &rt) const
    {
        if(!collected) {rt.draw(coin);}
        
    }
    
    // checks if coin is contacted
    void startContact() {m_contacting = true;}
    //ends coin contact
    void endContact() {m_contacting = false;}
    
    private:
    
    b2Body* m_coin;
    sf::CircleShape coin;
    bool m_contacting;
    bool collected;
    sf::Texture cointexture;
    Player* player1;
    
};
// this class handles coin contacting with Box2d b2ContactListener library
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
    
#endif /* COIN_HPP */
    
