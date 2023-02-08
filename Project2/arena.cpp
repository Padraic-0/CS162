/******************************************************
** Program: arena.cpp
** Author: Padraic Bergin
** Date: 10/31/2021
** Description: The arena class pits the user against a computer trainer. They chose bewtween attacking, healing, swaping
, until one trainer has no Pokemon left. Handles most of the UI.
** Input: Trainer functions to get Pokemon data
** Output: Sets Pokemon with new data when they loss health, calls functions in Trainer to change Pokemon order.
******************************************************/
#include <iostream>
#include "arena.h"
#include "pokemon.h"
#include "trainer.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//Arena construcotor is the brain of the program, calling functions to attack, swap and heal, running the play vs the
//cumpter in a endless batttle until one is vicotories, at the end of each round it checks to see if every team 
//still has remaining pokemon. Calls the destrucotrs at the end so that each trainers dynamic memory is freed
Arena::Arena(){
    Trainer user;
    cout << "What is your name? " << endl;
    string name;
    cin >> name;
    user.set_Name(name);
    Trainer pc;
    srand(time(0));
    user.fill_Team();
    pc.fill_Computer_Team();
    bool running = true;
    int n = 1;
    while (running == true){
        if (n == 1){
        cout << "Your move " << user.get_Name() << endl;
        cout << user.get_pokemon(0)->get_Name() << " vs " << pc.get_pokemon(0)->get_Name() << endl;
        cout << "Would you like to Attack(A) , Heal(H) , Swap(S)?" << endl;
        string choice;
        cin >> choice;
        if (choice == "A"){
            attack(user.get_pokemon(0), pc.get_pokemon(0));
            cout << pc.get_pokemon(0)->get_Name()<< " has " << pc.get_pokemon(0)->get_Health_points() << " health" << endl;
            if (has_to_switch(pc.get_pokemon(0)->get_Health_points()) == true){
                    pc.swap(0);
                }
            }
        if (choice == "H"){
            heal(user.get_pokemon(0));
            }
        if (choice == "S"){
            user.swap(1);
            cout << user.get_pokemon(0)->get_Name() << " vs " << pc.get_pokemon(0)->get_Name() << endl;
            }
        cout << "Computers move" << endl;
        int c1 = (rand() % 10 + 1);
        if (c1 == 1 || c1 == 4 || c1 == 5 || c1 == 6 || c1 == 7 || c1 == 8 || c1 == 9 || c1 == 10){
            cout << "Computer is attacking!" << endl;
          attack(pc.get_pokemon(0), user.get_pokemon(0));
          cout << user.get_pokemon(0)->get_Name()<< " has " << user.get_pokemon(0)->get_Health_points() << " health" << endl;
          if (has_to_switch(user.get_pokemon(0)->get_Health_points()) == true){
                    user.swap(1);
                }
          }
        if (c1 == 2){
            cout << "Computer is healing!" << endl;
            heal(pc.get_pokemon(0));
            }
        if (c1 ==3){
            cout << "Computer is swaping!" << endl;
            pc.swap(0);
            cout << user.get_pokemon(0)->get_Name() << " vs " << pc.get_pokemon(0)->get_Name() << endl;
            }
        else{

        }
        running = match_over(user.get_pokemon(0),user.get_pokemon(1),user.get_pokemon(2),pc.get_pokemon(0),pc.get_pokemon(1),pc.get_pokemon(2));
        n = 1;
       }
}
user.~Trainer();
pc.~Trainer();
}
//round is a unused function that would run a round
void Arena::round(int z, Pokemon* user, Pokemon* pc, Trainer trainer){
    cout << "New round!" << endl;
    if (z==1){
        cout << "Your move first" << endl;
        cout << user->get_Name() << " vs " << pc->get_Name() << endl;
        cout << "Would you like to Attack(A) , Heal(H) , Swap(S)?" << endl;
        string choice;
        cin >> choice;
        if (choice == "A"){
            attack(user, pc);
            cout << pc->get_Name()<< " has " << pc->get_Health_points() << " health" << endl;
            
        }
        if (choice == "H"){
            heal(user);
            
        }
        if (choice == "S"){
            trainer.swap(1);
            
        }
       
        
    }

}
//has_to_swtich forces the player to switch pokemon if their current one was damaged to 0 health
// this doesnt take up a turn
bool Arena::has_to_switch(float health){
    if(health == 0){
        cout << "Pokemon has no health, must switch"<<endl;
        return true;
    }
    else {
        return false;
    }
}
//attack pits two pokemon from input againsts each other.
// being Pokemon*  they have access to their current health and dmg and defense abilities
// a equation is used to find how much damged is done
// isntead of negative health, health is capped at 0 health
void Arena::attack(Pokemon* attacker, Pokemon* defender){
    float dmg = attacker->get_Attack();
    float def = defender->get_Defense();
    float health = defender->get_Health_points();
    float eff = type_damage(attacker, defender);
    float random = random_damage();
    if (eff == 2){
        cout << "Strong attack!" << endl;
    }
    if (eff == 1){
        cout << "Normal attack!" << endl;
    }
    if (eff == 0.5){
        cout << "Weak attack!" << endl;
    }
    //cout << dmg << endl;
    //cout << def << endl;
    float health_lost = 15 * (dmg / def) * eff * random;
    float new_health = health - health_lost;
    cout << health_lost << " damage was done"<< endl;
    defender->set_Health_points(new_health);
    if (defender->get_Health_points() < 0){
        defender->set_Health_points(0);
    }
}
//heal allows the pokemon to heal by 15 points
//taking in a pokemon*, -> allows access to memebr fucntion in the Pokemon class so that 
//health can be set from within this function
// limits new health to the max health that a pokemon can have
void Arena::heal(Pokemon* pokemon){
    float current_health = pokemon->get_Health_points();
    float max_Health = pokemon->get_max_Health_points();
    float new_Health = current_health + 15;
    if (current_health == 0){
        cout <<"Pokemon has no health and cant be healed"<< endl;
        return;
    }
    if (new_Health > max_Health){
        pokemon->set_Health_points(max_Health);
        cout << pokemon->get_Name() << " healed to max health" << endl;
    }
    else {
        pokemon->set_Health_points(new_Health);
        cout << pokemon->get_Name() << " healed " << endl;
    }
}

/*
void Arena::swap(Pokemon* p1, Pokemon* p2, Pokemon* p3){
    
    cout << "You're current Pokemon is: " << p1->get_Name() << endl ;
    cout << "Which Pokemon do you want to switch to? " << p2->get_Name() << "(1) " << p3->get_Name() << "(2) " << endl;
    int n;
    cin >> n;
    if (n==1){
        holder_array[0] = p2;
        holder_array[1] = p1;
        holder_array[2] = p3;
    }
    else {
        holder_array[0] = p3;
        holder_array[1] = p1;
        holder_array[2] = p2;
    }
    
}
*/
//type_damage gets the two pokemon types and compares them to see if it is a strong, weak, or normal attack
//lots of if statements are run to check combitnations.
float Arena::type_damage(Pokemon* attacker, Pokemon* defender){
    string a_type = attacker->get_Type();
    string d_type = defender->get_Type();
    cout << a_type << d_type<<endl;
    float eff = 1;
    if(a_type == "Fire"){
        if (d_type == "Grass"){
            eff = 2.00;
            return eff;
        }
        if (d_type == "Water"){
            
            eff = 0.5;
            return eff;
        }
        else {
            
            eff = 1;
            return eff;
        }
        
        
    }
    if(a_type == "Water"){
           
            if (d_type == "Fire"){
                
                eff = 2.00;
                return eff;
            }
            if (d_type == "Grass"){
                                
                eff = 0.5;
                return eff;
            }
            else {
                
                eff = 1;
                return eff;
            }
            
            
        }
    if(a_type == "Grass"){
        
         if (d_type == "Water"){
            
            eff = 2.00;
            return eff;
        }
        if (d_type == "Fire"){
            
            eff = 0.5;
            return eff;
        }
        else {
            
            eff = 1;
            return eff;
        }
        
        
    }
 
    
}
//match_over tests to see if all the user or pc pokemon are out of health, as long as two pokemon
//can battle then the match goes on.
bool Arena::match_over(Pokemon* user1, Pokemon* user2, Pokemon* user3, Pokemon* pc1, Pokemon* pc2, Pokemon* pc3){
    if (user1->get_Health_points() == 0 ){
        if (user2->get_Health_points() == 0){
            if (user3->get_Health_points() == 0){
                cout << "Pc has won the game!" << endl;
                return false;
            }
        }
        
    }
    if (pc1->get_Health_points() == 0 ){
        if (pc2->get_Health_points() == 0){
            if (pc3->get_Health_points() == 0){
                cout << pc1->get_Health_points()<<pc2->get_Health_points()<<pc3->get_Health_points()<<endl;
                cout << "User has won the game!" << endl;
                return false;
            }
        }
        
    }
    else {
        return true;
    }
}
//random_damage returns a float that is used in the damage function
//adding a bit of randoness to each attack.
// for 0.85 to 1.15 multipliers
float Arena::random_damage(){
    int d = (rand() % 30 + 85);
    return d *0.01;
}
