/*
 * Leetcode - 947
 * Most Stones Removed with Same Row or Column
 * 
 * On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
 * A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
 
 * Given an array `stones` of length `n` where stones[i] = [xi, yi] represents the location of the `ith` stone, 
 * return the largest possible number of stones that can be removed.
 * 
 * Example 1  :
 * Input      : stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output     : 5
 * 
 * Example 2  :
 * Input      : stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output     : 3
 * 
 * Example 3  :
 * Input      : stones = [[0,0]]
 * Output     : 0
 * 
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 * https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1
 * https://www.naukri.com/code360/problems/most-stones-removed-with-same-row-or-column_1376597
*/

// ! Google, Amazon, PhonePe, Samsung

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

void Union(int x, int y, std::vector<int> &rank, std::vector<int> &parent) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  // * already has same parent
  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent;
  } 
  else {
    rank[y_parent]++;
    parent[x_parent] = y_parent;
  }
}

void dfs(int i, std::vector<bool> &visited, std::vector<std::vector<int>> &stones) {
  int n = stones.size();
  visited[i] = true;
  for (int j = 0; j < n; ++j) {
    int r = stones[i][0];
    int c = stones[i][1];
    if (!visited[j] && (stones[j][0] == r || stones[j][0] == c)) {
      dfs(j, visited, stones);
    }
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * In one group if there are 'n' stones then 'n - 1' stones will be destoryed only 1 will be left
// * So we can say the following groups
// * G1 = (s1 - 1) stones remaining
// * G2 = (s2 - 1) stones remaining
// * G3 = (s3 - 1) stones remaining
// * G4 = (s4 - 1) stones remaining
// * Gn = (sn - 1) stones remaining
// * (s1 - 1) + (s2 - 1) + (s3 - 1) + (s4 - 1) + (s5 - 1) .... (sn - 1)
// * (s1 + s2 + s3 + s4 + .... + sn) - (1 + 1 + 1 + 1 + .... + 1)
// * Total Number of stones = (s1 + s2 + s3 + s4 + .... + sn)
// * Total Number of Groups = (1 + 1 + 1 + 1 + .... + 1)
// * Ans = no. of stones - no. of groups
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
int removeStones(std::vector<std::vector<int>> &stones) {
  int n = stones.size();
  std::vector<bool> visited(n, false);

  int groups = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, visited, stones);
      groups++;
    }
  }

  return n - groups;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * DSU
// * Ans = no. of stones - no. of groups
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
int removeStonesDSU(std::vector<std::vector<int>> &stones) {
  int n = stones.size();
  std::vector<bool> visited(n, false);

  std::vector<int> rank(n, 1);
  std::vector<int> parent(n);
  std::iota(begin(parent), end(parent), 0); // * fill from 0 to n

  for (int i = 0; i < n; ++i) {
    int r = stones[i][0], c = stones[i][1];
    for (int j = 1; j < n; ++j) {
      // * Both are in either same row or same column
      if (stones[j][0] == r || stones[j][1] == c) {
        Union(i, j, rank, parent);
      }
    }
  }

  int groups = 0;
  for (int i = 0; i < n; i++) {
    if (parent[i] == i)
      groups++;
  }
  
  return n - groups;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

  // * testcase 2
  // std::vector<std::vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};

  std::cout << "Stones: " << std::endl;
  for (auto &vec : stones)
    printArr(vec);

  // int ans = removeStones(stones);
  int ans = removeStonesDSU(stones);
  std::cout << "Max stones that can be removed: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 22-most-stones-removed-with-same-row-or-column.cpp -o output && ./output

