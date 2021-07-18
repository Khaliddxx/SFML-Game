//
//  menu.cpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//


#include "menu.h"
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ResourcePath.h>
#include "player.h"
#include "entity.h"
#include <fstream>
#include "menu.h"

std::string directory1 = "/Users/Khalid/Desktop/Brojekt/Brojekt/files/";

void Menu::mainMenu(float screenX, float screenY)
{
    if (!font.loadFromFile(directory1 + "Beyond Wonderland.ttf"))
    {
        //Handle Error
    }
    if (!swordtexture.loadFromFile(directory1 + "sword.png"))
        EXIT_FAILURE;
    
    sword.setTexture(swordtexture);
    
    mmenu[0].setFont(font);
    mmenu[0].setFillColor(sf::Color::Red);
    mmenu[0].setString("   Play");
    mmenu[0].setPosition(sf::Vector2f(700, (screenY / (maxmitems) * 2) + 100));
    mmenu[0].setCharacterSize(100);
    mmenu[0].setOutlineThickness(1);
    mmenu[0].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[1].setFont(font);
    mmenu[1].setFillColor(sf::Color::White);
    mmenu[1].setString("  Settings");
    mmenu[1].setPosition(sf::Vector2f(700, (screenY / (maxmitems) * 2.5) + 100));
    mmenu[1].setCharacterSize(100);
    mmenu[1].setOutlineThickness(1);
    mmenu[1].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[2].setFont(font);
    mmenu[2].setFillColor(sf::Color::White);
    mmenu[2].setString("Highscores");
    mmenu[2].setPosition(sf::Vector2f(700, (screenY / (maxmitems) * 3) + 100));
    mmenu[2].setCharacterSize(100);
    mmenu[2].setOutlineThickness(1);
    mmenu[2].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[3].setFont(font);
    mmenu[3].setFillColor(sf::Color::White);
    mmenu[3].setString("    Help");
    mmenu[3].setPosition(sf::Vector2f(690, (screenY / (maxmitems) * 3.5) + 100));
    mmenu[3].setCharacterSize(100);
    mmenu[3].setOutlineThickness(1);
    mmenu[3].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[4].setFont(font);
    mmenu[4].setFillColor(sf::Color::White);
    mmenu[4].setString("    Store");
    mmenu[4].setPosition(sf::Vector2f(700, (screenY / (maxmitems) * 4) + 100));
    mmenu[4].setCharacterSize(100);
    mmenu[4].setOutlineThickness(1);
    mmenu[4].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[5].setFont(font);
    mmenu[5].setFillColor(sf::Color::White);
    mmenu[5].setString("   Exit");
    mmenu[5].setPosition(sf::Vector2f(725, (screenY / (maxmitems) * 4.5) + 100));
    mmenu[5].setCharacterSize(100);
    mmenu[5].setOutlineThickness(1);
    mmenu[5].setOutlineColor(sf::Color(117, 74, 0));
    
}

void Menu::changepos(int i)
{
    mmenu[i].setFillColor(sf::Color::Red);
}

void Menu::restore(int i)
{
    mmenu[i].setFillColor(sf::Color::White);
}

void Menu::drawmenu(sf::RenderWindow &window, int index)
{

        if (index == 0)
        {
            sword.setPosition(mmenu[0].getPosition().x - 120, mmenu[0].getPosition().y);
            window.draw(sword);
            
        }
            
        else if (index == 1)
        {
            sword.setPosition(mmenu[1].getPosition().x - 120, mmenu[1].getPosition().y);
            window.draw(sword);
            
        }
        else if (index == 2)
        {
            sword.setPosition(mmenu[2].getPosition().x - 120, mmenu[2].getPosition().y);
            window.draw(sword);
            
        }
        else if (index == 3)
        {
            sword.setPosition(mmenu[3].getPosition().x - 120, mmenu[3].getPosition().y);
            window.draw(sword);
            
        }
        else if (index == 4)
        {
            sword.setPosition(mmenu[4].getPosition().x - 130, mmenu[4].getPosition().y);
            window.draw(sword);
        
        }
        else if (index == 5)
        {
            sword.setPosition(mmenu[5].getPosition().x - 130, mmenu[5].getPosition().y);
            window.draw(sword);
            
        }
    
    
    for (int i = 0; i < maxmitems; i++)
    {
        window.draw(mmenu[i]);
    }
}


//
//
//
//
//
//
//


void Menu::PlayMenu(float ScreenX, float screenY, sf::RenderWindow &window){
    
    
    if (!level1.loadFromFile(directory1 + "lvl1unlocked.png"))
        EXIT_FAILURE;
    pmenu[0].setTexture(level1);
    //window.draw(pmenu[0]);
    
    if (!level2.loadFromFile(directory1 + "lvl2locked.png"))
        EXIT_FAILURE;
    pmenu[1].setTexture(level2);
    //window.draw(pmenu[1]);
    
    if (!level3.loadFromFile(directory1 + "lvl3locked.png"))
        EXIT_FAILURE;
    pmenu[2].setTexture(level3);
    //window.draw(pmenu[2]);
    
    
}

void Menu::userMenu(float screenX, float screenY)
{
    if (!font.loadFromFile(directory1 + "Beyond Wonderland.ttf"))
        EXIT_FAILURE;
    
    if (!swordtexture.loadFromFile(directory1 + "sword.png"))
        EXIT_FAILURE;
        
    sword.setTexture(swordtexture);
    
    mmenu[0].setFont(font);
    mmenu[0].setFillColor(sf::Color::Red);
    mmenu[0].setString("   New User");
    mmenu[0].setPosition(sf::Vector2f(600, (screenY / (maxmitems) * 2) + 100));
    mmenu[0].setCharacterSize(100);
    mmenu[0].setOutlineThickness(1);
    mmenu[0].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[1].setFont(font);
    mmenu[1].setFillColor(sf::Color::White);
    mmenu[1].setString("Not New User");
    mmenu[1].setPosition(sf::Vector2f(600, (screenY / (maxmitems) * 2.5) + 100));
    mmenu[1].setCharacterSize(100);
    mmenu[1].setOutlineThickness(1);
    mmenu[1].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[2].setFont(font);
    mmenu[2].setFillColor(sf::Color::White);
    mmenu[2].setString("Delete User (soon)");
    mmenu[2].setPosition(sf::Vector2f(565, (screenY / (maxmitems) * 3) + 100));
    mmenu[2].setCharacterSize(100);
    mmenu[2].setOutlineThickness(1);
    mmenu[2].setOutlineColor(sf::Color(117, 74, 0));
    
    mmenu[3].setFont(font);
    mmenu[3].setFillColor(sf::Color::White);
    mmenu[3].setString("       Exit");
    mmenu[3].setPosition(sf::Vector2f(600, (screenY / (maxmitems) * 3.5) + 100));
    mmenu[3].setCharacterSize(100);
    mmenu[3].setOutlineThickness(1);
    mmenu[3].setOutlineColor(sf::Color(117, 74, 0));
    
}

void Menu::pmchangepos(int i)
{
    //pmenu[i].setFillColor(sf::Color::Red);
}

void Menu::pmrestore(int i)
{
    //pmenu[i].setFillColor(sf::Color::White);
}

void Menu::drawPlaymenu(sf::RenderWindow &window, int index)
{
    if (index == 0)
        window.draw(pmenu[0]);
    else if (index == 1)
        window.draw(pmenu[1]);
    else if (index == 2)
        window.draw(pmenu[2]);
}
