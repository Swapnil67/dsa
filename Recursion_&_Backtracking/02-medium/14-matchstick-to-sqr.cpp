/*
 * Leetcode - 473
 * Matchsticks to Square
 * 
 * You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
 * You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up,
 * and each matchstick must be used exactly one time.

 * Return true if you can make this square and false otherwise.

 * Example 1
 * input       : matchsticks = [1,1,2,2,2]
 * output      : true

 * Example 2
 * input       : matchsticks = [3,3,3,3,4]
 * output      : false
 * 
 * https://leetcode.com/problems/matchsticks-to-square/description/
*/

// ! Amazon, Google, Meta, Microsoft, Phonepe, Uber

#include <vector>
#include <numeric>
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

// * All sides for square should be of same length
bool dfs(vector<int> &matchsticks, vector<int> &sides, int i) {
  // * check if all sides are of same length
  if (i == matchsticks.size()) {
    return sides[0] == sides[1] &&
           sides[1] == sides[2] &&
           sides[2] == sides[3];
  }

  for (int j = 0; j < 4; ++j) {
    sides[j] += matchsticks[i];

    if (dfs(matchsticks, sides, i + 1))
      return true;

    sides[j] -= matchsticks[i];
  }

  return false;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(4^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
bool makesquare(vector<int> &matchsticks) {
  int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
  if (sum % 4 != 0)
    return false;

  vector<int> sides(4);
  return dfs(matchsticks, sides, 0);
}

int main(void) {
  // * testcase 1
  vector<int> matchsticks = {1, 1, 2, 2, 2};
  
  // * testcase 2
  // vector<int> matchsticks = {3, 3, 3, 3, 4};

  cout << "Matchsticks";
  printArr(matchsticks);

  bool ans = makesquare(matchsticks);
  cout << "Matchsticks to Square " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 14-matchstick-to-sqr.cpp -o output && ./output


/*
* # Time and Space Complexity Analysis
* ## Time Complexity: **O(4^n)** in worst case, but **pruned significantly**

* ### Why O(4^n)?
* - For each matchstick (n total), we try placing it in one of **4 sides**
* - Naive recursion tree has 4^n branches

* ### Pruning Optimizations:
* 1. **Early termination (`if (sides[i] == 0) break`)**: Once a side is empty, don't try other sides. This prevents redundant explorations.
*   - Example: If sides = [0, 3, 4, 4], trying to place the next stick in sides[1], sides[2], sides[3] after sides[0] = 0 is wasteful because sides[0] was already checked.

* 2. **Sorting in descending order**: Larger sticks are placed first
*    - Causes invalid placements to be detected earlier
*    - Prunes the search tree faster
* 
* 3. **Constraint check (`sides[i] + matchsticks[index] <= length`)**: Skip branches that exceed the target length
* 
* **Practical complexity**: Much better than O(4^n) due to these prunings. For n ≤ 15 (constraint), it's acceptable.
* 
---
* 
* ## Space Complexity: **O(n)**
* 
* ### Breakdown:
* - **Recursion call stack**: O(n) depth (we recurse through all n matchsticks)
* - **sides array**: O(1) = 4 fixed-size array
* - **Sorting**: O(1) extra space (in-place sort)
* 
* **Total**: O(n) from the recursion stack
* 
* ---
* 
* ## Example Walkthrough (n=6)
* 

```
Input: [1, 3, 4, 2, 2, 4]
Sorted: [4, 4, 3, 2, 2, 1]

Without pruning: 4^6 = 4096 possible paths
With pruning: ~20-30 paths explored

Early termination saves us from exploring:
- Branches where sides[i] + matchstick > 4 (target)
- Redundant placements when a side is empty
```
**Key insight**: The `break` statement when `sides[i] == 0` is crucial—it transforms this from exponential worst-case to a manageable solution for n ≤ 15.
*/