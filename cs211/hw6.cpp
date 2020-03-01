// Adam vanWestrienen
// HW#6 - 8 numbers in a cross

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

static int helper[8][5] = {
  {-1},               // 0
  {0, -1},            // 1
  {0, 1, -1},         // 2
  {0, 2, -1},         // 3
  {1, 2, -1},         // 4
  {1, 2, 3, 4, -1},   // 5
  {2, 3, 5, -1},      // 6
  {4, 5, 6, -1}       // 7
};

for (int i = 0; i < c; i++) {
  if (q[i] == q[c]) return false;
}
for (int i = 0; helper[c][i] != -1; i++) {
  if (abs(q[c] - q[helper[c][i]]) == 1) return false;
  }
 return true;
}

void print(int q[]) {
  static int solutions = 0;
  cout << "Solution # " << ++solutions << ": ";
  for (int i = 0; i < 8; i++) {
    cout << q[i] + 1;
    
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