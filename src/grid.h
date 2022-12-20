#pragma once
#include <iostream>
#include <vector>
#include "coordinates.h"
#include "./creatures.h"

using namespace std;
class Creature;

// == tile implementation == /

struct tile
{

    char type;
    bool hasPotion;
    Creature *being;
    coordinates pos;

    tile(char t, int p1, int p2)
    {
        type = t;
        pos.x = p1;
        pos.y = p2;
        being = NULL;
        hasPotion = false;
    }
};

class Grid
{

    int d1, d2;
    vector<vector<tile>> grid;
    bool isDay = true;
    vector<coordinates> land_coor;
    friend class Creature;
    friend class Avatar;
    friend class Game;

public:
    // Funcionality //
    Grid(int x, int y);
    void display();
    void display_tiles();
    ~Grid();
    void set_being(Creature *);
    void setDay(bool x) { isDay = x; };
    coordinates get_available_tile_coordinates();
    int get_d1();
    int get_d2();
    vector<vector<tile>> get_grid();
    bool get_isDay();
    vector<coordinates> get_land_coor();
};