#include <iostream>
#include "node.h"
#include "linkedlist.h"
using namespace std;

int main(){
    bool program = true;
    while (program) {
        Linked_List l1;
        bool run = true;
        string choice;
        while (run){
            int value;
            int adding;
            cout << "Push back, front, or insert? (1/2/3): ";
            cin >> adding;
            cout << "Please enter a number: ";
            cin >> value;
            if (adding == 1){
                l1.push_back(value);
            }
            if (adding == 2){
                l1.push_front(value);
            }
            if (adding == 3){
                int position;
                cout << "Insert at what index? : ";
                cin >> position;
                l1.insert(value,position);
            }
            cout << "Would you like to add another number (y/n): ";
            cin >> choice;
            if (choice == "n"){
                run = false;
            }
        }

        l1.print();
        cout << "Sort ascending or descending (a or d)? ";
        cin >> choice;
        if (choice == "a"){

            l1.sort_ascending();
        }

        if (choice == "d"){
            l1.sort_decending();
        }


        //l1.push_front(1);
        //l1.insert(4,4);
        //l1.print();
        //l1.merge_sort(l1.get_head());
        l1.print();
        l1.call_prime();
        l1.clear();
        cout << "Again? (y/n) ";
        string again;
        cin >> again;
        if (again == "n"){
            program = false;
        }
        
    }
    return 0;
}