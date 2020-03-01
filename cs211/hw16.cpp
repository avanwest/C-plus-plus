//Adam vanWestrienen
//HW #16

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c, int n);
void backtrack(int &c, int n);
int kbishops(int n, int k);
void print(int &solutions);

int main() {
  
  int n, k;
  while (true) {
    cout << "Enter board size N x N: ";
    cin >> n;
    if (n == -1)
      break;
    cout << "Enter the number of bishops on the board: ";
    cin >> k;
    cout << "The number of solutions for a board size of " << n << " with " << k << " bishops is: " << kbishops(n, k) << endl;
  }
  return 0;
  
}

bool ok(int q[], int c, int n) {
  for(int i = 0; i < c; i++) {
    if (q[i] / n + q[i] % n == q[c] / n + q[c] % n || q[i] / n - q[i] % n == q[c] / n - q[c] % n);
      return false;
  }
  return true;
}

void backtrack(int &c, int n) {
  c--;
  if (c == -1) {
    cout << n << endl;
    exit(0); 
  }
}

int kbishops(int n, int k) {
  
  int c = 1;
  int solutions = 0;
  bool done = false;

  int * q = new int[k];
  q[0] = 0;
  
  while (true) {
    while (c < k) {
      if (!done) 
        q[c] = -1;
      done = false;
    
      while (q[c] < (n * n)) {
        q[c]++;
      
        if (q[c] == (n * n)) {
        backtrack(c, solutions);
        done = true;
        continue;
      } 
      if (ok(q, c, n)) {
        c++;
        break;
       }
      }
    }

  print(solutions);
  backtrack(c, solutions);
  done = true;
  
    }

  }
  
  void print(int &solutions) {
    solutions++;
  }
  





