
#include "Tools.h"
#include <iostream>
#include <sstream>

using namespace std;
int Tools::stringToInt(string input_string){
    stringstream container(input_string);
    int x;
    container >> x;
    return x;
}

