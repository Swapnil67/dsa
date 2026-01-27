/*
 * Leetcode - 1590
 * Make Sum Divisible by P
 * 
 * Given an array of positive integers nums, remove the smallest subarray (possibly empty) 
 * such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
 * 
 * Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
 * 
 * A subarray is defined as a contiguous block of elements in the array.

 * Example 1:
 * Input: nums = [3,1,4,2], p = 6
 * Output: 1 

 * Example 2:
 * Input: nums = [6,3,5,2], p = 9
 * Output: 2 

 * Example 3:
 * Input: nums = [1,2,3], p = 3
 * Output: 0
 * 
 * https://leetcode.com/problems/make-sum-divisible-by-p/description/
 * https://www.naukri.com/code360/problems/make-sum-divisible-by-p_1466921
*/

#include <vector>
#include <climits>
#include <numeric>
#include <iostream>
#include <unordered_map>

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


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> &nums, int P) {
  int n = nums.size();
  int cnt = 0;

  // * Build the prefix sum array
  std::vector<int> prefix(n, 0);
  prefix[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + nums[i];
  }
  printArr(prefix);

  int total_sum = prefix[n - 1];
  if (total_sum % P == 0)
    return 0;

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      // * Remove sum from i to j from our total_sum
      int remove_subarray_sum = prefix[j] - prefix[i] + nums[i];
      // std::cout << total_sum << " - " << remove_subarray_sum << " = " << total_sum - remove_subarray_sum << std::endl;
      if ((total_sum - remove_subarray_sum) % P == 0) {
        ans = std::min(ans, (j - i + 1));
        break;
      }
    }
    // std::cout << std::endl;
  }

  return ans;
}

int minSubarray(std::vector<int> &nums, int p) {
  int n = nums.size();

  // * Find the total_sum of array
  // * (a + b) % p = (a % p + b % p) % p;
  int total_sum = 0;
  for (auto &num : nums) {
    total_sum = (total_sum + num) % p; // * we are doing this to save space and not using long long
  }
  if (total_sum == 0)
    return 0;

  int target = total_sum;
  std::cout << "target: " << target << std::endl;

  // * mp = {sum, index}
  std::unordered_map<int, int> prefix_mp;
  prefix_mp[0] = -1;

  int cur_sum = 0, ans = n;
  for (int i = 0; i < n; ++i) {
    cur_sum = (cur_sum + nums[i]) % p;
    prefix_mp[cur_sum] = i;

    // * We added plus 'p' to prevent from -ve modulo
    int prev = (cur_sum - target + p) % p; 
    // * Check if we have seen prev sum earlier
    if (prefix_mp.count(prev)) {
      ans = std::min(ans, i - prefix_mp[prev]);
    }
    std::cout << "cur_sum: " << cur_sum << ", prev: " << prev << std::endl;
  }

  // * ans cannot be entire array thats why the following condition
  return ans == n ? -1 : ans;
}

int main(void) {
  // * testcase 1
  int P = 6;
  std::vector<int> nums = {3, 1, 4, 2};

  // * testcase 2
  // int P = 3;
  // std::vector<int> nums = {1, 2, 3};

  // * testcase 3
  // int P = 9;
  // std::vector<int> nums = {6, 3, 5, 2};

  // * testcase  4
  // int P = 0;
  // std::vector<int> nums = {-1, -1, 1};

  std::cout << "K: " << P << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, P);
  int ans = minSubarray(nums, P);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-make-sum-divisible-by-p.cpp -o output && ./output
