#include <iostream>
#include "person.h"
#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(){
    type = "";
}

string Vehicle::get_type(){
    return type;
}

void Vehicle::set_type(string input){
    type = input;
}

