/**
 * * Leetcode - 1319
 * * Number of Operations to Make Network Connected
 *
 * * There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a 
 * * network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
 * * Any computer can reach any other computer directly or indirectly through the network.

 * * You are given an initial computer network connections. You can extract certain cables between two 
 * * directly connected computers, and place them between any pair of disconnected computers to make 
 * * them directly connected.

 * * Return the minimum number of times you need to do this in order to make all the computers connected. 
 * * If it is not possible, return -1.

 * * Example 1  :
 * * Input      : n = 4, connections = [[0,1],[0,2],[1,2]]
 * * Output     : 1
 * 
 * * Example 2  :
 * * Input      : n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
 * * Output     : 2
 * 
 * * https://leetcode.com/problems/number-of-operations-to-make-network-connected
 * * https://www.naukri.com/code360/problems/number-of-operations-to-make-graph-connected_1385179
 * * https://www.geeksforgeeks.org/problems/minimize-connections/1
 */

// ! DSU

// ! Microsoft, Meta, Amazon

#include <vector>
#include <numeric>
#include <iostream>

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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

int find(int x, std::vector<int> &parent) {
  if (x == parent[x])
    return x;

  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, std::vector<int> &parent, std::vector<int> &rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);
  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent;
  }
  else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}

// * Intuition
// * To connect 'n' nodes we need 'n-1' edges
// * Eg: n = 2, edges = 1
// * Eg: n = 3, edges = 2
// * Eg: n = 4, edges = 3
int makeConnected(int n, std::vector<std::vector<int>> &connections) {
  int e = connections.size(); // * Edges

  // * Edge case
  if (n - 1 > e)
    return -1;

  // * 1. Initialize rank and parent vectors
  std::vector<int> rank(n, 0);
  std::vector<int> parent(n);
  std::iota(begin(parent), end(parent), 0);

  // * 2. Classic DSU
  for (auto &vec : connections) {
    int u = vec[0], v = vec[1];
    int u_parent = find(u, parent);
    int v_parent = find(v, parent);

    // * Merge into one set
    if (u_parent != v_parent) {
      Union(u, v, parent, rank);
      n--;
    }
  }

  return n - 1;
}

int main(void) {
  // * testcase 1
  // int n = 4;
  // std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
  
  // * testcase 2
  int n = 6;
  std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  
  // * testcase 3
  // int n = 6;
  // std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  
  std::cout << "Components: " << n << std::endl;
  std::cout << "Connections: " << std::endl;
  printAdjList(connections);

  int ans = makeConnected(n, connections);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-no-of-ops-to-make-network-connected.cpp -o output && ./output