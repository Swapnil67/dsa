/*
 * Leetcode - 502
 * IPO
 * 
 * Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital,
 * LeetCode would like to work on some projects to increase its capital before the IPO. 
 * Since it has limited resources, it can only finish at most k distinct projects before the IPO. 
 * Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

 * You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of 
 * capital[i] is needed to start it.
 * 
 * Initially, you have w capital. When you finish a project, you will obtain its pure profit and the
 * profit will be added to your total capital.
 * 
 * Pick a list of at most k distinct projects from given projects to maximize your final capital,
 * and return the final maximized capital.
 
 * The answer is guaranteed to fit in a 32-bit signed integer.

 * Example 1
 * input       : k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
 * output      : 4
 * Explanation : Pick project indexed 0. so w = 1
 *               Pick project indexed 2. so w = 1 + 3

 * Example 2
 * input       : k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
 * output      : 6
 * Explanation : Pick project indexed 0. so w = 1
 *               Pick project indexed 1. so w = 1 + 2
 *               Pick project indexed 2. so w = 1 + 2 + 3
 * 
 * https://leetcode.com/problems/ipo/description/
*/

// ! Microsoft

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using min_heap & max_heap
// * TIME COMPLEXITY O(nlogn + nlogn)
// * SPACE COMPLEXITY O(n)
int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital) {
  int n = capital.size();

  // * pair = {capital, profit}
  std::vector<std::pair<int, int>> projects;
  for (int i = 0; i < n; ++i) { // * O(nlogn)
    projects.push_back({capital[i], profits[i]});
  }
  std::sort(projects.begin(), projects.end());

  // * For debugging
  // for (auto &p : projects) {
  //   std::cout << p.first << " " << p.second << std::endl;
  // }

  int i = 0 ;
  std::priority_queue<int> max_heap;
  while (k--) { // * O(nlogn)
    
    // * Push profits of the projects within budget into max_heap
    while (i < n && projects[i].first <= w) {
      max_heap.push(projects[i].second);
      i++;
    }

    if (max_heap.empty())
      break;

    w += max_heap.top(); // * project with most profit
    max_heap.pop();
  }

  return w;
}

int main(void) {
  // * testcase 1
  // int k = 2, w = 0;
  // std::vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};

  // * testcase 2
  int k = 3, w = 0;
  std::vector<int> profits = {1, 2, 3}, capital = {0, 1, 2};

  std::cout << "k: " << k << ", w: " << w << std::endl;
  std::cout << "Profits: ";
  printArr(profits);
  std::cout << "Capital: ";
  printArr(capital);

  int ans = findMaximizedCapital(k, w, profits, capital);
  std::cout << "Final Capital: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-ipo.cpp -o output && ./output