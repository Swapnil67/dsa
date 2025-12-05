/*
 * Leetcode - 1129
 * Shortest Path with Alternating Colors
 * 
 * You are given an integer n, the number of nodes in a directed graph where the nodes are labeled 
 * from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
 * 
 * You are given two arrays redEdges and blueEdges where:
 * 
 * - redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
 * - blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.

 * Return an array answer of length n, where each answer[x] is the length of the shortest path from 
 * node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 * Example 1:
 * Input     : n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
 * Output    : [0,1,-1]
 * 
 * Example 2:
 * Input     : n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
 * Output    : [0,1,-1]
 * 
 * https://leetcode.com/problems/shortest-path-with-alternating-colors
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

// ! Amazon

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

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int a = it[0], b = it[1];
    adj[a].push_back(b);
  }
  return adj;
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * red edge = 0
// * blue edge = 1

// * TIME COMPLEXITY O(n x n)
// * SPACE COMPLEXITY O(n x n)
std::vector<int> shortestAlternatingPaths(
    int n,
    std::vector<std::vector<int>> &redEdges,
    std::vector<std::vector<int>> &blueEdges)
{
  // * Adj list for red edges
  std::unordered_map<int, std::vector<int>> red_adj = constructadj(redEdges);
  // printAdjList(red_adj); // * For Debugging
  
  // * Adj list for blue edges
  std::unordered_map<int, std::vector<int>> blue_adj = constructadj(blueEdges);
  // printAdjList(blue_adj); // * For Debugging

  std::unordered_set<std::string> visit;
  visit.insert("0,-1");

  std::vector<int> ans(n, -1);
  std::queue<std::vector<int>> q;
  q.push({0, 0, -1}); // * {node, length, edge_color}
  // * Initially we have edge_color = -1 becoz we'll try to search for both edge
  // * i.e., red & blue edge

  while (!q.empty()) {
    std::vector<int> data = q.front();
    q.pop();
    int node = data[0], length = data[1], edge_color = data[2];
    // std::cout << "q.front(): " << "(" << node << " " << length << " " << edge_color << ")" << std::endl;
    if (ans[node] == -1)
      ans[node] = length;

    if (edge_color != 0) {
      for (int &ngbr: red_adj[node]) {
        std::string key = std::to_string(ngbr) + ",0";
        if (visit.insert(key).second) {
          q.push({ngbr, length + 1, 0});
        }
      }
    }

    if (edge_color != 1) {
      for (int &ngbr: blue_adj[node]) {
        std::string key = std::to_string(ngbr) + ",1";
        if (visit.insert(key).second) {
          q.push({ngbr, length + 1, 1});
        }
      }
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 3;
  // std::vector<std::vector<int>> redEdges = {{0, 1}, {1, 2}}, blueEdges = {};
  
  // * testcase 2
  // int n = 3;
  // std::vector<std::vector<int>> redEdges = {{0, 1}}, blueEdges = {{2, 1}};
  
  // * testcase 2
  int n = 3;
  std::vector<std::vector<int>> redEdges = {{0, 1}}, blueEdges = {{0, 2}, {1, 2}};

  std::cout << "-------- red edges -------- " << std::endl;
  for (auto &vec : redEdges)
    printArr(vec);
  std::cout << "-------- blue edges -------- " << std::endl;
  for (auto &vec : blueEdges)
    printArr(vec);

  std::vector<int> ans = shortestAlternatingPaths(n, redEdges, blueEdges);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 41-Shortest-Path-with-Alternating-Colors.cpp -o output && ./output
