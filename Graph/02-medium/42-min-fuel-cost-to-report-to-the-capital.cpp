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

using namespace std;

// ! Microsoft

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

long long dfs(int u, int parent, long long& res, int &seats,
              unordered_map<int, vector<int>>& adj) {
    int passengers = 0;
    for (auto& v : adj[u]) {
        if (v == parent)
            continue;

        int p = dfs(v, u, res, seats, adj);
        // cout << "u: " << u << ", p: " << p << endl;
        passengers += p;
        res += ceil((double)p / seats);
    }
    return passengers + 1;
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * At level get the number of passengers and divide it by seats available & take the ceil of division
// * then add the result to final answer.
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
long long minimumFuelCost(int seats, vector<vector<int>> &roads)
{
  // * 1. Create Adj list
  unordered_map<int, vector<int>> adj;
  for (auto &it: roads) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // printAdjList(adj); // * For Debugging

  // * DFS
  long long res = 0;
  dfs(0, -1, res, seats, adj);
  return res;
}

int main(void) {
  // * testcase 1
  // int seats = 3;
  // vector<vector<int>> roads = {{0, 1}, {0, 2}, {0, 3}};

  // * testcase 2
  int seats = 2;
  vector<vector<int>> roads = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};

  cout << "-------- blue edges -------- " << endl;
  for (auto &vec : roads)
    printArr(vec);

  long long ans = minimumFuelCost(seats, roads);
  cout << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 42-min-fuel-cost-to-report-to-the-capital.cpp -o output && ./output

/*
* roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]] and seats = 2
* Step-by-Step Execution1.

* Branch 1: 0 -> 1 -> 3 -> 2
* dfs(2): It is a leaf node.
* - Loops over no children.
* - Returns 0 + 1 = 1 passenger.
* 
* dfs(3): Processes child 2.
* - Receives p = 1 from city 2.
* - Adds fuel: ceil(1 / 2) = 1. Running res = 1.
* - Returns 1 + 1 = 2 passengers.
* 
* dfs(1): Processes child 3.
* - Receives p = 2 from city 3.
* - Adds fuel: ceil(2 / 2) = 1. Running res = 2.
* - Returns 2 + 1 = 3 passengers.
* 
* Back at dfs(0): Processes child 1.
* - Receives p = 3 from city 1.
* - Adds fuel: ceil(3 / 2) = 2. Running res = 4.
* - Cumulative passengers = 3.
* 
* 2. Branch 2: 0 -> 4 -> 6
* dfs(6): It is a leaf node.
* - Loops over no children.
* - Returns 0 + 1 = 1 passenger.
* 
* dfs(4): Processes child 6.
* - Receives p = 1 from city 6.
* - Adds fuel: ceil(1 / 2) = 1. Running res = 5.
* - Returns 1 + 1 = 2 passengers.
* 
* Back at dfs(0): Processes child 4.
* - Receives p = 2 from city 4.
* - Adds fuel: ceil(2 / 2) = 1. Running res = 6.
* - Cumulative passengers = 3 + 2 = 5.
* 
* 3. Branch 3: 0 -> 5
* - dfs(5): It is a leaf node.
* - Loops over no children.
* - Returns 0 + 1 = 1 passenger.
* 
* Back at dfs(0): Processes child 5.
* - Receives p = 1 from city 5.
* - Adds fuel: ceil(1 / 2) = 1. Running res = 7.
* - Cumulative passengers = 5 + 1 = 6.
* 
* Final Summary
* Total Fuel: 7.
* Total Passengers at Root: 6 (plus 1 at city 0 equals 7 total people).
*/
