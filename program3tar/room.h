/******************************************************
** Program: room.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Room holds a event*
** Input: set event
** Output: get event
******************************************************/
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "event.h"
using namespace std;

class Room{
    private:
        Event *event;
    public:
        Room();
        Event* get_event();
        void set_event(Event*);
};

#endif