/*
 * Leetcode - 1675
 * Minimize Deviation in Array
 * 
 * You are given an array nums of n positive integers.
 * You can perform two types of operations on any element of the array any number of times:

 * If the element is even, divide it by 2.
 * - For example, if the array is [1,2,3,4], then you can do this operation on the last element, 
 *   and the array will be [1,2,3,2].
 * 
 * If the element is odd, multiply it by 2.
 * - For example, if the array is [1,2,3,4], then you can do this operation on the first element, 
 *   and the array will be [2,2,3,4].
 * 
 * The deviation of the array is the maximum difference between any two elements in the array.
 * Return the minimum deviation the array can have after performing some number of operations.

 * Example 1
 * input       : nums = [1,2,3,4]
 * output      : 1
 * Explanation : You can transform the array to [1,2,3,2], then to [2,2,3,2], 
 *               then the deviation will be 3 - 2 = 1.

 * Example 2
 * input       : nums = [4,1,5,20,3]
 * output      : 3
 * Explanation : You can transform the array after two operations to [4,2,5,5,3]
 *               then the deviation will be 5 - 2 = 3.

 * Example 3
 * input       : nums = [2,10,8]
 * output      : 3
 * Explanation : You can transform the array after two operations to [2,5,4]
 *               then the deviation will be 5 - 2 = 3.
 * 
 * https://leetcode.com/problems/find-median-from-data-stream/description/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using min_heap & max_heap
// * n = size of array
// * m = maximum elements in nums
// * TIME COMPLEXITY O(n x logn x logm)
// * SPACE COMPLEXITY O(n)
int minimumDeviation(std::vector<int> &nums) {
  int n = nums.size();
  std::priority_queue<int, std::vector<int>> max_heap;    
  int min_ele = INT_MAX;
  for (auto &x : nums) { // * O(nlogn)
    // * multiply the odd number by '2'
    if (x % 2 != 0)
      x = x * 2;
    min_ele = std::min(min_ele, x); // * keep the min_ele
    max_heap.push(x);
  }

  int ans = INT_MAX;
  // * while top is even no.
  while ((max_heap.top() % 2) == 0) {
    // * get the max ele from heap
    int max_ele = max_heap.top();
    // std::cout << max_ele << " " << min_ele << std::endl;
    max_heap.pop();
    
    // * check the cur min deviation = (max_ele - min_ele)
    ans = std::min(ans, (max_ele - min_ele)); 

    // * check if min_ele changed
    min_ele = std::min(min_ele, (max_ele / 2)); 
    max_heap.push((max_ele / 2));
  }

  return std::min(ans, (max_heap.top() - min_ele));
};

int main(void) {
  // * testcase 1
  // std::vector<int> nums = {1, 2, 3, 4};

  // * testcase 2
  std::vector<int> nums = {4, 1, 5, 20, 3};

  std::cout << "Input Array: " << std::endl;
  printArr(nums);

  int ans = minimumDeviation(nums);
  std::cout << "Minimize Deviation in Array: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-min-deviation-in-arr.cpp -o output && ./output