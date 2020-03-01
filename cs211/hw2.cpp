//Adam vanWestrienen
//CS211
//HW#2

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;


bool equivalent(int a[], int b[], int n);

int main() {

	int size = 5;
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {5, 1, 2, 3, 4};
	int c[5] = {3, 1, 4, 5, 2};
	int d[5] = {3, 4, 5, 1, 2};

	if (equivalent(a, d, size))
		cout << "The arrays are shift equivalent" << endl;
	else
		cout << "The arrays are NOT shift equivalent" << endl;

	return 0;

}

bool equivalent(int a[], int b[], int n) {
	
	bool isEqual = false;
	bool done = false;

	int i = 0, j = 0, k = 0;
	
	while (!done) {
		cout << a[i] << "--" << b[j] << endl;
		if (a[i] != b[j]) {
			j = (j < n - 1) ? j + 1 : 0;
			if (k > 0) {
				done = true;
				isEqual = false;
			}
		}
		else {
			i = (i < n - 1) ? i + 1 : 0;
			j = (j < n - 1) ? j + 1 : 0;
			if (k++ == n) {
				done = true;
				isEqual = true;
			}
		}
	}
	return isEqual;
}








