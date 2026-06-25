/*
 * Leetcode - 1140
 * Stone Game I
 * 
 * 
 * https://leetcode.com/problems/stone-game
 * https://neetcode.io/problems/stone-game
*/

// ! Amazon, Google, Meta, Uber

#include <vector>
#include <numeric>
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

int dfs(int i, int total, int &sum, int &target, vector<int> &stones) {
  if (total >= target || i >= stones.size()) {
    return abs(total - (sum - total));
  }

  return min(dfs(i + 1, total, sum, target, stones),
             dfs(i + 1, total + stones[i], sum, target, stones));
}

int dfs(int i, int total, int &sum, int &target, vector<int> &stones,
        vector<vector<int>> &dp) {
  if (total >= target || i >= stones.size()) {
    return abs(total - (sum - total));
  }

  if (dp[i][total] != -1)
    return dp[i][total];

  return dp[i][total] =
             min(dfs(i + 1, total, sum, target, stones, dp),
                 dfs(i + 1, total + stones[i], sum, target, stones, dp));
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
bool bruteForce(vector<int> &stones) {
  int n = stones.size();
  int sum = accumulate(begin(stones), end(stones), 0);
  int target = sum / 2;
  return dfs(0, 0, sum, target, stones);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
bool betterApproach(vector<int> &stones) {
  int sum = accumulate(begin(stones), end(stones), 0);
  int target = sum / 2;
  vector<vector<int>> dp(stones.size() + 1, vector<int>(target + 1, -1));
  return dfs(0, 0, sum, target, stones, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n * target)
// * SPACE COMPLEXITY O(n * target)
bool lastStoneWeightII(vector<int> &stones) {
  int n = stones.size();

  int sum = accumulate(begin(stones), end(stones), 0);
  int target = sum / 2;

  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int t = 1; t <= target; ++t) {
      if (t >= stones[i - 1]) {
        // * This represents the maximum weight you get if you do choose to include the current stone.
        // * stones[i - 1]: The weight of the stone you are taking.
        // * t - stones[i - 1]: The remaining capacity left in your bag after putting this stone in.
        // * dp[i - 1][t - stones[i - 1]]: Look at the previous row to find the absolute best weight you achieved using that exact remaining capacity.
        dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - stones[i - 1]] + stones[i - 1]);
      } else {
        // * This represents the maximum weight you could get without using the current stone.
        dp[i][t] = dp[i - 1][t];
      }
    }
  }

  for (auto &vec : dp)
    printArr(vec);

  return sum - (2 * dp[n][target]);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
bool lastStoneWeightIIDP2(vector<int> &stones) {
  int n = stones.size();
  int sum = accumulate(begin(stones), end(stones), 0);
  int target = sum / 2;
  vector<int> dp(target + 1, 0);
  for (auto stone : stones) {
    for (int t = target; t >= stone; --t) {
      dp[t] = max(dp[t], dp[t - stone] + stone);
    }
  }
  return sum - (2 * dp[target]);
}

int main(void) {
  // * testcase 1
  vector<int> piles = {2, 7, 4, 1, 8, 1};

  // * testcase 2
  // vector<int> piles = {31, 26, 33, 21, 40};

  cout << "Piles: ";
  printArr(piles);

  // int ans = bruteForce(piles);
  // int ans = betterApproach(piles);
  // int ans = lastStoneWeightII(piles);
  int ans = lastStoneWeightIIDP2(piles);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 07-stone-game.cpp -o output && ./output

/*
* Dry Run for lastStoneWeightIIDP2
* Step-by-Step Dry Run

* Turn 1: Stone = 2 (Loop: t from 10 down to 2)
* For all t from 10 down to 2: max(dp[t], dp[t - 2] + 2) --> max(0, 0 + 2) = 2.
* Array after Turn 1: [0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2]
* 
* Turn 2: Stone = 4 (Loop: t from 10 down to 4)
* t = 10 down to 6: max(2, dp[t - 4] + 4) --> max(2, 2 + 4) = 6
* t = 5 down to 4: max(2, dp[t - 4] + 4) --> max(2, 0 + 4) = 4
* Array after Turn 2: [0, 0, 2, 2, 4, 4, 6, 6, 6, 6, 6]
* 
* Turn 3: Stone = 1 (Loop: t from 10 down to 1)
* t = 10: max(6, dp[9] + 1) --> max(6, 6 + 1) = 7
* t = 9 down to 7: Updates similarly by adding 1 to the previous state.
* t = 6: max(6, dp[5] + 1) --> max(6, 4 + 1) = 6 (No change)
* t = 5: max(4, dp[4] + 1) --> max(4, 4 + 1) = 5
* t = 4: max(4, dp[3] + 1) --> max(4, 2 + 1) = 4 (No change)
* t = 3: max(2, dp[2] + 1) --> max(2, 2 + 1) = 3
* t = 2: max(2, dp[1] + 1) --> max(2, 0 + 1) = 2 (No change)
* t = 1: max(0, dp[0] + 1) --> max(0, 0 + 1) = 1
* Array after Turn 3: [0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7]
* 
* Turn 4: Stone = 5 (Loop: t from 10 down to 5)
* t = 10: max(7, dp[5] + 5) --> max(7, 5 + 5) = 10
* t = 9: max(7, dp[4] + 5) --> max(7, 4 + 5) = 9
* t = 8: max(7, dp[3] + 5) --> max(7, 3 + 5) = 8
* t = 7: max(7, dp[2] + 5) --> max(7, 2 + 5) = 7 (No change)
* t = 6: max(6, dp[1] + 5) --> max(6, 1 + 5) = 6 (No change)
* t = 5: max(5, dp[0] + 5) --> max(5, 0 + 5) = 5 (No change)
* Array after Turn 4: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
* 
* Turn 5: Stone = 6 (Loop: t from 10 down to 6)
* t = 10: max(10, dp[4] + 6) --> max(10, 4 + 6) = 10 (No change)
* t = 9: max(9, dp[3] + 6) --> max(9, 3 + 6) = 9 (No change)
* t = 8: max(8, dp[2] + 6) --> max(8, 2 + 6) = 8 (No change)
* t = 7: max(7, dp[1] + 6) --> max(7, 1 + 6) = 7 (No change)
* t = 6: max(6, dp[0] + 6) --> max(6, 0 + 6) = 6 (No change)
* Array after Turn 5: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
* 
* Turn 6: Stone = 3 (Loop: t from 10 down to 3)
* t = 10: max(10, dp[7] + 3) --> max(10, 7 + 3) = 10 (No change)
* t = 9 down to 3: Every single comparison matches its existing value because the array is already perfectly    optimized up to its capacity limits.
* Array after Turn 6: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 
* 
*/