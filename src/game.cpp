#include "game.h"

using namespace std;

Game::Game(int d1, int d2, char team)
{
    initializeGame(d1, d2, team);
}

void Game::spawn_potion()
{
    coordinates available_pos{0, 0};
    available_pos = map->get_available_tile_coordinates();
    map->grid[available_pos.x][available_pos.y].hasPotion = true;
}

void Game::printStats()
{
    ClearScreen();
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "|                    GAME STATS                  |" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << "Avatar health: " << avatar->get_health() << " , potions : " << avatar->get_potions() << endl;

    for (unsigned int i = 0; i < beings.size(); i++)
    {
        cout << "id: " << beings[i]->id << " " << beings[i]->get_team() << "[" << to_string(i) << "]"
             << "::"
             << "Hp: " << beings[i]->get_health() << "|Pwr: " << beings[i]->get_strength() << "|Def: " << beings[i]->get_shield() << "|Potions: " << beings[i]->get_potions() << "|Dead: " << beings[i]->is_dead() << "|" << endl;
    }
}

void Game::set_being(Creature *b)
{

    // Get available tile.
    /*A tile is available when it is land and it has no other Creature on it*/
    coordinates available_pos{0, 0};
    available_pos = map->get_available_tile_coordinates();
    map->grid[available_pos.x][available_pos.y].being = b;
    b->set_coordinates(available_pos);
    cout << map->grid[available_pos.x][available_pos.y].being->type << endl;
}

int Game::getIndex(Creature *b)
{
    auto it = find(beings.begin(), beings.end(), b);

    // If element was found
    if (it != beings.end())
    {

        // calculating the index
        // of K
        int index = it - beings.begin();
        return index;
    }
    else
    {
        return -1;
    }
}

void Game::initializeGame(int d1, int d2, char team)
{

    // Create Grid-Map.
    map = new Grid(d1, d2);
    map->display();

    spawn_potion();
    // Create Player's Avatar.
    coordinates avatar_pos{0, 0};
    this->avatar = new Avatar(map, team, avatar_pos, 1, 1, 1);
    // avatar_pos = map->get_available_tile_coordinates();
    cout << avatar_pos.x << " , " << avatar_pos.y << endl;
    // map->setBeing(avatar_pos, avatar);
    set_being(avatar);

    //--Create Vampires.
    Creature *temp;
    int max_creatures = (d1 * d2) / 15;
    int num_of_creatures = (d1 * d2) / 30 + rand() % (max_creatures - 3);
    int vampires_num = num_of_creatures / 2;
    for (int i = 0; i < vampires_num; i++)
    {
        coordinates vampire_pos{0, 0};
        temp = new Vampire(map, 'B', vampire_pos, i, 1, 1);
        beings.push_back(temp);
        set_being(beings[i]);
    }
    //-- Create Werewolves.
    for (int i = vampires_num; i < vampires_num * 2; i++)
    {
        coordinates werewolves_pos{0, 0};
        temp = new Werewolf(map, 'L', werewolves_pos, i, 1, 1);
        beings.push_back(temp);
        set_being(beings[i]);
    }

    map->display();
}

void Game::BeingsEngagement()
{

    vector<Creature *> neighbors;
    int j = 0;
    for (unsigned int i = 0; i < beings.size(); i++)
    {
        neighbors = beings[i]->get_neighbors();
        if (neighbors.size() != 0)
        {
            j = rand() % (int)neighbors.size();
            cout << "J :" << j << endl;
        }
        else
        {
            continue;
        }

        // Is he on my team ?
        if (beings[i]->get_team() != neighbors[j]->get_team())
        {

            if (beings[i]->get_strength() >= neighbors[j]->get_strength() && beings[i]->isDead == false)
            {
                // Chance to evade..
                if (neighbors[j]->try_to_evade() == false)
                {
                    beings[i]->attack(neighbors[j]);
                    if (neighbors[j]->isCorpse())
                    {
                        int pos = getIndex(neighbors[j]);
                        beings.erase(beings.begin() + pos);
                    }
                }
            }
        }
        else
        {
            // if neighbor is  int my team
            if (beings[i]->get_potions() > 0 && neighbors[j]->get_health() < Health)
            {
                beings[i]->heal(neighbors[j]);
            }
        }

        cout << "size:" << neighbors.size() << endl;

        neighbors.clear();
    }

    return;
}

void Game::ClearScreen()
{
    cout << string(100, '\n');
}

void Game::gamePlay()
{

    bool game_over = false;
    isDay = true;
    int count = 0;

    while (game_over == false)
    {

        // Toggle day and night every 4 moves.
        if (count % 4 == 0)
        {
            if (isDay)
            {
                isDay = false;
            }
            else
            {
                isDay = true;
            }
        }

        // Catch Player's Move.
        switch ((getchar()))
        {
        case W:
            avatar->move_up();
            if (avatar->potion_check() == true)
            {
                spawn_potion();
            }
            break;
        case S:
            avatar->move_down();
            if (avatar->potion_check() == true)
            {
                spawn_potion();
            }
            break;
        case A:
            avatar->move_left();
            if (avatar->potion_check() == true)
            {
                spawn_potion();
            }

            break;
        case D:
            avatar->move_right();
            if (avatar->potion_check() == true)
            {
                spawn_potion();
            }

            break;
        case H:
            if (isDay == true && avatar->get_team() == 'W' && avatar->get_potions() > 0)
            {
                // avatar->heal(&beings);
            }
            if (isDay == false && avatar->get_team() == 'V' && avatar->get_potions() > 0)
            {
                // avatar->heal(&beings);
            }
            break;
        case ENTER:
            for (unsigned int i = 0; i < beings.size(); i++)
            {
                beings[i]->move();
            }
            BeingsEngagement();
            ClearScreen();
            map->display();
            break;

        case PAUSE:
            printStats();
            break;

        default:
            break;
        }

        // if user quits or a team id dead.
        // break;
    }

    return;
}

Game::~Game(){};