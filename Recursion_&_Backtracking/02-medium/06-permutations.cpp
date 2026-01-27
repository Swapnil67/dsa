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

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void helper(std::vector<int> arr,
            std::vector<int> &temp,
            std::vector<std::vector<int>> &ans,
            std::vector<bool> &used) {
  // * Base case
  if (temp.size() == arr.size()) {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < arr.size(); ++i) {
    // * If not previously taken then take
    if (used[i])
      continue;

    temp.push_back(arr[i]);
    used[i] = true;

    helper(arr, temp, ans, used);

    temp.pop_back();
    used[i] = false;
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n * n!)
// * SPACE COMPLEXITY O(n * n!)
std::vector<std::vector<int>> permutations(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  std::vector<bool> used(n);
  
  helper(arr, temp, ans, used);
  return ans;
}

int main(void) {
  std::vector<int> arr = {1, 2, 3};
  std::cout << "Input Array: ";
  printArr(arr);

  std::vector<std::vector<int>> ans = permutations(arr);
  std::cout << "Permutations: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-permutations.cpp -o output && ./output