#ifndef ADVENTURER_H
#define ADVENTURER_H
#include "coordinates.h"
#include <iostream>
#include <vector>
using namespace std;
class Adventurer{
    private:
        Coordinates location;
        bool can_escape;
    public:
        void set_player_location(int, int);
        Coordinates get_player_location();
        bool get_can_escape();
        void set_can_escape(bool);
    
        
};

#endif