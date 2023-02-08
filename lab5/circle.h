#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "shape.h"
using namespace std;
class Circle: public Shape{
private:
      float radius;
   public:
      Circle();
      float area();

      float get_radius();
      void set_radius(float);

};




#endif