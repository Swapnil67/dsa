/*
 * Leetcode - 473
 * Matchsticks to Square
 * 
 * You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
 * You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up,
 * and each matchstick must be used exactly one time.

 * Return true if you can make this square and false otherwise.

 * Example 1
 * input       : matchsticks = [1,1,2,2,2]
 * output      : true

 * Example 2
 * input       : matchsticks = [3,3,3,3,4]
 * output      : false
 * 
 * https://leetcode.com/problems/matchsticks-to-square/description/
*/

#include <vector>
#include <numeric>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

bool dfs(std::vector<int> &matchsticks, std::vector<int> &sides, int i) {
  if (i == matchsticks.size()) {
    return sides[0] == sides[1] &&
           sides[1] == sides[2] &&
           sides[2] == sides[3];
  }

  for (int j = 0; j < 4; ++j) {
    sides[j] += matchsticks[i];

    if (dfs(matchsticks, sides, i + 1))
      return true;

    sides[j] -= matchsticks[i];
  }

  return false;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * Count all possible 'n' length strings 
// * TIME COMPLEXITY O(4^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
bool makesquare(std::vector<int> &matchsticks) {
  int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
  if (sum % 4 != 0)
    return false;

  std::vector<int> sides(4);
  return dfs(matchsticks, sides, 0);
}

int main(void) {
  // * testcase 1
  // std::vector<int> matchsticks = {1, 1, 2, 2, 2};
  
  // * testcase 2
  std::vector<int> matchsticks = {3, 3, 3, 3, 4};

  std::cout << "Matchsticks";
  printArr(matchsticks);

  bool ans = makesquare(matchsticks);
  std::cout << "Matchsticks to Square " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 14-matchstick-to-sqr.cpp -o output && ./output