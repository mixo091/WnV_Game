#include <iostream>
#include <vector>

using namespace std;

class Creatures
{
    char type;
    int pos1, pos2;
    int potions;
    int strength;
    int shield;

    public:
    Creatures();
    ~Creatures();
    virtual void move() = 0;
    virtual void attack();
    virtual void heal();
};

class Avatar
{
    

};

class Vampires
{

};

class Werewolves
{

};