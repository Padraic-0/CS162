/******************************************************
** Program: Bottomless_pit.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Bottomless pit child of event. Redefines encounter() to kill player returing 1
** Input: non
** Output: 1
******************************************************/
#ifndef BOTTOMLESS_PIT_H
#define BOTTOMLESS_PIT_H
#include <iostream>
#include "event.h"
#include "coordinates.h"
#include "adventurer.h"
#include <vector>
using namespace std;
class Bottomless_pit: public Event {
    protected:

    public:
        Bottomless_pit();
        void percept();
        int encounter(vector<vector<Event*> > &, Adventurer&);//kills the player if they enter
};

#endif