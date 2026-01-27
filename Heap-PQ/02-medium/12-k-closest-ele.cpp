/**
 * * Leetcode - 658
 * * Find K Closest Elements
 * * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
 * * The result should also be sorted in ascending order.
 * 
 * * An integer a is closer to x than an integer b if:
 * * |a - x| < |b - x|, or
 * * |a - x| == |b - x| and a < b

 * * Example 1
 * * Input: arr = [1, 2, 3, 4, 5], k = 4, x = 3
 * * Output : [1, 2, 3, 4]
 * 
 * * Example 2
 * * Input  :  arr = [1, 1, 2, 3, 4, 5], k = 4, x = -1
 * * Output : [1, 1, 2, 3]
 * 
 * * https://leetcode.com/problems/find-k-closest-elements/description/
*/

#include <queue>
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using max_heap
// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(k)
std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
  int n = arr.size();

  // * max_heap = {diff, num}
  std::priority_queue<std::pair<int, int>> max_heap;

  // * Push the abs diff with 'x' to max_heap
  for (auto &num : arr) {
    max_heap.push({std::abs(num - x), num});
    if (max_heap.size() > k)
      max_heap.pop();
  }

  // * Build the answer array
  std::vector<int> ans;
  while (!max_heap.empty()) {
    std::pair<int, int> p = max_heap.top();
    ans.push_back(p.second);
    max_heap.pop();
  }

  // * sort the ans
  std::sort(ans.begin(), ans.end());

  return ans;
}

int main() {
  // * testcase 1
  int k = 4, x = 3;
  std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 4, x = -1;
  // std::vector<int> arr = {1, 1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 1, x = 9;
  // std::vector<int> arr = {1, 1, 1, 10, 10, 10};

  std::cout << "k: " << k << ", x: " << x << std::endl;
  printf("Input Array: ");
  printArr(arr);

  std::vector<int> ans = findClosestElements(arr, k, x);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-k-closest-ele.cpp -o output && ./output