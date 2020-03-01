 // Adam vanWestrienen

#ifndef VNT_H_INCLUDED
#define VNT_H_INCLUDED

#include "SafeMatrix.h"
#include <bits/stdc++.h>

class VNT {
	private:
		int row, column;
		SafeMatrix <int> vnt;
	
	public:
  // constructor initialized with INT_MAX
		VNT(int r, int c) {
			row = r;
			column = c;
			SafeMatrix <int> sm(row, column);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
          sm[i][j] = INT_MAX;
			  }
      }
			vnt = sm;
		}
		
	
    // add method (add num to bottom right corner of table)
    void add(int num) {
      if (vnt[row - 1][column - 1] != INT_MAX) {
        cout << "Table is full" << endl;
        exit(1);
      }
      else {
        vnt[row - 1][column - 1] = num;
        sort();
      }
    }

    // sort the table
    void sort() {
      int x;

      for (int k = 0; k < row; k++) {
        for (int m = 0; m < column; m++) {
            x = column+1;
            for (int i = k; i < row ; i++) {
                for (int j = x; j < column; j++) {
                    if (vnt[k][m] > vnt[i][j])
                        swap(vnt[k][m], vnt[i][j]);
                }
                x=0;
          } 
        }
      }  
    }
		
    // get the minimum value in the table
    int getMin() {
      int min = vnt[0][0];

      for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
          if (vnt[i][j] < min) {
            min = vnt[i][j];
          }
        }
      }
      return min;
    }
		
    // find method
    bool find(int num) {
      if (vnt[0][0] == INT_MAX) {
        return false;
      }
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
          if (vnt[i][j] == num) {
            return true;
          }
        }
      }
      return false;

    }
		
		//operator overload for printing.
		friend ostream& operator << (ostream& os, VNT v);
};

	ostream& operator <<(ostream& os, VNT a){
		os << a.vnt;
		return os;
	};

#endif  // VNT.h