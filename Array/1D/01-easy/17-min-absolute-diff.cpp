/*
 * Leetcode - 1200
 * Minimum Absolute Difference
 * 
 * Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
 * 
 * Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
 * 
 * - a, b are from arr
 * - a < b
 * - b - a equals to the minimum absolute difference of any two elements in arr
 * 
 * Example 1    :
 * Input        : arr = [4,2,1,3]
 * Output       : [[1,2],[2,3],[3,4]]
 * Explanation  : The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
 * 
 * Example 2    :
 * Input        : arr = [1,3,6,10,15]
 * Output       : [[1,3]]
 * 
 * Example 3    :
 * Input        : arr = [3,8,-10,23,19,-4,-14,27]
 * Output       : [[-14,-10],[19,23],[23,27]]
 * 
 * https://leetcode.com/problems/minimum-absolute-difference/description/
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

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr) {
  int n = arr.size();

  // * Step 1. Sort the input array
  std::sort(begin(arr), end(arr));

  // * Step 2. Find the mininum abs diff pair from array
  int min_dist = abs(arr[1] - arr[0]);
  for (int i = 1; i < n - 1; ++i) {
    int dist = abs(arr[i + 1] - arr[i]);
    min_dist = std::min(min_dist, dist);
  }
  // std::cout << min_dist << std::endl;

  // * Step 3. Find all possible pairs with same abs diff as min_dist
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n - 1; ++i) {
    int dist = abs(arr[i + 1] - arr[i]);
    if (dist == min_dist) {
      ans.push_back({arr[i], arr[i + 1]});
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<int> arr = {4, 2, 1, 3};

  // * testcase 2
  // std::vector<int> arr = {1, 3, 6, 10, 15};

  // * testcase 3
  // std::vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};

  std::cout << "Input Array: ";
  printArr(arr);

  std::vector<std::vector<int>>  ans = minimumAbsDifference(arr);
  std::cout << "Pairs" << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 17-min-absolute-diff.cpp -o output && ./output
