/*
 * Leetcode - 2477
 * Minimum Fuel Cost to Report to the Capital
 * 
 * There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting
 * of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0.
 * You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a 
 * bidirectional road connecting cities ai and bi.
 * 
 * There is a meeting for the representatives of each city. The meeting is in the capital city.
 * 
 * There is a car in each city. You are given an integer seats that indicates the number of seats in each car.
 * 
 * A representative can use the car in their city to travel or change the car 
 * and ride with another representative. The cost of traveling between two cities is one liter of fuel.
 * 
 * Return the minimum number of liters of fuel to reach the capital city.

 * Example 1:
 * Input     : roads = [[0,1],[0,2],[0,3]], seats = 5
 * Output    : 3
 * 
 * Example 2:
 * Input     : roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
 * Output    : 7

 * https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital
*/

#include <vector>
#include <math.h>
#include <iostream>
#include <unordered_map>

// ! Microsoft

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
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

long long dfs(int u, int parent, long long& res, int &seats,
              std::unordered_map<int, std::vector<int>>& adj) {
    int passengers = 0;
    for (auto& v : adj[u]) {
        if (v == parent)
            continue;
        int p = dfs(v, u, res, seats, adj);
        // std::cout << "u: " << u << ", p: " << p << std::endl;
        passengers += p;
        res += std::ceil((double)p / seats);
    }
    return passengers + 1;
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * At level get the number of passengers and divide it by seats available & take the ceil of division
// * then add the result to final answer.
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
long long minimumFuelCost(int seats, std::vector<std::vector<int>> &roads)
{
  // * 1. Create Adj list
  std::unordered_map<int, std::vector<int>> adj = constructadj(roads);
  // printAdjList(adj); // * For Debugging

  // * DFS
  long long res = 0;
  dfs(0, -1, res, seats, adj);
  return res;
}

int main(void) {
  // * testcase 1
  // int seats = 3;
  // std::vector<std::vector<int>> roads = {{0, 1}, {0, 2}, {0, 3}};

  // * testcase 2
  int seats = 2;
  std::vector<std::vector<int>> roads = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};

  std::cout << "-------- blue edges -------- " << std::endl;
  for (auto &vec : roads)
    printArr(vec);

  long long ans = minimumFuelCost(seats, roads);
  std::cout << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 42-min-fuel-cost-to-report-to-the-capital.cpp -o output && ./output

