/******************************************************
** Program: trainer.h
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Trainer class that handles the trainers team of pokemon, creates users team and randomly
selects computeres team. Uses heap memory to keep Pokemon objects updated so their information can be updated and received.
Deletes the heap memomory with destructor.
** Input: Trainer name, Team[]
** Output: name, Team[]
******************************************************/
#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
//include all pokemon
#include "pokemon.h"
#include "charmander.h"
#include "bulbasaur.h"
#include "squirtle.h"
#include "charizard.h"
using namespace std;

class Trainer{
    private: //maybe try private
        string Name;
        Pokemon* Team[3];
    public:
        
        Trainer();

        string get_Name();
        void set_Name(string);

        Pokemon* get_pokemon(int);
        void set_pokemon(Pokemon*, int);

        void fill_Team();
        void print_pokemon_info(Pokemon*);
        void attack(Pokemon*, Pokemon*);
        void fill_Computer_Team();
        void run_fill(int,int);
        void swap(int);
        void swap_two_because_we_cant_have_more_then_twenty_lines();
        void swap_THREE_because_we_cant_have_more_then_twenty_lines();
        int can_swap();
        int can_swap_pc();
        ~Trainer();
        /*
        void attack(int);
        void heal(Pokemon&);
        void swap();
        */

};
#endif

/*Pokemon* team[3];
what pokemon?
if(pokemon==bulb){
    team[currentnumber]= new bulb;
}


delete team[currentnumber]
*/