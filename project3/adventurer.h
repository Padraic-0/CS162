/******************************************************
** Program: adventuer.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Adventuer class that keeps track of the players location and wether they can escape
** Input: non
** Output: can escape
******************************************************/
#ifndef ADVENTURER_H
#define ADVENTURER_H
#include "coordinates.h"
#include <iostream>
#include <vector>
using namespace std;
class Adventurer{
    private:
        Coordinates location;
        bool can_escape;
    public:
        void set_player_location(int, int);
        Coordinates get_player_location();
        bool get_can_escape(); //bool for if the player can escape
        void set_can_escape(bool); //sets the bool for if the player can escape
    
        
};

#endif