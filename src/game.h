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

    //vector <Vampire> vampires;
    //vector <Werewolf> werewolves;
    vector<Creature*> beings;
    Avatar* avatar;
    Grid* map;
    bool isDay;
    Game(int d1 ,  int d2 , char team){
        initializeGame(d1,d2,team);
    }
  
    ~Game(){ };


    void printStats(){
        ClearScreen();
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"|                    GAME STATS                  |"<<endl;
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        for ( unsigned int i=0; i< beings.size()/2;i++){
            cout<<"V["<<to_string(i)<<"]"<<"::"<< "Hp: "<<"|Pwr: " <<"|Def: "<<"|Potions: "<<"|Dead: "<<"|"<<endl;
        }
        for ( unsigned int i=beings.size()/2; i<beings.size();i++){
            cout<<"W["<<to_string(i)<<"]"<<"::"<< "Hp: "<<"|Pwr: " <<"|Def: "<<"|Potions: "<<"|Dead: "<<"|"<<endl;
        }







    }


    void set_being(Creature* b){

        // Get available tile.
        /*A tile is available when it is land and it has no other Creature on it*/
        coordinates available_pos{0,0};
        available_pos = map->get_available_tile_coordinates();
        map->grid[available_pos.x][available_pos.y].being = b;
        b->set_coordinates(available_pos);
        cout << map->grid[available_pos.x][available_pos.y].being->type << endl;
    }




    void initializeGame(int d1, int d2 , char team){

        // Create Grid-Map.
        map = new Grid(d1,d2);
        map->display();

        // Create Player's Avatar.
        coordinates avatar_pos {0,0};
        this->avatar= new Avatar(map,team,avatar_pos,1,1,1);
        //avatar_pos = map->get_available_tile_coordinates();
        cout<<avatar_pos.x<<" , "<<avatar_pos.y<<endl;
        //map->setBeing(avatar_pos, avatar);
        set_being(avatar);

        //--Create Vampires.
        Creature* temp;
        int max_creatures = (d1*d2)/15;
        int num_of_creatures =4+rand()%(max_creatures-3);
        int vampires_num = num_of_creatures/2;
        for (int  i = 0; i < vampires_num; i++)
        {
            coordinates vampire_pos {0,0};
            temp = new Vampire(map,'B', vampire_pos, i, 1, 1);
            beings.push_back(temp);
            set_being(beings[i]);
        }
        //-- Create Werewolves.
        for (int  i = vampires_num; i < vampires_num*2; i++)
        {
            coordinates werewolves_pos {0,0};
            temp = new Werewolf(map,'L', werewolves_pos, i, 1, 1);
            beings.push_back(temp);
            set_being(beings[i]);
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
            case W:
                avatar->move_up();
                break;
            case S:
                avatar->move_down();
                break;
            case A:
                avatar->move_left();

                break;
            case D:
                avatar->move_right();
  
                break;
            case ENTER:
                for(unsigned int i=0; i<beings.size(); i++){
                    beings[i]->move();
                }
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
        //break;

        }
        

        



        return;
    }

 };

    


    







