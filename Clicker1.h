/*
Program to simulate an old fashioned counter.  User has the ability to add to a number with 2 place holders for dollars and 2 place holders for cents.  The amount can only reach $ 99.99.  Any additional amount added will default to a reset and start at $ 00.00.  User will enter a loop to increase the amount by 1, 10, 100, or 1000.  The user can also reset the number by forcing the counter to its max.  User can exit.
*/

class Clicker{

//each object of class will have 4 variables to be place holders for each number
//in the 4 digit amount
private:
	
	int c_ones;		//represents ones in cents amount
	int c_tens;		//tens in cents amount
	int d_ones;		//ones in dollars amount
	int d_tens;		//tens in dollar amount
		
	
public:
	//overloaded constructors are for testing.  Real device would not start with 
	//predefined objects, they would start as default and be added to
	Clicker(int first, int second, int third, int fourth);
	Clicker(int first, int second, int third);
	Clicker(int first, int second);
	Clicker(int first);
	Clicker();//default constructor
	void choiceInstructions(); //choice instructions for while loop a,s,d,f,o,e
	void getAmount();		//returns amount
	void reset();		//resets amount
	void incr1();			//adds one cent
	void incr10();		//adds ten cents
	void incr100();		//adds one dollar
	void incr1000();		//adds ten dollars
	void overFlow();			//has added to 99.99, error flag thrown

};