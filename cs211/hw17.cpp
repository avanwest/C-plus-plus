// Adam vanWestrienen
// HW #17

#include <iostream>
#include <cmath>
#include <string>
using namespace std; 


class Rat {
  private: 
    int n;
    int d;
    
  public:
  // CONSTRUCTORS
    
  // default constructor
  Rat() {
    n = 0;
    d = 1;
  }
  
  // converstion constructor
  Rat(int i) {
    n = i;
    d = 1;
  }
  
  // 2 parameter constructor
  Rat(int i, int j) {
    n = i;
    d = j;
  }
  
  // accessor functions
  int getN() { return n; }
  int getD() { return d; }
  
  void setN(int i) { n = i; }
  void setD(int j) { d = j; }
  
  // arithmatic operators
  Rat operator+(Rat r) {
    Rat t;
    t.n = n * r.d + d * r.n;
    t.d = d * r.d;
    return t;
  }
  
  Rat operator-(Rat r) {
    Rat t;
    t.n = n * r.d - d * r.n;
    t.d = d * r.d;
    return t;
  }
  
  Rat operator*(Rat r) {
    Rat t;
    t.n = n * r.n;
    t.d = d * r.d;
    return t;
  }
  
  Rat operator/(Rat r) {
    Rat t;
    t.n = n * r.d;
    t.d = d * r.n;
    return t;
  }
  

  // 2 overloaded i/o operators
  friend ostream& operator<<(ostream& os, Rat r);
  friend istream& operator>>(istream& is, Rat& r);
};

 // GCD function
  int gcd(int n, int d) {
    if (d == 0) return n;
      else return gcd(d, n % d);
  }
  // Reduce function
  Rat reduce(int &i, int &j){ 
    for(int a=i;a>0;a--){
        if(i%a==0 && j%a==0){
            i=i/a;
            j=j/a;
            break;
        }
    }
    return Rat(i,j);
    }
  
  ostream& operator<<(ostream& os, Rat r){
    reduce(r.n, r.d);
  // x/x always is one.
  if (r.n == r.d ) {
    os << "1" << endl;
  }
  // If the numerator is larger than the denominator, convert to whole decimal and the
  // remainder.
  else if ( r.n > r.d ) {
    int x = r.n / r.d;
    int y = r.n % r.d;
    // No remainder?
    if (y == 0) {
      os << to_string(x) << endl;
    }
    // There is a remainder.
    else {
      os << to_string(x) + " " + to_string(y) + "/" + to_string(r.d) << endl;
    }
  }
  // Otherwise just output the fraction.
  else {
    os<<r.n<<"/"<<r.d<<endl;
  }
  return os;
  
}
    
    
  istream& operator>>(istream& is, Rat& r) {
    is >> r.n >> r.d;
    return is;
  }
  

int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}






