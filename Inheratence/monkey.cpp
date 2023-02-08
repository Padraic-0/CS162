/*
	Monkey Class
*/
#include <iostream>
#include "monkey.h"

using namespace std;

Monkey::Monkey(){
    cout << "Default monkey constructor called" << endl;
	// set the longest jump
    age = 10;
	longest_jump = 5;
    max_bananas = 18;
}

Monkey::Monkey(string name, int age) : Animal(name, age){
    cout << "Alternate monkey constructor called" << endl;
	// set the longest jump
	longest_jump = 5;
    max_bananas = 18;
}

int Monkey::get_age(){
	cout << "Monkey get age called" << endl;
	return age;
}

