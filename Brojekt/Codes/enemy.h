//
//  enemy.hpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#ifndef __InstallingSFML__enemy__
#define __InstallingSFML__enemy__

#include "entity.h"
#include "random.h"

class enemy: public entity
{
public:
    int movespeed = 1;
    int movelength = 200;
    int attackdam = 5;
    int counterwalk = 0;
    int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
    int counter = 0;
    int hp = 30;
    int maxhp = 30;
    bool alive = true;
    
    
    enemy();
    void update();
    void updatemove(sf::RectangleShape tiles[][14]);

    
private:
    
    int mapsize = 14;
    float esize = 100;
    
    
};

#endif /* enemy_hpp */
