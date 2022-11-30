#pragma once
#include <iostream>
#include <vector>
#include "coordinates.h"
#include "grid.h"

using namespace std;


class Creature
{
    public:
    Grid* map;
    char type;
    coordinates position;
    int potions;
    int strength;
    int shield;

    Creature(Grid* ,char, coordinates, int, int, int);
    ~Creature();
    virtual void move() = 0;
    //virtual void attack();
    //virtual void heal();
};



class Vampire: public Creature
{
    public:
    Vampire(Grid* ,char, coordinates, int, int, int);
    ~Vampire();
    void move();
};

class Werewolf: public Creature
{
    public:
    Werewolf(Grid* ,char, coordinates, int, int, int);
    ~Werewolf();
    void move();
};


class Avatar:public Creature{
    public:

        Avatar(Grid* ,char,coordinates,int,int,int);
        ~Avatar();
        void move();


};