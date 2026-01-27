/*
 * Leetcode - 310
 * Minimum Height Trees
 * 
 * A tree is an undirected graph in which any two vertices are connected by exactly one path.
 * In other words, any connected graph without simple cycles is a tree.
 * 
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi]
 * indicates that there is an undirected edge between the two nodes ai and bi in the tree,
 * you can choose any node of the tree as the root. When you select a node x as the root, 
 * the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  
 * are called minimum height trees (MHTs).

 * Return a list of all MHTs' root labels. You can return the answer in any order.
 * The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 * Example 1  :
 * Input      : n = 4, edges = [[1,0],[1,2],[1,3]]
 * Output     : [1]

 * Example 2  :
 * Input      : n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
 * Output     : [3,4]
 
 * https://leetcode.com/problems/minimum-height-trees/description/
 * https://www.naukri.com/code360/problems/roots-of-the-tree-having-minimum-height_1235193
*/

// ! Apple, Amazon, Google

#include <queue>
#include <vector>
#include <climits>
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

void printAdjList(unordered_map<int, vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

unordered_map<int, vector<int>> constructadj(vector<vector<int>> &edges) {
  unordered_map<int, vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

int bfs(int &n, int &root, unordered_map<int, vector<int>> &adj) {
  queue<int> q;
  q.push(root);

  vector<bool> visited(n, false);
  visited[root] = true;

  int level = 0;
  while(!q.empty()) {
    int N = q.size();
    bool visit = false;
    while (N--) {
      int u = q.front();
      q.pop();

      for (auto &v : adj[u]) {
        if (!visited[v]) {
          visit = true;
          visited[v] = true;
          q.push(v);
        }
      }
    }
    if (visit)
      level += 1;
  }

  return level;
}

// * ------------------------- APPROACH: Brute Force -------------------------
// ! TLE
// * Find MHTs for all possible nodes for 1 to n
// * n = num of nodes
// * V = num of vertices
// * E = num of edges
// * TIME COMPLEXITY O(n) * O(V + E)
// * SPACE COMPLEXITY O(n) * O(V + E)
vector<int> bruteForce(int n, vector<vector<int>> &edges) {
  // * 1. Create a default adj list
  unordered_map<int, vector<int>> adj = constructadj(edges);
  // printAdjList(adj);

  vector<int> ans;
  int min_height = INT_MAX;
  unordered_map<int, vector<int>> height_mp;

  // * 2. Find Minimum height for all possible roots and save it to map
  for (int u = 0; u < n; ++u) {
    int height = bfs(n, u, adj);
    std::cout << "u: " << u << ", height: " << height << std::endl;
    min_height = min(min_height, height);
    height_mp[height].push_back(u);
  }
  
  // * For Debugging
  // for (auto &[height, vec]: height_mp) {
  //   cout << "Height: " << height << endl;
  //   printArr(vec);
  // }
  return height_mp[min_height];
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Observations 
// * - Try to choose central nodes i.e., exclude leaf nodes
// * - Answer has atmost 2 nodes

// * n = num of nodes
// * V = num of vertices
// * E = num of edges
// * TIME COMPLEXITY O(n) * O(V + E)
// * SPACE COMPLEXITY O(n) * O(V + E)
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
  // * 1. Create a default adj list with indegree
  vector<int> indegree(n, 0);
  unordered_map<int, vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    // * since its undirected we need to add indegree for both
    indegree[u]++; 
    indegree[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // printArr(indegree);
  // printAdjList(adj);

  // * Kahn's Algo
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    // * Since we are excluding leaf nodes
    if (indegree[i] == 1) {
      // std::cout << i << std::endl;
      q.push(i);
    }
  }

  while (n > 2) { // * we'll have atmost two roots possible
    int N = q.size();
    n -= N;
    std::cout << n << std::endl;
    
    while (N--) {
      int u = q.front();
      q.pop();
      // std::cout << "u: " << u << std::endl;

      for (auto &v: adj[u]) {
        // std::cout << v << std::endl;
        indegree[v]--;
        if (indegree[v] == 1)
          q.push(v);
      }
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 4;
  // vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};

  // * testcase 2
  int n = 6;
  vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};

  cout << "------------ edges -------------" << endl;
  for (auto &vec : edges)
    printArr(vec);

  // vector<int> ans = bruteForce(n, edges);
  vector<int> ans = findMinHeightTrees(n, edges);
  cout << "Minimum Height Trees root: " << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 51-min-height-trees.cpp -o output && ./output

 