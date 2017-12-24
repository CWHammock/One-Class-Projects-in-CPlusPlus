/* CS 519 - Spring 2016, Dr. Liu
Warren Hammock
Homework 2

*/


#include<iostream>
#include"Clicker1.h"

using namespace std;

int main(){
	char choice;
	Clicker counterMax(9, 9, 9, 9);
	counterMax.getAmount();
	counterMax.incr1();
	counterMax.getAmount();
	Clicker counter0;
	counter0.getAmount();
	counter0.incr1();
	counter0.getAmount();
	counter0.incr10();
	counter0.getAmount();
	counter0.choiceInstructions();
	cin >> choice;
	while (choice != 'e')
	{
		switch(choice)
		{
			case 'a': 
				counter0.getAmount();
				counter0.incr1();
				counter0.getAmount();
				break;
			
			case 's':
				counter0.getAmount();
				counter0.incr10();
				counter0.getAmount();
				break;
				
			
			case 'd':
				counter0.getAmount();
				counter0.incr100();
				counter0.getAmount();
				break;
			
			case 'f':
				counter0.getAmount();
				counter0.incr1000();
				counter0.getAmount();
				break;
			
			case 'o':
				counter0.overFlow();
				break;
				
			default:
				cout << "unknown letter selection." << endl;
			
		}
		counter0.choiceInstructions();
		cin >> choice;
	}
}