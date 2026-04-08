/*
 * Leetcode - 78
 * Subsets
 * 
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.

 * Example 1
 * input  : nums = [1,2,3]
 * output : [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

 * Example 2
 * input  : nums = [0]
 * output : [[],[0]]
 * 
 * https://leetcode.com/problems/subsets/description/
*/

// ! Unique elements in array.

// ! Amazon, Google, Meta, Microsoft, Apple, Adobe

#include <vector>
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

// * ------------------------- Optimal Approach -------------------------
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
void helper(int i,
            vector<int> &cur,
            vector<int> &nums,
            vector<vector<int>> &ans)
{
  if (i >= nums.size()) {
    ans.push_back(cur);
    return;
  }

  // * All subsets that include nums[i]
  cur.push_back(nums[i]); // * take
  helper(i + 1, cur, nums, ans);

  // * All subsets that don't include nums[i]
  cur.pop_back(); // * Not take
  helper(i + 1, cur, nums, ans);
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ans;
  vector<int> temp;
  helper(0, temp, nums, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {1, 2, 3};

  // * testcase 2
  // vector<int> nums = {1, 2, 3, 4};

  cout << "Input nums: ";
  printArr(nums);

  vector<vector<int>> ans = subsets(nums);
  cout << "Subsets: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-subsets.cpp -o output && ./output