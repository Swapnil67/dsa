/*
 * Leetcode - 2050
 * Parallel Courses III
 *
 * You are given an integer n, which indicates that there are n courses labeled from 1 to n. 
 * You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] 
 * denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship).
 * Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes
 * to complete the (i+1)th course.
 * 
 * You must find the minimum number of months needed to complete all the courses following these rules:
 * 
 * - You may start taking a course at any time if the prerequisites are met.
 * - Any number of courses can be taken at the same time.
 * 
 * Return the minimum number of months needed to complete all the courses.
 * 
 * Note: The test cases are generated such that it is possible to complete every course
 * (i.e., the graph is a directed acyclic graph).

 * * Example 1  :
 * * Input      : n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
 * * Output     : 8
 * 
 * * Example 2  :
 * * Input      : n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
 * * Output     : 12
 * 
 * https://leetcode.com/problems/find-all-people-with-secret/description/
 * 
 */

// ! Topological Sort

// ! Google, Uber

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
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
typedef std::pair<int, int> P;

void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

// * Directed Graph Adj
std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<int> &indegree,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0] - 1, v = it[1] - 1;
    adj[u].push_back(v);
    indegree[v]++;
  }
  return adj;
}

// * ------------------------- APPROACH: Optimal  -------------------------`
// * Topological Sort
// * TIME COMPLEXITY  O(V + E)
// * SPACE COMPLEXITY O(V + E)
int minimumTime(int n, std::vector<int> &time, std::vector<std::vector<int>> &relations) {
  std::vector<int> indegree(n, 0);
  std::unordered_map<int, std::vector<int>> adj = constructadj(indegree, relations);
  printAdjList(adj); // * for debugging
  
  // * 1. stores the max time to complete each course
  std::vector<int> max_course_time(n, 0);

  // * 2. Save all the courses without pre-requisites (i.e., indegree[course] = 0)
  std::queue<int> q;
  for (int course = 0; course < n; ++course) {
    if (indegree[course] == 0) {
      q.push(course);
      max_course_time[course] = time[course]; // * since these course do not have any pre-requisites
    }
  }
  // printArr(max_course_time); // * For Debugging

  // * 3. Topological Sort
  int months = 0;
  while (!q.empty()) {
    auto course = q.front();
    q.pop();

    // * Go to all next courses possible
    for (auto &next_course: adj[course]) {
      // * Finishing next_course of v will depend on the maximum time of its pre-requisites course
      max_course_time[next_course] = std::max(max_course_time[next_course], max_course_time[course] + time[next_course]);
      // std::cout << next_course << " -> " << max_course_time[next_course] << std::endl;
      indegree[next_course]--;
      if (indegree[next_course] == 0) {
        q.push(next_course);
      }
    }
  }
  // printArr(max_course_time); // * For Debugging

  return *max_element(begin(max_course_time), end(max_course_time));
}

int main(void) {
  // * testcase 1
  // int n = 3;
  // std::vector<int> time = {3, 2, 5};
  // std::vector<std::vector<int>> edges = {{1, 3}, {2, 3}};

  // * testcase 2
  int n = 5;
  std::vector<int> time = {1, 2, 3, 4, 5};
  std::vector<std::vector<int>> edges = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};

  std::cout << "Months: ";
  printArr(time);
  std::cout << "-------- edges -------- " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = minimumTime(n, time, edges);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-parallel-courses-III.cpp -o output && ./output
