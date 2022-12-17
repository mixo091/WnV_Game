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
    Creature* being;
    coordinates pos;

public:
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

    public:
    int d1, d2;
    vector<vector<tile>> grid;
    bool isDay = true;
    vector<coordinates> land_coor;

    // Funcionality //
    
    Grid(int x, int y);
    void display();
    void display_tiles();
    ~Grid() ;
    void set_being(Creature*);
    void setDay(bool x){isDay = x;};
    coordinates get_available_tile_coordinates();
};