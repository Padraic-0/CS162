/******************************************************
** Program: charizard.h
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon child class with unqiue values for damage, type, health... Redefines the virtual functions
in Pokemon class
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#ifndef CHARIZARD_H
#define CHARIZARD_H
#include <iostream>
#include "pokemon.h"
using namespace std;

class Charizard : public Pokemon{
    protected:

    public:
        Charizard();

        string get_Name();

        string get_Type();
    
        int get_Attack();

        int get_Defense();

        float get_Health_points();
        void set_Health_points(float);
};
#endif