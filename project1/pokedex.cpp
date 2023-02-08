/******************************************************
** Program: pokedex.cpp
** Author: Padraic Bergin 
** Date: Oct 18th, 2021
** Description: Pokedex implementation file with function definitions
** Input: Pokemon
** Output: Puts Pokemon in array of Pokemon
******************************************************/
#include <iostream>
#include "./pokedex.h"
#include <fstream>
#include <sstream>
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
Pokedex::Pokedex(ifstream &input){
    Pokedex::Trainer = "Ash";
    string holding_string_num_pokemon;
    input >> holding_string_num_pokemon;
    stringstream container(holding_string_num_pokemon);
    int x;
    container >> x;
    Pokedex::num_pokemon = x;

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
        stringstream container(holding_string_dex);
        int x;
        container >> x;
        int holding_dex = x;


        input >> holding_name;
        input >> holding_Types;

        string temp_string;

        

        //edit construcotr to not take array of moves yet
        Pokemon holding_Pokemon(holding_dex, holding_name, holding_Types);
        dex[i]= holding_Pokemon;

        for (int j = 0; j <= 3; j++){
            input >> temp_string;
            dex[i].set_Moves(j,temp_string);
        }
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




void Pokedex::search_by_dex_number(ofstream &fout, int dex_search, string where_to_print){
    bool matching_dex = false;
    for (int i = 0; i < num_pokemon; i++){
        if (dex[i].get_Dex_num()==dex_search){
            if (where_to_print == "F"){
                print_pokemon_info(fout, dex[i]);
            }
            else {
                print_pokemon_info_terminal(dex[i]);
            }
            matching_dex = true;

        }
        }
        if(matching_dex==false){
            cout<<"No Matching dex"<<endl;
        }
    
    
}

void Pokedex::search_by_type(ofstream &fout, string type_search, string where_to_print){
    bool matching_type = false;
    for (int i = 0; i < num_pokemon; i++){
        if (dex[i].get_Types()==type_search){
            if (where_to_print == "F"){
                print_pokemon_info(fout, dex[i]);
            }
            else {
                print_pokemon_info_terminal(dex[i]);
            }
            matching_type = true;
        }   
    }
    if (matching_type==false){
        cout << "No matching types " << endl;
    }
}

void Pokedex::print_pokemon_info_terminal(Pokemon printed_pokemon){
     cout << printed_pokemon.get_Dex_num() << " " << printed_pokemon.get_Name() << " " << printed_pokemon.get_Types() << "\n";
     
     for (int i =0; i <= 3; i++){
         cout << printed_pokemon.get_Moves(i)<<" ";
         if (i==3){
             cout<<"\n";
         }
     }
     


}


 void Pokedex::print_pokemon_info(ofstream &fout, Pokemon printed_pokemon){
     fout << printed_pokemon.get_Dex_num() << " " << printed_pokemon.get_Name() << " " << printed_pokemon.get_Types() << "\n";
     
     for (int i =0; i <= 3; i++){
         fout << printed_pokemon.get_Moves(i)<<" ";
         if (i==3){
             fout<<"\n";
         }
     }
     


}
void Pokedex::print_all_pokemon(ofstream &fout){
    for (int i = 0; i<num_pokemon; i++ ){
        print_pokemon_info(fout,dex[i]);
    }
}

void Pokedex::search_by_name(ofstream &fout, string name_search, string where_to_print){
    bool matching_name = false;
    for (int i = 0; i < num_pokemon; i++){
        if (dex[i].get_Name()==name_search){
            if (where_to_print == "F"){
                print_pokemon_info(fout, dex[i]);
            }
            else {
                print_pokemon_info_terminal(dex[i]);
            }
            matching_name = true;
        }   
    }
    if (matching_name==false){
        cout << "No matching name " << endl;
    }
}




void Pokedex::add_pokemon(ofstream &fout){
    string Name;
    string Moves[3];
    int Dex_num;
    string Types;
    cout <<"What is the dex number of the Pokemon: "<< endl;
    cin >> Dex_num;
    fout << Dex_num << " ";
    cout <<"What is the name of the Pokemon: "<< endl;
    cin >> Name;
    fout << Name << " ";
    cout <<"What is the type of the Pokemon: "<< endl;
    cin >> Types;
    fout << Types << "\n";
    cout <<"What are the moves of the Pokemon: "<< endl;
    for (int i=0; i<=3; i++){
        int j = i+1;
        cout<<"Move " << j << ": ";
        cin >> Moves[i];
        fout << Moves[i]<< " ";
        if (i==3){
            fout << "\n";
        }
    }
}

string Pokedex::where_to_print(){
    cout << "Would you like to print information to the terminal or to a file? (T/F) " << endl;
    string where_to_print;
    cin >> where_to_print;
    return where_to_print;
}

string Pokedex::open_file(string where_to_print){
    if (where_to_print == "F"){
        string outputfile;
        cout << "What is the name of the output file? (file name(.txt) " << endl;
        cin >> outputfile;
        return outputfile;
    }
    
}

