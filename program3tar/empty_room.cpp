/******************************************************
** Program: empty_room.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Empty room child of event. Fills a cave room as a empty room that doesnt effect the player.
** Input: non
** Output: 0 
******************************************************/
#include <iostream>
#include "event.h"
#include "empty_room.h"
#include "coordinates.h"
#include <vector>
using namespace std;

Empty_room::Empty_room(){
    noise = "";
    room.x = 0;
    room.y = 0;
    icon = " ";
}

int Empty_room::encounter(vector<vector<Event*> > &map, Adventurer &a1){
    return 0;
}