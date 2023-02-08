#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std;

class Pokemon{
    private:
        string Name;
        string Moves[4];
        int Dex_num;
        string Types;


    public:

    int get_Dex_num();//Getter
    void set_Dex_num(int);

    string get_Types();//Getter
    void set_Types(string);
    
    void set_Name(string);
    string get_Name();//Setter

    string* get_Moves();
    void set_Moves(string,int);

    Pokemon();//Constructor
    
    void print_info();//Print function

};

#endif