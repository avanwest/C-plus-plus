// Name: Adam vanWestrienen
// Project 4: Polynomial Arithmatic Redux (Maps)
// Reused the previous poly code for assignment 2 but redid with map data structure.


#include <fstream>
#include <sstream>
#include <map>
using namespace std;

class Poly {
	private:
	map <int, int> polynomial;
	
	public:
	Poly();
	
	void setCanonical(int c, int e);
	string getPoly();
	
	bool check(int c, int e);
	string convertInteger(int a);
};

	Poly::Poly() {}
	
	//Insert to Map, check if already there 
	void Poly::setCanonical(int c, int e) {
        if (check(c, e)) return;
        polynomial[e] = c;
    }

	string Poly::getPoly() {
	    string output = "", space = "", add = "+", x = "x", power = "x^", sub = "-";

		//Iterate through map
		map<int, int>::reverse_iterator p;
        for (p = polynomial.rbegin(); p != polynomial.rend(); p++) {
            if ((p -> second != 0) && (p -> first > 1)) {
                 if (p == polynomial.rbegin()) output += convertInteger(p -> second) + power + convertInteger(p -> first);
                 else if (p -> second < 0) output +=  sub +  convertInteger(p -> second * -1) + power + convertInteger(p -> first);
                 else output +=  add + convertInteger(p-> second) + power + convertInteger(p -> first);
            } else if ((p -> second != 0) && (p -> first == 1)){
                if (p -> second < 0) output +=  sub +  convertInteger(p -> second * -1) + x;
            	else output +=  add + convertInteger(p-> second) + x;
            } else if (p -> second != 0){
                if (p -> second < 0) output +=  sub +  convertInteger(p -> second * -1);
            	else output +=  add + convertInteger(p-> second);
            } 
        }
		//Return string
		return output;
	}
	
	
	
	//Check for exponent
	bool Poly::check(int c, int e) {
		
        //Iterate through map
        map<int, int>::iterator p = polynomial.find(e);
        if (p != polynomial.end()) 
        {
            p -> second += c;
            return true;
        }
        return false;
    }
    
  // Convert Integer
	string Poly::convertInteger(int x)
	{
		stringstream temp;
		temp << x;
		return temp.str();
	}
	

ostringstream os;
void output(string string_1, string string_2)
{
 	Poly canonical_1, canonical_2, Addition, Substitution, Multiplication;
	int Coefficient_1, Coefficient_2, Exponent_1, Exponent_2;
	stringstream str_1(string_1);
	while(str_1 >> Coefficient_1 >> Exponent_1)
	{
		//Add first string of polynomials
		canonical_1.setCanonical(Coefficient_1, Exponent_1);
		Addition.setCanonical(Coefficient_1, Exponent_1);
		Substitution.setCanonical(Coefficient_1, Exponent_1);
		
		stringstream str_2(string_2);
		while(str_2 >> Coefficient_2 >> Exponent_2)
		{
			//Multiplication of two polynomials (multiply the coeffiecnet and add the exponents).
			Multiplication.setCanonical(Coefficient_1 * Coefficient_2, Exponent_1 + Exponent_2);
		}
	}
	
	stringstream str_3(string_2);
	while(str_3 >> Coefficient_2  >> Exponent_2)
	{
    //Add second string of polynomials
		canonical_2.setCanonical(Coefficient_2, Exponent_2);
		
		Addition.setCanonical(Coefficient_2, Exponent_2);
		
    // Flip sign
		Substitution.setCanonical(-Coefficient_2, Exponent_2);
	}
	
	//Output
	os << "Polynomial 1 canonical form: " << canonical_1.getPoly() << endl;
	os << "Polynomial 2 canonical form: " << canonical_2.getPoly() << endl << endl;
	
	os << "Polynomial 1 + Polynomial 2 = " << Addition.getPoly() << endl;
	os << "Polynomial 1 - Polynomial 2 = " << Substitution.getPoly() << endl;
	os << "Polynomial 1 * Polynomial 2 = " << Multiplication.getPoly() << endl << endl;
};

int main(){
	string string_1, string_2;
	ifstream File;
	
	File.open("inputFile.txt");
	ofstream Print("outputFile.txt");
	if(File.is_open()){
		while(File.good()){
			getline(File, string_1);
			getline(File, string_2);
			output(string_1, string_2);
		}
	}
	
	Print << os.str();
	File.close();
	Print.close();
	
	return 0;
}







