/******************************************************
** Program: linkedlist.cpp
** Author: Padraic Bergin
** Date: 12/5/2021
** Description: Holds all of the function to add values to a linked list, and then sort it in acending or decedning order. The prime numbers of the list can befound. And the list is cleared from memory 
** Input: User input to add values to Nodes
** Output: sorted linked list and prime numbers
******************************************************/

#include "node.h"
#include "linkedlist.h"
#include <iostream>

using namespace std;


Linked_List::Linked_List(){
    head = NULL;
    length = 1;

}

Linked_List::Linked_List(Node* head2, int length2){
    head = head2;
    length = length2;

}

int Linked_List::get_length(){
    return length;

}

void Linked_List::print(){
    Node* t1;
    t1 = head;
    while (t1 != NULL){
        cout << t1->val << endl;
        t1 = t1->next;
        
    }
    if (t1 == NULL){
        return;

    }
}

void Linked_List::clear(){
    Node* t1;
    Node* t2;
    t1 = head;
    while (t1 != NULL){
        t2 = t1;
        t1 = t1->next;
        delete t2;
    }
    head = NULL;
    length = 0;

}

unsigned int Linked_List::push_back(int value){
    Node* n1 = new Node;
    n1->next = NULL;
    n1->val = value;
    
    if (head == NULL){
        head = n1;
        return (length += 1);
    }
    
    if (head != NULL){
        Node* t1;
        t1 = head;
        while (t1->next != NULL){
            t1 = t1->next;
        }
        t1->next = n1;
    
        return (length += 1);
    }
    


}

unsigned int Linked_List::push_front(int value){
    Node* n1 = new Node;
    n1->next = NULL;
    n1->val = value;
    Node* t1;
    t1 = head;
    head = n1;
    n1->next = t1;
    
}

unsigned int Linked_List::insert(int value, int index){
    if (head==NULL){
        cout <<"Cant insert" << endl;
        return length;
    }
    Node* n1 = new Node;
    n1->val = value;
    Node* t1;
    t1 = head;
    for (int i = 0; i < (index - 2) ; i++){
        t1 = t1->next;
    }
    n1->next = t1->next;
    t1->next = n1;
    return length += 1;

}

void Linked_List::sort_ascending(){
    merge_sort(head);
}

void Linked_List::sort_decending(){
    merge_sort_d(head);
}



Node* Linked_List::merge_sort(Node* head2){

    if (head2 == NULL || head2->next == NULL){ //If the Node passed in is a single Node then it doesnt need to be split

        return head2;
    }
    else {
        Node* left = head2;
        Node* right = head2;

        while (right->next != NULL){ //runs through the list until the left->next is NULL, the left node will be in the middle because its half way behind the right node 
            right = right->next;       
            
            if (right->next != NULL){
                left = left->next;
                right = right->next;
                
            }
            
        
        }
        
        right = left->next; // The right node is then moved back to the middle and the left node now make that nodes ->next = NULL spliting the list in two and returning the the head of the list
        left->next = NULL;
        left = head2;
        Node* t1;
        Node* t2;
        t1 = merge_sort(left);
        
        t2 = merge_sort(right);
        
        
        //cout <<"merging"<<endl;
        //cout << left->val << " " << right->val << endl;
        head2 = merge(t1, t2); // this will combine two lists together into one with a head* = head2
                                // I take t1 which returns from the merge_sort(left), so once the left spliting reaches a single Node then the Node is returned
                                // after which the merge_sort(right) is called and returns the same Node. Once two Nodes merge they return a head that = the first Node in that sorted
                                // list. Head2 is equal to this Node and is returned up the recursion order, each time the list gets larger and compared to the list next to it.
        return head2;
        
        
        //cout << left->val << " " << right->val << endl;
        

        
        
    }
}



void Linked_List::merge_sort_d(Node* head2){

    if (head2 == NULL || head2->next == NULL){

        return;
    }
    else {
        Node* left = head2;
        Node* right = head2;

        while (right->next != NULL){
            right = right->next;
            
            if (right->next != NULL){
                left = left->next;
                right = right->next; 
            }
        }
        
        right = left->next;
        left->next = NULL;
        left = head2;

        merge_sort_d(left);
        merge_sort_d(right);
        //cout <<"merging"<<endl;
        //cout << left->val << " " << right->val << endl;
        head2 = merge_d(left, right);
        //cout << left->val << " " << right->val << endl;
    }
}


Node* Linked_List::merge(Node* left, Node* right){
    
    if (left == NULL){ //when the temp->next node is passed into the merge function, if it is NULL because that Node is at the end of the list then it must be the next value in the ordered list
        //cout << "returning end " << right->val <<endl;
        return right; // the opposite is returned because it will be the smaller number
    }

    else if (right == NULL){
        //cout << "returning end " << left->val <<endl;
        return left;
    }
    Node* temp;
    if (left->val < right->val){
        temp = left;
        left->next = merge(temp->next, right); // recursivly calls the merge function, with the next value in the smaller Nodes list until one of top two if statements is satified. 
                                                // once this if statement finsished it returns the temp value which which then be the ordered list, the previously called recusion then uses this value as the ->next
        //cout << "connecting " << left->val << " to " << left->next->val<< endl;
  
    }
    else{
        temp = right;
        temp->next = merge(left, right->next);
        //cout << "connecting " << right->val << " to " << right->next->val <<  endl;
    }
    return temp;
}


Node* Linked_List::merge_d(Node* left, Node* right){
    
    if (left == NULL){
        return right;
    }

    else if (right == NULL){
        return left;
    }
    Node* temp;
    if (left->val < right->val){
        temp = right;
        right->next = merge_d(left, temp->next);
    }

    else{
        temp = left;
        temp->next = merge_d(left->next, right);
    }
    return temp;
}

Node* Linked_List::get_head(){
    return head;
}


bool Linked_List::prime(int number){
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

void Linked_List::call_prime(){
    Node* temp = head;
    while (temp->next != NULL){
        if (prime(temp->val)){
            cout << temp->val << " is a prime number" << endl;
        }
        temp = temp->next;
    }
}