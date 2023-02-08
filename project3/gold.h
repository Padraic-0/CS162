/******************************************************
** Program: Gold.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Gold child of event. redefines the encounter() to delete the gold and return 2 so that
the player is able to escape
** Input: non
** Output: 2
******************************************************/
#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include "event.h"
#include "coordinates.h"
#include "adventurer.h"
#include <vector>
using namespace std;
class Gold: public Event {
    protected:

    public:
        Gold();
        void percept();
        int encounter(vector<vector<Event*> > &, Adventurer&);//picks up gold and then replaces the gold event with a empty room
      
};

#endif