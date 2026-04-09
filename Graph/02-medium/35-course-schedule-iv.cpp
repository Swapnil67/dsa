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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

void printAdjList(unordered_map<int, vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * TC = O(E)
unordered_map<int, vector<int>> constructadj(vector<vector<int>> &edges) {
  unordered_map<int, vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
  }
  return adj;
}

// * TC = O(E)
unordered_map<int, vector<int>> constructadj(
    vector<int> &indegree,
    vector<vector<int>> &edges)
{
  unordered_map<int, vector<int>> adj;
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
    vector<bool> &visited,
    unordered_map<int, vector<int>> &adj)
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Check if we can reach src -> dest for each query
// * TIME COMPLEXITY O(Q * (V + E))
// * SPACE COMPLEXITY O(V + E)
vector<bool> checkIfPrerequisite(
    int numCourses,
    vector<vector<int>> &prerequisites,
    vector<vector<int>> &queries)
{
  // * Create a Adj list
  unordered_map<int, vector<int>> adj = constructadj(prerequisites);
  printAdjList(adj); // * For debugging
  
  int Q = queries.size();
  vector<bool> ans(Q, false);
  
  // * TC = O(Q)
  // * Go to src -> dest for all queries
  for (int i = 0; i < Q; ++i) {
    int src = queries[i][0], dest = queries[i][1];
    vector<bool> visited(numCourses, false);
    if (dfs(src, dest, visited, adj)) // * TC = O(V + E)
      ans[i] = true;
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Q - No of queries
// * Topological Sort (Kahn's Algo)
// * TIME COMPLEXITY O(V^2 * (V + E)) ~ O(numCourses² + Q)
// * SPACE COMPLEXITY O(V + E)        ~ O(numCourses²)
vector<bool> checkIfPrerequisite2(
    int numCourses,
    vector<vector<int>> &prerequisites,
    vector<vector<int>> &queries)
{
  // * Create a adjaency list & indegree vector
  vector<int> indegree(numCourses);
  unordered_map<int, vector<int>> adj = constructadj(indegree, prerequisites);
  printAdjList(adj); // * For debugging
  
  // * Push all the vertices whose indegree is '0'
  queue<int> q;
  for (int i = 0; i < numCourses; ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }
  
  // * Map from the node as key to the set of prerequisite nodes.
  unordered_map<int, unordered_set<int>> mp_st;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v : adj[u]) { // * O(V)
      mp_st[v].insert(u);
      for (auto &prereq : mp_st[u]) { // * O(V) - add the prerequisites of parent 'u' to the current prereq set
        mp_st[v].insert(prereq);
      }

      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  int Q = queries.size();
  vector<bool> ans(Q, false);
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
  // vector<vector<int>> prerequisites = {{1, 0}}, queries = {{0, 1}, {1, 0}};
  
  // * testcase 2
  // int numCourses = 2;
  // vector<vector<int>> prerequisites = {}, queries = {{1, 0}, {0, 1}};

  // * testcase 3
  int numCourses = 3;
  vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}}, queries = {{1, 0}, {1, 2}};

  cout << "-------- prerequisites -------- " << endl;
  for (auto &vec : prerequisites)
  printArr(vec);
  cout << "-------- queries -------- " << endl;
  for (auto &vec : queries)
  printArr(vec);
  
  // vector<bool> ans = checkIfPrerequisite(numCourses, prerequisites, queries);
  vector<bool> ans = checkIfPrerequisite2(numCourses, prerequisites, queries);
  cout << "-------- Answer -------- " << endl;
  for (int i = 0; i < queries.size(); ++i) {
    auto it = queries[i];
    cout << "query: (" << it[0] << ", " << it[1] << ")" << " -> " << ans[i] << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 35-course-schedule-iv.cpp -o output && ./output

 