//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//

#include "user.h"
#include<fstream>
#include<sstream> //String stream to read user data
#include<string>
#include <iostream>
using namespace std;

string directory2 = "/Users/Khalid/Desktop/Brojekt/Brojekt/files/";

void database_retreive(int &actlim, string Data[][17])
{
    ifstream database_read;
    database_read.open(directory2 + "user_data.txt");
    string data;
    stringstream Entry;
    //Read exisiting data and save it into an array
    int x = 0;
    while (!database_read.eof() && actlim < userlim)
    {
        getline(database_read, data, '#');
        Entry << data;
        for (int y = 0; y < 17; y++)
        {
            getline(Entry, Data[x][y], '\n');
        }
        Entry.str("");
        Entry.clear();
        x++;
    }
    actlim = x;
    database_read.close();
}

user::user()
{
    music = true;
    index = 0;
    database_retreive(actlim, Data);
}


//Add a new user
void user::create(string username)
{
    ofstream database_write;
    database_write.open(directory2 + "user_data.txt", ios::app);
    name = username;
    highscore = 0;
    level = 1;
    sprites = 1001;
    coins = 0;
    fireballs = 10;
    traps = 0;
    for (int u = 0; u < 10; u++)
        levelscore[u] = 0;
    database_write << name << endl;
    database_write << "0" << endl;
    database_write << "1" << endl;
    database_write << "1000" << endl;
    database_write << "0" << endl;
    database_write << "10" << endl;
    database_write << "0" << endl;
    for (int u = 7; u < 16; u++)
        database_write << "0" << endl;
    database_write << "0" << "#";
    database_write.close();
    
}

int user::set_totalscore()
{
    int totalscoree = 0;
    for (int x = 0; x < 10; x++)
        totalscoree = totalscoree + levelscore[x];
    return totalscoree;
    
}

void user::update_highscores(string &ste)
{
    //string sorted[userlim];
    ste += name;
    ste += '\t';
    for (int z = 0; z < userlim; z++)
    {
        if (Data[z][0] == name)
        {
            ste += Data[index][1];
            ste += '\n';
        }
    }
    for (int z = 0; z < userlim; z++)
    {
        if (Data[z][0] != name)
        {
            ste += Data[z][0];
            ste += '\t';
            ste += Data[z][1];
            ste += '\n';
        }
    }
}
//Check that user exists
string user::check_data(string username)
{
    string result;
    bool found = false;
    for (int z = 0; z < actlim + 1; z++)
        if (Data[z][0] == username)
            found = true;
    if (found)
        result = "Name exist!";
    else if (actlim >= userlim)
        result = "Max reached";
    else
        result = "1";
    
    return result;
}


//Find and read user data
void user::read_data(string username)
{
    stringstream temp;
    for (int z = 0; z < actlim + 1; z++)
    {
        if (Data[z][0] == username)
        {
            index = z;
            break;
        }
    }
    
    //Save User Data into the object
    name = username;
    temp << Data[index][1];
    temp >> highscore;
    temp.clear();
    temp << Data[index][2];
    temp >> level;
    temp.clear();
    temp << Data[index][3];
    temp >> sprites;
    temp.clear();
    temp << Data[index][4];
    temp >> coins;
    temp.clear();
    temp << Data[index][5];
    temp >> fireballs;
    temp.clear();
    temp << Data[index][6];
    temp >> traps;
    temp.clear();
    for (int p = 0; p < 10; p++)
    {
        temp << Data[index][7+p];
        temp >> levelscore[p];
        temp.clear();
    }
}


//Update User Data after level ends
void user:: level_end  (int new_level, int new_coins, int level_highscore, int new_fireballs, int new_traps, int scode)
{
    ofstream database_write;
    level = new_level;
    coins += new_coins;
    levelscore[new_level - 1] = level_highscore;
    fireballs = new_fireballs;
    traps = new_traps;
    sprites = scode;
    highscore = set_totalscore();
    //Save user data into the database (text file)
    database_write.open(directory2 + "user_data.txt");
    cout << actlim;
    for (int y = 0; y < actlim - 1; y++)
    {
        if (y == index)
        {
            
            database_write << Data[index][0] << endl << std::to_string(highscore) << endl << std::to_string(new_level + 1) << endl << std::to_string(scode)
            << endl << std::to_string(coins) << endl << std::to_string(new_fireballs) << endl << std::to_string(new_traps) << endl;
            
            //Update Level Scores
            for (int y = 7; y < new_level + 6; y++)
                database_write << Data[index][y] << endl;
            
            if (level == 10)
                database_write << std::to_string(level_highscore) << "#";
            else
            {
                database_write << std::to_string(level_highscore) << endl;
                for (int f = level + 7; f < 16; f++)
                    database_write << Data[index][f] << endl;
                database_write << Data[index][16] << "#";
            }
            
        }
        else
        {
            for (int l = 0; l < 7; l++)
                database_write << Data[y][l] << endl;
            
            //Update Level Scores
            for (int u = 7; u < 16; u++)
                database_write << Data[y][u] << endl;
            
            database_write << Data[y][16] << "#";
            
        }
    }
    //database_write.flush();
    database_write.close();
}





//Update Store purchases
void user::update_purchases(int new_fireballs, int new_traps, int scode, int new_coins)
{
    
    level_end(level-1, new_coins, levelscore[level-2], new_fireballs, new_traps, scode);
}
