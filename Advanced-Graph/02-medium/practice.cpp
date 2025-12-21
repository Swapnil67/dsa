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
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

void printAdjList2(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef std::pair<int, int> pii;

// std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
//   std::unordered_map<int, std::vector<int>> adj;
//   for (auto &it: edges) {
//     int u = it[0], v = it[1];
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }
//   return adj;
// }

std::unordered_map<int, std::vector<pii>> constructadj(
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<pii>> adj;
  for (auto &data: edges) {
    int u = data[0], v = data[1], w = data[2];
    adj[u].push_back({v, w});
    // adj[v].push_back({u, w});
  }
  return adj;
}

int find(int x, std::vector<int> &parent) {
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, std::vector<int> &rank, std::vector<int> &parent) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = parent[x_parent];
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = parent[y_parent];
  }
  else {
    parent[x_parent] = parent[y_parent];
    rank[y_parent]++;
  }
}

// * ------------------------------------------------------------------------------------------

// * 01 - Path With Minimum Effort  
// int minimumEffortPath(std::vector<std::vector<int>>& heights) {
// TODO
// }

// * 02 - Network Delay Time
// int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
// TODO
// }

// * 03 - Min Cost to Connect All Points
// int minCostConnectPoints(std::vector<std::vector<int>>& points) {
// TODO
// }

// * 04 - Path with Maximum Probability
// double maxProbability(
//     int n, int start, int end,
//     std::vector<double> succProb,
//     std::vector<std::vector<int>> &edges) {
// TODO 
// }

// * 05 - Find the Safest Path in a Grid
// int maximumSafenessFactor(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 06 - Cheapest Flights Within K Stops
// int findCheapestPrice(
//   int n, 
//   int src, int dst, int k,
//   std::vector<std::vector<int>> &flights) {
// TODO
// }

// * 07 - Minimum Multiplications to reach End
// int minimumMultiplications(int start, int end, std::vector<int> nums) {
// TODO
// }

// * 08 - Number of Ways to Arrive at Destination
// int countPaths(int n, std::vector<std::vector<int>> &roads) {
// TODO
// }

// * 09 - Find the City With the Smallest Number of Neighbors at a Threshold Distance
// int findTheCity(int n, int &distanceThreshold, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 10 - Minimum Cost to Convert String I
// long long minimumCost(
//     std::string source,
//     std::string target,
//     std::vector<char> &original,
//     std::vector<char> &changed,
//     std::vector<int> &cost)
// {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output