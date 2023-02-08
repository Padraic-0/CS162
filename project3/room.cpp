/******************************************************
** Program: room.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Room holds a event*
** Input: set event
** Output: get event
******************************************************/
#include <iostream>
#include "room.h"
#include "event.h"
#include "empty_room.h"
#include "super_bats.h"
#include "gold.h"
#include "wumbus.h"
#include "bottomless_pit.h"
using namespace std;

Room::Room(){
    event = NULL;
}

Event* Room::get_event(){
    return event;
}

void Room::set_event(Event* event_room){
    event = event_room;
}