/*
 * Leetcode - PAID
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

#include <tuple>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

int find_dist(vector<int> worker, vector<int> bike) {
  return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using sorting
// * N = no. of workers
// * M = no. of bikes
// * TIME COMPLEXITY O(NMlog(N*M))
// * SPACE COMPLEXITY O(N*M)
vector<int> bruteForce(
    vector<vector<int>> &workers,
    vector<vector<int>> &bikes)
{
  int n = workers.size(), m = bikes.size();

  // * Generate all the possible pairs
  vector<tuple<int, int, int>> all_triplets;
  for (int worker = 0; worker < n; ++worker) {
    for (int bike = 0; bike < m; ++bike) {
      int distance = find_dist(workers[worker], bikes[bike]);
      all_triplets.push_back({distance, worker, bike});
    }
  }

  // * Sort the triplets. By default, each sorting will prioritize the
  // * Tuple's first value, then second value, and finally the third value
  sort(begin(all_triplets), end(all_triplets));

  // * Initialize all values to false, to signify no bikes have been taken
  vector<bool> bike_status(m, false);
  
  // * Initialize all index to -1, to signify no worker has a bike
  vector<int> worker_status(n, -1);

  int pairs = 0;
  for (auto &[dist, worker, bike] : all_triplets) {
    cout << "dist: " << dist << ", worker: " << worker << ", bike: " << bike << endl;
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
  // vector<vector<int>> workers = {{0, 0}, {2, 1}}, bikes = {{1, 2}, {3, 3}};

  // * testcase 2
  vector<vector<int>> workers = {{0, 0}, {1, 1}, {2, 0}}, bikes = {{1, 0}, {2, 2}, {2, 1}};

  cout << "Workers: " << endl;
  for (auto &w : workers)
    printArr(w);
    
  cout << "bikes: " << endl;
  for (auto &b : bikes)
    printArr(b);

  vector<int> ans = bruteForce(workers, bikes);
  // vector<int>  ans = bruteForce(items);

  cout << "Campus Bikes" << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-campus-bikes.cpp -o output && ./output