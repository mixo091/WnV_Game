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
        bool is_legal_move(coordinates);
        void set_coordinates(coordinates);
        coordinates get_coordinates();
        void move_to_tile(coordinates);
        void move_up();
        void move_down();
        void move_left();
        void move_right();
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