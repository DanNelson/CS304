//Files to be included 
#include "stdafx.h"
#include "statistician.h"

//Using the standard namespace
using namespace std;

//Statistician constructor
//Initializes all instances variables
cs304_statistician::statistician::statistician(){
		cs304_statistician::statistician::reset();
}

//Next function
void cs304_statistician::statistician::next(int r){
	//Add the current number to the sum
	save_sum += r;
	//If there this is the first number inputed, then it is the minimum
	if(save_length == 0){
		save_min = r;
	}
	//Add one to the length
	save_length += 1;
	//If the current number is larger than the previous max then set the max to the current number
	if(r > save_max){
		save_max = r;
	}
	//If the current number is smaller than the smallest number set the min to the current number
	if(r < save_min){
		save_min = r;
	}
	//Save the mean
	//Cast length to a double to force double division
	save_mean = (save_sum /(double)save_length);
}

//Reset function
//Sets all instance variables back to zero
void cs304_statistician::statistician::reset(){
		save_length = 0;
		save_max    = 0.0;
		save_mean   = 0.0;
		save_min    = 0.0;
		save_sum    = 0.0;
}

//Returns the length of the statistician
int cs304_statistician::statistician::length() const{
	return save_length;
}

//Returns the sume of the statistician
double cs304_statistician::statistician::sum() const{
	return save_sum;
}

//Returns the mean of the statistician
double cs304_statistician::statistician::mean() const{
	return save_mean;
}

//Returns the minimum of the statistician
double cs304_statistician::statistician::minimum() const{
	return save_min;
}

//Returns the maximum of the statistician
double cs304_statistician::statistician::maximum() const{
	return save_max;
}

//Overrides the + opperator
 cs304_statistician::statistician cs304_statistician::operator +(const statistician& s1, const statistician& s2){
	//Creates a new statistician object to save values to and return
	statistician statistician_return;	
	//Adds the length of the two statistician
	statistician_return.save_length = s1.length() +s2.length();
	//Adds the sum of the statistician	
	statistician_return.save_sum = s1.sum() +s2.sum();
	//Selects which max to take	
	if(s1.maximum() > s2.maximum() ){
		statistician_return.save_max = s1.maximum();
	}
	else{
		statistician_return.save_max = s2.maximum();
	}
	//Selects which min to take
	if(s1.minimum() < s2.minimum() ){
		statistician_return.save_min = s1.minimum();
	}
	else{
		statistician_return.save_min = s2.minimum();
	}
	//Recalculates the mean
	statistician_return.save_mean = (((s1.mean()*s1.length()) +(s2.mean()*s2.length()))/statistician_return.save_length);	
	return statistician_return;
}

//Overrides the * operator
cs304_statistician::statistician cs304_statistician::operator *(double scale, const statistician& s){
	//Creates new statistician object to be returned
	statistician statistician_return;	
	//Scales all the values of the statistician
	statistician_return.save_max = s.maximum() * scale;
	statistician_return.save_mean = s.mean() * scale;
	statistician_return.save_min = s.minimum() * scale;
	statistician_return.save_sum = s.sum() * scale;
	//Retains the origin length
	statistician_return.save_length = s.length();	
	return statistician_return;
}


//Checks to see if two statisticians lengths are equal
bool cs304_statistician::operator ==(const statistician& s1, const statistician& s2){
	//If they are equal lengths return true
	if(s1.length() == s2.length() && s1.minimum() == s2.minimum() && s1.mean() == s2.mean() && s1.sum() == s2.sum() && s1.maximum() == s2.maximum())
		return true;
	//If they are not equal lengths return false
	else
		return false;
}

//Overrides the ostream operator
 ostream& cs304_statistician::operator <<(std::ostream& outs, const statistician& s){
	 outs << "Lenght: " << s.length() << std::endl;
	 outs << "Sum: " << s.sum() << std::endl;
	 outs << "Mean: " << s.mean() << std::endl;
	 outs << "Minimum: " << s.minimum() << std::endl;
	 outs << "Maximum: " << s.maximum() << std::endl;
	 return outs;
 }

