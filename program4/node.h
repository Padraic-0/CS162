/******************************************************
** Program: node.h
** Author: Padraic Bergin
** Date: 12/5/2021
** Description: A node with a value and a pointer to another Node
** Input: value, next*
** Output: value, next*
******************************************************/
#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
    public:
    int val;             // the value that this node stores
    Node *next;          // a pointer to the next node in the list
};

#endif