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

bool dfs_bob(
    int u, int time,
    vector<bool> &visited,
    unordered_map<int, int> &bob_time_map,
    unordered_map<int, vector<int>> &adj)
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

  bob_time_map.erase(u); // * Remove the node from bob path
  return false;
}

void dfs_alice(
    int u, int time,
    int income, int &max_alice_income,
    vector<bool> &visited,
    vector<int> &amount,
    unordered_map<int, int> &bob_time_map,
    unordered_map<int, vector<int>> &adj)
{
  visited[u] = true;

  // * Check if bob never reached this node or bob reached after alice
  if (bob_time_map.count(u) == 0 || time < bob_time_map[u]) {
    income += amount[u];
  } else if (time == bob_time_map[u]) {
    income += (amount[u] / 2);
  }

  // * Alice reached any leaf node & it should not be the starting node [For Alice Starting Node = 0]
  if (adj[u].size() == 1 && u != 0) { // * update the max_alice_income for alice
    max_alice_income = max(max_alice_income, income);
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
// * TIME COMPLEXITY   O(n)
// * SPACE COMPLEXITY  O(n) 
int mostProfitablePath(int bob, vector<int> amount, vector<vector<int>> &edges) {
  // * 1. Create Adj List
  unordered_map<int, vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // printAdjList(adj); // * For Debugging

  // * 2. DFS on bob for finding time to reach each node till 0
  int n = amount.size();
  vector<bool> visited(n, false);
  unordered_map<int, int> bob_time_map;
  dfs_bob(bob, 0, visited, bob_time_map, adj);
  // for (auto &[k, v]: bob_time_map) { // * For Debugging
  //   cout << "node: " << k <<  ", Time: " << v << endl;
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
  // vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
  // vector<int> amount = {-2, 4, 2, -4, 6};
  
  // * testcase 2
  // int bob = 1;
  // vector<vector<int>> edges = {{0, 1}};
  // vector<int> amount = {-7280, 2350};
  
  // * testcase 2
  int bob = 3;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
  vector<int> amount = {-5644, -6018, 1188, -8502};

  cout << "Amount: ";
  printArr(amount);
  cout << "------------ Edges -------------" << endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = mostProfitablePath(bob, amount, edges);
  cout << "Maximum Gold: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 53-most-profitable-path-in-a-tree.cpp -o output && ./output

 