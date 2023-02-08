/******************************************************
** Program: wumbus.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Wumbus child class of Event, redefines the encounter() to end game
** Input: non
** Output: 1
******************************************************/
#include <iostream>
#include "wumbus.h"
using namespace std;

Wumbus::Wumbus(){
    noise = "You smell a terrible stench";
    room.x = 0;
    room.y = 0;
    icon = "w";
}

int Wumbus::encounter(vector<vector<Event*> > &map, Adventurer &a1){
    cout <<"Wumbus ate you"<<endl;
    cout <<"Wumbus ate you"<<endl;
    return 1;

}