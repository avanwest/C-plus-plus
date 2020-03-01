#include <iostream>
using namespace std;

int main() {

	double  l, h, perimeter, area;

	cout << "Enter the length and width of the rectangle: " << endl;
	cin >> l >> h;
	perimeter = 2*(l + h);
	area = 2*(l * h);
	cout << "The perimeter of the rectangle is: " << perimeter << endl;
	cout << "The area of the rectangle is: " << area << endl;
	return 0;

}
