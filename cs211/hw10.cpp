// Adam vanWestrienen
// HW # 10 - N Queens

#include <iostream>
#include <cmath>
using namespace std;


bool isOk(int q[], int c);
int nqueens(int n);
void backtrack(int q[], int &c);

int main() {
  
  int n = 12;
  for (int i = 1; i <= n; ++i)
    cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}

int nqueens(int n) {

  int* q = new int[n];
  q[0] = 0;
  int c = 0;
  int counter = 0; 
  
    while (c >= 0) {
      c++;
      if (c == n ) {
        counter++;
        backtrack(q, c);
    } else {
        q[c] = -1;
    } while (c >= 0) {
      q[c]++;
        if (q[c] == n) {
          backtrack(q, c);
        } else {
          if (isOk(q, c)) {
            break;
          }
        
        }
        
    }
  }
  
  delete [] q;
  return counter;
}


bool isOk(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if (q[i] == q[c] || c - i == abs(q[c] - q[i]))
      return false;
  }
      return true;  
}


void backtrack(int q[], int &c) {
  c--;
  if (c == -1) {
return;
//  q[c]++;  
  }
  
}






