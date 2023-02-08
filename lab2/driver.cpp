#include <iostream>
#include "./pokemon.h"
#include "./pokedex.h"
using namespace std;
//Compile using: g++ pokemon.cpp pokedex.cpp driver.cpp-o lab2 ./lab2

int main(){
    
    Pokemon p1;
    p1.set_Name("Mewo");
    //cout <<p1.get_Name();
    Pokedex t1;
    t1.set_pokemon(p1,0);
    //cout<< (*t1.get_pokemon()).get_Name();
    //cout<< t1.get_pokemon()->get_Name();
    cout << t1.get_pokemon()->get_Moves()[2];


    



    //p1.print_info();
    

    return 0;
}