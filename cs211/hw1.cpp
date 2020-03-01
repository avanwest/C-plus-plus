// Adam vanWestrienen
// CS211
// HW#1


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;


int main() {

	long long pSquare, num1, num2;

	for (long long i = 1; ; i++) {
		pSquare = i * i;
		num1 = pSquare / 10 % 10;
		num2 = pSquare % 10;

		if (num1 % 2 != 0 && num2 % 2 != 0) {
			cout << i << endl;
			cout << pSquare;
			return 0;
		}
	}
}


