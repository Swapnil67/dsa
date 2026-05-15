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

// ! Amazon, Google, Meta, Microsoft, Bloomberg, Tiktok, Netflix

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

void printAdjList(unordered_map<int, vector<pair<int, int>>> &adj) {
  for (auto &[u, vec] : adj) {
    cout << u << " -> "; 
    for (auto &p: vec) {
      cout << "(" << p.first << " " << p.second << ") ";
    }
    cout << endl;
  }
}

typedef pair<int, int> pii;

unordered_map<int, vector<pii>> constructadj(vector<vector<int>> &edges) {
  unordered_map<int, vector<pii>> adj;
  if (edges.size() == 0)
    return adj;

  for (auto &vec: edges) {
    if (vec.size() == 0)
      continue;
    int u = vec[0], v = vec[1], w = vec[2];
    adj[u].push_back(make_pair(v, w));
  }
  return adj;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Using Dijkstra Algorithm
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E*Log(V))
// * SPACE COMPLEXITY O(E + V)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  unordered_map<int, vector<pii>> adj = constructadj(times);

  // * pair = {distance, v}
  priority_queue<pii, vector<pii>, greater<>> min_heap; 
  min_heap.push(make_pair(0, k));

  vector<int> distance(n + 1, INT_MAX);
  distance[k] = 0;

  // * Go to it's neighbour
  while (!min_heap.empty()) {
    auto [w1, u] = min_heap.top();
    min_heap.pop();

    for (auto &[v, w2]: adj[u]) {
      if (distance[v] > w1 + w2) {
        distance[v] = w1 + w2;
        min_heap.push({w1 + w2, v});
      }
    }
  } 

  // printArr(distance); // * For debugging

  // * Return the max distance
  int min_time = INT_MIN;
  for (int i = 1; i <= n; ++i) {
    if (distance[i] == INT_MAX)
      return -1;
    min_time = max(min_time, distance[i]);
  }
  return min_time;
}

int main(void) {
  std::cout << "Network Delay Time" << std::endl;
  
  // * testcase 1
  int k = 2, n = 4;
  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

  // * testcase 2
  // int n = 2, k = 1;
  // vector<vector<int>> times = {{1, 2, 1}};
  
  // * testcase 3
  // int n = 2, k = 2;
  // vector<vector<int>> times = {{1, 2, 1}};

  cout << "k: " << k << ", n: " << n << endl;
  cout << "Times" << endl;
  for (auto &vec : times)
    printArr(vec);

  int ans = networkDelayTime(times, n, k);
  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-network-delay-time.cpp -o output && ./output

 