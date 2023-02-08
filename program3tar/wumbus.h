/******************************************************
** Program: wumbus.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Wumbus child class of Event, redefines the encounter() to end game
** Input: non
** Output: 1
******************************************************/
#ifndef WUMBUS_H
#define WUMBUS_H
#include <iostream>
#include "event.h"
#include "coordinates.h"
#include "adventurer.h"
#include <vector>
using namespace std;
class Wumbus: public Event {
    protected:

    public:
        Wumbus();
        void percept();
        int encounter(vector<vector<Event*> > &, Adventurer&);//eats the player and ends the game
        void move(vector<vector<Event*> > &);//not used
      
};

#endif