/******************************************************
** Program: pokedex.h
** Author: Padraic Bergin
** Date: Oct 18th, 2021
** Description: Pokemon header file with Pokemon class functions defined 
** Input: Dex data
** Output: Dex data
******************************************************/
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

    public:

    
    Pokemon* dex;
    /*********************************************************************
      ** Function: Pokedex 
      ** Description: constructor
      ** Parameters: non  
      ** Pre-Conditions: non
      ** Post-Conditions: Pokedex with default variables is created
      *********************************************************************/
    Pokedex();
    

    /*********************************************************************
      ** Function: get_num_pokemon 
      ** Description: getter for number of pokemon
      ** Parameters: non  
      ** Pre-Conditions: non
      ** Post-Conditions: returns number of pokemon
      *********************************************************************/
    int get_num_pokemon();//getter


    /*********************************************************************
      ** Function: set_num_pokemon
      ** Description: setter for number of pokemon
      ** Parameters: int number of pokemon 
      ** Pre-Conditions: non
      ** Post-Conditions: number of pokemon is set 
      *********************************************************************/
    void set_num_pokemon(int);//setter


    /*********************************************************************
      ** Function:  get_trainer
      ** Description: returns trainer name
      ** Parameters: non 
      ** Pre-Conditions: string 
      ** Post-Conditions: returns string name 
      *********************************************************************/
    string get_trainer();//getter


    /*********************************************************************
      ** Function:  set_trainer
      ** Description: sets trainers name 
      ** Parameters: string name
      ** Pre-Conditions: non
      ** Post-Conditions: sets trainer name in pokedex
      *********************************************************************/
    void set_trainer(string);//setter

    /*********************************************************************
      ** Function: set_pokemon  
      ** Description: sets pokemon into dex
      ** Parameters:pokemon and dex position  
      ** Pre-Conditions: dex created
      ** Post-Conditions: sets pokemon into dex
      *********************************************************************/
    void set_pokemon(Pokemon,int);//setter


    /*********************************************************************
      ** Function:  get_pokemon_info
      ** Description: assignes the chuncks of string in the input file to Pokemon attributes, then copies temp pokemon to specific spot in dex[]
      ** Parameters: ifstream
      ** Pre-Conditions: ifstream open 
      ** Post-Conditions: files pokemon with data
      *********************************************************************/
    void get_pokemon_info(ifstream &);//assignes the chuncks of string in the input file to Pokemon attributes, then copies temp pokemon to specific spot in dex[]
    
    
    /*********************************************************************
      ** Function:  search_by_dex_number
      ** Description: searchs dex for pokemon with matching dex number
      ** Parameters:  ofsteam, dexnum, where to print
      ** Pre-Conditions: dex[]
      ** Post-Conditions: prints to terminal or file pokemon
      *********************************************************************/   
    void search_by_dex_number(ofstream &, int, string);//searches dex for matching dex number, calls either terminal or file print function
   
   
    /*********************************************************************
      ** Function:  search_by_type
      ** Description: searches for pokemon with matching type
      ** Parameters: ofstream, type, where to print  
      ** Pre-Conditions: dex[]
      ** Post-Conditions: prints to terminal or file pokemon
      *********************************************************************/
    void search_by_type(ofstream &, string, string);//searches dex for types of pokemon, prints to file or terminal
    
    
    /*********************************************************************
      ** Function:  Pokedex
      ** Description: constructor that gets the number of pokemon in file
      ** Parameters:  ifstream
      ** Pre-Conditions: open input file
      ** Post-Conditions: number of pokemon stored
      *********************************************************************/
    Pokedex(ifstream &);//constructor that gets the number of pokemon in file
    

    /*********************************************************************
      ** Function:  print_pokemon_info
      ** Description: prints pokemon info to file
      ** Parameters:  ofstream, pokemon
      ** Pre-Conditions: non
      ** Post-Conditions: prints to terminal or file pokemon
      *********************************************************************/  
    void print_pokemon_info(ofstream &, Pokemon);//prints pokemon info to file
    
    
    /*********************************************************************
      ** Function: search_by_name
      ** Description: searches dex for pokemon with same name 
      ** Parameters: ofsteam, name, where to print 
      ** Pre-Conditions: dex needs to be filled with pokemon
      ** Post-Conditions: prints to terminal or file pokemon
      *********************************************************************/
    void search_by_name(ofstream &, string, string);//compares pokemon in dex to name string, prints to file or terminal
    
    
    /*********************************************************************
      ** Function: add_pokemon
      ** Description: asks user for pokemon info, adds it to file they requested
      ** Parameters: of stream open
      ** Pre-Conditions: of stream open 
      ** Post-Conditions: pokemon data added to file
      *********************************************************************/
    void add_pokemon(ofstream &);//gets user input for pokemons and prints it to file
    

    /*********************************************************************
      ** Function: print_pokemon_info_terminal
      ** Description: prints pokemon info to terminal
      ** Parameters: pokemon object  
      ** Pre-Conditions: pokemon exists 
      ** Post-Conditions: pokemon printed
      *********************************************************************/ 
    void print_pokemon_info_terminal(Pokemon);//prints pokemon to terminal


    /*********************************************************************
      ** Function: print_all_pokemon
      ** Description: prints all pokemon fout
      ** Parameters:  ofstream&
      ** Pre-Conditions: ofstream open
      ** Post-Conditions: prints all pokemon
      *********************************************************************/
    void print_all_pokemon(ofstream &);//calls print pokemon info for each pokemon


    /*********************************************************************
      ** Function:  where_to_print
      ** Description: questions where to print
      ** Parameters: non 
      ** Pre-Conditions: non
      ** Post-Conditions: returns string where to print
      *********************************************************************/
    string where_to_print();//asks user where to print


    /*********************************************************************
      ** Function:  open_file
      ** Description: asks user for file name
      ** Parameters: string file name 
      ** Pre-Conditions: non
      ** Post-Conditions: returns file name
      *********************************************************************/
    string open_file(string);//asks user for file name
    
    
    /*********************************************************************
      ** Function: ~pokedex 
      ** Description: destrucotr
      ** Parameters: non
      ** Pre-Conditions: constructor
      ** Post-Conditions: array of pokedex destroyed
      *********************************************************************/
    ~Pokedex();

    


};


#endif