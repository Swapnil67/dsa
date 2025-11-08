/*
 * Leetcode - 743
 * Network Delay Time
 * 
 * You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed
 * edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a
 * signal to travel from source to target.
 * 
 * We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. 
 * If it is impossible for all the n nodes to receive the signal, return -1.

 * Example 1  :
 * Input      : times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * Output     : 2

 * Example 2  :
 * Input      : times = [[1,2,1]], n = 2, k = 1
 * Output     : 1

 * Example 3  :
 * Input      : times = [[1,2,1]], n = 2, k = 2
 * Output     : -1

 * https://leetcode.com/problems/network-delay-time/description/
 * https://www.geeksforgeeks.org/problems/network-delay-time/1
 * https://www.naukri.com/code360/problems/network-delay-time_1382215
*/

// ! Dijkstra Algorithm

// ! Google

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
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

void printAdjList(std::unordered_map<int, std::vector<std::pair<int, int>>> &adj) {
  for (auto &[u, vec] : adj) {
    std::cout << u << " -> "; 
    for (auto &p: vec) {
      std::cout << "(" << p.first << " " << p.second << ") ";
    }
    std::cout << std::endl;
  }
}

typedef std::pair<int, int> pii;

std::unordered_map<int, std::vector<pii>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<pii>> adj;
  if (edges.size() == 0)
    return adj;

  for (auto &vec: edges) {
    if (vec.size() == 0)
      continue;
    int u = vec[0], v = vec[1], w = vec[2];
    adj[u].push_back(std::make_pair(v, w));
  }
  return adj;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Dijkstra Algorithm
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E*Log(V))
// * SPACE COMPLEXITY O(E + V)
int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {

  std::unordered_map<int, std::vector<pii>> adj = constructadj(times);

  // * pair = {distance, {x, y}}
  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap; 
  min_heap.push(std::make_pair(0, k));

  std::vector<int> distance(n + 1, INT_MAX);
  distance[k] = 0;

  while (!min_heap.empty()) {
    int w1 = min_heap.top().first;
    int node = min_heap.top().second;
    min_heap.pop();

    for (auto &p: adj[node]) {
      int v = p.first, w2 = p.second;
      if (distance[v] > w1 + w2) {
        distance[v] = w1 + w2;
        min_heap.push({w1 + w2, v});
      }
    }
  } 

  // printArr(distance);

  // * Return the max distance
  int min_time = INT_MIN;
  for (int i = 1; i <= n; ++i) {
    if (distance[i] == INT_MAX)
      return -1;
    min_time = std::max(min_time, distance[i]);
  }
  return min_time;
}

int main(void) {
  // * testcase 1
  // int k = 2, n = 4;
  // std::vector<std::vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

  // * testcase 2
  // int n = 2, k = 1;
  // std::vector<std::vector<int>> times = {{1, 2, 1}};
  
  // * testcase 3
  int n = 2, k = 2;
  std::vector<std::vector<int>> times = {{1, 2, 1}};

  std::cout << "k: " << k << ", n: " << n << std::endl;
  std::cout << "Times" << std::endl;
  for (auto &vec : times)
    printArr(vec);

  int ans = networkDelayTime(times, n, k);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 14-network-delay-time.cpp -o output && ./output

 