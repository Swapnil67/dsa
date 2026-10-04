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
 * https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1
*/

// ! [confidence 2/5]
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

void dfs(int start, int target, vector<int> &cur, vector<int> &nums, vector<vector<int>> &ans) {
  // * BASE CASE: Success!
  if (target == 0) {
    ans.push_back(cur); // * Save this unique combination
    return;
  }

  // * Loop through all possible candidates starting from the current index 'start'
  for (int i = start; i < nums.size(); ++i) {
    // * 1. SKIP DUPLICATES at the current decision level.
    // * If the current number is the same as the previous number in this loop,
    // * it will generate a duplicate combination branch. We skip it.
    // * 'i > start' ensures we don't accidentally skip an element when
    // * moving down into a deeper recursive call.
    if (i > start && nums[i] == nums[i - 1])
      continue;

    // * 2. EARLY PRUNING (Optimization)
    // * Because the array is sorted, if 'nums[i]' is greater than our remaining target,
    // * all subsequent elements (which are equal or larger) will also exceed the target.
    // * We can break out of the loop early and stop exploring completely.
    if (target - nums[i] < 0)
      break;

    // * 3. EXPLORE: Include nums[i] in the current combination
    cur.push_back(nums[i]);

    // * Move to the next index (i + 1) so we never reuse the exact same element instance.
    dfs(i + 1, target - nums[i], cur, nums, ans);

    // * 4. BACKTRACK: Remove the element to restore state for the next loop iteration
    cur.pop_back();
  }
}

// * ------------------------- Optimal Approach -------------------------
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> ans;
  vector<int> cur;

  // * CRUCIAL STEP: Sorting is mandatory for Combination Sum II!
  // * It allows us to group duplicates together to skip them cleanly,
  // * and enables early loop pruning to make the code run significantly faster.
  sort(candidates.begin(), candidates.end());

  // * Start DFS traversal from index 0
  dfs(0, target, cur, candidates, ans);

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