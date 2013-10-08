// FILE: bag2.cxx
// CLASS implemented: bag (see bag2.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used, 
//		the array in_use is used to determine if the current position is
//      in use and a receipt is given which coincides with the array position; 
//   2. The actual items in the bag are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable data;
//   3. The size of the dynamic array is in the member variable capacity.
// File modified by: Danny Nelson 9/18/2013

#include "stdafx.h"
#include "bag2.h"

using namespace std;

namespace cs304_bag
{
   //Constructor to create a new bag object
    bag::bag(size_type initial_capacity)
    {
		//Create new array for items
        data = new value_type[initial_capacity];
		//Create new array to determine if the current position is in use
		in_use = new bool[initial_capacity];
		//Set all of the positions in the in_use array to zero
		for(bag::size_type i = 0; i < initial_capacity; i++){
			in_use[i] = false;
		}
		//The capacity of the bag will be set to the initial_capacity parameter of the constructor
        capacity = initial_capacity;
		//The used and largest receipt are set to zero seeing nothing is in the bag
        used = 0;
		largest_receipt = 0;
    }

	//Constructor called by compiler
    bag::bag(const bag& source)
    // Library facilities used: algorithm
    {
		//Creates new instance variables and copies the data from the old bag to the
		//New bag
        data = new value_type[source.capacity];
		in_use = new bool[source.capacity];
        capacity = source.capacity;
        used = source.used;
		largest_receipt = source.largest_receipt;
        copy(source.data, source.data + capacity, data);
		copy(source.in_use, source.in_use + capacity, data);
    }

	//Destructor called when the program completes to release memory
    bag::~bag( )
    {
		//Deletes dynamically allocated arrays
		delete [ ] data;
		delete [ ] in_use;
    }

	//Changes the size of the bag
    void bag::reserve(size_type new_capacity)
    // Library facilities used: algorithm
    {
		//Create pointers to new arrays
        value_type *larger_array;
		bool * larger_array_bool;

		// The allocated memory is already the right size, do not change the size of the bag
        if (new_capacity == capacity){
            return; 
		}

		//Can’t allocate less than we are using
        if (new_capacity < (largest_receipt+1)){
            new_capacity = largest_receipt+1; 
		}

		//Create a larger array of value_types then copy the data from the old array
		//To the new array and delete the old array
        larger_array = new value_type[new_capacity];
        std::copy(data, data + largest_receipt+1, larger_array);
        delete [ ] data;
        data = larger_array;
		
		//Create the new larger array of booleans then copy the data from the old array
		//To the new array and delete the old array
		larger_array_bool = new bool[new_capacity];
        copy(in_use, in_use + largest_receipt +1, larger_array_bool);
        delete [ ] in_use;
        in_use = larger_array_bool;

		//Set all the newly create positions to false
		for(size_type iterator = largest_receipt+1; iterator < new_capacity;iterator++){
			in_use[iterator] = false;
		}
        
		//Set the capacity to the new larger size
		capacity = new_capacity;
		       
    }
    
	//Inserts items into the bag
    bag::size_type bag::insert(const value_type& entry)
    {   
		//Create a size_type for the iterator
		bag::size_type i = 0;
		
		//If more memory needs to be allocated, call the reserve function 
        if ((largest_receipt+1) == capacity)
			reserve(capacity+1);
		
		//Loop to find a free position
		for(i = 0; i < capacity; i++){
			//If a free position is found
			if(in_use[i] == false){
				//Put the item in the bag
				data[i] = entry;
				//Indicate that the position is used
				in_use[i] = true;
				//Increment the number of items in the bag
				used++;
				//If it is the last position in the array
				if(i == (largest_receipt+1))
					largest_receipt = i;
				//Return the receipt number
				return i;
			}
		}
		//Should never get here keeps the compiler happy
		return i;
    }

	//Removes an item from the bag
	bag::value_type bag::remove(size_type receipt_number){
		//If the receipt the user entered is larger than the highest
		//Spot filled in the bag there is no item to return
		if(receipt_number > largest_receipt)
			throw std::out_of_range("The receipt number is larger than the highest receipt number!");

		//If there is no item in the position that the user entered
		//There is no item to return
		if(!in_use[receipt_number])
			throw std::out_of_range("The receipt number is currently not in use!");

		//Decrement the number of items in the bag
		used --;
		//Set the position to unused
		in_use[receipt_number] = false;
		//Return the item the user requested
		return data[receipt_number];
	}

	//Assignment operator
    void bag::operator =(const bag& source)
    // Library facilities used: algorithm
    {

	// Check for possible self-assignment:
	if (this == &source)
            return;

	// If needed, allocate an array with a different size:
	if (capacity != source.capacity)
	{
		//Use the reserve function instead of rewriting it
		reserve(source.capacity);
	}

	// Copy the data from the source object
	used = source.used;
	largest_receipt = source.largest_receipt;
	copy(source.data, source.data +  capacity, data);
	copy(source.in_use, source.in_use + capacity, in_use);
    
	}

	//Counts the number of times a particular value appears in the bag
    bag::size_type bag::count(const value_type& target) const
    {
	//Creates instance variables for iterator and number of times the value appears
	size_type answer;
	size_type i;
	answer = 0;
	
	//Loop to look through the array to determine how many times the value appears in the bag
	for (i = 0; i < largest_receipt; ++i){
		//Check to see if the item is in the bag
		//Also make sure the position in the bag is in_use because when an item is removed the position it
		//Is not uninitialized. Uses short-circuit evaluation
		if ((in_use[i]) && (target == data[i]))
			++answer;
	}
	return answer;
    }

	//Non-Const overloading of the [] operator
	bag::value_type bag::operator [](size_type receipt_number){
		//If the receipt number the user entered was greater than the largest receipt number
		if(receipt_number > largest_receipt)
			throw std::out_of_range("The receipt number is larger than the highest receipt number!");

		//If the position in the bag is not in use
		if(!in_use[receipt_number])
			throw std::out_of_range("The receipt number is currently not in use!");

		return data[receipt_number];
	}

	//Const overloading of the [] operator
	 bag::value_type const * bag::operator [](size_type receipt_number) const{
		 //If the receipt number the user entered was greater than the largest receipt number
		if(receipt_number > largest_receipt)
			throw std::out_of_range("The receipt number is larger than the highest receipt number! Thrown from const.");
		
		//If the position in the bag is not in use
		if(!in_use[receipt_number])
			throw std::out_of_range("The receipt number is currently not in use! Thrown from const.");
		
		return &data[receipt_number];
	}
	 
	
}