/*
 * Leetcode - 1887
 * Reduction Operations to Make the Array Elements Equal
 * 
 * Given an integer array nums, your goal is to make all elements in nums equal. 
 * To complete one operation, follow these steps:
 * 
 * 1. Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. 
 *    If there are multiple elements with the largest value, pick the smallest i.
 * 
 * 2. Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
 * 3. Reduce nums[i] to nextLargest.

 * Return the number of operations to make all elements in nums equal.

 * Example 1:
 * Input: nums = [5,1,3]
 * Output: 3
 * 
 * Example 2:
 * Input: nums = [1,1,1]
 * Output: 0
 * 
 * Example 3:
 * Input: nums = [1,1,2,2,3]
 * Output: 4

 * https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int reductionOperations(std::vector<int> nums) {
  int n = nums.size();

  int ops = 0;
  std::sort(begin(nums), end(nums));
  int i = n - 1;
  while (i >= 0) {
    // * Add all the prev largest elements to answer
    // * because we will change all the previous(n) larger elements to next larger element (n - 1)
    if (i != 0 && nums[i - 1] < nums[i]) {
      ops += (n - i);
    }
    i--;
  }

  return ops;
}

int main() {
  // * testcase 1
  std::vector<int> nums = {5, 1, 3};

  // * testcase 2
  // std::vector<int> nums = {1, 1, 1};

  // * testcase 3
  // std::vector<int> nums = {1, 1, 2, 2, 3};

  std::cout << "Nums" << std::endl;
  printArr(nums);

  int ans = reductionOperations(nums);
  printf("Ans: %d\n", ans);
  return 0;
}

// * run the code
// * g++ --std=c++20 25-reduction-operations-to-make-the-array-elements-equal.cpp -o output && ./output