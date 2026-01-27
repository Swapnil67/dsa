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

#include <set>
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

// * Using Set DS for avoiding duplicates
void solveBrute(std::vector<int> &candidates,
                int i,
                int target,
                std::vector<int> &temp,
                std::set<std::vector<int>> &st)
{
  if (target < 0)
    return;
    
  if (target == 0) {
    st.insert(temp);
    return;
  }

  if (i >= candidates.size())
    return;

  temp.push_back(candidates[i]);
  solveBrute(candidates, i + 1, target - candidates[i], temp, st);

  temp.pop_back();
  solveBrute(candidates, i + 1, target, temp, st);
}

// * ------------------------- Brute Force Approach -------------------------`
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^t * klogk)
// * SPACE COMPLEXITY O(n * k)
std::vector<std::vector<int>> bruteForce(std::vector<int> &candidates, int target) {
  std::sort(begin(candidates), end(candidates));
  std::set<std::vector<int>> st;
  std::vector<int> temp;
  solveBrute(candidates, 0, target, temp, st);
  std::vector<std::vector<int>> ans(st.begin(), st.end());
  return ans;
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

  if (i >= candidates.size() || candidates[i] > target)
    return;

  temp.push_back(candidates[i]);
  solve(candidates, i + 1, target - candidates[i], temp, ans);

  // * To avoid duplicates
  while (i < candidates.size() && candidates[i] == candidates[i + 1]) {
    i += 1;
  }

  temp.pop_back();
  solve(candidates, i + 1, target, temp, ans);
}

// * ------------------------- Optimal Approach -------------------------`
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
  std::sort(begin(candidates), end(candidates));
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  solve(candidates, 0, target, temp, ans);
  return ans;
}

int main(void) {
  int target = 8;
  std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  
  std::cout << "target: " << target << std::endl;
  std::cout << "Candidates: ";
  printArr(candidates);

  // std::vector<std::vector<int>> ans = bruteForce(candidates, target);
  std::vector<std::vector<int>> ans = combinationSum(candidates, target);
  std::cout << "Combination sum: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-combination-sum-ii.cpp -o output && ./output