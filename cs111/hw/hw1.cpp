
/*
 
Author: Adam vanWestrienen
Class: CS111 22A
Date: Feb. 14, 2017

Purpose: HW1, Create working programs to A) greet the user B) calculate the area of a trapezoid. 

*/

#include <iostream>
using namespace std;

int main() {

	// Part A. 

	string name;
	
	cout << "Part A: \n";
	cout << "What is your name?: ";
	cin >> name;

	cout << "***********************************" << endl;
	cout << "Hello " << name << "!" << endl << "This is CS111!" << endl << "It's great to see you!" << endl;;
	cout << "***********************************" << endl; 


	// Part B. 
	
	double  height, base1, base2;

	cout << "Part B. \n";
	cout << "What is the height of the trapezoid?: ";
    cin >> height;
	cout << "What is the base 1 of the trapezoid?: ";
	cin >> base1;;
	cout << "What is the base 2 of the trapezoid?: ";
	cin >> base2;
	cout << "The area of the tapezoid is: " << 1.0/2.0 * height * (base1 + base2) << endl; 
	return 0;
} 


