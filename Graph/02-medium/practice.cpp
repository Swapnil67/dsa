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

// * 01 - Number of Provinces
// int findCircleNum(std::vector<std::vector<int>> &isConnected) {
// TODO
// }

// * 02 - Course Schedule
// bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
// TODO
// }

// * 03 - Course Schedule II
// std::vector<int> canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
// TODO
// }

// * 04 - Is Graph Bipartite?
// bool isBipartiteDFS(std::vector<std::vector<int>> &graph) {
// TODO 
// }

// * 05 - Satisfiability of Equality Equations
// bool equationsPossible(std::vector<std::string>& equations) {
// TODO  
// }

// * 06 - Number of Operations to Make Network Connected
// int makeConnected(int n, std::vector<std::vector<int>> &connections) {
// TODO
// }

// * 07 - Count Unreachable Pairs of Nodes in an Undirected Graph
// long long countPairsDSU(int n, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 08 - Number of Islands
// int numIslandsDFS(std::vector<vc>& grid) {
// TODO  
// }

// * 09 - Max Area of Island
// int maxAreaOfIslandDFS(std::vector<std::vector<int>>& grid) {
// TODO
// }

// * 10 - Number of Closed Islands
// int closedIslandDFS(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 11 - Keys and Rooms
// bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
// TODO
// }

// * 12 - Possible Bipartition
// bool possibleBipartition(int n, std::vector<std::vector<int>> &dislikes) {
// TODO
// }

// * 13 - Shortest Path in Weighted undirected graph
// std::vector<int> shortestPath(int m, int n, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 14 - Network Delay Time
// int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
// TODO
// }

// * 15 - Shortest Path in Binary Matrix
// int shortestPathBinaryMatrixBFS(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 16 - Path With Minimum Effort
// int minimumEffortPath(std::vector<std::vector<int>>& heights) {
// TODO
// }

// * 17 - 01 Matrix
// std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
// TODO
// }

// * 18 - As Far from Land as Possible
// int maxDistance(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 19 - Rotting Oranges
// int orangesRotting(std::vector<std::vector<int>>& grid) {
// TODO 
// }

// * 20 - Redundant Connection
// std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 21 - Accounts Merge
// std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts) {
// TODO 
// }

// * 22 - Most Stones Removed with Same Row or Column
// int removeStones(std::vector<std::vector<int>> &stones) {
// TODO 
// }

// * 23 - Maximum Number of Fish in a Grid
// int maxAreaOfIslandDFS2(std::vector<std::vector<int>>& grid) {
// TODO 
// }

// * 24 - Count Servers that Communicate
// int countServers(std::vector<std::vector<int>>& grid) {
// TODO
// }

// * 25 - Clone Graph 
// int countServers(std::vector<std::vector<int>>& grid) {
// TODO (Do this on leetcode)
// }

// * 26 - Map of Highest Peak
// std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& mat) {
// TODO
// }

// * 27 - Find Champion II
// int findChampion(int n, std::vector<std::vector<int>>& edges) {
// TODO
// }

// * 28 - Count Sub Islands
// int countSubIslandsBFS(
//     std::vector<std::vector<int>> &grid1,
//     std::vector<std::vector<int>> &grid2)
// {
// TODO
// }

// * 29 - Reorder Routes to Make All Paths Lead to the City Zero
// int minReorder(int n, std::vector<std::vector<int>>& connections) {
// TODO
// }

// * 30 - Pacific Atlantic Water Flow
// std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
// TODO
// }

// * 31 - Surrounded Regions
// void solve(std::vector<std::vector<char>> &board) {
// TODO
// }

// * 32 - Walls And Gates
// void islandsAndTreasure(std::vector<std::vector<int>>& grid) {
// TODO
// }

// * 33 - Snakes and Ladders
// int snakesAndLadders(std::vector<std::vector<int>>& board) {
// TODO
// }

// * 34 - Find Eventual Safe States
// std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
// TODO
// }

// * 35 - Course Schedule IV
// std::vector<bool> checkIfPrerequisite(
//     int numCourses,
//     std::vector<std::vector<int>> &prerequisites,
//     std::vector<std::vector<int>> &queries)
// {
// TODO
// }

// * 36 - Graph Valid Tree
// bool validTree(
//     int n,
//     std::vector<std::vector<int>> &edges){
// TODO
// }

// * 37 - Check if Move is Legal
// bool validTree(
//     int n,
//     std::vector<std::vector<int>> &edges){
// TODO
// }

// * 38 - Shortest Bridge
// int shortestBridge(std::vector<std::vector<int>>& grid) {
// TODO
// }

// * 39 - Find Closest Node to Given Two Nodes
// int closestMeetingNode(std::vector<int> &edges, int node1, int node2) {
// TODO
// }

// * 40 - Number of Connected Components in an Undirected Graph
// int countComponents(int n, std::vector<int> &edges) {
// TODO
// }

// * 41 - Shortest Path with Alternating Colors
// std::vector<int> shortestAlternatingPaths(
//     int n,
//     std::vector<std::vector<int>> &redEdges,
//     std::vector<std::vector<int>> &blueEdges) 
// {
// TODO
// }

// * 42 - Minimum Fuel Cost to Report to the Capital
// long long minimumFuelCost(
//     int seats,
//     std::vector<std::vector<int>> &roads)
// {
// TODO
// }

// * 43 - Minimum Score of a Path Between Two Cities
// int minScoreDFS(int n, std::vector<std::vector<int>> &roads) {
// TODO
// }

// * 44 - Number of Enclaves
// int numEnclaves(std::vector<std::vector<int>>& grid) {
// TODO
// }

// * 45 - Regions Cut By Slashes
// int regionsBySlashes(std::vector<std::string> &grid) {
// TODO
// }

// * 46 - Minimum Number of Vertices to Reach All Nodes
// std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>> edges) {
// TODO
// }

// * 46 - Count the Number of Complete Components
// int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output