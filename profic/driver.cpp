#include <iostream>
#include <iostream>
#include "person.h"
#include "vehicle.h"
using namespace std;
using namespace std;

void printPersonInfo(Person p){
    string name = p.get_name();
    int num_vehicles = p.get_num_vehicles();
    cout << name <<" has " << num_vehicles << " vehicles." << endl;
    cout << "They have these vehicles: ";
    for (int i = 0; i < num_vehicles; i++){
        cout << p.get_vehicle(i).get_type() <<" ";
    }
    cout << endl;
}

int main(){
    cout << "What is the persons name?: ";
    string name;
    cin >> name;
    cout << "How many cars does "<< name << " have?: ";
    int num;
    cin >> num;
    Person p(num,name);
    for (int i = 0; i < num; i++){
        //p.list_vehicles[i] = new Vehicle;
        cout << "What type of vehicle?: ";
        string type;
        cin >> type;
        p.set_list(i,type);
    }
    printPersonInfo(p);


    return 0;
}