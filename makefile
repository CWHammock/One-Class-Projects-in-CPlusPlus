complexNumber.o: complexNumber.h complexNumber.cpp
		g++ -c -Wall complexNumber.cpp
hw3.o: hw3.cpp complexNumber.h
		g++ -c -Wall hw3.cpp
hw3: hw3.o complexNumbers.o
		g++ -o -Wall hw3 hw3.o complexNumber.o
