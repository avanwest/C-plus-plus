// Adam vanWestrienen

#include "VNT.h" 
#include <iostream>
using namespace std;

int main() {

  
	VNT A(5,7);

  cout << A << endl;

  A.add(25);
  A.add(100);
  A.add(42);
  A.add(64);
  A.add(6745);
  A.add(8101214);
  A.add(999999999);

  for (int i = 5; i < 22; i++) {
    A.add(i);
  }
	cout << "VNT A: " << endl << A << endl;
  cout << "The min value in A is: " << A.getMin() << endl << endl;;

  cout << "Is 25 in the table?" << endl;;

  if (A.find(25) == 1) cout << "true";
  else cout << "false";

  cout << endl;

	
	return 0;
}