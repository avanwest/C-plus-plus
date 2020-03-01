
#include <iostream>
using namespace std;

int main() {

// Declare Celcius temperature variable 

double ctemp;

// Ask user to input a temperature in Celcius

cout << "Input a Celcius temperature and press ENTER: ";

// Store response in the ctemp variable

cin >> ctemp;

// Convert Celcius temperature and output results

cout << "The temperature in Fahrenheight is: " << (ctemp * 1.8) + 32;

return 0; 


} 
