#include <iostream>
#include "shape.h"
using namespace std;

Shape::Shape(){
    name = "Name";
    color = "Color";

}

void print_shape_info(Shape & shape){
    cout << shape.get_name() << " " << shape.get_color() << " " << shape.area() << endl;
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