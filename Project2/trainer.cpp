/******************************************************
** Program: trainer.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: Trainer class that handles the trainers team of pokemon, creates users team and randomly
selects computures team. Uses heap memory to keep Pokemon objects updated so their information can be updated and received.
Deletes the heap memomory with destructor.
** Input: Trainer name, Team[]
** Output: name, Team[]
******************************************************/
#include <iostream>
#include "trainer.h"
#include "pokemon.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//Trainer constructor creates a trainer with NULL holding the place of *Pokemon in the Team array
//Team will later get filled in
Trainer::Trainer(){
    Name = "Trainer";
    Team[0] = NULL; //set to NULL
    Team[1] = NULL; //new Charmander;
    Team[2] = NULL; //new Squirtle;
}
//set_Name sets the trainer name to new name from input
void Trainer::set_Name(string new_Name){
    Name = new_Name;
}
//get_name returns the Trainers name as a string 
string Trainer::get_Name(){
    return Name;
}
//get_pokemon returns the pokemon at position i in Team[i] as a Pokemon*
Pokemon* Trainer::get_pokemon(int i){
    return Team[0];
}
//set_pokemon fills Team[i] with a pokemon* from input
void Trainer::set_pokemon(Pokemon* pokemon, int i){
    Team[i] = pokemon;

}
//print_pokemon_info prints the Pokemons name and health points to the terminal, by using a Pokemon*
//-> allows Pokemon* member functions to be called
void Trainer::print_pokemon_info(Pokemon* pokemon){
    cout << pokemon->get_Name() << " has " << pokemon->get_Health_points()<< " health"<< endl;
}


//fill_team asks the user which pokemon they want in their team, they are able to choose 3 Pokemon
// with no limit to how many of each pokemon they choose
// the Team[] array is filled with new pokemon, so that these pokemon are stored on the heap
void Trainer::fill_Team(){
    for (int i = 0 ; i < 3 ; i++){
        cout << "What Pokemon are you choosing: Bulbasaur(B) Charmander(C) Squirtle(S) Charizard (CZ)" << endl;
        string chosen;
        cin >> chosen;
        if (chosen == "B"){
            Team[i] = new Bulbasaur;
        }
        if (chosen == "C"){
            Team[i] = new Charmander;
        }
        if (chosen == "S") {
            Team[i] = new Squirtle;
        }
        if (chosen == "CZ") {
            Team[i] = new Charizard;
        }
    }
}

//attack pits two pokemon from input againsts each other.
// being Pokemon*  they have access to their current health and dmg and defense abilities
// a equation is used to find how much damged is done
void Trainer::attack(Pokemon* attacker, Pokemon* defender){
    int dmg = attacker->get_Attack();
    int def = defender->get_Defense();
    float health = defender->get_Health_points();
    string a_type = attacker->get_Type();
    string d_type = defender->get_Type();
    float eff = 0.5;
    if(a_type == d_type){
        eff = 2.00;
    }

    float health_lost = 15 * (dmg / def) * eff;
    float new_health = health - health_lost;
    defender->set_Health_points(new_health);
}
//fill_computer_team fills the computers team with random pokemon
void Trainer::fill_Computer_Team(){
    srand(time(0));
    int c1 = (rand() % 3 + 1);
    int c2 = (rand() % 3 + 1);
    int c3 = (rand() % 4 + 1);
    cout << "Pc chose a ";
    run_fill(c1,0);
    run_fill(c2,1);
    run_fill(c3,2);
    cout << endl;
    
}
//run_fill is used in fill_cumputer_team to take two ints and then add a specfific pokemon to the Team[]array
// Team is filled with new Pokemon on the heap
void Trainer::run_fill(int c, int i){
    
    if (c == 1){
        Team[i] = new Bulbasaur;
        cout << "Bulbasaur ";
        }
    if (c == 2){
        Team[i] = new Charmander;
        cout << "Charmander ";
    }
    if (c == 3) {
        Team[i] = new Squirtle;
        cout << "Squirtle ";
    }
    if (c == 4) {
        Team[i] = new Charizard;
        cout << "Charizard ";  
    }
    
}
//swap allows the user or computer to swap the current pokemon with another one,
//in the inout is 1 then it goes through the user swap, else it goes through the conputer swap
void Trainer::swap(int n){
    if (n==1){
        cout<< get_Name() << " is swaping!" << endl;
        cout << "You're current Pokemon is: " << Team[0]->get_Name() << endl;
        //cout << "Which Pokemon do you want to switch to? " << Team[1]->get_Name() << "(1) " << Team[2]->get_Name() << "(2) " << endl;
        int z = can_swap();
        if (z==1){swap_two_because_we_cant_have_more_then_twenty_lines();
        }
        if (z==2) {swap_THREE_because_we_cant_have_more_then_twenty_lines();
        }   
        if (z==0){
            return;
        }
    }
    else{
        srand(time(0));
        int c1 = can_swap_pc();

        if (c1==1){swap_two_because_we_cant_have_more_then_twenty_lines();
        }
        if (c1==2) {swap_THREE_because_we_cant_have_more_then_twenty_lines();
        }   
    } 
}
//can_swap_pc makes it so that the pc cannot swap to a pokemon with no health by making sure the other pokemon have health
// or else it doesnt list them
int Trainer::can_swap_pc(){
    float health_one = Team[1]->get_Health_points();
    float health_two = Team[2]->get_Health_points();
    int z;
    if (health_one > 0){
        if (health_two > 0){
            return (rand() % 2 + 1);
        }
        else {
            return 1;
        }

    }
    if (health_two > 0){
        if (health_one == 0){
            return 2;
        }

    }
    if (health_one == 0 && health_two == 0){
        return 0;
    }
}
//can_swap asks the user which pokemon they would like to swap too,
//but makes sure it only displays pokemon that currently havce health above 0
int Trainer::can_swap(){
    float health_one = Team[1]->get_Health_points();
    float health_two = Team[2]->get_Health_points();
    int z;
    if (health_one > 0){
        if (health_two > 0){
            cout << "Which Pokemon do you want to switch to? " << Team[1]->get_Name() << "(1) " << Team[2]->get_Name() << "(2) " << endl;
        }
        else {
            cout << "Which Pokemon do you want to switch to? " << Team[1]->get_Name() << "(1) " << Team[2]->get_Name() << " has no health " << endl;
        }

    }
    if (health_two > 0){
        if (health_one == 0){
            cout << "Which Pokemon do you want to switch to? " << Team[2]->get_Name() << "(2) " << Team[1]->get_Name() << " has no health " << endl;
        }

    }
    if (health_one == 0 && health_two == 0){
        cout << "No Pokemon with health to switch too" << endl;
        return 0;
    }
    cin >> z;
    return z;
}
//swap_two arrages the team order so that the second place pokemon becomes the first
void Trainer::swap_two_because_we_cant_have_more_then_twenty_lines(){
    Pokemon* holder_array[1];
    holder_array[0] = Team[0];
    Team[0] = Team[1];
    Team[1] = holder_array[0];
}

//swap_three arrages the team so that the last pokemon become the first pokemon in the array
void Trainer::swap_THREE_because_we_cant_have_more_then_twenty_lines(){
    Pokemon* holder_array[1];
    holder_array[0] = Team[0];
    Team[0] = Team[2];
    Team[2] = holder_array[0];
}
//~trainer is a destructor that deletes the heap memomory created by the Team array
Trainer::~Trainer(){
    delete Team[0];
    delete Team[1];
    delete Team[2];

}
