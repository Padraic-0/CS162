#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape{
    private:
        string name;
        string color;
    public:
        Shape();
        float area();

        string get_name();
        void set_name(string);

        string get_color();
        void set_color(string);
};



#endif