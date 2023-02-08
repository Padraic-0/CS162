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
    int encounter(vector<vector<Event*> > &, Adventurer&);
      
};

#endif