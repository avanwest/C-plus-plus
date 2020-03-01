// Adam vanWestrienen

#ifndef SAFEMATRIX_H_INCLUDED
#define SAFEMATRIX_H_INCLUDED

#include "SafeArray.h" 
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class SafeMatrix;

template <typename T>
ostream& operator<<(ostream& os, SafeMatrix<T> s);

template <typename T> 
class SafeMatrix {
    private:
     int rowLow, rowHigh, columnLow, columnHigh;
     SafeArray < SafeArray<T> > Matrix;

public:
    //default constructor
    SafeMatrix() {
        rowLow = 0, columnLow = 0;
        rowHigh = -1, columnHigh = -1;
        Matrix = NULL;
    }

    // one parameter constructor
    SafeMatrix(int size) {
        rowLow = 0, columnLow = 0;
        rowHigh = size - 1; 
        columnHigh = size - 1;
        Matrix = SafeArray < SafeArray <T> >(rowHigh + 1);
        for (int col = rowLow; col <= rowHigh; col++) {
           Matrix[col] = SafeArray <T> (columnHigh + 1);
        }
    }
    
    // two parameter constructor
    SafeMatrix(int rowSize, int colSize) {
        if (rowSize < 1 || colSize < 1) {
            cout << "constructor error in bounds definition" << endl;
            exit(1);
        }
        rowLow = 0, columnLow = 0;
        rowHigh = rowSize - 1;
        columnHigh = colSize - 1;
        Matrix = SafeArray <SafeArray<T> > (rowHigh + 1);
        for (int col = rowLow; col <= rowHigh; col++)  {
          Matrix[col] = SafeArray <T> (columnHigh + 1);
        }
    }
      
    // operator overload []
    SafeArray <T> &operator[](int i) {
        if (i < rowLow || i > rowHigh) {
            cout << "index "<< i << " is out of range"<< endl;
            exit(1);
        }
        
        return Matrix[i];
    }
    
    // operator overload: multiplication
    SafeMatrix <T> operator *(SafeMatrix & s) {
        if((columnHigh - columnLow) - (s.rowHigh - s.rowLow) != 0) {
            return 0;
        }
        int rowSize = (rowHigh - rowLow + 1);
        int colSize = (s.columnHigh - s.columnLow + 1);
        
        // create new matrix
        SafeMatrix <int> Mult(rowSize, colSize);
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                Mult[row][col] = 0;
            }
        }
        
        // multiply
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                for (int i = 0; i < (s.rowHigh - s.rowLow + 1); i++) {
                    Mult[row][col] += ((*this)[row + rowLow][i + columnLow]) 
                      * (s[i + s.rowLow][col + s.columnLow]);
                }
            }
        }
        return Mult;
    }
    
    
    //operator overload <<: so we can directly print SafeMatrix 
    friend ostream& operator<< <T>(ostream& os, SafeMatrix<T> s);
    
    //getters
    int getRowHigh(){
        return rowHigh;
    }
    
    int getColumnHigh(){
        return columnHigh;
    }
    
    int getRowLow(){
        return rowLow;
    }
    
    int getColumnLow(){
        return columnLow;
    }

};

template <class T>
ostream & operator<<(ostream & os, SafeMatrix <T> s) 
{
    for (int r = s.rowLow; r < (s.rowHigh + 1); r++) 
    {
        for (int c = s.columnLow; c < (s.columnHigh + 1); c++) 
        {
            os << s.Matrix[r][c] << " ";
        }
        
        os << endl;
    }
    
    return os;
};

#endif  // SafeMatrix.h