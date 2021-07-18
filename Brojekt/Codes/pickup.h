//
//  pickup.hpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#ifndef pickup_h
#define pickup_h

#include <stdio.h>
#include "entity.h"


class pickup: public entity
{
public:
    
    int counter = 0;
    int countAnimation = 0;
    int countery = 0;
    float movespeed = 2;
    int lifetime = 125;
    bool isCoin = true;
    int coinValue = 1;
    bool destroy = false;
    bool touched = false;
    
    //void set_movespeed(float);
    
    pickup();
    void update();
    void updatemove();
    void epicexit();
    
private:
    int csize = 75;
};

#endif /* pickup_hpp */
