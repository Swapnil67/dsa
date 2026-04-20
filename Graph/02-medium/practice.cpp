#include <queue>
#include <vector>
#include <numeric>
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

void printAdjList(unordered_map<int, vector<pii>> &adj) {
  for (auto &[key, pairs] : adj) {
    cout << key << " -> ";
    for (auto &it: pairs) {
      cout << "(" << it.first << ", " << it.second << ") ";
    }
    cout << endl;
  }
}

const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef pair<int, int> pii;

// * check out of bound
template <typename T>
bool check_not_oob(const int &row, const int &col, vector<vector<T>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

unordered_map<int, vector<pii>> constructadj(
    vector<vector<int>> &edges) {
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

// * 42 - Minimum Fuel Cost to Report to the Capital
// long long minimumFuelCost(int seats, vector<vector<int>> &roads) {
// TODO
// }

// * 43 - Minimum Score of a Path Between Two Cities
// int minScoreDFS(int n, vector<vector<int>> &roads) {
// TODO
// }

// * 44 - Number of Enclaves
// int numEnclaves(vector<vector<int>>& grid) {
// TODO
// }

// * 45 - Regions Cut By Slashes
// int regionsBySlashes(vector<string> &grid) {
// TODO
// }

// * 46 - Minimum Number of Vertices to Reach All Nodes
// vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> edges) {
// TODO
// }

// * 47 - Count the Number of Complete Components
// int countCompleteComponents(int n, vector<vector<int>>& edges) {
// TODO
// }

// * 48 - Detonate the Maximum Bombs
// int maximumDetonationBFS(vector<vector<int>> &edges) {
// TODO
// }

// * 49 - Find All Possible Recipes from Given Supplies
// vector<string> findAllRecipes(
//     vector<string> &recipes,
//     vector<string> &supplies,
//     vector<vector<string>> &ingredients)
// {
// TODO
// }

// * 50 - Shortest Distance After Road Addition Queries I
// vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
// TODO
// }

// * 51 - Minimum Height Trees
// vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
// TODO
// }

// * 52 - Path with Maximum Gold
// int getMaximumGold(vector<vector<int>> &grid) {
// TODO
// }

// * 53 - Most Profitable Path in a Tree
// int mostProfitablePath(int bob, vector<int> amount, vector<vector<int>> &edges) {
// TODO
// }

// * 54 - Minimum Operations to Convert Number
// int minimumOperations(vector<int> &nums, int start, int goal) {
// TODO
// }

// * 55 - Path With Maximum And Minimum Value
// int pathWithMaxMinValue(vector<vector<int>> &grid) {
// TODO
// }

// * 56 - Shortest Path to Get Food
// int getFood(vector<vector<char>> &grid) {
// TODO
// }

// * 57 - Open the Lock 
// int openLock(vector<string> &deadends, string target) {
// TODO
// }

// * ------------------------------------------------------------------------------------------

// * 01 - Number of Provinces
// int findCircleNum(vector<vector<int>> &isConnected) {
// TODO
// }

// * 02 - Course Schedule
// bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
// TODO
// }

// * 03 - Course Schedule II
// vector<int> canFinish(int numCourses, vector<vector<int>> &prerequisites) {
// TODO
// }

// * 04 - Is Graph Bipartite?
// bool isBipartiteDFS(vector<vector<int>> &graph) {
// TODO 
// }

// * 05 - Satisfiability of Equality Equations
// bool equationsPossible(vector<string>& equations) {
// TODO  
// }

// * 06 - Number of Operations to Make Network Connected
// int makeConnected(int n, vector<vector<int>> &connections) {
// TODO
// }

// * 07 - Count Unreachable Pairs of Nodes in an Undirected Graph
// long long countPairsDSU(int n, vector<vector<int>> &edges) {
// TODO
// }

// * 08 - Number of Islands
// int numIslandsDFS(vector<vc>& grid) {
// TODO  
// }

// * 09 - Max Area of Island
// int maxAreaOfIslandDFS(vector<vector<int>>& grid) {
// TODO
// }

// * 10 - Number of Closed Islands
// int closedIslandDFS(vector<vector<int>> &grid) {
// TODO
// }

// * 11 - Keys and Rooms
// bool canVisitAllRooms(vector<vector<int>>& rooms) {
// TODO
// }

// * 12 - Possible Bipartition
// bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
// TODO
// }

// * 13 - Shortest Path in Weighted undirected graph
// vector<int> shortestPath(int m, int n, vector<vector<int>> &edges) {
// TODO
// }

// * 14 - All Paths From Source to Target
// vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
// TODO
// }

// * 15 - Shortest Path in Binary Matrix
// int shortestPathBinaryMatrixBFS(vector<vector<int>> &grid) {
// TODO
// }

// * 16 - Battleships in a Board
// int countBattleships(vector<vector<char>>& board) {
// TODO
// }

// * 17 - 01 Matrix
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
// TODO
// }

// * 18 - As Far from Land as Possible
// int maxDistance(vector<vector<int>> &grid) {
// TODO
// }

// * 19 - Rotting Oranges
// int orangesRotting(vector<vector<int>>& grid) {
// TODO
// }

// * 20 - Redundant Connection
// vector<int> findRedundantConnection(vector<vector<int>> &edges) {
// TODO
// }

// * 21 - Accounts Merge
// vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
// TODO
// }

// * 22 - Most Stones Removed with Same Row or Column
// int removeStones(vector<vector<int>> &stones) {
// TODO
// }

// * 23 - Maximum Number of Fish in a Grid
// int maxAreaOfIslandDFS2(vector<vector<int>>& grid) {
// TODO 
// }

// * 24 - Count Servers that Communicate
// int countServers(vector<vector<int>>& grid) {
// TODO
// }

// * 25 - Clone Graph 
// int countServers(vector<vector<int>>& grid) {
// TODO (Do this on leetcode)
// }

// * 26 - Map of Highest Peak
// vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
// TODO
// }

// * 27 - Find Champion II
// int findChampion(int n, vector<vector<int>>& edges) {
// TODO
// }

// * 28 - Count Sub Islands
// int countSubIslandsBFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
// {
// TODO
// }

// * 29 - Reorder Routes to Make All Paths Lead to the City Zero
// int minReorder(int n, vector<vector<int>>& connections) {
// TODO
// }

// * 30 - Pacific Atlantic Water Flow
// vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
// TODO
// }

// * 31 - Surrounded Regions
// void solve(vector<vector<char>> &board) {
// TODO
// }

// * 32 - Walls And Gates
// void islandsAndTreasure(vector<vector<int>>& grid) {
// TODO
// }

// * 33 - Snakes and Ladders
// int snakesAndLadders(vector<vector<int>>& board) {
// TODO
// }

// * 34 - Find Eventual Safe States
// vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
// TODO
// }

// * 35 - Course Schedule IV
// vector<bool> checkIfPrerequisite(
//     int numCourses,
//     vector<vector<int>> &prerequisites,
//     vector<vector<int>> &queries)
// {
//   TODO
// }

// * 36 - Graph Valid Tree
// bool validTree(int n, vector<vector<int>> &edges){
// TODO
// }

// * 37 - Check if Move is Legal
// bool validTree(int n, vector<vector<int>> &edges) {
// TODO
// }

// * 38 - Shortest Bridge
// int shortestBridge(vector<vector<int>>& grid) {
// TODO
// }

// * 39 - Find Closest Node to Given Two Nodes
// int closestMeetingNode(vector<int> &edges, int node1, int node2) {
// TODO
// }

// * 40 - Number of Connected Components in an Undirected Graph
// int countComponents(int n, vector<int> &edges) {
// TODO
// }

// * 41 - Shortest Path with Alternating Colors
// vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) 
// {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output