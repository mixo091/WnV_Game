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
    if ((map->grid[pos.x][pos.y].type == ' ') & (map->grid[pos.x][pos.y].being == NULL))
    {
        return true;
    }
    return false;
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

void Vampire::move()
{
    cout << "move" << endl;
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
    cout << "move" << endl;
}

Avatar::Avatar(Grid *g, char t, coordinates pos, int pots, int stren, int shi) : Creature(g, t, pos, pots, stren, shi)
{
    // cout << "Avatar created!" << endl;
}

Avatar::~Avatar()
{
}

void Avatar::move() {}

void Avatar::move1(string direction)
{

    coordinates avatar_pos = get_coordinates();
    if (direction == "Up")
    {

        cout << "pathsa" << endl;

        coordinates wanted_move{avatar_pos.x - 1, avatar_pos.y};
        cout << "i am " << avatar_pos.x << " , " << avatar_pos.y << endl;
        cout << "want:" << wanted_move.x << " , " << wanted_move.y << endl;
        // bool legal_move = map->grid[wanted_move.x][wanted_move.y].get_availability();
        if (1)
        {
            map->grid[avatar_pos.x][avatar_pos.y].type = ' ';
            set_coordinates(wanted_move);
            map->grid[wanted_move.x][wanted_move.y].being = this;
            map->grid[wanted_move.x][wanted_move.y].type = this->type;
        }
    }
}