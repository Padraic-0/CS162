#include <iostream>
#include "./pokedex.h"
#include "./Tools.h"
#include <fstream>
using namespace std;
Tools T;

//default constructor
Pokedex::Pokedex(){
    
    //setting trainer
    Trainer = "Ash";

    //setting number of pokemon
    num_pokemon = 4;

    //setting dex
    dex = new Pokemon[4];

    
    
}
Pokedex::Pokedex(ifstream &input){
    Pokedex::Trainer = "Ash";
    string holding_string_num_pokemon;
    input >> holding_string_num_pokemon;
    Pokedex::num_pokemon = T.stringToInt(holding_string_num_pokemon);
    

    Pokedex::dex = new Pokemon[Pokedex::num_pokemon];


}

Pokedex::~Pokedex(){
   delete[] dex; 
   cout << "Destroyed" << endl;
   
}

void Pokedex::get_pokemon_info(ifstream &input){
    for (int i = 0; i < num_pokemon; i++){
        string holding_string_dex;
        string holding_name;
        string holding_Types;
    

        input >> holding_string_dex;
        int holding_dex = T.stringToInt(holding_string_dex);


        input >> holding_name;
        input >> holding_Types;

    
        Pokemon holding_Pokemon(holding_dex, holding_name, holding_Types);
        dex[i]= holding_Pokemon;
    }
    input.close();

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

void Pokedex::search_by_dex_number(ofstream &fout, int dex_search){
    bool matching_dex = false;
    for (int i = 0; i < num_pokemon; i++){
        if (dex[i].get_Dex_num()==dex_search){
            //dex[i].print_info();
            print_pokemon_info(fout, dex[i]);
            matching_dex = true;

        }
        }
        if(matching_dex==false){
            cout<<"No Matching dex"<<endl;
        }
    
    
}

void Pokedex::search_by_type(ofstream &fout, string type_search){
    bool matching_type = false;
    for (int i = 0; i < num_pokemon; i++){
        if (dex[i].get_Types()==type_search){
            //dex[i].print_info();
            print_pokemon_info(fout, dex[i]);
            matching_type = true;
        }   
    }
    if (matching_type==false){
        cout << "No matching types " << endl;
    }
}
 void Pokedex::print_pokemon_info(ofstream &fout, Pokemon printed_pokemon){
     /*
     ofstream fout;
     char f[15];
    for(int i = 0; i < filename.length(); i++){
        f[i] = filename[i];
    }

     fout.open(f, ios::app);
     */
     fout << printed_pokemon.get_Dex_num() << " " << printed_pokemon.get_Name() << " " << printed_pokemon.get_Types() << "\n";
     /*
     for (int i =0; i < 3; i++){
         fout << printed_pokemon.get_Moves;
     }
     */


}

void Pokedex::search_by_name(ofstream &fout, string name_search){
    bool matching_name = false;
    for (int i = 0; i < num_pokemon; i++){
        if (dex[i].get_Name()==name_search){
            //dex[i].print_info();
            print_pokemon_info(fout, dex[i]);
            matching_name = true;
        }   
    }
    if (matching_name==false){
        cout << "No matching name " << endl;
    }
}


string Pokedex::getFilename(){
    return filename;
}

void Pokedex::setFilename(string tempFileName){
    filename = tempFileName;
}


