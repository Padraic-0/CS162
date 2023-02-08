#ifndef POKEDEX_H
#define POKEDEX_H
#include <iostream>
#include "./pokemon.h"
#include <fstream>


using namespace std;

class Pokedex{
    private:
        string Trainer;
        int num_pokemon;
        
        

        string filename;


    public:

    string getFilename();
    void setFilename(string);
    Pokemon* dex;
    //declar construcotor in header file
    Pokedex();
    

    int get_num_pokemon();//getter
    void set_num_pokemon(int);//setter

    string get_trainer();//getter
    void set_trainer(string);//setter

    Pokemon* get_pokemon();//getter
    void set_pokemon(Pokemon,int);//setter

    void get_pokemon_info(ifstream &);
    void search_by_dex_number(ofstream &, int);
    void search_by_type(ofstream &, string);
    Pokedex(ifstream &);
    void print_pokemon_info(ofstream &, Pokemon);
    void search_by_name(ofstream &, string);
    ~Pokedex();

    


};


#endif