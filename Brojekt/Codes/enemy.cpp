//
//  enemy.cpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//


#include <SFML/Audio.hpp>
#include "enemy.h"
#include <ctime>
#include <stdlib.h>
#include <SFML/Graphics.hpp>


 

 enemy::enemy()
 {
 rect.setSize(sf::Vector2f(100,100));
 rect.setPosition(300,500);
 rect.setFillColor(sf::Color::Blue);
 sprite.setTextureRect(sf::IntRect(0, 0, esize, esize));

 }

// void enemy::set_movespeed(float n) {
// moveSpeed = n;
// }
//



 void enemy::update()
{
    
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x+5, rect.getPosition().y - rect.getSize().y/2);
 }


void enemy::updatemove(sf::RectangleShape tiles[][14])
{

    if (direction == 1)
    {
        rect.move(0, -movespeed);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(0, movespeed);
                    direction = 1;
                }
            }
        sprite.setTextureRect(sf::IntRect(counterwalk*esize, esize*3, esize, esize));
    }

    else if (direction == 2)
    {

        rect.move(0, movespeed);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(0, -movespeed);
                    direction = 2;
                }
            }
        sprite.setTextureRect(sf::IntRect(counterwalk*esize, 0, esize, esize));

    }

    else if (direction == 3)
    {

        rect.move(-movespeed, 0);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(movespeed, 0);
                    direction = 3;
                }
            }
        sprite.setTextureRect(sf::IntRect(counterwalk*esize, esize, esize, esize));
    }

    else if (direction == 4)
    {

        rect.move(movespeed, 0);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(-movespeed, 0);
                    direction = 4;
                }
            }
        sprite.setTextureRect(sf::IntRect(counterwalk*esize, esize*2, esize, esize));
    }
    
    else
    {
        // Nothing :3
    }



    counterwalk++;

    if (counterwalk >= 2)
        counterwalk = 0;
    
    
    counter++;
    if (counter >= movelength)
    {
        direction = generateRandom(6);
        counter = 0;
    }

}

