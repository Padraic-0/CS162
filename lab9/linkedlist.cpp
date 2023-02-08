//printing
/*
head->[7] -> [8] -> [9]
Node* t1;
t1 = head;
            //head/t1->[7] -> [8] -> [9]
for (int i = 0; i < length(3); i++){
    cout << t1->val;
    t1 = t1->next;
}

while (t1 != NULL)
*/
#include <iostream>
using namespace std;

class Node {
    public:
    int val;             // the value that this node stores
    Node *next;          // a pointer to the next node in the list
};

class Linked_List {
    private:
        unsigned int length;                 // the number of nodes contained in the list
        Node *head;                          // a pointer to the first node in the list

    public:
        Linked_List();
        Linked_List(Node*, int);
        int get_length();
        void print();                        // output a list of all integers contained within the list
        void clear();                        // delete the entire list (remove all nodes and reset length to 0)
        unsigned int push_front(int);        // insert a new value at the front of the list (returns the new length of the list)
        unsigned int push_back(int);         // insert a new value at the back of the list (returns the new length of the list)
        unsigned int insert(int,int);
        void merge_sort(Node*);
        Node* get_head();
        Node* merge(Node*,Node*);
};

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

void Linked_List::merge_sort(Node* head2){

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

        merge_sort(left);
        
        merge_sort(right);
        
        
        //cout <<"merging"<<endl;
        //cout << left->val << " " << right->val << endl;
        head2 = merge(left, right);
        //cout << left->val << " " << right->val << endl;
        

        
        
    }
}

Node* Linked_List::merge(Node* left, Node* right){
    
    if (left == NULL){
        //cout << "returning end " << right->val <<endl;
        return right;
    }

    else if (right == NULL){
        //cout << "returning end " << left->val <<endl;
        return left;
    }
    Node* temp;
    if (left->val < right->val){
        temp = left;

        left->next = merge(temp->next, right);
        //cout << "connecting " << left->val << " to " << left->next->val<< endl;

        
        
        
        
    }

    else{
        temp = right;
        temp->next = merge(left, right->next);

        
        //cout << "connecting " << right->val << " to " << right->next->val <<  endl;

        

    }

    return temp;








}

Node* Linked_List::get_head(){
    return head;
}

int main(){
    Linked_List l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(6);  
    l1.push_back(5);
    //l1.push_back(3);
    //l1.push_back(10);
    
    //l1.push_back(6);
    //l1.push_back(7);
    //l1.push_back(8);

    //l1.push_front(1);
    //l1.insert(4,4);
    //l1.print();
    l1.merge_sort(l1.get_head());
    l1.print();
    //l1.clear();
    return 0;
}