#pragma once
#include <iostream>
#include <vector>


using namespace std;



// == tile implementation == /

struct tile
{

    char type;
    //Living* m;
    int x, y;

public:
    tile(char t, int p1, int p2)
    {
        type = t;
        x = p1;
        y = p2;
    }
};

class Grid
{

public:
    int d1, d2;
    vector<vector<tile>> grid;

    // Funcionality //

    Grid(int x, int y);
    void display();
    ~Grid() ;
};