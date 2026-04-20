/*
 * Leetcode - 1319
 * Number of Operations to Make Network Connected
 *
 * There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a 
 * network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
 * Any computer can reach any other computer directly or indirectly through the network.

 * You are given an initial computer network connections. You can extract certain cables between two 
 * directly connected computers, and place them between any pair of disconnected computers to make 
 * them directly connected.

 * Return the minimum number of times you need to do this in order to make all the computers connected. 
 * If it is not possible, return -1.

 * Example 1  :
 * Input      : n = 4, connections = [[0,1],[0,2],[1,2]]
 * Output     : 1
 * 
 * Example 2  :
 * Input      : n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * Output     : 2
 * 
 * https://www.geeksforgeeks.org/problems/connecting-the-graph/1
 * https://www.geeksforgeeks.org/problems/minimize-connections/1
 * https://leetcode.com/problems/number-of-operations-to-make-network-connected
 * https://www.naukri.com/code360/problems/number-of-operations-to-make-graph-connected_1385179
 */

// ! DSU

// ! Amazon, Google, Microsoft, Meta, Uber

#include <vector>
#include <numeric>
#include <iostream>

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

// * Print adjacency list
template <typename T>
void printAdjList(vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    cout << i << " -> ";
    printArr(adj[i]);
  }
}

class DSU {
  vector<int> parent;
  vector<int> rank;

public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n);
    iota(begin(parent), end(parent), 0);
  }

  int find(int x) {
    if (x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }

  void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent == y_parent)
      return;

    if (rank[x_parent] > rank[y_parent]) {
      parent[y_parent] = x_parent;
    } else {
      parent[x_parent] = y_parent;
      rank[y_parent]++;
    }
  }
};

// * Intuition
// * To connect 'n' nodes we need 'n-1' edges
// * Eg: n = 2, edges = 1
// * Eg: n = 3, edges = 2
// * Eg: n = 4, edges = 3

// * First Figure out number of connected components
int makeConnected(int n, vector<vector<int>> &connections) {
  int e = connections.size(); // * Edges

  // * Edge case
  if (n - 1 > e)
    return -1;

  DSU du(n);

  // * 1. Initialize rank and parent vectors
  vector<int> rank(n, 0);
  vector<int> parent(n);
  iota(begin(parent), end(parent), 0);

  // * 2. Classic DSU
  for (auto &vec : connections) {
    int u = vec[0], v = vec[1];
    int u_parent = du.find(u);
    int v_parent = du.find(v);

    // * Merge into one set
    if (u_parent != v_parent) {
      du.Union(u, v);
      n--;
    }
  }

  return n - 1;
}

int main(void) {
  // * testcase 1
  // int n = 4;
  // vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
  
  // * testcase 2
  // int n = 6;
  // vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  
  // * testcase 3
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  
  cout << "Components: " << n << endl;
  cout << "Connections: " << endl;
  printAdjList(connections);

  int ans = makeConnected(n, connections);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-no-of-ops-to-make-network-connected.cpp -o output && ./output