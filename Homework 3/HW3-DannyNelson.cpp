// FILE: HW2-DannyNelson.cpp
// CLASS implemented: bag (see bag2.h for documentation)
// DATE: 10/04/13
// Implementation file for the bag class with iterators: Used to test the functionality
// of the program.
// File modified by: Danny Nelson 10/7/13

#include "stdafx.h"
#include "bag.h"

using namespace cs304_bag;
using namespace std;

//Tests the const overloading of the [] operator
template <class Item>
void constArrayOpperatorTest(const bag<Item>& source, typename bag<Item>::size_type reciept){
	cout << source[reciept] << endl;
}

//Creates a const bag to test the const iterator
template <class Item> 
const bag<Item> constConverter(const bag<Item>& source){
	return source;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//Testing creating a bag
	bag<int> test(3);
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
	bag<int> mybag(2);
	//Test using the assignment operator
	mybag = test;
	//Test using the copy constructor
	bag<int> test3(mybag);
	
	//Create a new bag for testing the iterators
	bag<int> testBag(4);
	testBag.insert(1);
	testBag.insert(2);
	testBag.insert(3);
	testBag.insert(4);

	//////////////////Postfix Test////////////////////////

	//Start the bag iteration
	bag<int>::iterator it = testBag.begin();
	
	//Print all the items in the bag in forward order
	for(it = testBag.begin(); it != testBag.end(); it++){
		cout << *it << endl;
	}

	//Restart bag iteration
	it = testBag.begin();
	//Increment the iterator to test the -- operator
	++it;
	++it;
	++it;
	
	//Print all the items in the bag in reverse order
	for(it; it != testBag.end(); it--){
		cout << *it << endl;
	}


	//////////////////Prefix Test////////////////////////

	//Create a const bag to be used with the const iterator
	const bag<int> constBag = constConverter(testBag);
	//State iteration of the const bag
	bag<int>::const_iterator const_it = constBag.begin();

	//Prints off all the items in the bag in forward order
	for(const_it; const_it != constBag.end(); ++const_it){
		cout << *const_it << endl;
	}

	//Restarts iteration of the bag
	const_it = constBag.begin();
	//Increment the iterator to test the -- Operator
	++const_it;
	++const_it;
	++const_it;
	
	//Print off all the items in the bag in reverse order
	for(const_it; const_it != constBag.end(); const_it--){
		cout << *const_it << endl;
	}
	
	
	return EXIT_FAILURE;

}



