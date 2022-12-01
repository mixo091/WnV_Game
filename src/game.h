#pragma once
#include <iostream>
#include <vector>
#include "./grid.h"
#include "./creatures.h"
#include <stdio.h>
#include <unistd.h>
#define W 119
#define S 115
#define D 100
#define A 97
#define ENTER 10
#define PAUSE 32


//-- Game Class Implementation. --//

class Game {

    public:

    vector <Vampire> vampires;
    vector <Werewolf> werewolves;
    Avatar* avatar;
    Grid* map;
    bool isDay;
      Game(){
        initializeGame(20,20);
    }
  
    ~Game(){ };

    void set_being(Creature* b){

        // Get available tile.
        /*A tile is available when it is land and it has no other Creature on it*/
        coordinates available_pos{0,0};
        available_pos = map->get_available_tile_coordinates();
        map->grid[available_pos.x][available_pos.y].being = b;
        map->grid[available_pos.x][available_pos.y].type =  b->type;
        b->set_coordinates(available_pos);


    }




    void initializeGame(int d1, int d2){

        // Create Grid-Map.
        map = new Grid(d1,d2);

        map->display();

        // Create Player's Avatar.
        coordinates avatar_pos {0,0};
        this->avatar= new Avatar(map,'A',avatar_pos,1,1,1);


        //avatar_pos = map->get_available_tile_coordinates();
        cout<<avatar_pos.x<<" , "<<avatar_pos.y<<endl;
        //map->setBeing(avatar_pos, avatar);
        set_being(avatar);
        

        


        //Create Vampires.
        int vampires_num = 10;
        for (int  i = 0; i < vampires_num; i++)
        {
            coordinates vampire_pos {0,0};
            Vampire v(map,'V', vampire_pos, i, 1, 1);
            vampires.push_back(v);
            set_being(&vampires[i]);
            //cout<<vampires[i].potions<<endl;
        }

        int werewolves_num = 10;
        for (int  i = 0; i < werewolves_num; i++)
        {
            coordinates werewolves_pos {0,0};
            Werewolf w(map,'W', werewolves_pos, i, 1, 1);
            werewolves.push_back(w);
            set_being(&werewolves[i]);
            //cout<<werewolves[i].potions<<endl;
        }
        
        map->display();
        
    }


    // Function to Clear Game Screen.
    void ClearScreen() {
	  cout << string(100, '\n');	
    }


    void gamePlay(){

        
        int move = 0 ;
        bool game_over = false;

        while (game_over == false)
        {

            // Catch Player's Move.
            switch((move=getchar())) {
                putchar (move);
            case W:
                cout << endl << "Up" << endl;//key up
                avatar->move1("Up");
                ClearScreen();
                map->display();
                // Move player Up if possible
                //move others 
                //Clean Map
                //redisplay map()

                break;
            case S:
                cout << endl << "Down" << endl;   // key down
                break;
            case A:
                cout << endl << "Left" << endl;  // key left
                break;
            case D:
                cout << endl << "enter" << endl;  // key right
                break;
            case ENTER:
                break;

            case PAUSE:
                //Display Stats & Menu.

            default:
                break;
               
               

            }
            


        // if user quits or a team id dead.
        //break;

        }
        

        



        return;
    }

 };

    


    







