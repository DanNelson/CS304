// FILE: bag2.h
// CLASS PROVIDED: bag (a container class for a collection of items)
//
// TYPEDEFS and MEMBER CONSTANTS for the bag class:
//   typedef _____ value_type
//     bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef _____ size_type
//     bag::size_type is the data type of any variable that keeps track of how
//     many items are in a bag.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     bag::DEFAULT_CAPACITY is the initial capacity of a bag that is created
//     by the default constructor.
//
// CONSTRUCTOR for the bag class:
//   bag(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   void reserve(size_type new_capacity)
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//   size_type insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//	   return value is receipt, or position in the array, that the item
//	   was inserted into. Memory is allocated if needed.
//   
//	 value_type remove(size_type receipt_number)
//		Precondition: The receipt number must exist and array position in use
//		Postcondition: The item has been removed from the bag and the
//		return type is value_type which will contain the item, if not present throws out_of_range exception.
//
//	 value_type operator [](size_type reciept_numer)
//		Precondition: The receipt number must exist and array position in use
//		Postcondition: Returns a pointer to the item given by
//		receipt. If the item is not present, an out_of_range exception
//		is thrown.
//
//	 void operator =(const bag& source)
//		Postcondition: Sets two bags equal to each other. If one bag is
//		larger than another bag, more memory is allocated. 
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type size( ) const 
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bag
//
//	 value_type const *  operator [](size_type reciept_numer) const
//		Postcondition: Returns a const pointer to the item given by
//		receipt. If the item is not present, an out_of_range exception
//		is thrown.
//
// NONMEMBER FUNCTIONS for the bag class:
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag:
//   If there is insufficient dynamic memory, then the following functions call reserve
//   to allocate more memory: The constructors, reserve, insert, and the assignment operator. 
//	 If a memory cannot be allocated, a bad_alloc exception will be thrown.

#ifndef MAIN_SAVITCH_BAG2_H
#define MAIN_SAVITCH_BAG2_H
#include <cstdlib>  // Provides size_t

namespace cs304_bag
{
    class bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;        
        // CONSTRUCTORS and DESTRUCTOR
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag( );
        // MODIFICATION MEMBER FUNCTIONS
        void reserve(size_type new_capacity);
        size_type insert(const value_type& entry);
		value_type remove(size_type receipt_number);
		value_type operator [](size_type receipt_number);
        void operator =(const bag& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
		value_type const * operator [](size_type receipt_number) const;
    private:
        value_type *data;     // Pointer to partially filled dynamic array
		bool *in_use;		  // Pointer to a dynamic array that determines if a give position is in use
        size_type used;       // How much of array is being used
        size_type capacity;   // Current capacity of the bag
		size_type largest_receipt; // Highest receipt number that is in use
    };
}

#endif
