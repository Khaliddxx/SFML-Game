//
//  player.cpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#include <iostream>
#include "player.h"



player::player()
{
    rect.setSize(sf::Vector2f(psize-2,psize-2));
    //rect.setPosition(400,400);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 3*psize, psize, psize));

}

void player::update()
{
    sprite.setPosition(rect.getPosition());
}

void player::updatemove(sf::RectangleShape tiles[][14])
{
    
//UPPPPP
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect.move(0, -moveSpeed);
        for (int i=0; i<mapsiz; i++)
            for (int j=0; j<mapsiz; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(0, moveSpeed);
                    direction = 1;
                }

            }
        sprite.setTextureRect(sf::IntRect(counterwalk*psize, psize*3, psize, psize));
    }
    
    
    
// DOWNN
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect.move(0, moveSpeed);
        for (int i=0; i<mapsiz; i++)
            for (int j=0; j<mapsiz; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(0, -moveSpeed);
                    direction = 2;
                }

            }
        sprite.setTextureRect(sf::IntRect(counterwalk*psize, 0, psize, psize));
    }
    
    
//LEEFTTT
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect.move(-moveSpeed, 0);
        for (int i=0; i<mapsiz; i++)
            for (int j=0; j<mapsiz; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(moveSpeed, 0);
                    direction = 3;
                }

            }
        sprite.setTextureRect(sf::IntRect(counterwalk*psize, psize, psize, psize));
    }
    
    
//RIGHHTTT
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect.move(moveSpeed, 0);
        for (int i=0; i<mapsiz; i++)
            for (int j=0; j<mapsiz; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if (rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                        rect.move(-moveSpeed, 0);
                    direction = 4;
                }

            }
        sprite.setTextureRect(sf::IntRect(counterwalk*psize, psize*2, psize, psize));
    }
    
    counterwalk++;
    
    if (counterwalk == 2)
        counterwalk = 0;
    
}
