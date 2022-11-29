#include <iostream>
#include <vector>
#include "grid.h"

using namespace std;

tile::tile(char t, int p1, int p2)
{
    type = t;
    x = p1;
    y = p2;
}

Grid::Grid(int x, int y)
{
    this->d1 = x;
    this->d2 = y;

    for (int i = 0; i < x; i++)
    {

        vector<tile> sub_vec;
        grid.push_back(sub_vec);

        for (int j = 0; j < y; j++)
        {
            tile new_tile('x', i, j);
            grid[i].push_back(new_tile);
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {

            cout << grid[i][j].type << "[ " << grid[i][j].x << "," << grid[i][j].y << " ]" << endl;
        }
    }
}

void Grid::diplay()
{

    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {

            cout << grid[i][j].type << " ";

            if (j == d2 - 1)
            {
                cout << endl;
            }
        }
    }
}

Grid::~Grid()
{
    cout << "Grid Destroyed" << endl;
}