/*
 * Leetcode - 1140
 * Stone Game I
 * 
 * Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, 
 * and each pile has a positive integer number of stones piles[i].
 * 
 * The objective of the game is to end with the most stones. The total number of stones across all the piles is odd,
 * so there are no ties.
 * 
 * Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either 
 * from the beginning or from the end of the row. This continues until there are no more piles left, 
 * at which point the person with the most stones wins.
 * 
 * Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.
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

  // * Alice will only play when even piles and we try to maximize that sum
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
  int total = accumulate(piles.begin(), piles.end(), 0);
  int aliceScore = dfs(0, n - 1, piles);
  return aliceScore > total - aliceScore;
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
bool betterApproach(vector<int> &piles) {
  int n = piles.size();
  dp.resize(n, vector<int>(n, -1));
  int total = accumulate(piles.begin(), piles.end(), 0);
  int aliceScore = dfs_mem(0, n - 1, piles);
  return aliceScore > total - aliceScore;
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
      bool even = ((r - l + 1) % 2 == 0);
      int left = even ? piles[l] : 0;
      int right = even ? piles[r] : 0;
      if (l == r) {
        dp[l][r] = left; 
      } else {
        dp[l][r] = max(dp[l + 1][r] + left, dp[l][r - 1] + right);
      }
    }
  }
  
  for (auto &vec : dp)
    printArr(vec);
  // cout << "------------------" << endl;

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
      // * In a game with an EVEN total number of piles (like 4 piles):
      // * - Alice starts when length is 4 (Even)
      // * - Bob plays when length is 3 (Odd)
      // * - Alice plays when length is 2 (Even)
      // * - Bob plays when length is 1 (Odd)
      bool isAliceTurn = ((r - l + 1) % 2 == 0);
      if (l == r) {
        dp[r] = 0; // Will always be 0 because length 1 is Bob's turn
      }
      else {
        int left = isAliceTurn ? piles[l] : 0;
        int right = isAliceTurn ? piles[r] : 0;
        dp[r] = max(dp[r] + left, dp[r - 1] + right);
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
  int ans = stoneGame(piles);
  // int ans = stoneGameDP2(piles);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 07-stone-game.cpp -o output && ./output


/*
*                                     [0,1,2,3]
*                                     [5,3,4,5]
*                                     dfs(0, 3) 
*                                 [even=True, ret=10]
*                                  /            \
*                    Take Left (i+1)             Take Right (j-1)
*                                /                \
*                        dfs(1, 3)                dfs(0, 2)
*                    [even=False, ret=5]      [even=False, ret=5]
*                      /           \            /           \
*                 dfs(2, 3)     dfs(1, 2)   dfs(1, 2)     dfs(0, 1)
*                [even=True,   [even=True,  [even=True,  [even=True,
*                  ret=5]        ret=4]       ret=4]        ret=5]
*                 /     \       /     \      /     \       /     \
*            dfs(3,3) dfs(2,2) dfs(2,2) dfs(1,1) dfs(2,2) dfs(1,1) dfs(1,1) dfs(0,0)
*            [ret=0]  [ret=0]  [ret=0]  [ret=0]  [ret=0]  [ret=0]  [ret=0]  [ret=0]
*
*/