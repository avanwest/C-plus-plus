#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;



bool largerThan11(int num);
int  rollDice(int n);
void emphasis(string words);
void computeRectangle(double len, double wid, double& area, double& perimeter);
void swap(double& area, double& perimeter);

int main() {

	cout << "Part A: " << endl;
	
   	srand(time(NULL));
	
	int num1, num2, num3;
	int rollOne = rollDice(num1);
	int rollTwo = rollDice(num2);
	int rollThree = rollDice(num3);
	int sum = rollOne + rollTwo + rollThree;	

	while(largerThan11(sum) == false) {
		cout << "Roll dice: " << rollOne << " " << rollTwo << " " << rollThree << " ";		  cout << "Sum = " << sum << endl;

		rollOne = rollDice(num1);
		rollTwo = rollDice(num2);
		rollThree = rollDice(num3);
		sum = rollOne + rollTwo + rollThree;
	}
	if (largerThan11(sum) == true) {
		cout << "Roll dice: " << rollOne << " " << rollTwo << " " << rollThree << " ";		  cout << "Sum = " << sum << endl;
		emphasis("Yes! Finally.");
	} 
	
	cout << endl;

	cout << "\nPart B: " << endl;
	
	double len = 2.5, wid = 5, area = 0, perimeter = 0;
	computeRectangle(len, wid, area, perimeter);
	cout << "Area of Rectangle = " << area << " and its Perimeter = " 
		 << perimeter << endl;

	swap(area, perimeter);
	
	cout << "Values in area and perimeter are swapped: " << area << " "
		 << perimeter << endl;
	
	return 0;	

}


bool largerThan11(int num) {

	if (num > 11) 
		return true;
	else
	   	return false;
}


int rollDice(int n) {

	n = rand() % 6 + 1;
	return n;

}

void emphasis(string words) {

	for (int i = 0; i < 3; i++) {
		cout << words;
	}
}


void computeRectangle(double len, double wid, double& area, double& perimeter) {

	area = len * wid;
	perimeter = 2 * (len * wid);
}

void swap(double&  area, double& perimeter) {

	double temp = area;
	area = perimeter;
	perimeter = temp;
}




