/**
 * * Disjoint Set Union
 * 
 * * Example 1  :
 * * Input      : V = 4, edges[][] = [[3, 0], [1, 0], [2, 0]]
 * * Output     : [3, 2, 1, 0]
 * 
 * * Example 2  :
 * * Input      : V = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]
 * * Output     : [4, 5, 0, 1, 2, 3] or [5, 2, 4, 0, 1, 3]
 * 
 * * https://www.naukri.com/code360/problems/topological-sort_982938
 * * https://www.geeksforgeeks.org/problems/topological-sort/1
 * 
*/


/*
* DSU has 2 primary operations
* - Combine two given sets
* - Tell if two numbers (a, b) belongs to same set or not
*/

#include <vector>
#include <iostream>

int find(int n, std::vector<int> &parent) {
  if (n == parent[n])
    return n;
  return parent[n] = find(parent[n], parent);
}

void Union(int x, int y, std::vector<int> &parent, std::vector<int> &rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  // * Already in same set
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

int main(void) {
  int V = 3;
  std::vector<int> rank(V);
  std::vector<int> parent(V);
  for (int i = 0; i < V; ++i) {
    rank[i] = 1;
    parent[i] = i;
  }

  return 0;
}