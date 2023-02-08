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
        int encounter(vector<vector<Room*> > &, Adventurer&);
};

#endif