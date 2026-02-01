/*
 * Leetcode - 945
 * Minimum Increment to Make Array Unique
 * 
 * You are given an integer array nums. In one move, you can pick an index i 
 * where 0 <= i < nums.length and increment nums[i] by 1.
 * 
 * Return the minimum number of moves to make every value in nums unique.
 * 
 * The test cases are generated so that the answer fits in a 32-bit integer.
 * 
 * Example 1   :
 * Input       : nums = [1,2,2]
 * Output      : 1
 * Explanation : After 1 move, the array could be [1, 2, 3].
 * 
 * Example 2   :
 * Input       : nums = [3,2,1,2,1,7]
 * Output      : 6
 * Explanation : After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 *               It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
 * 
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}


// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums) {
  // * Sort the input array
  sort(begin(nums), end(nums));

  int n = nums.size();
  int moves = 0;
  for (int i = 1; i < n; ++i) {
    if (nums[i] == nums[i - 1]) {
      moves += 1;
      nums[i] += 1;
    }
    else if (nums[i - 1] > nums[i]) {
      moves += (nums[i - 1] - nums[i] + 1);
      nums[i] = nums[i - 1] + 1;
    }
  }

  return moves;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * Similar to counting sort
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1) 
int minIncrementForUnique(vector<int>& nums) {
  int max_ele = 0;
  for (auto &num: nums) {
    max_ele = max(max_ele, num);
  }
  int n = nums.size();
  std::vector<int> count(n + max_ele, 0);
  for (auto &val: nums) {
    count[val]++;
  }

  int moves = 0;
  for (int i = 0; i < count.size(); ++i) {
    if (count[i] <= 1)
      continue;

    int extra = count[i] - 1; // * Each element should have '1' count
    count[i + 1] += extra;
    count[i] = 1;
    moves += extra;
  }

  return moves;
}

int main(void) {
  // * testcase 1
  vector<int> heights = {1, 2, 2};

  // * testcase 2
  // vector<int> heights = {3, 2, 1, 2, 1, 7};

  // * testcase 3
  // vector<int> heights = {9, 8, 7, 7, 6, 5, 4, 3};

  std::cout << "Input heights: ";
  printArr(heights);
  
  // int ans = bruteForce(heights);
  int ans = minIncrementForUnique(heights);
  std::cout << "Moves: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-min-increment-to-make-array-unique.cpp -o output && ./output
