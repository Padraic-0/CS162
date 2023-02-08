/******************************************************
** Program: event.h
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Parent class of all of the events. Is polymorphic and is virtual.
** Input: non
** Output: non
******************************************************/
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
      Event();// event constructor
      //~Event();
      void percept(); //calls the noise of event
      virtual int encounter(vector<vector<Event*> > &, Adventurer&); //what happens if the user enters the room
      void player_location(Coordinates); //player location
      string get_icon(); // returns the icon of the event
      void set_coordinates(int, int); //sets the coordinates of the event
      Coordinates get_coordinates(); //gets the coordinates of the event

};

#endif