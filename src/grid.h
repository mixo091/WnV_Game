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
    Creature* being  = NULL;
    coordinates pos;

public:
    tile(char t, int p1, int p2)
    {
        type = t;
        pos.x = p1;
        pos.y = p2;
    }
};

class Grid
{

    public:
    int d1, d2;
    vector<vector<tile>> grid;
    vector<coordinates> land_coor;

    // Funcionality //
    
    Grid(int x, int y);
    void display();
    ~Grid() ;
    void set_being(Creature*);
    coordinates get_available_tile_coordinates();
};