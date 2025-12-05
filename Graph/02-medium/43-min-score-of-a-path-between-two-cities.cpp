/*
 * Leetcode - 2477
 * Minimum Score of a Path Between Two Cities
 * 
 * You are given a positive integer n representing n cities numbered from 1 to n. 
 * You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a 
 * bidirectional road between cities ai and bi with a distance equal to distancei. 
 * The cities graph is not necessarily connected.
 * 
 * The score of a path between two cities is defined as the minimum distance of a road in this path.
 * 
 * Return the minimum possible score of a path between cities 1 and n.
 
 * - A path is a sequence of roads between two cities.
 * - It is allowed for a path to contain the same road multiple times, and you can visit cities 1 
 *   and n multiple times along the path.
 * - The test cases are generated such that there is at least one path between 1 and n.

 * Example 1:
 * Input       : n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
 * Output      : 5
 * Explanation : The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4.
 *               The score of this path is min(9,5) = 5. It can be shown that no other path has less score.
 * 
 * Example 2:
 * Input       : n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
 * Output      : 2
 * Explanation : The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. 
 *               The score of this path is min(2,2,4,7) = 2.

 * https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

// ! Google

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

void printAdjList(std::unordered_map<int, std::vector<std::pair<int, int>>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    for (auto &it : vec) {
      std::cout << "(" << it.first << " " << it.second << ") ";
    }
    std::cout << std::endl;
  }
}

std::unordered_map<int, std::vector<std::pair<int, int>>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1], w = it[2];
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  return adj;
}

void dfs(
    int u,
    int &result,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<std::pair<int, int>>> &adj)
{
  visited[u] = true;
  for (auto &[v, w] : adj[u]) {
    result = std::min(result, w);
    if (!visited[v]) {
      dfs(v, result, visited, adj);
    }
  }
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int minScoreDFS(int n, std::vector<std::vector<int>> &roads) {
  // * 1. Create Adj list
  std::unordered_map<int, std::vector<std::pair<int, int>>> adj = constructadj(roads);
  printAdjList(adj); // * For Debugging

  std::vector<bool> visited(n, false);
  
  // * 2. save all the ngbr of '1' into queue
  int result = INT_MAX;
  dfs(1, result, visited, adj);
  
  return result;
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int minScore(int n, std::vector<std::vector<int>> &roads) {
  // * 1. Create Adj list
  std::unordered_map<int, std::vector<std::pair<int, int>>> adj = constructadj(roads);
  printAdjList(adj); // * For Debugging
  
  // * 2. Start from 1
  std::queue<int> q;
  q.push(1);
  
  // * 3. BFS
  std::vector<bool> visited(n, false);
  int min_path = INT_MAX;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    
    for (auto &[v, w] : adj[u]) {
        min_path = std::min(min_path, w);
      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }

  return min_path;
}

int main(void) {
  // * testcase 1
  // int n = 4;
  // std::vector<std::vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};

  // * testcase 2
  int n = 2;
  std::vector<std::vector<int>> roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};

  std::cout << "-------- blue edges -------- " << std::endl;
  for (auto &vec : roads)
    printArr(vec);

  int ans = minScoreDFS(n, roads);
  // int ans = minScoreBFS(n, roads);
  std::cout << "Minimum score: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 43-min-score-of-a-path-between-two-cities.cpp -o output && ./output

