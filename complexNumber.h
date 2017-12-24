/*
File complexNumber.h
Created 2/8/16
created by: Warren Hammock
use: interface for the complexNumber.cpp file.
files need: implementation is stored in complexNumber.cpp, testing will also need hw3.cpp.
purpose: class that adds, subtracts, and multiplies 2 complex numbers.
*/
#ifndef COMPLEX_NUMBER  //defines file to be read
#define COMPLEX_NUMBER // makes sure the file is only read once, even if the
						// it is referenced mulitple times



class complexNumber{
private:
	double realPart;		//example number 2 + 3i
	double imaginaryPart;

public:
	complexNumber();	//default constructor
	complexNumber(double real);		//declare real number, imag is 0
	complexNumber(double real, double imaginary);
	friend const complexNumber operator -(const complexNumber& number);	//gives negitive value to imaginary part of number
	friend const bool operator ==(const complexNumber& first, const complexNumber& second); //checks equality of 2 objects
	friend const complexNumber operator *(const complexNumber& first, const complexNumber& second); //multiplies complex objects
	friend std::ostream& operator <<(std::ostream& outputStream, const complexNumber& outMessage); //stream output objects
	friend std::istream& operator >>(std::istream& inputStream, complexNumber& inMessage); //stream input objects
	const complexNumber operator +(const complexNumber& otherNumber); //adds two complex objects
	const complexNumber operator -(const complexNumber& otherNumber); //subtracts two complex objects

};




#endif
