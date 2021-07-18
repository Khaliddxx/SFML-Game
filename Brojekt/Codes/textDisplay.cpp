//
//  textdisplay.cpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#include "textDisplay.h"


textDisplay::textDisplay()
{
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(117, 74, 0));
    text.setCharacterSize(40);
    text.setString(str);
}

void textDisplay::update()
{
    
    text.move(0,-movespeed);
    
    counter++;
    if (counter >= lifeTime)
    {
        destroy = true;
    }
}


void textDisplay::updatemove (sf::RectangleShape tiles[][14], vector<enemy> &enemyArray)
{
    if (direction == 1) // Up
    {
        text.move (0, -movespeed2);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    if ((text.getPosition().y - 100 == tiles[i][j].getPosition().y)&&
                        (text.getPosition().x == tiles[i][j].getPosition().x))
                        text.move(0, movespeed2);
                   // if (text.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                    //    text.move(0, movespeed2);
                }
            }
        
    }
    else if (direction == 2) // Down
    {
        text.move (0, movespeed2);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    //if (text.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                    if ((text.getPosition().y - 100 == tiles[i][j].getPosition().y)&&
                        (text.getPosition().x == tiles[i][j].getPosition().x))
                            text.move(0, -movespeed2);
                }
            }

    }
    else if (direction == 3) // Left
    {
        text.move (-movespeed2, 0);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                    //if (text.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                    if ((text.getPosition().y - 100 == tiles[i][j].getPosition().y)&&
                        (text.getPosition().x == tiles[i][j].getPosition().x))
                            text.move(movespeed2, 0);
                }
            }

    }
    else if (direction == 4) // Right
    {
        text.move (movespeed2, 0);
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Blue)
                {
                   // if (text.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                    if ((text.getPosition().y - 100 == tiles[i][j].getPosition().y)&&
                        (text.getPosition().x == tiles[i][j].getPosition().x))
                            text.move(movespeed2, 0);
                }
            }
    }
    
    else
    {
        
    }
        
//    counter++;
//    if (counter >= movelength)
//    {
//        direction = 0;
//    }

}

