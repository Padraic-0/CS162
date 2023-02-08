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
        virtual float area()=0;
        

        string get_name();
        void set_name(string);

        string get_color();
        void set_color(string);
};

void print_shape_info(Shape &);


#endif