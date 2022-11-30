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

Grid::Grid(int x, int y ,)
{
    this->d1 = x;
    this->d2 = y;
    srand(time(NULL));

    for (int i = 0; i < x; i++)
    {
        vector<tile> sub_vec;
        grid.push_back(sub_vec);
        vector <coordinates> available_positions;
        char terrain;
        for (int j = 0; j < y; j++)
        {
            terrain = getLandscape();
            if (terrain == land){  coordinates t{i,j} ; land_coor.push_back(t); available_positions.push_back(t);}
            tile new_tile(terrain, i, j);
            grid[i].push_back(new_tile);
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
void Grid::setBeing(vector<coordinates> &vec, Creature *b)
{
    coordinates temp;
    temp = vec[0];
    grid[temp.x][temp.y].being = b;
    grid[temp.x][temp.y].type = grid[temp.x][temp.y].being->type;
}


// Get random available tile for Creature Placement.
coordinates Grid:get_available_tile_coordinates(){

    vector<coordinates> available_tiles ; 
    for ( unsigned int i = 0; i < this->land_coor.size(); i++ ){
        if(grid[this->land_coor[ i ].x][this->land_coor[i].y].being == NULL){
            available_tiles.push_back(land_coor[i]);
        }
    }
    random_tile = rand % available_tiles.size();
    coordinates tile{ available_tiles[random_tile].x, available_tiles[random_tile].y};
    available_tiles.clear();
    return tile;

}


void Grid::set_being(Creature* being){

    // Get available tile.
    /*A tile is available when it is land and it has no other Creature on it*/
    coordinates available_pos{0,0};
    available_pos = this->get_available_tile_coordinates();

   

}