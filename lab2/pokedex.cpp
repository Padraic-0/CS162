#include <iostream>
#include "./pokedex.h"
using namespace std;

//default constructor
Pokedex::Pokedex(){
    //setting trainer
    Trainer = "Ash";

    //setting number of pokemon
    num_pokemon = 4;

    //setting dex
    dex = new Pokemon[4];

    
    
}

void Pokedex::set_trainer(string new_trainer){
    Trainer = new_trainer;
}

string Pokedex::get_trainer(){
    return Trainer;
}

void Pokedex::set_num_pokemon(int new_num_pokemon){
    num_pokemon = new_num_pokemon;
}

int Pokedex::get_num_pokemon(){
    return num_pokemon;
}

void Pokedex::set_pokemon(Pokemon new_pokemon, int n1){
    //changed Pokemon[n1] to dex[n1]
    dex[n1] = new_pokemon;
}

Pokemon* Pokedex::get_pokemon(){
    //changed pokedex to dex
    return dex;
}




