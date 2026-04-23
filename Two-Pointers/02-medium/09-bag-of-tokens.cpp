/*
 * Leetcode - 948
 * Bag of Tokens
 * 
 * You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer 
 * array tokens, where each tokens[i] denotes the value of token 'i'.
 * 
 * Your goal is to maximize the total score by strategically playing these tokens. In one move, 
 * you can play an unplayed token in one of the two ways (but not both for the same token):
 * 
 * Face-up: 
 * - If your current power is at least tokens[i], you may play token[i], losing tokens[i] power and gaining 1 score.
 * Face-down: 
 * - If your current score is at least 1, you may play token[i], gaining tokens[i] power and losing 1 score.
 * 
 * Return the maximum possible score you can achieve after playing any number of tokens.

 * Example 1
 * Input  : [100], power = 50
 * Output : 0
 * 
 * Example 2
 * Input  : tokens = [200, 100], power = 150
 * Output : 1
 * 
 * Example 3
 * Input  : tokens = [100, 200, 300, 400], power = 200
 * Output : 2

 * https://leetcode.com/problems/bag-of-tokens/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

int bagOfTokensScore(vector<int> tokens, int power) {
  // * sort the tokens
  sort(tokens.begin(), tokens.end()); 
  int n = tokens.size();
  int i = 0, j = n - 1;

  int score = 0, max_score = 0;
  while(i <= j) {
    // cout << power << endl;
    // * Increase the score by reducing power
    if(power >= tokens[i]) {
      power -= tokens[i];
      score += 1;
      i++;
      max_score = max(max_score, score);
    }
    else {
      if (score >= 1) {
        // * Increase the power by reducing score
        power += tokens[j];
        score -= 1;
        j--;
      }
      else {
        return max_score;
      }
    }
  }
  return max_score;
}

int main() {
  int power = 200;
  vector<int> tokens = {100, 200, 300, 400};

  // int power = 150;
  // vector<int> tokens = {200, 100};

  cout << "Power: " << power << endl;
  cout << "Tokens: ";
  printArr(tokens);

  int ans = bagOfTokensScore(tokens, power);
  cout << "Max Score " << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-bag-of-tokens.cpp -o output && ./output

// * DRY RUN

// * score = 0, max_score = 0
// * power = 200
// * 100, 200, 300, 400 
// * i              j

// * arr[i] = 100 | if(power >= arr[i]) true | power -= arr[i] & score++ & i++

// * ---------------------

// * score = 1, max_score = 1
// * power = 100
// * 100, 200, 300, 400 
// *      i          j

// * arr[i] = 200 | if(power >= arr[i]) false | power += arr[j] & score-- & j--;

// * ---------------------

// * score = 0, max_score = 1
// * power = 500
// * 100, 200, 300, 400 
// *      i     j

// * arr[i] = 200 | if(power >= arr[i]) true | power -= arr[i] & score++ & i++;

// * ---------------------

// * score = 1, max_score = 1
// * power = 300
// * 100, 200, 300, 400 
// *           ij

// * arr[i] = 300 | if(power >= arr[i]) true | power -= arr[i] & score++ & i++;

// * max_score = 2