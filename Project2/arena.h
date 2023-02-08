/******************************************************
** Program: arena.h
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: The arena class pits the user against a computer trainer. They chose bewtween attacking, healing, swaping
, until one trainer has no Pokemon left. Handles most of the UI.
** Input: Trainer functions to get Pokemon data
** Output: Sets Pokemon with new data when they loss health, calls functions in Trainer to change Pokemon order.
******************************************************/
#ifndef ARENA_H
#define ARENA_H
#include <iostream>
#include "pokemon.h"
#include "trainer.h"
using namespace std;

class Arena{
    private:
        int remaining_pokemon_player;
        int remaining_pokemon_c;
    public:
        Arena();
        void attack(Pokemon*, Pokemon*);
        void heal(Pokemon*);
        //void swap(Pokemon* p1, Pokemon* p2, Pokemon* p3);
        int get_remaining_pokemon_player();
        void set_remaining_pokemon_player(int);
        int get_remaining_pokemon_c();
        void set_remaining_pokemon_c(int);
        void round(int n, Pokemon*, Pokemon*, Trainer);
        float type_damage(Pokemon*, Pokemon*);
        bool has_to_switch(float);
        bool match_over(Pokemon*, Pokemon*, Pokemon*, Pokemon*, Pokemon*, Pokemon*);
        float random_damage();
};

#endif