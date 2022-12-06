#include <iostream>
#include "./grid.h"
#include "./creatures.h"
#include "./game.h"

int main(int argc , char* argv[])
{
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    char team = *argv[3];
    Game game(x,y,team);
    game.gamePlay();
    return 0;
}
