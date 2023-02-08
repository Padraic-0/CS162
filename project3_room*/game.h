#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "adventurer.h"
#include "event.h"
#include "empty_room.h"
#include "super_bats.h"
#include "gold.h"
#include "wumbus.h"
#include "bottomless_pit.h"
#include "coordinates.h"
using namespace std;
class Game{
    private:
        Coordinates wumbus;
    public:
        
        Game();
        //Game(vector<vector<Room*>>&);
        void Game_destructor(vector<vector<Room*>>& ,vector<vector<Room*>>&, int);
        void build_cave(int,vector<vector<Room*>>&,Coordinates);
        void room(int,int,int,vector<vector<Room*>>&, Coordinates);
        void middle_room();
        void bottom_room(int);
        void print_room();
        string event();
        void fill_events(vector<vector<Room*>> &, int);
        void fill_events_two(vector<vector<Room*>> &, int);
        void copy(vector<vector<Room*>>&,vector<vector<Room*>>&, int);
        void clear_events(vector<vector<Room*>>, int);
        Coordinates spawn(vector<vector<Room*>>&, Adventurer&,int);
        int move(vector<vector<Room*>>&, int,Adventurer&);
        void shoot_arrow(char, Adventurer, vector<vector<Room*>>&, int);
        int check_wumbus(vector<vector<Room*>> &,int, int, int);
        void awake_wumbus(vector<vector<Room*>> &);
        Coordinates set_wumbus_location(vector<vector<Room*>> &, int);
        Coordinates get_wumbus_location();
        void call_precept(vector<vector<Room*>> &, Adventurer &);
        bool valid_move(int, int,char, int);
        int escape_rope(Coordinates, Adventurer&);
};


#endif