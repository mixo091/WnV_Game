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

//Edw ola ta headers. grid beings etc.



class Game {

    public:

    vector <Vampire> vampires;
    vector <Werewolf> werewolves;
    vector <coordinates> pos_available;
    //Avatar avatar;
    Grid* map;

    //stat srtucture { number of w , number of v ,  number potion of a}

    bool isDay;
    
    void getAvailablePostitions(vector<coordinates> &vec){
        coordinates p1;
        p1.x=1;
        p1.y=3;
        coordinates p2;
        p2.x=2;
        p2.y=3;

        vec.push_back(p1);
        vec.push_back(p2);
    }

    void initializeGame(int d1, int d2){

        // Create Grid-Map.
        map = new Grid(d1,d2);

        // Create Player's Avatar.
        coordinates avatar_pos {0,0};
        Avatar avatar(map,'A',avatar_pos,1,1,1);

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
        





        return;
    }




















    Game(){
        initializeGame(50,50);
    }

/*
        gameEngine(){

            loop{

                1- set day or night based on a cond
                2- move being randomly in the map
                3- fights and healing ( player based on night day cond)
                4- check for deaths remove corpses
                5- update stat structure.
                6- ckeck game's ending condition to break.


            }

        }
*/
    


    







};