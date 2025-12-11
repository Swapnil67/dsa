/*
 * Leetcode - 1514
 * Path with Maximum Probability
 * 
 * You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list 
 * where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of 
 * success of traversing that edge succProb[i].

 * Given two nodes start and end, find the path with the maximum probability of success to go from start
 * to end and return its success probability.

 * If there is no path from start to end, return 0. Your answer will be accepted if it differs from 
 * the correct answer by at most 1e-5.

 * Example 1  :
 * Input      : n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
 * Output     : 0.25000

 * Example 2  :
 * Input      : n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
 * Output     : 0.30000

 * Example 3  :
 * Input      : n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
 * Output     : 0.00000

 * https://leetcode.com/problems/path-with-maximum-probability/description/
*/

// ! Dijkstra Algorithm

// ! Google, Amazon, Meta, Microsoft, Samsung

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
typedef std::pair<int, double> pif;

void printAdjList(std::unordered_map<int, std::vector<pif>> &adj) {
  for (auto &[u, vec] : adj) {
    std::cout << u << " -> "; 
    for (auto &p: vec) {
      std::cout << "(" << p.first << " " << p.second << ") ";
    }
    std::cout << std::endl;
  }
}

std::unordered_map<int, std::vector<pif>> constructadj(
    std::vector<double> &succProb,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<pif>> adj;
  if (edges.size() == 0)
    return adj;

  int n = edges.size();
  for (int i = 0; i < n; ++i) {
    int u = edges[i][0], v = edges[i][1];
    double w = succProb[i];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  return adj;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using Dijkstra Algorithm
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E*Log(V))
// * SPACE COMPLEXITY O(E + V)
double maxProbability(
    int n, int start, int end,
    std::vector<double> succProb,
    std::vector<std::vector<int>> &edges)
{
  // * 1. Construct adj
  std::unordered_map<int, std::vector<pif>> adj = constructadj(succProb, edges);
  printAdjList(adj);

  std::vector<double> dist(n, 0.0);
  dist[start] = 1.0; // * Prob to reach start is 100% i.e. Probability = 1

  // * {probability, node}
  std::priority_queue<std::pair<double, int>> max_heap;
  max_heap.push({1.0, start});

  while (!max_heap.empty()) {
    auto [u_prob, u] = max_heap.top();
    max_heap.pop();
    // std::cout << "u: " << u << ", prob " << u_prob << std::endl;

    for (auto &[v, v_prob]: adj[u]) {
      double new_prob = u_prob * v_prob;
      // std::cout << "v: " << v << ", new_prob " << new_prob << std::endl;
      if (new_prob > dist[v]) {
        dist[v] = new_prob;
        max_heap.push({new_prob, v});
      }
    }
  }

  return dist[end];
}

int main(void) {
  // * testcase 1
  int n = 3, start = 0, end = 2;
  std::vector<double> succProb = {0.5, 0.5, 0.2};
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  
  // * testcase 2
  // int n = 3, start = 0, end = 2;
  // std::vector<double> succProb = {0.5, 0.5, 0.3};
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};

  // * testcase 3
  // int n = 3, start = 0, end = 2;
  // std::vector<double> succProb = {0.5};
  // std::vector<std::vector<int>> edges = {{0, 1}};

  std::cout << "start: " << start << ", end: " << end << std::endl;
  std::cout << "Success Probability: ";
  printArr(succProb);
  std::cout << "Edegs" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  double ans = maxProbability(n, start, end, succProb, edges);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-path-with-max-probability.cpp -o output && ./output

 