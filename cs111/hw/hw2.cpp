
// vanWestrienen, Adam 
// CS111 11A Homework 2
// March 1, 2017
//
// Purpose: Translate user's BMI index based on height and weight input



#include <iostream> 
using namespace std;


int main() {

	double h, w, bmi;

	cout << "Body Mass Index Program \n";
	cout << "What is your height measured in inches: \n";
	cin >> h;
	if (h < 10) {
		cout << "Input for height must be 10 inches or more. \n";
		cout << "Terminating the Program. \n";
	return 0;
	}

	cout << "What is your weight meaured in pounds: \n";
	cin >> w;
	while (w <= 0) {
		cout << "Please enter a weight greater than 0 lb: ";
		cin >> w;
	}
	
	bmi =  (w * 703) / (h * h);
	
	
	if ((bmi >= 18.5) && (bmi <= 25)) {
	   	cout << "Your BMI index is " << bmi << " and considered normal."<< endl;
	} else if (bmi < 18.5) {
		cout << "Your BMI index is " << bmi << " and considered underweight." << endl;
	} else {
		cout << "Your BMI index is " << bmi << " and considered overweight." << endl;
	}	

	return 0;


}
