//
//  random.cpp
//  Brojekt
//
//  Created by Khalid Mohamed on 12/7/17.
//  Copyright © 2017 Khalid Mohamed. All rights reserved.
//

#include "random.h"

int generateRandom(int max)
{
    int randomNumber = rand();
    float random = (randomNumber % max) + 1;
    int myRandom = random;
    return myRandom;
}

int generateRandom0(int max)
{
    int randomNumber = rand();
    float random = (randomNumber % max);
    int myRandom = random;
    return myRandom;
}

bool generateRandomBool()
{
    int randomNumber = rand();
    float random = (randomNumber % 2) + 1;
    int myRandom = random;
    if (myRandom == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

