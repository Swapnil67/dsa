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
 * https://www.naukri.com/code360/problems/combination-sum_981296
 * https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1
*/

// ! [confidence 5/5]
// ! Amazon, Google, Meta, Microsoft, Apple, Tiktok, Walmart

#include <vector>
#include <iostream>

using namespace std;

void printArr(vector<int> arr) {
  cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;
}

void dfs(int i, int target, vector<int> &cur, vector<int> &nums, vector<vector<int>> &ans) {
  // * BASE CASE 1: Success!
  // * We successfully reduced the target to 0, meaning the numbers
  // * in 'cur' sum up exactly to the original target.
  if (target == 0) {
    ans.push_back(cur); // * Save a copy of this valid combination
    return;             // * Backtrack to explore other paths
  }

  // * BASE CASE 2: Out of Bounds
  // * If our pointer 'i' moves past the last element of 'nums',
  // * we have no more numbers left to choose from.
  if (i >= nums.size())
    return; // * Backtrack

  // * CHOICE 1: EXCLUDE the current number (nums[i])
  // * We decide not to pick the current element.
  // * We move to the next index (i + 1) while keeping the 'target' the same.
  dfs(i + 1, target, cur, nums, ans);

  // * CHOICE 2: INCLUDE the current number (nums[i])
  // * We can only pick this number if it doesn't exceed our remaining target.
  if (target - nums[i] >= 0) {
    // * 1. Take the element: add it to our current combination
    cur.push_back(nums[i]);

    // * 2. Explore: Move deeper into the recursion tree.
    // * Crucial point: We pass 'i' (instead of i + 1) because we can
    // * reuse this exact same number an infinite number of times.
    // * We also subtract its value from our remaining 'target'.
    dfs(i, target - nums[i], cur, nums, ans);

    // * 3. Backtrack: Remove the element we just added
    // * so we can clean up the state before moving to other branches.
    cur.pop_back();
  }
}

// * ------------------------- Optimal Approach -------------------------
// * - 'n' = no. of elements in the input candidates array
// * - 't' = target sum (The maximum depth occurs when we repeatedly pick the smallest number in the array (target / min_val))
// * - 'k' = is the average length of the combinations (temp array)
// * TIME COMPLEXITY O(2^t * k)
// * SPACE COMPLEXITY O(n * k)
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> ans; // * Stores all valid unique combinations
  vector<int> cur;         // * Temporary list to build individual combinations

  // * Start our Depth-First Search (DFS) from index 0
  dfs(0, target, cur, candidates, ans);

  return ans;
}

int main(void) {
  
  // * testcase 1
  // int target = 7;
  // vector<int> candidates = {2, 3, 6, 7};

  // * testcase 2
  int target = 14;
  vector<int> candidates = {13, 3, 2, 17};

  cout << "target: " << target << endl;
  cout << "Candidates: ";
  printArr(candidates);

  vector<vector<int>> ans = combinationSum(candidates, target);
  cout << "Combination sum: " << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-combination-sum.cpp -o output && ./output

/*
* candidates = [2, 3], target = 4

*                                dfs(0, 4)  [i=0, val=2]
*                               /        \
*                              /          \
*                 (Exclude 2) /            \ (Include 2)
*                            /              \
*                    dfs(1, 4)               dfs(0, 2)  [i=0, val=2]
*                   [i=1, val=3]            /        \
*                   /          \           /          \
*       (Exclude 3)/ (Include 3)\         /            \
*                 /              \       /              \
*            dfs(2, 4)       dfs(1, 1) dfs(1, 2)       dfs(0, 0) 
*             (i >= size)    [i=1, val=3] [i=1, val=3]   (target == 0)
*               [X]          /      \     /      \          [✓]
*                           /        \   /        \       Saved: [2, 2]
*                      dfs(2, 1)     [X]dfs(2, 2)  [X]
*                      (i >= size)   (tgt-val<0)(i >= size)(tgt-val<0)
*                        [X]                     [X]

*/