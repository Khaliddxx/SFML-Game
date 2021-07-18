//
//  random.hpp
//  Brojekt
//
//  Created by Khalid Mohamed on 12/7/17.
//  Copyright © 2017 Khalid Mohamed. All rights reserved.
//

#ifndef random_h
#define random_h

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include "ResourcePath.h"
#include <cstdlib>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>
using namespace std;

int generateRandom(int max);
int generateRandom0(int max);
bool generateRandomBool();

#endif  /* random_hpp */
