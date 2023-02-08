#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "shape.h"
using namespace std;

class Rectangle: public Shape{
private:
      float width;
      float height;
   public:
      Rectangle();
      float area();

      float get_width();
      void set_width(float);

      float get_height();
      void set_height(float);
      


};

      bool operator> (Rectangle &,Rectangle &);
      bool operator< (Rectangle &,Rectangle &);


#endif