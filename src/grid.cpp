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

// -- Grid Display Function --//
void Grid::display()
{

    for (int i = 0; i < d1; i++)
    {
        cout << "==";
        if (i == d1 - 1)
        {
            cout << "===" << endl;
        }
    }

    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            if (j == 0)
            {
                cout << "| ";
            }
            cout << grid[i][j].type << " ";
            if (j == d2 - 1)
            {
                cout << "|";
                cout << endl;
            }
        }
    }
    for (int i = 0; i < d1; i++)
    {
        cout << "==";
        if (i == d1 - 1)
        {
            cout << "===" << endl;
        }
    }
}

//-- Grid Destructor --//
Grid::~Grid() { cout << "Grid Destroyed" << endl; }

//-- Grid setBeings --//
void Grid::setBeing(vector<being_coordinates> &vec, Creature *b)
{
    being_coordinates temp;
    temp = vec[0];
    grid[temp.x][temp.y].being = b;
    grid[temp.x][temp.y].type = grid[temp.x][temp.y].being->type;
}