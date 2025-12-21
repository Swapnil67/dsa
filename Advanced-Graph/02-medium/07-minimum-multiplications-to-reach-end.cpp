/*
 * Minimum Multiplications to reach End
 *
 * Given start, end and an array arr of n numbers. At each step, start is multiplied with any number 
 * in the array and then mod operation with 100000 is done to get the new start.
 * 
 * Your task is to find the minimum steps in which end can be achieved starting from start.
 * If it is not possible to reach end, then return -1.

 * Example 1  
 * Input           : start = 3, end = 30, nums = {2, 5, 7}
 * Output          : 2
 * Explanation     : Following two steps gets us from start to end
 *                  - Step 1: 3 * 2 = 6 % 100000 = 6 
 *                  - Step 2: 6 * 5 = 30 % 100000 = 30
 * Example 2  
 * Input           : start = 7, end = 66175, nums = {3, 4, 65}
 * Output          : 2
 * Explanation     : Following two steps gets us from start to end
 *                  - Step 1: 7 * 3 = 21 % 100000 = 21 
 *                  - Step 2: 21 * 3 = 63 % 100000 = 63 
 *                  - Step 3: 63 * 65 = 4095 % 100000 = 4095 
 *                  - Step 4: 4095 * 65 = 266175 % 100000 = 66175
 * 
 * * https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

typedef std::pair<int, int> pii;

// * ------------------------- Approach 2: Optimal -------------------------
// * BFS + Dijkstra's Algorithm
// * TIME COMPLEXITY O(100000 * N) (Hypothetical depends on the size of nums array)
// * SPACE COMPLEXITY O(1)
int minimumMultiplications(int start, int end, std::vector<int> nums) {
  int M = 100000;
  std::vector<int> dist(100000, INT_MAX); // * (Given in question)
  dist[start] = 0;

  // * Min heap = {steps, Val}
  std::queue<pii> q;
  q.push({0, start});

  // * BFS
  while (!q.empty()) {
    auto [steps, val] = q.front();
    q.pop();
    std::cout << val << " -> " << steps << std::endl;

    if (val == end)
      return steps;

    for (auto &it : nums) {
      int v = (val * it) % M;
      // std::cout << "    v: " << v << std::endl;

      if (v == end)
        return steps + 1;

      if (dist[v] > steps + 1) {
        dist[v] = steps + 1;
        q.push({steps + 1, v});
      }
    }
  }

  return -1;
}

int main(void) {
  // * testcase 1
  int start = 7, end = 66175;
  std::vector<int> nums = {3, 4, 65};

  // * testcase 2
  // int start = 3, end = 30;
  // std::vector<int> nums = {2, 5, 7};

  std::cout << "start: " << start << ", end: " << end << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  int ans = minimumMultiplications(start, end, nums);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-minimum-multiplications-to-reach-end.cpp -o output && ./output