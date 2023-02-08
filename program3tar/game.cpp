/******************************************************
** Program: game.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Main file for controlling the flow of the game, builds the cave to user size and then files it
with events. Each loop of the game allows the player to move and then checks what events are around it to print 
the noises they make. The user has to option to quit the game, play the same map, or play a new one 
** Input: size of cave, and debug mode
** Output: non
******************************************************/
#include <iostream>
#include <algorithm>
#include "game.h"
#include "adventurer.h"
#include "coordinates.h"
#include "event.h"
#include "empty_room.h"
#include "super_bats.h"
#include "gold.h"
#include "wumbus.h"
#include "bottomless_pit.h"
#include "coordinates.h"
#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
#include <math.h>
#include <cstdlib> 
using namespace std;
Game::Game(int size, bool debug){
    Adventurer a1;
    
    //vector<vector<Event*> > map(4,vector<Event*>(4,NULL));
    vector<vector<Event*>> map (size,vector<Event*>(size,NULL));
    vector<vector<Event*>> copy_map (size,vector<Event*>(size,NULL));
    //map.begin();
    //vector<vector<Event*>> iterator:: row;
    //map.reserve(25);
    map.resize(size*size);
    fill_events(map, size);
    //spawn(a1);
    copy(map,copy_map,size);
    //build_cave(5, map, a1.get_player_location());
    bool on = true;
    bool run = true;
    while (on == true){
        bool has_gold = false;
        copy(copy_map,map,size);
        Coordinates spawn_location = spawn(map,a1,size);
        build_cave(size,map, a1.get_player_location(),debug);
        call_precept(map, a1);
        
        while (run == true){
            wumbus = set_wumbus_location(map, size);
            int encounter = move(map, size, a1, debug);
            if (encounter == 2){
                has_gold = true;
            }
            if (encounter == 1 || ((has_gold) && (escape_rope(spawn_location,a1) == 1))){run = false;}
            call_precept(map, a1);
        
            
        }
        
        cout << "Would you like to play again? same map(1) new map(2) quit (3) "<< endl;
        int choice;
        cin >> choice;
        if (choice == 2){
            Game g1(size,debug);
        }
        if (choice == 3){
            on = false;
            run = false;
            Game_destructor(map,copy_map, size);
            //delete copy_map[0][0];
        }
        if (choice == 1){
            on = true;
            run = true;
        }

    }
    
    
    

    /*
    
    vector <vector<char>> map;
    map.reserve(16);
    map = {
            {' ','*','g','s'},
            {' ',' ','w','b'},
            {'p',' ',' ','b'},
            {'b','p','p','p'}
        };
    
    build_cave(4,map);
    Adventurer a1;
    a1.location = a1.player_location(map,4);
    cout << a1.location.x<<a1.location.y<<"location"<<endl;
    */
    
}


void Game::build_cave(int size,vector<vector<Event*>> &map, Coordinates a1, bool debug){
    //srand ( unsigned ( std::time(0) ) );
    //random_shuffle(map.begin(),map.end(), myrandom);
    cout << endl;
    for (int i = 0; i < size; i++){
        for (int p = 0; p < size; p++){
            room(i,p,size,map,a1,debug);
        }
    }
    for(int z = 0; z < size; z++){
            cout<<"*---*";
            if (z==size-1){
                cout<<endl;
            }
        }

    
}

void Game::room(int i, int p, int size,vector<vector<Event*>> &map, Coordinates a1,bool debug){
    cout<<"*---*";
    if (p==size-1){
        cout<<endl;
        for(int z = 0; z < size; z++){
            string icon;
            if ((i == a1.x) && (z == a1.y)){
                icon = "*";
            }
            else{
                if (debug){
                    icon = map[i][z]->get_icon();
                }
                else{
                    icon = " ";
                }
                
            }
            cout<<"| "<< icon <<" |";
            if (z==size-1){
                cout<<endl;
            }
        }
    }
}

void Game::fill_events(vector<vector<Event*>> &map, int size){
   for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            map[i][j] = new Empty_room;
            map[i][j]->set_coordinates(i,j);
        }
   }
   fill_events_two(map,size);
   /*
   map[0][0] = new Gold;
   map[0][0]->set_coordinates(0,0);
   map[0][1] = new Wumbus;
   map[0][1]->set_coordinates(0,1);
   map[0][2] = new Super_bats;
   map[0][2]->set_coordinates(0,2);
   map[0][3] = new Super_bats;
   map[0][3]->set_coordinates(0,3);
   map[1][0] = new Bottomless_pit;
   map[1][0]->set_coordinates(1,0);
   map[1][1] = new Bottomless_pit;
   map[1][1]->set_coordinates(1,1);
   */
   

   /*
   a = (rand() % (size-1));
   b = (rand() % (size-1));
   c = (rand() % (size-1));
   d = (rand() % (size-1));
   e = (rand() % (size-1));
   f = (rand() % (size-1));
   g = (rand() % (size-1));
   h = (rand() % (size-1));
   i = (rand() % (size-1));
   j = (rand() % (size-1));
   k = (rand() % (size-1));
   l = (rand() % (size-1));
   map[a][b] = new Gold;
   map[a][b]->set_coordinates(0,0);
   map[c][d] = new Wumbus;
   map[c][d]->set_coordinates(0,1);
   map[e][f] = new Super_bats;
   map[e][f]->set_coordinates(0,2);
   map[g][h] = new Super_bats;
   map[g][h]->set_coordinates(0,3);
   map[i][j] = new Bottomless_pit;
   map[i][j]->set_coordinates(1,0);
   map[k][l] = new Bottomless_pit;
   map[k][l]->set_coordinates(1,1);
   


   for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout <<map[i][j]->get_icon()<< map[i][j]->get_coordinates().x<<map[i][j]->get_coordinates().y<< "coordinates"<<endl;
        }
   }
   
   

    
    for (int i = 0; i < size; i++){
        
        for (int j = 0; j < size; j++){
            if (i == 0 && j ==0){
                map[i][j] = new Gold;
                map[i][j]->set_coordinates(i,j);
                cout<<"works"<<endl;
                cout <<map[i][j]->get_icon()<< map[i][j]->get_coordinates().x<<map[i][j]->get_coordinates().y<< "coordinates"<<endl;
                
            }
            if (i == 0 && j == 1){
                map[i][j] = new Wumbus;
                map[i][j]->set_coordinates(i,j);
                cout <<map[i][j]->get_icon()<< map[i][j]->get_coordinates().x<<map[i][j]->get_coordinates().y<< "coordinates"<<endl;
                
            }
            if (i == 0 && ((j == 2) || (j == 3))){
                map[i][j] = new Super_bats;
                map[i][j]->set_coordinates(i,j);
                cout <<map[i][j]->get_icon()<< map[i][j]->get_coordinates().x<<map[i][j]->get_coordinates().y<< "coordinates"<<endl;
                
            }
            if (i == 1 && ((j == 0) || (j == 1))){
                map[i][j] = new Bottomless_pit;
                map[i][j]->set_coordinates(i,j);
                cout <<map[i][j]->get_icon()<< map[i][j]->get_coordinates().x<<map[i][j]->get_coordinates().y<< "coordinates"<<endl;
                
            }
            //if(i >=1 && ((j != 0) || (j != 1))) {
            else{
                map[i][j] = new Empty_room;
                map[i][j]->set_coordinates(i,j);
                cout <<map[i][j]->get_icon()<< map[i][j]->get_coordinates().x<<map[i][j]->get_coordinates().y<< "coordinates"<<endl;
                
            }
            
        }
    }
    */
}

void Game::fill_events_two(vector<vector<Event*>> &map, int size){
    srand(time(NULL));
    for (int i = 0; i < 7;){
        int x = (rand() % (size-1));
        int y = (rand() % (size-1));
        if (map[x][y]->get_icon() == " "){
            if (i < 2){
                delete map[x][y];
                map[x][y] = new Bottomless_pit;
            }
            if (i > 4){
                delete map[x][y];
                map[x][y] = new Super_bats;
            }
            if (i == 3){
                delete map[x][y];
                map[x][y] = new Gold;
            }
            if (i == 4){
                delete map[x][y];
                map[x][y] = new Wumbus;
            }
            i++;
        }

    }
}

void Game::clear_events(vector<vector<Event*>> map, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            map[i].pop_back();
        }
    }
}

void Game::Game_destructor(vector<vector<Event*>> &map,vector<vector<Event*>> &copy_map, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            delete map[i][j];
            //delete copy_map[i][j];
        }
    }
    //delete map;
}

Coordinates Game::spawn(vector<vector<Event*>>&map ,Adventurer &a1, int size){
    srand(time(NULL));
    int x = (rand() % (size-1));
    int y = (rand() % (size-1));
    while(map[x][y]->get_icon() != " "){
        x = (rand() % (size-1));
        y = (rand() % (size-1));
    }
    a1.set_player_location(x,y);
    Coordinates spawn_location;
    spawn_location.x = x;
    spawn_location.y = y;
    return spawn_location;
}

int Game::move(vector<vector<Event*>> &map, int size,Adventurer &a1,bool debug){
    
    cout <<"Where move"<<endl;
    system("stty raw");
    char input = getchar();
    char input2;
    if (input == ' '){ 
         input2 = getchar();
    }
    //cout << endl;
    //cout << "--"<<input<<"--";
    system("stty cooked");
    if (input == 'w' && valid_move(a1.get_player_location().x, a1.get_player_location().y, input, size)){
        a1.set_player_location((a1.get_player_location().x - 1), a1.get_player_location().y);
    }
    if (input == 'a' && valid_move(a1.get_player_location().x, a1.get_player_location().y, input, size)){
        a1.set_player_location((a1.get_player_location().x), a1.get_player_location().y - 1);
    }
    if (input == 's' && valid_move(a1.get_player_location().x, a1.get_player_location().y, input, size)){
        a1.set_player_location((a1.get_player_location().x + 1), a1.get_player_location().y);
    }
    if (input == 'd' && valid_move(a1.get_player_location().x, a1.get_player_location().y, input, size)){
        a1.set_player_location((a1.get_player_location().x), a1.get_player_location().y + 1);
    }
    if (input == ' '){
        shoot_arrow(input2, a1, map, size);
    }

    int event = map[a1.get_player_location().x][a1.get_player_location().y]->encounter(map,a1);
    //a1.set_player_location(x,y);
    build_cave(size, map, a1.get_player_location(),debug);
    return event;
    
}

void Game::shoot_arrow(char direction, Adventurer a1, vector<vector<Event*>> &map, int size){
    int x = a1.get_player_location().x;
    int y = a1.get_player_location().y;
    int z;
    if (direction == 'w'){
        z = check_wumbus(map, x-1, y, 1);
        if (z==0){
            check_wumbus(map, x-2, y, 2);
        }
    }
    if (direction == 'a'){
        z = check_wumbus(map, x, y-1, 1);
        if (z==0){
            check_wumbus(map, x, y-2, 2);
        }
    }
    if (direction == 's'){
        z = check_wumbus(map, x+1, y, 1);
        if (z==0){
            check_wumbus(map, x+2, y, 2);
        }
    }
    if (direction == 'd'){
        z = check_wumbus(map, x, y+1, 1);
        if (z==0){
            check_wumbus(map, x, y+2, 2);
        }
    }
}

int Game::check_wumbus(vector<vector<Event*>> &map, int x , int y, int rooms_flown_through){
    int size = pow(map.size(), 0.5);
    string icon;
    if (x > -1){
        if (x < size){
            if (y > -1){
                if (y < size){
                    icon = map[x][y]->get_icon();
                }
            }
        }
    }
    
    if (icon == "w"){
        cout << endl;
        cout << "you hit the wumbus" << endl;
        wumbus = get_wumbus_location();
        //delete map[wumbus.x][wumbus.y];
        delete map[wumbus.x][wumbus.y];
        map[wumbus.x][wumbus.y] = new Empty_room;
        return 1;
    }
    else{
        if(rooms_flown_through == 2){
            cout << "You missed the wumbus"<< endl;
            awake_wumbus(map);
            return 0;
        }
    }
    

}

void Game::awake_wumbus(vector<vector<Event*>> &map){
    int c1 = (rand() % 100 + 1);
    int size;
    cout << c1;
    int tempx = get_wumbus_location().x;
    int tempy = get_wumbus_location().y;
    if (c1 < 75){
        srand(time(NULL));
        size = pow(map.size(), 0.5);
        int x = (rand() % (size-1));
        int y = (rand() % (size-1));
        while(map[x][y]->get_icon() != " "){
            //cout << "works" << endl;
            x = (rand() % (size-1));
            y = (rand() % (size-1));
            //cout << x<<y << endl;

    }
        delete map[x][y];
        map[x][y] = new Wumbus;
        delete map[tempx][tempy];
        map[tempx][tempy] = new Empty_room;
    }
}

Coordinates Game::set_wumbus_location(vector<vector<Event*>> &map, int size){
    //Coordinates wumbus;
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++)
            if (map[x][y]->get_icon() == "w"){
                wumbus.x = x;
                wumbus.y = y;
            }
    }
    return wumbus;
}

Coordinates Game::get_wumbus_location(){
    return wumbus;
}

void Game::call_precept(vector<vector<Event*>> &map,Adventurer &a1){
    int x;
    int y;
    int size = pow(map.size(), 0.5);

    
    x = a1.get_player_location().x;
    y = a1.get_player_location().y;
    if (x < (size-1)){
        map[x][y]->percept();
        map[x+1][y]->percept();
    }
    if (x > 0){
        map[x-1][y]->percept();
    }
        
    if (y < (size-1)){
        map[x][y+1]->percept();
    }
    if (y > 0){
        map[x][y-1]->percept();
    }


}

bool Game::valid_move(int x, int y,char direction, int size){
    if (direction == 'w'){
        if (x == 0){
            return false;
        }
    }
    if (direction == 's'){
        if (x == (size-1)){
            return false;
        }
    }
    if (direction == 'a'){
        if (y == 0){
            return false;
        }
    }
    if (direction == 'd'){
        if (y == (size-1)){
            return false;
        }
    }
    else{
        return true;
    }

}

void Game::copy(vector<vector<Event*>> &base,vector<vector<Event*>> &blank, int size){
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            blank[x][y] = base[x][y];
        }
    }
}

int Game::escape_rope(Coordinates spawn_location, Adventurer &a1){
    int x = spawn_location.x;
    int y = spawn_location.y;
    if (x == a1.get_player_location().x && y == a1.get_player_location().y){
        if (a1.get_can_escape()){
            cout <<"Would you like to escape? (y/n)"<< endl;
            string input;
            cin >> input;
            if (input == "y"){
                return 1;
            }
            else{
                a1.set_can_escape(0);
                return 0;
            }
        }
    }
    else {
        return 0;
    }
}