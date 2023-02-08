#include <iostream>
#include "circle.h"
using namespace std;
Circle::Circle(){
    radius = 1.00;
}

float Circle::area(){
    float pi = 3.14;
    float area_circle = pi * radius * radius;
    return area_circle;
}

float Circle::get_radius(){
    return radius;
}

void Circle::set_radius(float new_radius){
    radius = new_radius;
}