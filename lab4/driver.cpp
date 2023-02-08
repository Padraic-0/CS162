#include <iostream>
#include "./shape.h"
#include "./circle.h"
#include "./rectangle.h"
#include "./square.h"
using namespace std;

int main(){
    Circle c;
    Rectangle r;
    r.set_height(4);
    r.set_width(8);

    cout << r.area();

    Square s(4.);
    cout << s.area();
    

    
    
    return 0;
}