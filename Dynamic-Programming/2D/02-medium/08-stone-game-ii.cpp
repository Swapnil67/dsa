/*
 * Leetcode - 1140
 * Stone Game II
 * 
 * Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, 
 * and each pile has a positive integer number of stones piles[i].
 * The objective of the game is to end with the most stones.
 * 
 * Alice and Bob take turns, with Alice starting first.
 * 
 * On each player's turn, that player can take all the stones in the first X remaining piles, 
 * where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
 * 
 * The game continues until all the stones have been taken.
 *  
 * Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
 * 
 * https://leetcode.com/problems/stone-game-ii/
 * https://neetcode.io/problems/stone-game-ii/
*/

// ! Amazon, Google, Meta, Uber

#include <vector>
#include <climits>
#include <cstring>
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

int dfs(bool alice, int i, int M, vector<int> &piles) {
  if (i >= piles.size())
    return 0;

  int res = alice ? 0 : INT_MAX;
  int stones = 0;
  for (int x = 1; x <= 2 * M; ++x) {
    if (i + x > piles.size())
      break;

    if (alice) { // * Take Maximum for alice
      stones += piles[i + x - 1];
      res = max(res, stones + dfs(false, i + x, max(M, x), piles));
    } else { // * Take Minimum for bob
      res = min(res, dfs(true, i + x, max(M, x), piles));
    }
  }

  return res;
}

vector<vector<vector<int>>> dp;
int dfs_mem(bool alice, int i, int M, vector<int> &piles) {
  if (i >= piles.size())
    return 0;

  if (dp[alice][i][M] != -1)
    return dp[alice][i][M];

  int res = alice ? 0 : INT_MAX;
  int stones = 0;
  for (int x = 1; x <= 2 * M; ++x) {
    if (i + x > piles.size())
      break;

    if (alice) { // * Take Maximum for alice
      stones += piles[i + x - 1];
      res = max(res, stones + dfs_mem(false, i + x, max(M, x), piles));
    } else { // * Take Minimum for bob
      res = min(res, dfs_mem(true, i + x, max(M, x), piles));
    }
  }

  return dp[alice][i][M] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(n^3)
// * SPACE COMPLEXITY O(n^2)
int bruteForce(vector<int> &piles) {
  int n = piles.size();
  return dfs(true, 0, 1, piles);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int betterApproach(vector<int> &piles) {
  int n = piles.size();
  dp.resize(2, vector<vector<int>> (n + 1, vector<int>(n + 1, -1)));
  return dfs_mem(true, 0, 1, piles);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(n)
int stoneGameII(vector<int> &piles) {
  int n = piles.size();
  return 0;
}


int main(void) {
  // * testcase 1
  vector<int> piles = {2, 7, 9, 4, 4};

  // * testcase 2
  // vector<int> piles = {1, 2, 3, 4, 5, 100};

  cout << "Piles: ";
  printArr(piles);

  int ans = bruteForce(piles);
  // int ans = betterApproach(piles);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 08-stone-game-ii.cpp -o output && ./output
