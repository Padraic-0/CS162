#include <iostream>
#include "rectangle.h"
using namespace std;
Rectangle::Rectangle(){
    width = 1.00;
    height = 2.00;
    set_name("rectangle");
    set_color("blue");
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

bool operator>(Rectangle &R1,Rectangle &R2){
    if(R1.area()>R2.area()){
        return true;
    }
    else{
        return false;
    }
}

bool operator<(Rectangle &R1,Rectangle &R2){
    if(R1.area()<R2.area()){
        
        return true;
    }
    else{
        
        return false;
    }
}