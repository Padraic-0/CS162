/******************************************************
** Program: charmader.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "charmander.h"
using namespace std;
//Charmander construcotor
//adds new name type attack defense health points to the pokemon
Charmander::Charmander(){
    Name = "Charmander";
    Type = "Fire";
    Attack = 52;
    Defense = 43;
    Health_points = 39.00;
    max_Health = 39.00;

}
//get_Name gets pokemon name and returns it as a string
string Charmander::get_Name(){
    return Name;
}
//get_Type returns Pokemon type as string
string Charmander::get_Type(){
    return Type;
}
//get_Attack returns attack value as int
int Charmander::get_Attack(){
    return Attack;
}
//get_Defense returns defense as a int value
int Charmander::get_Defense(){
    return Defense;
}
//get_Health_points returns the current health points of the pokemon as a float
float Charmander::get_Health_points(){
    return Health_points;
}
//set_Health_points is used to heal the Pokemon, taking a float and assinging it as the Pokemons new health points
void Charmander::set_Health_points(float new_Health_points){
    Health_points = new_Health_points;
}