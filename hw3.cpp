/*
File hw3.cpp
Created 2/8/16
created by: Warren Hammock
use: test the implementation of the complexNumber.cpp and complexNumber.h.
files need: complexNumber.cpp and complexNumber.h
purpose: tests a class that adds, subtracts, and multiplies 2 complex numbers.
*/
#include<iostream>
#include"complexNumber.h"




int main(){

    complexNumber num1, num2(1.1), num3(2.2, 3.3), userNum, sum, minus, times, equalAmount1(2.2, 3.3), equalAmount2 (2.2, 3.3);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl; //shows 3 diff types of constructors
    std::cout << "Enter a complex number, first real number then imaginary number: \n";
    std::cin >> userNum; //gets user complex object
    std::cout << userNum << std::endl;
    sum = num3 + userNum;   //adds two complex objects
    std::cout << sum << std::endl; //output sum of addition
    minus = num3 - userNum; //subtracts two complex objects
    std::cout << minus << std::endl; //output subtraction result
    times = num3 * userNum;     //multiply 2 complex objects
    std::cout << times << std::endl;    //output muliplication result
    return 0;

}
