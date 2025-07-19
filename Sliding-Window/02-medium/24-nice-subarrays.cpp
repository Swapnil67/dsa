
/**
 * * Leetcode - 1248
 * * Count Number of Nice Subarrays
 * * Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
 * * Return the number of nice sub-arrays.

 * * Example 1
 * * Input  : nums = [1,1,2,1,1], k = 3
 * * Output : 2
 * * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

 * * Example 2
 * * Input  : nums = [2,4,6], k = 1
 * * Output : 0
 * * Explanation: There are no odd numbers in the array.

 * * Example 3
 * * Input  : nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * * Output : 16
 * 
 * * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(26)
int bruteForce(std::vector<int> &arr, int k) {
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int odds = 0;
    for (int j = i; j < n; ++j) {
      if (arr[j] % 2 == 1) {
        odds++;
      }
      if (odds == k) {
        ans += (n - j);
        break;
      }
    }
  }
  return ans;
}


int helper(std::vector<int> &nums, int goal) {
  int n = nums.size();
  int ans = 0;
  int i = 0, j = 0, cur_sum = 0;

  while (j < n) {
    cur_sum += (nums[j] % 2);

    while (i <= j && cur_sum > goal) {
      cur_sum -= (nums[i] % 2);
      i++;
    }

    // * add all subarrays from 'i' to 'j'
    ans += (j - i + 1);
    j++;
  }

  return ans;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Similar to binary subarry sum
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int numberOfSubarrays(std::vector<int> &nums, int k) {
  return helper(nums, k) - helper(nums, k - 1);
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Similar to subarray sum equals k
// * Using odd count map
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int numberOfSubarraysB(std::vector<int> &nums, int k) {
  int n = nums.size();
  
  int cur_odd_count = 0, result = 0;
  std::unordered_map<int, int> mp;
  mp[0] = 1;      // * default, we seen 0 odd numbers atleast once

  for(int i = 0; i < n; ++i) {
    cur_odd_count += (nums[i] % 2);

    int rem = cur_odd_count - k;
    if (mp.count(rem)) {
      result += mp[rem];
    }

    mp[cur_odd_count]++;
  }

  // * For debugging
  // for(auto a: mp) {
  //   printf("%d: %d\n", a.first, a.second);
  // }

  return result;
}

int main() {
  // int k = 3;
  // std::vector<int> arr = {1, 1, 2, 1, 1};

  int k = 2;
  std::vector<int> arr = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
  printArr(arr);

  // int ans = numberOfSubarrays(arr, k);
  int ans = numberOfSubarraysB(arr, k);
  std::cout << "Nice subarrays: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 24-nice-subarrays.cpp -o output && ./output
