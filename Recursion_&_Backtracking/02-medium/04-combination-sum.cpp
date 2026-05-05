/*
 * Leetcode - 39
 * Combination Sum
 * 
 * Given an array of distinct integers candidates and a target integer target, 
 * return a list of all unique combinations of candidates where the chosen numbers sum to target. 
 * You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times. 
 * Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * 
 * The test cases are generated such that the number of unique combinations that sum up to target is less
 * than 150 combinations for the given input.

 * Example 1
 * input  : candidates = [2,3,6,7], target = 7
 * output : [[2,2,3],[7]]
 * 

 * Example 2
 * input  : candidates = [2,3,5], target = 8
 * output : [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * https://leetcode.com/problems/combination-sum/description/
 * https://www.naukri.com/code360/problems/combination-sum_981296
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Tiktok, Walmart

#include <vector>
#include <iostream>

using namespace std;

void printArr(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

void solve(vector<int> &nums,
           int i,
           int target,
           vector<int> &temp,
           vector<vector<int>> &ans)
{
  if (target == 0) {
    ans.push_back(temp);
    return;
  }

  if (target < 0 || i >= nums.size())
    return;

  temp.push_back(nums[i]);
  solve(nums, i, target - nums[i], temp, ans);

  temp.pop_back();
  solve(nums, i + 1, target, temp, ans);
}

// * ------------------------- Optimal Approach -------------------------
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^t * k)
// * SPACE COMPLEXITY O(n * k)
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> ans;
  vector<int> temp;
  solve(candidates, 0, target, temp, ans);
  return ans;
}

int main(void) {
  
  // * testcase 1
  // int target = 7;
  // vector<int> candidates = {2, 3, 6, 7};

  // * testcase 2
  int target = 14;
  vector<int> candidates = {13, 3, 2, 17};

  cout << "target: " << target << endl;
  cout << "Candidates: ";
  printArr(candidates);

  vector<vector<int>> ans = combinationSum(candidates, target);
  cout << "Combination sum: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-combination-sum.cpp -o output && ./output