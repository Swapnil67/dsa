
/**
 * * Leetcode - 713
 * * Subarray Product Less Than K
 * * Given an array of integers nums and an integer k, return the number of contiguous subarrays 
 * * where the product of all the elements in the subarray is strictly less than k.

 * * Example 1
 * * Input  : nums = [10, 5, 2, 6], k = 100
 * * Output : 8
 * * Explanation: The 8 subarrays that have product less than 100 are:
 * * [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
 * * Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

 * * Example 2
 * * Input  : nums = [1, 2, 3], k = 0
 * * Output : 0
 * * Explanation: There are 0 subarray whose product is less than 0
 * 
 * * https://leetcode.com/problems/subarray-product-less-than-k/description/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur_product = 1;
    for (int j = 0; j < n; ++j) {
      cur_product *= arr[j];
      if(cur_product < k) {
        ans++;
      }
      else {
        break;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window
// * (j - i + 1) = no. of subarrays ending at 'j'
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
  int n = nums.size();
  int ans = 0;
  int i = 0, j = 0, cur_product = 1;

  // * since nums has [1 .... 1000]
  if(k <= 1) {    // * k = 0, k = 1;
    return 0;
  }

  while(j < n) {
    cur_product *= nums[j];
    // printf("%d\n", cur_product);

    // * Shrink the window
    while (i < j && cur_product >= k) {
      cur_product /= nums[i];
      i++;
    }

    // * Add all the subarrays b/w 'i' & 'j'
    ans += (j - i + 1);
    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  int k = 100;
  std::vector<int> arr = {10, 5, 2, 6};

  // * testcase 2
  // int k = 0;
  // std::vector<int> arr = {1, 2, 3};

  printf("Product: %d\n", k);
  printf("Input Array\n");
  printArr(arr);  

  // int ans = bruteForce(arr, k);
  int ans = numSubarrayProductLessThanK(arr, k);
  printf("%d Subarrays With product less than %d\n", k, ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-subarry-product-less-than-k.cpp -o output && ./output