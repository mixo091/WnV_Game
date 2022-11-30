#pragma once
#include <iostream>
#include <vector>
#include "./grid.h"
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//Edw ola ta headers. grid beings etc.



class Game {

    public:

    vector <Vampire> vampires;
    vector <Werewolf> werewolves;
    vector <being_coordinates> pos_available;
    //Avatar avatar;
    Grid* map;

    //stat srtucture { number of w , number of v ,  number potion of a}

    bool isDay;
    
    void getAvailablePostitions(vector<being_coordinates> &vec){
        being_coordinates p1;
        p1.x=1;
        p1.y=3;
        being_coordinates p2;
        p2.x=2;
        p2.y=3;

        vec.push_back(p1);
        vec.push_back(p2);
    }

    void initializeGame(int d1, int d2){


        // Create Player's Avatar.

        


        //Setting grid
        map = new Grid(d1,d2);

        //Getting available positions
        getAvailablePostitions(pos_available);
        cout << "vec = ( " << pos_available.front().x << ", " << pos_available.front().y << " )"<< endl;

        //Creating Beings
        being_coordinates pv;
        pv.x=0;
        pv.y=0;
        being_coordinates pw;
        pw.x=0;
        pw.y=0;

        Vampire v1('V', pv, 1, 1, 1);
        vampires.push_back(v1);
        Werewolf w1('W', pw, 1, 1, 1);
        werewolves.push_back(w1);

        //Set Beings
        map->setBeing(pos_available, &v1);

        //Setting Beings on the grid
        map->display();
        
    
        



    }



    void gamePlay(){

        int move = 0 ;
        bool game_over = false;
        while (!game_over)
        {
            // Catch Player's Move.

            switch((c=getch())) {
            case KEY_UP:
                cout << endl << "Up" << endl;//key up
                break;
            case KEY_DOWN:
                cout << endl << "Down" << endl;   // key down
                break;
            case KEY_LEFT:
                cout << endl << "Left" << endl;  // key left
                break;
            case KEY_RIGHT:
                cout << endl << "Right" << endl;  // key right
                break;
            default:
                cout << endl << "null" << endl;  // not arrow
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