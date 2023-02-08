/******************************************************
** Program: pokemon.h
** Author: Padraic Bergin
** Date: Oct 18th, 2021
** Description: Pokemon header file, defines the functions of the Pokemon Class
** Input: Pokemon data
** Output: Pokemon data
******************************************************/
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
    /*********************************************************************
      ** Function: Pokemon 
      ** Description: Parameter constructor 
      ** Parameters: int dex num, string name, string type  
      ** Pre-Conditions: Pokemon class called 
      ** Post-Conditions: Pokemon with name type and dex number  
      *********************************************************************/ 
    Pokemon(int,string,string);
    

    /*********************************************************************
      ** Function: get dex num 
      ** Description: return the dex number 
      ** Parameters: none  
      ** Pre-Conditions: dex number needs to be set, or default construcotor called 
      ** Post-Conditions: returns int dex num 
      *********************************************************************/ 
    int get_Dex_num();//Getter


    /*********************************************************************
      ** Function: Set dex num
      ** Description: Setter for dex num 
      ** Parameters: int dex_num  
      ** Pre-Conditions: pokemon object needs to created
      ** Post-Conditions: Pokemon now has set dex number 
      *********************************************************************/     
    void set_Dex_num(int);//setter


    /*********************************************************************
      ** Function: get_types 
      ** Description: returns the Pokemon type 
      ** Parameters: non   
      ** Pre-Conditions: called with pokemon object 
      ** Post-Conditions: returns string 
      *********************************************************************/ 
    string get_Types();//Getter


    /*********************************************************************
      ** Function: set_types 
      ** Description:  setter for pokemon type
      ** Parameters:  string type 
      ** Pre-Conditions: pokemon object which is gettign type needs to exists 
      ** Post-Conditions: pokemon now has a set type 
      *********************************************************************/ 
    void set_Types(string);//setter


    /*********************************************************************
      ** Function: set_name
      ** Description: setter for name 
      ** Parameters: string name   
      ** Pre-Conditions:  pokemon needs to exist
      ** Post-Conditions:  pokemon now has set name
      *********************************************************************/    
    void set_Name(string);//setter


    /*********************************************************************
      ** Function:  get_name
      ** Description:  getter for name
      ** Parameters:  pokemon exists 
      ** Pre-Conditions: pokemon has a name 
      ** Post-Conditions:  returns pokemon name
      *********************************************************************/ 
    string get_Name();//getter
    

    /*********************************************************************
      ** Function: get_moves 
      ** Description: returns the move at array spot move_number 
      ** Parameters: int move_number  
      ** Pre-Conditions: moves need to be assigned 
      ** Post-Conditions: returns the pokemon move 
      *********************************************************************/ 
    string get_Moves(int move_number);


    /*********************************************************************
      ** Function:  set_moves
      ** Description: sets move at int, to string move 
      ** Parameters:  int move_num, string move 
      ** Pre-Conditions: array of moves needs to exist 
      ** Post-Conditions:  pokemon now has set move
      *********************************************************************/ 
    void set_Moves(int ,string);//getter


    /*********************************************************************
      ** Function: Pokemon 
      ** Description: construcotor
      ** Parameters:  non
      ** Pre-Conditions: non
      ** Post-Conditions: Pokemon with default values is created
      *********************************************************************/
    Pokemon();//Constructor


    /*********************************************************************
      ** Function: print_info
      ** Description: prints pokemon info to terminal
      ** Parameters: non 
      ** Pre-Conditions: called with pokemon object
      ** Post-Conditions: terminal prints pokemon info
      *********************************************************************/
    void print_info();//Print function

};

#endif