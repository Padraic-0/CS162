/******************************************************
** Program: super_bats.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Super bat class child of Event. Redefines encounter to move player around randomly
** Input: non
** Output: 0 is lands in safe spot, 1 is the player dies in drop off
******************************************************/
#ifndef SUPER_BAT_H
#define SUPER_BAT_H
#include <iostream>
#include "event.h"
#include "coordinates.h"
#include "adventurer.h"
#include <vector>
using namespace std;
class Super_bats: public Event {
    protected:

    public:
    Super_bats();
    void percept();
    int encounter(vector<vector<Event*> > &, Adventurer&);//flies the player to random room
      
};

#endif