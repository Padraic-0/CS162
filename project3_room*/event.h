#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include "coordinates.h"
#include "adventurer.h"
#include <vector>
using namespace std;
class Event{
    protected:
      string noise;
      Coordinates room;
      string icon;
      

    public:
      Event();
      //~Event();
      void percept();
      virtual int encounter(vector<vector<Room*> > &, Adventurer&);
      void player_location(Coordinates);
      string get_icon();
      void set_coordinates(int, int);
      Coordinates get_coordinates();

};

#endif