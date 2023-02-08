#include <iostream>
#include "bottomless_pit.h"
using namespace std;

Bottomless_pit::Bottomless_pit(){
    noise = "You feel a breeze";
    room.x = 0;
    room.y = 0;
    icon = "p";
}

int Bottomless_pit::encounter(vector<vector<Room*> > &map, Adventurer &a1){
    cout << "You fell down a deep hole" << endl;
    return 1;
}