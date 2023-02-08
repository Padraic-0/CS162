#include <iostream>
#include "event.h"
#include "empty_room.h"
#include "coordinates.h"
#include <vector>
using namespace std;

Empty_room::Empty_room(){
    noise = "";
    room.x = 0;
    room.y = 0;
    icon = " ";
}

int Empty_room::encounter(vector<vector<Room*> > &map, Adventurer &a1){
    return 0;
}
