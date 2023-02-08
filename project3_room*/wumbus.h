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
        int encounter(vector<vector<Event*> > &, Adventurer&);
        void move(vector<vector<Event*> > &);
      
};

#endif