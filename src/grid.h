#pragma once
#include <iostream>
#include <vector>
#include "./creatures.h"


using namespace std;



// == tile implementation == /
struct coordinates
{
    int x;
    int y;
};

struct tile
{

    char type;
    Creature* being = NULL;
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

    // Funcionality //
    public:
    Grid(int x, int y);
    void display();
    ~Grid() ;
    void setBeing(vector<being_coordinates>&, Creature*);
};