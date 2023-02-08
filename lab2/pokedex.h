#ifndef POKEDEX_H
#define POKEDEX_H
#include <iostream>
#include "./pokemon.h"

using namespace std;

class Pokedex{
    private:
        string Trainer;
        int num_pokemon;
        Pokemon* dex;



    public:
    //declar construcotor in header file
    Pokedex();

    int get_num_pokemon();//getter
    void set_num_pokemon(int);//setter

    string get_trainer();//getter
    void set_trainer(string);//setter

    Pokemon* get_pokemon();//getter
    void set_pokemon(Pokemon,int);//setter



};


#endif