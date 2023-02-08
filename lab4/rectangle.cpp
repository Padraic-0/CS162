#include <iostream>
#include "rectangle.h"
using namespace std;
Rectangle::Rectangle(){
    width = 1.00;
    height = 2.00;
}

float Rectangle::area(){
    float area_rectangle = width * height;
    return area_rectangle;
}

float Rectangle::get_width(){
    return width;
}

void Rectangle::set_width(float new_width){
    width = new_width;
}

float Rectangle::get_height(){
    return height;
}

void Rectangle::set_height(float new_height){
    height = new_height;
}
