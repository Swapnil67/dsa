/*
 * Leetcode - 90
 * Subsets II
 * 
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.

 * Example 1
 * input  : nums = [1,2,2]
 * output : [[],[1],[1,2],[1,2,2],[2],[2,2]]

 * Example 2
 * input  : nums = [0]
 * output : [[],[0]]
 * 
 * https://leetcode.com/problems/subsets-ii/description/
 * https://www.naukri.com/code360/problems/unique-subsets_3625236
*/

// ! Contains Duplicates in array.

// ! Amazon, Google, Meta, Microsoft, Apple

#include <set>
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

void helperBrute(
    vector<int> &nums,
    vector<int> temp, int idx,
    set<vector<int>> &ans_set)
{
  if (idx >= nums.size()) {
    ans_set.insert(temp);
    return;
  }

  temp.push_back(nums[idx]);
  helperBrute(nums, temp, idx + 1, ans_set);

  temp.pop_back();
  helperBrute(nums, temp, idx + 1, ans_set);
}


void helper(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &ans) {
  if (i >= nums.size()) {
    ans.push_back(temp);
    return;
  }

  // * All subsets that include nums[i]
  temp.push_back(nums[i]); // * take
  helper(nums, i + 1, temp, ans);


  // * All subsets that don't include nums[i]
  while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
    i += 1;
  }

  temp.pop_back();  // * Not take
  helper(nums, i + 1, temp, ans);
}

// * ------------------------- Brute Force Approach -------------------------`
// * TIME COMPLEXITY  O(n * 2^n)
// * SPACE COMPLEXITY O(2^n)
vector<vector<int>> bruteForce(vector<int> &nums) {
  set<vector<int>> st;
  vector<int> temp;
  helperBrute(nums, temp, 0, st);
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY  O(n * 2^n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> subsets(vector<int> &nums) {
  // ! Important step
  sort(nums.begin(), nums.end()); // * to handle duplicates

  vector<vector<int>> ans;
  vector<int> temp;
  helper(nums, 0, temp, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {1, 2, 2};

  // * testcase 2
  // vector<int> nums = {1, 2, 2, 3};

  cout << "Input nums: ";
  printArr(nums);

  // vector<vector<int>> ans = bruteForce(nums);
  vector<vector<int>> ans = subsets(nums);
  cout << "Subsets: " << endl;
  for (auto &vec : ans)
    printArr(vec);

 return 0;
}

// * Run the code
// * g++ --std=c++20 02-subsets-ii.cpp -o output && ./output