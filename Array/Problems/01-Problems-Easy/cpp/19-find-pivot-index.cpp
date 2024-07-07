/**
 * * Find Pivot Index
 * * Given an array of integers nums, calculate the pivot index of this array.
 * * The pivot index is the index where the sum of all the numbers strictly to the left of the index is 
 * * equal to the sum of all the numbers strictly to the index's right.

 * * If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left.
 * * This also applies to the right edge of the array.
 * 
 * * Return the leftmost pivot index. If no such index exists, return -1.

 * * Example 1
 * * Input  : nums = [1,7,3,6,5,6]
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> nums) {
  int n = nums.size();
  int sum = 0, pivotIdx = -1;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    int curSum = 0;
    for (int j = i; j < n; j++) {
      curSum += nums[j];
    }
    // std::cout << curSum << " " << sum << std::endl;
    if(curSum == sum) {
      return i;
    }
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Prefix Sum + Basic Maths
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int findPivotIndex(std::vector<int> nums) {
  int n = nums.size();
  int sum = 0, pivotIdx = -1;

  // * Step 1: Get the total sum of array [O(N)]
  for (int i = 0; i < n; i++) {
    sum += nums[i];
  }

  // * Step 2: Compare curSum with remSum [O(N)] 
  int leftSum = 0;
  for (int i = 0; i < n; i++) {
    int rightSum = sum - (leftSum + nums[i]);
    // std::cout << leftSum << " " << rightSum << std::endl;
    if(rightSum == leftSum) {
      return i;
    }
    leftSum += nums[i];
  }
  return -1;
}

int main() {
  std::vector<int> nums = {1, 2, 3}; // * -1
  // std::vector<int> nums = {2, 1, -1}; // * 0
  // std::vector<int> nums = {1, 7, 3, 6, 5, 6}; // * 3
  printArr(nums);
  int pivotIndex = bruteForce(nums);
  // int pivotIndex = findPivotIndex(nums);
  std::cout << "Pivot Index " << pivotIndex << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 19-find-pivot-index.cpp -o 19-find-pivot-index && ./19-find-pivot-index