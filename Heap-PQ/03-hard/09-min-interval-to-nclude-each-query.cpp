/*
 * Leetcode - 1851
 * Minimum Interval to Include Each Query
 * 
 * You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at 
 * lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, 
 * or more formally righti - lefti + 1.

 * You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such
 * that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

 * Return an array containing the answers to the queries.

 * Example 1
 * input       : intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
 * output      : [3,3,1,4]

 * Example 2
 * input       : intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
 * output      : [2,-1,4,6]

 * https://leetcode.com/problems/minimum-interval-to-include-each-query/
*/

// ! Google

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}


// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * m = size of queries
// * TIME COMPLEXITY O(n * m)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<std::vector<int>> &intervals,
                            std::vector<int> &queries)
{
  int n = queries.size();
  std::vector<int> ans(n, -1);
  for (int i = 0; i < n; ++i) {
    int cur_query = queries[i];
    int min_size = INT_MAX;
    for (auto &vec : intervals) {
      int cur_size = vec[1] - vec[0] + 1;
      if (cur_query >= vec[0] && cur_query <= vec[1]) {
        min_size = std::min(min_size, cur_size);
      }
    }
    if (min_size != INT_MAX)
      ans[i] = min_size;
  }

  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Min Heap
// * m = size of queries
// * TIME COMPLEXITY O(nlogn + mlogm * nlogm)
// * SPACE COMPLEXITY O(1)
std::vector<int> minInterval(std::vector<std::vector<int>> intervals,
                            std::vector<int> queries)
{
  int n = queries.size(), m = intervals.size();

  // * 1. sort the queries
  std::vector<int> temp_queries = queries;
  std::sort(begin(temp_queries), end(temp_queries));

  // * 2. sort the interval based on left value
  std::sort(begin(intervals), end(intervals));

  // * For debugging
  std::cout << "Intervals: " << std::endl;
  for (auto &vec : intervals)
    printArr(vec);

  // * 3. Create a min heap of {size, right_val}
  typedef std::pair<int, int> pii;
  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;

  std::unordered_map<int, int> mp;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    // * Push all the valid intervals int min_heap
    while (j < m && intervals[j][0] <= temp_queries[i]) {
      int size = intervals[j][1] - intervals[j][0] + 1; // * size = (right - left + 1)
      min_heap.push({size, intervals[j][1]}); // * {size, right}
      j++;
    }

    // * The current query doesn't belongs to the interval
    while (!min_heap.empty() && temp_queries[i] > min_heap.top().second) {
      min_heap.pop();
    }

    // * save the size of current query
    mp[temp_queries[i]] = min_heap.empty() ? -1 : min_heap.top().first;
  }

  // * Form the result using map
  std::vector<int> ans;
  for (auto &x: queries) {
    ans.push_back(mp[x]);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<int> queries = {2, 3, 4, 5};
  // std::vector<std::vector<int>> intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
  
  // * testcase 2
  std::vector<int> queries = {2, 19, 5, 22};
  std::vector<std::vector<int>> intervals = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};

  std::cout << "queries: ";
  printArr(queries);
  // std::cout << "Intervals: " << std::endl;
  // for (auto &vec: intervals) printArr(vec);

  // std::vector<int> ans = bruteForce(intervals, queries);
  std::vector<int> ans = minInterval(intervals, queries);
  std::cout << "Ans: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-min-interval-to-nclude-each-query.cpp -o output && ./output