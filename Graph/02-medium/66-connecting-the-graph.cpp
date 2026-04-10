/*
 * Connecting the graph
 * 
 * You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that 
 * edge between any two vertices in one operation. Find the minimum number of operations that will be required 
 * to connect the graph.
 * 
 * If it is not possible to connect the graph, return -1.
 * 
 * Example 1    :
 * Input        : n = 4, edges = [ [0, 1] , [0, 2] , [1, 2] ]
 * Output       : 1
 * 
 * Example 2    :
 * Input        : n = 6, edges = [ [0,1] , [0,2] , [0,3] , [1,2] , [1,3] ]
 * Output       : 2
 * Explanation  : 
 * https://www.geeksforgeeks.org/problems/connecting-the-graph/1
*/

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)

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

class DSU {
public:
  vector<int> parent, rank;
  DSU(int n) {
    rank.resize(n);
    parent.resize(n);
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
    if (rank[x_parent] > rank[y_parent]) {
      parent[y_parent] = x_parent;
    } else {
      parent[x_parent] = y_parent;
      rank[y_parent]++;
    }
  }
};

int solve(int n, vector<vector<int>>& edge) {
  DSU ds(n);

  int extra_edges = 0;
  for (auto &it : edge) {
    int u = it[0], v = it[1];
    if (ds.find(u) == ds.find(v)) {
      extra_edges++;
    } else {
      ds.Union(u, v);
    }
  }

  // * Number of actual components in a graph
  int components = 0;
  for (int i = 0; i < n; ++i) {
    if (i == ds.parent[i])
      components++;
  }

  int ans = components - 1; // * Graph Theory
  if (extra_edges >= ans)   // * If there are extra edges greater than components
    return ans;

  return -1; // * no extra edge
}

int main(void) {
  // * testcase 1
  int n = 6;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

  // * testcase 2
  // int n = 4;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
  
  cout << "n: " << n << endl;
  cout << "edges: " << endl;
  for (auto &vec : edges)
    printArr(vec);


  int ans = solve(n, edges);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 66-connecting-the-graph.cpp -o output && ./output
