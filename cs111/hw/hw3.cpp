

// vanWestrienen, Adam 
// CS111 11:10-12pm, Homework 3



#include <iostream>
using namespace std;

int main() {

//Part A


	int n, sum = 0, neg = 0, pos = 0;
    double count = 0;

	cout << "Enter an integer, the input ends if it is 0: \n";

	while (true) {
		cin >> n;
		if (n == 0) { 
			double average = sum / count;
			cout << "The number of positives is " << pos << "." << endl;	
		    cout << "The number of negatives is " << neg << "." << endl;
			cout << "The total is " << sum << "." << endl;
			cout << "The average is " << average << "." << endl;
	    	return 0;					
		} else if (n > 0) {
			pos++;
			sum = sum + n;
			count++;
		} else {
			neg++;
			sum = sum + n;
			count++;
		}

	}	

//Part B

	int num;

	do { 
		cout << "Enter an odd integer between 9 and 15 (inclusive): ";
		cin >> num;
	} while (num <= 9 || num >= 15 || num % 2 == 0);

		for (int r = 1; r <= num; r++) {
		  for(int pattern = 1; pattern <= 2; pattern++) {	
			for (int c = 1; c <= num; c++) {
				if (r == c || r + c == num + 1)   	
					cout << "*";
				else if ((r == (num + 1) / 2) && (c > (num + 1) / 2))
					cout << "+";
				else if ((r== (num + 1) / 2) && (c < (num + 1) / 2))
					cout << "x";
				else if ((c == (num + 1) / 2))
					cout << "&";
				else cout << " ";	
			} 
			cout << "    ";
	 	  }		  
		   cout << endl; 	   
		}
	
	return 0;

}
