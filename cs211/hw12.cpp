
// Adam vanWestrienen
// HW #12 -- Towers of Hanoi

#include <iostream>
#include <vector>
using namespace std;


int main() {
  
  vector<int> t[3];
  int n;
  cout << "Please enter the number of rings to mover: ";
  cin >> n;
  cout << endl;
  
  int from = 0, candidate = 1, move = 0;
  int to;
  if (n % 2 != 0) 
    to = 1;
  else 
    to = 2;
  
  // Initialize the towers
  for (int i = n + 1; i >= 1; --i) 
    t[0].push_back(i);
  t[1].push_back(n+1);
  t[2].push_back(n+1);
    
  while (t[1].size() < n+1) {
    cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A')
    << " to tower " << char(to+'A') << endl;
    
    // move the discs around
    t[to].push_back(t[from].back()); 
    t[from].pop_back();
    
    // from
    if (t[(to+1) % 3].back() < t[(to+2) % 3].back())
      from = (to+1) % 3;
    else 
      from = (to+2) % 3;
      
    // update candidate  
    candidate = t[from].back();  
  
    // to
    if (n % 2 != 0) {
      if (candidate < t[(from+1) % 3].back())
      to = (from+1) % 3;
    else
      to = (from+2) % 3;
    }
    if (n % 2 == 0) {
      if (candidate < t[(from+2) % 3].back())
      to = (from+2) % 3;
    else 
      to = (from+1) % 3; 
    }

  }
  
  return 0;
  
}





