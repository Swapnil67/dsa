/*
 * Leetcode - 2563
 * Count the Number of Fair Pairs
 * 
 * Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
 * 
 * A pair (i, j) is fair if:
 *  0 <= i < j < n, and
 *  lower <= nums[i] + nums[j] <= upper
 * 
 * Example 1:
 * Input       : nums = [0,1,7,4,4,5], lower = 3, upper = 6
 * Output      : 6
 * Explanation : There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
 * 
 * Example 2:
 * Input       : nums = [1,7,9,2,5], lower = 11, upper = 11
 * Output      : 1
 * Explanation : There is a single fair pair: (2,3).
 * 
 * https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
 */

// ! Google, Amazon

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

typedef long long ll;

ll lowerBound(std::vector<int> &nums, int target, int l , int r) {
  int n = nums.size();
  int ans = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] >= target) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

ll upperBound(std::vector<int> &nums, int target, int l , int r) {
  int n = nums.size();
  int ans = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] > target) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

ll helper(std::vector<int> &nums, int target) {
  ll l = 0, r = nums.size() - 1;
  ll sum = 0;
  while (l < r) {
    if (nums[l] + nums[r] <= target) {
      sum += (r - l);
      l++;
    }
    else {
      r--;
    }
  }
  return sum;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(1)
long long bruteForce(std::vector<int> nums, int lower, int upper) {
  int n = nums.size();
  int pairs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = nums[i] + nums[j];
      if (lower <= sum && sum <= upper) {
        pairs++;
      }
    }
  }
  return pairs;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Sorting + Binary Search
// * lower <= nums[i] + nums[j] <= upper
// * TIME COMPLEXITY O(n * log(n))
// * SPACE COMPLEXITY O(1)
ll countFairPairs(std::vector<int> nums, int lower, int upper) {
  // * sort the input array
  std::sort(nums.begin(), nums.end());

  int n = nums.size();
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    std::cout << "nums[i] = " << nums[i] << std::endl;

    // * Count how many numbers are < than lower - nums[i]
    long long lb = lowerBound(nums, lower - nums[i], i + 1, n - 1);
    lb = lb - i;

    // * Count how many numbers are <= than upper - nums[i]
    long long ub = upperBound(nums, upper - nums[i], i + 1, n - 1);
    ub = ub - i;

    // * Using SDL
    // int idx = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) - begin(nums);
    // int lb = idx - 1 - i;
    // idx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) - begin(nums);
    // int ub = idx - 1 - i;

    std::cout << "lower bound: " << lb << " & upper bound: " << ub << std::endl;
    std::cout << "----------------------------" << std::endl;

    ans += (ub - lb);
  }
  return ans;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * Two Pointer Approach
// * Intuition
// *                  Lower                                                 Upper 
// * ----------------------------------------------------------------------------
// * <------------------------------- Red --------------------------------------->
// * <------ blue ------->
// *                     <========================= Orange ======================>
// * Orange = Red - Blue
// * SPACE COMPLEXITY O(1)
ll countFairPairs2(std::vector<int> nums, int lower, int upper) {
  std::sort(nums.begin(), nums.end());
  return helper(nums, upper) - helper(nums, lower - 1);
}

int main(void) {
  int lower = 3, upper = 6;
  std::vector<int> nums = {0, 1, 7, 4, 4, 5};

  // int lower = 11, upper = 11;
  // std::vector<int> nums = {1, 7, 9, 2, 5};

  // int lower = 8, upper = 13;
  // std::vector<int> nums = {1, 4, 5, 1, 7, 4, 20};

  std::cout << "Lower: " << lower << " & Upper: " << upper << std::endl;
  printArr(nums);

  // long long pairs = bruteForce(nums, lower, upper);
  long long pairs = countFairPairs(nums, lower, upper);
  // long long pairs = countFairPairs2(nums, lower, upper);
  std::cout << "Fair Pairs: " << pairs << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-count-fair-pairs.cpp -o output && ./output

