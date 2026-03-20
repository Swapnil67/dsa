/*
 * Leetcode - 1489
 * Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 * 
 * Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where 
 * edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. 
 * A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the 
 * minimum possible total edge weight.
 * 
 * Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). 
 * An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge.
 * On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
 * 
 * Note that you can return the indices of the edges in any order.
 * 
 * Example 1    :
 * Input        : n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
 * Output       : 5
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
 * Output       : 5
 * Explanation  : 
 * 
*/

#include <vector>
#include <climits>
#include <numeric>
#include <iostream>
#include <algorithm>

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

class UnionFind {
public:
    vector<int> rank;
    vector<int> parent;
    UnionFind(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        iota(begin(parent), end(parent), 0);
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
      int xp = find(x);
      int yp = find(y);

      if (xp == yp)
        return false;

      if (rank[xp] > rank[yp]) {
        parent[yp] = xp;
      }
      else {
        parent[xp] = yp;
        rank[yp]++;
      }
      return true;
    }
};

int N;
// * O(E · α(N))
int kruskals(int skip_edge, int add_edge, vector<vector<int>> &edges) {
  UnionFind uf(N);

  int edges_connected = 0;
  int sum = 0;
  if (add_edge != -1) {
    uf.Union(edges[add_edge][0], edges[add_edge][1]);
    edges_connected++;
    sum += edges[add_edge][2];
  }

  int V = edges.size();
  for (int i = 0; i < V; ++i) {
    if (i == skip_edge)
      continue;

    vector<int> data = edges[i];
    int u = data[0], v = data[1], w = data[2];

    int u_p = uf.find(u);
    int v_p = uf.find(v);

    if (u_p != v_p) {
      uf.Union(u, v);
      sum += w;
      edges_connected++;
    }
  }

  if (edges_connected != N - 1)
    return INT_MAX;

  return sum;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * E is the number of edges
// * N is number of vertices
// * α is the inverse Ackermann function (practically constant).
// * TIME COMPLEXITY O(E² · α(N)) ~ O(E²)
// * SPACE COMPLEXITY O(N + E)
vector<vector<int>>
findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
{
  N = n;
  int V = edges.size();
  for (int i = 0; i < V; ++i) {
    edges[i].push_back(i);
  }

  // * ElogE
  sort(begin(edges), end(edges), [&](const vector<int> &v1, const vector<int> &v2)
       { return v1[2] < v2[2]; });

  // * Find minimum MST without adding or skipping any edge
  int MIN_MST = kruskals(-1, -1, edges);

  vector<int> critical_edges, pseudo_critical_edges;
  for (int i = 0; i < V; ++i)
  {
    vector<int> data = edges[i];
    // * Skip edge to check critical
    if (kruskals(i, -1, edges) > MIN_MST) {
      critical_edges.push_back(data[3]);
    }
    else if (kruskals(-1, i, edges) == MIN_MST) {
      // * add edge to check pseudo critical
      pseudo_critical_edges.push_back(data[3]);
    }
  }

  return {critical_edges, pseudo_critical_edges};
}

int main(void) {
  std::cout << "Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree" << std::endl;
  // * testcase 1
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};

  // * testcase 2
  // int n = 4;
  // std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};

  cout << "Vertices: " << n << endl;
  cout << "Edges" << endl;
  for (auto &vec : edges)
    printArr(vec);

  std::vector<std::vector<int>> ans = findCriticalAndPseudoCriticalEdges(n, edges);
  std::cout << "Critical Edges" << std::endl;
  printArr(ans[0]);
  std::cout << "Pseudo Critical Edges" << std::endl;
  printArr(ans[1]);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 11-find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree.cpp -o output && ./output
