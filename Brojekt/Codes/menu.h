//
//  menu.hpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//



#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef menu_hpp
#define menu_hpp
const int maxmitems = 6;
const int maxPitems = 3;

class Menu
{
public:
    
    // constructors
    void mainMenu(float, float);
    void userMenu(float, float);
    void PlayMenu(float, float, sf::RenderWindow &window);
    void changepos(int);
    void restore(int);

    void drawmenu(RenderWindow &window, int index);
    void clearmenu(sf::RenderWindow &window);
    
    // Managing the "Play" Menu
    void drawPlaymenu(RenderWindow &window, int index);
    void pmchangepos(int);
    void pmrestore(int);
    
private:
    int selectedItemIndex;
    Font font;
    Texture level1, level2, level3, swordtexture;
    Sprite sword;
    Text mmenu[maxmitems];
    Sprite pmenu[maxPitems];
    
};




#endif /* menu_hpp */
