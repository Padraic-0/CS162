/******************************************************
** Program: driver.cpp
** Author: Padraic Bergin
** Date: Mon Oct 18th, 2021
** Description: Command line argument takes a file to be opened, the Pokemon in this file
are read into a dex, where each Pokemons: dex number, name, type, and four moves. This store
information can be looked up by the user and either printed to a file or the terminal. Additionally
the user may add a Pokemon to a desired file by filing out the required data for a Pokemon.
** Input: User defined Pokemon file
** Output: Pokemon data
******************************************************/
#include <iostream>
#include "./pokemon.h"
#include "./pokedex.h"
#include <fstream>
#include <stdlib.h>
using namespace std;


int main(int argc, char *argv[]){
    string input_file;
    input_file = argv[1];
    cout << input_file << endl;
    fstream f;
    ifstream fin(input_file.c_str());
    if (!fin.is_open()){
        cout << "File doesn't exist"<< endl;
        return 0;
    }
    Pokedex inputs(fin);
    inputs.get_pokemon_info(fin);
    ofstream fout;
    

    bool run;
    run = true;
    while (run==true){
        cout << "Would you like to search for Pokemon? (Y/N) or add a Pokemon? (A)" << endl;
        string answer;
        cin >> answer;
        if (answer=="Y"){
            cout << "Would you like to search for a Pokemon by dex number(1) or by type(2) or by name(3) " << endl;
            int searchoption;
            cin >> searchoption;
            string where_to_print;
            string outputfile;
            if (searchoption == 1){
                cout << "Would you like to print information to the terminal or to a file? (T/F) " << endl;
                string where_to_print;
                cin >> where_to_print;
                if (where_to_print == "F"){
                    cout << "What is the name of the output file? (file name(.txt) " << endl;
                    cin >> outputfile;
                }
                ofstream fout(outputfile.c_str(), ios::app);
                cout <<"Whats the dex number of Pokemon are you looking for: " << endl;
                int searchdex;
                cin >> searchdex;
                inputs.search_by_dex_number(fout, searchdex, where_to_print);
                
            }   

            if (searchoption == 2){
                cout << "Would you like to print information to the terminal or to a file? (T/F) " << endl;
                string where_to_print;
                cin >> where_to_print;
                if (where_to_print == "F"){
                    cout << "What is the name of the output file? (file name(.txt) " << endl;
                    cin >> outputfile;
                }
                ofstream fout(outputfile.c_str(), ios::app);
                cout <<"Whats the type of Pokemon are you looking for: " << endl;
                string searchtype;
                cin >> searchtype;
                inputs.search_by_type(fout, searchtype, where_to_print);
            }
            if (searchoption== 3){
                cout << "Would you like to print information to the terminal or to a file? (T/F) " << endl;
                string where_to_print;
                cin >> where_to_print;
                if (where_to_print == "F"){
                    cout << "What is the name of the output file? (file name(.txt) " << endl;
                    cin >> outputfile;
                }
                ofstream fout(outputfile.c_str(), ios::app);
                cout << "Whats the name of the Pokemon you are looking for: " << endl;
                string searchname;
                cin >> searchname;
                inputs.search_by_name(fout, searchname, where_to_print);
            }
        }
        
        if (answer=="N"){
            run = false;
        }

        if (answer=="A"){
            cout << "Where would you like to add this Pokemon to? (filename.txt) " << endl;
            string added_pokemon_file;
            cin >> added_pokemon_file;
            
            ofstream fout(added_pokemon_file.c_str(), ios::trunc);
            fout << inputs.get_num_pokemon() + 1 <<"\n";
            inputs.print_all_pokemon(fout);
            
            inputs.add_pokemon(fout);
            fout.close();

            ifstream fin(added_pokemon_file.c_str());
            Pokedex inputs(fin);
            inputs.get_pokemon_info(fin);
            

        }
        //ofstream fout(outputfile.c_str(), ios::app);


        
    }
    
    
    


    


    




    return 0;
}