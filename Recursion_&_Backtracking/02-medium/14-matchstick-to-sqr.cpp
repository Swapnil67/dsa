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

// ! Amazon, Google, Meta, Microsoft, Phonepe, Uber

#include <vector>
#include <numeric>
#include <iostream>

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

// * All sides for square should be of same length
bool dfs(vector<int> &matchsticks, vector<int> &sides, int i) {
  // * check if all sides are of same length
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

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(4^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
bool makesquare(vector<int> &matchsticks) {
  int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
  if (sum % 4 != 0)
    return false;

  vector<int> sides(4);
  return dfs(matchsticks, sides, 0);
}

int main(void) {
  // * testcase 1
  // vector<int> matchsticks = {1, 1, 2, 2, 2};
  
  // * testcase 2
  vector<int> matchsticks = {3, 3, 3, 3, 4};

  cout << "Matchsticks";
  printArr(matchsticks);

  bool ans = makesquare(matchsticks);
  cout << "Matchsticks to Square " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 14-matchstick-to-sqr.cpp -o output && ./output