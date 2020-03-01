// Adam vanWestrienen
// HW #15


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows = 5, cols = 6;
static string path[rows][cols];
static int memo[rows][cols] = {0};
int cost(int i, int j);

int main() {
  
  int minRow = 0;
  int ex[rows];
  
  for (int i = 0; i < rows; i++) 
    ex[i] = cost(i, cols - 1);
    
  int min = ex[0];
  for (int i = 1; i < rows; i++) {
    if (min > ex[i]) {
      min = ex[i];
      minRow = i;
    }
  }
  
  cout << "The shortest path is of length " << min << "." << endl;
  cout << "Path: " << path[minRow][cols-1] << endl;
  
  return 0;
  
}

int cost(int i, int j) {
  int u;
  int d;
  int l;
  static int weight[rows][cols] = {
    {3, 4, 1, 2, 8, 6}, 
    {6, 1, 8, 2, 7, 4}, 
    {5, 9, 3, 9, 9, 5}, 
    {8, 4, 1, 3, 2, 6}, 
    {3, 7, 2, 8, 6, 4}
  };
  
  
  if (memo[i][j] != 0) {
    return memo[i][j];
  }
  if (j == 0) {
    path[i][j] = to_string(i);
    return weight[i][j];
  }
  u = (i == 0) ? rows - 1 : i - 1;
  l = j - 1;
  d = (i + 1) % rows;
  int left = cost(i, j - 1) + weight[i][j];
  int up = cost(u, j - 1) + weight[i][j];
  int down = cost(d, j - 1) + weight[i][j];
  
  int min = left;
  

  if (up < min) {
    path[i][j]  =  path[u][l] + ", "  + to_string(i);
    min = up;
  }
   
  if (down < min) {
    min = down;
    path[i][j]  = path[d][l] + ", " +  to_string(i);
  }
  if ( min == left) {
    path[i][j]  = path[i][l] + ", "  + to_string(i);
  
  memo[i][j] = min;
  return min;
  
  }
}
    
    
    
    
    
    
    
    
  
