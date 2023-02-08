#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   vector<int> v2;
   std::vector<int> stdv; //Standard vector
   

   //Compare operation of our vector to std
   //v.push_back(23);
   //v2.push_back(25);
   //stdv.push_back(24);
   //v.push_back(24);
   stdv.reserve(100);

   //cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   //v=v2;
   //cout << v2.at(0) << endl;

   return 0;
}