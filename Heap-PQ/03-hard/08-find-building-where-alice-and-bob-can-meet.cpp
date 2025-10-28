/*
 * Leetcode - 2940
 * Find Building Where Alice and Bob Can Meet
 * 
 * You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.
 * If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
 * You are also given another array queries where queries[i] = [ai, bi]. On the ith query, 
 * Alice is in building ai while Bob is in building bi.
 
 * Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query.
 * If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

 * Example 1
 * input       : heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
 * output      : [2,5,-1,5,2]

 * Example 2
 * input       : heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
 * output      : [7,6,-1,4,6]

 * https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/
*/

#include <queue>
#include <vector>
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
// * Nexted Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> &heights,
                            std::vector<std::vector<int>> &queries)
{
  int n = queries.size();
  std::vector<int> ans(n, -1);

  for (int i = 0; i < n; ++i) {
    auto p = queries[i];
    std::sort(begin(p), end(p));
    int l = p[0], r = p[1];

    std::cout << heights[l] << " " << heights[r] << std::endl;

    // * Both are already at same spot
    if (l == r || heights[l] < heights[r]) {
      ans[i] = r;
      continue;
    }
    
    // * Find who is standing on higher building 
    int max_h = std::max(heights[l], heights[r]);

    // * start searching from right most index to last building
    for (int j = r; j <= heights.size(); ++j) {
      std::cout << heights[j] << std::endl;
      if (heights[j] > max_h) {
        ans[i] = j;
        break;
      }
    }

    std::cout << "--------------" << std::endl;
  }

  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> leftmostBuildingQueries(std::vector<int> &heights,
                                         std::vector<std::vector<int>> &queries)
{
#define pii std::pair<int, int>
  int n = queries.size();
  std::vector<int> ans(n, -1);

  // * { 'right_idx': { {'max_h', 'query_idx'} } }
  std::unordered_map<int, std::vector<pii>> groups;
  for (int i = 0; i < n; ++i) {
    int l = queries[i][0], r = queries[i][1];
    if (l == r) {
        ans[i] = r;
    } else if (l < r && heights[l] < heights[r]) {
        ans[i] = r;
    } else if (l > r && heights[l] > heights[r]) {
        ans[i] = l;
    } else {
        groups[std::max(l, r)].push_back({std::max(heights[l], heights[r]), i});
    }
  }

  // * For Debugging
  for (auto &g : groups) {
    std::cout << g.first << std::endl;
    for (auto &gp : g.second) {
      std::cout << "    (" << gp.first << " " << gp.second << ")" << std::endl;
    }
  }

  int m = heights.size();
  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;
  for (int i = 0; i < m; ++i) {

    // * Push all the pair int min_heap 
    for (auto &p: groups[i]) {
      min_heap.push(p);
    }

    while (!min_heap.empty() && heights[i] > min_heap.top().first) {
      ans[min_heap.top().second] = i;
      min_heap.pop();
    }
  }

  return ans;
}


int main(void) {
  // * testcase 1
  std::vector<int> heights = {6, 4, 8, 5, 2, 7};
  std::vector<std::vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
  
  // * testcase 2
  // std::vector<int> heights = {5, 3, 8, 2, 6, 1, 4, 6};
  // std::vector<std::vector<int>> queries = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
  
  // * testcase 3
  // std::vector<int> heights = {2, 1};
  // std::vector<std::vector<int>> queries = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

  std::cout << "Heights: ";
  printArr(heights);
  std::cout << "Queries: " << std::endl;
  for (auto &q : queries)
    printArr(q);

  // std::vector<int> ans = bruteForce(heights, queries);
  std::vector<int> ans = leftmostBuildingQueries(heights, queries);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ -ggdb --std=c++20 08-find-building-where-alice-and-bob-can-meet.cpp -o output && ./output