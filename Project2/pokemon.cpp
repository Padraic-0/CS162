/******************************************************
** Program: pokemon.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon parent class with base values for damage, type, health...virtual functions
that will be redefined in child class. Because it has virtual functions, it can be intizaed unless as a pointer
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "pokemon.h"
using namespace std;

Pokemon::Pokemon(){
    Name = "Name";
    Type = "Type";
    Attack = 1;
    Defense = 1;
    Health_points = 1.23;
}

float Pokemon::get_max_Health_points(){
    return max_Health;
}