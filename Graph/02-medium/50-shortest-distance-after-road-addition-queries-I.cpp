/*
 * Leetcode - 3243
 * Shortest Distance After Road Addition Queries I
 * 
 * You are given an integer n and a 2D integer array queries.

 * There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road 
 * from city i to city i + 1 for all 0 <= i < n - 1.

 * queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. 
 * After each query, you need to find the length of the shortest path from city 0 to city n - 1.

 * Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the 
 * length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

 * 
 * Example 1  :
 * Input      : n = 5, queries = [[2,4],[0,2],[0,4]]
 * Output     : 2

 * Example 2  :
 * Input      : n = 4, queries = [[0,3],[0,2]]
 * Output     : 1
 
 * Example 3  :
 * Input      : bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
 * Output     : 1
 
 * https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/
*/

// ! Google

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

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

void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

int bfs(int &dest, std::unordered_map<int, std::vector<int>> &adj) {
  std::queue<int> q;
  q.push(0);

  std::vector<bool> visited(dest, false);
  visited[0] = true;

  int level = 0;
  while(!q.empty()) {
    int N = q.size();
    while (N--) {
      int u = q.front();
      q.pop();

      if (u == dest - 1)
        return level;
  
      for (auto &v : adj[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    level += 1;
  }

  return -1;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Q = num of queries
// * V = num of vertices
// * E = num of edges
// * TIME COMPLEXITY O(Q) * O(V + E)
// * SPACE COMPLEXITY O(Q) * O(V + E)
std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>> &queries) {
  // * 1. Create a default adj list
  std::unordered_map<int, std::vector<int>> adj;
  for (int i = 0; i <= n - 2; ++i) {
    adj[i].push_back(i + 1);
  }
  // printAdjList(adj);

  // * 2. Add each query to Adj list & then find min distance from 0 -> n
  std::vector<int> ans;
  for (auto &it : queries) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    int distance = bfs(n, adj);
    ans.push_back(distance);
  }
  // printAdjList(adj);

  return ans;
}

int main(void) {
  // * testcase 1
  int n = 5;
  std::vector<std::vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};

  // * testcase 2
  // int n = 4;
  // std::vector<std::vector<int>> queries = {{0, 3}, {0, 2}};

  std::cout << "------------ queries -------------" << std::endl;
  for (auto &vec : queries)
    printArr(vec);

  std::vector<int> ans = shortestDistanceAfterQueries(n, queries);
  std::cout << "Shortest Distance From 0 -> n" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 50-shortest-distance-after-road-addition-queries-I.cpp -o output && ./output

 