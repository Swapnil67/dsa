/*
 * Leetcode - 947
 * Most Stones Removed with Same Row or Column
 * 
 * On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
 * A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
 
 * Given an array `stones` of length `n` where stones[i] = [xi, yi] represents the location of the `ith` stone, 
 * return the largest possible number of stones that can be removed.
 * 
 * Example 1  :
 * Input      : stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output     : 5
 * 
 * Example 2  :
 * Input      : stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output     : 3
 * 
 * Example 3  :
 * Input      : stones = [[0,0]]
 * Output     : 0
 * 
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
*/

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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

int removeStones(std::vector<std::vector<int>> &stones) {
  return 0;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

  // * testcase 2
  // std::vector<std::vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};

  std::cout << "Stones: " << std::endl;
  for (auto &vec : stones)
    printArr(vec);

  int ans = removeStones(stones);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 22-most-stones-removed-with-same-row-or-column.cpp -o output && ./output

