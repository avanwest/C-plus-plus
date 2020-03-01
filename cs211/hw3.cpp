// Adam vanWestrienen
// HW#3 - Score the race

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

bool valid(int numRunners[]);


int main() {
  
  int teamScores[26] = {0};
  int numRunners[26] = {0};
  string input;
  
  cout << "Enter the winners of the race (enter done to exit): ";
  cin >> input;
  while (input != "done") {
  
    for (int i = 0; i < 26; i++) {
      teamScores[i] = 0;
      numRunners[i] = 0;
    } 
      
      
    for (int i = 0; i < input.length(); i++) { 
      switch (input.at(i)) {
          case 'A': 
            teamScores[0] += i + 1;
            numRunners[0] ++;
            break;
          case 'B': 
            teamScores[1] += i + 1;
            numRunners[1] ++;
            break;
          case 'C': 
            teamScores[2] += i + 1;
            numRunners[2] ++;
            break;
          case 'D': 
            teamScores[3] += i + 1;
            numRunners[3] ++;
            break;
          case 'E': 
            teamScores[4] += i + 1;
            numRunners[4] ++;
            break;
          case 'F': 
            teamScores[5] += i + 1;
            numRunners[5] ++;
            break;
          case 'G': 
            teamScores[6] += i + 1;
            numRunners[6] ++;
            break;
          case 'H': 
            teamScores[7] += i + 1;
            numRunners[7] ++;
            break;
          case 'I': 
            teamScores[8] += i + 1;
            numRunners[8] ++;
            break; 
          case 'J': 
            teamScores[9] += i + 1;
            numRunners[9] ++;
            break;
          case 'K': 
            teamScores[10] += i + 1;
            numRunners[10] ++;
            break;
          case 'L': 
            teamScores[11] += i + 1;
            numRunners[11] ++;
            break; 
          case 'M': 
            teamScores[12] += i + 1;
            numRunners[12] ++;
            break;
          case 'N': 
            teamScores[13] += i + 1;
            numRunners[13] ++;
            break;
          case 'O': 
            teamScores[14] += i + 1;
            numRunners[14] ++;
            break; 
          case 'P': 
            teamScores[15] += i + 1;
            numRunners[15] ++;
            break;
          case 'Q': 
            teamScores[16] += i + 1;
            numRunners[16] ++;
            break;
          case 'R': 
            teamScores[17] += i + 1;
            numRunners[17] ++;
            break;
          case 'S': 
            teamScores[18] += i + 1;
            numRunners[18] ++;
            break;
          case 'T': 
            teamScores[19] += i + 1;
            numRunners[19] ++;
            break;
          case 'U': 
            teamScores[20] += i + 1;
            numRunners[20] ++;
            break; 
          case 'V': 
            teamScores[21] += i + 1;
            numRunners[21] ++;
            break;
          case 'W': 
            teamScores[22] += i + 1;
            numRunners[22] ++;
            break;
          case 'X': 
            teamScores[23] += i + 1;
            numRunners[23] ++;
            break; 
          case 'Y': 
            teamScores[24] += i + 1;
            numRunners[24] ++;
            break;
          case 'Z': 
            teamScores[25] += i + 1;
            numRunners[25] ++;
            break;
            
        }
        
    }
    
    // Error messages: use valid function to check for equal number of teams and uppercase input. 
    for (int i = 0; i < input.length(); i++) {
      if (valid(numRunners)) {
        cout << "Not valid entry. Each team must have equal number of runners. Try again." << endl;
        cin >> input;
        break;
      }
      if (islower(input[i])) {
        cout << "Not valid entry. Must use uppercase letters." << endl;
        cin >> input;
        break;
      }
        
    }
    
  
    
    // Check the number of teams and number of runners and output it:
    int runners = 0;
    int numTeams = 0; 
    for (int i = 0; i < 26; i++) {
      if (numRunners[i] > 0)
        numTeams++;
        if (numRunners[i] > runners)
          runners = numRunners[i];
    }
    cout << endl;
    cout << "Number of teams in the race: " << numTeams << endl;
    cout << "Number of runners per team: " << runners << endl;
    cout << "--------------------------------" << endl;
    cout << "RESULTS" << endl;
  
    
    // Run the results of the race and score it:
    char teamNames[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    double bestScore = 10000;
    int bestIndex = 0;
    int min;
    
    for (int i = 0; i < 26; i++) {
      double score = teamScores[i];
      if (teamScores[i] > 0) {
        double average =  score / runners;
        
        cout <<  teamNames[i] << " " << average << endl;

        if (bestScore > average && average != 0) {
          bestScore = average;
          bestIndex = i;
        }
          if (i > 0 && teamScores[i] < teamScores[i - 1])
            min = i;
      }
    } 
    
    // Output the winner:
    cout << endl;
    cout << "And the winning team is...team " << teamNames[bestIndex] << "! with a total placement score of "<< bestScore << " points. Congratulations!" << endl;
    cout << endl << endl;
      
    // Start the next race:
    cout << "Enter the winners of next the race (enter done to exit): ";
    cin >> input;
    
    }
    
  return 0;
  
}
   
    
// Check for valid number of runners per team:
bool valid(int a[]) {    
    int runnersPerTeam; 
    for (int i = 0; i < 26; i++) {
      if (a[i] == 0) continue;
        runnersPerTeam = a[i];
        break;
    }
    
    for (int i = 0; i < 26; i++) {
      if (a[i] != runnersPerTeam && a[i] != 0) 
        return true;
      }
      return false;
    
}

