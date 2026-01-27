/*
 * Leetcode - 1524
 * Number of Sub-arrays With Odd Sum
 * 
 * Given an array of integers arr, return the number of subarrays with an odd sum.
 * Since the answer can be very large, return it modulo 109 + 7.
 *
 * Eaxmple 1:
 * Input          : arr = [1,3,5]
 * Output         : 4
 * Explanation    : All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 *                  All sub-arrays sum are [1,4,9,3,8,5].
 *                  Odd sums are [1,9,3,5] so the answer is 4.
 * 
 * Eaxmple 2:
 * Input          : arr = [2,4,6]
 * Output         : 0
 * Explanation    : All sub-arrays have even sum and the answer is 0.
 * 
 * Eaxmple 3:
 * Input          : arr = [1,2,3,4,5,6,7]
 * Output         : 16
 * 
 * 
 * https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
 * https://www.naukri.com/code360/problems/number-of-sub-arrays-with-odd-sum_1463156
*/

// ! Amazon

#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int find_next_greater_at_right(std::vector<int> &nums, int idx) {
  int n = nums.size();
  for (int i = n - 1; i > idx + 1; --i) {
    if (nums[i] > nums[idx])
      return i;
  }
  return -1;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> nums) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += nums[j];
      if (cur_sum % 2 != 0)
        ans += 1;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Using Prefix Array
// * Even + Odd = Odd
// * Keep Even & Odd Sub arrays count
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int betterApproach(std::vector<int> &nums) {
  int M = 1e9 + 7;
  int n = nums.size();
  
  // * Create a prefix array
  std::vector<int> prefix(n, 0);
  prefix[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + nums[i];
  }

  int ans = 0, even_cnt = 1, odd_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (prefix[i] % 2 == 0) {
      ans = (ans + odd_cnt) % M; // * Add prev odd count
      even_cnt += 1;
    } else {
      ans = (ans + even_cnt) % M; // * Add prev even count
      odd_cnt += 1;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Prefix Sum Variable
// * Even + Odd = Odd
// * Keep Even & Odd Sub arrays count
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int numOfSubarrays(std::vector<int> &nums) {
  int M = 1e9 + 7;
  int n = nums.size();

  int ans = 0, cur_sum = 0;
  int even_cnt = 1; // * since '0' is even
  int odd_cnt = 0;
  
  for (int i = 0; i < n; ++i) {
    cur_sum += nums[i];
    if (cur_sum % 2 == 0) {
      // * Add previous odd count
      ans = (ans + odd_cnt) % M; 
      even_cnt += 1;
    } else {
      // * Add previous even count
      ans = (ans + even_cnt) % M; 
      odd_cnt += 1;
    }
  }

  return ans;
}

int main() {
  // * testcase 1
  std::vector<int> nums = {1, 3, 5};

  // * testcase 2
  // std::vector<int> nums = {2, 4, 6};

  // * testcase 3
  // std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  std::cout<<"Input Array: ";
  printArr(nums);
  
  // int ans = bruteForce(nums);
  int ans = betterApproach(nums);
  // int ans = numOfSubarrays(nums);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 27-no-of-sub-arrays-with-odd-sum.cpp -o output && ./output
