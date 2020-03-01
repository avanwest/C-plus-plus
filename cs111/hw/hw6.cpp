//Adam vanWestrienen, MW 11:10-12pm, CS111


#include <iostream>
#include <string>
using namespace std;


int smallCol(int x[][3], int r, int c);
string toUpperCase(string x);
string toLowerCase(string x);
bool equals(string x, string y);

int main() {

	int x[2][3] = {{3, 1, 4}, {1, 5, 9}};
	cout << "Smallest column sum = " << smallCol(x, 2, 3) << endl;

	string z; 
	string y;

	cout << "Enter a string: ";
	getline(cin, z);

	cout << "Enter another string: ";
	getline(cin, y);
	
	cout << "Words in uppercase: " << toUpperCase(z) << " " << toUpperCase(y) << endl;
	cout << "Words in lowercase: " << toLowerCase(z) << " " << toLowerCase(y) << endl;
	
	if (equals(z,y)) cout << "They are the same.";
	else cout << "They are not the same." << endl;

	return 0;

}

	int smallCol(int x[][3], int r, int c) {
		int smallest;
		for (int col = 0; col < c; col++) {
			int total = 0;
			for (int row = 0; row < r; row++)
				total += x[row][col];
				if (col == 0 || total < smallest) 
					smallest = total;
		}
		return smallest;
	}

	string toUpperCase(string x) {
		for (int i = 0; i < x.length(); i++)
			if (x[i] >= 'a' && x[i] <= 'z')
				x[i] = x[i] - 'a' + 'A';
		return x;
	}
	
	string toLowerCase(string x) {
		for (int i = 0; i < x.length(); i++) 
			if (x[i] >= 'A' && x[i] <= 'Z')
				x[i] = x[i] - 'A' + 'a';
		return x;
	}

	bool equals(string x, string y) {
		if (x.length() == y.length()) {
			for (int i = 0; i < x.length(); i++) {
				if (x[i] == y[i]) return true;
				else return false;
			}
		}
		else return false;
	}









