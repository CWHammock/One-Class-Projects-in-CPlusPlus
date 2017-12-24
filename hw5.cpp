/*
File: linkedlist.h

Author: Warren Hammock

Date: 3/9/16

Summary: Driver file for the lklist class.
         Used to test the functionality of
         of the class.  FOR TESTING ONLY.

Files to include: 	linkedlist.cpp, linkedlist.h

*/

#include "linkedlist.h"

int main()
{
   //create an lklist object
   lklist listOne;
   //populate listOne with 10 numbers
   srand(time(0));
   for (int i = 0;i < 10; i++)
   {
      listOne.pushFront(rand()%99+1);
   }
   std::cout << listOne << std::endl;
   //create an empty new lklist object
   lklist listTwo;
   //add one number to listTwo
   listTwo.pushFront(13);
   //show listTwo
   std::cout << listTwo << std::endl;
   //replace contents of the listTwo with listOne;
   listTwo = listOne;
   //show contents of listTwo
   std::cout << listTwo << std::endl;
   //clear listTwo
   listTwo.clearList();
   //populate with 10 random numbers
   for (int i = 0;i < 10; i++)
   {
      listTwo.pushFront(rand()%99+1);
   }
   //show listTwo
   std::cout << listTwo << std::endl;
   //use copy constructor with listTwo
   lklist listThr(listTwo);
   //show contents of listThr
   std::cout << listThr << std::endl;

}
