/*
 * Leetcode - 2467
 * Most Profitable Path in a Tree
 * 
 * There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. 
 * You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that 
 * there is an edge between nodes ai and bi in the tree.
 * 
 * At every node i, there is a gate. You are also given an array of even integers amount, 
 * where amount[i] represents:
 * 
 * the price needed to open the gate at node i, if amount[i] is negative, or,
 * the cash reward obtained on opening the gate at node i, otherwise.
 * 
 * The game goes on as follows:
 * - Initially, Alice is at node 0 and Bob is at node bob.
 * - At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, 
 *   while Bob moves towards node 0.
 * - For every node along their path, Alice and Bob either spend money to open the gate at that node, 
 *   or accept the reward. Note that:
 * -- If the gate is already open, no price will be required, nor will there be any cash reward.
 * -- If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. 
 *    In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, 
 *    if the reward at the gate is c, both of them receive c / 2 each.
 * 
 * - If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. 
 *   Note that these events are independent of each other.
 * 
 * Return the maximum net income Alice can have if she travels towards the optimal leaf node.

 * Example 1  :
 * Input      : edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
 * Output     : 6

 * Example 2  :
 * Input      : edges = [[0,1]], bob = 1, amount = [-7280,2350]
 * Output     : -7280

 * https://leetcode.com/problems/most-profitable-path-in-a-tree/
*/

// ! Apple, Amazon, Google

#include <vector>
#include <climits>
#include <iostream>
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

void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}
const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int r, int c, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  
  const auto is_safe = [&](const int &row, const int &col) {
    return row >= 0 && row < m && col >= 0 && col < n;
  };
  
  int original_value = grid[r][c];
  grid[r][c] = 0;

  int max_gold = 0;
  for (auto &dir: dirs) { // * Go to all 4 directions
    int dr = r + dir[0], dc = c + dir[1];
    if (is_safe(dr, dc) && grid[dr][dc] != 0) {
      max_gold = std::max(max_gold, dfs(dr, dc, grid));
    }
  }

  grid[r][c] = original_value;
  return original_value + max_gold;
}

bool dfs_bob(
    int u, int time,
    std::vector<bool> &visited,
    std::unordered_map<int, int> &bob_time_map,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[u] = true;
  bob_time_map[u] = time;
  
  if (u == 0) { // * Reached Destination
    return true;
  }

  for (auto &v: adj[u]) {
    if (!visited[v]) {
      if (dfs_bob(v, time + 1, visited, bob_time_map, adj))
        return true;
    }
  }

  bob_time_map.erase(u);
  return false;
}

void dfs_alice(
    int u, int time,
    int income, int &max_alice_income,
    std::vector<bool> &visited,
    std::vector<int> &amount,
    std::unordered_map<int, int> &bob_time_map,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[u] = true;

  // * Check if bob never reached this node or bob reached after alice
  if (bob_time_map.find(u) == bob_time_map.end() || time < bob_time_map[u]) {
    income += amount[u];
  } else if (time == bob_time_map[u]) {
    income += (amount[u] / 2);
  }

  // * Alice reached any leaf node & it should not be the starting node [For Alice Starting Node = 0]
  if (adj[u].size() == 1 && u != 0) { // * update the max_alice_income for alice
    max_alice_income = std::max(max_alice_income, income);
  }
  
  // * Go to it's neighbours
  for (auto &v: adj[u]) {
    if (!visited[v]) {
      dfs_alice(v, time + 1, income, max_alice_income, visited, amount, bob_time_map, adj);
    }
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * DFS for both Bob & Alice
// * TIME COMPLEXITY 
// * SPACE COMPLEXITY 
int getMaximumGold(int bob, std::vector<int> amount, std::vector<std::vector<int>> &edges) {
  int n = amount.size();

  // * 1. Create Adj List
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  printAdjList(adj);

  // * 2. DFS on bob for finding time to reach each node till 0
  std::unordered_map<int, int> bob_time_map;
  int time = 0;
  std::vector<bool> visited(n, false);
  dfs_bob(bob, time, visited, bob_time_map, adj);
  // for (auto &[k, v]: bob_time_map) { // * For Debugging
  //   std::cout << "node: " << k <<  ", Time: " << v << std::endl;
  // }
  
  // * 3. DFS on alice for finding max_income to reach any leaf node
  int max_alice_income = INT_MIN;
  visited.assign(n, false);
  dfs_alice(0, 0, 0, max_alice_income, visited, amount, bob_time_map, adj);

  return max_alice_income;
}

int main(void) {
  // * testcase 1
  // int bob = 3;
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
  // std::vector<int> amount = {-2, 4, 2, -4, 6};
  
  // * testcase 2
  // int bob = 1;
  // std::vector<std::vector<int>> edges = {{0, 1}};
  // std::vector<int> amount = {-7280, 2350};
  
  // * testcase 2
  int bob = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
  std::vector<int> amount = {-5644, -6018, 1188, -8502};

  std::cout << "Amount: ";
  printArr(amount);
  std::cout << "------------ Edges -------------" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = getMaximumGold(bob, amount, edges);
  std::cout << "Maximum Gold: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 53-most-profitable-path-in-a-tree.cpp -o output && ./output

 