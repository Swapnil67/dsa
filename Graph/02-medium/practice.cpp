#include <queue>
#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

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

// * check out of bound
template <typename T>
bool check_not_oob(const int &row, const int &col, std::vector<std::vector<T>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

std::unordered_map<int, std::vector<pii>> constructadj(
    std::vector<std::vector<int>> &edges) {
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

// * 14 - All Paths From Source to Target
// std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
// TODO
// }

// * 15 - Shortest Path in Binary Matrix
// int shortestPathBinaryMatrixBFS(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 16 - Battleships in a Board
// int countBattleships(std::vector<std::vector<char>>& board) {
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

// * 46 - Minimum Number of Vertices to Reach All Nodes
// std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>> edges) {
// TODO
// }

// * 47 - Count the Number of Complete Components
// int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
// TODO
// }

// * 48 - Detonate the Maximum Bombs
// int maximumDetonationBFS(std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 49 - Find All Possible Recipes from Given Supplies
// std::vector<std::string> findAllRecipes(
//     std::vector<std::string> &recipes,
//     std::vector<std::string> &supplies,
//     std::vector<std::vector<std::string>> &ingredients)
// {
// TODO
// }

// * 50 - Shortest Distance After Road Addition Queries I
// std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>> &queries) {
// TODO
// }

// * 51 - Minimum Height Trees
// vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
// TODO
// }

// * 52 - Path with Maximum Gold
// int getMaximumGold(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 53 - Most Profitable Path in a Tree
// int mostProfitablePath(int bob, std::vector<int> amount, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 54 - Minimum Operations to Convert Number
// int minimumOperations(std::vector<int> &nums, int start, int goal) {
// TODO
// }

// * 55 - Path With Maximum And Minimum Value
// int pathWithMaxMinValue(std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 56 - Shortest Path to Get Food
// int getFood(std::vector<std::vector<char>> &grid) {
// TODO
// }

// * 57 - Open the Lock 
// int openLock(std::vector<std::string> &deadends, std::string target) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output