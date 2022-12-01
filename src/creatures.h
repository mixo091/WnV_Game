#pragma once
#include <iostream>
#include <vector>
#include "coordinates.h"
#include "grid.h"
#include <string>


using namespace std;
class Grid;

class Creature
{
    public:

  
        char type;
        coordinates position;
        int potions;
        int strength;
        int shield;
        Grid* map;

        Creature(Grid*,char, coordinates, int, int, int);
        ~Creature();
        void set_coordinates(coordinates);
        coordinates get_coordinates();
        virtual void move() = 0;
        //virtual void attack();
        //virtual void heal();
};



class Vampire: public Creature
{
    public:
    Vampire(Grid*,char, coordinates, int, int, int);
    ~Vampire();
    void move();
};

class Werewolf: public Creature
{
    public:
    Werewolf(Grid*,char, coordinates, int, int, int);
    ~Werewolf();
    void move();
};


class Avatar:public Creature{
    public:

        Avatar(Grid*,char,coordinates,int,int,int);
        ~Avatar();
        void move();
        void move1(string);


};