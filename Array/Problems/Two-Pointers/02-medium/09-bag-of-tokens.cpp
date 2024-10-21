/**
 * * Bag of Tokens
 * * You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, 
 * * where each tokens[i] denotes the value of tokeni.
 * * Your goal is to maximize the total score by strategically playing these tokens. In one move, 
 * * you can play an unplayed token in one of the two ways (but not both for the same token):
 * 
 * * Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
 * * Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
 * 
 * * Return the maximum possible score you can achieve after playing any number of tokens.

 * * Example 1
 * * Input  : [100], power = 50
 * * Output : 0
 * 
 * * Example 2
 * * Input  : tokens = [200,100], power = 150
 * * Output : 1
 * 
 * * Example 3
 * * Input  : tokens = [100,200,300,400], power = 200
 * * Output : 2

 * * https://leetcode.com/problems/bag-of-tokens/description/
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int bagOfTokensScore(std::vector<int> tokens, int power) {

  // * sort the tokens
  std::sort(tokens.begin(), tokens.end()); 
  int n = tokens.size();
  int i = 0, j = n - 1;

  int score = 0;
  int max_score = 0; // * initially

  while(i <= j) {
    std::cout << power << std::endl;
    if(power >= tokens[i]) {
      power -= tokens[i];
      score += 1;
      i++;
      max_score = std::max(max_score, score);
    }
    else if (score >= 1) {
      power += tokens[j];
      j--;
      score -= 1;
    }
    else {
      return max_score;
    }
  }
  return max_score;
}

int main() {
  // int power = 200;
  // std::vector<int> tokens = {100, 200, 300, 400};
  int power = 150;
  std::vector<int> tokens = {200, 100};
  std::cout << "Power " << power << std::endl;
  std::cout<<"Tokens ";
  printArr(tokens);
  int ans = bagOfTokensScore(tokens, power);
  std::cout << "Max Score " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-bag-of-tokens.cpp -o output && ./output