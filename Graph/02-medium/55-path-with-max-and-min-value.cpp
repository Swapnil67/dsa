/*
 * Path With Maximum And Minimum Value
 *
 * Given a matrix of integers ‘ARR’ with ‘R’ rows and ‘C’ columns, find the maximum score of a path 
 * starting at [0, 0] and ending at [R-1, C-1]. The score of a path is the minimum value in that path. 
 * For example, the value of the path 8 -> 4 -> 5 -> 9 is 4. A path moves some number of times from one 
 * visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).
 *
 * Example 1:
 * Input       : ARR = {{5 4 5} , {1 2 6} , {7 4 6}}
 * Output      : 4
 * Explanation : so the path with maximum value will be 5 -> 4 -> 5 -> 6 -> 6 and we have to return 
 *               the minimum value in this path as the answer i.e 4.
 * 
 * https://www.naukri.com/code360/problems/path-with-maximum-and-minimum-value_1281861
*/
#include<queue>
#include<vector>
#include<climits>
#include<iostream>

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

const std::vector<std::vector<int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int pathWithMaxMinValue(std::vector<std::vector<int>> &arr) {
  int m = arr.size(), n = arr[0].size();

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

  typedef std::pair<int, std::pair<int, int>> P;
  std::priority_queue<P, std::vector<P>> max_heap;
  max_heap.push({arr[0][0], {0, 0}});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int path_min = INT_MAX;
  while (!max_heap.empty()) {
    auto [d, p] = max_heap.top();
    auto [r, c] = p;
    max_heap.pop();

    path_min = std::min(path_min, d);

    visited[r][c] = true;

    if (r == m - 1 && c == n - 1)
      return path_min;

    for (auto &dir : dirs)
    {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc])
      {
        max_heap.push({arr[dr][dc], {dr, dc}});
      }
    }
  }

  return -1;
}

int main(void) {
 // * testcase 1
 std::vector<std::vector<int>> arr = {{5, 4, 5}, {1, 2, 6}, {7, 4, 6}};

 std::cout << "Input Matrix: " << std::endl;
 for (auto &vec : arr)
   printArr(vec);

 int ans = pathWithMaxMinValue(arr);
 std::cout << "Answer: " << ans << std::endl;
 return 0;
}

// * Run the code
// * g++ --std=c++20 55-path-with-max-and-min-value.cpp -o output && ./output