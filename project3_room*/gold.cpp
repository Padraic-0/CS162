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

int Gold::encounter(vector<vector<Room*> > &map, Adventurer &a1){
    cout << "You collected the gold! You can now escape"<< endl;
    int x = a1.get_player_location().x;
    int y = a1.get_player_location().y;
    delete map[x][y].get_event();
    map[x][y] = new Empty_room;
    return 2;
}