/*
 * Leetcode - 1584
 * Min Cost to Connect All Points
 * 
 * You are given an array points representing integer coordinates of some points on a 2D-plane,
 * where points[i] = [xi, yi].

 * The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance 
 * between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

 * Return the minimum cost to make all points connected. All points are connected if there is 
 * exactly one simple path between any two points.
 * 
 * Example 1  :
 * Input      : points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * Output     : 20

 * Example 2  :
 * Input      : points = [[3,12],[-2,5],[-4,1]]
 * Output     : 18

 * https://leetcode.com/problems/min-cost-to-connect-all-points/description/
 * https://www.naukri.com/code360/problems/minimum-cost-to-connect-all-points_1381518
 * https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1
*/

// ! MST

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

int prims_algorithm(int &V, std::unordered_map<int, std::vector<pii>> &adj) {
  std::vector<bool> in_mst(V, false);

  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;
  min_heap.push({0, 0});

  int cost = 0;
  while (!min_heap.empty()) {
    auto &[wt, u] = min_heap.top();
    min_heap.pop();

    if (in_mst[u])
      continue;

    in_mst[u] = true;
    cost += wt;

    for (auto &[v, w]: adj[u]) {
      if (!in_mst[v]) {
        min_heap.push({w, v});
      }
    }
  }

  return cost;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E*Log(V))
// * SPACE COMPLEXITY O(E + V)
int minCostConnectPoints(std::vector<std::vector<int>>& points) {

  // * 1. Create an Adj list
  std::unordered_map<int, std::vector<pii>> adj;
  int V = points.size();
  for (int i = 0; i < V; ++i) {
    int x1 = points[i][0], y1 = points[i][1];
    for (int j = i + 1; j < V; ++j) {
      int x2 = points[j][0], y2 = points[j][1];
      int dist = std::abs(x2 - x1) + std::abs(y2 - y1);
      adj[i].push_back({j, dist});
      adj[j].push_back({i, dist});
    }
  }
  printAdjList(adj);

  // * Prims Algo for each node
  int min_cost = prims_algorithm(V, adj);
  return min_cost;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> points = {{3,12},{-2,5},{-4,1}}

  std::cout << "Points" << std::endl;
  for (auto &vec : points)
    printArr(vec);

  int ans = minCostConnectPoints(points);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-min-cost-to-connect-all-points.cpp -o output && ./output

 