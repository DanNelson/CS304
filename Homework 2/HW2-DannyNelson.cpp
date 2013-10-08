// FILE: HW2-DannyNelson.cpp
// CLASS implemented: bag (see bag2.h for documentation)
// Implementation file for the bag class: Used to test the functionality
// of the program.
// File modified by: Danny Nelson 9/18/2013

#include "stdafx.h"
#include "bag2.h"

using namespace cs304_bag;
using namespace std;

//Tests the const overloading of the [] operator
void constArrayOpperatorTest(const bag& source, bag::size_type reciept){
	cout << source[reciept] << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Testing creating a bag
	bag test(3);
	//Testing putting more items in the bag than the bag's size
	cout << test.insert(5) << endl;
	cout << test.insert(6) << endl;
	cout << test.insert(7) << endl;
	cout << test.insert(8) << endl;
	cout << test.insert(9) << endl;
	//Try to resize to a size smaller than allowed
	test.reserve(2);
	//Try removing a size that is allowed
	cout << test.remove(1) << endl;
	//Try removing a size that is not allowed
	try{
		cout << test.remove(100) << endl;
	}
	catch(out_of_range e){cout << e.what();}
	//Insert three more numbers to see if the unused position from remove is filled
	cout << test.insert(7) << endl;
	cout << test.insert(8) << endl;
	cout << test.insert(9) << endl;
	//Begin exception handling checking
	//Test a value that is too large for the non-const overloading of []
	try{
		cout << test[100] << endl;
	}
	catch (out_of_range e){ cout << e.what() << endl;}
	//Test a value for the const overloading of the [] operator 
	try{
		cout << endl;
		constArrayOpperatorTest(test,100);
	}
	catch(out_of_range e){ cout << e.what();}	
	//Create another bag
	bag mybag(2);
	//Test using the assignment operator
	mybag = test;
	//Test using the copy constructor
	bag test3(mybag);
}



