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

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void helper_brute(std::vector<int> arr,
            std::vector<int> &temp,
            std::set<std::vector<int>> &arr_set,
            std::vector<bool> &used) {
  // * Base case
  if (temp.size() == arr.size()) {
    arr_set.insert(temp);
    return;
  }

  for (int i = 0; i < arr.size(); ++i) {
    // * If not previously taken then take
    if (used[i])
      continue;

    temp.push_back(arr[i]);
    used[i] = true;

    helper_brute(arr, temp, arr_set, used);

    temp.pop_back();
    used[i] = false;
  }
}

void helper(std::vector<int> &arr,
            std::vector<int> &temp,
            std::unordered_map<int, int> freq_map,
            std::vector<std::vector<int>> &ans) {

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
std::vector<std::vector<int>> bruteForce(std::vector<int> &arr) {
  int n = arr.size();
  std::set<std::vector<int>> arr_set;
  std::vector<int> temp;
  std::vector<bool> used(n);
  
  helper_brute(arr, temp, arr_set, used);
  std::vector<std::vector<int>> ans(arr_set.begin(), arr_set.end());

  return ans;
}

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n * n!)
std::vector<std::vector<int>> permutations(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;

  // * count freq of each num in arr
  std::unordered_map<int, int> freq_map;
  for (auto &num : arr) {
    freq_map[num]++;
  }

  helper(arr, temp, freq_map, ans);
  return ans;
}

int main(void) {
  std::vector<int> arr = {1, 1, 2};
  std::cout << "Input Array: ";
  printArr(arr);

  // std::vector<std::vector<int>> ans = bruteForce(arr);
  std::vector<std::vector<int>> ans = permutations(arr);
  std::cout << "Permutations: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-permutations-ii.cpp -o output && ./output