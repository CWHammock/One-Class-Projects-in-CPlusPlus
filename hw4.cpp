/*--------------------------------------------------------------------------------------------------------
	File:	hw4.cpp

	Author:	Warren Hammock

	Date:	3/2/2016

	Summary: 	Driver file for class lklist in linkedlist.h and linkedlist.cpp.  Class implements a list object
				comprised of a string on nodes. The nodes are connected from forward and back.  The list
				is established by a head pointer.

	Files to include: 	linkedlist.h, linkedlist.cpp

---------------------------------------------------------------------------------------------------------*/
//usec 10000
//sec 10000000
#include "linkedlist.h"


int main()
{
    lklist oneList;
    //check if the list is empty
    if (oneList.empty())
    {
        std::cout << "list is empty" << std::endl;
    }
    //push 4 new values into the object in front of the head
    oneList.pushFront(35);
    oneList.pushFront(36);
    oneList.pushFront(37);
    oneList.pushFront(38);
    std::cout << oneList << std::endl;
    //push 3 new values behind the head
    oneList.pushBack(44);
    oneList.pushBack(46);
    oneList.pushBack(54);
//    lnList.swap(lnList.find(36), lnList.find(37));
    std::cout << oneList << std::endl;
    //create a second list with copy constructor
    lklist secList(oneList);
    //print second list
    std::cout << secList << std::endl;
    //test count function to return the number of numbers on list
    std::cout << "The number of numbers in list are: " << oneList.count() << std::endl;
    //show lnList before erasing node with a value of 36
    std::cout << oneList << std::endl;
    oneList.erase(oneList.find(36));
    //show list after erasing node with value of 36
    std::cout << oneList << std::endl;
    //create a third linked list
    lklist thirList;
    //copy contents of lnList into new list
    thirList = oneList;
    //display new list to see it has same members as lnList
    thirList.pushBack(23);
    std::cout << thirList << std::endl;
    //clear list
    oneList.clearList();
    //show the list is clear
    std::cout << oneList << std::endl;
    oneList.pushFront(55);
    oneList.pushBack(88);
    std::cout << oneList << std::endl;




	return 0;

}
