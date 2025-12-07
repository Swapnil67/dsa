#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * Print adjacency list
void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef std::pair<int, int> pii;
typedef std::pair<int, pii> P;

// * 01 - Maximum Number of Points From Grid Queries
// std::vector<int> maxPoints(std::vector<int> &queries, std::vector<std::vector<int>> &grid) {
// TODO
// }

// * 02 - Maximum Number of K-Divisible Components
// int maxKDivisibleComponents(
//     int n, int k,
//     std::vector<int> &values,
//     std::vector<std::vector<int>> &edges)
// {
// TODO
// }

// * 03 - Sliding Puzzle
// int slidingPuzzle(std::vector<std::vector<int>> &board) {
// TODO
// }

// * 04 - Largest Color Value in a Directed Graph
// int largestPathValue(std::string &colors, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 05 - Minimum Number of Days to Eat N Oranges 
// int minDaysBFS(int n) {
// TODO
// }

// * 06 - Find All People With Secret
// std::vector<int> findAllPeople(int n, int first_person, std::vector<std::vector<int>> &meetings) {
// TODO
// }

// * 07 - Word Ladder
// int ladderLength(
//     std::string begin_word,
//     std::string end_word,
//     std::vector<std::string> &word_list) {
// TODO
// }

// * 08 - Word Ladder II
// std::vector<std::vector<std::string>> findLadders(
//     std::string begin_word,
//     std::string end_word,
//     std::vector<std::string> &word_list)
// {
// TODO
// }

std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<int> &indegree,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0] - 1, v = it[1] - 1;
    indegree[v]++;
    adj[u].push_back(v);
  }
  return adj;
}

// * 09 - Parallel Courses III
int minimumTime(
    int n,
    std::vector<int> &time,
    std::vector<std::vector<int>> &relations)
{
  std::vector<int> indegree(n, 0);
  std::unordered_map<int, std::vector<int>> adj = constructadj(indegree, relations);
  printAdjList(adj);

  std::vector<int> max_course_time(n, 0);
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
      max_course_time[i] = time[i];
    }
  }

  printArr(max_course_time);
  int months = 0;
  while (!q.empty()) {
    auto course = q.front();
    q.pop();

    for (auto &next_course : adj[course]) {
      max_course_time[next_course] = std::max(max_course_time[next_course],
                                              max_course_time[course] + time[next_course]);
      indegree[next_course]--;
      if (indegree[next_course] == 0)
        q.push(next_course);
    }
  }

  printArr(max_course_time);
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
// * g++ --std=c++20 practice.cpp -o output && ./output