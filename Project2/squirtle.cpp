/******************************************************
** Program: squirtle.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "squirtle.h"
using namespace std;
//squrtle construcor
//adds new name type attack defense health points to the pokemon
Squirtle::Squirtle(){
    Name = "Squirtle";
    Type = "Water";
    Attack = 48;
    Defense = 65;
    Health_points = 44.00;
    max_Health = 44.00;

}
//get_Name gets pokemon name and returns it as a string
string Squirtle::get_Name(){
    return Name;
    
}
//get_Type returns Pokemon type as string
string Squirtle::get_Type(){
    return Type;
    cout << "called";
}
//get_Attack returns attack value as int
int Squirtle::get_Attack(){
    return Attack;
}
//get_Defense returns defense as a int value
int Squirtle::get_Defense(){
    return Defense;
    cout << "called";
}
//get_Health_points returns the current health points of the pokemon as a float
float Squirtle::get_Health_points(){
    return Health_points;
    cout << "called";
}
//set_Health_points is used to heal the Pokemon, taking a float and assinging it as the Pokemons new health points
void Squirtle::set_Health_points(float new_Health_points){
    Health_points = new_Health_points;
}