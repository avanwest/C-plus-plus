// Adam vanWestrienen

#include "Poly.h"
#include <fstream>
#include <string>

int main(){
	string line1, line2;
	ifstream File;
	
	File.open("input.txt");
	ofstream Print("output.txt");
	if(File.is_open()){
		while(File.good()){
			getline(File, line1);
      cout << line1 << endl;
			getline(File, line2);
      cout << line2 << endl;
			printList(line1, line2);
		}
	}
	
	Print << os.str();
	File.close();
	Print.close();
	
	return 0;
}