/*
 * Leetcode - 1462
 * Course Schedule IV
 * 
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
 * course ai first if you want to take course bi.
 * 
 * - For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

 * Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, 
 * then course a is a prerequisite of course c.
 * 
 * You are also given an array queries where queries[j] = [uj, vj]. For the jth query, 
 * you should answer whether course uj is a prerequisite of course vj or not.
 * 
 * Return a boolean array answer, where answer[j] is the answer to the jth query.

 * Example 1:
 * Input     : numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
 * Output    : [false,true]
 * 
 * Example 2:
 * Input     : numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
 * Output    : [false,false]
 * 
 * Example 2:
 * Input     : numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
 * Output    : [true,true]

 * https://leetcode.com/problems/course-schedule-iv/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

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

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * TC = O(E)
std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) 
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
  }
  return adj;
}

// * TC = O(E)
std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<int> &indegree,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    indegree[v]++;
  }
  return adj;
}

// * DFS for check if we arrive at a dest node if we start traversing from src node
bool dfs(
    int src, int dest,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[src] = true; // * mark visited

  if (src == dest) // * reached destination
    return true;   

  for (auto &ngbr: adj[src]) {
    if (!visited[ngbr] && dfs(ngbr, dest, visited, adj)) {
      return true;
    }
  }
  return false;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Check if we can reach src -> dest for each query
// * TIME COMPLEXITY O(Q * (V + E))
// * SPACE COMPLEXITY O(V + E)
std::vector<bool> checkIfPrerequisite(
    int numCourses,
    std::vector<std::vector<int>> &prerequisites,
    std::vector<std::vector<int>> &queries)
{
  // * Create a Adj list
  std::unordered_map<int, std::vector<int>> adj = constructadj(prerequisites);
  printAdjList(adj); // * For debugging
  
  int Q = queries.size();
  std::vector<bool> ans(Q, false);
  
  // * TC = O(Q)
  // * Go to src -> dest for all queries
  for (int i = 0; i < Q; ++i) {
    int src = queries[i][0], dest = queries[i][1];
    std::vector<bool> visited(numCourses, false);
    if (dfs(src, dest, visited, adj)) // * TC = O(V + E)
      ans[i] = true;
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Topological Sort (Kahn's Algo)
// * TIME COMPLEXITY O(V^2 * (V + E))
// * SPACE COMPLEXITY O(V + E)
std::vector<bool> checkIfPrerequisite2(
    int numCourses,
    std::vector<std::vector<int>> &prerequisites,
    std::vector<std::vector<int>> &queries)
{
  // * Create a adjaency list & indegree vector
  std::vector<int> indegree(numCourses);
  std::unordered_map<int, std::vector<int>> adj = constructadj(indegree, prerequisites);
  printAdjList(adj); // * For debugging
  
  int Q = queries.size();
  std::vector<bool> ans(Q, false);

  // * Push all the vertices whose indegree is '0'
  std::queue<int> q;
  for (int i = 0; i < numCourses; ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }
  
  // * Map from the node as key to the set of prerequisite nodes.
  std::unordered_map<int, std::unordered_set<int>> mp_st;
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto &v : adj[node]) { // * O(V)
      mp_st[v].insert(node);
      for (auto &prereq : mp_st[node]) { // * O(V) - add the prerequisites of parent node to the current prereq set
        mp_st[v].insert(prereq);
      }

      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  // * TC = O(Q)
  for (int i = 0; i < Q; ++i) {
    int src = queries[i][0], dest = queries[i][1];
    ans[i] = mp_st[dest].find(src) != mp_st[dest].end();
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int numCourses = 2;
  // std::vector<std::vector<int>> prerequisites = {{1, 0}}, queries = {{0, 1}, {1, 0}};
  
  // * testcase 2
  // int numCourses = 2;
  // std::vector<std::vector<int>> prerequisites = {}, queries = {{1, 0}, {0, 1}};

  // * testcase 3
  int numCourses = 3;
  std::vector<std::vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}}, queries = {{1, 0}, {1, 2}};

  std::cout << "-------- prerequisites -------- " << std::endl;
  for (auto &vec : prerequisites)
  printArr(vec);
  std::cout << "-------- queries -------- " << std::endl;
  for (auto &vec : queries)
  printArr(vec);
  
  // std::vector<bool> ans = checkIfPrerequisite(numCourses, prerequisites, queries);
  std::vector<bool> ans = checkIfPrerequisite2(numCourses, prerequisites, queries);
  std::cout << "-------- Answer -------- " << std::endl;
  for (int i = 0; i < queries.size(); ++i) {
    auto it = queries[i];
    std::cout << "query: (" << it[0] << ", " << it[1] << ")" << " -> " << ans[i] << std::endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 35-course-schedule-iv.cpp -o output && ./output

 