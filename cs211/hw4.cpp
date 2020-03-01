//Adam vanWestrienen
//HW #4 -  8 of Queens - (2D Array)


#include <iostream>
using namespace std;


int main() {

	int b[8][8] = {0}, r = 0, c = 0;

   	b[0][0] = 1;   // begin by placing a queen in  1st row, 1st column

// next column	
nc: 
   	c++; 
	if (c == 8) goto print; // if you pass the last column, go to print
	r = -1;

// next row	
nr: 
   	r++; 
	if (r == 8) goto backtrack; 

	// row test
	for (int i = 0; i < c; i++) {  
		if (b[r][i] == 1) goto nr;
	}

	// up diagnal test
	for (int i = 1; (r - i >= 0) && (c - i >= 0); i++) { 
		if (b[r - i][c - i] == 1) goto nr;
	}
	// down diagnal test
	for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++) {
		if (b[r + i][c - i] == 1) goto nr;
	}

	b[r][c] = 1;
	goto nc;

// backtrack: move to previous column and check for solution	
backtrack: c--;

	if (c == -1) return 0;

	r = 0;
	while (b[r][c] != 1) {
		r++;
	}
    b[r][c] = 0;	
    goto nr;
	

// print solutions	
print: 

	static int solution = 0;

	cout << "Solution #" << ++solution << ":" << endl;
	for (int row  = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			cout << b[row][col];
		}
		cout << endl;
	}
	cout << endl;
	goto backtrack;
}





