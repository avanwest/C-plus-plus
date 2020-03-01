// Adam vanWestrienen 
// HW #13
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
using namespace std;

void print(int q[]);
bool ok(int q[], int col);
void backtrack(int q[], int &c);

int main() {
  
  int q[3] = {}, c = 0;
  q[0] = 0;
  
      while (c >= 0) {
      c++;
      if (c == 3) {
        print(q);
        backtrack(q, c);
    } else {
        q[c] = -1;

    } while (c >= 0) {
      q[c]++;
        if (q[c] == 3) {
          backtrack(q, c);
        } else {
          if (ok(q, c))
            break;
        }
        
    }
    
      
    }
     
  return 0;
}
  

bool ok(int q[], int c) {
  
  
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
  static int solution = 0;
  cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
  for (int i = 0; i < 3; ++i)
    cout << i << "\t" << q[i] << endl;
  cout << endl;
  
  
}

void backtrack(int q[], int &c) {
  c--;
  if (c == -1) {
    exit(0);
  q[c]++;  
  }
}

