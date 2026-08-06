/*
 * Leetcode - 1406
 * Stone Game III
 * 
 * Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, 
 * and each stone has an associated value which is an integer given in the array stoneValue.
 * 
 * Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.
 * 
 * The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.
 * 
 * The objective of the game is to end with the highest score, and the winner is the player with the highest 
 * score and there could be a tie. The game continues until all the stones have been taken.
 * 
 * Assume Alice and Bob play optimally.
 * 
 * Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.
 * 
 * Example 1    :
 * Input        : stoneValue = [1,2,3,7]
 * Output       : Bob
 * 
 * Example 2    :
 * Input        : stoneValue = [1,2,3,-9]
 * Output       : Alice
 * 
 * Example 3    :
 * Input        : stoneValue = [1,2,3,6]
 * Output       : Tie
 * 
 * https://leetcode.com/problems/stone-game-iii/description/
*/

// ! Amazon, Google, Meta, Uber

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

int dfs(int l, int r, vector<int> &piles) {
  if (l > r)
    return 0;

  // * Alice will only play when even piles and we try to maximize that sum
  bool even = (r - l + 1) % 2 == 0;
  int left = even ? piles[l] : 0;
  int right = even ? piles[r] : 0;
  return max(left + dfs(l + 1, r, piles), right + dfs(l, r - 1, piles));
}

int dfs(int i, vector<int> &stoneValue) {
  int n = stoneValue.size();
  if (i >= n)
    return 0;
  int res = INT_MIN, total = 0;
  for (int j = i; j < min(i + 3, n); ++j) {
    total += stoneValue[j];
    res = max(res, total - dfs(j + 1, stoneValue));
  }
  return res;
}

int dfs(int i, vector<int> &stoneValue, vector<int>& dp) {
  int n = stoneValue.size();
  if (i >= n)
    return 0;

  if (dp[i] != INT_MIN)
    return dp[i];

  int res = INT_MIN, total = 0;
  for (int j = i; j < min(i + 3, n); ++j) {
    total += stoneValue[j];
    res = max(res, total - dfs(j + 1, stoneValue, dp));
  }
  return dp[i] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
string bruteForce(vector<int> &stoneValue) {
  int ans = dfs(0, stoneValue);
  if (ans == 0)
    return "Tie";
  return ans > 0 ? "Alice" : "Bob";
}
// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool betterApproach(vector<int> &stoneValue) {
  int n = stoneValue.size();
  vector<int> dp(n + 1, -1);
  int ans = dfs(0, stoneValue);
  if (ans == 0)
    return "Tie";
  return ans > 0 ? "Alice" : "Bob";
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
string stoneGameIII(vector<int>& stoneValue) {
  int n = stoneValue.size();
  vector<int> dp(n + 1, INT_MIN);
  dp[n] = 0;
  for (int i = n - 1; i >= 0; --i) {
    int total = 0;
    dp[i] = INT_MIN;
    for (int j = i; j < min(i + 3, n); j++) {
      total += stoneValue[j];
      dp[i] = max(dp[i], total - dp[j + 1]);
    }
  }
  int ans = dp[0];
  if (ans == 0)
      return "Tie";
  return ans > 0 ? "Alice" : "Bob";
}
  

int main(void) {
  // * testcase 1
  vector<int> stoneValue = {5, 3, 4, 5};

  // * testcase 2
  // vector<int> stoneValue = {1, 2, 3, 4, 5, 100};

  cout << "stoneValue: ";
  printArr(stoneValue);

  // string ans = bruteForce(stoneValue);
  // string ans = betterApproach(stoneValue);
  string ans = stoneGameIII(stoneValue);

  cout << "Winner: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 06-stone-game-iii.cpp -o output && ./output
