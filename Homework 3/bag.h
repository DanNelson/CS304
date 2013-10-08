// FILE: bag2.h
// CLASS PROVIDED: bag (a container class for a collection of items)
// DATE: 10/04/13
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
//   size_type insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//	   return value is receipt, or position in the array, that the item
//	   was inserted into. Memory is allocated if needed.
//   
//	 Item remove(size_type receipt_number)
//		Precondition: The receipt number must exist and array position in use
//		Postcondition: The item has been removed from the bag and the
//		return type is Item which will contain the item, if not present throws out_of_range exception.
//
//	 Item operator [](size_type reciept_numer)
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
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bag
//
//	 Item const *  operator [](size_type reciept_numer) const
//		Postcondition: Returns a const pointer to the item given by
//		receipt. If the item is not present, an out_of_range exception
//		is thrown.
//
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag:
//   If there is insufficient dynamic memory, then the following functions call reserve
//   to allocate more memory: The constructors, reserve, insert, and the assignment operator. 
//	 If a memory cannot be allocated, a bad_alloc exception will be thrown.
//
// TYPEDEFS and MEMBER CONSTANTS for the bag_iterator class:
// CONSTRUCTOR for the bag class:
//   bag_iterator(Item * initial_data = NULL, bool * initial_in_use = NULL, typename bag<Item>::size_type * initial_capacity = NULL);
//		Postcondition: The iterator is empty with an the data from
//		the bag. The iterator state will point at the first valid item in the iterator.
//		Default parameters are specified for creating a null iterator.
//
// MODIFICATION MEMBER FUNCTIONS for the bag_iterator class:
//   bag_iterator& operator ++()
//     Postcondition: A bag_iterator will be returned that is the 
//		current state and the state of the iterator will be moved
//		one position forward. If there are more items in the bag
//		if there is not, a null iterator will be created.
//
//   bag_iterator& operator --();
//     Postcondition: A bag_iterator will be returned that is the 
//		current state and the state of the iterator will be moved
//		one position backward. If there are more items in the bag
//		if there is not, a null iterator will be created.
//   
// 	 bag_iterator operator ++(int)
//	    Postcondition: A bag_iterator will be returned with the state
//		one beyond the current state. If there are more items in the bag
//		if there is not, a null iterator will be created.
//
// 	 bag_iterator operator --(int)
//	    Postcondition: A bag_iterator will be returned with the state
//		one behind the current state. If there are more items in the bag
//		if there is not, a null iterator will be created.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//	 Item operator * ( ) const
//		Postcondition: An item will be returned if there is an item in 
//		the current state of the iterator. If there is no item in that state,
//		a null item will be returned.
//
//	 bool operator == (const bag_iterator i) const
//		Postcondition: Returns true if two iterators are equal and
//		false if the two iterators are not equal.
//
//	 bool operator != (const bag_iterator i) const
//		Postcondition: Returns false if two iterators are equal and
//		true if the two iterators are not equal.
//
// NONMEMBER FUNCTIONS for the bag class:
//
// VALUE SEMANTICS for the bag_iterator class:
//   Assignments and the copy constructor may not be used with bag objects.
//
//
// TYPEDEFS and MEMBER CONSTANTS for the bag_iterator class:
// CONSTRUCTOR for the bag class:
//   bag_iterator(const Item * initial_data = NULL, const bool * initial_in_use = NULL, typename const bag<Item>::size_type * initial_capacity = NULL);
//		Postcondition: The iterator is empty with an the data from
//		the bag. The iterator state will point at the first valid item in the iterator.
//		Default parameters are specified for creating a null iterator.
//
// MODIFICATION MEMBER FUNCTIONS for the bag_iterator class:
//   bag_iterator& operator ++()
//     Postcondition: A bag_iterator will be returned that is the 
//		current state and the state of the iterator will be moved
//		one position forward. If there are more items in the bag
//		if there is not, a null iterator will be created.
//
//   bag_iterator& operator --();
//     Postcondition: A bag_iterator will be returned that is the 
//		current state and the state of the iterator will be moved
//		one position backward. If there are more items in the bag
//		if there is not, a null iterator will be created.
//   
// 	 bag_iterator operator ++(int)
//	    Postcondition: A bag_iterator will be returned with the state
//		one beyond the current state. If there are more items in the bag
//		if there is not, a null iterator will be created.
//
// 	 bag_iterator operator --(int)
//	    Postcondition: A bag_iterator will be returned with the state
//		one behind the current state. If there are more items in the bag
//		if there is not, a null iterator will be created.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//	 Item operator * ( ) const
//		Postcondition: An item will be returned if there is an item in 
//		the current state of the iterator. If there is no item in that state,
//		a null item will be returned.
//
//	 bool operator == (const bag_iterator i) const
//		Postcondition: Returns true if two iterators are equal and
//		false if the two iterators are not equal.
//
//	 bool operator != (const bag_iterator i) const
//		Postcondition: Returns false if two iterators are equal and
//		true if the two iterators are not equal.
//
// NONMEMBER FUNCTIONS for the bag class:
//
// VALUE SEMANTICS for the bag_iterator class:
//   Assignments and the copy constructor may not be used with bag objects.
//
// File modified by: Danny Nelson 10/7/13

#ifndef MAIN_SAVITCH_BAG2_H
#define MAIN_SAVITCH_BAG2_H
#include <cstdlib>  // Provides size_t


namespace cs304_bag
{
	//Forward class definition
	template <class Item> class bag_iterator; 
	template <class Item> class const_bag_iterator; 

	template <class Item>
    class bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef Item value_type;
        typedef std::size_t size_type;
		typedef bag_iterator<Item> iterator;
		typedef const_bag_iterator<Item> const_iterator;
        static const size_type DEFAULT_CAPACITY = 30;        
        // CONSTRUCTORS and DESTRUCTOR
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag( );
        // MODIFICATION MEMBER FUNCTIONS
        void reserve(size_type new_capacity);
        size_type insert(const Item& entry);
		Item remove(size_type receipt_number);
		Item operator [](size_type receipt_number);
        void operator =(const bag<Item>& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const Item& target) const;
		Item const * operator [](size_type receipt_number) const;
		const_iterator begin() const;
		const_iterator end() const;

		//ITERATOR FUNCTIONS
		iterator begin();
		iterator end();
		 
    private:
        Item *data;     // Pointer to partially filled dynamic array
		bool *in_use;		  // Pointer to a dynamic array that determines if a give position is in use
        size_type used;       // How much of array is being used
        size_type capacity;   // Current capacity of the bag
		size_type largest_receipt; // Highest receipt number that is in use
    };

	//Non-Const iterator
	template <class Item>
	class bag_iterator:public std::iterator <std::bidirectional_iterator_tag, Item>{
	public:
		// CONSTRUCTORS and DESTRUCTOR
		bag_iterator(Item * initial_data = NULL, bool * initial_in_use = NULL, typename bag<Item>::size_type * initial_capacity = NULL);
		 // MODIFICATION MEMBER FUNCTIONS
		bag_iterator& operator ++();
		bag_iterator& operator --();
		bag_iterator operator ++(int);
		bag_iterator operator --(int); 
		// CONSTANT MEMBER FUNCTIONS
		Item operator * ( ) const;
		bool operator == (const bag_iterator i) const;
		bool operator != (const bag_iterator i) const;
		
	private:
		Item * data; // Pointer to partially filled dynamic array
		bool * in_use; // Pointer to a dynamic array that determines if a give position is in use
		typename bag<Item>::size_type * capacity; // Pointer to the current capacity of the bag
		typename bag<Item>::size_type  state; // Stores the current state of the iterator

	};

	//Const bag iterator
	template <class Item>
	class const_bag_iterator:public std::iterator <std::bidirectional_iterator_tag, const Item>{
	public:
		// CONSTRUCTORS and DESTRUCTOR
		const_bag_iterator(const Item * initial_data = NULL,const bool * initial_in_use = NULL, typename const bag<Item>::size_type * initial_capacity = NULL);
		// MODIFICATION MEMBER FUNCTIONS
		const_bag_iterator& operator ++();
		const_bag_iterator& operator --();
		const_bag_iterator operator ++(int);
		const_bag_iterator operator --(int); 
		// CONSTANT MEMBER FUNCTIONS
		Item operator * ( ) const;
		bool operator == (const const_bag_iterator i) const;
		bool operator != (const const_bag_iterator i) const;
		

	private:
		const Item * data; // Pointer to partially filled dynamic array
		const bool * in_use; // Pointer to a dynamic array that determines if a give position is in use
		const typename bag<Item>::size_type * capacity; // Pointer to the current capacity of the bag
		typename bag<Item>::size_type  state; // Stores the current state of the iterator

	};

}

#include "bag.template"
#endif
