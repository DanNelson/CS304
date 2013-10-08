// FILE: statistician.h
// Written by: Michael Main (main@colorado.edu)
//             Modified 08/28/2013 by kw
//			   Modified 09/04/2013 by Dan Nelson
//
// CLASS PROVIDED: statistician
//   A class to keep track of statistics on a sequence of real numbers
//   This class is part of the namespace cs301_statistician.
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers.
//
// MODIFICATION functions
//   void next(int r)
//     Postcondition: The number r has been added to the statistician as the next
//     number in the sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//   
// CONSTANT functions
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean of the numbers
//     in the statistician's sequence.
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the smallest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned is equivalent to one that had 
//     received all of the numbers of the sequences of s1 and s2.
//   statistician operator *(int scale, const statistician& s)
//     Postcondition: The statistician that is returned is equivalent to one that had 
//     received the same sequence that s had, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: Returns true when s1 and s2 have the same length, mean,
//     minimum, maximim, and sum. Returns false otherwise.
//   ostream& operator <<(ostream& outs, const statistician& s)
//     Postcondition: the length of the statistician has been written to outs
//     
// VALUE SEMANTICS for the statistician class:
//	 Assignments and the copy constructor may be used with statistician objects.

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>


namespace cs304_statistician
{
    class statistician
    {
    public:
        // CONSTRUCTOR
        statistician( );
        // MODIFICATION MEMBER FUNCTIONS
        void   next(int r);
        void   reset( );
        // CONSTANT MEMBER FUNCTIONS
        int    length( )  const;
        double sum( )     const;
        double mean( )    const;
        double minimum( ) const;
        double maximum( ) const;
        // FRIEND FUNCTIONS
        friend statistician operator +(const statistician& s1, const statistician& s2);
        friend statistician operator *(double scale, const statistician& s);
        //Changed line to allow program to compile
		friend std::ostream& operator <<(std::ostream& outs, const statistician& s);
    private:
    	//Defines instance variables
    	int save_length;
		double save_min;
		double save_max;
		double save_mean;
		double save_sum;
    };

    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);
}

#endif
