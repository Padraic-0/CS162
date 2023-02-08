#include <iostream>
#include "./pokemon.h"
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
void Pokemon::set_Moves(string new_Move, int n){
    
    Moves[n] = new_Move;
        
}

string* Pokemon::get_Moves(){
    return Moves;
}

//string Pokemon::get_


void Pokemon::set_Types(string new_Types){
    Types = new_Types;
}
string Pokemon::get_Types(){
    return Types;
}


void Pokemon::print_info(){
    cout << Name << Types << Dex_num << Moves[1]<< endl;
}