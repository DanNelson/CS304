// HW1-DannyNelson.cpp : Defines the entry point for the console application.
//Creates objects and tests them
//All remaining member functions are indirectly tested in the statistician.cpp file

#include "stdafx.h"
#include "statistician.h"

using namespace cs304_statistician;

int _tmain(int argc, _TCHAR* argv[])
{
	//Creates a statistician object
	statistician statistician_obj1;
	statistician_obj1.next(5);
	statistician_obj1.next(6);
	statistician_obj1.next(7);
	statistician_obj1.next(8);
	statistician_obj1.next(9);
	statistician_obj1.next(10);
	//Prints statistician object string representation
	std::cout << statistician_obj1 << std::endl;

	//Creates a statistician object
	statistician statistician_obj2;
	statistician_obj2.next(2);
	statistician_obj2.next(3);
	statistician_obj2.next(4);
	//Prints statistician object string representation
	std::cout << statistician_obj2 << std::endl;

	//Test the infix + operator functionality
	statistician statistician_obj3;
	statistician_obj3 = statistician_obj1 + statistician_obj2;
	std::cout << statistician_obj3 << std::endl;

	//Tests the infix * operator functionality
	statistician statistician_obj4;
	statistician_obj4 = 4 * statistician_obj2;
	std::cout << statistician_obj4 << std::endl;

	//Tests the infix == operator functionality
	std::cout << "Are the statistician objects the same? " << (statistician_obj4 == statistician_obj1) << std::endl;
	return EXIT_SUCCESS;
}

