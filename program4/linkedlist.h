/******************************************************
** Program: linkedlist.h
** Author: Padraic Bergin
** Date: 12/5/2021
** Description: Holds all of the function to add values to a linked list, and then sort it in acending or decedning order. The prime numbers of the list can befound. And the list is cleared from memory  
** Input: User input to add values to Nodes
** Output: sorted linked list and prime numbers
******************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
    private:
        unsigned int length;                 // the number of nodes contained in the list
        Node *head;                          // a pointer to the first node in the list

    public:
        Linked_List(); //sets up linked list with lenght of 1 as it holds a head Node, and a NULL head Node
        Linked_List(Node*, int); //not used
        int get_length(); //Returns the length of the list, I mostly used while(->next != NULL instead of a for loop)
        void print();                        // output a list of all integers contained within the list
        void clear();                        // delete the entire list (remove all nodes and reset length to 0)
        unsigned int push_front(int);        // insert a new value at the front of the list (returns the new length of the list)
        unsigned int push_back(int);         // insert a new value at the back of the list (returns the new length of the list)
        unsigned int insert(int,int);        // instert a value at a index position
        void sort_ascending();               //sorts ascending returning a head of each sorted list
        void sort_decending();               //I tried this one(decedning) differntly so that it has no return type, I thought maybe the pointers carry the new head value up the recursion call list
        Node* merge_sort(Node*);    
        void merge_sort_d(Node*);   
        Node* get_head();           //Not used
        Node* merge(Node*,Node*);   //Finds the next smallest value to add as the next value in a list(asending)
        Node* merge_d(Node*,Node*); //Finds the next largest value to add as the next value in a list(decending)
        bool prime(int);    //bool statment to tell if the number is prime
        void call_prime();  //if the prime() returns true then the value is prime and then printed
};

#endif