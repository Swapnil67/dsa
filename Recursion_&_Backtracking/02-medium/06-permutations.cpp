/*
 * Leetcode - 46
 * Permutations
 * 
 * Given an array nums of distinct integers, return all the possible permutations. 
 * You can return the answer in any order.

 * Example 1
 * input  : nums = [1,2,3]
 * output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * Example 2
 * input  : nums = [0,1]
 * output : [[0,1],[1,0]]
 * 
 * https://leetcode.com/problems/permutations/
 * https://www.naukri.com/code360/problems/permuatations_892989
 * https://www.naukri.com/code360/problems/permutations-of-a-string_985254
*/

// ! Amazon, Google, Meta, Microsoft, Bloomberg, Apple, Uber, Oracle

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

void helper(vector<int> arr,
            vector<int> &cur,
            vector<vector<int>> &ans,
            vector<bool> &used)
{
  // * Base case
  if (cur.size() == arr.size()) {
    ans.push_back(cur);
    return;
  }

  for (int i = 0; i < arr.size(); ++i) {
    // * If not previously taken then take
    if (used[i])
      continue;

    cur.push_back(arr[i]);
    used[i] = true;

    helper(arr, cur, ans, used);

    cur.pop_back();
    used[i] = false;
  }
}

// * ------------------------- Optimal Approach -------------------------
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n * n!)
vector<vector<int>> permutations(vector<int> &arr) {
  int n = arr.size();
  vector<vector<int>> ans;
  vector<int> cur;
  vector<bool> used(n);
  
  helper(arr, cur, ans, used);
  return ans;
}

int main(void) {

  // * testcase 1
  // vector<int> arr = {1, 2, 3};

  // * testcase 2
  vector<int> arr = {0, 1};

  cout << "Input Array: ";
  printArr(arr);

  vector<vector<int>> ans = permutations(arr);
  cout << "Permutations: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-permutations.cpp -o output && ./output