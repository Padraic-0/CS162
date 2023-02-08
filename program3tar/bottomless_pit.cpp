/******************************************************
** Program: Bottomless_pit.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Bottomless pit child of event. Redefines encounter() to kill player returing 1
** Input: non
** Output: 1
******************************************************/
#include <iostream>
#include "bottomless_pit.h"
using namespace std;

Bottomless_pit::Bottomless_pit(){
    noise = "You feel a breeze";
    room.x = 0;
    room.y = 0;
    icon = "p";
}

int Bottomless_pit::encounter(vector<vector<Event*> > &map, Adventurer &a1){
    cout << "You fell down a deep hole" << endl;
    return 1;
}