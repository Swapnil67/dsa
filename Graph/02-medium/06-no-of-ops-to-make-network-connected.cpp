/**
 * * Leetcode - 990
 * * Satisfiability of Equality Equations
 *
 * * You are given an array of strings equations that represent relationships between variables where each
 * * string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
 * * Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

 * * Return true if it is possible to assign integers to variable names so as to satisfy all the given equations
 * * or false otherwise.

 * * Example 1  :
 * * Input      : equations = ["a==b","b!=a"]
 * * Output     : false
 * 
 * * Example 2  :
 * * Input      : equations = ["b==a","a==b"]
 * * Output     : true
 * 
 * * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 */

// ! DSU

#include <vector>
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

int makeConnected(int n, std::vector<std::vector<int>> &connections) {
  int e = connections.size(); // * Edges

  // * Edge case
  if (n - 1 > e)
    return -1;

  // * 1. Initialize rank and parent vectors
  std::vector<int> rank(n, 0);
  std::vector<int> parent(n);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }

  // * 2. Classic DSU
  for (auto &vec : connections) {
    int u_parent = find(vec[0], parent);
    int v_parent = find(vec[1], parent);

    // * Merge into one set
    if (u_parent != v_parent) {
      Union(vec[0], vec[1], parent, rank);
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
  // int n = 6;
  // std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  
  // * testcase 3
  int n = 6;
  std::vector<std::vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  
  std::cout << "Components: " << n << std::endl;
  std::cout << "Connections: " << std::endl;
  printAdjList(connections);

  int ans = makeConnected(n, connections);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-no-of-ops-to-make-network-connected.cpp -o output && ./output