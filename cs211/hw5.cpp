// Adam vanWestrienen
// HW#5 - 8 Queens - (1D w/out gotos)

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
using namespace std;


bool isOk(int q[], int c);
void print(int q[]);
void backtrack(int q[], int &c);

int main() {
  
  int q[8] = {}, c = 0;
  q[0] = 0;
  
    while (c >= 0) {
      c++;
      if (c == 8) {
        print(q);
        backtrack(q, c);
    } else {
        q[c] = -1;

    } while (c >= 0) {
      q[c]++;
        if (q[c] == 8) {
          backtrack(q, c);
        } else {
          if (isOk(q, c))
            break;
        }
        
    }
    
      
    }
     
  return 0;
}


bool isOk(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
      return false;
  }
      return true;  
}

void print(int q[]) {
  static int solutions = 0;
  cout << "Solution #" << ++solutions << ": ";
  for (int i = 0; i < 8; i++) {
    cout << q[i] << " ";
  }
  cout << endl;
}

void backtrack(int q[], int &c) {
  c--;
  if (c == -1) {
    exit(0);
  q[c]++;  
  }
}






