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