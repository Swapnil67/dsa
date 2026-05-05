/*
 * Leetcode - 40
 * Combination Sum II
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target), 
 * find all unique combinations in candidates where the candidate numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 * 
 * Example 1
 * input  : candidates = [10,1,2,7,6,1,5], target = 8
 * output : [[1,1,6], [1,2,5], [1,7], [2,6]]
 * 
 * Example 2
 * input  : candidates = [2,5,2,1,2], target = 5
 * output : [[1,2,2], [5]]
 * 
 * https://leetcode.com/problems/combination-sum-ii/description/
 * https://www.naukri.com/code360/problems/combination-sum-ii_1112622
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Tiktok, Walmart

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printArr(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

// * Using Set DS for avoiding duplicates
void solveBrute(vector<int> &candidates,
                int i,
                int target,
                vector<int> &temp,
                set<vector<int>> &st)
{
  if (target == 0) {
    st.insert(temp);
    return;
  }

  // * Edge Case
  if (target < 0 || i >= candidates.size())
    return;

  temp.push_back(candidates[i]);
  solveBrute(candidates, i + 1, target - candidates[i], temp, st);

  temp.pop_back();
  solveBrute(candidates, i + 1, target, temp, st);
}

// * ------------------------- Brute Force Approach -------------------------
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^t * klogk)
// * SPACE COMPLEXITY O(n * k)
vector<vector<int>> bruteForce(vector<int> &candidates, int target) {
  sort(begin(candidates), end(candidates));
  set<vector<int>> st;
  vector<int> temp;
  solveBrute(candidates, 0, target, temp, st);
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

void solve(
    int i,
    int target,
    vector<int> &nums,
    vector<int> &temp,
    vector<vector<int>> &ans) {
  if (target < 0)
    return;
    
  if (target == 0) {
    ans.push_back(temp);
    return;
  }

  if (i >= nums.size() || nums[i] > target)
    return;

  temp.push_back(nums[i]);
  solve(i + 1, target - nums[i], nums, temp, ans);

  // * To avoid duplicates
  while (i < nums.size() && nums[i] == nums[i + 1]) {
    i += 1;
  }

  temp.pop_back();
  solve(i + 1, target, nums, temp, ans);
}

// * ------------------------- Optimal Approach -------------------------
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  sort(begin(candidates), end(candidates));
  vector<int> temp;
  vector<vector<int>> ans;
  solve(0, target, candidates, temp, ans);
  return ans;
}

int main(void) {
  int target = 8;
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  
  cout << "target: " << target << endl;
  cout << "Candidates: ";
  printArr(candidates);

  // vector<vector<int>> ans = bruteForce(candidates, target);
  vector<vector<int>> ans = combinationSum(candidates, target);
  cout << "Combination sum: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-combination-sum-ii.cpp -o output && ./output