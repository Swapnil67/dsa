/*
 * Leetcode - 778
 * Swim in Rising Water
 *
 * You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
 * 
 * It starts raining, and water gradually rises over time. At time t, the water level is t, 
 * meaning any cell with elevation less than equal to t is submerged or reachable.
 * 
 * You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both
 * squares individually are at most t. You can swim infinite distances in zero time. 
 * Of course, you must stay within the boundaries of the grid during your swim.
 *
 * Return the minimum time until you can reach the bottom right square (n - 1, n - 1) 
 * if you start at the top left square (0, 0).
 * 
 * Example 1  :
 * Input      : tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * Output     : 3

 * Example 2  :
 * Input      : tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output     : 16
 * 
 * https://leetcode.com/problems/swim-in-rising-water/
*/

// ! Meta, Microsoft, Google, Amazon, Uber, Netflix, Flipkart

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

typedef std::vector<char> vc;

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
void printAdjList(std::unordered_map<T, std::vector<T>> &adj) {
  std::cout << "----- Adj List -----" << std::endl;
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

bool dfs(
    int num_tickets, std::string from_city,
    std::vector<std::string> &ans,
    std::vector<std::string> &path,
    std::unordered_map<std::string, std::vector<std::string>> &adj)
{
  path.push_back(from_city);

  // * We found the first lexical valid path
  if (path.size() == num_tickets + 1) {
    ans = path;
    return true;
  }

  // * Go to its neighbours
  std::vector<std::string>& neighbours = adj[from_city];
  for (int i = 0; i < neighbours.size(); ++i) {
    std::string to_city = neighbours[i];
    neighbours.erase(neighbours.begin() + i); // * so that we don't go into infinite loop

    if (dfs(num_tickets, to_city, ans, path, adj))
      return true;

    neighbours.push_back(to_city);
  }

  path.pop_back();
  return true;
}

void dfs2(
    std::string from_city,
    std::vector<std::string> &ans,
    std::unordered_map<std::string, std::vector<std::string>> &adj)
{
  while (!adj[from_city].empty()) {
    std::string to_city = adj[from_city].back();
    adj[from_city].pop_back();
    dfs2(to_city, ans, adj);
  }
  ans.push_back(from_city);
}

// * ------------------------- Approach 1: Optimal -------------------------
// ! TLE
// * Depth First Search
// * TIME COMPLEXITY O(E * V)
// * SPACE COMPLEXITY O(E * V)
std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
  // * Create a Adj list
  std::unordered_map<std::string, std::vector<std::string>> adj;
  for (auto &it: tickets) {
    auto from = it[0], to = it[1];
    adj[from].push_back(to);
  }
  // * Since we need in lexical order
  for (auto &[key, dest] : adj) {
    std::sort(begin(dest), end(dest));
  }
  // printAdjList(adj);

  int num_tickets = tickets.size();
  std::vector<std::string> ans;
  std::vector<std::string> path;
  dfs(num_tickets, "JFK", ans, path, adj);
  
  return path;
}

// * ------------------------- Approach 1: Optimal -------------------------
// * Hierholzer's Algorithm (Recursion)
// * This problem is an Eulerian Path problem:
// * TIME COMPLEXITY O(ElogE)
// * SPACE COMPLEXITY O(E)
std::vector<std::string> findItinerary2(std::vector<std::vector<std::string>>& tickets) {
  // * Create a Adj list
  std::unordered_map<std::string, std::vector<std::string>> adj;
  for (auto &it: tickets) {
    auto from = it[0], to = it[1];
    adj[from].push_back(to);
  }
  // * Since we need in lexical order
  for (auto &[key, dest] : adj) {
    std::sort(rbegin(dest), rend(dest));
  }
  printAdjList(adj);

  int num_tickets = tickets.size();
  std::vector<std::string> ans;
  dfs2("JFK", ans, adj);

  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<std::string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

  // * testcase 2
  std::vector<std::vector<std::string>> tickets = {{"JFK", "SFO"},
                                                   {"JFK", "ATL"},
                                                   {"SFO", "ATL"},
                                                   {"ATL", "JFK"},
                                                   {"ATL", "SFO"}};

  std::cout << "tickets: " << std::endl;
  for (auto &vec : tickets)
    printArr(vec);

  // std::vector<std::string> ans = findItinerary(tickets);
  std::vector<std::string> ans = findItinerary2(tickets);
  std::cout << "Itinerary" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-reconstruct-itinerary.cpp -o output && ./output