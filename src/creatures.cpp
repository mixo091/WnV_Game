#include <iostream>
#include <vector>
#include "./creatures.h"
#include "./grid.h"
#include <string>
#define Health 6

using namespace std;

Creature::Creature(Grid *g, char t, coordinates pos, int pots, int stren, int shi)
{
    this->type = t;
    this->isDead = false;
    this->position = pos;
    this->potions = rand()%3;
    this->strength = 1+rand()%3;
    this->shield = 1+rand()%2;
    this->health = Health;
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

    if ((map->grid[pos.x][pos.y].type == ' ') && (map->grid[pos.x][pos.y].being == NULL) && (map->grid[pos.x][pos.y].hasPotion == false ))
    {
        return true;
    }
    return false;
}

void Creature::move()
{
}



vector<Creature*> Creature::get_neighbors(){

    coordinates neighbor_tiles [] =  { {position.x-1,position.y} , {position.x+1,position.y} , {position.x,position.y+1} , {position.x,position.y-1} };
     vector<Creature*> neighbors;

     cout<<"ok1"<<endl;

    for ( int i = 0 ; i < 4 ; i++){

        if(!((neighbor_tiles[i].x < 0 || neighbor_tiles[i].x > map->d1 - 1) || (neighbor_tiles[i].y < 0 || neighbor_tiles[i].y > map->d2 - 1))  &&  map->grid[neighbor_tiles[i].x][neighbor_tiles[i].y].being != NULL ){
            cout<<"exee geitona" <<endl;
            neighbors.push_back(map->grid[neighbor_tiles[i].x][neighbor_tiles[i].y].being);
            //cout<<"ser " <<neighbors[i]->get_strength()<<endl;
        } 
    }

    cout<<"ok2"<<endl;
    
    return neighbors;

}


char Creature::get_team(){return type;}

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




int Creature::get_health(){return health;}
void Creature::inc_health(int x){ health +=x;}
void Creature::dec_health(int x){if ( x > 0){health-=x;}}
int Creature::get_shield(){return shield;}
int Creature::get_strength(){return strength;}
int Creature::get_potions(){return potions;}
void Creature::dec_potions(){ potions -=1;}
bool Creature::is_dead(){return isDead;}
void Creature::attack(Creature* b){
    b->dec_health( this->get_strength() - b->get_shield());
};
bool Creature :: isCorpse(){ 
    if(health<=0){
        isDead = true;

        map->grid[position.x][position.y].being = NULL;
        return true ;
        
    }
        
    return false;}


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
    this->potions = 1;
}


bool Avatar::is_legal_move(coordinates pos)
{
    if ((pos.x < 0 || pos.x > map->d1 - 1) || (pos.y < 0 || pos.y > map->d2 - 1))
    {
        return false;
    }

    if ((map->grid[pos.x][pos.y].type == ' ') && (map->grid[pos.x][pos.y].being == NULL)  )
    {
        return true;
    }
    return false;
}

void Avatar::inc_potions(){
    potions++;
}

bool Avatar::potion_check(){
    if (map->grid[position.x][position.y].hasPotion){
        inc_potions();
        map->grid[position.x][position.y].hasPotion = false;
        return true;
    }
    return false;
}



Avatar::~Avatar()
{
}