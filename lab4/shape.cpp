#include <iostream>
#include "shape.h"
using namespace std;

Shape::Shape(){
    name = "Name";
    color = "Color";

}

float Shape::area(){
    return 0;
}

string Shape::get_name(){
    return name;
}

void Shape::set_name(string new_name){
    name = new_name;
}

string Shape::get_color(){
    return color;
}

void Shape::set_color(string new_color){
    color = new_color;
}