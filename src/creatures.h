#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct being_coordinates
{
    int x;
    int y;
};

class Creature
{
    public:
    char type;
    being_coordinates position;
    int potions;
    int strength;
    int shield;

    Creature(char, being_coordinates, int, int, int);
    ~Creature();
    virtual void move() = 0;
    //virtual void attack();
    //virtual void heal();
};

// class Avatar
// {
    

// };

class Vampire: public Creature
{
    public:
    Vampire(char, being_coordinates, int, int, int);
    ~Vampire();
    void move();
};

class Werewolf: public Creature
{
    public:
    Werewolf(char, being_coordinates, int, int, int);
    ~Werewolf();
    void move();
};


class Avatar:public Creature{
    public:

        Avatar(char,being_coordinates,int,int,int);
        ~Avatar();
        void move();


};