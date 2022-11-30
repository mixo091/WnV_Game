#include <iostream>
#include <vector>
#include "./creatures.h"

using namespace std;

Creature::Creature(char t, being_coordinates pos, int pots, int stren, int shi)
{
    this->type = t;
    this->position = pos;
    this->potions = pots;
    this->strength = stren;
    this->shield = shi;
}

Creature::~Creature() {}

Vampire::Vampire(char t, being_coordinates pos, int pots, int stren, int shi) : Creature(t, pos, pots, stren, shi)
{
    cout << "Vampire created!" << endl;
}

Vampire::~Vampire()
{
}

void Vampire::move()
{
    cout << "move" << endl;
}

Werewolf::Werewolf(char t, being_coordinates pos, int pots, int stren, int shi) : Creature(t, pos, pots, stren, shi)
{
    cout << "Werewolf created!" << endl;
}

Werewolf::~Werewolf()
{
}

void Werewolf::move()
{
    cout << "move" << endl;

}




Avatar::Avatar(char t, being_coordinates pos, int pots, int stren, int shi) : Creature(t, pos, pots, stren, shi)
{
    cout << "Avatar created!" << endl;
}

Avatar::~Avatar()
{
}

void Avatar::move()
{
    cout << "move" << endl;
}