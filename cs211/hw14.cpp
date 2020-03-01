// Adam vanWestrienen
// HW #14

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
using namespace std;


bool ok(int q[], int c);
void print(int q[]);
void next(int q[], int c);
void printStable(int q[]);
bool okStable(int q[], int c);
void nextStable(int q[], int c);


int main() {
  int q[8];
  int s[3];
  cout << "8 CROSS SOLUTIONS" << endl;
  cout << "------------------" << endl;
  next(q, 0);
  cout << "STABLE MARRIAGE SOLUTIONS" << endl;
  cout << "-------------------------" << endl;
  nextStable(s, 0);
  return 0;
}

bool ok(int q[], int c) {

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


bool okStable(int q[], int c) {
  static int mp[3][3] = { 
    {0,2,1}, 
    {0,2,1}, 
    {1,2,0}
  };
  static int wp[3][3] = {
    {2,1,0}, 
    {0,1,2},
    {2,0,1}
  };
  
    for (int i = 0; i < c; i++) {
      if (q[i] == q[c])
        return false;
      if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c] || mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])
        return false;
    }
  return true;
}


void print(int q[]) {
  static int solutions = 0;
  cout << "Solution #" << ++solutions << ": ";
  cout << endl << endl;
  cout << " " << q[1] << q[4] << endl;
  cout << q[0] << q[2] << q[5] << q[7] << endl;
  cout <<  " " << q[3] << q[6] << " ";
  cout <<  endl << endl;
}


void printStable(int q[]) {  
  static int solution = 0;
  cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
  for (int i = 0; i < 3; ++i)
    cout << i << "\t" << q[i] << endl;
  cout << endl;
}


void next(int q[], int c) {
  if (c == 8)
    print(q);
  else for (q[c] = 0; q[c] < 8; ++q[c])
    if (ok(q,c)) 
      next(q, c + 1);
}

void nextStable(int q[], int c) {
  if (c == 3)
    printStable(q);
  else for (q[c] = 0; q[c] < 3; ++q[c])
    if (okStable(q,c))
      nextStable(q, c + 1);
}



