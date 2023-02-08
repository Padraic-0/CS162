/******************************************************
** Program: bulbasaur.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "bulbasaur.h"
using namespace std;
//bulbasaur construcotor
//adds new name type attack defense health points to the pokemon
Bulbasaur::Bulbasaur(){
    Name = "Bulbasaur";
    Type = "Grass";
    Attack = 49;
    Defense = 49;
    Health_points = 45.00;
    max_Health = 45.00;
}
//get_Name gets pokemon name and returns it as a string
string Bulbasaur::get_Name(){
    return Name;
}
//get_Type returns Pokemon type as string
string Bulbasaur::get_Type(){
    return Type;
}
//get_Attack returns attack value as int
int Bulbasaur::get_Attack(){
    return Attack;
}
//get_Defense returns defense as a int value
int Bulbasaur::get_Defense(){
    return Defense;
}
//get_Health_points returns the current health points of the pokemon as a float
float Bulbasaur::get_Health_points(){
    return Health_points;
}
//set_Health_points is used to heal the Pokemon, taking a float and assinging it as the Pokemons new health points
void Bulbasaur::set_Health_points(float new_Health_points){
    Health_points = new_Health_points;
}