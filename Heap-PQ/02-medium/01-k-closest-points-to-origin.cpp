/*
 * Leetcode - 973
 * K Closest Points to Origin
 * 
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
 * return the k closest points to the origin (0, 0).
 *                                                                                    _________________________
 * The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2 ).
 * 
 * You may return the answer in any order. The answer is guaranteed to be unique 
 * (except for the order that it is in).

 * Example 1
 * input  : points = [[1,3],[-2,2]], k = 1
 * output : [[-2,2]]
 * 
 * http://leetcode.com/problems/k-closest-points-to-origin/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop + Sorting
// * TIME COMPLEXITY O(n * nlogn)
// * SPACE COMPLEXITY O(n)
std::vector<std::vector<int>> bruteForce(std::vector<std::vector<int>> points, int k) {
  int n = points.size();
  if (n == 0)
    return points;

  std::vector<std::pair<int, std::vector<int>>> coordinates;

  for (auto &point : points) {
    int delta_x = point[0] - 0;
    int delta_y = point[1] - 0;
    int x = delta_x * delta_x; // * abs diff in x-coordinates
    int y = delta_y * delta_y; // * abs diff in y-coordinates
    // std::cout << x + y << std::endl;
    // int distance = std::sqrt(x + y);
    coordinates.push_back({x + y, point});
  }

  // * sort the coordinates in ASC order 
  std::sort(coordinates.begin(), coordinates.end());

  std::vector<std::vector<int>> ans;
  for(auto &it: coordinates) {
    if(k > 0) {
      ans.push_back(it.second);
    } else {
      break;
    }
    k--;
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using max_heap
// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(k)
std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> points, int k) {
  int n = points.size();
  if (n == 0)
    return points;

  // * use max_heap
  typedef std::pair<int, std::vector<int>> P;
  std::priority_queue<P, std::vector<P>> max_heap;

  for (auto &point : points) {
    int dx = point[0] - 0;
    int dy = point[1] - 0;
    int x = dx * dx; // * abs diff in x-coordinates
    int y = dy * dy; // * abs diff in y-coordinates

    // std::cout << x + y << std::endl;
    // int distance = std::sqrt(x + y); // * No need for this

    max_heap.push({x + y, point});

    // * We only need first 'k' smaller elements
    if (max_heap.size() > k)
      max_heap.pop();
  }

  // * we need only 'k' elements
  std::vector<std::vector<int>> ans;
  while (k) {
    ans.push_back(max_heap.top().second);
    max_heap.pop();
    k--;
  }

  return ans;
}

int main() {
  // * testcase 1
  // int k = 1;
  // std::vector<std::vector<int>> points = {{1, 3}, {-2, 2}};

  // * testcase 2
  int k = 2;
  std::vector<std::vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};

  std::cout << "Points: " << std::endl;
  for (auto &vec : points)
  printArr(vec);
  
  // std::vector<std::vector<int>> ans = bruteForce(points, k);
  std::vector<std::vector<int>> ans = kClosest(points, k);
  
  std::cout << "k closest points: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-k-closest-points-to-origin.cpp -o output && ./output

