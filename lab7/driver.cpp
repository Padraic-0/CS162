#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib> 
using namespace std;
bool prime(int number){
    bool possible_prime;
    for (int i = 2; i < number; i++){
        
        if ((number % i) >= 1){
            possible_prime = true;
        }
        if ((number % i) == 0){
            possible_prime = false;
            return possible_prime;
            break;
        }

    }
    return possible_prime;
}

int main() {
    int length;
    bool valid = true;
    cout << (4%3);
    while (valid == true){
        cout <<"Size of list";
        cin >> length;
        if (length > 0){
            valid = false;
        }
        else {
            valid = true;
        }
    }
    
    int* list = new int [length];
    int* list_sorted = new int [length];
    srand(time(0));
    for (int i = 0; i < length; i++){
        int num = (rand() % 100 + 1);
        list[i] = num;
    }
    for (int i = 0; i < length; i++){
        list_sorted[i] = list[i];
    }
    for (int i = 0; i < length; i++){
        cout << list[i]<<endl;
    }

    for (int i = 0; i < length; i++){
        int smallest = i;
        for (int j = i; j < length; j++){
            if (list_sorted[j] < list_sorted[smallest]){
                smallest = j;
            }
            }   
        int temp = list_sorted[i];
        list_sorted[i] = list_sorted[smallest];
        list_sorted[smallest] = temp;
    }

    


    
    cout<<"This is the list"<<endl;
    for (int i = 0; i < length; i++){
        cout << list_sorted[i]<<endl;
    }
    cout<<"This is the sorted list"<<endl;

    for(int i = 0; i < length; i++){
        if(prime(list_sorted[i])== true){
            cout << list_sorted[i] << ",";
        }
        if (i == (length-1)){
            cout << " are prime numbers"<< endl;
        }
    }


    return 0;
}