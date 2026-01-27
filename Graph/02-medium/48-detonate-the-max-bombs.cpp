/*
 * Leetcode - 2101
 * Detonate the Maximum Bombs
 * 
 * You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
 * This area is in the shape of a circle with the center as the location of the bomb.

 * The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi 
 * denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the 
 * radius of its range.

 * You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that
 * lie in its range. These bombs will further detonate the bombs that lie in their ranges.
 * 
 * Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed 
 * to detonate only one bomb.
 * 
 * Example 1  :
 * Input      : bombs = [[2,1,3],[6,1,4]]
 * Output     : 2

 * Example 2  :
 * Input      : bombs = [[1,1,5],[10,10,5]]
 * Output     : 1
 
 * Example 3  :
 * Input      : bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
 * Output     : 1
 
 * https://leetcode.com/problems/count-the-number-of-complete-components/description/
*/

// ! Google

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

typedef long long ll;

void dfs(
    int u, int &bombs,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<int>> &adj)
{
  bombs += 1;
  visited[u]= true;
  for (auto &v: adj[u]) {
    if (!visited[v]) {
      dfs(v, bombs, visited, adj);
    }
  }
}

int bfs(int node, std::unordered_map<int, std::vector<int>> &adj) {
  std::unordered_set<int> visited;
  visited.insert(node);

  std::queue<int> q;
  q.push(node);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v: adj[u]) {
      if (visited.find(v) == visited.end()) {
        visited.insert(v);
        q.push(v);
      }
    }
  }

  return (int)visited.size();
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Calculate count of vertices & edges for each subgraph and check if the following formula is valid
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
int maximumDetonationDFS(std::vector<std::vector<int>> &edges) {
  int n = edges.size();
  
  // * 1. Construct adj matrix
  std::unordered_map<int, std::vector<int>> adj;
  for (int i = 0; i < n; ++i) {
    ll x1 = (ll)edges[i][0], y1 = (ll)edges[i][1];
    ll r_sqr = (edges[i][2] * edges[i][2]) * 1ll;
    for (int j = 0; j < n; ++j) {
      if (i == j) // * same bomb
        continue;

      ll x2 = (ll)edges[j][0], y2 = (ll)edges[j][1];
      ll dx = (x2 - x1), dy = (y2 - y1);
      // * caculate distance b/w two coordinates
      ll d_sqr = (dx * dx) + (dy * dy);
      // std::cout << r_sqr << " " << d_sqr << std::endl;
      if (r_sqr >= d_sqr) {
        adj[i].push_back(j);
      }
    }
  }
  // printAdjList(adj); // * For Debugging
  
  // * 2. DFS for every ith bomb and check how far it can reach
  int max_bombs = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<bool> visited(n, false);
    int bombs = 0;
    dfs(i, bombs, visited, adj);
    max_bombs = std::max(max_bombs, bombs);
  }

  return max_bombs;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
int maximumDetonationBFS(std::vector<std::vector<int>> &edges) {
  int n = edges.size();

  // * 1. Construct adj matrix
  std::unordered_map<int, std::vector<int>> adj;
  for (int i = 0; i < n; ++i) {
    ll x1 = (ll)edges[i][0], y1 = (ll)edges[i][1];
    ll r_sqr = (edges[i][2] * edges[i][2]) * 1ll;
    for (int j = 0; j < n; ++j) {
      if (i == j) // * same bomb
        continue;
      
      ll x2 = (ll)edges[j][0], y2 = (ll)edges[j][1];
      ll dist_sqr = (x2 - x1) * (x2 - x2) + (y2 - y1) * (y2 - y1);
      if (r_sqr >= dist_sqr) {
        adj[i].push_back(j);
      }
    }
  }
  // printAdjList(adj); // * For Debugging

  int max_bombs = 0;
  // * 2. BFS for every ith bomb and check how far it can reach
  for (int u = 0; u < n; ++u) {
    int bombs = bfs(u, adj);
    max_bombs = std::max(max_bombs, bombs);
  }

  return max_bombs;
}

int main(void) {
  // * testcase 1 // * bombs denotate = 2
  // std::vector<std::vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};

  // * testcase 2 // * bombs denotate = 1
  // std::vector<std::vector<int>> bombs = {{1, 1, 5}, {10, 10, 5}};

  // * testcase 3 // * bombs denotate = 5
  std::vector<std::vector<int>> bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};

  std::cout << "------------ Bombs -------------" << std::endl;
  for (auto &vec : bombs)
    printArr(vec);

  // int ans = maximumDetonationDFS(bombs);
  int ans = maximumDetonationBFS(bombs);
  std::cout << "Bombs Denotate: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 48-detonate-the-max-bombs.cpp -o output && ./output

 