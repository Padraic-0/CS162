/******************************************************
** Program: Gold.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Gold child of event. redefines the encounter() to delete the gold and return 2 so that
the player is able to escape
** Input: non
** Output: 2
******************************************************/
#include <iostream>
#include "gold.h"
#include "empty_room.h"
using namespace std;

Gold::Gold(){
    noise = "You see a glimmer nearby";
    room.x = 0;
    room.y = 0;
    icon = "g";
}

int Gold::encounter(vector<vector<Event*> > &map, Adventurer &a1){
    cout << "You collected the gold! You can now escape"<< endl;
    int x = a1.get_player_location().x;
    int y = a1.get_player_location().y;
    delete map[x][y];
    map[x][y] = new Empty_room;
    return 2;
}