
/******************************************************
** Program: charizard.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "charizard.h"
using namespace std;
//Chairzard constructor
//adds new name type attack defense health points to the pokemon
Charizard::Charizard(){
    Name = "Charizard";
    Type = "Fire";
    Attack = 55;
    Defense = 53;
    Health_points = 75.00;
    max_Health = 75.00;
}
//get_Name gets pokemon name and returns it as a string
string Charizard::get_Name(){
    return Name;
}
//get_Type returns Pokemon type as string
string Charizard::get_Type(){
    return Type;
}
//get_Attack returns attack value as int
int Charizard::get_Attack(){
    return Attack;
}
//get_Defense returns defense as a int value
int Charizard::get_Defense(){
    return Defense;
}
//get_Health_points returns the current health points of the pokemon as a float
float Charizard::get_Health_points(){
    return Health_points;
}
//set_Health_points is used to heal the Pokemon, taking a float and assinging it as the Pokemons new health points
void Charizard::set_Health_points(float new_Health_points){
    Health_points = new_Health_points;
}