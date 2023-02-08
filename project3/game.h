/******************************************************
** Program: game.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Main file for controlling the flow of the game, builds the cave to user size and then files it
with events. Each loop of the game allows the player to move and then checks what events are around it to print 
the noises they make. The user has to option to quit the game, play the same map, or play a new one 
** Input: size of cave, and debug mode
** Output: non
******************************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "adventurer.h"
#include "event.h"
#include "empty_room.h"
#include "super_bats.h"
#include "gold.h"
#include "wumbus.h"
#include "bottomless_pit.h"
#include "coordinates.h"
using namespace std;
class Game{
    private:
        Coordinates wumbus; //Holds the location of the wumbus
    public:
        
        Game(int,bool); //starts a game with the user input size, and wether the game is in debug mode or not
        //Game(vector<vector<Event*>>&);
        void Game_destructor(vector<vector<Event*>>& ,vector<vector<Event*>>&, int); //deletes and frees the memorey of each event in the vecotor
        void build_cave(int,vector<vector<Event*>>&,Coordinates,bool); //runs a loop of the size of the cave to call room() to finsish building the cave. Builds the bottom row.
        void room(int,int,int,vector<vector<Event*>>&, Coordinates, bool); //when called it builds the walls of a cave with the event icon in the middle if in debug mode, and a * if the player is in that room
        void middle_room(); //not used
        void bottom_room(int); //not used
        void print_room(); // not used
        string event(); //not used
        void fill_events(vector<vector<Event*>> &, int); //fills the vector with random events
        void fill_events_two(vector<vector<Event*>> &, int); //additional filling of vecotor
        void copy(vector<vector<Event*>>&,vector<vector<Event*>>&, int); //copies map for if player wants to play again
        void clear_events(vector<vector<Event*>>, int); //not used
        Coordinates spawn(vector<vector<Event*>>&, Adventurer&,int); //spawns the player on the map storing that location as the exit
        int move(vector<vector<Event*>>&, int,Adventurer&,bool); //allows user to use wasp to move the character and calls shot function is the player wants to shoot the arrow
        void shoot_arrow(char, Adventurer, vector<vector<Event*>>&, int); //shoots the arrow in the direction, checks if wumpus is hit
        int check_wumbus(vector<vector<Event*>> &,int, int, int);// checks if wumpus was hit by arrow if not calls the awake wumpus function
        void awake_wumbus(vector<vector<Event*>> &);//75% chance the wumpus wakes up when arrow is shot and moves to new empty room
        Coordinates set_wumbus_location(vector<vector<Event*>> &, int);// sets the coordinates of the wumpus location
        Coordinates get_wumbus_location();// gets the wumpus location
        void call_precept(vector<vector<Event*>> &, Adventurer &); //calls the sounds of each event if they are near the player
        bool valid_move(int, int,char, int); //makes sure the player is moving to a valid room, ie not leaving the cave
        int escape_rope(Coordinates, Adventurer&); //if the user enters the escape room as if the want to escape if they already have the gold
};


#endif