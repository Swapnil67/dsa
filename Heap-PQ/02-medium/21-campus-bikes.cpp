/*
 * Leetcode - ?
 * Campus Bikes
 * 
 * Example 1
 * input  : workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
 * output : [1,0]
 * 
 * Example 2
 * input  : workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
 * output : [0,2,1]
 * 
 * https://neetcode.io/problems/high-five/
 * https://leetcode.com/problems/high-five/description/
*/

// ! Google, Amazon

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int find_dist(std::vector<int> worker, std::vector<int> bike) {
  return std::abs(worker[0] - bike[0]) + std::abs(worker[1] - bike[1]);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using sorting
// * N = no. of workers
// * M = no. of bikes
// * TIME COMPLEXITY O(NMlog(N*M))
// * SPACE COMPLEXITY O(N*M)
std::vector<int> bruteForce(
    std::vector<std::vector<int>> &workers,
    std::vector<std::vector<int>> &bikes)
{
  int n = workers.size(), m = bikes.size();

  // * Generate all the possible pairs
  std::vector<std::tuple<int, int, int>> all_triplets;
  for (int worker = 0; worker < n; ++worker) {
    for (int bike = 0; bike < m; ++bike) {
      int distance = find_dist(workers[worker], bikes[bike]);
      all_triplets.push_back({distance, worker, bike});
    }
  }

  // * Sort the triplets. By default, each sorting will prioritize the
  // * Tuple's first value, then second value, and finally the third value
  std::sort(begin(all_triplets), end(all_triplets));

  // * Initialize all values to false, to signify no bikes have been taken
  std::vector<bool> bike_status(m, false);
  
  // * Initialize all index to -1, to signify no worker has a bike
  std::vector<int> worker_status(n, -1);

  int pairs = 0;
  for (auto &[dist, worker, bike] : all_triplets) {
    std::cout << "dist: " << dist << ", worker: " << worker << ", bike: " << bike << std::endl;
    if (worker_status[worker] == -1 && !bike_status[bike]) {
      bike_status[bike] = true;
      worker_status[worker] = bike;
      pairs++;
    }

    if (pairs == n)
      break;
  }

  return worker_status;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> workers = {{0, 0}, {2, 1}}, bikes = {{1, 2}, {3, 3}};

  // * testcase 2
  std::vector<std::vector<int>> workers = {{0, 0}, {1, 1}, {2, 0}}, bikes = {{1, 0}, {2, 2}, {2, 1}};

  std::cout << "Workers: " << std::endl;
  for (auto &w : workers)
    printArr(w);
    
  std::cout << "bikes: " << std::endl;
  for (auto &b : bikes)
    printArr(b);

  std::vector<int> ans = bruteForce(workers, bikes);
  // std::vector<int>  ans = bruteForce(items);

  std::cout << "Campus Bikes" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-campus-bikes.cpp -o output && ./output