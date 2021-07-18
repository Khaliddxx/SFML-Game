//
//  player.hpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//
#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>


#include "entity.h"


class player: public entity 
{
public:
    
    float moveSpeed = 1.5;
    int counterwalk = 0;
    int attackdam = 5;
    int direction = 0; // 1. up - 2. down - 3. left - 4.right
    int hp = 100;
    int coins = 0;
    float time;
    bool won = false;
    bool lost = false;
    int ekilled = 0;
    
    //void set_movespeed(float);
    
    player();
    void update();
    void updatemove(sf::RectangleShape[][14]);
    
private:
    int mapsiz = 14;
    float psize = 100;
    
    
};







#endif /* player_hpp */
