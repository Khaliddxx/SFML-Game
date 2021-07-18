//
//  textdisplay.hpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#ifndef textDisplay_hpp
#define textDisplay_hpp

#include <stdio.h>
#include "entity.h"
#include "enemy.h"

class textDisplay: public entity
{
public:
    float movespeed = 0.2;
    std::string str = "Default";
    int counter = 0;
    int lifeTime = 450;
    bool destroy = false;
    bool stability = false;
    float movespeed2 = 1;
    int direction = 0;
    float movelength = 0;
    
    
    textDisplay();
    void update();
    void updatemove(sf::RectangleShape tiles[][14], vector<enemy> &enemyArray);
    
private:
    int mapsize = 14;
    
};



#endif /* textdisplay_hpp */
