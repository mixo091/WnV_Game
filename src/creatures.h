#pragma once
#include <iostream>
#include <vector>
#include "coordinates.h"


using namespace std;


class Creature
{
    public:

  
        char type;
        coordinates position;
        int potions;
        int strength;
        int shield;
        // Grid* map;

        Creature(char, coordinates, int, int, int);
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
    Vampire(char, coordinates, int, int, int);
    ~Vampire();
    void move();
};

class Werewolf: public Creature
{
    public:
    Werewolf(char, coordinates, int, int, int);
    ~Werewolf();
    void move();
};


class Avatar:public Creature{
    public:

        Avatar(char,coordinates,int,int,int);
        ~Avatar();
        void move();


};