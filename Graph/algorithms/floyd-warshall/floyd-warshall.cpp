/*
 * Floyd Warshall
 *
 * Example 2
 * Input  : dist[][] = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}}
 * Output : {{0, 1, 7}, {1, 0, 6}, {-1, -1, 0}}
 * 
 * https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/

// ! Google, Uber

#include <vector>
#include <climits>
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(N^2) (input matrix)
void floydWarshall(std::vector<std::vector<int>> &dist) {
  int m = dist.size(), n = dist[0].size();

  // * Make diagnol to 0
  for (int i = 0; i < n; ++i)
    dist[i][i] = 0;

  for (int via = 0; via < m; ++via) {
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (dist[r][via] == INT_MAX || dist[via][c] == INT_MAX)
          continue;

        // * dist[1][0] = dist[1][0] + dist[0][0] (going via 0)
        dist[r][c] = std::min(dist[r][c], dist[r][via] + dist[via][c]);
      }
    }
  }
  
  // * To find -ve loop. since going from 0 -> 0 should not be -ve number
  // for (int r = 0; r < m; ++r) {
  // * loop exists
  //   if (dist[r][r] < 0) return true;
  // }

}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> dist = {{0, 4, INT_MAX, 5, INT_MAX},
                                         {INT_MAX, 0, 1, INT_MAX, 6},
                                         {2, INT_MAX, 0, 3, INT_MAX},
                                         {INT_MAX, INT_MAX, 1, 0, 2},
                                         {1, INT_MAX, INT_MAX, 4, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> dist = {{0, -1, 2}, {1, 0, INT_MAX}, {3, 1, 0}};

  // * testcase 3
  // std::vector<std::vector<int>> dist = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};

  std::cout << "Dist" << std::endl;
  for (auto &vec : dist)
    printArr(vec);

  floydWarshall(dist);
  std::cout << "Answer" << std::endl;
  for (auto &vec : dist)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 floyd-warshall.cpp -o output && ./output

