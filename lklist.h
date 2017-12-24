
#ifndef LKLIST_H
#define LKLIST_H

//============================================================================
// Name        : lklist.h
// Author      : Warren Hammock
// Date        : April 2, 2016
// Description : Create a template class for a linked list and an iterator
//               for the list.  Only driver needed to utilize the linked
//               list and iterator.
//============================================================================


template<class T>
struct node
{
	T value;
	node* next;
	node* prev;
};

template<class T>
class lklist
{
public:
    friend class iterator;
      class iterator
        {
      public:
      friend class lklist<T>;
      //move iterator forward by one then evaluate
      iterator& operator ++() {loc = loc -> next; return *this;}
      //move iterator back by one then evaluate
      iterator& operator --() {loc = loc -> prev; return *this;}
      //evaluate and move iterator forward by one
      iterator operator ++(int junk) {iterator temp = *this; loc = loc -> next; return temp;}
      //evaluate and move iterator back by one
      iterator operator --(int junk) {iterator temp = *this; loc = loc -> prev; return temp;}
      //compares two iterators to determine if they are pointing to same
      bool operator == (const iterator rhs) {return (loc == rhs.loc);}
      //compares two iterators to determine if they are not pointing to same point
      bool operator != (const iterator rhs) {return (loc != rhs.loc);}
      //outputs display of value the iterator is pointing to
      const T& operator *() const {return loc -> value;}
      private:
      node<T> * loc;
      iterator(node<T> * l) {loc = l;}
};
    lklist();
    virtual ~lklist(); //deconstructor
    lklist(const lklist<T>& listOne); //copy constructor
    lklist<T>& operator =(const lklist<T>& listOne); //deep copies one list into another
    const int size(iterator first, iterator last); //counts the number of values of list
    bool empty(); //checks to see if list is empty
    void push_front(const T& newValue);  //pushes value before head pointer node
    void push_back(const T& newValue);  //pushes value before node
    void pop_front();
    void pop_back();
    iterator find(iterator first, iterator last, const T& newValue);    //locates a value
    void clearList();  //clears all values from the list and leaves head
    void itr_swap(iterator left, iterator right);
    iterator begin(){return (iterator(head->next));}
    iterator end(){return (iterator(head));}


private:
	node<T>* head;
};

//default constructor
template<class T>
lklist<T>::lklist()
{
    head = new node<T>;
    head->prev = head;
    head->next = head;
}
//--------------------------
//copy constructor
template<class T>
lklist<T>::lklist(const lklist<T>& listIn){

    head = new node<T>;
    head->prev = head;
    head->next = head;
    node<T>* temp = listIn.head;
    while (temp->next != listIn.head){

        temp = temp->next;
        pushBack(temp->value);
    }
}
//--------------------------
//deconstruct
template<class T>
lklist<T>::~lklist(){
    while (head->next != head){
    node<T>* toDelete = head->next;
    toDelete->next->prev = toDelete->prev;
    toDelete->prev->next = toDelete->next;
    delete toDelete;
    }
    delete head;
}
//--------------------------
//remove node from position head + 1
template<class T>
void lklist<T>::pop_front(){
    node<T>* toDelete = head->next;
    toDelete->next->prev = toDelete->prev;
    toDelete->prev->next = toDelete->next;
    delete toDelete;
}
//--------------------------
//remove node from position head - 1
template<class T>
void lklist<T>::pop_back(){
    node<T>* toDelete = head->prev;
    toDelete->next->prev = toDelete->prev;
    toDelete->prev->next = toDelete->next;
    delete toDelete;
}

//--------------------------
//returns the number of values in the list
template<class T>
const int lklist<T>::size(iterator first, iterator last){
    int count = 0;
    while (first != last){count++, first++;}
    return count;

}
//--------------------------
//swaps the values of two iterators
template<class T>
    void lklist<T>::itr_swap(iterator left, iterator right){
    iterator temp = left;
    *left = *right;
    *right = *temp;

}

//--------------------------
//checks if the list is empty
template<class T>
bool lklist<T>::empty(){
    return (head->next == head);
}
//--------------------------
//places value and node after head
template<class T>
void lklist<T>::push_front(const T& newValue){
	node<T>* nextNode;
	nextNode = new node<T>;
	nextNode->value = newValue;
	nextNode->prev = head;
	nextNode->next = head->next;
	head->next->prev = nextNode;
	head->next = nextNode;
}
//--------------------------
//places new value and node before head
template<class T>
void lklist<T>::push_back(const T& newValue){
	node<T>* nextNode;
	nextNode = new node<T>;
	nextNode->value = newValue;
	nextNode->prev = head->prev;
	nextNode->next = head;
	head->prev->next = nextNode;
	head->prev = nextNode;
}
//--------------------------
//find the position of node by its value
template<class T>
typename lklist<T>::iterator lklist<T>::find(iterator first, iterator last, const T& valueToFind){
    while (first != last)
    {
        if (*first == valueToFind) return first;
        ++first;
    }
    return last;
}

//--------------------------
//deep copies one list into another
template<class T>
lklist<T>& lklist<T>::operator =(const lklist<T>& listOne){
    if (this == listOne){
        return;
    }
    clearList();
    node<T>* temp = listOne.head;
    while (temp->next != listOne.head){
        temp = temp->next;
        pushBack(temp->value);
    }
    return *this;
}

//--------------------------
//clears all values from list
template<class T>
void lklist<T>::clearList(){
    while (head->next != head){
        node<T>* temp = head->next;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
}


#endif
