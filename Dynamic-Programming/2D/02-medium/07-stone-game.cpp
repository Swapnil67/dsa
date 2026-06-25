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

  bool even = (r - l + 1) % 2 == 0;
  int left = even ? piles[l] : 0;
  int right = even ? piles[r] : 0;
  return max(left + dfs(l + 1, r, piles), right + dfs(l, r - 1, piles));
}

vector<vector<int>> dp;
int dfs_mem(int l, int r, vector<int> &piles) {
  if (l > r)
    return 0;

  if (dp[l][r] != -1)
    return dp[l][r];

  bool even = (r - l + 1) % 2 == 0;
  int left = even ? piles[l] : 0;
  int right = even ? piles[r] : 0;
  int ans = max(dfs_mem(l + 1, r, piles) + left, dfs_mem(l, r - 1, piles) + right);
  return dp[l][r] = ans;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
bool bruteForce(vector<int> &piles) {
  int n = piles.size();
  // * dfs(l, r, piles)
  return dfs(0, n - 1, piles);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
bool betterApproach(vector<int> &piles) {
  int n = piles.size();
  dp.resize(n, vector<int>(n, -1));
  return dfs_mem(0, n - 1, piles);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
bool stoneGame(vector<int> &piles) {
  int n = piles.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // * Bottom-up DP: Start from the smallest subproblems (single elements)
  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r < n; ++r) {
      if (l == r) {
        dp[l][r] = 0; // * Will always be 0 because length 1 is Bob's turn
      }
      else {
        // * In a game with an EVEN total number of piles (like 4 piles):
        // * - Alice starts when length is 4 (Even)
        // * - Bob plays when length is 3 (Odd)
        // * - Alice plays when length is 2 (Even)
        // * - Bob plays when length is 1 (Odd)
        int remainingCount = r - l + 1;
        bool isAliceTurn = (remainingCount % 2 == 0);
        int leftPoints = isAliceTurn ? piles[l] : 0;
        int rightPoints = isAliceTurn ? piles[r] : 0;
        // * maximum total score Alice can secure for the subarray from index i to j.
        dp[l][r] = max(dp[l + 1][r] + leftPoints, dp[l][r - 1] + rightPoints);
      }
    }
  }

  for (auto &vec : dp)
    printArr(vec);

  int sum = accumulate(begin(piles), end(piles), 0);
  int aliceScore = dp[0][n - 1];
  return aliceScore > sum - aliceScore;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
bool stoneGameDP2(vector<int> &piles) {
  int n = piles.size();
  vector<int> dp(n, 0);

  // * Bottom-up DP: Start from the smallest subproblems (single elements)
  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r < n; ++r) {
      int remainingCount = r - l + 1;

      // * In a game with an EVEN total number of piles (like 4 piles):
      // * - Alice starts when length is 4 (Even)
      // * - Bob plays when length is 3 (Odd)
      // * - Alice plays when length is 2 (Even)
      // * - Bob plays when length is 1 (Odd)
      bool isAliceTurn = (remainingCount % 2 == 0);
      if (l == r) {
        dp[r] = 0; // Will always be 0 because length 1 is Bob's turn
      }
      else {
        int leftPoints = isAliceTurn ? piles[l] : 0;
        int rightPoints = isAliceTurn ? piles[r] : 0;
        dp[r] = max(dp[r] + leftPoints, dp[r - 1] + rightPoints);
      }
    }
  }

  printArr(dp);

  int sum = accumulate(begin(piles), end(piles), 0);
  int aliceScore = dp[n - 1];
  return aliceScore > sum - aliceScore;
}


int main(void) {
  // * testcase 1
  vector<int> piles = {5, 3, 4, 5};

  // * testcase 2
  // vector<int> piles = {1, 2, 3, 4, 5, 100};

  cout << "Piles: ";
  printArr(piles);

  // int ans = bruteForce(piles);
  // int ans = betterApproach(piles);
  // int ans = stoneGame(piles);
  int ans = stoneGameDP2(piles);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 07-stone-game.cpp -o output && ./output


/*
*                                                [5,3,4,5]
*                                        dfs(0, 3) [Rem: 4, Alice]
*                                         Returns: max(5+5, 5+5) = 10
*                                              /               \
*                                             /                 \
*                                            /                   \
*                             dfs(1, 3) [Rem: 3, Bob]            dfs(0, 2) [Rem: 3, Bob]
*                             Returns: max(5, 4) = 5             Returns: max(4, 5) = 5
*                                   /          \                      /          \
*                                  /            \                    /            \
*                    dfs(2, 3) [Alice]     dfs(1, 2) [Alice]   dfs(1, 2) [Alice]     dfs(0, 1) [Alice]
*                  Ret: max(4+0, 5+0)=5      Ret: max(3, 4)=4    Ret: max(3, 4)=4      Ret: max(5, 3)=5
*                        /        \            /        \          /        \            /        \
*                       /          \          /          \        /          \          /          \
*               dfs(3,3)    dfs(2,2)  dfs(2,2)    dfs(1,1)  dfs(2,2)    dfs(1,1)  dfs(1,1)    dfs(0,0)
*                [Bob]       [Bob]     [Bob]       [Bob]     [Bob]       [Bob]     [Bob]       [Bob]
*               Ret: 0      Ret: 0    Ret: 0      Ret: 0    Ret: 0      Ret: 0    Ret: 0      Ret: 0
*                /    \      /    \    /    \      /    \    /    \      /    \    /    \      /    \
*              dfs    dfs  dfs    dfs dfs    dfs  dfs    dfs dfs    dfs  dfs    dfs dfs    dfs  dfs    dfs
*             (4,3)  (3,2)(3,2)  (2,1)(3,2)  (2,1)(2,0)  (1,0)(3,2)  (2,1)(2,0)  (1,0)(2,0)  (1,0)(1,-1) (0,-1)
*              [0]    [0]  [0]    [0]  [0]    [0]  [0]    [0]  [0]    [0]  [0]    [0]  [0]    [0]  [0]   [0]
*/