/*
File: linkedlist.h

Author: Warren Hammock

Date: 3/9/16

Summary: Definitions to functions for
         the lklist class.  Class links
         nodes together to create a list.

Files to include: 	hw4.cpp, linkedlist.h

*/

#include "linkedlist.h"


//default constructor
lklist::lklist()
{
    head = new node;
    head->prev = head;
    head->next = head;


}

//--------------------------

//copy constructor
lklist::lklist(const lklist& listIn)
{
    head = new node;
    head->prev = head;
    head->next = head;

    node* temp = listIn.head;
    while (temp->next != listIn.head)
    {
        temp = temp->next;
        pushBack(temp->value);

    }

}

//--------------------------
//deconstructor

lklist::~lklist()
{

    while (head->next != head)
    {
        erase(head->next);

    }
    delete head;

}

//--------------------------
//returns the number of values in the list
int lklist::count()
{
    node* temp;
    temp = head;
    int counter =  0;
    while (temp->next != head)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}


//--------------------------

//checks if the list is empty
bool lklist::empty()
{

    return (head->next == head);

}

//--------------------------

//places value and node after head
void lklist::pushFront(const int& newValue)
{
	node* nextNode;
	nextNode = new node;
	nextNode->value = newValue;
	nextNode->prev = head;
	nextNode->next = head->next;
	head->next->prev = nextNode;
	head->next = nextNode;

}

//--------------------------

//places new value and node before head
void lklist::pushBack(const int& newValue)
{
	node* nextNode;
	nextNode = new node;
	nextNode->value = newValue;
	nextNode->prev = head->prev;
	nextNode->next = head;
	head->prev->next = nextNode;
	head->prev = nextNode;

}
//--------------------------

//find the position of node by its value
node* lklist::find(const int valueToFind)
{
    node* temp;
    temp = head;
    while (temp->value != valueToFind && temp->next != head)
    {
        temp = temp->next;
    }
    return temp;
}

//--------------------------

//takes in a node and deletes it

void lklist::erase(node* toDelete)
{
    toDelete->next->prev = toDelete->prev;
    toDelete->prev->next = toDelete->next;
    delete toDelete;
}



//--------------------------
//deep copies one list into another
lklist& lklist::operator =(const lklist& listOne)
{
    if (head == listOne.head)
	{
		head = new node;
	}
	if(head->next != head)
    {
        clearList();
    }
    node* temp = listOne.head;
    while (temp->next != listOne.head)
    {
        temp = temp->next;
        pushBack(temp->value);

    }
    return *this;

}

//--------------------------

//overloaded operator for display
std::ostream& operator <<(std::ostream& outStream, const lklist& listOne)
{
    node* temp = listOne.head;
    while(temp->next != listOne.head)
 {
  outStream << temp->next->value << " ";
  temp = temp -> next;
 }
 return outStream;
}

//--------------------------
//clears all values from list

void lklist::clearList()
{

    while (head->next != head)
    {
        node* temp = head->next;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
}




