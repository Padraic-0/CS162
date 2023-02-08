#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstring>
#include "vehicle.h"
using namespace std;

class Person{
    private:
        string name;
        int num_vehicles;
        Vehicle* list_vehicles;
        //Vehicle list_vehicles = new Vehicle[num_vehicles];
        //list_vehicles = new Vehicle[];


    public:

        Person(int,string);

        string get_name();
        void set_name(string);

        int get_num_vehicles();
        void set_num_vehicles(int);

        Vehicle get_vehicle(int);
        void set_list(int,string);




};




#endif
