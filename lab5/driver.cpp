#include <iostream>
#include "./shape.h"
#include "./circle.h"
#include "./rectangle.h"
#include "./square.h"
using namespace std;

int main(){
    Circle c;
    Rectangle r;
    Rectangle r2;
    r.set_height(5);
    r.set_width(8);
    r2.set_height(4);
    r2.set_width(8);
    c.set_radius(8);
    cout << c.area()<<endl;

    cout << r.area()<<endl;

    Square s(4.);
    cout << s.area()<<endl;
    if (r>r2){
        cout<< "bigger"<< endl;
    }
    print_shape_info(r);
    
    

    
    
    return 0;
}