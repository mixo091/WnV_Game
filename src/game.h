#pragma once
#include <iostream>
#include <vector>
#include "./grid.h"
#include "./creatures.h"
#include <stdio.h>
#include <unistd.h>
#include <bits/stdc++.h>
#define W 119
#define S 115
#define D 100
#define A 97
#define H 104
#define ENTER 10
#define PAUSE 32
#define Health 2

//-- Game Class Implementation. --//

class Game
{
    // Attributes
    vector<Creature *> beings;
    Avatar *avatar;
    Grid *map;
    bool isDay;

public:
    // Methods
    Game(int, int, char);
    ~Game();
    void printStats();
    void spawn_potion();
    void set_being(Creature *);
    int getIndex(Creature *b);
    void initializeGame(int d1, int d2, char team);
    void BeingsEngagement();
    void ClearScreen(); // Function to Clear Game Screen.
    void gamePlay();
    int get_random_move(Creature *);
};
