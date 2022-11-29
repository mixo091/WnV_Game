#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./grid.h"

#define tree '^'
#define water '~'
#define land ' '

using namespace std;

char getLandscape()
{
    double val = (double)rand() / RAND_MAX;
    char terrain;
    if (val < 0.4) // land.
        terrain = land;
    else if (val < 0.7) // trees.
        terrain = tree;
    else // water.
        terrain = water;

    return terrain;
}

//== Grid Implementation. ==//

// -- Grid Constructor -- //

Grid::Grid(int x, int y)
{
    this->d1 = x;
    this->d2 = y;

    int per = 0.6 * (x * y);
    cout << per << endl;

    // initialize random seed.
    srand(time(NULL));

    for (int i = 0; i < x; i++)
    {
        vector<tile> sub_vec;
        grid.push_back(sub_vec);

        for (int j = 0; j < y; j++)
        {

            tile new_tile(getLandscape(), i, j);
            grid[i].push_back(new_tile);
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {

            // cout << grid[i][j].type << "[ " << grid[i][j].x << "," << grid[i][j].y << " ]" << endl;
        }
    }
}
