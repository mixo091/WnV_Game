#include <iostream>
#include <vector>
#include "./creatures.h"
#include "./grid.h"
#include <string>

using namespace std;

Creature::Creature(Grid *g, char t, coordinates pos, int pots, int stren, int shi)
{
    this->type = t;
    this->position = pos;
    this->potions = pots;
    this->strength = stren;
    this->shield = shi;
    this->map = g;
}

void Creature::set_coordinates(coordinates pos)
{
    this->position = pos;
}

coordinates Creature::get_coordinates()
{
    return this->position;
}

bool Creature::is_legal_move(coordinates pos)
{
    if ((pos.x < 0 || pos.x > map->d1 - 1) || (pos.y < 0 || pos.y > map->d2 - 1))
    {
        return false;
    }

    if ((map->grid[pos.x][pos.y].type == ' ') && (map->grid[pos.x][pos.y].being == NULL))
    {
        return true;
    }
    return false;
}

void Creature::move()
{
}

void Creature::move_to_tile(coordinates pos)
{
    if (is_legal_move(pos))
    {
        map->grid[position.x][position.y].being = NULL;
        set_coordinates(pos);
        map->grid[pos.x][pos.y].being = this;
    }
}

void Creature::move_up()
{
    coordinates wanted_move{position.x - 1, position.y};
    move_to_tile(wanted_move);
}

void Creature::move_down()
{
    coordinates wanted_move{position.x + 1, position.y};
    move_to_tile(wanted_move);
}

void Creature::move_left()
{
    coordinates wanted_move{position.x, position.y - 1};
    move_to_tile(wanted_move);
}

void Creature::move_right()
{
    coordinates wanted_move{position.x, position.y + 1};
    move_to_tile(wanted_move);
}

Creature::~Creature() {}

Vampire::Vampire(Grid *g, char t, coordinates pos, int pots, int stren, int shi) : Creature(g, t, pos, pots, stren, shi)
{
    // cout << "Vampire created!" << endl;
}

Vampire::~Vampire()
{
}


void Vampire::move_up_right()
{
    coordinates wanted_move{position.x - 1, position.y+1};
    move_to_tile(wanted_move);
}

void Vampire::move_down_right()
{
    coordinates wanted_move{position.x + 1, position.y+1};
    move_to_tile(wanted_move);
}

void Vampire::move_up_left()
{
    coordinates wanted_move{position.x-1, position.y - 1};
    move_to_tile(wanted_move);
}

void Vampire::move_down_left()
{
    coordinates wanted_move{position.x+1, position.y-1};
    move_to_tile(wanted_move);
}




void Vampire::move()
{
    int prob = rand() % 9;
    cout << "rand = " << prob << endl;
    switch (prob)
    {
    case 0:
        move_up();
        break;
    case 1:
        move_down();
        break;
    case 2:
        move_left();
        break;
    case 3:
        move_right();
        break;
    case 4:
        // Stays still
        break;
    case 5:
        move_down_left();
        break;
    case 6:
        move_up_left();
        break;
    case 7:
        move_down_right();
        break;
    case 8:
        move_up_right();
        break;
    }
    return;
}

Werewolf::Werewolf(Grid *g, char t, coordinates pos, int pots, int stren, int shi) : Creature(g, t, pos, pots, stren, shi)
{
    // cout << "Werewolf created!" << endl;
}

Werewolf::~Werewolf()
{
}

void Werewolf::move()
{
    int prob = rand() % 5;
    cout << "rand = " << prob << endl;
    switch (prob)
    {
    case 0:
        move_up();
        break;
    case 1:
        move_down();
        break;
    case 2:
        move_left();
        break;
    case 3:
        move_right();
        break;
    case 4:
        // Stays still
        break;
    }
    return;
}

Avatar::Avatar(Grid *g, char t, coordinates pos, int pots, int stren, int shi) : Creature(g, t, pos, pots, stren, shi)
{
    // cout << "Avatar created!" << endl;
}

Avatar::~Avatar()
{
}