/**
 * * Maximum Product Difference Between Two Pairs
 * * The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
 * * Return the maximum such product difference.

 * * Example 1
 * * Input  : nums = [5,6,2,7,4]
 * * Output: 34
 * * Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
 * * The product difference is (6 * 7) - (2 * 4) = 34.

 * * https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int> findLargestAndSmallest(std::vector<int> arr, int n) {
  int largest = INT_MIN, secondLargest = INT_MIN;
  int smallest = INT_MAX, secondSmallest = INT_MAX;

  for (int i = 0; i < n; i++) {
    if(arr[i] < smallest) {
      secondSmallest = smallest;
      smallest = arr[i];
    }
    else if(arr[i] < secondSmallest) {
      secondSmallest = arr[i];
    }

    if(arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    }
    else if(arr[i] > secondLargest) {
      secondLargest = arr[i];
    }
  }
  return {largest, secondLargest, smallest, secondSmallest};
} 

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// TODO

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Find largest & smallest and second largest & second smallest
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxProductDifference(std::vector<int> arr) {
  int n = arr.size();
  if(n < 4) return -1;

  // * Find largest & Second Largest
  std::vector<int> ans = findLargestAndSmallest(arr, n);
  return (ans[0] * ans[1]) - (ans[2] * ans[3]);
}

int main() {
  std::vector<int> arr = {5, 6, 2, 7, 4};
  int ans = maxProductDifference(arr);
  std::cout << "Max Product difference: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 24-max-product-diff-two-pairs.cpp -o 24-max-product-diff-two-pairs && ./24-max-product-diff-two-pairs