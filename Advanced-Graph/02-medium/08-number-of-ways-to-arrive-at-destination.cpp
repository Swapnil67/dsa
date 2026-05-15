/*
* Leetcode - 1976
* Number of Ways to Arrive at Destination
*
* You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads 
* between some intersections. The inputs are generated such that you can reach any intersection 
* from any other intersection and that there is at most one road between any two intersections.
*
* You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] 
* means that there is a road between intersections ui and vi that takes timei minutes to travel. 
* You want to know in how many ways you can travel from intersection 0 to intersection n - 1 
* in the shortest amount of time.

* Return the "number of ways" you can arrive at your destination in the "shortest amount of time". 
* Since the answer may be large, return it modulo 109 + 7.
*
* Example 1:
* Input         : n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]   
* Output        : 4
* Explanation   : The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
*                 The four ways to get there in 7 minutes are:
*                 - 0 ➝ 6
*                 - 0 ➝ 4 ➝ 6
*                 - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
*                 - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
*
* https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
* https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
*/

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

typedef pair<int, int> pii;
typedef pair<long long, int> pli;

void printAdjList(unordered_map<int, vector<pii>> &adj) {
  cout << "----------------- Adj ------------------" << endl;
  for (auto &[u, vec] : adj) {
    cout << u << " -> "; 
    for (auto &p: vec) {
      cout << "(" << p.first << " " << p.second << ") ";
    }
    cout << endl;
  }
  cout << "----------------- Adj ------------------" << endl;
}

unordered_map<int, vector<pii>> constructadj(vector<vector<int>> &roads) {
  unordered_map<int, vector<pii>> adj;
  for (auto &r: roads) {
    int u = r[0], v = r[1], t = r[2];
    adj[u].push_back(make_pair(v, t));
    adj[v].push_back(make_pair(u, t));
  }
  return adj;
}

// * ------------------------- Approach 2: Optimal -------------------------
// * BFS + Dijkstra's Algorithm
// * TIME COMPLEXITY O(E + Vlogv)
// * SPACE COMPLEXITY O(V + E)
int countPaths(int n, vector<vector<int>> &roads) {
  // * Construct adj 
  unordered_map<int, vector<pii>> adj = constructadj(roads);
  printAdjList(adj); // * For Debugging
  
  // * Min Heap = {dist, node}
  priority_queue<pli, vector<pli>, greater<>> min_heap;
  min_heap.push({0, 0});
  
  vector<int> ways(n, 0);
  ways[0] = 1;

  vector<long long> dist(n, LLONG_MAX);
  dist[0] = 0;
  
  // * BFS (Dijkstra)
  int mod = (int)(1e9 + 7);
  while (!min_heap.empty()) {
    auto [t1, u] = min_heap.top();
    min_heap.pop();

    for (auto &[v, t2]: adj[u])  {
      long long total_time = t1 + t2;
      if (dist[v] > total_time) {
        dist[v] = total_time;
        min_heap.push({total_time, v});
        ways[v] = ways[u]; // * Since we are coming on this node for the first time
      }
      else if (dist[v] == total_time) {
        // * we can reach the same dest in same time from multiple nodes(ways)
        // * we need to add all possible ways
        ways[v] = (ways[v] + ways[u]) % mod;
      }
    }
  }
  // printArr(ways);
  return ways[n - 1] % mod;
}

int main(void) {
  // * testcase 1
  int n = 7;
  vector<vector<int>> roads = {
      {0, 6, 7},
      {0, 1, 2},
      {1, 2, 3},
      {1, 3, 3},
      {6, 3, 3},
      {3, 5, 1},
      {6, 5, 1},
      {2, 5, 1},
      {0, 4, 5},
      {4, 6, 2}};

  // * testcase 2
  // int n = 2;
  // vector<vector<int>> roads = {{1, 0, 10}};

  cout << "n: " << n << endl;
  cout << "roads: " << endl;
  for (auto &vec : roads)
    printArr(vec);

  int ans = countPaths(n, roads);
  cout << "Number of Ways to Arrive at Destination: " << ans << endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 08-number-of-ways-to-arrive-at-destination.cpp -o output && ./output