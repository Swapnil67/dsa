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
#include <algorithm>
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

// * ------------------------- Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> bruteForce(vector<int> &arr) {
  int n = arr.size();
  set<vector<int>> arr_set;
  vector<int> temp;
  vector<bool> used(n);
  
  helper_brute(arr, temp, arr_set, used);
  vector<vector<int>> ans(arr_set.begin(), arr_set.end());

  return ans;
}

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n * n!)
vector<vector<int>> permutations(vector<int> &arr) {
  int n = arr.size();
  vector<vector<int>> ans;
  vector<int> temp;

  // * count freq of each num in arr
  unordered_map<int, int> freq_map;
  for (auto &num : arr) {
    freq_map[num]++;
  }

  helper(arr, temp, freq_map, ans);
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