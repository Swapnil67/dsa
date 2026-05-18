/*
 * Leetcode - 646
 * Maximum Length of Pair Chain
 * 
 * You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
 * 
 * A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
 * 
 * Return the length longest chain which can be formed.
 * You do not need to use up all the given intervals. You can select pairs in any order.
 *
 * Example 1   :
 * Input       :  pairs = [[1,2],[2,3],[3,4]]
 * Output      :  2
 * Explanation : The longest chain is [1,2] -> [3,4].
 *
 * Example 2   :
 * Input       :  pairs = [[1,2],[7,8],[4,5]]
 * Output      :  3
 * Explanation : The longest chain is [1,2] -> [4,5] -> [7,8].
 * 
 * https://leetcode.com/problems/maximum-length-of-pair-chain
 * https://www.geeksforgeeks.org/problems/maximum-length-chain-of-pairs/1
 * https://www.naukri.com/code360/problems/maximum-length-pair-chain_985258
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Uber, Paypal, Bloomberg

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

bool is_increasing(vector<int> &nums) {
  int n = nums.size();
  for (int i = 1; i < n; ++i) {
    if (nums[i - 1] >= nums[i])
      return false;
  }
  return true;
}

// * Recursion Without Memoization
int solve_brute(int i, int prev_idx, vector<vector<int>> &pairs) {
  if (i >= pairs.size())
    return 0;

  int take = 0;
  if (prev_idx == -1 || pairs[prev_idx][1] < pairs[i][0]) {
    take = 1 + solve_brute(i + 1, i, pairs);
  }
  int skip = solve_brute(i + 1, prev_idx, pairs);

  return max(take, skip);
}

// * Recursion With Memoization
// * i - current index
// * pi - previous index
int solve(int i, int pi, vector<vector<int>> &pairs,
          vector<vector<int>> &dp) {
  if (i >= pairs.size())
    return 0;

  if (pi != -1 && dp[i][pi] != -1)
    return dp[i][pi];

  int take = 0;
  if (pi == -1 || pairs[pi][1] < pairs[i][0]) {
    take = 1 + solve(i + 1, i, pairs, dp);
  }
  int skip = solve(i + 1, pi, pairs, dp);

  if (pi != -1)
    dp[i][pi] = max(take, skip);

  return max(take, skip);
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Generate All the subsequences
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n)
int bruteForce(vector<vector<int>> &pairs) {
  sort(begin(pairs), end(pairs));
  int ans = 0;
  solve_brute(0, -1, pairs);
  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int findLongestChain(vector<vector<int>> &pairs) {
  sort(begin(pairs), end(pairs));
  int n = pairs.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return solve(0, -1, pairs, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Dynamic Programming - Bottom Up DP
// * Count of longest increasing subseq at every index in dp array
// * TIME COMPLEXITY O(n * n)
// * SPACE COMPLEXITY O(n)
int findLongestChain2(vector<vector<int>> &pairs) {
  sort(begin(pairs), end(pairs));
  int n = pairs.size();
  vector<int> t(n, 1);

  int max_len = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (pairs[i][0] > pairs[j][1]) {
        t[i] = max(t[i], t[j] + 1);
        max_len = max(max_len, t[i]);
      }
    }
  }

  return max_len;
}

int main(void) {
  // * testcase 1
  vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};

  // * testcase 2
  // vector<vector<int>> pairs = {{1, 2}, {7, 8}, {4, 5}};

  cout << "Input nums: ";
  for (auto &vec : pairs)
    printArr(vec);

  // int ans = bruteForce(pairs);
  int ans = findLongestChain(pairs);
  cout << "Ans: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-longest-increasing-subsequence.cpp -o output && ./output
