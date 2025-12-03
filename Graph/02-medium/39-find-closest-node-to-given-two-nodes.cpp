/*
 * Leetcode - 2359
 * Find Closest Node to Given Two Nodes
 * 
 * You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

 * The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from
 * node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

 * You are also given two integers node1 and node2.

 * Return the index of the node that can be reached from both node1 and node2, such that the maximum between the 
 * distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, 
 * return the node with the smallest index, and if no possible answer exists, return -1.

 * Example 1:
 * Input     : edges = [2,2,3,-1], node1 = 0, node2 = 1
 * Output    : 2
 * 
 * Example 2:
 * Input     : edges = [1,2,-1], node1 = 0, node2 = 2
 * Output    : 2

 * https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/
*/

#include <vector>
#include <climits>
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

void dfs(int node,
         std::vector<int> &dist,
         std::vector<int> &edges)
{
  int v = edges[node]; // * ngbr of current node
  if (v != -1 && dist[v] != -1) {
    dist[v] = dist[node] + 1;
    dfs(v, dist, edges);
  }
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n x n)
// * SPACE COMPLEXITY O(n x n)
int closestMeetingNode(std::vector<int> &edges, int node1, int node2)
{
  int n = edges.size();
  // * get the distance from node1 to its ngbrs
  std::vector<int> dist_node1(n, -1);
  dist_node1[node1] = 0; // * distance to itself will be zero
  dfs(node1, dist_node1, edges);
  // printArr(dist_node1);
  
  // * get the distance from node2 to its ngbrs 
  std::vector<int> dist_node2(n, -1);
  dist_node2[node2] = 0; // * distance to itself will be zero
  dfs(node2, dist_node2, edges);
  // printArr(dist_node2);

  int ans = -1;
  int cur_max = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int max_d = std::max(dist_node1[i], dist_node2[i]);
    if (cur_max > max_d) {
      ans = i;
      cur_max = max_d;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1 // * Ans = 1
  int node1 = 0, node2 = 1;
  std::vector<int> edges = {2, 2, 3, -1};
  
  // * testcase 2 // * Ans = 2
  // int node1 = 0, node2 = 2;
  // std::vector<int> edges = {1, 2, -1};

  std::cout << "node1: " << node1 << " " << "node2: " << node2 << std::endl;
  std::cout << "Edges:  ";
  printArr(edges);

  int steps = closestMeetingNode(edges, node1, node2);

  std::cout << "Steps: " << steps << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 39-find-closest-node-to-given-two-nodes.cpp -o output && ./output

 