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
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void solve(std::vector<int> &candidates,
           int i,
           int target,
           std::vector<int> &temp,
           std::vector<std::vector<int>> &ans)
{
  if (target < 0)
    return;
    
  if (target == 0) {
    ans.push_back(temp);
    return;
  }

  if (i >= candidates.size())
    return;

  temp.push_back(candidates[i]);
  solve(candidates, i, target - candidates[i], temp, ans);

  temp.pop_back();
  solve(candidates, i + 1, target, temp, ans);
}


// * ------------------------- Optimal Approach -------------------------`
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^t * k)
// * SPACE COMPLEXITY O(n * k)
std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  solve(candidates, 0, target, temp, ans);
  return ans;
}

int main(void) {
  int target = 7;
  std::vector<int> candidates = {2, 3, 6, 7};
  std::cout << "target: " << target << std::endl;
  printArr(candidates);

  std::vector<std::vector<int>> ans = combinationSum(candidates, target);
  std::cout << "Combination sum: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-combination-sum.cpp -o output && ./output