/*
File: linkedlist.h

Author: Warren Hammock

Date: 3/9/16

Summary: Interface file for the lklist class.
         Class uses a nodes that are linked to
         create a list.

Files to include: 	hw4.cpp, linkedlist.cpp

*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>


struct node
{
	int value;
	node* next;
	node* prev;
};

class lklist
{
public:

    lklist();
    virtual ~lklist(); //deconstructor
    lklist(const lklist& listOne); //copy constructor
    lklist& operator =(const lklist& listOne); //deep copies one list into another
    int count(); //counts the number of values of list
    bool empty(); //checks to see if list is empty
    void pushFront(const int& newValue);  //pushes value before head pointer node
    void pushBack(const int& newValue);  //pushes value before node
    node* find(const int newValue);    //locates a value
    friend std::ostream& operator <<(std::ostream& outStream, const lklist& listOne); //overloaded operator for output
    void erase(node* toDelete); //deletes value
    void clearList();   //clears all values from the list and leaves head



private:

	node* head;

};

#endif
