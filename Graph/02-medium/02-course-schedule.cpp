/**
 * * Leetcode - 207
 * * Course Schedule
 *
 * * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
 * * take course bi first if you want to take course ai.
 
 * * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 
 * * Return true if you can finish all courses. Otherwise, return false.
 
 * * Example 1  :
 * * Input      : numCourses = 2, prerequisites = [[1,0]]
 * * Output     : true
 * 
 * * Example 2  :
 * * Input      : numCourses = 2, prerequisites = [[1,0],[0,1]]
 * * Output     : false
 * 
 * * https://leetcode.com/problems/course-schedule/description/
 */

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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

// * Construct adjacency list for DFS
std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int a = it[0], b = it[1];
    adj[b].push_back(a);
  }
  return adj;
}

// * Construct adjacency list for BFS
std::vector<std::vector<int>> contructadj(
    int V,
    std::vector<std::vector<int>> &prerequisites,
    std::vector<int> &indegree)
{
  std::vector<std::vector<int>> adj(V);

  for (auto &it: prerequisites) {
    int a = it[0], b = it[1];
    // * b ---> a
    adj[b].push_back(a);
    indegree[a]++;
  }

  return adj;
}

bool bfs(int V, std::vector<std::vector<int>> &adj, std::vector<int> &indegree) {
  int count = 0; // * to check if cycle
  std::queue<int> q;
  
  // * Push all the vertices with indegree = 0
  for (int i = 0; i < V; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
      count++;
    }
  }

  // * Classic BFS
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v: adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
        count++;
      }
    }
  }

  // std::cout << "N: " << V << ", Count: " << count << std::endl;
  return count == V; // * Not found cycle means we managed to finish all courses
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<int> indegree(numCourses, 0);
  std::vector<std::vector<int>> adj = contructadj(numCourses, prerequisites, indegree);

  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);
  std::cout << "Indegree" << std::endl;
  printArr(indegree);

  return bfs(numCourses, adj, indegree);
}

int main(void) {

  // * testcase 1
  // int numCourses = 2;
  // std::vector<std::vector<int>> prerequisites = {{1, 0}};

  // * testcase 2
  int numCourses = 2;
  std::vector<std::vector<int>> prerequisites = {{1, 0}, {0, 1}};

  std::cout << "numCourses: " << numCourses << std::endl;
  std::cout << "prerequisites: " << std::endl;
  for (auto &vec : prerequisites)
    printArr(vec);

  bool ans = canFinish(numCourses, prerequisites);
  std::cout << "is Course Schedule: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 02-course-schedule.cpp -o output && ./output