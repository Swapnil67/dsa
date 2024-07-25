/**
 * * Maximum Product Difference Between Two Pairs
 * * The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
 * * Return the maximum such product difference.

 * * Example 1
 * * Input  : nums = [5,6,2,7,4]
 * * Output : 3
 * * Explanation: The pivot index is 3.
 * * Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 * * Right sum = nums[4] + nums[5] = 5 + 6 = 11

 * * Example 2
 * * Input  : nums = [1,2,3]
 * * Output : -1
 * * Explanation: There is no index that satisfies the conditions in the problem statement.
 * 
 * * https://leetcode.com/problems/find-pivot-index/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
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


int maxProductDifference(std::vector<int> arr) {
  int n = arr.size();
  if(n < 4) return -1;

  // * Find largest & Second Largest
  std::vector<int> nums = findLargestAndSmallest(arr, n);
  int largest = nums[0]; 
  int secondLargest = nums[1];
  int smallest = nums[2];
  int secondSmallest = nums[3];
  return (largest * secondLargest) - (smallest * secondSmallest);
}

int main() {
  std::vector<int> arr = {5, 6, 2, 7, 4};
  int ans = maxProductDifference(arr);
  std::cout << "Max Product difference: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 24-max-product-diff-two-pairs.cpp -o 24-max-product-diff-two-pairs && ./24-max-product-diff-two-pairs