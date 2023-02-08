/*
	Animal Class
*/
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal(string input_name, int age) {
	cout << "Alternate animal constructor called" << endl;
	name = input_name;
	this->age = age;
}

Animal::Animal() {
	cout << "Default animal constructor called" << endl;
	this->name = "Specimen Unknown";
	this->age = 0;
}

string Animal::get_name() {
	return name;
}

int Animal::get_age(){
	cout << "Animal get age called" << endl;
	return age;
}

void Animal::set_name(string name){
    this->name = name;
}