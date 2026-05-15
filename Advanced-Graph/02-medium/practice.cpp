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
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * Print adjacency list
template <typename T>
void printAdjList(vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    cout << i << " -> ";
    printArr(adj[i]);
  }
}

void printAdjList2(unordered_map<int, vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef pair<int, int> pii;

// unordered_map<int, vector<int>> constructadj(vector<vector<int>> &edges) {
//   unordered_map<int, vector<int>> adj;
//   for (auto &it: edges) {
//     int u = it[0], v = it[1];
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }
//   return adj;
// }

unordered_map<int, vector<pii>> constructadj(
    vector<vector<int>> &edges)
{
  unordered_map<int, vector<pii>> adj;
  for (auto &data: edges) {
    int u = data[0], v = data[1], w = data[2];
    adj[u].push_back({v, w});
    // adj[v].push_back({u, w});
  }
  return adj;
}

int find(int x, vector<int> &parent) {
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &rank, vector<int> &parent) {
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
// int minimumEffortPath(vector<vector<int>>& heights) {
// TODO
// }

// * 02 - Network Delay Time
// int networkDelayTime(vector<vector<int>>& times, int n, int k) {
// TODO
// }

// * 03 - Min Cost to Connect All Points
// int minCostConnectPoints(vector<vector<int>>& points) {
// TODO
// }

// * 04 - Path with Maximum Probability
// double maxProbability(int n, int start, int end, vector<double> succProb, vector<vector<int>> &edges) {
// TODO 
// }

// * 05 - Find the Safest Path in a Grid
// int maximumSafenessFactor(vector<vector<int>> &grid) {
// TODO
// }

// * 06 - Cheapest Flights Within K Stops
// int findCheapestPrice(int n, int src, int dst, int k, vector<vector<int>> &flights) {
// TODO
// }

// * 07 - Minimum Multiplications to reach End
// int minimumMultiplications(int start, int end, vector<int> nums) {
// TODO
// }

// * 08 - Number of Ways to Arrive at Destination
// int countPaths(int n, vector<vector<int>> &roads) {
// TODO
// }

// * 09 - Find the City With the Smallest Number of Neighbors at a Threshold Distance
// int findTheCity(int n, int &distanceThreshold, vector<vector<int>> &edges) {
// TODO
// }

// * 10 - Minimum Cost to Convert String I
// long long minimumCost(
//     string source, string target,
//     vector<char> &original, vector<char> &changed, vector<int> &cost)
// {
// TODO
// }

// * 11 - Minimize the Maximum Edge Weight of Graph
// int minMaxWeight(int n, int threshold, vector<vector<int>> &edges) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output