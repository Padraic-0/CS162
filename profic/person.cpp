#include <iostream>
#include "person.h"
#include "vehicle.h"
using namespace std;

Person::Person(int number1, string name1){
    name = name1;
    num_vehicles = number1;
    list_vehicles = new Vehicle[num_vehicles];

}

string Person::get_name(){
    return name;
}

void Person::set_name(string name){
    name = name;
}

int Person::get_num_vehicles(){
    return num_vehicles;
}

void Person::set_num_vehicles(int num_vehicles){
    num_vehicles = num_vehicles;
}

Vehicle Person::get_vehicle(int i){
    return list_vehicles[i];

}

void Person::set_list(int i,string type){
    list_vehicles[i].set_type(type);

}
