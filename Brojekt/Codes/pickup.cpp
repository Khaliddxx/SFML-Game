//
//  pickup.cpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#include "pickup.h"
#include <iostream>

pickup::pickup()
{
    rect.setSize(sf::Vector2f(75,75));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Yellow) ;
    //sprite.setTextureRect(sf::IntRect(0, 0, csize, csize));
    
}

void pickup::update()
{
    sprite.setPosition(rect.getPosition());
}



void pickup::updatemove()
{

        sprite.setTextureRect(sf::IntRect(countAnimation*csize, countery*csize, csize, csize));
        
        countAnimation++;
        
        if (countAnimation > 3)
        {
            countAnimation = 0;
            
            countery++;
            if (countery > 3)
                countery = 0;
            
        }

}

void pickup::epicexit()
{
    
    rect.move(0,-movespeed);
    
    counter++;
    if (counter >= lifetime)
    {
        destroy = true;
    }
}


    
