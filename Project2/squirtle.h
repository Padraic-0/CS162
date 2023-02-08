/******************************************************
** Program: squirtle.h
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include <iostream>
#include "pokemon.h"
using namespace std;

class Squirtle : public Pokemon{
    protected:
    /*
        Name = "Squirtle";
        Type = "Water";
        Attack = 48;
        Defense = 65;
        Health_points = 44.00;
    */
    public:
        Squirtle();

        string get_Name();

        string get_Type();
    
        int get_Attack();

        int get_Defense();

        float get_Health_points();
        void set_Health_points(float);
};
#endif