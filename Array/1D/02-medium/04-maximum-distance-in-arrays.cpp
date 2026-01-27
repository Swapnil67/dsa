/*
 * Leetcode - 624
 * Maximum Distance in Arrays
 * 
 * maximum sum among all subarrays
 * 
 * Example 1:
 * Input       : arrays = [[1,2,3],[4,5],[1,2,3]]
 * Output      : 4
 * Explanation : One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 
 *              in the second array.
 * 
 * Example 2:
 * Input       : arrays = [[1],[1]]
 * Output      : 0
 * 
 * https://leetcode.com/problems/maximum-distance-in-arrays/description/
 * 
*/

#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * Simple Greedy
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxDistance(std::vector<std::vector<int>> &arr) {
  int n = arr.size();
  int max_dist = 0;
  int MIN = arr[0].front();
  int MAX = arr[0].back();

  for (int j = 1; j < n; ++j) {
    int cur_min = arr[j].front();
    int cur_max = arr[j].back();
    max_dist = std::max(max_dist, std::max(abs(MIN - cur_max),
                                 abs(MAX - cur_min)));

    MIN = std::min(MIN, cur_min);
    MAX = std::max(MAX, cur_max);
  }
  return max_dist;
}

int main() {
  // * testcase 1
  std::vector<std::vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};

  // * testcase 2
  // std::vector<std::vector<int>> arrays = {{1}, {1}};

  int ans = maxDistance(arrays);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-maximum-distance-in-arrays.cpp -o output && ./output