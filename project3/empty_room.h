/******************************************************
** Program: empty_room.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Empty room child of event. Fills a cave room as a empty room that doesnt effect the player.
** Input: non
** Output: 0 
******************************************************/
#ifndef EMPTY_ROOM_H
#define EMPTY_ROOM_H
#include <iostream>
#include "event.h"
#include "coordinates.h"
#include "adventurer.h"
#include <vector>
using namespace std;
class Empty_room: public Event {
    protected:

    public:
        Empty_room();
        void percept();
        int encounter(vector<vector<Event*> > &, Adventurer&);//nothing happens if the user enters
      
};

#endif