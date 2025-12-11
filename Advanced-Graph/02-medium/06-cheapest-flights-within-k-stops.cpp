/*
 * Leetcode - 787
 * Cheapest Flights Within K Stops
 *
 * There are n cities connected by some number of flights. You are given an array flights 
 * where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city from[i] to city to[i] 
 * with cost price[i].
 * 
 * You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
 * If there is no such route, return -1.

 * Example 1  :
 * Input      : n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
 * Output     : 700

 * * Example 2  :
 * * Input      : n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
 * * Output     : 200

 * * Example 3  :
 * * Input      : n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
 * * Output     : 500
 * 
 * * https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * * https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
*/

// ! Meta, Microsoft, Google, Apple, Amazon, Uber

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

typedef std::vector<int> vi;

void printAdjList(std::unordered_map<int, std::vector<std::pair<int, int>>> &adj) {
  std::cout << "Adjacency List" << std::endl;
  for (auto &[u, vec] : adj) {
    std::cout << u << " -> "; 
    for (auto &p: vec) {
      std::cout << "(" << p.first << " " << p.second << ") ";
    }
    std::cout << std::endl;
  }
}

// * ------------------------- Approach 2: Optimal -------------------------
// * BFS + Dijkstra's Algorithm
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int findCheapestPrice(
  int n, 
  int src, int dst, int k,
  std::vector<std::vector<int>> &flights) {

  // * 1. Create a adj list
  std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
  for (auto &data : flights) {
    int from = data[0], to = data[1], cost = data[2];
    adj[from].push_back({to, cost});
  }
  // printAdjList(adj); // * For Debugging

  std::vector<int> dist(n, INT_MAX);
  dist[src] = 0; // * dist to src is 0

  std::queue<std::pair<int, int>> q;
  q.push({src, 0}); // * start bfs from src node
  
  int min_cost = INT_MAX;
  int stops = 0;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [u, cost] = q.front();
      q.pop();
  
      for (auto &[v, cost_to] : adj[u]) {
        int total_cost = cost + cost_to;
        // std::cout << "v: " << v << ", total_cost: " << total_cost << std::endl;
        if (dist[v] > total_cost) {
          dist[v] = total_cost;
          q.push({v, total_cost});
        }
      }
    }
    stops += 1;
    if (stops > k)
      break;
  }
  printArr(dist);

  return dist[dst] == INT_MAX ? -1: dist[dst];
}

int main(void) {
  // * testcase 1
  // int n = 4, src = 0, dst = 3, k = 1;
  // std::vector<std::vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  
  // * testcase 2
  // int n = 3, src = 0, dst = 2, k = 1;
  // std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
  
  // * testcase 3
  // int n = 3, src = 0, dst = 2, k = 0;
  // std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
  
  // * testcase 4
  int n = 5, src = 2, dst = 1, k = 1;
  std::vector<std::vector<int>> flights = {{4, 1, 1}, {1, 2, 3}, {0, 3, 2}, {0, 4, 10}, {3, 1, 1}, {1, 4, 3}};

  std::cout << "src: " << src << ", dst: " << dst << ", k: " << k << std::endl;
  std::cout << "Flights: " << std::endl;
  for (auto &vec : flights)
    printArr(vec);

  int ans = findCheapestPrice(n, src, dst, k, flights);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-cheapest-flights-within-k-stops.cpp -o output && ./output