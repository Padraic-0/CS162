#include <iostream>
#include "super_bats.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

Super_bats::Super_bats(){
    noise = "You hear wings flapping";
    room.x = 0;
    room.y = 0;
    icon = "b";
}

int Super_bats::encounter(vector<vector<Event*> > &map, Adventurer &a1){
    cout <<"You have walked into a room full of bats, they fly you around the cave!"<<endl;
    srand(time(NULL));
    int size = pow(map.size(), 0.5);
    int c1;
    int c2;
    while(map[a1.get_player_location().x][a1.get_player_location().y]->get_icon() == "b"){
        c1 = (rand() % (size-1));
        c2 = (rand() % (size-1));
        a1.set_player_location(c1,c2);
    }
    if(map[a1.get_player_location().x][a1.get_player_location().y]->get_icon() == "w"){
        cout << "The wumpus ate you" << endl;
        return 1;
    }

    if(map[a1.get_player_location().x][a1.get_player_location().y]->get_icon() == "p"){
        cout << "You feel into a pit and died" << endl;
        return 1;
    }
    
    
    return 0;
}