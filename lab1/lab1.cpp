#include <iostream>
#include <stdlib.h> //Used for atoi
//hawkinma@oregonstate.edu

using namespace std;

void mean_num(int *list_numbers, int n){
    int mean;
    int total = 0;
    for (int i = 0; i < n; i++){
        total = total + list_numbers[i];
    }
    cout << "The mean is " << total / n << endl;
}

void smallest_num(int *list_numbers, int n){
    int smallest_number;
    smallest_number = list_numbers[0];
    for (int i=1; i < n; i++){
        if (smallest_number > list_numbers[i]){
            smallest_number = list_numbers[i];
        }
        else{
            smallest_number = smallest_number;
        }
        
    }
    cout << "The smallest number is: " << smallest_number << endl;
}

void biggest_num(int *list_numbers, int n){
    int biggest_number;
    biggest_number = list_numbers[0];
    for (int i=1; i < n; i++){
        if (biggest_number < list_numbers[i]){
            biggest_number = list_numbers[i];
        }
        }
        
    
    cout << "The biggest number is: " << biggest_number << endl;
    }

int* array_builder(int n){
    int *list_numbers = new int[n];
    for (int i=0; i < n; i++){
        int user_num;
        cin >> user_num;
        if (user_num > 0){
            list_numbers[i] = user_num;
        }
        else {
            cout << "Inputed value is too small" << endl;
            i--;
        }
        
    }


    return list_numbers;
}

int array_size(int size){
    int n = size;
    while (n==0){
        cout << "Input valid number" << endl;
        cin >> n;
    }
    
    return n;
}

int main(int argc, char *argv[]){
    int n;
    n=atoi(argv[1]);
    n=array_size(n);
    int *list_numbers = array_builder(n);
    //looking for biggest number
    /*int biggest_number;
    biggest_number = list_numbers[0];
    for (int i=1; i < n; i++){
        if (biggest_number < list_numbers[i]){
            biggest_number = list_numbers[i];
        }
        else{
            biggest_number = biggest_number;
        }
        
    }
    cout << biggest_number; */
    biggest_num(list_numbers,n);
    smallest_num(list_numbers,n);
    mean_num(list_numbers,n);
   

    delete[] list_numbers;
    return 0;
}