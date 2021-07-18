//
//  projectile.hpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#ifndef projectile_h
#define projectile_h

#include <stdio.h>

#include "entity.h"


class projectile: public entity
{
public:
    
    float moveSpeed = 2.5;
    int counterAnimation = 0;
    bool destroy = false;
    int attackdam = 10;
    int direction = 0;// 1. up - 2. down - 3. left - 4.right
    bool enemyshoots = false;
    
    
    int counterlifetime = 0;
    int lifetime = 250;              // Projectile lifetime
    
    void set_movespeed(float);
    
    projectile();
    
    void update();
    //void updatemove(sf::RectangleShape[][14]);
    
private:
    int projectile_size = 60;
    
};

#endif /* projectile_hpp */
