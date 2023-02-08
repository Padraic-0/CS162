/******************************************************
** Program: pokemon.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Pokemon parent class with base values for damage, type, health...virtual functions
that will be redefined in child class. Because it has virtual functions, it can be intizaed unless as a pointer
** Input: pokemon data
** Output: Pokemon data
******************************************************/
#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
using namespace std;

class Pokemon{
    protected:
    string Name;
    string Type;
    int Attack;
    int Defense;
    float Health_points;
    float max_Health;

    public:
    Pokemon();
    
    float get_max_Health_points();
    virtual string get_Name()=0;

    virtual string get_Type()=0;
    
    virtual int get_Attack()=0;

    virtual int get_Defense()=0;

    virtual float get_Health_points()=0;
    virtual void set_Health_points(float)=0;


};

#endif