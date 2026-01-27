/*
 * Leetcode - 2059
 * Minimum Operations to Convert Number
 * 
 * https://leetcode.com/problems/minimum-operations-to-convert-number/description/
*/

#include <queue>
#include <vector>
#include <iostream>

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * BFS
// * N = Size of queue
// * M = size of nums
// * TIME COMPLEXITY O(N x M)
// * SPACE COMPLEXITY O(M)
int minimumOperations(std::vector<int> &nums, int start, int goal) {
  int n = nums.size();

  std::queue<int> q;
  q.push(start);

  std::vector<bool> visited(1001, false);

  int level = 0;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      int u = q.front();
      q.pop();

      if (u == goal)
        return level;

      if (u > 1000 || u < 0 || visited[u])
        continue;

      visited[u] = true;
      for (int i = 0; i < nums.size(); ++i) {
        q.push(u + nums[i]);
        q.push(u - nums[i]);
        q.push(u ^ nums[i]);
      }
    }
    level += 1;
  }

  return -1;
}

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

int main(void) {
  // * testcase 1
  int start = 2, goal = 12;
  std::vector<int> nums = {2, 4, 12};

  // * testcase 2
  // int start = 0, goal = -4;
  // std::vector<int> nums = {3, 5, 7};

  // * testcase 3
  // int start = 0, goal = 1;
  // std::vector<int> nums = {2, 8, 16};

  std::cout << "Start: " << start << ", Goal: " << goal << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  int ans = minimumOperations(nums, start, goal);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 54-minimum-operations-to-convert-number.cpp -o output && ./output