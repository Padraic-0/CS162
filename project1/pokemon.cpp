/******************************************************
** Program: pokemon.cpp
** Author: Padraic Bergin
** Date: Oct 18th, 2021
** Description: Pokemon implementation file, defines Pokemon class definitions
** Input: Pokemon data
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "./pokemon.h"
#include <fstream>
using namespace std;

// default constructor
Pokemon::Pokemon(){
    // setting name
    Name = "Pikka";

    // setting default moves
    
    Moves[0] = "One";
    Moves[1] = "Two";
    Moves[2] = "Three";
    Moves[3] = "Four";

    // set dex number
    Dex_num = 1;

    // set type
    Types = "Eletric";


}

//file input for pokemon constructor
Pokemon::Pokemon(int new_Dex_num, string new_Name, string new_Types/*, string new_Move[4]*/){
    Dex_num = new_Dex_num;
    Name = new_Name;
    Types = new_Types;
    //Moves = new_Move;
    
}

//Return type Whichclass::name(parameters){};
void Pokemon::set_Dex_num(int new_Dex_num){
    Dex_num = new_Dex_num;

}
int Pokemon::get_Dex_num(){
    return Dex_num;
}

void Pokemon::set_Name(string new_Name){
    Name = new_Name;
}
string Pokemon::get_Name(){
    return Name;
}
/**/
void Pokemon::set_Moves(int n, string new_Move){
    
    Moves[n] = new_Move;
        
}

string Pokemon::get_Moves(int move_number){
    return Moves[move_number];
}

//string Pokemon::get_


void Pokemon::set_Types(string new_Types){
    Types = new_Types;
}
string Pokemon::get_Types(){
    return Types;
}


void Pokemon::print_info(){
    //fout << Name << Types << Dex_num << endl;
}