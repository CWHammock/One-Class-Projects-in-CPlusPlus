#include<iostream>
#include"Clicker1.h"

using namespace std;

Clicker::Clicker():c_ones(0), c_tens(0), d_ones(0), d_tens(0)
{}

Clicker::Clicker(int first):c_ones(first), c_tens(0), d_ones(0), d_tens(0)
{}

Clicker::Clicker(int first, int second):c_ones(first), c_tens(second), d_ones(0), d_tens(0)
{}

Clicker::Clicker(int first, int second, int third):c_ones(first), c_tens(second), d_ones(third), d_tens(0)
{}

Clicker::Clicker(int first, int second, int third, int fourth):c_ones(first), c_tens(second), d_ones(third), d_tens(fourth)
{}

void Clicker::choiceInstructions()
{
	cout << "Let me know what you want to do: press 'a' to add one.  press 's' to add 10. \n" <<  "press 'd' to add 100.  press 'f' to add 1000.  press 'o' for overflow.  press 'e' to exit. \n";
}


void Clicker::getAmount()
{
	cout << "$ " <<  d_tens << d_ones << "." << c_tens << c_ones << endl;
}

void Clicker::overFlow()
{
	cout << "You have reach the max.  I will reset now" << endl;
	reset();
}


void Clicker::reset()
{
	c_ones = 0;
	c_tens = 0;
	d_ones = 0;
	d_tens = 0;
}

void Clicker::incr1()
{
	if (c_ones == 9)
	{
		c_ones = 0;
		incr10();
	}
	else
	{	
		c_ones = c_ones + 1;
	}	
}

void Clicker::incr10()
{
	if (c_tens == 9)
	{
		c_tens = 0;
		incr100();
	}
	else
	{
		c_tens = c_tens + 1;
	}
}

void Clicker::incr100()
{
	if (d_ones == 9)
	{
		d_ones = 0;
		incr1000();
	}
	else
	{
		d_ones = d_ones + 1;
	}
}

void Clicker::incr1000()
{
	if (d_tens == 9)
	{
		overFlow();
		reset();
	}
	else
	{
		d_tens = d_tens + 1;
	}
}