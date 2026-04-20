/*
 * Leetcode - 2924
 * Find Champion II
 * 
 * There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.
 * You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG,
 * where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.
 * 
 * A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.
 * 
 * Team a will be the champion of the tournament if there is no team b that is stronger than team a.
 * 
 * Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.
 * 
 * Example 2    :
 * Input        : n = 3, edges = [[0,1],[1,2]]
 * Output       : 0
 * Explanation  : 
 * 
 * Example 1    :
 * Input        : n = 4, edges = [[0,2],[1,3],[1,2]]
 * Output       : -1
 * Explanation  : 
 * 
 * https://leetcode.com/problems/find-champion-ii/
*/

#include <queue>
#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Find the indgree of 'v' node
// * TIME COMPLEXITY O(M + N) 
// * SPACE COMPLEXITY O(n)
int findChampion(int n, vector<vector<int>>& edges) {
  // * find the indegree of all edges
  vector<int> indegree(n, 0);
  for (auto &it : edges) { // * O(M)
    int u = it[0], v = it[1];
    indegree[v]++;
  }

  int champ = -1;
  for (int i = 0; i < n; ++i) { // * O(N)
    if (indegree[i] == 0) {
      // * only one can be champion
      if (champ != -1)
        return -1;
      
      champ = i;
    }
  }

  return champ;
}

int main(void) {
  // * testcase 1
  int n = 3;
  vector<vector<int>> edges = {{0, 1}, {0, 2}};
  
  // * testcase 2
  // int n = 4;
  // vector<vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};

  cout << "Edges" << endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = findChampion(n, edges);
  cout << "Champion: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 27-find-champion-II.cpp -o output && ./output

 