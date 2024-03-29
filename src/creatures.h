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
    char type;
    int id;
    int strength;
    int shield;
    int health;
    bool isDead;

protected:
    coordinates position;
    int potions;
    Grid *map;

public:
    Creature(Grid *, char, coordinates, int, int, int);
    ~Creature();
    virtual bool is_legal_move(coordinates);
    void set_coordinates(coordinates);
    coordinates get_coordinates();
    void move_to_tile(coordinates);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    virtual void move(int) = 0;
    int get_id();
    int get_health();
    int get_shield();
    int get_potions();
    int get_strength();
    void inc_health(int x);
    void dec_health(int x);
    void dec_potions();
    bool is_dead();
    char get_team();
    vector<Creature *> get_neighbors();
    void attack(Creature *);
    virtual void heal(Creature *b);
    bool isCorpse();
    bool try_to_evade(int);
    // virtual void attack();
    // virtual void heal();
};

class Vampire : public Creature
{
public: // Kinountai kai diagonia
    Vampire(Grid *, char, coordinates, int, int, int);
    ~Vampire();
    void move_up_left();
    void move_up_right();
    void move_down_left();
    void move_down_right();
    void move(int);
};

class Werewolf : public Creature
{
public:
    Werewolf(Grid *, char, coordinates, int, int, int);
    ~Werewolf();
    void move(int);
};

class Avatar : public Creature
{
public:
    Avatar(Grid *, char, coordinates, int, int, int);
    ~Avatar();
    bool is_legal_move(coordinates);
    bool potion_check();
    void inc_potions();
    void heal(vector<Creature *> &);
    void move(int);
};