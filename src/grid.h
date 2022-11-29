#include <iostream>
#include <vector>

using namespace std;

struct tile
{

    char type;
    //  Living* m;
    int x, y;

public:
    tile(char t, int p1, int p2);
};

class Grid
{

    public:
    int d1, d2;
    vector<vector<tile>> grid;

    Grid(int x, int y);
    ~Grid();
    void diplay();
};