// Adam vanWestrienen

#include "SafeMatrix.h" 
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    
    int count = 0;

    // default constructor
    // SafeMatrix <int> m();
    
    // single paramter constructor
    SafeMatrix <int> m1(3);
    
    for (int row = m1.getRowLow(); row <= m1.getRowHigh(); row++) {
        for (int col = m1.getColumnLow(); col <= m1.getColumnHigh(); col++) {
            m1[row][col] = count++;
        }
    }
    
    count = 0;
    
    // two parameter constructor
    SafeMatrix <int> m2(3,3);
    
    for (int row = m2.getRowLow(); row <= m2.getRowHigh(); row++) {
        for (int col = m2.getColumnLow(); col <= m2.getColumnHigh(); col++) {
            m2[row][col] = count += 2;
        }
    }
    
    count = 0;
    
    // copy constructor
    SafeMatrix <int> m3(m1);
    

    // cout << endl << "Matrix m: \n" << m<< endl;
    cout << endl << "Matrix m1: \n" << m1 << endl;
    cout << endl << "Matrix m2: \n" << m2 << endl;
    cout << endl << "Matrix m3: \n" << m3 << endl;
   
 
    // Test multiplication
    cout << "m1 * m2:" << endl << m1 * m2 << endl;
    
    return 0;

}