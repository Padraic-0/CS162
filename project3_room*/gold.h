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
        int encounter(vector<vector<Event*> > &, Adventurer&);
      
};

#endif