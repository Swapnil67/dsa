/**
 * * Leetcode - 210
 * * Course Schedule II
 *
 * * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
 * * take course bi first if you want to take course ai.
 
 * * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 
 * * Return the ordering of courses you should take to finish all courses. 
 * * If there are many valid answers, return any of them. If it is impossible to finish all courses, 
 * * return an empty array.

 * * Example 1  :
 * * Input      : numCourses = 2, prerequisites = [[1,0]]
 * * Output     : [0,1]
 * 
 * * Example 2  :
 * * Input      : numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * * Output     : [0,2,1,3] or [0,1,2,3]
 * 
 * * https://leetcode.com/problems/course-schedule-ii/
 */

#include <queue>
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

std::vector<int> bfs(int n, std::vector<std::vector<int>> &adj, std::vector<int> &indegree) {

  int count = 0;
  std::queue<int> q;

  // * Push all the vertices with indegree = 0
  for (int u = 0; u < n; ++u) {
    if (indegree[u] == 0) {
      count++;
      q.push(u);
    }
  }

  // * Classic BFS
  std::vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    ans.push_back(u);
    q.pop();

    for (auto &v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        count++;
        q.push(v);
      }
    }
  }

  if (count == n) // * valid topological sort
    return ans;

  return {};
}

std::vector<int> canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {

  std::vector<int> indegree(numCourses, 0);
  std::vector<std::vector<int>> adj = contructadj(numCourses, prerequisites, indegree);

  // * For Debugging
  // std::cout << "Adjacency List" << std::endl;
  // printAdjList(adj);
  // std::cout << "Indegree" << std::endl;
  // printArr(indegree);

  return bfs(numCourses, adj, indegree);
}

int main(void) {

  // * testcase 1
  // int numCourses = 2;
  // std::vector<std::vector<int>> prerequisites = {{1, 0}};

  // * testcase 2
  // int numCourses = 2;
  // std::vector<std::vector<int>> prerequisites = {{1, 0}, {0, 1}};

  // * testcase 3
  int numCourses = 4;
  std::vector<std::vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  std::cout << "numCourses: " << numCourses << std::endl;
  std::cout << "prerequisites: " << std::endl;
  for (auto &vec : prerequisites)
    printArr(vec);

  std::vector<int> ans = canFinish(numCourses, prerequisites);
  std::cout << "Course Schedule: ";
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 03-course-schedule-ii.cpp -o output && ./output