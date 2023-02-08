#include <iostream>
#include "adventurer.h"
#include "coordinates.h"
#include <vector>
using namespace std;

void Adventurer::set_player_location(int x, int y){
    location.x = x;
    location.y = y;
    can_escape = true;

}

Coordinates Adventurer::get_player_location(){
    return location;
}

bool Adventurer::get_can_escape(){
    return can_escape;
}

void Adventurer::set_can_escape(bool value){
    can_escape = value;
}