/******************************************************
** Program: adventuer.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Adventuer class that keeps track of the players location and wether they can escape
** Input: non
** Output: can escape
******************************************************/
#include <iostream>
#include "adventurer.h"
#include "coordinates.h"
#include <vector>
using namespace std;

void Adventurer::set_player_location(int x, int y){
    location.x = x;
    location.y = y;
    can_escape = true;

}

Coordinates Adventurer::get_player_location(){
    return location;
}

bool Adventurer::get_can_escape(){
    return can_escape;
}

void Adventurer::set_can_escape(bool value){
    can_escape = value;
}