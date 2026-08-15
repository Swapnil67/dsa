/*
 * Leetcode - 486
 * Predict the Winner
 * 
 * You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
 * 
 * Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 
 * At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1])
 * which reduces the size of the array by 1. 
 * The player adds the chosen number to their score. The game ends when there are no more elements in the array.
 * 
 * Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, 
 * and you should also return true. You may assume that both players are playing optimally.
 * 
 * 
 * Example 1    :
 * Input        : nums = [1,5,2]
 * Output       : false
 * 
 * Example 2    :
 * Input        : nums = [1,5,233,7]
 * Output       : true
 *
 * https://leetcode.com/problems/predict-the-winner/description/ 
*/

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

int dfs(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
	if (i > j)
		return 0;

	if (i == j)
		return nums[i];

	if (dp[i][j] != -1)
		return dp[i][j];

	// * ith for p1 then next possible scores for p1 will be (i + 2, j) or (i + 1, j - 1) 
	int take_left =
	nums[i] + min(dfs(i + 2, j, nums, dp), dfs(i + 1, j - 1, nums, dp));
	
	// * jth for p1 then next possible scores for p1 will be (i + 1, j - 1) or (i, j - 2) 
	int take_right =
			nums[j] + min(dfs(i + 1, j - 1, nums, dp), dfs(i, j - 2, nums, dp));

	return dp[i][j] = max(take_left, take_right);
}

int dfs2(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
	if (i > j)
		return 0;

	if (i == j)
		return nums[i];

	if (dp[i][j] != -1)
		return dp[i][j];

	int take_left = nums[i] - dfs(i + 1, j, nums, dp);

	int take_right = nums[j] - dfs(i, j - 1, nums, dp);

	return dp[i][j] = max(take_left, take_right);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
bool betterApproach(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	int p1 = dfs(0, n - 1, nums, dp);
	int total = accumulate(begin(nums), end(nums), 0);
	int p2 = total - p1;
	return p1 >= p2;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Using diff of score between players
// * Top Down + Memoization
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
bool predictTheWinner(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	return dfs2(0, n - 1, nums, dp) >= 0;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

/*
* If p1 takes from ith index
*
*                       p1 (i + 2, j) 
*                      /  
* p1(i) => p2(i + 1, j)
*                     \ 
*                      p1 (i + 1, j - 1)
*
*
* If p1 takes from jth index
*
*                       p1 (i + 1, j - 1) 
*                      /  
* p1(j) => p2(i, j - 1)
*                     \ 
*                      p1 (i, j - 2)
*
*/