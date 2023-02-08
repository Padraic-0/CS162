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
        int encounter(vector<vector<Room*> > &, Adventurer&);
      

};

#endif