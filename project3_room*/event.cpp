#include <iostream>
#include "event.h"
using namespace std;

Event::Event(){
    noise = " ";
    room.x = 0;
    room.y = 0;
    icon = " ";
}

string Event::get_icon(){
    return icon;
}

void Event::set_coordinates(int x, int y){
    room.x = x;
    room.y = y;
}

Coordinates Event::get_coordinates(){
    return room;
}
/*
Event::~Event(){
    delete Event;
}
*/

void Event::percept(){
    cout << noise << endl;
}

int Event::encounter(vector<vector<Room*> > &map, Adventurer &a1){
    return 0;
}