/*
 * Floyd Warshall
 *
 * Example 1
 * Input  : n = 3, m = 3, src = 1, dst = 3 dist = {{1, 2, 2}, {1, 3, 2}, {2, 3, -1}}
 * Output : 1
 *
 * Example 2
 * Input  : n = 4, m = 4, src = 1, dst = 4 dist = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}}
 * Output : 1
 * 
 * https://www.naukri.com/code360/problems/bellmon-ford_2041977
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
int floydWarshall(
    int &n, int m, int &src, int &dst,
    std::vector<std::vector<int>> &edges)
{
  // * Create an Adj Matrix
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
  for (auto &it: edges) {
    int u = it[0] - 1, v = it[1] - 1, w = it[2];
    dist[u][v] = w;
  }
  // std::cout << "Dist Adj" << std::endl;
  // for (auto &vec : dist)
  //   printArr(vec);

  // * Count the min dist from every 'V' to every other 'V'
  // * Distance to itself will be 0
  for (int i = 0; i < n; ++i)
    dist[i][i] = 0;

  for (int via = 0; via < m; ++via) {
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (dist[r][via] == INT_MAX || dist[via][c] == INT_MAX)
          continue;
        dist[r][c] = std::min(dist[r][c], dist[r][via] + dist[via][c]);
      }
    }
  }
  // std::cout << "Dist Adj" << std::endl;
  // for (auto &vec : dist)
  //   printArr(vec);

  return dist[src - 1][dst - 1];
}

int main(void) {
  // * testcase 1
  // int n = 3, m = 3, src = 1, dst = 3;
  // std::vector<std::vector<int>> dist = {{1, 2, 2}, {1, 3, 2}, {2, 3, -1}};

  // * testcase 2
  int n = 4, m = 4, src = 1, dst = 4;
  std::vector<std::vector<int>> dist = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}};

  std::cout << "n: " << n << ", src: " << src << ", dst: " << dst << std::endl;
  std::cout << "Dist" << std::endl;
  for (auto &vec : dist)
    printArr(vec);

  int ans = floydWarshall(n, m, src, dst, dist);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 floyd-warshall-2.cpp -o output && ./output

