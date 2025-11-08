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

typedef std::pair<int, int> pii;

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

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

