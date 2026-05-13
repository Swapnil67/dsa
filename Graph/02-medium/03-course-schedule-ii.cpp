/*
 * Leetcode - 210
 * Course Schedule II
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
 * take course bi first if you want to take course ai.
 
 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 
 * Return the ordering of courses you should take to finish all courses. 
 * If there are many valid answers, return any of them. If it is impossible to finish all courses, 
 * return an empty array.

 * Example 1  :
 * Input      : numCourses = 2, prerequisites = [[1,0]]
 * Output     : [0,1]
 * 
 * Example 2  :
 * Input      : numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output     : [0,2,1,3] or [0,1,2,3]
 * 
 * https://leetcode.com/problems/course-schedule-ii/
 */

// ! Meta, Amazon, Microsoft, Google

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

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

// * Print adjacency list
void printAdjList(unordered_map<int, vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

// * Kahn's Algo
vector<int> bfs(
    int n,
    vector<int> &indegree,
    unordered_map<int, vector<int>> adj)
{

  int count = 0;
  queue<int> q;

  // * Push all the vertices with indegree = 0
  for (int u = 0; u < n; ++u) {
    if (indegree[u] == 0) {
      count++;
      q.push(u);
    }
  }

  // * Classic BFS
  vector<int> ans;
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

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Kahn's Algo
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
vector<int> canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  // * Step 1. Create a Adj list with indegree vector
  vector<int> indegree(numCourses, 0);
  unordered_map<int, vector<int>> adj;
  for (auto &it: prerequisites) {
    int a = it[0], b = it[1];
    // * b ---> a
    adj[b].push_back(a);
    indegree[a]++;
  }

  // * For Debugging
  // cout << "Adjacency List" << endl;
  // printAdjList(adj);
  // cout << "Indegree" << endl;
  // printArr(indegree);

  // * Step 2. Kahn's Algo
  return bfs(numCourses, indegree, adj);
}

int main(void) {

  // * testcase 1
  // int numCourses = 2;
  // vector<vector<int>> prerequisites = {{1, 0}};

  // * testcase 2
  // int numCourses = 2;
  // vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

  // * testcase 3
  int numCourses = 4;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  cout << "numCourses: " << numCourses << endl;
  cout << "prerequisites: " << endl;
  for (auto &vec : prerequisites)
    printArr(vec);

  vector<int> ans = canFinish(numCourses, prerequisites);
  cout << "Course Schedule: ";
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 03-course-schedule-ii.cpp -o output && ./output