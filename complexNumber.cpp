/*
File complexNumber.cpp
Created 2/8/16
created by: Warren Hammock
use: implementation file for complexNumber.h.
files need: complexNumber.h implement with another class and hw3.cpp for testing
purpose: class that adds, subtracts, and multiplies 2 complex numbers.
*/
#include <iostream>
#include <cstdlib>
#include "complexNumber.h"


const complexNumber i(0, 1);
complexNumber::complexNumber():realPart(0.0), imaginaryPart(0.0){} //default constructor
complexNumber::complexNumber(double real):realPart(real), imaginaryPart(0.0){}
complexNumber::complexNumber(double real, double imaginary):realPart(real), imaginaryPart(imaginary){}
// overloads - operator to change an object with a positive real and imaginary
// part to have a postive real and negitive imaginary part
const complexNumber operator -(const complexNumber& number)
{
	return complexNumber(number.realPart, -number.imaginaryPart);
}
// overload output stream for complex objects to detail real and imaginary
// numbers
std::ostream& operator <<(std::ostream& outputStream, const complexNumber& outMessage)
{
	outputStream << outMessage.realPart << " + " << outMessage.imaginaryPart <<
		"i";
	return outputStream;

}
// overloads input stream for input of real and imaginary parts to be input
// from external source
std::istream& operator >>(std::istream& inputStream, complexNumber& inMessage)
{
	inputStream >> inMessage.realPart >> inMessage.imaginaryPart;
	return inputStream;
}
// mulitplies two complexNumber objects, will state if they are they are
// equal objects. uses return constructor to do calculations.
//Stopped at multiplication, the instructions did not say add a divide function
const complexNumber operator *(const complexNumber& first, const complexNumber& second)
{
	if (first == second)
	{
		std::cout << "the numbers are the same \n";
		return complexNumber((first.realPart*second.realPart - first.imaginaryPart*second.imaginaryPart),
			(first.realPart*second.imaginaryPart) + (first.imaginaryPart*second.realPart));
	}
	else
	return complexNumber((first.realPart*second.realPart - first.imaginaryPart*second.imaginaryPart),
		(first.realPart*second.imaginaryPart) + (first.imaginaryPart*second.realPart));
}
// adds two complexNumber objects
// showing how to return an object by creating a new on locally, versus
// returning a constructor
const complexNumber complexNumber::operator +(const complexNumber& otherNumber)
{
	complexNumber temp;
	temp.realPart = realPart + otherNumber.realPart;
	temp.imaginaryPart = imaginaryPart + otherNumber.imaginaryPart;
	return temp;
}
// subtracts two complexNumber objects
const complexNumber complexNumber::operator -(const complexNumber& otherNumber)
{
	return complexNumber(realPart-otherNumber.realPart, imaginaryPart-otherNumber.imaginaryPart);
}
// evaluates two complexNumber object to see if they hold the same value
const bool operator ==(const complexNumber& first, const complexNumber& second)
{
    return ((first.realPart == second.realPart) &&
        (first.imaginaryPart == second.imaginaryPart));
}
