#pragma once
#include <iostream>
#include <vector>
#include "./grid.h"
#include <stdio.h>
#include <unistd.h>
#define W 119
#define S 115
#define D 100
#define A 97


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

    //stat srtucture { number of w , number of v ,  number potion of a}


    /*
    void getAvailablePostitions(vector<coordinates> &vec){
        coordinates p1;
        p1.x=1;
        p1.y=3;
        coordinates p2;
        p2.x=2;
        p2.y=3;

        vec.push_back(p1);
        vec.push_back(p2);
    }*/

    void initializeGame(int d1, int d2){

        // Create Grid-Map.
        map = new Grid(d1,d2);

        map->display();

        // Create Player's Avatar.
        coordinates avatar_pos {0,0};
        this->avatar= new Avatar('A',avatar_pos,1,1,1);


        //avatar_pos = map->get_available_tile_coordinates();
        cout<<avatar_pos.x<<" , "<<avatar_pos.y<<endl;
        //map->setBeing(avatar_pos, avatar);
        map->set_being(avatar);
        

        


        //Create Vampires.
        int vampires_num = 10;
        for (int  i = 0; i < vampires_num; i++)
        {
            coordinates vampire_pos {0,0};
            Vampire v('V', vampire_pos, i, 1, 1);
            vampires.push_back(v);
            map->set_being(&vampires[i]);
            //cout<<vampires[i].potions<<endl;
        }

        int werewolves_num = 10;
        for (int  i = 0; i < werewolves_num; i++)
        {
            coordinates werewolves_pos {0,0};
            Werewolf w('W', werewolves_pos, i, 1, 1);
            werewolves.push_back(w);
            map->set_being(&werewolves[i]);
            //cout<<werewolves[i].potions<<endl;
        }
        
        map->display();
        
        /*

        // Set Avatar on the map.
        map->set_being(&avatar);


   

        //Getting available positions
        getAvailablePostitions(pos_available);
        cout << "vec = ( " << pos_available.front().x << ", " << pos_available.front().y << " )"<< endl;

        //Creating Beings
        coordinates pv;
        pv.x=0;
        pv.y=0;
        coordinates pw;
        pw.x=0;
        pw.y=0;

        Vampire v1(map,'V', pv, 1, 1, 1);
        vampires.push_back(v1);
        Werewolf w1(map,'W', pw, 1, 1, 1);
        werewolves.push_back(w1);

        //Set Beings
        map->setBeing(pos_available, &v1);

        //Setting Beings on the grid
        map->display();
        
    
        */



    }


    // Function to Clear Game Screen.
    void ClearScreen() {
	  cout << string(100, '\n');	
    }


    void gamePlay(){

        /*
        int move = 0 ;
        bool game_over = false;
        while (game_over == false)
        {

            cout<<"ok"<<endl;
            // Catch Player's Move.

            switch((move=getchar())) {
                putchar (move);
            case W:
                cout << endl << "Up" << endl;//key up
                break;
            case S:
                cout << endl << "Down" << endl;   // key down

                ClearScreen();
                 sleep(0.1);
                 map->display();
                break;
            case A:
                cout << endl << "Left" << endl;  // key left
                break;
            case D:
                cout << endl << "enter" << endl;  // key right
                break;
            case 10:
                putchar (move);
                cout<<move<<endl;
                break;
            default:
                break;
               
               

            }
            




        }
        

        */



        return;
    }

 };

    


    







