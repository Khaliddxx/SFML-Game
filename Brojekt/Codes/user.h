//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//


#ifndef user_hpp
#define user_hpp


#include<string>
using namespace std;
const int userlim = 5;

class user
{
public:
    
    //User Variables
    string name;
    int highscore, level, coins, fireballs, traps, levelscore[10], sprites, id;
    bool music, processing;
    bool lvl1 = true, lvl2 = false, lvl3 = false;
    int actlim, index;
    
    string Data[userlim][17];
    
    //User Set
    user();
    
    //User Update
    
    void update_highscores(string &ste);
    void level_end(int new_level, int new_coins, int levelscore, int new_fireballs, int new_traps, int scode);
    void update_purchases(int new_fireballs, int new_traps, int scode, int new_coins);
    void read_data(string username);
    string check_data(string username);
    void create(string username);
    int set_totalscore();
    
private:
};



#endif /* player_hpp */
