/******************************************************
** Program: driver.cpp
** Author: Padraic Bergin
** Date: 11/25/2021
** Description: Takes in command line arg for size and wether its in debug mode and then calls the game constructor
with those values. 
** Input: command line arg
** Output: int size, bool debug
******************************************************/
#include <iostream>
#include "game.h"
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]) {
    int size = atoi(argv[1]);
    if (size < 4){
        return 0;
    }
    string debug_string = argv[2];
    bool debug = false;
    if (debug_string == "true"){
        debug = true;
    }


    Game g1(size,debug);

    return 0;
}