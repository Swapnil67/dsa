/*
 * Leetcode - 2924
 * Find Champion II
 * 
 * There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.
 TODO
*/

#include <queue>
#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Find the indgree of 'v' node
// * TIME COMPLEXITY O(M + N) 
// * SPACE COMPLEXITY O(n)
int findChampion(int n, std::vector<std::vector<int>>& edges) {
  // * find the indegree of all edges
  std::vector<int> indegree(n, 0);
  for (auto &it : edges) { // * O(M)
    int u = it[0], v = it[1];
    indegree[v]++;
  }

  int champ = -1;
  for (int i = 0; i < n; ++i) { // * O(N)
    if (indegree[i] == 0) {
      // * only one can be champion
      if (champ != -1) {
        return -1;
      }
      champ = i;
    }
  }

  return champ;
}

int main(void) {
  // * testcase 1
  // int n = 3;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}};
  
  // * testcase 2
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};

  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = findChampion(n, edges);
  std::cout << "Champion: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 27-find-champion-II.cpp -o output && ./output

 