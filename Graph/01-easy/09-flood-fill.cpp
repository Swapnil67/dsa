/**
 * * Leetcode - 733
 * * Flood Fill
 * 
 * * You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel 
 * * value of the image. You are also given three integers sr, sc, and color. 
 * * Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

 * * To perform a flood fill:
 * * - Begin with the starting pixel and change its color to color.
 * * - Perform the same process for each pixel that is directly adjacent (pixels that share a side with
 * *   the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
 * * - Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their 
 * *   color if it matches the original color of the starting pixel.
 * * - The process stops when there are no more adjacent pixels of the original color to update.

 * * Return the modified image after performing the flood fill.

 * * Example 1  :
 * * Input      : image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * * Output     : [[2,2,2],[2,2,0],[2,0,1]]
 * 
 * * Example 2  :
 * * Input      : image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
 * * Output     : [[0,0,0],[0,0,0]]
 * 
 * * https://leetcode.com/problems/flood-fill/description/
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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

const std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y, std::vector<std::vector<int>> &res, int &initial_color, int &new_color) {
  int m = res.size();
  int n = res[0].size();
  std::cout << x << " " << y << std::endl;

  res[x][y] = new_color;

  for (auto &dir: dirs) {
    int new_x = x + dir[0];
    int new_y = y + dir[1];
    if ((new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) &&
        (res[new_x][new_y] == initial_color && res[new_x][new_y] != new_color))
    {
      dfs(new_x, new_y, res, initial_color, new_color);
    }
  }
} 

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color) {
  std::vector<std::vector<int>> res = image;
  int initial_color = image[sr][sc];
  dfs(sr, sc, res, initial_color, color);
  return res;
}

int main(void) {
  // * testcase 1
  int sr = 1, sc = 1, color = 2;
  std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  
  // * testcase 2
  // int sr = 0, sc = 0, color = 0;
  // std::vector<std::vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
  
  // * testcase 2
  // int sr = 1, sc = 0, color = 2;
  // std::vector<std::vector<int>> image = {{0, 0, 0}, {0, 0, 0}};

  std::cout << "image: " << std::endl;
  for (auto &vec : image)
    printArr(vec);

  std::cout << "Ans: " << std::endl;
  std::vector<std::vector<int>> ans = floodFill(image, sr, sc, color);
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-flood-fill.cpp -o output && ./output