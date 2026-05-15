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
 * 
*/

// ! MST

// ! Google, Meta, Uber, Microsoft

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

int prims_algorithm(int &V, unordered_map<int, vector<pii>> &adj) {
  vector<bool> in_mst(V, false);

  priority_queue<pii, vector<pii>, greater<>> min_heap;
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

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E*Log(V))
// * SPACE COMPLEXITY O(E + V)
int minCostConnectPoints(vector<vector<int>>& points) {
  // * 1. Create an Adj list
  unordered_map<int, vector<pii>> adj;
  int V = points.size();
  for (int i = 0; i < V; ++i) {
    int x1 = points[i][0], y1 = points[i][1];
    for (int j = i + 1; j < V; ++j) {
      int x2 = points[j][0], y2 = points[j][1];
      int dist = abs(x2 - x1) + abs(y2 - y1);
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
  vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

  // * testcase 2
  // vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};

  cout << "Points" << endl;
  for (auto &vec : points)
    printArr(vec);

  int ans = minCostConnectPoints(points);
  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-min-cost-to-connect-all-points.cpp -o output && ./output

 