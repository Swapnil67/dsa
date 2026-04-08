/*
 * Leetcode - 47
 * Permutations II
 * 
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 * Example 1
 * input  : nums = [1,1,2]
 * output : [[1,1,2], [1,2,1], [2,1,1]]

 * Example 2
 * input  : nums = [1,2,3]
 * output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * https://leetcode.com/problems/permutations-ii/
*/

#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>

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

void helper_brute(
    vector<int> arr,
    vector<int> &temp,
    set<vector<int>> &st,
    vector<bool> &used)
{
  // * Base case
  if (temp.size() == arr.size()) {
    st.insert(temp);
    return;
  }

  for (int i = 0; i < arr.size(); ++i) {
    // * If not previously taken then take
    if (used[i])
      continue;

    temp.push_back(arr[i]);
    used[i] = true;

    helper_brute(arr, temp, st, used);

    temp.pop_back();
    used[i] = false;
  }
}

void helper(
    vector<int> &arr,
    vector<int> &temp,
    unordered_map<int, int> &freq_map,
    vector<vector<int>> &ans)
{

  // * Base case
  if (temp.size() == arr.size()) {
    ans.push_back(temp);
    return;
  }

  for (auto &[num, cnt] : freq_map) {
    if (cnt <= 0)
      continue;

    freq_map[num]--;
    temp.push_back(num);

    helper(arr, temp, freq_map, ans);

    freq_map[num]++;
    temp.pop_back();
  }
}

// * ------------------------- Brute Force Approach -------------------------
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> bruteForce(vector<int> &nums) {
  int n = nums.size();
  set<vector<int>> nums_set;
  vector<int> temp;
  vector<bool> used(n);
  
  helper_brute(nums, temp, nums_set, used);
  vector<vector<int>> ans(nums_set.begin(), nums_set.end());

  return ans;
}

// * ------------------------- Optimal Approach -------------------------
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n * n!) ~ For output list
vector<vector<int>> permutations(vector<int> &nums) {
  vector<vector<int>> ans;
  
  // * count freq of each num in nums
  unordered_map<int, int> freq_map;
  for (auto &num : nums) {
    freq_map[num]++;
  }
  
  vector<int> temp;
  helper(nums, temp, freq_map, ans);
  return ans;
}

int main(void) {
  vector<int> arr = {1, 1, 2};
  cout << "Input Array: ";
  printArr(arr);

  // vector<vector<int>> ans = bruteForce(arr);
  vector<vector<int>> ans = permutations(arr);
  cout << "Permutations: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-permutations-ii.cpp -o output && ./output