//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//
//
//
//
//
//

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "random.h"
#include "menu.h"
#include "entity.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include <ctime>
#include <cstdlib>
#include "ResourcePath.h"
#include "textDisplay.h"
#include "pickup.h"
#include <sstream>
#include "user.h"
#include <string>
#include <locale>


int screenX = 1850;
int screenY = 1300;
float tsize = 100;
float coinsize = 75;
float tilesize = 100;
float FBLogo = 100;
const int mapsize = 14;


// I had some errors with loading "some" of the files from the resource path directory. I tried to change alot of Xcode's setting to solve it but i don't know what was wrong with these specific files. Even when i edited the scheme they didn't word. Here is the directory that you can manually change.

// May also be used in other classes as directory1 & directory2 (as last minute bug fixing)

std::string directory = "/Users/Khalid/Desktop/Brojekt/Brojekt/files/";





using namespace sf;


void main_menu(user &user1, sf::Music &menumusic, sf::Music &clickmusic);
void play(sf::RenderWindow &window, user &user1, sf::Music &menumusic, sf::Music &clickmusic);
void userchoice(sf::Music &menumusic, sf::Music &clickmusic);
void game(int level, sf::Texture &tile, user &user1, sf::Music &menumusic, sf::Music &clickmusic);
int main();



void win(int lvl, int coins, int fireballs, int traps, int remainingtime, int enemykilled, int health, user &user1, sf::Music &clickmusic, sf::Music &menumusic, sf::Texture &tile)
{
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    if (!texture.loadFromFile(directory + "winner.png"))
    {
        EXIT_FAILURE;
    }
    background.setTexture(texture);
    
    //set Text
    sf::Text end_text[6];
    sf::Font font;
    
    //Font Load
    if (!font.loadFromFile(directory + "sansation.ttf"))
        EXIT_FAILURE;
    
    //Set Text Fonts
    for (int h = 0; h < 6; h++)
    {
        end_text[h].setFont(font);
        end_text[h].setFillColor(sf::Color::Red);
        end_text[h].setOutlineThickness(1);
        end_text[h].setOutlineColor(sf::Color::Black);
        end_text[h].setCharacterSize(100);
    }
    
    //Initiate score
    int lvl_score = 0, pscore, new_highscore;
    lvl_score += (coins * 10) + (remainingtime * 15) + health - (enemykilled * 5);
    pscore = user1.levelscore[lvl - 1];
    //Save Game
    if (pscore >= lvl_score)
        new_highscore = pscore;
    else
        new_highscore = lvl_score;
    
    //Set Text Position
    cout << std::to_string(coins);
    end_text[0].setString(std::to_string(coins));
    end_text[0].setPosition(630, 400);
    end_text[1].setString(std::to_string(remainingtime));
    end_text[1].setPosition(1270, 590);
    end_text[2].setString(std::to_string(enemykilled));
    end_text[2].setPosition(1270, 400);
    end_text[3].setString(std::to_string(health));
    end_text[3].setPosition(630, 590);
    end_text[4].setString(std::to_string(lvl_score));
    end_text[4].setPosition(630, 830);
    end_text[5].setString(std::to_string(new_highscore));
    end_text[5].setPosition(1270, 830);
    user1.level_end(lvl, coins, new_highscore, fireballs, 0, 1000);
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    
    
    int index = 0;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        window.clear();
        window.draw(background);
        for(int k =0; k < 6; k++)
            window.draw(end_text[k]);
        window.display();
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::R)
                    {
                        window.close();
                        game(lvl-1, tile, user1, menumusic, clickmusic);
                    }
                    else if (event.key.code == sf::Keyboard::E)
                    {
                        window.close();
                        play(window, user1, menumusic, clickmusic);
                    }
                    else if (event.key.code == sf::Keyboard::D)
                    {
                        window.close();
                        game(lvl, tile, user1, menumusic, clickmusic);
                    }
                    break;
            }
        }
    }
    
    
}

void lose(int lvl, int coins, int fireballs, int traps, int remainingtime, int enemykilled, int health, user &user1, sf::Music &clickmusic, sf::Music &menumusic, sf::Texture &tile)
{
    
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    if (!texture.loadFromFile(directory + "fail_screen.png"))
    {
        EXIT_FAILURE;
    }
    background.setTexture(texture);
    
    //set Text
    sf::Text end_text[6];
    sf::Font font;
    
    //Font Load
    if (!font.loadFromFile(directory + "sansation.ttf"))
        EXIT_FAILURE;
    
    //Set Text Fonts
    for (int h = 0; h < 6; h++)
    {
        end_text[h].setFont(font);
        end_text[h].setFillColor(sf::Color::Red);
        end_text[h].setOutlineThickness(1);
        end_text[h].setOutlineColor(sf::Color::Black);
        end_text[h].setCharacterSize(100);
    }
    
    //Initiate score
    int  highscore;
    highscore = user1.levelscore[lvl - 1];
    
    //Set Text Position
    cout << std::to_string(coins);
    end_text[0].setString(std::to_string(coins));
    end_text[0].setPosition(630, 400);
    end_text[1].setString(std::to_string(remainingtime + 1));
    end_text[1].setPosition(1270, 590);
    end_text[2].setString(std::to_string(enemykilled));
    end_text[2].setPosition(1270, 400);
    end_text[3].setString(std::to_string(health));
    end_text[3].setPosition(730, 590);
    end_text[4].setString("0");
    end_text[4].setPosition(730, 830);
    end_text[5].setString(std::to_string(highscore));
    end_text[5].setPosition(1270, 830);
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    
    
    int index = 0;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        window.clear();
        window.draw(background);
        for (int k = 0; k < 6; k++)
            window.draw(end_text[k]);
        window.display();
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::R)
                    {
                        window.close();
                        game(lvl, tile, user1, menumusic, clickmusic);
                    }
                    else if (event.key.code == sf::Keyboard::E)
                    {
                        window.close();
                        play(window, user1, menumusic, clickmusic);
                    }
                    else if (event.key.code == sf::Keyboard::D)
                    {
                        window.close();
                        game(lvl, tile, user1, menumusic, clickmusic);
                    }
                    break;
            }
        }
    }
    
    
}



void create_level(sf::RenderWindow &window, sf::RectangleShape shape[][14], sf::Texture &tile, int lvl, player &player1, enemy enemy1, vector<enemy> &enemyArray, vector<textDisplay> &textDisplayArray, textDisplay textDisplay1, vector<pickup> &pickupArray, pickup pickup1)
{
    window.create(sf::VideoMode(1400, 1500), "Brojekt");
    
    char c;
    std::string level;
    std::string directory;
    
    std::ifstream inputfile;
    inputfile.open(resourcePath() + "Map1.txt");
    
    
    if (lvl == 1)
        inputfile.ignore(1000, '#');
    else if (lvl == 2)
        inputfile.ignore(1000, '$');
    else if (lvl == 3)
        inputfile.ignore(10000, '%');
    
    
    inputfile >> directory;
    if(!tile.loadFromFile(resourcePath() + directory))
        EXIT_FAILURE;
    

    
    inputfile >> c;
    while (!inputfile.eof())
    {
        
        for (int j=0; j<14; j++)
        {
            for (int i=0; i<14; i++)
            {
                
                shape[i][j].setSize(sf::Vector2f(tilesize,tilesize));
                shape[i][j].setPosition(sf::Vector2f(i*tilesize, j*tilesize));
                
                
                if (c == '1')
                {
                    shape[i][j].setFillColor(sf::Color::Blue);
                }
                
                
                else if (c == '0')
                {
                    shape[i][j].setFillColor(sf::Color::White);
                    
                }
                
                else if (c == '3')
                {
                    enemy1.rect.setPosition(i*tilesize, j*tilesize);
                    enemyArray.push_back(enemy1);
                }
                else if (c == '5')
                {
                    pickup1.rect.setPosition(i*tilesize + tilesize/2 - coinsize/2, j*tilesize + tilesize/2 - coinsize/2);
                    pickupArray.push_back(pickup1);
                }
                else if (c == '6')
                {
                    player1.rect.setPosition(i*tilesize, j*tilesize);
                }
                else if (c == '7')
                {
                    shape[i][j].setFillColor(sf::Color::Magenta);
                    
                }
                
                
                
                inputfile >> c;
            }
        }
        
        inputfile >> player1.time;
        inputfile.close();
    }
}





// Rendering
void render(RenderWindow &window ,RectangleShape shape[][mapsize], player player1, sf::Texture &tile)
{
    sf::Sprite spritetile[14][14];
    
    
    for (int i=0; i<mapsize; i++)
    {
        for (int j=0; j<mapsize; j++){
            if (shape[i][j].getFillColor() == sf::Color::Blue)
            {   spritetile[i][j].setTexture(tile);
                spritetile[i][j].setTextureRect(IntRect(0,0,tsize,tsize));
                spritetile[i][j].setPosition(Vector2f(tsize*i,tsize*j));
            }
            else if (shape[i][j].getFillColor() == sf::Color::Magenta)
            {
                spritetile[i][j].setTexture(tile);
                spritetile[i][j].setTextureRect(IntRect(tsize*2,0,tsize,tsize));
                spritetile[i][j].setPosition(Vector2f(tsize*i,tsize*j));
                
            }
            
            else
            {   spritetile[i][j].setTexture(tile);
                spritetile[i][j].setTextureRect(IntRect(tsize,0,tsize,tsize));
                spritetile[i][j].setPosition(Vector2f(tsize*i,tsize*j));
            }
            
            window.draw(spritetile[i][j]);
        }
        
    }
    
}



// The Game

void game(int level, sf::Texture &tile, user &user1, sf::Music &menumusic, sf::Music &clickmusic)
{
    std::srand(unsigned(time(0)));
    
    
    // variables
    int counter = 0;
    int counter2 = 0;
    int timer = 0;
    //bool coinmusicbool = false;
    
    sf::Clock mainclock, clock, clock2, clock3, clock4;

    
    
    
    // Create the main window
    sf::RenderWindow window;
    window.setFramerateLimit(60);
    RectangleShape tiles[mapsize][mapsize];
    
    
    
    sf::Text textCoin, textHP, textFireBall, time;
    sf::Font font, xerox_bold, medieval;
    sf::Texture texturePlayer, textureEnemy, textureFireBall, textureCoin, playerHP, textureFBLogo, textureclock;
    sf::Music musiclvl1, musiclvl2, coinmusic, firemusic, playerfire;
    


    
    
    
    //Textures
    if(!texturePlayer.loadFromFile(resourcePath() + "player.png"))
        EXIT_FAILURE;
    if(!textureEnemy.loadFromFile(resourcePath() + "enemy.png"))
        EXIT_FAILURE;
    if(!textureFireBall.loadFromFile(resourcePath() + "fireball.png"))
        EXIT_FAILURE;
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
        EXIT_FAILURE;
    if (!xerox_bold.loadFromFile(directory + "/XeroxB.ttf"))
        EXIT_FAILURE;
    if (!textureCoin.loadFromFile(resourcePath() + "coin.png"))
        EXIT_FAILURE;
    if (!playerHP.loadFromFile(resourcePath() + "playerHP.png"))
        EXIT_FAILURE;
    if (!playerHP.loadFromFile(resourcePath() + "playerHP.png"))
        EXIT_FAILURE;
    if (!textureFBLogo.loadFromFile(resourcePath() + "FBLogo.png"))
        EXIT_FAILURE;
    if (!textureclock.loadFromFile(resourcePath() + "clock.png"))
        EXIT_FAILURE;
    
    
    // Music
    if (!musiclvl1.openFromFile(resourcePath() + "Two.ogg"))
        EXIT_FAILURE;
    if (!musiclvl2.openFromFile(resourcePath() + "One.ogg"))
        EXIT_FAILURE;
    if (!coinmusic.openFromFile(directory + "coin.ogg"))
        EXIT_FAILURE;
    if (!firemusic.openFromFile(directory + "Fire-sound.ogg"))
        EXIT_FAILURE;
    if (!playerfire.openFromFile(directory + "Fire-sound.ogg"))
        EXIT_FAILURE;


    
    
    sf::Sprite spriteplayerHP(playerHP);
    spriteplayerHP.setTextureRect(sf::IntRect(0,0,tsize,tsize));
    
    sf::Sprite spriteCoin(textureCoin);
    spriteCoin.setTextureRect(sf::IntRect(0,0,coinsize, coinsize));
    
    sf::Sprite spriteFBLogo(textureFBLogo);
    spriteFBLogo.setTextureRect(sf::IntRect(0,0,FBLogo,FBLogo));
    
    sf::Sprite spriteplayer(texturePlayer);
    spriteplayer.setTextureRect(sf::IntRect(0,0,tsize,tsize));
    
    sf::Sprite spriteclock(textureclock);
    spriteclock.setTextureRect(sf::IntRect(0,0,tsize,tsize));
    
    musiclvl1.setVolume(20);
    musiclvl2.setVolume(30);
    
// Music Management
    menumusic.stop();
    if (level == 1)
        musiclvl1.play();
    else if (level == 2)
        musiclvl2.play();
    else if (level == 3)
        musiclvl1.play();
    
    
    // Objects
    
    
    // Player Object
    class player player1;
    player1.sprite.setTexture(texturePlayer);
    
    // Projectile Object
    class projectile projectile1;
    projectile1.sprite.setTexture(textureFireBall);
    
    // Enemy Object
    class enemy enemy1;
    enemy1.sprite.setTexture(textureEnemy);
    enemy1.text.setFont(xerox_bold);
    enemy1.text.setCharacterSize(35);
    enemy1.text.setFillColor(sf::Color(230,0,0));
    enemy1.text.setOutlineColor(sf::Color(117, 74, 0));
    enemy1.text.setOutlineThickness(1);
    //enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    
    // Text Display Object
    class textDisplay textDisplay1;
    textDisplay1.text.setFont(font);
    
    
    // Coin Object
    class pickup pickup1;
    pickup1.sprite.setTexture(textureCoin);
    pickup1.sprite.setTextureRect(sf::IntRect(0,0,75,75));
    pickup1.rect.setPosition(500, 500);
    
    
    // Enemy Vector Array
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;
    
    
    // Projectile Vector Array
    std::vector<projectile>::const_iterator iter;
    std::vector<projectile> projectileArray;
    
    
    // Text Vector Array
    vector<textDisplay>::const_iterator iter8;
    vector<textDisplay> textDisplayArray;
   
    
    // Pickup Vector Array
    vector<pickup>::const_iterator iter11;
    vector<pickup> pickupArray;
    
    
//    // Fireball music Array
//    vector<sf::Music>::const_iterator iter5;
//    vector<sf::Music> firemusicArray;
   
    
    
    
    // Initializing the window after all the declarations
    
    create_level(window, tiles, tile, level, player1, enemy1, enemyArray, textDisplayArray, textDisplay1, pickupArray, pickup1);
    
    // Start the game loop
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                if (level == 1)
                    musiclvl1.stop();
                else if (level == 2)
                    musiclvl2.stop();
                else if (level == 3)
                    musiclvl1.stop();
                
                menumusic.play();
                window.close();
                play(window, user1, menumusic, clickmusic);
            }
            
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect VisibleArea(0,0,1400,1500);
                window.setView(sf::View(VisibleArea));
            }
        }
        
        
        
        // Clear screen
        window.clear();
        
        
        // Clock
        sf::Time mainElapsed = mainclock.getElapsedTime();
        
        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        sf::Time elapsed4 = clock4.getElapsedTime();
        //std::cout << int(elapsed2.asSeconds()) << std::endl;
        
        
        
        
        // Update the window
        render(window, tiles, player1, tile);
        
        
///////////////////////////////////////////////////////////////////////////////////////////////////
        
        
// Timer
        
        timer = mainElapsed.asSeconds();
        if (player1.time - timer < 0)
            window.close();
        
        
  
// Player wins
        
        for (int i=0; i<mapsize; i++)
            for (int j=0; j<mapsize; j++)
            {
                if (tiles[i][j].getFillColor() == sf::Color::Magenta)
                {
                    if (player1.rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                    {
                        player1.won = true;
                        timer = mainElapsed.asSeconds();
                        window.close();
                    }
                    
                }
            }

        
// Losing
        
        if (player1.hp <= 0 || timer >= player1.time )
            player1.lost = true;
        

            
        
        
// Player collides with Pickup Item
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {

                pickupArray[counter].touched = true;
            
            }
            
            counter++;
        }
        
        
        
        
        
// Enemy hits player
        
        if (elapsed2.asSeconds() >= 0.5)
        {
            clock2.restart();
            
            // Enemy Collides with Player (Player takes damage)
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
                {
                    // Text (so cool)
                    textDisplay1.text.setString("- " + to_string(enemyArray[counter].attackdam));
                    textDisplay1.text.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x *3/7 , player1.rect.getPosition().y - player1.rect.getSize().y/2);
                    
                    textDisplay1.text.setFillColor(Color::Red);
                    textDisplayArray.push_back(textDisplay1);
                    
                    player1.hp -= enemyArray[counter].attackdam;
                }
                
                counter++;
            }
        }
        

        
// Fireball collides with wall
        
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            for (int i=0; i<mapsize; i++)
            {
                for (int j=0; j<mapsize; j++)
                {
                    if (tiles[i][j].getFillColor() == Color::Blue)
                    {
                        if (projectileArray[counter].rect.getGlobalBounds().intersects(tiles[i][j].getGlobalBounds()))
                            projectileArray[counter].destroy = true;
                    }
                    else
                    {
                        //nothing
                    }
                }
            }
            counter++;
        }
        
      
        
// Enemy fireball hits player
        
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            //int hitter = counter;
                if (projectileArray[counter].rect.getGlobalBounds().intersects(player1.rect.getGlobalBounds()) && projectileArray[counter].enemyshoots == true)
                {
                    projectileArray[counter].destroy = true;
                    
                    // Text (so cool)
                    textDisplay1.text.setString("- " +to_string(projectileArray[counter].attackdam));
                    textDisplay1.text.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - textDisplay1.text.getCharacterSize()/3, player1.rect.getPosition().y - player1.rect.getSize().y/2 - textDisplay1.rect.getSize().x/2);
                    
                    textDisplay1.text.setFillColor(Color::White);
                    textDisplayArray.push_back(textDisplay1);
                    
                    player1.hp -= projectileArray[counter].attackdam;
                }
            counter++;
        }

        
        
        
// Player fireball hits enemy

        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                 if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()) && projectileArray[counter].enemyshoots == false)
                {
                    projectileArray[counter].destroy = true;
                    
                    // Text (so cool)
                    textDisplay1.text.setString("- " +to_string(projectileArray[counter].attackdam));
                    textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x/2 - textDisplay1.text.getCharacterSize()/3, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y/2 - textDisplay1.rect.getSize().x/2);

                    textDisplay1.text.setFillColor(Color::White);
                    textDisplayArray.push_back(textDisplay1);

                        enemyArray[counter2].hp-= projectileArray[counter].attackdam;
                    
                    if (enemyArray[counter2].hp <= 0)
                    {
                        enemyArray[counter2].alive = false;
                    }
                }
                counter2++;
            }
            counter++;
        }

        
        
// Delete Dead Enemy
        
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].alive == false)
            {
                player1.ekilled++;
                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }
        
        
        
        
// Delete Projectile
        
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].destroy == true)
            {
                projectileArray.erase(iter);
                break;
            }
            
            counter++;
        }
        
        
// Delete Text Display
        
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            if (textDisplayArray[counter].destroy == true)
            {
                textDisplayArray.erase(iter8);
                break;
            }
            
            counter++;
        }
        
        
// Delete Pickup Items
        
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (pickupArray[counter].destroy == true)
            {
                if (pickupArray[counter].isCoin == true)
                {
                    //play the coin sound
                    coinmusic.setVolume(3);
                    coinmusic.play();
                    
                    player1.coins += pickupArray[counter].coinValue;
                }
                pickupArray.erase(iter11);
                break;
            }
            
            counter++;
        }
        
        
        
// Fire missle (Space button)
        
        if (elapsed1.asSeconds() >= 0.1 && user1.fireballs > 0)
        {
            clock.restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                //play the fireshoot sound
                //firemusicArray.push_back(firemusic);
                playerfire.setVolume(40);
                playerfire.play();

                projectile1.enemyshoots = false;
                projectile1.rect.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2, player1.rect.getPosition().y + player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                projectile1.direction = player1.direction;
                user1.fireballs--;

                projectileArray.push_back(projectile1);
            }
        }
        
        
// Enemy shoots fireballs
        
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            //To make only the first initialized enemies shoot
            int r = generateRandom0(6);
            if (elapsed4.asSeconds() >= 1.4)
            {
                
                //firemusicArray.push_back(firemusic);
                firemusic.setVolume(10);
                firemusic.play();
                
                clock4.restart();
                
                projectile1.enemyshoots = true;
                projectile1.rect.setPosition(enemyArray[r].rect.getPosition().x + enemyArray[r].rect.getSize().x/2 - projectile1.rect.getSize().x/2, enemyArray[r].rect.getPosition().y + enemyArray[r].rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                projectile1.direction = enemyArray[r].direction;
                projectileArray.push_back(projectile1);
                
            }
        }
        
        
// Draw Player
        window.draw(player1.sprite);
        
        
        
// Draw Pickups (coins now)
        
        counter = 0;
        for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if (pickupArray[counter].touched)
                pickupArray[counter].epicexit();
                
                
            pickupArray[counter].update();
            if (elapsed3.asSeconds() >= 0.03)
            {
                clock3.restart();
                pickupArray[counter].updatemove();
                
            }
            window.draw(pickupArray[counter].sprite);
            
            counter++;
        }
        
        
        
// Draw Projectile
        
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            projectileArray[counter].update(); // Update Projectile
            //window.draw(projectileArray[counter].rect);
            window.draw(projectileArray[counter].sprite);
            
            counter++;
        }
        
 
        
// Draw Enemies
        
   counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {

                enemyArray[counter].update();
                enemyArray[counter].updatemove(tiles);
                window.draw(enemyArray[counter].sprite);
                
                
                counter++;
            }
        
// Draw enemies

        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].text.setString("HP:" + to_string(enemyArray[counter].hp));
            window.draw(enemyArray[counter].text);
            
            counter++;
        }
        
// Update Player
        
        player1.update();
        player1.updatemove(tiles);
        
        
// Player wins
        
        if (player1.won)
        {
            musiclvl1.stop();
            musiclvl2.stop();
            win(level + 1, player1.coins, user1.fireballs, 0, player1.time, player1.ekilled, player1.hp, user1, clickmusic, menumusic, tile);
        }
        else if (player1.lost)
        {
            musiclvl1.stop();
            musiclvl2.stop();
            lose(level, player1.coins, user1.fireballs, 0, player1.time, player1.ekilled, player1.hp, user1, clickmusic, menumusic, tile);
            
        }


        
// Draw Text
        
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++)
        {
            textDisplayArray[counter].update();
            window.draw(textDisplayArray[counter].text);
            
            counter++;
        }
        
        
        
// Status bar
        
        // Draw Health logo
        spriteplayerHP.setPosition(0*tilesize, mapsize*tilesize);
        window.draw(spriteplayerHP);
        
        // Draw Health count
        textHP.setFont(font);
        textHP.setCharacterSize(75);
        textHP.setFillColor(sf::Color::Green);
        textHP.setPosition(1*tilesize, mapsize*tilesize);
        textHP.setString(" " + to_string(player1.hp));
        window.draw(textHP);
        
        
        
        
        // Draw coin logo
        spriteCoin.setPosition(3*tilesize + tilesize/2 - coinsize/2, mapsize*tilesize + tilesize/2 - coinsize/2);
        window.draw(spriteCoin);
        
        
        // Draw coin count
        textCoin.setFont(font);
        textCoin.setCharacterSize(75);
        textCoin.setFillColor(sf::Color::Yellow);
        textCoin.setPosition(4*tilesize, mapsize*tilesize);
        textCoin.setString(" " + to_string(player1.coins));
        window.draw(textCoin);
        
        
        
        // Draw Fireball logo
        spriteFBLogo.setPosition(6*tilesize + tilesize/2 - FBLogo/2, mapsize*tilesize + tilesize/2 - FBLogo/2 - 8);
        window.draw(spriteFBLogo);
        
        
        // Draw Fireball count
        textFireBall.setFont(font);
        textFireBall.setCharacterSize(75);
        textFireBall.setFillColor(sf::Color::Red);
        textFireBall.setPosition(7*tilesize, mapsize*tilesize);
        textFireBall.setString(" " + to_string(user1.fireballs));
        window.draw(textFireBall);
        
        
        // Draw clock logo
        spriteclock.setPosition(11*tilesize + tilesize/2 - FBLogo/2, mapsize*tilesize + tilesize/2 - FBLogo/2);
        window.draw(spriteclock);

        
        // Draw time
        time.setFont(font);
        time.setCharacterSize(75);
        time.setFillColor(sf::Color::White);
        time.setPosition(12*tilesize, mapsize*tilesize);
        time.setString(to_string(int(player1.time) - timer));
        window.draw(time);
        
        
    
        
// I have an error in this method
        
//// Play Fireball Music
//        counter = 0;
//        for (iter5 = firemusicArray.begin(); iter5 != firemusicArray.end(); iter5++)
//        {
//            firemusicArray[counter].setVolume(30);
//            firemusicArray[counter].play();
//        }
//
        
//////////////////////////////////////////////////////////////////////////////////////////////////
            
        
        window.display();
        
    
    
    
    }
    EXIT_SUCCESS;
}

void play(sf::RenderWindow &window, user &user1, sf::Music &menumusic, sf::Music &clickmusic){
    {
        window.close();
        sf::Texture texture;
        sf::Texture tile;
        sf::Sprite background;
        if (!texture.loadFromFile(resourcePath() + "castle.jpg"))
            EXIT_FAILURE;
        background.setTexture(texture);
        window.draw(background);
        
        srand(unsigned(time(0)));
        
        // Open Menu
        sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
        // Open Menu
        Menu menu;
        menu.PlayMenu(window.getSize().x, window.getSize().y, window);
        int index = 0;
        while (window.isOpen())
        {
            // Process events
            sf::Event event;
            
            window.clear();
            
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                    {
                        window.close();
                        main_menu(user1, menumusic, clickmusic);
                        break;
                    }
                        
                    case sf::Event::KeyPressed:
                        switch (event.key.code)
                    {
                        case sf::Keyboard::Return:
                            clickmusic.play();
                            switch (index)
                        {
                            case 0:
                            {
                                window.close();
                                game(1, tile, user1, menumusic, clickmusic);
                                break;
                            }
                            case 1:
                            {
                                window.close();
                                game(2, tile, user1, menumusic, clickmusic);
                                break;
                            }
                            case 2:
                            {
                                window.close();
                                game(3, tile, user1, menumusic, clickmusic);
                                break;
                            }
                                
                        }
                            
                            break;
                        case sf::Keyboard::Right:
                            if (index < maxPitems - 1)
                            {
                                menu.pmrestore(index);
                                index++;
                                menu.pmchangepos(index);
                                //menu.drawPlaymenu(window, index);
                            }
                            break;
                        case sf::Keyboard::Left:
                            if (index > 0)
                            {
                                menu.pmrestore(index);
                                index--;
                                menu.pmchangepos(index);
                                //menu.drawPlaymenu(window, index);
                            }
                            break;
                        case sf::Keyboard::BackSpace:
                        {
                            clickmusic.play();
                            window.close();
                            main_menu(user1, menumusic, clickmusic);
                            break;
                        }
                        
                    }
                }
            }
            menu.drawPlaymenu(window, index);
            window.display();
        }
    }
}

void store(sf::RenderWindow &window, user &user1, sf::Music &menumusic, sf::Music &clickmusic) {
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    if (!texture.loadFromFile(directory + "castlebg.png"))
    {
        EXIT_FAILURE;
    }
    background.setTexture(texture);
    
    //Names Text Set
    sf::Text text[5], instructions[2];
    sf::Font font, rb;
    //Font Load
    if (!font.loadFromFile(directory + "Beyond Wonderland.ttf"))
        EXIT_FAILURE;
    if (!rb.loadFromFile(directory + "RingBearer.ttf"))
        EXIT_FAILURE;
    
    for (int j = 0; j < 4; j++)
    {
        text[j].setFont(font);
        text[j].setOutlineThickness(1);
        text[j].setFillColor(sf::Color::White);
        text[j].setOutlineColor(sf::Color(117, 74, 0));
        text[j].setCharacterSize(100);
    }
    text[0].setString("Coins: ");
    text[0].setPosition(600, 600);
    text[1].setString("Fireballs: ");
    text[1].setPosition(600, 800);
    text[2].setString(to_string(user1.coins));
    text[2].setPosition(1100, 600);
    text[3].setString(to_string(user1.fireballs));
    text[3].setPosition(1100, 800);
    
    //Set Instruction and status
    for (int j = 0; j < 2; j++)
    {
        instructions[j].setFont(rb);
        instructions[j].setOutlineThickness(1);
        instructions[j].setFillColor(sf::Color::Yellow);
        instructions[j].setOutlineColor(sf::Color::Black);
        instructions[j].setCharacterSize(80);
    }
    
    instructions[0].setString("Welcome to The Store");
    instructions[0].setPosition(300, 200);
    instructions[1].setString("Press Up key to buy. Enter to exit. 5 fireballs = 10 coins");
    instructions[1].setPosition(100, 1000);
    //Window size set
    
    
    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        window.clear();
        window.draw(background);
        for (int j = 0; j < 4; j++)
            window.draw(text[j]);
        for (int j = 0; j < 2; j++)
            window.draw(instructions[j]);
        window.display();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        if (user1.coins >= 10)
                        {
                            clickmusic.play();
                            user1.coins -= 10;
                            user1.fireballs += 5;
                            text[2].setString(std::to_string(user1.coins));
                            text[3].setString(to_string(user1.fireballs));
                            instructions[0].setString("Successful purchase");
                            
                        }
                        else
                        {
                            instructions[0].setString("Out of coins");
                            clickmusic.play();
                        }
                    }
                    else if (event.key.code == sf::Keyboard::Return)
                    {
                        clickmusic.play();
                        user1.update_purchases(user1.fireballs, 0, 1000, user1.coins);
                        window.close();
                        main_menu(user1, menumusic, clickmusic);
                        
                    }
                    break;
            }
        }
        
        
        
        
    }
}

void Settings(user &user1, sf::Music &menumusic, sf::Music &clickmusic) {
    
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    if (!texture.loadFromFile(resourcePath() + "castlebg_2.png"))
    {
        EXIT_FAILURE;
    }
    background.setTexture(texture);
    
    //Names Text Set
    sf::Text text;
    sf::Text status;
    sf::Font font;
    
    //Font Load
    if (!font.loadFromFile(directory + "Beyond Wonderland.ttf"))
        EXIT_FAILURE;
    
    text.setFont(font);
    text.setOutlineThickness(1);
    text.setFillColor(sf::Color::Red);
    text.setOutlineColor(sf::Color(117, 74, 0));
    text.setPosition(600, screenY / 2);
    text.setCharacterSize(90);
    text.setString("Sound \t");
    
    status.setFont(font);
    status.setOutlineThickness(1);
    status.setOutlineColor(sf::Color(117, 74, 0));
    status.setPosition(920, screenY / 2);
    status.setCharacterSize(90);
    
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    
    
    
    while (window.isOpen())
    {
        if (user1.music)
        {
            status.setFillColor(sf::Color::Green);
            status.setString("on");
            menumusic.setVolume(100);
            clickmusic.setVolume(100);
        }
        else
        {
            status.setFillColor(sf::Color::Red);
            status.setString("off");
            menumusic.setVolume(0);
            clickmusic.setVolume(0);
        }
        // Process events
        sf::Event event;
        window.clear();
        window.draw(background);
        window.draw(text);
        window.draw(status);
        window.display();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
                        user1.music = !user1.music;
                    else if (event.key.code == sf::Keyboard::Return)
                    {
                        clickmusic.play();
                        window.close();
                        main_menu(user1, menumusic, clickmusic);
                    }
                    else if (event.key.code == sf::Keyboard::BackSpace)
                    {
                        clickmusic.play();
                        window.close();
                        main_menu(user1, menumusic, clickmusic);
                    }
                    break;
            }
        }
        
        
        
        
    }
    
}


void Highscores(user &user1, sf::Music &menumusic, sf::Music &clickmusic) {
    
    
    
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    if (!texture.loadFromFile(resourcePath() + "castlebg.png"))
    {
        EXIT_FAILURE;
    }
    background.setTexture(texture);
    
    //Names Text Set
    string str = "Loading....";
    sf::Text text;
    sf::Font font;
    //Font Load
    if (!font.loadFromFile(directory + "XeroxB.ttf"))
        EXIT_FAILURE;
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(117, 74, 0));
    text.setPosition(0+80, screenY/2);
    text.setCharacterSize(90);
    text.setString(str);
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    window.clear();
    window.draw(background);
    window.draw(text);
    window.display();
    
    
    
    
    
    const int userlim = 4; //Database user limit
    ifstream database_read;
    database_read.open(resourcePath() + "user_data.txt");
    string data, Data[userlim][17];
    int x = 0;
    stringstream Entry;
    //Read exisiting data and save it into an array
    while (!database_read.eof() && x < userlim)
    {
        getline(database_read, data, '#');
        Entry << data;
        for (int y = 0; y < 17; y++)
            getline(Entry, Data[x][y], '\n');
        Entry.str("");
        Entry.clear();
        x++;
    }
    database_read.close();
    //find index
    str = "";
    for (int z = 0; z < x + 1; z++)
    {
        str += Data[z][0];
        str += '\t';
        str += Data[z][1];
        str += '\n';
    }
    
    
    text.setString(str);
    
    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        window.clear();
        window.draw(background);
        window.draw(text);
        window.display();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    main_menu(user1, menumusic, clickmusic);
                    
                    break;
                    
                case sf::Event::KeyPressed:
                    clickmusic.play();
                    window.close();
                    main_menu(user1, menumusic, clickmusic);
                    break;
                    
            }
        }
        
        
        
        
    }
    
}


void Helper(sf::RenderWindow &window, user &user1, sf::Music &menumusic, sf::Music &clickmusic)
{
    
    sf::Texture helptexture;
    sf::Sprite helper;
    if (!helptexture.loadFromFile(resourcePath() + "helper.png"))
        EXIT_FAILURE;
    helper.setTexture(helptexture);
    
    
    while (window.isOpen())
    {
        
        sf::Event event;
        window.clear();
        window.draw(helper);
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    main_menu(user1, menumusic, clickmusic);
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    clickmusic.play();
                    window.close();
                    main_menu(user1, menumusic, clickmusic);
                    break;
                }
            }
        }
        window.display();
    }
    
}


void main_menu(user &user1, sf::Music &menumusic, sf::Music &clickmusic)
{
    sf::Texture texture;
    sf::Sprite background;
    if (!texture.loadFromFile(resourcePath() + "castlebg.png"))
    {
        EXIT_FAILURE;
    }
    background.setTexture(texture);
    // Open Menu
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    Menu menu;
    menu.mainMenu(window.getSize().x, window.getSize().y);
    int index = 0;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        window.clear();
        window.draw(background);
        
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                {
                    case sf::Keyboard::Return:
                        clickmusic.play();
                        switch (index)
                    {
                        case 0:
                        {
                            play(window, user1, menumusic, clickmusic);
                            break;
                        }
                            
                        case 1:
                            window.close();
                            Settings(user1, menumusic, clickmusic);
                            break;
                        case 2:
                            window.close();
                            Highscores(user1, menumusic, clickmusic);
                            break;
                        case 3:
                            Helper(window, user1, menumusic, clickmusic);
                            break;
                        case 4:
                            store(window, user1, menumusic, clickmusic);
                            window.close();
                            break;
                        case 5:
                            window.close();
                            break;
                            
                    }
                        
                        break;
                    case sf::Keyboard::Down:
                        if (index < maxmitems - 1)
                        {
                            clickmusic.play();
                            menu.restore(index);
                            index++;
                            menu.changepos(index);
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (index > 0)
                        {
                            clickmusic.play();
                            menu.restore(index);
                            index--;
                            menu.changepos(index);
                        }
                        break;
                }
            }
        }
        menu.drawmenu(window, index);
        window.display();
    }
}


int user_initiation(int age, sf::Music &menumusic, sf::Music &clickmusic)
{
    
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    
    if (!texture.loadFromFile(resourcePath() + "entername.png"))
    {
        return EXIT_FAILURE;
    }
    
    background.setTexture(texture);
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    
    //Set Text
    std::string str;
    sf::Text text;
    sf::Font medieval, ringbearer;
    user user1;
    //Font Load
    if (!medieval.loadFromFile(directory + "Beyond Wonderland.ttf"))
        EXIT_FAILURE;
    if (!ringbearer.loadFromFile(directory + "XeroxB.ttf"))
        EXIT_FAILURE;
    
    
    text.setFont(medieval);
    text.setFillColor(sf::Color::Red);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(117, 74, 0));
    text.setPosition(screenX / 3 - 10, screenY / 2 + 260);
    text.setCharacterSize(100);
    std::locale loc;
    string result = "Name ?";
    text.setString(result);
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        //Draw Background and Text
        window.clear();
        window.draw(background);
        window.draw(text);
        window.display();
        
        

        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    userchoice(menumusic, clickmusic);
                    break;
                case sf::Event::TextEntered:
                {
                    if (event.text.unicode == '\b' && str.length() > 0)
                    {
                        str.erase(str.size() - 1, 1);
                        text.setFont(ringbearer);
                        text.setString(str);
                        break;
                    }
                    else if (event.text.unicode < 128 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && event.text.unicode != '\b'  && str.length() < 11)
                    {
                        str += toupper(static_cast<char>(event.text.unicode), loc);
                        text.setFont(ringbearer);
                        text.setString(str);
                        break;
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                    {
                        clickmusic.play();
                        result = user1.check_data(str);
                        switch (age)
                        {
                            case 1:
                            {
                                if (result == "1" || result == "Max reached")
                                {
                                    text.setString("Wrong name !");
                                    break;
                                }
                                else if (result == "Name exist!")
                                {
                                    user1.read_data(str);
                                    window.close();
                                    main_menu(user1, menumusic, clickmusic);
                                    break;
                                }
                                break;
                            }
                                
                            case 0:
                            {
                                if (result == "1")
                                {
                                    user1.create(str);
                                    window.close();
                                    main_menu(user1, menumusic, clickmusic);
                                    break;
                                }
                                else
                                {
                                    text.setString(result);
                                    break;
                                }
                            }
                            default:
                                break;
                                
                                
                        }
                        break;
                    }
                }
                default:
                    break;
                    
            }
        }
        
        
        
    }
    
}

void introscreen(sf::RenderWindow &window, sf::Music &menumusic, sf::Music &clickmusic)
{

    sf::Texture introtexture;
    sf::Sprite intro;
    if (!introtexture.loadFromFile(directory + "intro.png"))
        EXIT_FAILURE;
    intro.setTexture(introtexture);
    
    while (window.isOpen())
    {
        sf::Event event;
        window.clear();
        window.draw(intro);
        
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    user_initiation(0, menumusic, clickmusic);
                }
                    break;
                case sf::Event::KeyPressed:
                {
                    clickmusic.play();
                    window.close();
                    user_initiation(0, menumusic, clickmusic);
                }
                    
        
        
            }
        }
        window.display();
    }
    

}

void userchoice(sf::Music &menumusic, sf::Music &clickmusic)
{
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    
    if (!texture.loadFromFile(resourcePath() + "castlebg.png"))
    {
        EXIT_FAILURE;
    }
    
    background.setTexture(texture);
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    
    
    
    Menu menu;
    menu.userMenu(window.getSize().x, window.getSize().y);
    int index = 0;
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        window.clear();
        window.draw(background);
        
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                {
                    case sf::Keyboard::Return:
                        clickmusic.play();
                        switch (index)
                    {
                        case 0:
                        {
                            introscreen(window, menumusic, clickmusic);
                            break;
                        }
                        case 1:
                        {
                            window.close();
                            user_initiation(1, menumusic, clickmusic);
                            break;
                        }
                        case 2:
                            //window.close();
                            //deleteuser();
                            break;
                        case 3:
                            window.close();
                            break;
                            
                    }
                        
                        break;
                    case sf::Keyboard::Down:
                        if (index < maxmitems - 2)
                        {
                            clickmusic.play();
                            menu.restore(index);
                            index++;
                            menu.changepos(index);
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (index > 0)
                        {
                            clickmusic.play();
                            menu.restore(index);
                            index--;
                            menu.changepos(index);
                        }
                        break;
                    
                }
            }
        }
        menu.drawmenu(window, index);
        window.display();
    }
    
}

int main()
{
    //Background Image Set
    sf::Texture texture;
    sf::Sprite background;
    sf::Music menumusic, clickmusic;

    if (!clickmusic.openFromFile(directory + "click-sound.ogg"))
        EXIT_FAILURE;
    

    if (!texture.loadFromFile(resourcePath() + "anykey.png"))
        EXIT_FAILURE;
    if (!menumusic.openFromFile(directory + "Wolven_Storm.ogg"))
        EXIT_FAILURE;
        
    background.setTexture(texture);
    menumusic.play();
    
    //Window size set
    sf::RenderWindow window(sf::VideoMode(screenX, screenY), "Brojekt");
    
    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        window.clear();
        window.draw(background);
        window.display();
        
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::KeyPressed:
                    clickmusic.setVolume(15);
                    clickmusic.play();
                    window.close();
                    userchoice(menumusic, clickmusic);
                    break;
                    
            }
        }
        
    }
    return 0;
}

