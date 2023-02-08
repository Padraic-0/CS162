/******************************************************
** Program: charmader.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#ifndef CHARMANDER_H
#define CHARMANDER_H
#include <iostream>
#include "pokemon.h"
using namespace std;

class Charmander : public Pokemon{
    protected:
    /*
        Name = "Charmander";
        Type = "Fire";
        Attack = 52;
        Defense = 43;
        Health_points = 39.00;
    */
    public:
        Charmander();

        string get_Name();

        string get_Type();
    
        int get_Attack();

        int get_Defense();

        float get_Health_points();
        void set_Health_points(float);
};
#endif