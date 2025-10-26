/*
 * Leetcode - 2462
 * Total Cost to Hire K Workers
 * 
 * You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
 * You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

 * - You will run k sessions and hire exactly one worker in each session.
 * - In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last
 *   candidates workers. Break the tie by the smallest index.
 *   - For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th 
 *     worker because they have the lowest cost [3,2,7,7,1,2].
 *   - In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they 
 *     have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
 *     
 * - If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. 
 *   Break the tie by the smallest index.
 *     
 * - A worker can only be chosen once.
 * 
 * Return the total cost to hire exactly k workers.

 * Example 1
 * input  : costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
 * output : 11

 * Example 2
 * input  : costs = [1,2,4,1], k = 3, candidates = 3
 * output : 4
 * 
 * https://leetcode.com/problems/total-cost-to-hire-k-workers/description
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

long long totalCost(std::vector<int> &costs, int k, int candidates) {
  int n = costs.size();
  int i = 0, j = n - 1;
  int total_cost = 0;
  std::priority_queue<int, std::vector<int>, std::greater<>> pq1, pq2;
  while (k > 0) {

    // * Put costs from start in pq1
    while (i <= j && pq1.size() < candidates) {
      pq1.push(costs[i]);
      i++;
    }

    // * Put costs from end in pq2
    while (j >= i && pq2.size() < candidates) {
      pq2.push(costs[j]);
      j--;
    }

    int cost1 = pq1.empty() ? INT_MAX : pq1.top();
    int cost2 = pq2.empty() ? INT_MAX : pq2.top();

    // std::cout << cost1 << "   " << cost2 << std::endl;

    if (cost1 <= cost2) {
      total_cost += cost1;
      pq1.pop();
    } else {
      total_cost += cost2;
      pq2.pop();
    }
    k--;

    // std::cout << "total_cost " << total_cost << std::endl;
  }

  return total_cost;
}

int main(void) {
  // * testcase 1
  // int k = 3, candidates = 4;
  // std::vector<int> cost = {17, 12, 10, 2, 7, 2, 11, 20, 8};
  
  // * testcase 2
  int k = 3, candidates = 3;
  std::vector<int> cost = {1, 2, 4, 1};

  std::cout << "k: " << k << ", candidates: " << candidates << std::endl;
  std::cout << "Costs: ";
  printArr(cost);

  long long ans = totalCost(cost, k, candidates);
  std::cout << "Total Cost to Hire K Workers: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-total-cost-to-hire-k-workers.cpp -o output && ./output